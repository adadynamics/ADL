from enum import Enum


class TokenType(Enum):
#   ARITHMETIC OPERATORS

    TOKEN_MUL = "*"
    TOKEN_DIV = "/"
    TOKEN_ADD = "+"
    TOKEN_SUB = "-"

#   COMPARISON OPERATORS

    TOKEN_GREATER = ">"
    TOKEN_LESS = "<"
    TOKEN_GREATER_EQUAL = ">="
    TOKEN_LESS_EQUAL = "<="

#   EQUALITY OPERATORS

    TOKEN_EQUAL = "=="
    TOKEN_NOT_EQUAL = "!="

#   BITWISE OPERATORS

    TOKEN_BITWISE_AND = "&"
    TOKEN_BITWISE_OR = "|"
    TOKEN_BITWISE_XOR = "^"
    TOKEN_BITWISE_NOT = "~"

#   LOGICAL OPERATORS

    TOKEN_AND = "&&"
    TOKEN_OR  = "||"
    TOKEN_NOT = "!"

#   ASSIGNMENT OPERATORS

    TOKEN_ASSIGN = "="

#   MISCELLENIOUS SYMBOLS

    TOKEN_COLON = ":"
    TOKEN_SEMI_COLON = ";"
    TOKEN_LBRACE = "("
    TOKEN_RBRACE = ")"
    TOKEN_UNDERSCORE = "_"
    TOKEN_RETPARAM = "->"
    TOKEN_COMMA = ","
    TOKEN_DOT = "."

#   IDENTIFIERS

    TOKEN_IDENT = "0"

#   LITERALS

    TOKEN_LITERAL_INT = "1"
    TOKEN_LITERAL_FLOAT = "2"
    TOKEN_LITERAL_STRING = "3"

#   KEYWORDS

    TOKEN_KEYWORD_AND = "and"
    TOKEN_KEYWORD_BREAK = "break"
    TOKEN_KEYWORD_BOOL = "bool"
    TOKEN_KEYWORD_CASE = "case"
    TOKEN_KEYWORD_CONST = "const"
    TOKEN_KEYWORD_CONTINUE = "continue"
    TOKEN_KEYWORD_DEFAULT = "default"
    TOKEN_KEYWORD_DO = "do"
    TOKEN_KEYWORD_ELIF = "elif"
    TOKEN_KEYWORD_ELSE = "else"
    TOKEN_KEYWORD_ENUM = "enum"
    TOKEN_KEYWORD_F32 = "f32"
    TOKEN_KEYWORD_F64 = "f64"
    TOKEN_KEYWORD_FALSE = "false"
    TOKEN_KEYWORD_FN = "fn"
    TOKEN_KEYWORD_FOR = "for"
    TOKEN_KEYWORD_I8 = "i8"
    TOKEN_KEYWORD_I16 = "i16"
    TOKEN_KEYWORD_I32 = "i32"
    TOKEN_KEYWORD_I64 = "i64"
    TOKEN_KEYWORD_IF = "if"
    TOKEN_KEYWORD_IMPL = "impl"
    TOKEN_KEYWORD_LOOP = "loop"
    TOKEN_KEYWORD_NOT = "not"
    TOKEN_KEYWORD_NULL = "null"
    TOKEN_KEYWORD_OR = "or"
    TOKEN_KEYWORD_PASS = "pass"
    TOKEN_KEYWORD_PUB = "pub"
    TOKEN_KEYWORD_RETURN = "return"
    TOKEN_KEYWORD_SELF = "self"
    TOKEN_KEYWORD_STRUCT = "struct"
    TOKEN_KEYWORD_SWITCH = "switch"
    TOKEN_KEYWORD_TRUE = "true"
    TOKEN_KEYWORD_U8 = "u8"
    TOKEN_KEYWORD_U16 = "u16"
    TOKEN_KEYWORD_U32 = "u32"
    TOKEN_KEYWORD_U64 = "u64"
    TOKEN_KEYWORD_USE = "use"
    TOKEN_KEYWORD_VOID = "void"
    TOKEN_KEYWORD_WHILE = "while"
    TOKEN_KEYWORD_WITH = "with"

#   OTHERS

    TOKEN_ERROR = "4"
    TOKEN_EOF = "5"


class Token:
    def __init__(self,type,string,start,length,row,col):
        self.type = type
        self.string = string
        self.start = start
        self.length = length
        self.row = row
        self.col = col


