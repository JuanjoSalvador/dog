main: src/dog.c
	mkdir -p bin
	gcc src/dog.c src/utils.h -o bin/dog 
