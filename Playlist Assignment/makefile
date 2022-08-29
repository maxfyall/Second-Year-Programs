CC = gcc

CFLAGS = -Wall -Wextra -Werror -pedantic

test: playlist.c playlist_tester.c
	$(CC) $(CFLAGS) -o play playlist.c playlist_tester.c

all: play