# Makefile
# Author: aqrabwi, 13/02/2025
# Description: Compiles two executables (oss and user) from their respective source files.

# Set the compiler to gcc.
CC      = gcc

# Compiler flags: -Wall enables all warnings, -g includes debugging information.
CFLAGS  = -Wall -g

# List of target executables to be built.
TARGETS = oss user

# The default target "all" builds both oss and user executables.
all: $(TARGETS)


# Rule to build the "oss" executable from its object file oss.o.
oss: oss.o
	$(CC) $(CFLAGS) -o oss oss.o    # Link oss.o to create the executable 'oss'

# Rule to build the "user" executable from its object file user.o.
user: user.o
	$(CC) $(CFLAGS) -o user user.o   # Link user.o to create the executable 'user'

# Rule to compile oss.c into the object file oss.o.
oss.o: oss.c
	$(CC) $(CFLAGS) -c oss.c         # Compile oss.c (-c flag) to generate oss.o

# Rule to compile user.c into the object file user.o.
user.o: user.c
	$(CC) $(CFLAGS) -c user.c         # Compile user.c (-c flag) to generate user.o

# "clean" target to remove all generated object files and executables.
clean:
	rm -f *.o $(TARGETS)             # Remove all .o files and executables (oss and user)
oss: oss.o
	$(CC) $(CFLAGS) -o oss oss.o    # Link oss.o to create the executable 'oss'

# Rule to build the "user" executable from its object file user.o.
user: user.o
	$(CC) $(CFLAGS) -o user user.o   # Link user.o to create the executable 'user'

# Rule to compile oss.c into the object file oss.o.
oss.o: oss.c
	$(CC) $(CFLAGS) -c oss.c         # Compile oss.c (-c flag) to generate oss.o

# Rule to compile user.c into the object file user.o.
user.o: user.c
	$(CC) $(CFLAGS) -c user.c         # Compile user.c (-c flag) to generate user.o

# "clean" target to remove all generated object files and executables.
clean:
	rm -f *.o $(TARGETS)             # Remove all .o files and executables (oss and user)