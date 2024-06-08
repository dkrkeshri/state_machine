CC=gcc
CFLAFS=-I,
DEPS= state_machine.h

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

state_machine: state_machine.o
	$(CC) -o state_machine state_machine.o
