# dog

[![Master CI](https://github.com/JuanjoSalvador/dog/actions/workflows/ci.yml/badge.svg)](https://github.com/JuanjoSalvador/dog/actions/workflows/ci.yml)

Dog command for *nix systems. Because there is a `cat` command, should be a `dog` command too. Was written completely using Vim and WSL2, compiled with GCC and developed in one night.

**For the Work In Progress - Windows version, [check this branch](https://github.com/JuanjoSalvador/dog/tree/wip/windows).**

> This package is purely joke, please do not take it seriously.

```
➜  ~ dog
          __
 |_______/ V`-,
  }        /~~  Whoof!
 /_)^ --,r'
|b      |b
```


## Installation

### From package (Debian/Ubuntu)

Download the last stable package from releases and install it using `dpkg`.

### From source (other platforms)

#### Requisites

You will need to install at least GCC and Make for your OS.

#### Intructions

Just clone the repository and build it using `make` and GCC.

```shell
$ make
$ sudo make install
```

## Building your own DEB package

The repository also includes a sample building script you can use to build and package your own DEB package, you can distribute or even analyze for learning purposes. Just run the script as follows.

```shell
$ ./BUILD-DEB-PACKAGE.sh
```
Make sure to change the version into the `VERSION` file.
