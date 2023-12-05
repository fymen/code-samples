.PHONY: all clean

COMPILER = gcc
COMPILER_FLAG = -Wall

default: all

all: rolling-shutter

rolling-shutter: rolling-shutter.o
	${COMPILER} -o $@ $^

%.o: %.c
	${COMPILER} -c  ${COMPILER_FLAG} $<

test:
	ffmpeg -i original.mp4 -f image2pipe -vcodec ppm pipe:1 |./rolling-shutter | x264 -o output.mp4 /dev/stdin

clean:
	@-rm test
	@-rm *.o
	@-rm -r gcm.cache
