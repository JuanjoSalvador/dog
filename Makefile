sources = src/dog.c src/functions.h src/dogos.h
bindir = bin

main: $(bindir)
	gcc $(sources) -o $(bindir)/dog 

$(bindir): $(sources)
	mkdir -p $(bindir)


.SILENT: install
install:
	cp bin/dog /usr/local/bin/dog