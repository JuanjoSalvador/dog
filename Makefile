sources = src/dog.c src/functions.h src/dogos.h
bindir = bin

main: $(bindir)
	mkdir -p $(bindir) 
	gcc $(sources) -o $(bindir)/dog

$(bindir): $(sources)
	mkdir -p $(bindir)

.SILENT: install

install: install-dog install-man
	echo successfully installed dog

install-dog:
	cp bin/dog /usr/local/bin/dog

install-man:
	sudo mkdir -p /usr/local/man/man1
	sudo cp man/dog.1 /usr/local/man/man1/dog.1
	sudo gzip /usr/local/man/man1/dog.1
	sudo mandb
