.PHONY: all clean

COMPILER = g++
COMPILER_FLAG = -std=c++20 -fmodules-ts -Wall
INC_FLAG = `pkg-config opencv4 --cflags`
LD_FLAG = `pkg-config opencv4  --libs`

default: all

all: test

# VERY IMPORTAN! In compilling modules the order of compilation matters.
# This is a characteristic of the technology. Check for example to swap
# the two lines bellow:
# App.exe:  main.o func.o
test:  rotate_image.o #string.o
	${COMPILER} $^ -o $@ ${LD_FLAG}

%.o: %.cpp
	${COMPILER} -c  ${COMPILER_FLAG} ${INC_FLAG} $<

gcm:
	g++ -std=c++20 -fmodules-ts -xc++-system-header  list

clean:
	@-rm test
	@-rm *.o
	@-rm -r gcm.cache
