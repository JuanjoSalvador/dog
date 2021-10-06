#ifndef functions

#include <unistd.h>

const char* version = "0.0.4";

typedef struct dogo_info
{
	const char **wheres_dog;
	int dog_y_size;
} dogo_info;

#define NUM_OF_DOGS (sizeof(dogselection)/sizeof(dogo_info))

void setDefaultDog(int newDefaultDog);
int getDefaultDog(void);
int getDefaultDogInput(char *chosen_dog_input_string);
void render(char* bark, dogo_info *dogo_info, int finish);
void renderFile(char* filepath, dogo_info *dogo_info);
char* paramsToString(int argc, char *argv[]);

void clearScreen()
{
  const char *CLEAR_SCREEN_ANSI = "\e[1;1H\e[2J";
  write(STDOUT_FILENO, CLEAR_SCREEN_ANSI, 12);
}

#endif
