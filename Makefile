sources = src/dog.c src/getopt.c
bindir = bin

ifeq ($(OS),Windows_NT)
	mkdirCommand = if not exist $(bindir) mkdir $(bindir)
else
	mkdirCommand = mkdir -p $(bindir)
endif

main: $(bindir)
	gcc $(sources) -o $(bindir)/dog

$(bindir): $(sources)
	$(mkdirCommand)


.SILENT: install
install:
	cp bin/dog /usr/local/bin/dog