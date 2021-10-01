sources = src/dog.c src/functions.h src/dogos.h

main: $(sources)
	mkdir -p bin
	gcc $(sources) -o bin/dog 

.SILENT: install

install: install-dog install-man

install-dog:
	cp bin/dog /usr/local/bin/dog

install-man:
	sudo mkdir -p /usr/local/man/man1
	sudo cp man/dog.1 /usr/local/man/man1/dog.1
	sudo gzip /usr/local/man/man1/dog.1
	sudo mandb
	echo okay