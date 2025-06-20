INC= -I include
SRC_C = src/c
TARGET = target
INC= src/c/include
OBJ= $(TARGET)/obj
FLAGS= -Wall -Wextra -Werror 
LINK= -ladl -lkeyutils -lnuma -lc -lm

CC = gcc #i686-w64-mingw32-gcc

DEFINES = -D _GNU_SOURCE #-D ADL_OS_UNIX 

OBJECTS = $(OBJ)/string.o $(OBJ)/unix.o $(OBJ)/socket.o $(OBJ)/os.o $(OBJ)/raw.o $(OBJ)/file_linux.o  $(OBJ)/file.o $(OBJ)/directory.o $(OBJ)/pthread_linux.o $(OBJ)/thread.o $(OBJ)/process_linux.o
ADL_LIB = $(TARGET)/libadl.a

install: $(ADL_LIB)
	sudo cp $(ADL_LIB) /usr/lib
	sudo rm -rf /usr/include/adl
	sudo mkdir /usr/include/adl 
	sudo cp -r $(INC)/* /usr/include/adl

$(ADL_LIB): $(OBJECTS)
	ar -rv $@ $^


$(OBJ)/process_linux.o   : $(SRC_C)/os/process/process_linux.c
	$(CC) $(FLAGS) $(DEFINES)-c $< -o $@


$(OBJ)/thread.o   : $(SRC_C)/os/thread/thread.c
	$(CC) $(FLAGS) $(DEFINES)-c $< -o $@

$(OBJ)/pthread_linux.o   : $(SRC_C)/os/thread/pthread_linux.c
	$(CC) $(FLAGS) $(DEFINES)-c $< -o $@

$(OBJ)/directory.o   : $(SRC_C)/os/file/directory.c
	$(CC) $(FLAGS) $(DEFINES)-c $< -o $@

$(OBJ)/file.o   : $(SRC_C)/os/file/file.c
	$(CC) $(FLAGS) $(DEFINES)-c $< -o $@


$(OBJ)/file_linux.o   : $(SRC_C)/os/file/file_linux.c
	$(CC) $(FLAGS) $(DEFINES)-c $< -o $@


$(OBJ)/raw.o   : $(SRC_C)/os/net/raw/raw.c
	$(CC) $(FLAGS) $(DEFINES)-c $< -o $@

$(OBJ)/socket.o: $(SRC_C)/os/net/socket/socket.c
	$(CC) $(FLAGS) $(DEFINES)-c $< -o $@

$(OBJ)/string.o: $(SRC_C)/ds/string.c
	$(CC) $(FLAGS) $(DEFINES)-c $< -o $@


$(OBJ)/os.o   : $(SRC_C)/os/os.c
	$(CC) $(FLAGS) $(DEFINES)-c $< -o $@


$(OBJ)/unix.o: $(SRC_C)/unix/unix.c
	$(CC) $(FLAGS) $(DEFINES)-c $< -o $@



clean:
	rm -rf $(OBJ)/*

