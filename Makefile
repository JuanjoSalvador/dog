sources = src/dog.c src/functions.h src/dogos.h

main: $(sources)
	gcc $(sources) -o bin/dog 

.SILENT: install
install:
	cp bin/dog /usr/local/bin/dog