#-D ROBOTSLIMIT=number to change max robots, default 1000
#-D ROBOTMEM=number to set memory size of single robot, default 10
CC=gcc
CFLAGS=-I. -lm -g -Wall
DEPS = interpreter.h robot.h map.h commands.h display.h
OBJ = main.o interpreter.o commands.o map.o display.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

main: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
