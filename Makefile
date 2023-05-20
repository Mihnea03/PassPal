CC=gcc
OBJ:= obj/passpal.o obj/user_ops.o obj/crypt.o

obj/%.o: src/%.c
	$(CC) -c -o $@ $<

build: $(OBJ)
	$(CC) -Wall -g -o bin/passpal $^

run:
	./bin/passpal

clean: $(OBJ) 
	rm -f bin/passpal .users/* obj/*