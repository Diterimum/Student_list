CC = gcc
CFLAGS = -Wall -Wextra -Iheaders

SRC = $(wildcard *.c) $(wildcard listFolder/*.c) $(wildcard addFolder/*.c) $(wildcard deleteFolder/*.c)

OBJS = $(SRC:.c=.o)

fileStudents: $(OBJS)
	$(CC) $(OBJS) -o fileStudents

%.o: %.c
	$(CC) -c $< -o $@ $(CFLAGS)

clean:
	rm -f *.o fileStudents $(wildcard listFolder/*.o) $(wildcard addFolder/*.o) $(wildcard deleteFolder/*.o)