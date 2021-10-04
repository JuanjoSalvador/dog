#ifndef functions

#ifdef WIN32
#include <windows.h>
#endif

#define STDOUT_FILENO 0

const char* version = "0.0.4";

void render(char* bark, int finish);
void renderFile(char* filepath);
char* paramsToString(int argc, char *argv[]);

// A header file shouldn't implements functions, just define the function
// prototype/interface (this function should be moved to dog.c)
void clearScreen()
{
  const char *CLEAR_SCREEN_ANSI = "\e[1;1H\e[2J";
  write(STDOUT_FILENO, CLEAR_SCREEN_ANSI, 12);
}

void os_sleep(int seconds) // cross-platform sleep function
{
  #ifdef WIN32
    Sleep(seconds * 1000);
  #else
    sleep(seconds);
  #endif
}

#endif
