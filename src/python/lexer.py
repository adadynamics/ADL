from tokens import *


#tok = Token(TokenType.TOKEN_ADD,"",0,0,0,0)

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
        self.line = 0
        self.error = False

    def peek(self,ahead = 0):
        if (self.index + ahead) >= self.size:
            return ""
        return self.file_contents[self.index + ahead]
    
    def consume(self):
        self.index += 1
        return self.file_contents[self.index - 1]
    
    def print_error(self,token,msg):
        end = token.start + token.length
        string = self.file_contents[token.line:end]
        row_width = len(str(token.row))
        col_width = len(str(token.col))
        offset = token.start - token.line + 2
        

        print(f" {msg} at line {token.row} col {token.col}\n")
        print(f"                {token.row}:{token.col} |  {string}")
        print(f"                ",end="")
        for i in range(row_width):
            print(" ",end="")
        print(" ",end="")
        
        for i in range(col_width):
            print(" ",end="")
        print("  ",end="")
        
        for i in range(offset):
            print(" ",end="")
        print("^")

    def print_errors(self):
        for token in self.tokens:
            if token.type == TokenType.TOKEN_ERROR_INVALID_CHARACTER:
                if self.error == False:
                    print("\n------------- Lexical Errors ----------------\n")

                self.error = True
                self.print_error(token,f"invalid token '{token.string}'")

            elif token.type == TokenType.TOKEN_ERROR_UNTERMINATED_STRING:
                if self.error == False:
                    print("\n------------- Lexical Errors ----------------\n")

                self.error = False
                
                self.print_error(token,"unterminated string literal")
                


    def scan_tokens(self):
        while self.peek() != "":
            self.start = self.current
            self.scan_token()

        #self.tokens.append(Token(TokenType.TOKEN_EOF,"eof",self.start,self.length,self.row,self.col))


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
                if self.peek() == ":":
                    self.add_token_double(TokenType.TOKEN_RESOLUTION,"::")
                else:
                    self.add_token_single(TokenType.TOKEN_COLON)
            case ";":
                self.add_token_single(TokenType.TOKEN_SEMI_COLON)
            case "(":
                self.add_token_single(TokenType.TOKEN_LBRACE)
            case ")":
                self.add_token_single(TokenType.TOKEN_RBRACE)
            case ",":
                self.add_token_single(TokenType.TOKEN_COMMA)
            case ".":
                self.add_token_single(TokenType.TOKEN_DOT,".")
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


                if buf == "alloc":
                    if self.peek() == "!":
                        buf += self.consume()
                        self.update_col(len(buf))
                        self.add_token(TokenType.TOKEN_KEYWORD_ALLOC,buf)
                        return
                    else:
                        self.update_col(len(buf))
                else:
                    self.update_col(len(buf))

                if buf == "and":
                    self.add_token(TokenType.TOKEN_KEYWORD_AND,buf)
                elif buf == "alloc":
                    if self.peek() == "!":
                        self.add_token(TokenType.TOKEN_KEYWORD_ALLOC,buf)
                elif buf == "break":
                    self.add_token(TokenType.TOKEN_KEYWORD_BREAK,buf)
                elif buf == "bool":
                    self.add_token(TokenType.TOKEN_KEYWORD_BOOL,buf)
                elif buf == "case":
                    self.add_token(TokenType.TOKEN_KEYWORD_CASE,buf)
                elif buf == "const":
                    self.add_token(TokenType.TOKEN_KEYWORD_CONST,buf)
                elif buf == "continue":
                    self.add_token(TokenType.TOKEN_KEYWORD_CONTINUE,buf)
                elif buf == "default":
                    self.add_token(TokenType.TOKEN_KEYWORD_DEFAULT,buf)
                elif buf == "do":
                    self.add_token(TokenType.TOKEN_KEYWORD_DO,buf)
                elif buf == "elif":
                    self.add_token(TokenType.TOKEN_KEYWORD_ELIF,buf)
                elif buf == "else":
                    self.add_token(TokenType.TOKEN_KEYWORD_ELSE,buf)
                elif buf == "enum":
                    self.add_token(TokenType.TOKEN_KEYWORD_ENUM,buf)
                elif buf == "f32":
                    self.add_token(TokenType.TOKEN_KEYWORD_F32,buf)
                elif buf == "f64":
                    self.add_token(TokenType.TOKEN_KEYWORD_F64,buf)
                elif buf == "false":
                    self.add_token(TokenType.TOKEN_KEYWORD_FALSE,buf)
                elif buf == "__fini__":
                    self.add_token(TokenType.TOKEN_KEYWORD_FINI,buf)
                elif buf == "fn":
                    self.add_token(TokenType.TOKEN_KEYWORD_FN,buf)
                elif buf == "for":
                    self.add_token(TokenType.TOKEN_KEYWORD_FOR,buf)
                elif buf == "i8":
                    self.add_token(TokenType.TOKEN_KEYWORD_I8,buf)
                elif buf == "i16":
                    self.add_token(TokenType.TOKEN_KEYWORD_I16,buf)
                elif buf == "i32":
                    self.add_token(TokenType.TOKEN_KEYWORD_I32,buf)
                elif buf == "i64":
                    self.add_token(TokenType.TOKEN_KEYWORD_I64,buf)
                elif buf == "if":
                    self.add_token(TokenType.TOKEN_KEYWORD_IF,buf)
                elif buf == "impl":
                    self.add_token(TokenType.TOKEN_KEYWORD_IMPL,buf)
                elif buf == "__init__":
                    self.add_token(TokenType.TOKEN_KEYWORD_INIT,buf)
                elif buf == "loop":
                    self.add_token(TokenType.TOKEN_KEYWORD_LOOP,buf)
                elif buf == "not":
                    self.add_token(TokenType.TOKEN_KEYWORD_NOT,buf)
                elif buf == "null":
                    self.add_token(TokenType.TOKEN_KEYWORD_NULL,buf)
                elif buf == "or":
                    self.add_token(TokenType.TOKEN_KEYWORD_OR,buf)
                elif buf == "pass":
                    self.add_token(TokenType.TOKEN_KEYWORD_PASS,buf)
                elif buf == "pub":
                    self.add_token(TokenType.TOKEN_KEYWORD_PUB,buf)
                elif buf == "return":
                    self.add_token(TokenType.TOKEN_KEYWORD_RETURN,buf)
                elif buf == "self":
                    self.add_token(TokenType.TOKEN_KEYWORD_SELF,buf)
                elif buf == "struct":
                    self.add_token(TokenType.TOKEN_KEYWORD_STRUCT,buf)
                elif buf == "switch":
                    self.add_token(TokenType.TOKEN_KEYWORD_SWITCH,buf)
                elif buf == "true":
                    self.add_token(TokenType.TOKEN_KEYWORD_TRUE,buf)
                elif buf == "u8":
                    self.add_token(TokenType.TOKEN_KEYWORD_U8,buf)
                elif buf == "u16":
                    self.add_token(TokenType.TOKEN_KEYWORD_U16,buf)
                elif buf == "u32":
                    self.add_token(TokenType.TOKEN_KEYWORD_U32,buf)
                elif buf == "u64":
                    self.add_token(TokenType.TOKEN_KEYWORD_U64,buf)
                elif buf == "use":
                    self.add_token(TokenType.TOKEN_KEYWORD_USE,buf)
                elif buf == "void":
                    self.add_token(TokenType.TOKEN_KEYWORD_VOID,buf)
                elif buf == "while":
                    self.add_token(TokenType.TOKEN_KEYWORD_WHILE,buf)
                elif buf == "with":
                    self.add_token(TokenType.TOKEN_KEYWORD_WITH,buf)
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
                error = False
                buf = ""
                while self.peek() != "\"":
                    if self.peek() == "":
                        error = True
                        break

                    buf += self.consume()

                if error == True:
                    self.add_token(TokenType.TOKEN_ERROR_UNTERMINATED_STRING,buf)
                else:
                    self.consume()
                    self.add_token(TokenType.TOKEN_LITERAL_STRING,buf)
                
                self.update_col(len(buf) + 2)
                
            case _:
                self.add_token_single(TokenType.TOKEN_ERROR_INVALID_CHARACTER,char)

    def match_token(self,expected):
        if self.peek() != expected:
            return False
        self.consume()
        return True

    def update_row(self,row_dx):
        self.row += row_dx
        self.line = self.index
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
        self.tokens.append(Token(type,string,self.start,self.length,self.row,self.col,self.line))
