INC= -I include
SRC_C = src/c
TARGET = target
INC= src/c/include
OBJ= $(TARGET)/obj
FLAGS= -Wall -Wextra -Werror 
LINK= -ladl -lkeyutils -lnuma -lc -lm

CC = gcc

OBJECTS = $(OBJ)/string.o $(OBJ)/unix.o $(OBJ)/socket.o $(OBJ)/os.o $(OBJ)/raw.o
ADL_LIB = $(TARGET)/libadl.a

install: $(ADL_LIB)
	sudo cp $(ADL_LIB) /usr/lib
	sudo rm -rf /usr/include/adl
	sudo mkdir /usr/include/adl 
	sudo cp -r $(INC)/* /usr/include/adl

$(ADL_LIB): $(OBJECTS)
	ar -rv $@ $^

$(OBJ)/raw.o   : $(SRC_C)/os/net/raw/raw.c
	$(CC) $(FLAGS) -D _GNU_SOURCE -c $< -o $@

$(OBJ)/socket.o: $(SRC_C)/os/net/socket/socket.c
	$(CC) $(FLAGS) -D _GNU_SOURCE -c $< -o $@

$(OBJ)/string.o: $(SRC_C)/ds/string.c
	$(CC) $(FLAGS) -D _GNU_SOURCE -c $< -o $@

$(OBJ)/unix.o: $(SRC_C)/unix/unix.c
	$(CC) $(FLAGS) -D _GNU_SOURCE -c $< -o $@

$(OBJ)/os.o: $(SRC_C)/os/os.c
	$(CC) $(FLAGS) -D _GNU_SOURCE -c $< -o $@

clean:
	rm -rf $(OBJ)/*

