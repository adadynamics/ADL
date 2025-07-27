from c4_ast import *

class Codegen:
    def __init__(self,programs,name):
        self.programs = programs
        self.name = name
        print(name)
        self.file = open(name,"w")
        self.file.write("#include <stdio.h>\n")
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
            print(f"fns {len(decl.impl.fns)}")
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

                    self.source += type + " " + arg.ident.string
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

            src += type + " " + arg.ident.string
            if i + 1 < len(decl.args_init) - 1:
                src += ","

        src += "){" + tmp_src
        src += "\n\treturn self.__init__("
        src += "self,"

        for i in range(len(decl.args_init) - 1):
            arg = decl.args_init[i + 1]
            src += arg.ident.string
            if i + 1 < len(decl.args_init) - 1:
                src += ","
        src += ");"
        src += "\n}"
        self.source += "\n" + src
        print(src)

    
    def gen_impl_decl(self,decl):
        return

    def gen_fn_decl(self,decl,prefix="",struct=None):
        if prefix == "":
            pre = ""
        else:
            pre = prefix + "_"
            
        retparam = decl.retparam.string
        print(retparam)
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

            self.source += type + " " + arg.ident.string
            if i < len(decl.args) - 1:
                self.source += ","
        
        self.source += "){\n"
        self.gen_block_stmt(decl.block,"\t")
        self.source += "\n}\n"

    def gen_var_decl(self,decl,block,tab):
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

        self.source += tab + type + " " + decl.ident.string
        if decl.expr != None:
            self.source += " = "
            self.gen_expr(decl.expr,block)
        
        self.source += ";\n"

    def gen_var_assign(self,decl,block,tab):
        self.source += tab + decl.ident.string + " = "
        self.gen_expr(decl.expr,block)
        self.source += ";\n"

    def gen_block_stmt(self,block,tab=""):
        for stmt in block.stmts:
            #self.source += tab
            self.gen_stmt(stmt,block,tab)

    def gen_stmt(self,stmt,block,tab):
        match stmt.type:
            case StmtType.STMT_VARDECL:
                self.gen_var_decl(stmt.stmt,block,tab)
            
            case StmtType.STMT_STRUCT_ACCESS:
                self.gen_struct_access(stmt.stmt,block,tab)

            case StmtType.STMT_VARASSIGN:
                self.gen_var_assign(stmt.stmt,block,tab)

            case StmtType.STMT_FNCALL:
                self.gen_fncall(stmt.stmt,block,tab)
                self.source += ";\n"

            case StmtType.STMT_IF:
                self.gen_if_stmt(stmt.stmt,block,tab)

            case StmtType.STMT_WHILE:
                self.gen_while_stmt(stmt.stmt,block,tab)
            
            case StmtType.STMT_SWITCH:
                self.gen_switch_stmt(stmt.stmt,block,tab)

            case StmtType.STMT_RETURN:
                self.gen_return_stmt(stmt.stmt,block,tab)
            
            case StmtType.STMT_LOOP:
                self.gen_loop_stmt(stmt.stmt,block,tab)

    def gen_struct_access(self,stmt,block,tab):
        
        match stmt.type:
            case StructAccessType.STRUCT_ACCESS_METHOD:
                type = block.table.lookup(stmt.left.string)
                if type == None:
                    print("-----------------------------------------------------------------------")
                
                type = type.type.string
                self.source += tab + type + "_"
                self.gen_fncall(stmt.right,block,"")
            
            case StructAccessType.STRUCT_ACCESS_PROPERTY:
                
                self.source += tab + stmt.left.string + "."
                self.gen_expr(stmt.right,block)

        self.source += ";\n"
            

    def gen_fncall(self,stmt,block,tab):
        ident = stmt.ident.string
        if stmt.ident.string == "new":
            ident = "Create"

        print("--------------------------------------------------------")
        print(ident)


        self.source += tab + ident + "("

        for i in range(len(stmt.exprs)):
            expr = stmt.exprs[i]
            self.gen_expr(expr,block)
            if i < len(stmt.exprs) - 1:
                self.source += ","

        self.source += ")"

    def gen_if_stmt(self,stmt,block,tab):
        self.source += tab + "if"

        self.source += "("
        self.gen_expr(stmt.expr,block)
        self.source += "){\n"
        self.gen_block_stmt(stmt.block,tab + "\t")
        self.source += tab + "}\n"

        for Elif in stmt.elifs:
            self.source += tab + "else if("
            self.gen_expr(Elif.expr,block)
            self.source += "){\n"
            self.gen_block_stmt(Elif.block,tab + "\t")
            self.source += tab + "}\n"

        if stmt.Else != None:
            self.source += tab + "else{\n"
            self.gen_block_stmt(stmt.Else.block,tab + "\t")
            self.source += tab + "}\n"

    def gen_while_stmt(self,stmt,block,tab):
        self.source += tab + "while("

        self.gen_expr(stmt.expr,block)
        self.source += "){\n"
        self.gen_block_stmt(stmt.block,tab + "\t")
        self.source += tab + "}\n"

    def gen_switch_stmt(self,stmt,block,tab):
        self.source += tab + "switch("

        self.gen_expr(stmt.expr,block)
        self.source += "){\n"
        
        for Case in stmt.cases:
            if Case.defaultt == 1:
                self.source += tab + "\tdefault"
            else:
                self.source += tab + "\tcase "
                self.gen_expr(Case.expr,block)
            self.source += ":{\n"
            self.gen_block_stmt(Case.block,tab + "\t\t")
            self.source += tab + "\t\tbreak;\n"
            self.source += tab + "\t}\n"

        self.source += "}\n"

    def gen_loop_stmt(self,stmt,block,tab):
        self.source += tab + "while(1){\n"

        self.gen_block_stmt(stmt.block,tab + "\t")

        self.source += tab + "}\n"
    
    def gen_return_stmt(self,stmt,block,tab):
        self.source += tab + "return"

        if stmt.expr != None:
            self.source += " "
            self.gen_expr(stmt.expr,block)

        self.source += ";\n"

    def gen_expr(self,expr,block):
        match expr.type:
            case ExprType.EXPR_BINARY:
                self.gen_binary_expr(expr.val,block)
            case ExprType.EXPR_UNARY:
                self.gen_unary_expr(expr.val,block)
            case ExprType.EXPR_FNCALL:
                self.gen_fncall_expr(expr.val,block)
            case ExprType.EXPR_RESOLVED:
                self.gen_resolved_expr(expr.val,block)
            case ExprType.EXPR_GROUPING:
                self.gen_grouping_expr(expr.val,block)
            case ExprType.EXPR_PRIMARY:
                self.gen_primary_expr(expr.val,block)


    def gen_binary_expr(self,expr,block):
        self.gen_expr(expr.left,block)
        self.source += " " + expr.op.string + " "
        self.gen_expr(expr.right,block)

    def gen_unary_expr(self,expr,block):
        self.source += expr.op.string + " "
        self.gen_expr(expr.right)

    def gen_fncall_expr(self,expr,block):
        self.gen_fncall(expr.fncall,block,"")

    def gen_resolved_expr(self,expr,block): 
        self.source += expr.left.string + "_"
        self.gen_expr(expr.right,block)


    def gen_primary_expr(self,expr,block):

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

