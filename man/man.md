% DOG(1) dog 0.0.4
% Juanjo Salvador
% October 2021

# NAME
dog - your personal dog

# SYNOPSIS
**dog** [-v] [\--version] [-h] [\--help] [-b] [\--bork] [-g] [\--guau] [-w] [\--who-is-a-good-boy] [-m \<MESSAGE>] [\--message \<MESSAGE>] [-f \<FILE>] [\--file \<FILE>]

# DESCRIPTION
**dog** behaves like a trained dog, saying everything you tell it to. Running **dog**  without parameters causes it to say "whoof".

# OPTIONS
**-v**, **-\-version**
: Displays the software version alongside the author

**-h**, **-\-help**
: Displays a friendly help message

**-b**, **-\-bork**
: **dog** says "bork"

**-g**, **-\-guau**
: **dog** says "Guau"

**-w**, **-\-who-is-a-good-boy**
: **dog** says "Whoof whoof whoof!!"

**-m \<MESSAGE>**, **-\-message \<MESSAGE>**
: **dog** says out \<MESSAGE>. If \<MESSAGE> is longer than one word (separated by spaces), it's best to wrap it with quotes (" or ')

## EXAMPLE
    **dog** --message "Hello World!"


**-f \<FILE>**, **-\-file \<FILE>**
: **dog** says out the content of the file at path \<FILE>. \<FILE> is a path to a file from which **dog** should read out its content

