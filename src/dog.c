#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <getopt.h>
#include "functions.h"
#include "dogos.h"

static const uint8_t MAX_SIZE_BARK = 64;
static const uint8_t MAX_SIZE_VERSION = 24;
static const uint8_t MAX_SIZE_RENDER = 64;

int main(int argc, char *argv[]) {

	char bark[MAX_SIZE_BARK];
	char dog_version[MAX_SIZE_VERSION];
	int opt;
	int long_index = 0;
	int length = 2;

	snprintf(bark, MAX_SIZE_BARK, "%s", "Whoof!");
	snprintf(dog_version, MAX_SIZE_VERSION, "Dog, v%s", version);

	static struct option long_options[] = {
		{"help", no_argument, 0, 'h'},
		{"bork", no_argument, 0, 'b'},
		{"file",  required_argument, 0,  'f' },
		{"guau", no_argument, 0, 'g'},
		{"message",  required_argument, 0,  'm' },
		{"version",  no_argument, 0,  'v' },
		{"who-is-a-good-boy",  no_argument, 0,  'w' },
		{"length",  required_argument, 0,  'l' },
		{NULL, 0, NULL, 0}
	};

	if (argv[optind] == NULL) {
		render(bark, true, length);
	} else {
		if ((opt = getopt_long(argc, argv, "hbgm:f::vwl:", long_options, &long_index)) != -1) {
			switch (opt) {
				case 'h':					
					render(dog_version, false, length);
					printf("\n\n");

					printf("USAGE\n\n");
					printf("    dog [OPTION] [OPTION PARAM]\n\n");
					printf("EXAMPLE\n\n");
					printf("    dog --message 'Hello World!'\n\n");
					printf("AVAILABLE OPTIONS\n\n");
					printf("    (no option)              Dog goes 'whoof'. Default option.\n");
					printf("    -b, --bork               Dog goes 'bork'.\n");
					printf("    -g, --guau               Dog goes 'guau' (spanish version).\n");
					printf("    -m, --message            Dog will say your message.\n");
					printf("    -f, --file  [FILE]       Dog will say every line of the specified file.\n");
					printf("    -v, --version            Prints dog version.\n");
					printf("    -w, --who-is-a-good-boy  Who's a good boy? You're a good boy!.\n");
					printf("    -l, --length [LENGTH]    Set the dog lenth. Default is 2\n");
					break;

				case 'b':
					strcpy(bark, "Bork!");
					render(bark, true, length);
					break;

				case 'f':
					renderFile(optarg);
					break;

				case 'g':
					strcpy(bark, "¡Guau!");
					render(bark, true, length);
					break;

				case 'm':
					strcpy(bark, optarg);
					render(bark, true, length);
					break;

				case 'v': 
					printf("Dog, v%s. Written by Juanjo Salvador and other dog lovers on GitHub.\n", version);
					break;

				case 'w':
					strcpy(bark, "Whoof whoof whoof!!");
					render(bark, true, length);
					break;	
				case 'l':
					length = atoi(optarg);
					render(bark, true, length);
					break;	
			}
		}
	}

	return 0;
}

void clearScreen()
{
  const char *CLEAR_SCREEN_ANSI = "\e[1;1H\e[2J";
  write(STDOUT_FILENO, CLEAR_SCREEN_ANSI, 11);
}

void render(char* bark, int finish, int length) {
	char buffer[255];

	for (int i = 0; i<5; i++) {

		char middle[length + 10];
		memset(middle, dog_middle[i], length);
		middle[length] = 0;

		if (i != 2) {
			sprintf(buffer, "%s%s%s\n", dog_bag[i], middle, dog_front[i]);
		} else {
			sprintf(buffer, "%s%s%s  %s\n", dog_bag[i], middle, dog_front[i], bark);
		}
		printf("%s", buffer);
	}
	if(finish == true) {
		exit(0);
	}
}

void renderFile(char* filepath) {
	FILE* fp;
	char* line = NULL;
	size_t len = 0;
	ssize_t read;

	fp = fopen(filepath, "r");
	if (fp == NULL)
        exit(EXIT_FAILURE);

	while ((read = getline(&line, &len, fp)) != -1) {
		clearScreen();
		render(line, false, 2);
		sleep(1);
    }

    fclose(fp);
    if (line)
        free(line);
    exit(EXIT_SUCCESS);
}

// // Note: This Function is not used
// //
// // Note: In this function you are allocating dynamic memory multiple times.
// //       You must free this memory, it is like constantly kick the dog, at
// //       some point, the dog will bite you. Also, avoid returning a
// //       dynamically allocated data outside the function, nobody outside know
// //       it is dynamic and must free it.
// //
// // Note: strcpy(), strcat(), sprintf() functions are unsafe (it easy to write
// //       outside the reserved memory using it), it is better to use a safest
// //       functions like strncpy(), stncat() and snprintf().
// char* paramsToString(int argc, char *argv[]) {
// 	if(argc < 1) {
// 		return "";
// 	}

// 	char* ret = (char*) malloc(strlen(argv[1]));
// 	strcpy(ret, argv[1]);

// 	if(argc > 1) {
// 		for(int i = 2; i < argc; i++) {
// 			char* tmp = (char*) malloc(strlen(ret) + strlen(argv[i]) + 1);
// 			// You should check if the allocation fails
// 			//if (tmp == NULL)
// 			//    continue;
// 			strcpy(tmp, ret);
// 			strcat(tmp, " ");
// 			strcat(tmp, argv[i]);
// 			strcpy(ret, tmp);
// 			//free(tmp); // You must free this in each iteration
// 		}
// 	}

// 	return ret;
// }
