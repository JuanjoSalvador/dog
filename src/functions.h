#ifndef functions

#include <windows.h>

#define STDOUT_FILENO 0

const char* version = "0.0.4";

void render(char* bark, int finish);
void renderFile(char* filepath);
char* paramsToString(int argc, char *argv[]);

void clearScreen()
{
  const char *CLEAR_SCREEN_ANSI = "\e[1;1H\e[2J";
  write(STDOUT_FILENO, CLEAR_SCREEN_ANSI, 12);
}

#endif
