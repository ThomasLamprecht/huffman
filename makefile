CC = gcc
version = 0.0.1b
out = huffman-$(version).bin
debug = debugged_huffman-$(version).bin

main: huffman.o io.o dyn_menu.o list.o main.o
	$(CC) -o $(out) huffman.o io.o dyn_menu.o list.o main.o

huffman.o: huffman.c huffman.h
	$(CC) -c huffman.c 

io.o: io.c io.h
	$(CC) -c io.c

list.o: list.c list.h
	$(CC) -c list.c

main.o: main.c main.h
	$(CC) -c main.c

dyn_menu.o: dyn_menu.c dyn_menu.h
	$(CC) -c dyn_menu.c


debug: huffman_d.o io_d.o dyn_menu_d.o list_d.o main_d.o
	$(CC) -o $(debug) huffman_d.o io_d.o dyn_menu_d.o list_d.o main_d.o -g

huffman_d.o: huffman.c huffman.h
	$(CC) -c huffman.c -g -o huffman_d.o

io_d.o: io.c io.h
	$(CC) -c io.c -g -o io_d.o

list_d.o: list.c list.h
	$(CC) -c list.c -g -o list_d.o

main_d.o: main.c main.h
	$(CC) -c main.c -g -o main_d.o

dyn_menu_d.o: dyn_menu.c dyn_menu.h
	$(CC) -c dyn_menu.c -g -o dyn_menu_d.o

tidy:
	rm *.o
