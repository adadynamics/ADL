INC= -I include
SRC_C = src/c
TARGET = target
INC= src/c/include
UNIX_OBJ= $(TARGET)/obj/unix
UNIX_FLAGS= -Wall -Wextra -Werror 
UNIX_LINK= -ladl -lkeyutils -lnuma -lc -lm

UNIX_CC = gcc 
UNIX_DEFINES = -D _GNU_SOURCE #-D ADL_OS_UNIX 

WINDOWS_OBJ = $(TARGET)/obj/windows
WINDOWS_CC = i686-w64-mingw32-gcc
WINDOWS_DEFINES = 
WINDOWS_FLAGS = # -Wall -Wextra -Werror 
WINDOWS_LINK = -lws2_32


OS_OBJ  = $(TARGET)/obj/os


UNIX_OBJECTS = $(UNIX_OBJ)/string.o $(UNIX_OBJ)/file.o $(UNIX_OBJ)/ipc.o $(UNIX_OBJ)/memory.o $(UNIX_OBJ)/net.o $(UNIX_OBJ)/process.o $(UNIX_OBJ)/signal.o $(UNIX_OBJ)/sys.o $(UNIX_OBJ)/thread.o $(UNIX_OBJ)/time.o $(UNIX_OBJ)/user.o $(UNIX_OBJ)/unix.o $(UNIX_OBJ)/os.o $(OS_OBJ)/unix_socket_linux.o $(OS_OBJ)/unix_socket.o $(OS_OBJ)/unix_tcp.o


ADL_WINDOWS_LIB = $(TARGET)/libwinadl.a

WINDOWS_OBJECTS = $(WINDOWS_OBJ)/string.o $(WINDOWS_OBJ)/file.o $(WINDOWS_OBJ)/net.o $(WINDOWS_OBJ)/windows.o $(WINDOWS_OBJ)/os.o $(OS_OBJ)/windows_socket_windows.o $(OS_OBJ)/windows_socket.o $(OS_OBJ)/windows_tcp.o

windows_install: $(ADL_WINDOWS_LIB)
	sudo cp $(ADL_WINDOWS_LIB) /usr/i686-w64-mingw32/lib
	sudo rm -rf /usr/i686-w64-mingw32/include/adl
	sudo mkdir /usr/i686-w64-mingw32/include/adl 
	sudo cp -r $(INC)/* /usr/i686-w64-mingw32/include/adl

$(ADL_WINDOWS_LIB): $(WINDOWS_OBJECTS)
	sudo rm -rf /usr/i686-w64-mingw32/lib/libwinadl.a
	sudo rm -rf $(ADL_WINDOWS_LIB)
	ar -rcsv $@ $^


$(OS_OBJ)/windows_tcp.o: $(SRC_C)/os/net/tcp/tcp.c
	$(WINDOWS_CC) $(WINDOWS_FLAGS) $(WINDOWS_DEFINES)-c $< -o $@


$(OS_OBJ)/windows_socket.o: $(SRC_C)/os/net/socket/socket.c
	$(WINDOWS_CC) $(WINDOWS_FLAGS) $(WINDOWS_DEFINES)-c $< -o $@

$(OS_OBJ)/windows_socket_windows.o: $(SRC_C)/os/net/platform/windows/socket_windows.c
	$(WINDOWS_CC) $(WINDOWS_FLAGS) $(WINDOWS_DEFINES)-c $< -o $@


$(WINDOWS_OBJ)/os.o: $(SRC_C)/os/os.c
	$(WINDOWS_CC) $(WINDOWS_FLAGS) $(WINDOWS_DEFINES)-c $< -o $@

$(WINDOWS_OBJ)/windows.o: $(SRC_C)/windows/windows.c
	$(WINDOWS_CC) $(WINDOWS_FLAGS) $(WINDOWS_DEFINES)-c $< -o $@


$(WINDOWS_OBJ)/net.o: $(SRC_C)/windows/net/net.c
	$(WINDOWS_CC) $(WINDOWS_FLAGS) $(WINDOWS_DEFINES)-c $< -o $@

$(WINDOWS_OBJ)/file.o: $(SRC_C)/windows/file/file.c
	$(WINDOWS_CC) $(WINDOWS_FLAGS) $(WINDOWS_DEFINES)-c $< -o $@

$(WINDOWS_OBJ)/string.o: $(SRC_C)/ds/string.c
	$(WINDOWS_CC) $(WINDOWS_FLAGS) $(WINDOWS_DEFINES)-c $< -o $@



ADL_UNIX_LIB = $(TARGET)/libadl.a

unix_install: $(ADL_UNIX_LIB)
	sudo cp $(ADL_UNIX_LIB) /usr/lib
	sudo rm -rf /usr/include/adl
	sudo mkdir /usr/include/adl 
	sudo cp -r $(INC)/* /usr/include/adl

$(ADL_UNIX_LIB): $(UNIX_OBJECTS)
	sudo rm -rf /usr/lib/libadl.a
	sudo rm -rf $(ADL_UNIX_LIB)
	ar -rcsv $@ $^




$(OS_OBJ)/unix_tcp.o: $(SRC_C)/os/net/tcp/tcp.c
	$(UNIX_CC) $(UNIX_FLAGS) $(UNIX_DEFINES)-c $< -o $@

$(OS_OBJ)/unix_socket.o: $(SRC_C)/os/net/socket/socket.c
	$(UNIX_CC) $(UNIX_FLAGS) $(UNIX_DEFINES)-c $< -o $@

$(OS_OBJ)/unix_socket_linux.o: $(SRC_C)/os/net/platform/unix/socket_linux.c
	$(UNIX_CC) $(UNIX_FLAGS) $(UNIX_DEFINES)-c $< -o $@


$(UNIX_OBJ)/os.o: $(SRC_C)/os/os.c
	$(UNIX_CC) $(UNIX_FLAGS) $(UNIX_DEFINES)-c $< -o $@

$(UNIX_OBJ)/unix.o: $(SRC_C)/unix/unix.c
	$(UNIX_CC) $(UNIX_FLAGS) $(UNIX_DEFINES)-c $< -o $@


$(UNIX_OBJ)/user.o: $(SRC_C)/unix/user/user.c
	$(UNIX_CC) $(UNIX_FLAGS) $(UNIX_DEFINES)-c $< -o $@

$(UNIX_OBJ)/time.o: $(SRC_C)/unix/time/time.c
	$(UNIX_CC) $(UNIX_FLAGS) $(UNIX_DEFINES)-c $< -o $@


$(UNIX_OBJ)/thread.o: $(SRC_C)/unix/thread/thread.c
	$(UNIX_CC) $(UNIX_FLAGS) $(UNIX_DEFINES)-c $< -o $@

$(UNIX_OBJ)/sys.o: $(SRC_C)/unix/sys/sys.c
	$(UNIX_CC) $(UNIX_FLAGS) $(UNIX_DEFINES)-c $< -o $@

$(UNIX_OBJ)/signal.o: $(SRC_C)/unix/signal/signal.c
	$(UNIX_CC) $(UNIX_FLAGS) $(UNIX_DEFINES)-c $< -o $@

$(UNIX_OBJ)/process.o: $(SRC_C)/unix/process/process.c
	$(UNIX_CC) $(UNIX_FLAGS) $(UNIX_DEFINES)-c $< -o $@

$(UNIX_OBJ)/net.o: $(SRC_C)/unix/net/net.c
	$(UNIX_CC) $(UNIX_FLAGS) $(UNIX_DEFINES)-c $< -o $@

$(UNIX_OBJ)/memory.o: $(SRC_C)/unix/memory/memory.c
	$(UNIX_CC) $(UNIX_FLAGS) $(UNIX_DEFINES)-c $< -o $@

$(UNIX_OBJ)/ipc.o: $(SRC_C)/unix/ipc/ipc.c
	$(UNIX_CC) $(UNIX_FLAGS) $(UNIX_DEFINES)-c $< -o $@

$(UNIX_OBJ)/file.o: $(SRC_C)/unix/file/file.c
	$(UNIX_CC) $(UNIX_FLAGS) $(UNIX_DEFINES)-c $< -o $@

$(UNIX_OBJ)/string.o: $(SRC_C)/ds/string.c
	$(UNIX_CC) $(UNIX_FLAGS) $(UNIX_DEFINES)-c $< -o $@




clean:
	rm -rf $(UNIX_OBJ)/*
	rm -rf $(WINDOWS_OBJ)/*
	rm -rf $(OS_OBJ)/*
