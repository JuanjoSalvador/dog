# MAN PAGE

This folder contains all things concerning the man page of this project

## Details

### File - man.md

Contains the man page of this project in markdown format (editable)

### File - dog.1 

Contains the generated man page from the pandoc command (do not edit)

## Contribute

Make changes to the man.md and not the dog.1 

Use pandoc to generate the man page (dog.1)

The command `pandoc man.md -s -t man -o dog.1` should generate a new man page (dog.1)