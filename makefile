#
# PROGRAM:	assign1
# PROGRAMMER:   Gonzalo Pantoja
# LOGON ID:     z#
# DATE DUE:     9/14/17
#

# Compiler variables
CCFLAGS = -ansi -Wall -std=c++11

# Rule to link object code files to create executable file
assign1: assign1.o
	g++ $(CCFLAGS) -o assign1 assign1.o

# Rule to compile source code file to obkect code
assign1.o: assign1.cpp
	g++ $(CCFLAGS) -c assign1.cpp

# pseudo-target to remove obkect code and executable files
clean:
	-rm *.o assign1

