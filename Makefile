sources = src/dog.c src/functions.h src/dogos.h
bindir = bin

VERSION = $(shell cat VERSION)
TEMP_DIR = dog_$(VERSION)_all

CONTROL = $(TEMP_DIR)/DEBIAN/control
POSTINST = $(TEMP_DIR)/DEBIAN/postinst

main: $(bindir)
	mkdir -p $(bindir) 
	gcc $(sources) -o $(bindir)/dog

$(bindir): $(sources)
	mkdir -p $(bindir)

.SILENT: install clean

install: install-dog install-man
	echo successfully installed dog

install-dog:
	cp bin/dog /usr/local/bin/dog

install-man:
	sudo mkdir -p /usr/local/man/man1
	sudo cp man/dog.1 /usr/local/man/man1/dog.1
	sudo gzip /usr/local/man/man1/dog.1
	sudo mandb

clean:
	rm -rf dog_$(VERSION)_all
	rm -rf bin
	rm *.deb

build-man:
	pandoc man/man.md -s -t man -o man/dog.1

build-deb: main build-man
	mkdir $(TEMP_DIR)
	mkdir -p $(TEMP_DIR)/usr/local/bin
	mkdir -p $(TEMP_DIR)/DEBIAN

	cp $(bindir)/dog $(TEMP_DIR)/usr/local/bin

	echo "Package: dog" > $(CONTROL)
	echo "Version: $(VERSION)" >> $(CONTROL)
	echo "Architecture: all" >> $(CONTROL)
	echo "Maintainer: Juanjo Salvador <juanjosalvador@netc.eu>" >> $(CONTROL)
	echo "Description: A program that shows a dog barking into your terminal." >> $(CONTROL)

	echo "mkdir -p /usr/local/man/man1" > $(POSTINST)
	echo "cp man/dog.1 /usr/local/man/man1/dog.1" >> $(POSTINST)
	echo "gzip /usr/local/man/man1/dog.1" >> $(POSTINST)
	echo "mandb" >> $(POSTINST)

	chmod 0755 $(POSTINST)

	dpkg-deb --build --root-owner-group $(TEMP_DIR)

	rm -rf $(TEMP_DIR)
