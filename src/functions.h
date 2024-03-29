/* Include Guard */

#ifndef _FUNCTIONS_H_
#define _FUNCTIONS_H_

/*****************************************************************************/

#include <unistd.h>

const char* version = "1.0.0";

void render(char* bark, int finish, int length);
void renderFile(char* filepath);
char* paramsToString(int argc, char *argv[]);
void clearScreen();
/*****************************************************************************/

#endif /* _FUNCTIONS_H_ */
