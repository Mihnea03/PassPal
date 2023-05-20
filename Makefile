CC=gcc
OBJ:= obj/passpal.o

obj/%.o: src/%.c
	$(CC) -c -o $@ $<

build: $(OBJ)
	$(CC) -Wall -g -o bin/passpal.exe $^

exec:
	./bin/passpal.exe

clean: $(OBJ) 
	rm -f bin/passpal.exe .users/* obj/*