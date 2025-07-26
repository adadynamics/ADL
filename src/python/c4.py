from lexer import *
from parser import *
from semantic import *
from codegen import *
from compile import *
import sys


if __name__ == "__main__":
    if len(sys.argv) < 2:
        sys.exit(1)

    buf = ""
    with open(sys.argv[1]) as file:
        buf = file.read()
    lex = Lexer(buf)
    lex.scan_tokens()
    
    """
    for tok in lex.tokens:
        print(tok.type)
    """
    parser = Parser(lex.tokens)
    parser.parse_programs()

    resolver = Resolver(parser.programs)
    resolver.resolve_programs()


    name = sys.argv[1]
    name = name[0:len(name) - 3]
    print(name)
    codegen = Codegen(resolver.programs,name + ".c")
    codegen.gen_programs()

    compile = Compile(name)
    compile.compile()
