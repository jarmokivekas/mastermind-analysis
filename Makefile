CFLAGS=-g -Wall -lm
CC=gcc

all: values

table: compile
	./main.exe && gnuplot table.p -p

values: compile
	./main.exe > values.dat && gnuplot values.p -p
	
run: compile
	./main.exe 
	
main.exe: main.o master_code.o
	$(CC) $^ -o $@

%.c: %.o
	$(CC) -c $^ -o $@ $(CFALGS)
