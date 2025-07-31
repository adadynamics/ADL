from c4_ast import *


class BuildSymbolTable:
    def __init__(self,programs):
        self.programs = programs
        self.previous = None
        self.next = None

    def build_symboltable_programs(self):
        size = len(self.programs.decls)
        for i in range(size):
            if i > 0:
                self.previous = self.programs.decls[i - 1]
            
            if i < size - 1:
               self.next = self.programs.decls[i + 1]

            program = self.programs.decls[i]
            symbol = self.build_symboltable_program(program)
            if self.programs.table.add(symbol.name,symbol) == False:
                print(f"{symbol.name} redefined")

    def build_symboltable_program(self,program):
        symbol = Symbol("","","","")

        match program.type:
            case DeclType.DECL_ENUM:
                symbol = self.build_symboltable_enum_decl(program.decl)

            case DeclType.DECL_STRUCT:
                symbol = self.build_symboltable_struct_decl(program.decl)

            case DeclType.DECL_IMPL:
                symbol = self.build_symboltable_impl_decl(program.decl)

            case DeclType.DECL_FN:
                symbol = self.build_symboltable_fn_decl(program.decl)
            
            case DeclType.DECL_VARDECL:
                symbol = self.build_symboltable_var_decl(program.decl)

            case DeclType.DECL_VARASSIGN:
                symbol = self.build_symboltable_var_assign(program.decl)
            case _:
                print(f"impossible {program.type}")

        return symbol

    def build_symboltable_enum_decl(self,program):

        self.programs.types.add(program.ident.string,Type(program.ident,TypeType.TYPE_ENUM))

        for constant in program.constants:
            if program.table.add(constant.string,constant) == False:
                print(f"{constant.string} redefined")
            
        symbol = Symbol(program.ident.string,None,SymbolType.SYMBOL_ENUM,program)
        return symbol

    def build_symboltable_struct_decl(self,program):
        
        self.programs.types.add(program.ident.string,Type(program.ident,TypeType.TYPE_STRUCT,program))
        for varD in program.varDs:
            sym = self.build_symboltable_var_decl(varD)
            if program.table.add(varD.ident.string,sym) == False:
                print(f"{varD.ident.string} redefined")

        symbol = Symbol(program.ident.string,None,SymbolType.SYMBOL_STRUCT,program)
        return symbol
    
    def build_symboltable_impl_decl(self,program):
        if self.previous.type != DeclType.DECL_STRUCT:
            print(f"impl {program.ident.string} declared without a struct {program.ident.string} preceding it")

        elif self.previous.decl.ident.string != program.ident.string:
            print(f"impl {program.ident.string} declared without a struct {program.ident.string} preceding it")
        

        for fn in program.fns:
            sym = self.build_symboltable_fn_decl(fn)
            if program.table.add(fn.ident.string,sym) == False:
                print(f"{fn.ident.string} in impl {program.ident.string} redefined")

        self.previous.decl.impl = program
        symbol = Symbol(program.ident,None,SymbolType.SYMBOL_IMPL,program)
        return symbol

    def build_symboltable_fn_decl(self,program):
                
        program.block = self.build_symboltable_block_stmt(program.block,None)

        for arg in program.args:
            sym = self.build_symboltable_var_decl(arg)
            if program.block.table.add(arg.ident.string,sym) == False:
                print(f"{arg.ident.string} in fn {program.ident.string} redefined")


        symbol = Symbol(program.ident.string,program.retparam,SymbolType.SYMBOL_FNDECL,program)
        return symbol
    
    def build_symboltable_var_decl(self,varD):
        
        return Symbol(varD.ident.string,varD.type,SymbolType.SYMBOL_VARDECL,varD)

    def build_symboltable_var_assign(self,varA):

        return Symbol(varA.ident.string,None,SymbolType.SYMBOL_VARASSIGN,varA)
    

    def build_symboltable_block_stmt(self,block,parent):
        
        if parent != None:
            block.table = SymbolTable(parent.table)

        for stmt in block.stmts:
            symbol = None
            match stmt.type:
                case StmtType.STMT_VARDECL:
                    symbol = self.build_symboltable_var_decl(stmt.stmt)
    
                case StmtType.STMT_IF:
                    symbol = self.build_symboltable_if_stmt(stmt.stmt,block)
                case StmtType.STMT_WHILE:
                    symbol = self.build_symboltable_while_stmt(stmt.stmt,block)
                case StmtType.STMT_FOR:
                    symbol = self.build_symboltable_for_stmt(stmt.stmt,block)
                case StmtType.STMT_SWITCH:
                    symbol = self.build_symboltable_switch_stmt(stmt.stmt,block)
                case StmtType.STMT_LOOP:
                    symbol = self.build_symboltable_loop_stmt(stmt.stmt,block)
                case StmtType.STMT_WITH:
                    symbol = self.build_symboltable_with_stmt(stmt.stmt,block)
                
                case StmtType.STMT_RETURN:
                    symbol = self.build_symboltable_return_stmt(stmt.stmt,block)
                
                case _:
                    continue
            
            if symbol == None:
                continue

            if block.table.add(symbol.name,symbol) == False:
                print(f"{stmt.stmt.ident.string} redefined")
            else:
                pass
                #print(f"{symbol.name} defined")

        return block

    def build_symboltable_if_stmt(self,stmt,block):

        stmt.block = self.build_symboltable_block_stmt(stmt.block,block)

        for Elif in stmt.elifs:
            Elif.block = self.build_symboltable_block_stmt(Elif.block,block)

        if stmt.Else != None:
            stmt.Else.block = self.build_symboltable_block_stmt(stmt.Else.block,block)
        return None


    def build_symboltable_while_stmt(self,stmt,block):

        stmt.block = self.build_symboltable_block_stmt(stmt.block,block)
        return None

    def build_symboltable_if_stmt(self,stmt,block):

        stmt.block = self.build_symboltable_block_stmt(stmt.block,block)

        for Elif in stmt.elifs:
            Elif.block = self.build_symboltable_block_stmt(Elif.block,block)

        if stmt.Else != None:
            stmt.block = self.build_symboltable_block_stmt(stmt.Else.block,block)
        return None

    def build_symboltable_switch_stmt(self,stmt,block):

        for Case in stmt.cases:
            Case.block = self.build_symboltable_block_stmt(Case.block,block)
        return None

    def build_symboltable_loop_stmt(self,stmt,block):

        stmt.block = self.build_symboltable_block_stmt(stmt.block,block)
        return None

    def build_symboltable_return_stmt(self,stmt,block):

        return None









class ResolveBindings:
    def __init__(self,programs):
        self.programs = programs
        self.previous = None
        self.next = None
        self.alloc = AllocType.ALLOC_NONE

    def resolve_programs(self):
        size = len(self.programs.decls)
        for i in range(size):
            if i > 0:
                self.previous = self.programs.decls[i - 1]
            
            if i < size - 1:
               self.next = self.programs.decls[i + 1]

            program = self.programs.decls[i]
            self.resolve_program(program)

    def resolve_program(self,program):

        match program.type:
            case DeclType.DECL_ENUM:
                self.resolve_enum_decl(program.decl)

            case DeclType.DECL_STRUCT:
                self.resolve_struct_decl(program.decl)

            case DeclType.DECL_IMPL:
                self.resolve_impl_decl(program.decl)

            case DeclType.DECL_FN:
                self.resolve_fn_decl(program.decl)
            
            case DeclType.DECL_VARDECL:
                self.resolve_var_decl(program.decl)

            case DeclType.DECL_VARASSIGN:
                self.resolve_var_assign(program.decl)
            case _:
                print(f"impossible {program.type}")

    def resolve_enum_decl(self,decl):

        if self.programs.types.lookup(decl.ident.string) == None:
            print(f"huh? => enum {decl.ident.string} not in types table")

        for constant in decl.constants:
            if decl.table.lookup(constant.string) == None:
                print(f"{constant.string} not in enum {decl.ident.string} table")


    def resolve_struct_decl(self,decl):

        if self.programs.types.lookup(decl.ident.string) == None:
            print(f"huh? => struct {decl.ident.string} not in types table")

        for varD in decl.varDs:
            self.resolve_var_decl(varD,decl)
            if decl.table.lookup(varD.ident.string) == None:
                print(f"{varD.ident.string} not in struct {decl.ident.string} table")

        if decl.impl == None:
            return
        
        struct = decl
        for fn in decl.impl.fns:
            self.resolve_fn_decl(fn,struct)
            if decl.table.lookup(fn.ident.string) == None:
                print(f"{fn.ident.string} not in impl {decl.ident.string} table")

    def resolve_impl_decl(self,decl):
        pass

    def resolve_fn_decl(self,decl,struct=None):

        block = decl.block
        for arg in decl.args:
            self.resolve_var_decl(arg,block)
            if block.table.lookup(arg.ident.string) == None:
                print(f"{arg.ident.string} not in fn {decl.ident.string} table")

        self.resolve_block_stmt(block)

    def resolve_var_decl(self,decl,block=None):

        if block.table.lookup(decl.ident.string) == None:
            print(f"{decl.ident.string} not in any symbol table")

        self.resolve_expr(decl.expr,block)

        if self.alloc == AllocType.ALLOC_OWNER:
            decl.alloc = AllocType.ALLOC_OWNER
            
        self.alloc = AllocType.ALLOC_NONE

    def resolve_var_assign(self,decl,block=None):

        if block.table.lookup(decl.ident.string) == None:
            print(f"{decl.ident.string} not in any symbol table")
            return
        
        sym = block.table.lookup(decl.ident.string)

        self.resolve_expr(decl.expr,block)

        if self.alloc == AllocType.ALLOC_OWNER:
            sym.val.alloc = AllocType.ALLOC_OWNER

        elif decl.alloc == AllocType.ALLOC_OWNER:
            sym.val.alloc = AllocType.ALLOC_OWNER
            decl.alloc = AllocType.ALLOC_NONE

        self.alloc = AllocType.ALLOC_NONE

    def resolve_block_stmt(self,block):

        for stmt in block.stmts:

            match stmt.type:
                case StmtType.STMT_VARDECL:
                    self.resolve_var_decl(stmt.stmt,block)
                case StmtType.STMT_VARASSIGN:
                    self.resolve_var_assign(stmt.stmt,block)
                case StmtType.STMT_FNCALL:
                    self.resolve_fncall(stmt.stmt,block)
                case StmtType.STMT_IF:
                    self.resolve_if_stmt(stmt.stmt,block)
                case StmtType.STMT_WHILE:
                    self.resolve_while_stmt(stmt.stmt,block)
                case StmtType.STMT_FOR:
                    self.resolve_for_stmt(stmt.stmt,block)
                case StmtType.STMT_SWITCH:
                    self.resolve_switch_stmt(stmt.stmt,block)
                case StmtType.STMT_LOOP:
                    self.resolve_loop_stmt(stmt.stmt,block)
                case StmtType.STMT_WITH:
                    self.resolve_with_stmt(stmt.stmt,block)
                case StmtType.STMT_RETURN:
                    self.resolve_return_stmt(stmt.stmt,block)
                case StmtType.STMT_STRUCT_ACCESS:
                    self.resolve_struct_access(stmt.stmt,block)
                case _:
                    continue
    
    def resolve_fncall(self,stmt,block):

        if self.programs.table.lookup(stmt.ident.string) == None:
            print(f"{stmt.ident.string} called but not defined")

        for expr in stmt.exprs:
            self.resolve_expr(expr,block)

    def resolve_struct_access(self,stmt,block):

        struct = None
        sym = block.table.lookup(stmt.left.string)
        if sym == None:
            print(f"{stmt.left.string} is used but not declared")
        else:
            if self.programs.types.lookup(sym.type.string) == None:
                print("unknown type")
                pass
            else:
                struct = sym.val

        
        if struct == None:
            return
        
        match stmt.type:
            case StructAccessType.STRUCT_ACCESS_METHOD:
                if struct.table.lookup(stmt.right.ident.string) == None:
                    print(f"{stmt.right.ident.string} called but not defined in {struct.ident.string}")
            case StructAccessType.STRUCT_ACCESS_PROPERTY:
                self.resolve_expr(stmt.right,struct.block)

    def resolve_if_stmt(self,stmt,block):

        self.resolve_expr(stmt.expr,block)

        self.resolve_block_stmt(stmt.block)

        for Elif in stmt.elifs:
            self.resolve_expr(Elif.expr,block)
            self.resolve_block_stmt(Elif.block)

        if stmt.Else != None:
            self.resolve_block_stmt(stmt.Else.block)

    def resolve_while_stmt(self,stmt,block):

        self.resolve_expr(stmt.expr,block)

        self.resolve_block_stmt(stmt.block)

    def resolve_switch_stmt(self,stmt,block):

        self.resolve_expr(stmt.expr,block)

        for Case in stmt.Cases:
            if Case.default == 0:
                self.resolve_expr(Case.expr,block)

            self.resolve_block_stmt(Case.block)

    def resolve_loop_stmt(self,stmt,block):

        self.resolve_block_stmt(stmt.block)

    def resolve_return_stmt(self,stmt,block):

        self.resolve_expr(stmt.expr,block)

    def resolve_expr(self,expr,block):
        if expr == None:
            return
        
        match expr.type:
            case ExprType.EXPR_BINARY:
                self.resolve_binary_expr(expr.val,block)
            case ExprType.EXPR_UNARY:
                self.resolve_unary_expr(expr.val,block)
            case ExprType.EXPR_FNCALL:
                self.resolve_fncall_expr(expr.val,block)
            case ExprType.EXPR_RESOLVED:
                self.resolve_resolved_expr(expr.val,block)
            case ExprType.EXPR_ALLOC:
                self.resolve_alloc_expr(expr.val,block)
            case ExprType.EXPR_GROUPING:
                self.resolve_grouping_expr(expr.val,block)
            case ExprType.EXPR_PRIMARY:
                self.resolve_primary_expr(expr.val,block)

    def resolve_binary_expr(self,expr,block):
        self.resolve_expr(expr.left,block)
        self.resolve_expr(expr.right,block)

    def resolve_unary_expr(self,expr,block):
        self.resolve_expr(expr.right,block)

    def resolve_fncall_expr(self,expr,block):
        self.resolve_fncall(expr.fncall,block)

    def resolve_resolved_expr(self,expr,block):
        struct = None
        if self.programs.types.lookup(expr.left.string) == None:
            print(f"struct {expr.left.string} used but not defined")
        else:
            type = self.programs.types.lookup(expr.left.string)
            struct = type.val

        if struct == None:
            return
        
        block = struct
        self.resolve_expr(expr.right,block)

    def resolve_alloc_expr(self,expr,block): 
        self.resolve_expr(expr.size,block)


    def resolve_primary_expr(self,expr,block):

        if expr.type == LiteralType.LIT_IDENT:
            if block.table.lookup(expr.literal.string) == None:
                print(f"{expr.literal.string} used but not defined")
            else:
                
                sym = block.table.lookup(expr.literal.string)
                #print(f"heree {sym.val.ident.string} {sym.val.alloc}")
                if sym.val.alloc == AllocType.ALLOC_OWNER:
                    #return
                    #print(f" ident in primary {sym.val.ident.string}")
                    #sym.val.alloc = AllocType.ALLOC_NO_ACCESS
                    #self.alloc = AllocType.ALLOC_OWNER
                    pass
                #print(f"{expr.literal.string} used and defined")
                

