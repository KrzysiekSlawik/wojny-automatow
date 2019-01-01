CC=gcc
CFLAGS=-I.
DEPS = interpreter.h
OBJ = main.o interpreter.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

main: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
