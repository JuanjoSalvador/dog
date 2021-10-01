# dog


Dog command for Windows systems. Because there is a `cat` command, should be a `dog` command too. Original version was written completely using Vim and WSL2, compiled with GCC and developed in one night, Windows version was made in 15 minutes with VS2019 and StackOverflow.

> This package is purely joke, please do not take it seriously.

```
➜  ~ dog
          __
 |_______/ V`-,
  }        /~~  Whoof!
 /_)^ --,r'
|b      |b
```

## Windows changes

Since `dog` is using POSIX functions and libs insteaf of standard C libs, I need to replace some of them with Windows version of the libs and workarounds. Everything is working but `--file` option. Currentpy working on it.

## Building

### Requisites

You will need to install at least VisualStudio 2019 Community, but maybe it works with VS2015.

### Intructions

Open the solution (`dog.sln`) with Visual Studio 2019 and click on *Compile*. Result will be placed on `Release` folder.

### Testing it

Open your PowerShell console, go to `Release` or `Debug` folder and run

```powershell
> .\dog.exe --message 'It works!'
```
