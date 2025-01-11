CC = gcc
CFLAGS = -Wall -Wextra -std=c99

SRC = saper.c plansza.c game.c print_map.c
OBJ = $(SRC:.c=.o)
EXEC = saper

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC)	$(CFLAGS)	-o	$@	$^

clean:
	rm	-f	$(OBJ)	$(EXEC)

.PHONY:	all	clean