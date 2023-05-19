CC=gcc
SRCFILE=src
USERSFILE=.users
OBJ
OBJ:= obj/new.o obj/passpal.o

obj/%.o: src/%.c
	$(CC) -c -o $@ $<

build: $(OBJ)
	$(CC) -Wall -g -o bin/passpal.exe $^

exec:
	./bin/passpal.exe

full_reset:
	rm -f bin/passpal.exe
	rm -rf $(USERSFILE)/*
	rm -rf $(OBJFILE)/*