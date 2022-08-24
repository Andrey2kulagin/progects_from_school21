CC=gcc
CFLAGS=-Wall -Werror -Wextra
SOURCE=polish.c graph.c output.c
EXECUTABLE=../build/graph

all: $(SOURCE)
	$(CC) $(CFLAGS) $(SOURCE) -o $(EXECUTABLE)