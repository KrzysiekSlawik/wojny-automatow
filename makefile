CC=gcc
CFLAGS=-I. -lm -g
DEPS = interpreter.h robot.h map.h commands.h
OBJ = main.o interpreter.o commands.o map.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

main: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
