CC=gcc
OBJ:= obj/new.o obj/passpal.o

obj/%.o: src/%.c
	$(CC) -c -o $@ $<

init:
	mkdir .users bin obj

build: $(OBJ)
	$(CC) -Wall -g -o bin/passpal.exe $^

exec:
	./bin/passpal.exe

full_reset: $(OBJ) 
	rm -f bin/passpal.exe .users/* obj/*