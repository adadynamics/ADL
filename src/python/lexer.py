from tokens import *


tok = Token(TokenType.TOKEN_ADD,"",0,0,0,0)

class Lexer:

    def __init__(self,file_contents):
        self.file_contents = file_contents
        self.size = len(self.file_contents)
        self.index = 0
        self.tokens = []

        self.start = 0
        self.current = 0
        self.length = 0
        self.row = 1
        self.col = 0

    def peek(self,ahead = 0):
        if (self.index + ahead) >= self.size:
            return ""
        return self.file_contents[self.index + ahead]
    
    def consume(self):
        self.index += 1
        return self.file_contents[self.index - 1]
    
    def scan_tokens(self):
        print(self.size)
        while self.peek() != "":
            self.start = self.current
            self.scan_token()

        self.tokens.append(Token(TokenType.TOKEN_EOF,"eof",self.start,self.length,self.row,self.col))


    def scan_token(self):
        #print(self.index)
        char = self.consume()

        match char:
            case "*":
                self.add_token_single(TokenType.TOKEN_MUL,"*")
            case "/":
                self.add_token_single(TokenType.TOKEN_DIV,"/")
            case "+":
                self.add_token_single(TokenType.TOKEN_ADD,"+")
            case "-":
                if self.peek() == ">":
                    self.add_token_double(TokenType.TOKEN_RETPARAM,"->")
                else:
                    self.add_token_single(TokenType.TOKEN_SUB,"-")

#            case "-":
#                val = TokenType.TOKEN_RETPARAM if self.match_token(">") == True else TokenType.TOKEN_SUB
#                self.add_token_single(val)

            case ">":
                if self.peek() == "=":
                    self.add_token_double(TokenType.TOKEN_GREATER_EQUAL,">=")
                else:
                    self.add_token_single(TokenType.TOKEN_GREATER,">")

            case "<":
                if self.peek() == "=":
                    self.add_token_double(TokenType.TOKEN_LESS_EQUAL,"<=")
                else:
                    self.add_token_single(TokenType.TOKEN_LESS,"<")

            case "=":
                if self.peek() == "=":
                    self.add_token_double(TokenType.TOKEN_EQUAL,"==")
                else:
                    self.add_token_single(TokenType.TOKEN_ASSIGN,"=")

            case "!":
                if self.peek() == "=":
                    self.add_token_double(TokenType.TOKEN_NOT_EQUAL,"!=")
                else:
                    self.add_token_single(TokenType.TOKEN_NOT,"!")

            case "&":
                if self.peek() == "&":
                    self.add_token_double(TokenType.TOKEN_AND,"&&")
                else:
                    self.add_token_single(TokenType.TOKEN_BITWISE_AND,"&")

            case "|":
                if self.peek() == "|":
                    self.add_token_double(TokenType.TOKEN_OR,"||")
                else:
                    self.add_token_single(TokenType.TOKEN_BITWISE_OR,"|")
            
            case "^":
                self.add_token_single(TokenType.TOKEN_BITWISE_XOR,"^")

            case "~":
                self.add_token_single(TokenType.TOKEN_BITWISE_NOT,"~")

            case ":":
                self.add_token_single(TokenType.TOKEN_COLON)
            case ";":
                self.add_token_single(TokenType.TOKEN_SEMI_COLON)
            case "(":
                self.add_token_single(TokenType.TOKEN_LBRACE)
            case ")":
                self.add_token_single(TokenType.TOKEN_RBRACE)
            case "_":
                self.add_token_single(TokenType.TOKEN_UNDERSCORE)
            case ",":
                self.add_token_single(TokenType.TOKEN_COMMA)
            case ".":
                self.add_token_single(TokenType.TOKEN_DOT)
            case " ":
                self.update_col(1)
            case "\r":
                self.update_col(1)
            case "\t":
                self.update_col(4)
            case "\n":
                self.update_row(1)
                self.update_col(1)
            
            case 'a' | 'b' | 'c' | 'd' | 'e' | 'f' | 'g' | 'h' | 'i' | 'j' | 'k' | 'l' | 'm' \
             | 'n' | 'o' | 'p' | 'q' | 'r' | 's' | 't' | 'u' | 'v' | 'w' | 'x' | 'y' | 'z' \
             | 'A' | 'B' | 'C' | 'D' | 'E' | 'F' | 'G' | 'H' | 'I' | 'J' | 'K' | 'L' | 'M' \
             | 'N' | 'O' | 'P' | 'Q' | 'R' | 'S' | 'T' | 'U' | 'V' | 'W' | 'X' | 'Y' | 'Z' \
             | '_':
                buf = char
                while self.peek().isalnum() or self.peek() == "_":
                    buf += self.consume()
                self.update_col(len(buf))



                if buf == "and":
                    self.add_token(TokenType.TOKEN_KEYWORD_AND)
                elif buf == "break":
                    self.add_token(TokenType.TOKEN_KEYWORD_BREAK)
                elif buf == "bool":
                    self.add_token(TokenType.TOKEN_KEYWORD_BOOL)
                elif buf == "case":
                    self.add_token(TokenType.TOKEN_KEYWORD_CASE)
                elif buf == "const":
                    self.add_token(TokenType.TOKEN_KEYWORD_CONST)
                elif buf == "continue":
                    self.add_token(TokenType.TOKEN_KEYWORD_CONTINUE)
                elif buf == "default":
                    self.add_token(TokenType.TOKEN_KEYWORD_DEFAULT)
                elif buf == "do":
                    self.add_token(TokenType.TOKEN_KEYWORD_DO)
                elif buf == "elif":
                    self.add_token(TokenType.TOKEN_KEYWORD_ELIF)
                elif buf == "else":
                    self.add_token(TokenType.TOKEN_KEYWORD_ELSE)
                elif buf == "enum":
                    self.add_token(TokenType.TOKEN_KEYWORD_ENUM)
                elif buf == "f32":
                    self.add_token(TokenType.TOKEN_KEYWORD_F32)
                elif buf == "f64":
                    self.add_token(TokenType.TOKEN_KEYWORD_F64)
                elif buf == "false":
                    self.add_token(TokenType.TOKEN_KEYWORD_FALSE)
                elif buf == "fn":
                    self.add_token(TokenType.TOKEN_KEYWORD_FN)
                elif buf == "for":
                    self.add_token(TokenType.TOKEN_KEYWORD_FOR)
                elif buf == "i8":
                    self.add_token(TokenType.TOKEN_KEYWORD_I8)
                elif buf == "i16":
                    self.add_token(TokenType.TOKEN_KEYWORD_I16)
                elif buf == "i32":
                    self.add_token(TokenType.TOKEN_KEYWORD_I32)
                elif buf == "i64":
                    self.add_token(TokenType.TOKEN_KEYWORD_I64)
                elif buf == "if":
                    self.add_token(TokenType.TOKEN_KEYWORD_IF)
                elif buf == "impl":
                    self.add_token(TokenType.TOKEN_KEYWORD_IMPL)
                elif buf == "loop":
                    self.add_token(TokenType.TOKEN_KEYWORD_LOOP)
                elif buf == "not":
                    self.add_token(TokenType.TOKEN_KEYWORD_NOT)
                elif buf == "null":
                    self.add_token(TokenType.TOKEN_KEYWORD_NULL)
                elif buf == "or":
                    self.add_token(TokenType.TOKEN_KEYWORD_OR)
                elif buf == "pass":
                    self.add_token(TokenType.TOKEN_KEYWORD_PASS)
                elif buf == "pub":
                    self.add_token(TokenType.TOKEN_KEYWORD_PUB)
                elif buf == "return":
                    self.add_token(TokenType.TOKEN_KEYWORD_RETURN)
                elif buf == "self":
                    self.add_token(TokenType.TOKEN_KEYWORD_SELF)
                elif buf == "struct":
                    self.add_token(TokenType.TOKEN_KEYWORD_STRUCT)
                elif buf == "switch":
                    self.add_token(TokenType.TOKEN_KEYWORD_SWITCH)
                elif buf == "true":
                    self.add_token(TokenType.TOKEN_KEYWORD_TRUE)
                elif buf == "u8":
                    self.add_token(TokenType.TOKEN_KEYWORD_U8)
                elif buf == "u16":
                    self.add_token(TokenType.TOKEN_KEYWORD_U16)
                elif buf == "u32":
                    self.add_token(TokenType.TOKEN_KEYWORD_U32)
                elif buf == "u64":
                    self.add_token(TokenType.TOKEN_KEYWORD_U64)
                elif buf == "use":
                    self.add_token(TokenType.TOKEN_KEYWORD_USE)
                elif buf == "void":
                    self.add_token(TokenType.TOKEN_KEYWORD_VOID)
                elif buf == "while":
                    self.add_token(TokenType.TOKEN_KEYWORD_WHILE)
                elif buf == "with":
                    self.add_token(TokenType.TOKEN_KEYWORD_WITH)
                else:
                    self.add_token(TokenType.TOKEN_IDENT,buf)
            case '0' | '1' | '2' | '3' | '4' | '5' | '6' | '7' | '8' | '9':
                buf = char
                while self.peek().isdigit():
                    buf += self.consume()
                
                if(self.peek() == "."):
                    buf += self.consume()
                    while self.peek().isdigit():
                        buf += self.consume()
                    self.add_token(TokenType.TOKEN_LITERAL_FLOAT,buf)
                else:
                    self.add_token(TokenType.TOKEN_LITERAL_INT,buf)

                self.update_col(len(buf))
            
            case "\"":
                buf = ""
                while self.peek() != "\"":
                    buf += self.consume()

                self.consume()
                self.add_token(TokenType.TOKEN_LITERAL_STRING,buf)
                self.update_col(len(buf) + 2)
                print(len(buf) + 2)

    def match_token(self,expected):
        if self.peek() != expected:
            return False
        self.consume()
        return True

    def update_row(self,row_dx):
        self.row += row_dx
        self.col = 0

    def update_col(self,col_dx):
        self.col += col_dx
        self.current += col_dx
        self.length = self.current - self.start

    def add_token_double(self,type,string = ""):
        self.consume()
        self.add_token(type,string)
        self.update_col(2)

    def add_token_single(self,type,string = ""):
        self.add_token(type,string)
        self.update_col(1)

    def add_token(self,type,string = ""):
        self.tokens.append(Token(type,string,self.start,self.length,self.row,self.col))
