PROG := shell
SRC = shell.c lexer.c
OBJ = $(SRC:%.c=%.o)

.PHONY: all clean

all: $(PROG)

$(PROG): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c lexer.h
	$(CC) $(CFLAGS) -c $<

clean:
	$(RM) $(PROG) $(OBJ)
