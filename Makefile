CC := g++
CFLAGS := -Wall -g
SRC_DIR := .

.PHONY: all clean

all: main.out

main.out: main.cpp lib.cpp
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm -f main.out 

votest.out: lib.cpp vo/vo.cpp vo/votest.cpp
	$(CC) $(CFLAGS) $^ -o $@

a23test.out: lib.cpp a23/a23.cpp a23/a23test.cpp
	$(CC) $(CFLAGS) $^ -o $@

arntest.out: lib.cpp arn/arn.cpp arn/arntest.cpp
	$(CC) $(CFLAGS) $^ -o $@