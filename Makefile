main: src/dog.c
	mkdir -p bin
	gcc src/dog.c src/utils.h src/dogos.h -o bin/dog 

.SILENT: install
install:
	cp bin/dog /usr/local/bin/dog