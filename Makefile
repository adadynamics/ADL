INC= -I include
SRC_C = src/c
TARGET = target
INC= src/c/include
OBJ= $(TARGET)/obj
FLAGS= -Wall -Wextra -Werror 
LINK= -ladl -lkeyutils -lnuma -lc -lm

OBJECTS = $(OBJ)/string.o $(OBJ)/unix.o
ADL_LIB = $(TARGET)/libadl.a

install: $(ADL_LIB)
	sudo cp $(ADL_LIB) /usr/lib
	sudo rm -rf /usr/include/adl
	sudo mkdir /usr/include/adl 
	sudo cp -r $(INC)/* /usr/include/adl

$(ADL_LIB): $(OBJECTS)
	ar -rv $@ $^

$(OBJ)/string.o: $(SRC_C)/ds/string.c
	gcc $(FLAGS) -D _GNU_SOURCE  -c $< -o $@

$(OBJ)/unix.o: $(SRC_C)/unix/unix.c
	gcc $(FLAGS) -D _GNU_SOURCE  -c $< -o $@




