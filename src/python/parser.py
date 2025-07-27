from c4_ast import *


class Parser:
    def __init__(self,tokens):
        self.index = 0
        self.tokens = tokens
        self.size = len(self.tokens)
        self.programs = Programs()
        self.in_impl = False

    def peek(self,ahead = 0):
        if self.index + ahead >= self.size:
            return False

        return self.tokens[self.index + ahead]


    def consume(self):
        self.index += 1
        return self.tokens[self.index - 1]
    
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
            
            case TokenType.TOKEN_EOF:
                self.consume()
            case _:
                print(f"unknown declarator in {self.peek().string} in line {self.peek().row} col {self.peek().col}")
                self.consume()
            
        return program
    
    def parse_enum_decl(self):
        self.consume()
        enum = EnumDecl()

        if self.peek() != TokenType.TOKEN_IDENT:
            pass
        enum.add_ident(self.consume())

        if self.consume().type != TokenType.TOKEN_COLON:
            pass

        while self.peek().type != TokenType.TOKEN_COLON:
            enum.add_constant(self.consume())

        if self.consume().type != TokenType.TOKEN_COLON:
            pass

        return enum
    

    def parse_struct_decl(self):
        self.consume()
        struct = StructDecl()

        if self.peek().type != TokenType.TOKEN_IDENT:
            pass
        struct.add_ident(self.consume())

        if self.consume().type != TokenType.TOKEN_COLON:
            pass

        while self.peek().type != TokenType.TOKEN_COLON:
            struct.add_vard(self.parse_var_decl())
        
        if self.consume().type != TokenType.TOKEN_COLON:
            pass

        return struct
    
    def parse_impl_decl(self):
        self.consume()
        impl = ImplDecl()
        self.in_impl = True

        if self.peek().type != TokenType.TOKEN_IDENT:
            pass
        impl.add_ident(self.consume())

        if self.consume().type != TokenType.TOKEN_COLON:
            pass

        while self.peek().type != TokenType.TOKEN_COLON:
            if self.peek().type != TokenType.TOKEN_KEYWORD_FN:
                pass

            impl.add_fn(self.parse_fn_decl())

        if self.consume().type != TokenType.TOKEN_COLON:
            pass
            
        return impl
    
    def parse_fn_decl(self):
        self.consume()
        fn = FnDecl()

        if self.peek().type == TokenType.TOKEN_KEYWORD_INIT and self.in_impl == False:
            print(f"__init__ constructor used outside an impl declaration at row {self.peek().row} col {self.peek().col}")

        elif self.peek().type == TokenType.TOKEN_KEYWORD_FINI and self.in_impl == False:
            print(f"__fini__ constructor used outside an impl declaration at row {self.peek().row} col {self.peek().col}")

        elif self.peek().type != TokenType.TOKEN_IDENT:
            pass

        fn.add_ident(self.consume())

        if self.consume().type != TokenType.TOKEN_LBRACE:
            pass

        while self.peek().type != TokenType.TOKEN_RBRACE:
            fn.add_arg(self.parse_var_decl())

            if self.peek().type != TokenType.TOKEN_COMMA:
                pass
            else:
                self.consume()

        if self.consume().type != TokenType.TOKEN_RBRACE:
            pass

        if self.consume().type != TokenType.TOKEN_RETPARAM:
            pass

        fn.add_retparam(self.consume())

        if self.peek().type != TokenType.TOKEN_COLON:
            print(f"no colon in {fn.ident.string}")
            pass

        fn.add_block(self.parse_block_stmt())
        return fn
    
    def parse_var_decl(self):
        var = VarDecl()

        if self.not_token_type(self.peek()) or self.peek().type != TokenType.TOKEN_IDENT:
            pass
        var.add_type(self.consume())

        if self.peek().type != TokenType.TOKEN_IDENT:
            pass
        var.add_ident(self.consume())

        if self.peek().type != TokenType.TOKEN_ASSIGN:
            return var
        self.consume()

        var.add_expr(self.parse_expr())
        return var
    
    def not_token_type(self,type):
        match type:
            case TokenType.TOKEN_KEYWORD_F32 | TokenType.TOKEN_KEYWORD_F64 | TokenType.TOKEN_KEYWORD_I8 | TokenType.TOKEN_KEYWORD_I16 | TokenType.TOKEN_KEYWORD_I32 | TokenType.TOKEN_KEYWORD_I64 | TokenType.TOKEN_KEYWORD_U8 | TokenType.TOKEN_KEYWORD_U16 | TokenType.TOKEN_KEYWORD_U32 | TokenType.TOKEN_KEYWORD_U64 | TokenType.TOKEN_KEYWORD_BOOL:
                return False
            case _:
                return True

    def parse_var_assign(self):
        var = VarAssign()

        if self.peek().type != TokenType.TOKEN_IDENT:
            pass
        var.add_ident(self.consume())

        if self.consume().type != TokenType.TOKEN_ASSIGN:
            pass

        var.add_expr(self.parse_expr())
        return var
    
    def parse_block_stmt(self):
        block = BlockStmt()

        if self.consume().type != TokenType.TOKEN_COLON:
            pass

        while self.peek().type != TokenType.TOKEN_COLON:
            block.add(self.parse_stmt())

        if self.consume().type != TokenType.TOKEN_COLON:
            pass

        return block
    
    def parse_stmt(self):
        stmt = Stmt()

        match self.peek().type:
            case TokenType.TOKEN_IDENT:
                if self.peek(1).type == TokenType.TOKEN_LBRACE:
                    stmt.add_type(StmtType.STMT_FNCALL)
                    stmt.add_stmt(self.parse_fncall())
                elif self.peek(1).type == TokenType.TOKEN_DOT:
                    stmt.add_type(StmtType.STMT_STRUCT_ACCESS)
                    stmt.add_stmt(self.parse_struct_access())
                
                elif self.peek(1).type == TokenType.TOKEN_ASSIGN:
                    stmt.add_type(StmtType.STMT_VARASSIGN)
                    stmt.add_stmt(self.parse_var_assign())
                
                else:
                    stmt.add_type(StmtType.STMT_VARDECL)
                    stmt.add_stmt(self.parse_var_decl())

            case TokenType.TOKEN_KEYWORD_IF:
                stmt.add_type(StmtType.STMT_IF)
                stmt.add_stmt(self.parse_if_stmt())
            
            case TokenType.TOKEN_KEYWORD_WHILE:
                stmt.add_type(StmtType.STMT_WHILE)
                stmt.add_stmt(self.parse_while_stmt())
            
            case TokenType.TOKEN_KEYWORD_SWITCH:
                stmt.add_type(StmtType.STMT_SWITCH)
                stmt.add_stmt(self.parse_switch_stmt())
            
            case TokenType.TOKEN_KEYWORD_LOOP:
                stmt.add_type(StmtType.STMT_LOOP)
                stmt.add_stmt(self.parse_loop_stmt())

            case TokenType.TOKEN_KEYWORD_RETURN:
                stmt.add_type(StmtType.STMT_RETURN)
                stmt.add_stmt(self.parse_return_stmt())
            
            case _:
                print(f"unknown statement in {self.peek().string} in line {self.peek().row} col {self.peek().col}")
                self.consume()

        return stmt
    
    def parse_fncall(self):
        fn = FnCall()
        print("---------------------testing---------------------")
        print(self.peek().string)
        if self.peek().type != TokenType.TOKEN_IDENT:
            pass

        fn.add_ident(self.consume())

        if self.consume().type != TokenType.TOKEN_LBRACE:
            pass
        
        while self.peek().type != TokenType.TOKEN_RBRACE:
            fn.add_expr(self.parse_expr())
            if self.peek().type == TokenType.TOKEN_COMMA:
                self.consume()

        if self.consume().type != TokenType.TOKEN_RBRACE:
            pass

        return fn
    
    def parse_struct_access(self):
        struct = StructAccess()

        struct.left = self.consume()

        if self.consume().type != TokenType.TOKEN_DOT:
            pass

        if self.peek(1).type == TokenType.TOKEN_LBRACE:
            struct.add_type(StructAccessType.STRUCT_ACCESS_METHOD)
            struct.right = self.parse_fncall()
        else:
            struct.add_type(StructAccessType.STRUCT_ACCESS_PROPERTY)
            struct.right = self.parse_expr()

        return struct



    
    def parse_if_stmt(self):
        If = IfStmt()

        if self.consume().type != TokenType.TOKEN_KEYWORD_IF:
            pass

        If.add_expr(self.parse_expr())

        if self.peek().type != TokenType.TOKEN_COLON:
            pass
        If.add_block(self.parse_block_stmt())

        while self.peek().type == TokenType.TOKEN_KEYWORD_ELIF:
            self.consume()
            Elif = ElifBlock()
            Elif.add_expr(self.parse_expr())
            if self.peek().type != TokenType.TOKEN_COLON:
                pass
            Elif.add_block(self.parse_block_stmt())
            If.add_elif(Elif)

        if self.peek().type != TokenType.TOKEN_KEYWORD_ELSE:
            pass
        else:
            self.consume()
            Else = ElseBlock()
            if self.peek().type != TokenType.TOKEN_COLON:
                pass
            else:
                Else.add_block(self.parse_block_stmt())
            If.add_else(Else)

        return If
    
    def parse_while_stmt(self):
        While = WhileStmt()

        if self.consume().type != TokenType.TOKEN_KEYWORD_WHILE:
            pass

        While.add_expr(self.parse_expr())

        if self.peek().type != TokenType.TOKEN_COLON:
            pass
        While.add_block(self.parse_block_stmt())

        return While
    
    def parse_switch_stmt(self):
        switch = SwitchStmt()

        if self.consume().type != TokenType.TOKEN_KEYWORD_SWITCH:
            pass

        switch.add_expr(self.parse_expr())

        if self.consume().type != TokenType.TOKEN_COLON:
            pass
        
        while self.peek().type == TokenType.TOKEN_KEYWORD_CASE:
            Case = CaseBlock()
            self.consume()
            Case.add_expr(self.parse_expr())
            if self.peek().type != TokenType.TOKEN_COLON:
                pass
            Case.add_block(self.parse_block_stmt())
            switch.add_case(Case)

        if self.peek().type != TokenType.TOKEN_KEYWORD_DEFAULT:
            pass
        else:
            Case = CaseBlock()
            Case.default()
            self.consume()
            if self.peek().type != TokenType.TOKEN_COLON:
                pass
            else:
                Case.add_block(self.parse_block_stmt())
                switch.add_case(Case)

        if self.consume().type != TokenType.TOKEN_COLON:
            pass
        return switch

    def parse_loop_stmt(self):
        loop = LoopStmt()

        if self.consume().type != TokenType.TOKEN_KEYWORD_LOOP:
            pass

        if self.peek().type != TokenType.TOKEN_COLON:
            pass
        loop.add_block(self.parse_block_stmt())

        return loop
    
    def parse_return_stmt(self):
        Return = ReturnStmt()

        if self.consume().type != TokenType.TOKEN_KEYWORD_RETURN:
            pass

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
            
            case TokenType.TOKEN_IDENT:
                if self.peek(1).type == TokenType.TOKEN_LBRACE:
                    return Expr(ExprType.EXPR_FNCALL,FnCallExpr(self.parse_fncall()))
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




    
