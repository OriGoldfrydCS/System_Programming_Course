# Shortcuts
CC = gcc
AR = ar
FLAGS = -Wall -g

# Source and header dependencies
SRC_LOOP = advancedClassificationLoop.c
SRC_BASIC = basicClassification.c
SRC_RECURSIVE = advancedClassificationRecursion.c
HEADER_FILE = NumClass.h

# Object files
OBJECTS_BASIC = basicClassification.o
OBJECTS_LOOP = advancedClassificationLoop.o
OBJECTS_RECURSIVE = advancedClassificationRecursion.o
OBJECTS_MAIN = main.o

# Default target: compile all libraries and programs
all: loops recursives loopd recursived mains maindloop maindrec

# Object file rules
$(OBJECTS_MAIN): main.c $(HEADER_FILE)
	$(CC) $(FLAGS) -c main.c

$(OBJECTS_BASIC): $(SRC_BASIC) $(HEADER_FILE)
	$(CC) $(FLAGS) -c $(SRC_BASIC) -fPIC

$(OBJECTS_LOOP): $(SRC_LOOP) $(HEADER_FILE)
	$(CC) $(FLAGS) -c $(SRC_LOOP) -fPIC

$(OBJECTS_RECURSIVE): $(SRC_RECURSIVE) $(HEADER_FILE)
	$(CC) $(FLAGS) -c $(SRC_RECURSIVE) -fPIC

# Static library that contains loop implementation
loops: libclassloops.a
libclassloops.a: $(OBJECTS_LOOP) $(OBJECTS_BASIC)
	$(AR) -rcs libclassloops.a $(OBJECTS_LOOP) $(OBJECTS_BASIC)

# Static library that contains recursive implementation
recursives: libclassrec.a
libclassrec.a: $(OBJECTS_RECURSIVE) $(OBJECTS_BASIC)
	$(AR) -rcs libclassrec.a $(OBJECTS_RECURSIVE) $(OBJECTS_BASIC)
	
# Dynamic library that contains loop implementation
loopd: libclassloops.so
libclassloops.so: $(OBJECTS_LOOP) $(OBJECTS_BASIC)
	$(CC) $(FLAGS) -shared -o libclassloops.so $(OBJECTS_LOOP) $(OBJECTS_BASIC)

# Dynamic library that contains recursive implementation
recursived: libclassrec.so
libclassrec.so: $(OBJECTS_RECURSIVE) $(OBJECTS_BASIC)
	$(CC) $(FLAGS) -shared -o libclassrec.so $(OBJECTS_RECURSIVE) $(OBJECTS_BASIC)

# Main program that linked to the recursive library
mains: $(OBJECTS_MAIN) libclassrec.a
	$(CC) $(FLAGS) -o mains $(OBJECTS_MAIN) libclassrec.a 

# Main program that linked to the dynamic library (loops)
maindloop: $(OBJECTS_MAIN) libclassloops.so
	$(CC) $(FLAGS) -o maindloop $(OBJECTS_MAIN) -L. ./libclassloops.so

# Main program that linked to the dynamic library (recursion)

maindrec: $(OBJECTS_MAIN) libclassrec.so
	$(CC) $(FLAGS) -o maindrec $(OBJECTS_MAIN) -L. ./libclassrec.so

# Clean-up
clean:
	rm -f *.o *.a *.so mains maindloop maindrec