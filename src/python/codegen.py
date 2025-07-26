from c4_ast import *

class Codegen:
    def __init__(self,programs,name):
        self.programs = programs
        self.name = name
        print(name)
        self.file = open(name,"w")
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
            self.source += "\n\t" + varD.type.string + " " + varD.ident.string + ";"

        if decl.impl != None:
            print(f"fns {len(decl.impl.fns)}")
            for fn in decl.impl.fns:
                self.source += "\n\t" + fn.retparam.string + " (*" + fn.ident.string + ")("
                for i in range(len(fn.args)):
                    arg = fn.args[i]
                    self.source += arg.type.string + " " + arg.ident.string
                    if i < len(fn.args) - 1:
                        self.source += ","
                
                self.source += ");"
                #print(self.source)


        self.source += "\n};\n"

        if decl.impl != None:
            for fn in decl.impl.fns:
                self.gen_fn_decl(fn,decl.ident.string)
                pass

    
    def gen_impl_decl(self,decl):
        return

    def gen_fn_decl(self,decl,prefix=""):
        if prefix == "":
            pre = ""
        else:
            pre = prefix + "_"
            
        self.source += decl.retparam.string + " " + pre + decl.ident.string + "("

        for i in range(len(decl.args)):
            arg = decl.args[i]
            self.source += arg.type.string + " " + arg.ident.string
            if i < len(decl.args) - 1:
                self.source += ","
        
        self.source += "){\n"
        self.gen_block_stmt(decl.block,"\t")
        self.source += "\n}\n"

    def gen_var_decl(self,decl,block,tab):
        self.source += tab + decl.type.string + " " + decl.ident.string
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
            
            case StmtType.STMT_VARASSIGN:
                self.gen_var_assign(stmt.stmt,block,tab)

            case StmtType.STMT_FNCALL:
                self.gen_fncall(stmt.stmt,block,tab)

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

    def gen_fncall(self,stmt,block,tab):
        self.source += tab + stmt.ident.string + "("

        if stmt.expr != None:
            self.gen_expr(stmt.expr,block)

        self.source += ");\n"

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
            case ExprType.EXPR_PRIMARY:
                self.gen_primary_expr(expr.val,block)


    def gen_binary_expr(self,expr,block):
        self.gen_expr(expr.left,block)
        self.source += " " + expr.op.string + " "
        self.gen_expr(expr.right,block)

    def gen_unary_expr(self,expr,block):
        self.source += expr.op.string + " "
        self.gen_expr(expr.right)

    def gen_primary_expr(self,expr,block):
        self.source += expr.literal.string

