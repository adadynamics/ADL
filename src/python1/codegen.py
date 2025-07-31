from c4_ast import *

class Codegen:
    def __init__(self,programs,name):
        self.programs = programs
        self.alloc = AllocType.ALLOC_NONE
        self.name = name
        self.file = open(name,"w")
        self.file.write("#include <stdio.h>\n#include <stdlib.h>\n#ifndef c4_malloc\n#define c4_malloc malloc\n#define c4_free free\n#endif\n")
        self.source = ""

    def gen_programs(self):
        for program in self.programs.decls:
            self.gen_program(program)

        self.file.write(self.source)

    def gen_program(self,program):
        
        match program.type:
            case DeclType.DECL_ENUM:
                self.gen_enum_decl(program.decl)

            case DeclType.DECL_STRUCT:
                self.gen_struct_decl(program.decl)

            case DeclType.DECL_IMPL:
                self.gen_impl_decl(program.decl)

            case DeclType.DECL_FN:
                self.gen_fn_decl(program.decl)
            
            case DeclType.DECL_VARDECL:
                self.gen_var_decl(program.decl)

            case DeclType.DECL_VARASSIGN:
                self.gen_var_assign(program.decl)
            case _:
                print(f"impossible {program.type}")
       
    def gen_enum_decl(self,decl):
        self.source += "enum " + decl.ident.string 
        self.source += "\n{"

        for constant in decl.constants:
            self.source += "\n\t" + constant.string + ","

        self.source += "\n};\n"

    def gen_struct_decl(self,decl):
        self.source += "struct " + decl.ident.string
        self.source += "\n{"

        for varD in decl.varDs:
            type = self.programs.types.lookup(varD.type.string)
            if type != None:
                match type.type:
                    case TypeType.TYPE_ENUM:
                        type = "enum " + varD.type.string
                    case TypeType.TYPE_STRUCT:
                        type = "struct " + varD.type.string
                    case _:
                        type = varD.type.string
            else:
                        type = varD.type.string

            self.source += "\n\t" + type + " " + varD.ident.string + ";"

        if decl.impl != None:
            for fn in decl.impl.fns:
                retparam = fn.retparam.string
                tmp_retparam = self.programs.types.lookup(retparam)
                if tmp_retparam != None:
                    match tmp_retparam.type:
                        case TypeType.TYPE_ENUM:
                            retparam = "enum " + retparam
                        case TypeType.TYPE_STRUCT:
                            retparam = "struct " + retparam
                        case _:
                            retparam = fn.retparam.string

                self.source += "\n\t" + retparam + " (*" + fn.ident.string + ")("
                type = ""
                for i in range(len(fn.args)):
                    arg = fn.args[i]
                    type = self.programs.types.lookup(arg.type.string)
                    if type != None:
                        match type.type:
                            case TypeType.TYPE_ENUM:
                                type = "enum " + arg.type.string
                            case TypeType.TYPE_STRUCT:
                                type = "struct " + arg.type.string
                            case _:
                                type = arg.type.string
                    else:
                        type = arg.type.string

                    ptr = ""
                    for index in range(arg.ptr):
                        ptr += "*"

                    self.source += type + " " + ptr + arg.ident.string
                    if i < len(fn.args) - 1:
                        self.source += ","
                
                self.source += ");"
                #print(self.source)


        self.source += "\n};\n"

        pre = decl.ident.string + "_"
        tmp_src = "struct " + decl.ident.string + " " + pre + "Create(void){"
        tmp_src = "\n\t struct " +decl.ident.string + " " + "self;"
            

        if decl.impl != None:
            for fn in decl.impl.fns:
                self.gen_fn_decl(fn,decl.ident.string,decl)
                tmp_src += "\n\t self." + fn.ident.string + " = " + pre + fn.ident.string + ";"
                pass
            
        src = "struct " + decl.ident.string + " " + pre + "Create("
        for i in range(len(decl.args_init) - 1):
            arg = decl.args_init[i + 1]
            type = self.programs.types.lookup(arg.type.string)
            if type != None:
                match type.type:
                    case TypeType.TYPE_ENUM:
                        type = "enum " + arg.type.string
                    case TypeType.TYPE_STRUCT:
                        type = "struct " + arg.type.string
                    case _:
                        type = arg.type.string
            else:
                        type = arg.type.string

            ptr = ""
            for index in range(arg.ptr):
                ptr += "*"

            src += type + " " + ptr + arg.ident.string
            if i + 1 < len(decl.args_init) - 1:
                src += ","

        src += "){" + tmp_src
        src += "\n\treturn self.__init__("
        src += "&self"

        for i in range(len(decl.args_init) - 1):
            if i + 1 < len(decl.args_init) :
                src += ","
            arg = decl.args_init[i + 1]
            src += arg.ident.string
            
        src += ");"
        src += "\n}"
        self.source += "\n" + src

    
    def gen_impl_decl(self,decl):
        return

    def gen_fn_decl(self,decl,prefix="",struct=None):
        if prefix == "":
            pre = ""
        else:
            pre = prefix + "_"
            
        retparam = decl.retparam.string
        tmp_retparam = self.programs.types.lookup(retparam)
        if tmp_retparam != None:
            match tmp_retparam.type:
                case TypeType.TYPE_ENUM:
                    retparam = "enum " + retparam
                case TypeType.TYPE_STRUCT:
                    retparam = "struct " + retparam
                    

        self.source += retparam + " " + pre + decl.ident.string + "("

        if decl.ident.string == "__init__" and struct != None:
            struct.args_init = decl.args

        if decl.ident.string == "__fini__" and struct != None:
            struct.args_fini = decl.args

        for i in range(len(decl.args)):
            arg = decl.args[i]
            sym = decl.block.table.lookup(arg.ident.string)
            #print(sym.name)
            type = self.programs.types.lookup(arg.type.string)
            if type != None:
                match type.type:
                    case TypeType.TYPE_ENUM:
                        type = "enum " + arg.type.string
                    case TypeType.TYPE_STRUCT:
                        type = "struct " + arg.type.string
                    case _:
                        type = arg.type.string
            else:
                        type = arg.type.string

            self.source += type + " "
            ptr = ""
            for index in range(arg.ptr):
                ptr += "*"

            if arg.ptr != 0:
                sym.val.alloc = AllocType.ALLOC_OWNER
                sym.seen = True

            self.source += ptr + arg.ident.string
            if i < len(decl.args) - 1:
                self.source += ","
        
        self.source += "){\n"
        self.gen_block_stmt(decl.block,decl.ident.string,"\t")
        self.source += "\n}\n"
        #print(decl.alloc)
        #print(f"fndecl {decl.ident.string}")

    def gen_var_decl(self,decl,block,tab,tmp_fn):

        type = self.programs.types.lookup(decl.type.string)
        if type != None:
            match type.type:
                case TypeType.TYPE_ENUM:
                    type = "enum " + decl.type.string
                case TypeType.TYPE_STRUCT:
                    type = "struct " + decl.type.string
                case _:
                    type = decl.type.string
        else:
                    type = decl.type.string


        ptr = ""
        for i in range(decl.ptr):
            ptr += "*"

        sym = block.table.lookup(decl.ident.string)
        sym.seen = True
        self.source += tab + type + " " + ptr + decl.ident.string
        if decl.expr != None:
            self.source += " = "
            self.gen_expr(decl.expr,block,False,tmp_fn)
        
        self.source += ";\n"

        if self.alloc == AllocType.ALLOC_OWNER:
            decl.alloc = AllocType.ALLOC_OWNER

        elif self.alloc == AllocType.ALLOC_RETURNED:
            decl.alloc = AllocType.ALLOC_OWNER
            print(f"{decl.ident.string}  returned alloc  {self.alloc}")
            
        self.alloc = AllocType.ALLOC_NONE

    def gen_var_assign(self,decl,block,tab,tmp_fn):
        self.source += tab + decl.ident.string + " = "
        self.gen_expr(decl.expr,block,False,tmp_fn)
        self.source += ";\n"

        sym = block.table.lookup(decl.ident.string)
        if self.alloc == AllocType.ALLOC_OWNER:
            sym.val.alloc = AllocType.ALLOC_OWNER
        
        elif self.alloc == AllocType.ALLOC_RETURNED:
            sym.val.alloc = AllocType.ALLOC_OWNER

        elif decl.alloc == AllocType.ALLOC_OWNER:
            sym.val.alloc = AllocType.ALLOC_OWNER
            decl.alloc = AllocType.ALLOC_NONE

        self.alloc = AllocType.ALLOC_NONE

    def gen_block_stmt(self,block,tmp_fn,tab=""):
        free_idents = []
        for stmt in block.stmts:
            #self.source += tab
            match stmt.type:
                case StmtType.STMT_VARDECL:
                    self.gen_var_decl(stmt.stmt,block,tab,tmp_fn)
                    #if stmt.stmt.alloc == AllocType.ALLOC_OWNER:
                    #    block.free_idents.append(stmt.stmt.ident.string)
                    pass
                
                case StmtType.STMT_STRUCT_ACCESS:
                    self.gen_struct_access(stmt.stmt,block,tab,tmp_fn)

                case StmtType.STMT_VARASSIGN:
                    self.gen_var_assign(stmt.stmt,block,tab,tmp_fn)
                    #if stmt.stmt.alloc == AllocType.ALLOC_OWNER:
                    #    block.free_idents.append(stmt.stmt.ident.string)
                    pass

                case StmtType.STMT_FNCALL:
                    self.gen_fncall(stmt.stmt,block,tab,tmp_fn)
                    self.source += ";\n"

                case StmtType.STMT_IF:
                    self.gen_if_stmt(stmt.stmt,block,tab,tmp_fn)

                case StmtType.STMT_WHILE:
                    self.gen_while_stmt(stmt.stmt,block,tab,tmp_fn)
                
                case StmtType.STMT_SWITCH:
                    self.gen_switch_stmt(stmt.stmt,block,tab,tmp_fn)

                case StmtType.STMT_RETURN:
                    self.gen_return_stmt(stmt.stmt,block,tab,tmp_fn)
                
                case StmtType.STMT_LOOP:
                    self.gen_loop_stmt(stmt.stmt,block,tab,tmp_fn)
        
        for sym in block.table.symbols.values():
            free = ""
            #print(f"block end ====) {sym.name} {sym.kind} {sym.val.alloc}")
            if sym.kind == SymbolType.SYMBOL_VARDECL and sym.val.alloc == AllocType.ALLOC_OWNER:
                free = sym.val.ident.string
                self.source += tab + "c4_free(" + free + ");\n" 

    def gen_struct_access(self,stmt,block,tab,tmp_fn):
        
        match stmt.type:
            case StructAccessType.STRUCT_ACCESS_METHOD:
                type = block.table.lookup(stmt.left.string)
                if type == None:
                    pass
                
                type = type.type.string
                self.source += tab + type + "_"
                self.gen_fncall(stmt.right,block,"",tmp_fn)
            
            case StructAccessType.STRUCT_ACCESS_PROPERTY:
                
                self.source += tab + stmt.left.string + "."
                self.gen_expr(stmt.right,block,False,tmp_fn)

        self.source += ";\n"
            

    def gen_fncall(self,stmt,block,tab,tmp_fn):
        ident = stmt.ident.string
        sym = self.programs.table.lookup(ident)
        #print(sym.val.alloc)
        args = sym.val.args

        if stmt.ident.string == "new":
            ident = "Create"


        self.source += tab + ident + "("

        for i in range(len(stmt.exprs)):
            expr = stmt.exprs[i]
            arg = args[i]
            self.gen_expr(expr,block,False,tmp_fn)
            if self.alloc == AllocType.ALLOC_OWNER:
                arg.alloc = AllocType.ALLOC_OWNER
                
            self.alloc = AllocType.ALLOC_NONE
            if i < len(stmt.exprs) - 1:
                self.source += ","

        self.source += ")"
        #print(f" fncall  {ident}   =============== {sym.val.alloc} {sym.name} {tmp_fn}")
        if sym.val.alloc == AllocType.ALLOC_RETURNED:
            #print("we are in business baby")
            self.alloc = AllocType.ALLOC_RETURNED

    def gen_if_stmt(self,stmt,block,tab,tmp_fn):
        returns = False
        self.source += tab + "if"
        
        self.source += "("
        self.gen_expr(stmt.expr,block,False,tmp_fn)
        self.source += "){\n"
        self.gen_block_stmt(stmt.block,tmp_fn,tab + "\t")
        self.source += tab + "}\n"
        
        returns = stmt.block.returns

        for sym in block.table.symbols.values():
            if sym.kind == SymbolType.SYMBOL_VARDECL:
                sym.val.alloc = sym.val.previous_alloc
                #print(f"   ^^^^^^^^^^^^^^^^^^^    {sym.name} {sym.val.alloc}   {sym.val.previous_alloc}")

        for Elif in stmt.elifs:
            self.source += tab + "else if("
            self.gen_expr(Elif.expr,block,False,tmp_fn)
            self.source += "){\n"
            self.gen_block_stmt(Elif.block,tmp_fn,tab + "\t")
            self.source += tab + "}\n"

            if returns:
                if Elif.block.returns == False:
                    print("expected elif to return since a previous conditional block returns")
                else:
                    returns = True
            elif Elif.block.returns == True:
                print("elif cannot return since a previous conditional if block did not return")

            for sym in block.table.symbols.values():
                if sym.kind == SymbolType.SYMBOL_VARDECL:
                    sym.val.alloc = sym.val.previous_alloc
                    #print(f"   ^^^^^^^^^^^^^^^^^^^    {sym.name} {sym.val.alloc}   {sym.val.previous_alloc}")

        if stmt.Else != None:
            self.source += tab + "else{\n"
            self.gen_block_stmt(stmt.Else.block,tmp_fn,tab + "\t")
            self.source += tab + "}\n"

        for sym in block.table.symbols.values():
            if sym.kind == SymbolType.SYMBOL_VARDECL:
                pass
                #sym.val.alloc = sym.val.restore
                #print(f"   ^^^^^^^^^^^^^^^^^^^    {sym.name} {sym.val.alloc}   {sym.val.previous_alloc}")

    def gen_while_stmt(self,stmt,block,tab,tmp_fn):
        self.source += tab + "while("

        self.gen_expr(stmt.expr,block,False,tmp_fn)
        self.source += "){\n"
        self.gen_block_stmt(stmt.block,tmp_fn,tab + "\t")
        self.source += tab + "}\n"

    def gen_switch_stmt(self,stmt,block,tab,tmp_fn):
        self.source += tab + "switch("

        self.gen_expr(stmt.expr,block,False,tmp_fn)
        self.source += "){\n"
        
        for Case in stmt.cases:
            if Case.defaultt == 1:
                self.source += tab + "\tdefault"
            else:
                self.source += tab + "\tcase "
                self.gen_expr(Case.expr,block,False,tmp_fn)
            self.source += ":{\n"
            self.gen_block_stmt(Case.block,tmp_fn,tab + "\t\t")
            self.source += tab + "\t\tbreak;\n"
            self.source += tab + "\t}\n"

        self.source += "}\n"

    def gen_loop_stmt(self,stmt,block,tab,tmp_fn):
        self.source += tab + "while(1){\n"

        self.gen_block_stmt(stmt.block,tmp_fn,tab + "\t")

        self.source += tab + "}\n"
    
    def gen_return_stmt(self,stmt,block,tab,tmp_fn):
        source = self.source
        self.source += tab + "return"

        if stmt.expr != None:
            self.source += " "
            self.gen_expr(stmt.expr,block,True,tmp_fn)

        self.source += ";\n"
        tmp_source = self.source[len(source) - 1:]
        self.source = source
        #print(tmp_source)
        #import sys
        #sys.exit(7)
        
        tmp_block = block
        while tmp_block != None:
            for sym in tmp_block.table.symbols.values():
                free = ""
                if sym.kind == SymbolType.SYMBOL_VARDECL and sym.val.alloc == AllocType.ALLOC_OWNER and sym.seen == True:
                    free = sym.val.ident.string
                    self.source += tab + "c4_free(" + free + ");\n" 
            tmp_block = tmp_block.parent

        self.source += tmp_source
        if self.alloc == AllocType.ALLOC_RETURNED:
            sym = self.programs.table.lookup(tmp_fn)
            sym.val.alloc = AllocType.ALLOC_RETURNED
            self.alloc = AllocType.ALLOC_NONE

        block.returns = True  

    def gen_expr(self,expr,block,ret = False,fn = None):
        match expr.type:
            case ExprType.EXPR_BINARY:
                self.gen_binary_expr(expr.val,block,ret,fn)
            case ExprType.EXPR_UNARY:
                self.gen_unary_expr(expr.val,block,ret,fn)
            case ExprType.EXPR_FNCALL:
                self.gen_fncall_expr(expr.val,block,ret,fn)
            case ExprType.EXPR_RESOLVED:
                self.gen_resolved_expr(expr.val,block,ret,fn)
            case ExprType.EXPR_ALLOC:
                self.gen_alloc_expr(expr.val,block,ret,fn)
            case ExprType.EXPR_GROUPING:
                self.gen_grouping_expr(expr.val,block,ret,fn)
            case ExprType.EXPR_PRIMARY:
                self.gen_primary_expr(expr.val,block,ret,fn)


    def gen_binary_expr(self,expr,block,ret = False,fn = None):
        self.gen_expr(expr.left,block,ret,fn)
        self.source += " " + expr.op.string + " "
        self.gen_expr(expr.right,block,ret,fn)

    def gen_unary_expr(self,expr,block,ret = False,fn = None):
        self.source += expr.op.string + " "
        self.gen_expr(expr.right,ret,fn)

    def gen_fncall_expr(self,expr,block,ret = False,fn = None):
        self.gen_fncall(expr.fncall,block,"",fn)

    def gen_resolved_expr(self,expr,block,ret = False,fn = None): 
        self.source += expr.left.string + "_"
        self.gen_expr(expr.right,block,ret,fn)


    def gen_alloc_expr(self,expr,block,ret = False,fn = None): 
        self.source += "c4_malloc("
        self.gen_expr(expr.size,block,ret,fn)
        self.source += ")"


    def gen_primary_expr(self,expr,block,ret = False,fn = None):

        match expr.type:
            case LiteralType.LIT_FALSE:
                self.source += expr.literal.string
            
            case LiteralType.LIT_TRUE:
                self.source += expr.literal.string

            case LiteralType.LIT_INT:
                self.source += expr.literal.string
            
            case LiteralType.LIT_FLOAT:
                self.source += expr.literal.string

            case LiteralType.LIT_STRING:
                self.source += "\"" + expr.literal.string + "\""
            case LiteralType.LIT_IDENT:
                self.source += expr.literal.string

                if block.table.lookup(expr.literal.string) == None:
                    pass
                else:
                    
                    sym = block.table.lookup(expr.literal.string)
                    if sym.val.alloc == AllocType.ALLOC_NO_ACCESS:
                        print(f"{sym.val.ident.string} cannot be used...it transferred ownership")

                    if sym.val.alloc == AllocType.ALLOC_OWNER:
                        if ret == True:
                            self.alloc = AllocType.ALLOC_RETURNED
                            sym.val.alloc = AllocType.ALLOC_RETURNED
                            sym.val.previous_alloc = AllocType.ALLOC_OWNER
                            #print(f"[[[[]]]] {sym.name}")
                        else:
                            sym.val.alloc = AllocType.ALLOC_NO_ACCESS
                            sym.val.previous_alloc = AllocType.ALLOC_OWNER
                            self.alloc = AllocType.ALLOC_OWNER
                            #print(f"############## {sym.name}")

