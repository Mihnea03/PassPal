CC=gcc
OBJ:= obj/passpal.o obj/user_ops.o obj/crypt.o obj/init_free.o

obj/%.o: src/%.c
	$(CC) -c -o $@ $<

build: $(OBJ)
	$(CC) -Wall -g -o bin/passpal $^

run:
	./bin/passpal

clean: 
	rm -f bin/passpal .users/* obj/*

full_clean:
	make clean
	rm .users/.user_meta
	touch .users/.user_meta