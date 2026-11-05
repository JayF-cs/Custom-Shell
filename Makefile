PROG := shell
SRC = shell.c lexer.c utils.c
OBJ = $(SRC:%.c=%.o)

.PHONY: all clean

all: $(PROG)

$(PROG): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c lexer.h token.h utils.h
	$(CC) $(CFLAGS) -c $<

clean:
	$(RM) $(PROG) $(OBJ)
