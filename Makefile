CC=g++
SRC=src/none.cpp src/util.cpp
LDFLAGS=-lxcb -lxcb-util
WARN=-Wall -Wpedantic -Wextra

default: none

none: $(SRC)
	$(CC) $(SRC) $(LDFLAGS) $(WARN) -o none
