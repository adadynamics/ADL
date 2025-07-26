from codegen import *
import subprocess



class Compile:
    def __init__(self,name,compiler = "gcc"):
        self.name = name
        self.compiler = compiler

    def compile(self):
        self.make()

    def make(self):
        buf = ""
        buf += f"{self.name}:{self.name}.c\n"
        buf += f"\t{self.compiler} $^ -o $@ "

        buf += f"\nclean:{self.name}.c\n"
        buf += f"\trm -rf $<"
        
        with open("Makefile","w") as file:
            file.write(buf)
