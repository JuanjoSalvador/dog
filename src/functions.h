/* Include Guard */

#ifndef _FUNCTIONS_H_
#define _FUNCTIONS_H_

/*****************************************************************************/

#include <unistd.h>

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

/*****************************************************************************/

#endif /* _FUNCTIONS_H_ */
