from c4_ast import *


class Resolver:
    def __init__(self,programs):
        self.programs = programs
        self.previous = None
        self.next = None

    def resolve_programs(self):
        size = len(self.programs.decls)
        for i in range(size):
            if i > 0:
                self.previous = self.programs.decls[i - 1]
            
            if i < size - 1:
               self.next = self.programs.decls[i + 1]

            program = self.programs.decls[i]
            symbol = self.resolve_program(program)
            if self.programs.table.add(symbol.name,symbol) == False:
                print(f"{symbol.name} redefined")

    def resolve_program(self,program):
        symbol = Symbol("","","","")

        match program.type:
            case DeclType.DECL_ENUM:
                symbol = self.resolve_enum_decl(program.decl)

            case DeclType.DECL_STRUCT:
                symbol = self.resolve_struct_decl(program.decl)

            case DeclType.DECL_IMPL:
                symbol = self.resolve_impl_decl(program.decl)

            case DeclType.DECL_FN:
                symbol = self.resolve_fn_decl(program.decl)
            
            case DeclType.DECL_VARDECL:
                symbol = self.resolve_var_decl(program.decl)

            case DeclType.DECL_VARASSIGN:
                symbol = self.resolve_var_assign(program.decl)
            case _:
                print(f"impossible {program.type}")

        return symbol

    def resolve_enum_decl(self,program):

        for constant in program.constants:
            if program.table.add(constant.string,constant) == False:
                print(f"{constant.string} redefined")
            
        symbol = Symbol(program.ident.string,None,SymbolType.SYMBOL_ENUM,program)
        return symbol

    def resolve_struct_decl(self,program):
        
        for varD in program.varDs:
            sym = self.resolve_var_decl(varD)
            if program.table.add(varD.ident.string,sym) == False:
                print(f"{varD.ident.string} redefined")

        symbol = Symbol(program.ident.string,None,SymbolType.SYMBOL_STRUCT,program)
        return symbol
    
    def resolve_impl_decl(self,program):
        if self.previous.type != DeclType.DECL_STRUCT:
            print(f"impl {program.ident.string} declared without a struct {program.ident.string} preceding it")

        elif self.previous.decl.ident.string != program.ident.string:
            print(f"impl {program.ident.string} declared without a struct {program.ident.string} preceding it")
        

        for fn in program.fns:
            sym = self.resolve_fn_decl(fn)
            if program.table.add(fn.ident.string,sym) == False:
                print(f"{fn.ident.string} in impl {program.ident.string} redefined")

        self.previous.decl.impl = program
        symbol = Symbol(program.ident,None,SymbolType.SYMBOL_IMPL,program)
        return symbol

    def resolve_fn_decl(self,program):
                
        program.block = self.resolve_block_stmt(program.block,None)

        for arg in program.args:
            sym = self.resolve_var_decl(arg)
            if program.block.table.add(arg.ident.string,sym) == False:
                print(f"{arg.ident.string} in fn {program.ident.string} redefined")


        symbol = Symbol(program.ident.string,program.retparam,SymbolType.SYMBOL_FNDECL,program)
        return symbol
    
    def resolve_var_decl(self,varD):
        
        return Symbol(varD.ident.string,varD.type,SymbolType.SYMBOL_VARDECL,varD)

    def resolve_var_assign(self,varA):

        return Symbol(varA.ident.string,None,SymbolType.SYMBOL_VARASSIGN,varA)
    

    def resolve_block_stmt(self,block,parent):
        
        block.table = SymbolTable(parent)

        for stmt in block.stmts:
            symbol = None
            match stmt.type:
                case StmtType.STMT_VARDECL:
                    symbol = self.resolve_var_decl(stmt.stmt)
                case StmtType.STMT_BLOCK:
                    block.stmts[block.stmts.index(stmt)] = self.resolve_block_stmt(stmt.stmt,block.table)
                case _:
                    continue

            if block.table.add(symbol.name,symbol) == False:
                print(f"{stmt.stmt.ident.string} redefined")
            else:
                print(f"{symbol.name} defined")

        return block

            