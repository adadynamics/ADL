from c4_ast import *


class Parser:
    def __init__(self,tokens,file_contents):
        self.file_contents = file_contents
        self.index = 0
        self.tokens = tokens
        self.size = len(self.tokens)
        self.programs = Programs()
        self.in_impl = False
        self.previous_block = None

    def peek(self,ahead = 0):
        if self.index + ahead >= self.size:
            return False

        return self.tokens[self.index + ahead]


    def consume(self):
        self.index += 1
        return self.tokens[self.index - 1]
    
    def print_error(self,token,msg):
        end = token.start + token.length
        string = self.file_contents[token.line:end]
        row_width = len(str(token.row))
        col_width = len(str(token.col))
        offset = token.start - token.line + 2
        col = token.col - token.length

        print(f" {msg} at line {token.row} col {col}\n")
        print(f"                {token.row}:{col} |  {string}")
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

    def synchronize_decl(self):

        while self.peek() != False:
            match self.peek().type:
                case TokenType.TOKEN_KEYWORD_ENUM | TokenType.TOKEN_KEYWORD_FN | TokenType.TOKEN_KEYWORD_IMPL | TokenType.TOKEN_KEYWORD_STRUCT | TokenType.TOKEN_IDENT:
                    break
                case _:
                    self.consume()

    def synchronize_stmt(self):

        while self.peek() != False:
            match self.peek().type:
                case TokenType.TOKEN_KEYWORD_ENUM | TokenType.TOKEN_KEYWORD_FN | TokenType.TOKEN_KEYWORD_IMPL | TokenType.TOKEN_KEYWORD_STRUCT | TokenType.TOKEN_IDENT | TokenType.TOKEN_KEYWORD_IF | TokenType.TOKEN_KEYWORD_WHILE | TokenType.TOKEN_KEYWORD_SWITCH | TokenType.TOKEN_KEYWORD_WITH | TokenType.TOKEN_KEYWORD_LOOP | TokenType.TOKEN_KEYWORD_RETURN | TokenType.TOKEN_KEYWORD_DO:
                    break
                case _:
                    self.consume()

    def parse_programs(self):
        self.programs = Programs()

        while self.peek() != False:
            self.programs.add(self.parse_program())

    
    def parse_program(self):
        program = Program()

        match self.peek().type:
            case TokenType.TOKEN_KEYWORD_ENUM:
                program.add(DeclType.DECL_ENUM,self.parse_enum_decl())

            case TokenType.TOKEN_KEYWORD_STRUCT:
                program.add(DeclType.DECL_STRUCT,self.parse_struct_decl())

            case TokenType.TOKEN_KEYWORD_IMPL:
                program.add(DeclType.DECL_IMPL,self.parse_impl_decl())

            case TokenType.TOKEN_KEYWORD_FN:
               program.add(DeclType.DECL_FN, self.parse_fn_decl())

            case TokenType.TOKEN_IDENT:
                if self.peek(1).type == TokenType.TOKEN_ASSIGN:
                    program.add(DeclType.DECL_VARASSIGN,self.parse_var_assign())
                else:
                    program.add(DeclType.DECL_VARDECL,self.parse_var_decl())
            case _:
                token = self.consume()
                self.print_error(token,f"unknown declarator '{token.string}'")
                self.synchronize_decl()
                
            
        return program
    
    def parse_enum_decl(self):
        self.consume()
        enum = EnumDecl()

        if self.peek() != TokenType.TOKEN_IDENT:
            tmp_token = self.consume()
            self.print_error(tmp_token,f"expected an identifier after impl instead of '{tmp_token.string}'")
            self.synchronize_decl()
            return
        else:
            enum.add_ident(self.consume())

        if self.peek().type != TokenType.TOKEN_COLON:
            tmp_token = self.consume()
            self.print_error(tmp_token,f"expected an : after identifier instead of '{tmp_token.string}'")
        else:
            self.consume()

        while self.peek().type != TokenType.TOKEN_COLON:
            enum.add_constant(self.consume())

        if self.peek().type != TokenType.TOKEN_COLON:
            tmp_token = self.consume()
            self.print_error(tmp_token,f"expected an : after identifier instead of '{tmp_token.string}'")
        else:
            self.consume()

        return enum
    

    def parse_struct_decl(self):
        self.consume()
        struct = StructDecl()

        if self.peek().type != TokenType.TOKEN_IDENT:
            tmp_token = self.consume()
            self.print_error(tmp_token,f"expected an identifier after struct instead of '{tmp_token.string}'")
        else:
            struct.add_ident(self.consume())

        if self.peek().type != TokenType.TOKEN_COLON:
            tmp_token = self.consume()
            self.print_error(tmp_token,f"expected an : after identifier instead of '{tmp_token.string}'")
        else:
            self.consume()

        while self.peek().type != TokenType.TOKEN_COLON:
            struct.add_vard(self.parse_var_decl(struct))
        
        if self.peek().type != TokenType.TOKEN_COLON:
            tmp_token = self.consume()
            self.print_error(tmp_token,f"expected an : after identifier instead of '{tmp_token.string}'")
        else:
            self.consume()


        return struct
    
    def parse_impl_decl(self):
        self.consume()
        impl = ImplDecl()
        self.in_impl = True

        if self.peek().type != TokenType.TOKEN_IDENT:
            tmp_token = self.consume()
            self.print_error(tmp_token,f"expected an identifier after impl instead of '{tmp_token.string}'")
        else:
            impl.add_ident(self.consume())

        if self.peek().type != TokenType.TOKEN_COLON:
            tmp_token = self.consume()
            self.print_error(tmp_token,f"expected an : after identifier instead of '{tmp_token.string}'")
        else:
            self.consume()


        while self.peek().type != TokenType.TOKEN_COLON:
            if self.peek().type != TokenType.TOKEN_KEYWORD_FN:
                tmp_token = self.consume()
                self.print_error(tmp_token,f"expected an fn after : in impl {impl.ident} instead of '{tmp_token.string}'")
            else:
                impl.add_fn(self.parse_fn_decl())

        if self.peek().type != TokenType.TOKEN_COLON:
            tmp_token = self.consume()
            self.print_error(tmp_token,f"expected an : after identifier instead of '{tmp_token.string}'")
        else:
            self.consume()
            
        return impl
    
    def parse_fn_decl(self):
        self.consume()
        fn = FnDecl()
        self.previous_block = None

        if self.peek().type == TokenType.TOKEN_KEYWORD_INIT and self.in_impl == False:
            tmp_token = self.consume()
            self.print_error(tmp_token,f"__init__ constructor used outside an impl declaration ")

        elif self.peek().type == TokenType.TOKEN_KEYWORD_FINI and self.in_impl == False:
            tmp_token = self.consume()
            self.print_error(tmp_token,f"__fini__ constructor used outside an impl declaration ")
            
        elif self.peek().type != TokenType.TOKEN_IDENT:
            tmp_token = self.consume()
            self.print_error(tmp_token,f"expected an identifier after fn instead of '{tmp_token.string}'")
        else:
            fn.add_ident(self.consume())

        if self.peek().type != TokenType.TOKEN_LBRACE:
            tmp_token = self.consume()
            self.print_error(tmp_token,f"expected an ( after identifier instead of '{tmp_token.string}'")
        else:
            self.consume()


        while self.peek().type != TokenType.TOKEN_RBRACE:
            fn.add_arg(self.parse_var_decl(fn.block))

            if self.peek().type == TokenType.TOKEN_RBRACE:
                break

            if self.peek().type != TokenType.TOKEN_COMMA:
                tmp_token = self.consume()
                self.print_error(tmp_token,f"expected a , after identifier instead of '{tmp_token.type}'")
            else:
                self.consume()

        if self.peek().type != TokenType.TOKEN_RBRACE:
            tmp_token = self.consume()
            self.print_error(tmp_token,f"expected an ) after identifier instead of '{tmp_token.string}'")
        else:
            self.consume()


        if self.peek().type != TokenType.TOKEN_RETPARAM:
            tmp_token = self.consume()
            self.print_error(tmp_token,f"expected a -> after ) instead of '{tmp_token.string}'")
        else:
            self.consume()
            fn.add_retparam(self.consume())

        if self.peek().type != TokenType.TOKEN_COLON:
            tmp_token = self.consume()
            self.print_error(tmp_token,f"expected a : after -> instead of '{tmp_token.string}'")
        else:
            block = None
            fn.add_block(self.parse_block_stmt(block))
            return fn
    

    
    def parse_var_decl(self,block=None):
        var = VarDecl()

        if not self.token_type(self.peek()) and self.peek().type != TokenType.TOKEN_IDENT:
            tmp_token = self.consume()
            self.print_error(tmp_token,f"expected a type before identifier instead of '{tmp_token.string}'")
        else:
            var.add_type(self.consume())

        while self.peek().type == TokenType.TOKEN_MUL:
            self.consume()
            var.ptr += 1

        if self.peek().type != TokenType.TOKEN_IDENT:
            tmp_token = self.consume()
            self.print_error(tmp_token,f"expected an identifier after type instead of '{tmp_token.string}'")
        else:
            var.add_ident(self.consume())

        if self.peek().type != TokenType.TOKEN_ASSIGN:
            return var
        
        self.consume()

        if self.peek().type == TokenType.TOKEN_KEYWORD_ALLOC:
            var.add_expr(self.parse_primary_expr())
            var.add_alloc(AllocType.ALLOC_OWNER)

        else:
            var.add_expr(self.parse_expr())
        
        return var
    
    def token_type(self,type):
        match type:
            case TokenType.TOKEN_KEYWORD_F32 | TokenType.TOKEN_KEYWORD_F64 | TokenType.TOKEN_KEYWORD_I8 | TokenType.TOKEN_KEYWORD_I16 | TokenType.TOKEN_KEYWORD_I32 | TokenType.TOKEN_KEYWORD_I64 | TokenType.TOKEN_KEYWORD_U8 | TokenType.TOKEN_KEYWORD_U16 | TokenType.TOKEN_KEYWORD_U32 | TokenType.TOKEN_KEYWORD_U64 | TokenType.TOKEN_KEYWORD_BOOL:
                return True
            case _:
                return False

    def parse_var_assign(self,block):
        var = VarAssign()

        if self.peek().type != TokenType.TOKEN_IDENT:
            tmp_token = self.consume()
            self.print_error(tmp_token,f"expected an identifier after type instead of '{tmp_token.string}'")
        else:
            var.add_ident(self.consume())

        if self.peek().type != TokenType.TOKEN_ASSIGN:
            tmp_token = self.consume()
            self.print_error(tmp_token,f"expected a = identifier instead of '{tmp_token.string}'")
        else:
            self.consume()

        if self.peek().type == TokenType.TOKEN_KEYWORD_ALLOC:
            var.add_expr(self.parse_primary_expr())
            var.add_alloc(AllocType.ALLOC_OWNER)
        else:
            var.add_expr(self.parse_expr())

        return var
    
    def parse_block_stmt(self,parent = None):
        block = BlockStmt()

        if self.peek().type != TokenType.TOKEN_COLON:
            tmp_token = self.consume()
            self.print_error(tmp_token,f"expected a : instead of '{tmp_token.string}'")
        else:
            self.consume()

        while self.peek().type != TokenType.TOKEN_COLON:
            block.add(self.parse_stmt(block))

        if self.peek().type != TokenType.TOKEN_COLON:
            tmp_token = self.consume()
            self.print_error(tmp_token,f"expected a : instead of '{tmp_token.string}'")
        else:
            self.consume()

        
        block.add_parent(parent)
        self.previous_block = block
        return block
    
    def parse_stmt(self,block):
        stmt = Stmt()

        match self.peek().type:
            case TokenType.TOKEN_IDENT:
                if self.peek(1).type == TokenType.TOKEN_LBRACE:
                    stmt.add_type(StmtType.STMT_FNCALL)
                    stmt.add_stmt(self.parse_fncall(block))

                elif self.peek(1).type == TokenType.TOKEN_DOT:
                    stmt.add_type(StmtType.STMT_STRUCT_ACCESS)
                    stmt.add_stmt(self.parse_struct_access(block))

                elif self.peek(1).type == TokenType.TOKEN_ASSIGN:
                    stmt.add_type(StmtType.STMT_VARASSIGN)
                    stmt.add_stmt(self.parse_var_assign(block))
                
                else:
                    stmt.add_type(StmtType.STMT_VARDECL)
                    stmt.add_stmt(self.parse_var_decl(block))

            case TokenType.TOKEN_KEYWORD_IF:
                stmt.add_type(StmtType.STMT_IF)
                stmt.add_stmt(self.parse_if_stmt(block))
            
            case TokenType.TOKEN_KEYWORD_WHILE:
                stmt.add_type(StmtType.STMT_WHILE)
                stmt.add_stmt(self.parse_while_stmt(block))
            
            case TokenType.TOKEN_KEYWORD_SWITCH:
                stmt.add_type(StmtType.STMT_SWITCH)
                stmt.add_stmt(self.parse_switch_stmt(block))
            
            case TokenType.TOKEN_KEYWORD_LOOP:
                stmt.add_type(StmtType.STMT_LOOP)
                stmt.add_stmt(self.parse_loop_stmt(block))


            case TokenType.TOKEN_KEYWORD_RETURN:
                stmt.add_type(StmtType.STMT_RETURN)
                stmt.add_stmt(self.parse_return_stmt(block))
            
            case _:
                tmp_token = self.consume()
                self.print_error(tmp_token,f"unknown statement ")

        return stmt
    
    def parse_fncall(self,block):
        fn = FnCall()
        if self.peek().type != TokenType.TOKEN_IDENT:
            tmp_token = self.consume()
            self.print_error(tmp_token,f"expected an identifier instead of '{tmp_token.string}'")
        else:
            fn.add_ident(self.consume())

        if self.peek().type != TokenType.TOKEN_LBRACE:
            tmp_token = self.consume()
            self.print_error(tmp_token,f"expected a ( after identifier instead of '{tmp_token.string}'")
        else:
            self.consume()
        
        while self.peek().type != TokenType.TOKEN_RBRACE:
            fn.add_expr(self.parse_expr())
            if self.peek().type == TokenType.TOKEN_COMMA:
                self.consume()

        if self.peek().type != TokenType.TOKEN_RBRACE:
            tmp_token = self.consume()
            self.print_error(tmp_token,f"expected ) instead of '{tmp_token.string}'")
        else:
            self.consume()

        return fn
    
    def parse_struct_access(self,block):
        struct = StructAccess()

        struct.left = self.consume()

        if self.peek().type != TokenType.TOKEN_DOT:
            tmp_token = self.consume()
            self.print_error(tmp_token,f"expected a . after identifier instead of '{tmp_token.string}'")
        else:
            self.consume()

        if self.peek(1).type == TokenType.TOKEN_LBRACE:
            struct.add_type(StructAccessType.STRUCT_ACCESS_METHOD)
            struct.right = self.parse_fncall()
        else:
            struct.add_type(StructAccessType.STRUCT_ACCESS_PROPERTY)
            struct.right = self.parse_expr()

        return struct



    
    def parse_if_stmt(self,block):
        If = IfStmt()

        if self.peek().type != TokenType.TOKEN_KEYWORD_IF:
            tmp_token = self.consume()
            self.print_error(tmp_token,f"expected an if instead of '{tmp_token.string}'")
        else:
            self.consume()

        If.add_expr(self.parse_expr())

        if self.peek().type != TokenType.TOKEN_COLON:
            tmp_token = self.consume()
            self.print_error(tmp_token,f"expected a : after expression instead of '{tmp_token.string}'")
        else:
            If.add_block(self.parse_block_stmt(block))

        while self.peek().type == TokenType.TOKEN_KEYWORD_ELIF:
            self.consume()
            Elif = ElifBlock()
            Elif.add_expr(self.parse_expr())
            
            if self.peek().type != TokenType.TOKEN_COLON:
                tmp_token = self.consume()
                self.print_error(tmp_token,f"expected a : after expression instead of '{tmp_token.string}'")
            else:
                Elif.add_block(self.parse_block_stmt(block))
                If.add_elif(Elif)

        if self.peek().type != TokenType.TOKEN_KEYWORD_ELSE:
            pass
        else:
            self.consume()
            Else = ElseBlock()
            if self.peek().type != TokenType.TOKEN_COLON:
                tmp_token = self.consume()
                self.print_error(tmp_token,f"expected a : after else instead of '{tmp_token.string}'")
            else:
                Else.add_block(self.parse_block_stmt(block))
                If.add_else(Else)

        return If
    

    def parse_while_stmt(self,block):
        While = WhileStmt()

        if self.peek().type != TokenType.TOKEN_KEYWORD_WHILE:
            tmp_token = self.consume()
            self.print_error(tmp_token,f"expected a while instead of '{tmp_token.string}'")
        else:
            self.consume()

        While.add_expr(self.parse_expr())

        if self.peek().type != TokenType.TOKEN_COLON:
            tmp_token = self.consume()
            self.print_error(tmp_token,f"expected a : after expression instead of '{tmp_token.string}'")
        else:
            While.add_block(self.parse_block_stmt(block))

        return While
    
    def parse_switch_stmt(self,block):
        switch = SwitchStmt()

        if self.peek().type != TokenType.TOKEN_KEYWORD_SWITCH:
            tmp_token = self.consume()
            self.print_error(tmp_token,f"expected a switch instead of '{tmp_token.string}'")
        else:
            self.consume()

        switch.add_expr(self.parse_expr())

        if self.consume().type != TokenType.TOKEN_COLON:
            tmp_token = self.consume()
            self.print_error(tmp_token,f"expected a : after expression instead of '{tmp_token.string}'")
        else:
            self.consume()
        
        while self.peek().type == TokenType.TOKEN_KEYWORD_CASE:
            Case = CaseBlock()
            self.consume()
            Case.add_expr(self.parse_expr())
            
            if self.peek().type != TokenType.TOKEN_COLON:
                tmp_token = self.consume()
                self.print_error(tmp_token,f"expected a : after expression instead of '{tmp_token.string}'")
            else:
                Case.add_block(self.parse_block_stmt(block))
                switch.add_case(Case)

        if self.peek().type != TokenType.TOKEN_KEYWORD_DEFAULT:
            pass
        else:
            Case = CaseBlock()
            Case.default()
            self.consume()
            if self.peek().type != TokenType.TOKEN_COLON:
                tmp_token = self.consume()
                self.print_error(tmp_token,f"expected a : instead of '{tmp_token.string}'")
            else:
                Case.add_block(self.parse_block_stmt(block))
                switch.add_case(Case)

        if self.consume().type != TokenType.TOKEN_COLON:
            tmp_token = self.consume()
            self.print_error(tmp_token,f"expected a : instead of '{tmp_token.string}'")
        return switch

    def parse_loop_stmt(self,block):
        loop = LoopStmt()

        if self.peek().type != TokenType.TOKEN_KEYWORD_LOOP:
            tmp_token = self.consume()
            self.print_error(tmp_token,f"expected a loop instead of '{tmp_token.string}'")
        else:
            self.consume()

        if self.peek().type != TokenType.TOKEN_COLON:
            tmp_token = self.consume()
            self.print_error(tmp_token,f"expected a : instead of '{tmp_token.string}'")
        else:
            loop.add_block(self.parse_block_stmt(block))

        return loop
    
    def parse_return_stmt(self,block):
        Return = ReturnStmt()

        if self.consume().type != TokenType.TOKEN_KEYWORD_RETURN:
            tmp_token = self.consume()
            self.print_error(tmp_token,f"expected a return instead of '{tmp_token.string}'")

        Return.add_expr(self.parse_expr())
        return Return
    

    def parse_expr(self):
        return self.parse_equality_expr()
    
    def parse_equality_expr(self):
        expr = self.parse_comparison_expr()

        while self.peek().type == TokenType.TOKEN_EQUAL or self.peek().type == TokenType.TOKEN_NOT_EQUAL:
            op = self.consume()
            right = self.parse_comparison_expr()
            expr = Expr(ExprType.EXPR_BINARY,BinaryExpr(expr,op,right))

        return expr
    
    def parse_comparison_expr(self):
        expr = self.parse_term_expr()

        while self.peek().type == TokenType.TOKEN_GREATER or self.peek().type == TokenType.TOKEN_LESS or self.peek().type == TokenType.TOKEN_GREATER_EQUAL or self.peek().type == TokenType.TOKEN_LESS_EQUAL:
            op = self.consume()
            right = self.parse_term_expr()
            expr = Expr(ExprType.EXPR_BINARY,BinaryExpr(expr,op,right))

        return expr


    def parse_term_expr(self):
        expr = self.parse_factor_expr()

        while self.peek().type == TokenType.TOKEN_ADD or self.peek().type == TokenType.TOKEN_SUB:
            op = self.consume()
            right = self.parse_factor_expr()
            expr = Expr(ExprType.EXPR_BINARY,BinaryExpr(expr,op,right))

        return expr
    
    def parse_factor_expr(self):
        expr = self.parse_unary_expr()

        while self.peek().type == TokenType.TOKEN_MUL or self.peek().type == TokenType.TOKEN_DIV:
            op = self.consume()
            right = self.parse_unary_expr()
            expr = Expr(ExprType.EXPR_BINARY,BinaryExpr(expr,op,right))

        return expr
    

    def parse_unary_expr(self):
        if self.peek().type == TokenType.TOKEN_ADD or self.peek().type == TokenType.TOKEN_SUB:
            op = self.consume()
            right = self.parse_unary_expr()
            return Expr(ExprType.EXPR_UNARY,UnaryExpr(op,right))

        return self.parse_primary_expr()

    def parse_primary_expr(self):

        match self.peek().type:
            case TokenType.TOKEN_KEYWORD_FALSE:
                return Expr(ExprType.EXPR_PRIMARY,PrimaryExpr(self.consume(),LiteralType.LIT_FALSE))

            case TokenType.TOKEN_KEYWORD_TRUE:
                return Expr(ExprType.EXPR_PRIMARY,PrimaryExpr(self.consume(),LiteralType.LIT_TRUE))
            
            case TokenType.TOKEN_LITERAL_INT:
                return Expr(ExprType.EXPR_PRIMARY,PrimaryExpr(self.consume(),LiteralType.LIT_INT))
            
            case TokenType.TOKEN_LITERAL_FLOAT:
                return Expr(ExprType.EXPR_PRIMARY,PrimaryExpr(self.consume(),LiteralType.LIT_FLOAT))
            
            case TokenType.TOKEN_LITERAL_STRING:
                return Expr(ExprType.EXPR_PRIMARY,PrimaryExpr(self.consume(),LiteralType.LIT_STRING))
            
            case TokenType.TOKEN_KEYWORD_ALLOC:
                self.consume()

                if self.consume().type != TokenType.TOKEN_LBRACE:
                    print("expected ( after alloc!")
                    pass

                size = self.parse_expr()

                if self.consume().type != TokenType.TOKEN_RBRACE:
                    print("expected ) after alloc!")
                    pass

                return Expr(ExprType.EXPR_ALLOC,AllocExpr(size))

            case TokenType.TOKEN_IDENT:
                if self.peek(1).type == TokenType.TOKEN_LBRACE:
                    return Expr(ExprType.EXPR_FNCALL,FnCallExpr(self.parse_fncall(None)))
                elif self.peek(1).type == TokenType.TOKEN_RESOLUTION:
                    left = self.consume()
                    self.consume()
                    right = self.parse_expr()
                    return Expr(ExprType.EXPR_RESOLVED,ResolvedExpr(left,right))

                return Expr(ExprType.EXPR_PRIMARY,PrimaryExpr(self.consume(),LiteralType.LIT_IDENT))
            
            
            case TokenType.TOKEN_LBRACE:
                self.consume()
                expr = self.parse_expr()
                if self.consume().type != TokenType.TOKEN_RBRACE:
                    pass
                return Expr(ExprType.EXPR_GROUPING,GroupingExpr(expr))




    
