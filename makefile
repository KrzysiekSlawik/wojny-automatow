CC=gcc
CFLAGS=-I.
DEPS = interpreter.h robot.h map.h commands.h
OBJ = main.o interpreter.o commands.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

main: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
