CC		= clang
CFLAGS		= -std=c99 -Wall -Wextra -O3

all: clean build

build:
	$(CC) $(CFLAGS) -o pythree src/pythree.c

clean:
	rm -f pythree
