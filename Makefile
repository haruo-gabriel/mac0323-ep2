CC := g++
CFLAGS := -Wall -g
SRC_DIR := .

.PHONY: all clean

all: main.out

main.out: main.cpp lib.cpp vo.cpp abb.cpp tr.cpp a23.cpp arn.cpp
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm -f main.out 

votest.out: lib.cpp vo.cpp votest.cpp
	$(CC) $(CFLAGS) $^ -o $@

abbtest.out: lib.cpp abb.cpp abbtest.cpp
	$(CC) $(CFLAGS) $^ -o $@

trtest.out: lib.cpp tr.cpp trtest.cpp
	$(CC) $(CFLAGS) $^ -o $@

a23test.out: lib.cpp a23.cpp a23test.cpp
	$(CC) $(CFLAGS) $^ -o $@

arntest.out: arn.cpp arntest.cpp
	$(CC) $(CFLAGS) $^ -o $@