# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -Wextra -I.

# Linker flags
LDFLAGS = -lpthread

# Source files
SRC_SERVER = class_server.c admin_functions.c
SRC_ADMIN = class_admin.c admin_functions.c
SRC_CLIENT = class_client.c admin_functions.c

# Header files
HEADERS = Header.h

# Executables
EXE_SERVER = class_server
EXE_ADMIN = class_admin
EXE_CLIENT = class_client

# Default target
all: $(EXE_SERVER) $(EXE_ADMIN) $(EXE_CLIENT)

# Rules to build the executables
$(EXE_SERVER): $(SRC_SERVER) $(HEADERS)
	$(CC) $(CFLAGS) $(SRC_SERVER) -o $(EXE_SERVER) $(LDFLAGS)

$(EXE_ADMIN): $(SRC_ADMIN) $(HEADERS)
	$(CC) $(CFLAGS) $(SRC_ADMIN) -o $(EXE_ADMIN) $(LDFLAGS)

$(EXE_CLIENT): $(SRC_CLIENT) $(HEADERS)
	$(CC) $(CFLAGS) $(SRC_CLIENT) -o $(EXE_CLIENT) $(LDFLAGS)

# Clean up the build
clean:
	rm -f $(EXE_SERVER) $(EXE_ADMIN) $(EXE_CLIENT)

.PHONY: all clean
