from lexer import *

class Programs:
    def __init__(self):
        self.decls = []
        self.table = SymbolTable()
        self.types = TypeTable()

    def add(self,program):
        self.decls.append(program)
    
    def add_table(self,table):
        self.table = table

class Program:
    def __init__(self):
        self.type = None
        self.decl = None

    def add(self,type,decl):
        self.type = type
        self.decl = decl


class DeclType(Enum):
    DECL_ENUM = 0
    DECL_STRUCT = 1
    DECL_IMPL = 2
    DECL_FN = 3
    DECL_VARDECL = 4
    DECL_VARASSIGN = 5

class EnumDecl:
    def __init__(self):
        self.ident = None
        self.constants = []
        self.table = SymbolTable()

    def add_ident(self,ident):
        self.ident = ident

    def add_constant(self,constant):
        self.constants.append(constant)

class StructDecl:
    def __init__(self):
        self.ident = None
        self.varDs = []
        self.table = SymbolTable()
        self.impl = None
        self.args_init = []
        self.args_fini = []

    def add_ident(self,ident):
        self.ident = ident

    def add_vard(self,varD):
        self.varDs.append(varD)
    
    def add_impl(self,impl):
        self.impl = impl

class ImplDecl:
    def __init__(self):
        self.ident = None
        self.fns = []
        self.table = SymbolTable()

    def add_ident(self,ident):
        self.ident = ident

    def add_fn(self,fn):
        self.fns.append(fn)

class FnDecl:
    def __init__(self):
        self.ident = None
        self.args = []
        self.retparam = None
        self.block = None

    def add_ident(self,ident):
        self.ident = ident

    def add_arg(self,arg):
        self.args.append(arg)

    def add_retparam(self,retparam):
        self.retparam = retparam

    def add_block(self,block):
        self.block = block

class VarDecl:
    def __init__(self):
        self.ident = None
        self.type = None
        self.expr = None

    def add_ident(self,ident):
        self.ident = ident

    def add_type(self,type):
        self.type = type

    def add_expr(self,expr):
        self.expr = expr


class VarAssign:
    def __init__(self):
        self.ident = None
        self.expr = None

    def add_ident(self,ident):
        self.ident = ident

    def add_expr(self,expr):
        self.expr = expr

class BlockStmt:
    def __init__(self):
        self.stmts = []
        self.table = SymbolTable()

    def add(self,stmt):
        self.stmts.append(stmt)

class Stmt:
    def __init__(self):
        self.type = None
        self.stmt = None

    def add_type(self,type):
        self.type = type

    def add_stmt(self,stmt):
        self.stmt = stmt

class StmtType(Enum):
    STMT_VARDECL = 0
    STMT_VARASSIGN = 1
    STMT_FNCALL = 2
    STMT_IF = 3
    STMT_WHILE = 5
    STMT_FOR = 6
    STMT_SWITCH = 7
    STMT_LOOP = 8
    STMT_WITH = 9
    STMT_RETURN = 10
    STMT_BLOCK = 11
    STMT_STRUCT_ACCESS = 12

class FnCall:
    def __init__(self):
        self.ident = None
        self.exprs = []
    
    def add_ident(self,ident):
        self.ident = ident

    def add_expr(self,expr):
        self.exprs.append(expr)

class StructAccess:
    def __init__(self):
        self.type = None
        self.left = None
        self.right = None
    
    def add_type(self,type):
        self.type = type

    def add_left(self,left):
        self.left = left

    def add_right(self,right):
        self.right = right

class StructAccessType(Enum):
    STRUCT_ACCESS_PROPERTY = 0
    STRUCT_ACCESS_METHOD = 1

class IfStmt:
    def __init__(self):
        self.expr = None
        self.block = None
        self.elifs = []
        self.Else = None

    def add_expr(self,expr):
        self.expr = expr

    def add_block(self,block):
        self.block = block

    def add_elif(self,Elif):
        self.elifs.append(Elif)

    def add_else(self,Else):
        self.Else = Else

class ElifBlock:
    def __init__(self):
        self.expr = None
        self.block = None

    def add_expr(self,expr):
        self.expr = expr

    def add_block(self,block):
        self.block = block

class ElseBlock:
    def __init__(self):
        self.block = None

    def add_block(self,block):
        self.block = block  

class WhileStmt:
    def __init__(self):
        self.expr = None
        self.block = None

    def add_expr(self,expr):
        self.expr = expr

    def add_block(self,block):
        self.block = block

class SwitchStmt:
    def __init__(self):
        self.expr = None
        self.cases = []

    def add_expr(self,expr):
        self.expr = expr

    def add_case(self,Case):
        self.cases.append(Case)


class CaseBlock:
    def __init__(self):
        self.defaultt = 0
        self.expr = None
        self.block = None

    def add_expr(self,expr):
        self.expr = expr

    def add_block(self,block):
        self.block = block

    def default(self):
        self.defaultt = 1


class LoopStmt:
    def __init__(self):
        self.block = None

    def add_block(self,block):
        self.block = block


class ReturnStmt:
    def __init__(self):
        self.expr = None

    def add_expr(self,expr):
        self.expr = expr


class Expr:
    def __init__(self,type,val):
        self.type = type
        self.val = val

class ExprType(Enum):
    EXPR_PRIMARY = 0
    EXPR_GROUPING = 1
    EXPR_FNCALL = 2
    EXPR_RESOLVED = 3
    EXPR_UNARY = 4
    EXPR_BINARY = 5



class BinaryExpr:
    def __init__(self,left,op,right):
        self.left = left
        self.op = op
        self.right = right

class UnaryExpr:
    def __init__(self,op,right):
        self.op = op
        self.right = right

class ResolvedExpr:
    def __init__(self,left,right):
        self.left = left
        self.right = right

class FnCallExpr:
    def __init__(self,fncall):
        self.fncall = fncall

class GroupingExpr:
    def __init__(self,expr):
        self.expr = expr

class PrimaryExpr:
    def __init__(self,literal,type):
        self.literal = literal
        self.type = type

class LiteralType:
    LIT_FALSE = 0
    LIT_TRUE = 1
    LIT_INT = 2
    LIT_FLOAT = 3
    LIT_STRING = 4
    LIT_IDENT = 5


class Symbol:
    def __init__(self,name,type,kind,val = None):
        self.name = name
        self.type = type
        self.kind = kind
        self.resolved = Resolve.UNRESOLVED
        self.val = val
    
class SymbolType(Enum):
    SYMBOL_VARDECL = 0
    SYMBOL_VARASSIGN = 1
    SYMBOL_ENUM = 2
    SYMBOL_STRUCT = 3
    SYMBOL_FNDECL = 4
    SYMBOL_FNCALL = 5
    SYMBOL_IMPL = 6

class Resolve(Enum):
    UNRESOLVED = 0
    RESOLVING = 1
    RESOLVED = 2

class SymbolTable:
    def __init__(self,parent = None):
        self.parent = parent
        self.symbols = dict()

    def add(self,name,symbol):
        if self.symbols.get(name,None) != None:
            return False
        
        self.symbols[name] = symbol
        return True
    
    def lookup(self,name):
        scope = self

        while scope != None:
            symbol = scope.symbols.get(name,None)
            if symbol != None:
                return symbol
            scope = scope.parent

        return None
    

class Type:
    def __init__(self,name,type):
        self.name = name
        self.type = type

class TypeType(Enum):
    TYPE_F32 = 0
    TYPE_F64 = 1
    TYPE_I8 = 2
    TYPE_I16 = 3
    TYPE_I32 = 4
    TYPE_I64 = 5
    TYPE_U8 = 6
    TYPE_U16 = 7
    TYPE_U32 = 8
    TYPE_U64 = 9
    TYPE_BOOL = 10
    TYPE_ENUM = 11
    TYPE_STRUCT = 12

class TypeTable:
    def __init__(self):
        self.types = dict()

    def add(self,name,type):
        if self.types.get(name,None) != None:
            return False
        
        self.types[name] = type

    def lookup(self,name):
        if self.types.get(name,None) == None:
            return None
        return self.types.get(name)