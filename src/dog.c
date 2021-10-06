#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <getopt.h>
#include "functions.h"
#include "dogos.h"


static dogo_info dogselection[] = {
	{&dog_one[0], 5},
	{&dog_two[0], 11}
};

int main(int argc, char *argv[]) {
	
	char* bark = "Whoof!";
	char dog_version[255];
	int opt;
	int long_index = 0;
	int chosen_dog_input;
	int chosen_dog;

	chosen_dog = getDefaultDog();

	sprintf(dog_version, "Dog, v%s", version);

	static struct option long_options[] = {
		{"help", no_argument, 0, 'h'},
		{"bork", no_argument, 0, 'b'},
		{"file",  required_argument, 0,  'f' },
		{"guau", no_argument, 0, 'g'},
		{"message",  required_argument, 0,  'm' },
		{"version",  no_argument, 0,  'v' },
		{"who-is-a-good-boy",  no_argument, 0,  'w' },
		{"chosen-dog",  required_argument, 0,  'd' },
		{NULL, 0, NULL, 0}
	};

	if (argv[optind] == NULL) {
		render(bark, &dogselection[chosen_dog], true);
	} else {
		if ((opt = getopt_long(argc, argv, "hbgm:f::vwd:", long_options, &long_index)) != -1) {
			switch (opt) {
				case 'h':					
					render(dog_version, &dogselection[chosen_dog], false);
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
					printf("    -d, --chosen-dog         Select your favourite dog.\n");
					break;

				case 'b':
					bark = "Bork!";
					render(bark, &dogselection[chosen_dog], true);
					break;

				case 'f':
					renderFile(optarg, &dogselection[chosen_dog]);
					break;

				case 'g':
					bark = "Guau!";
					render(bark, &dogselection[chosen_dog], true);
					break;

				case 'm':
					bark = optarg;
					render(bark, &dogselection[chosen_dog], true);
					break;

				case 'v': 
					printf("Dog, v%s. Written by Juanjo Salvador <juanjosalvador(at)netc.eu>\n", version);
					break;

				case 'w':
					bark = "Whoof whoof whoof!!";
					render(bark, &dogselection[chosen_dog], true);
					break;	

				case 'd':
					chosen_dog_input = getDefaultDogInput(optarg);
					if (chosen_dog_input != (chosen_dog)) {
						chosen_dog = chosen_dog_input;
						setDefaultDog(chosen_dog_input + 1);
					}

					render(bark, &dogselection[chosen_dog], true);
					break;	
			}
		}
	}

	return 0;
}

void setDefaultDog(int newDefaultDog) {
	FILE* fp;
	char* line = NULL;
	size_t len = 0;
	
	fp = fopen("/usr/local/man/man1/chosendog.txt", "w+");
	if (fp == NULL)
        exit(EXIT_FAILURE);
	fprintf(fp, "%i", newDefaultDog);

	fclose(fp);
}

int getDefaultDog(void) {
	FILE* fp;
	char* line = NULL;
	size_t len = 0;
	int chosen_dog_input;
	
	fp = fopen("/usr/local/man/man1/chosendog.txt", "r");
	if (fp == NULL)
        exit(EXIT_FAILURE);
	getline(&line, &len, fp);

	chosen_dog_input = getDefaultDogInput(line);
	fclose(fp);

	return chosen_dog_input;
}

int getDefaultDogInput(char *chosen_dog_input_string) {
	int chosen_dog_input;

	chosen_dog_input = atoi(chosen_dog_input_string) - 1;
	if ((chosen_dog_input >= 0) && (chosen_dog_input < NUM_OF_DOGS))	{
		return chosen_dog_input;
	}
	else {
		return 0;	/* first dog is default dog */
	}
}

void render(char* bark, dogo_info *dogo_info, int finish) {
	char buffer[255];

	for (int i = 0; i<dogo_info->dog_y_size; i++) {
		if (i != 2) {
			sprintf(buffer, "%s\n", dogo_info->wheres_dog[i]);
		} else {
			sprintf(buffer, "%s  %s\n", dogo_info->wheres_dog[i], bark);
		}
		printf("%s", buffer);
	}
	if(finish == true) {
		exit(0);
	}
}

void renderFile(char* filepath, dogo_info *dogo_info) {
	FILE* fp;
	char* line = NULL;
	size_t len = 0;
	ssize_t read;

	fp = fopen(filepath, "r");
	if (fp == NULL)
        exit(EXIT_FAILURE);

	while ((read = getline(&line, &len, fp)) != -1) {
		clearScreen();
		render(line, dogo_info, false);
		sleep(1);
    }

    fclose(fp);
    if (line)
        free(line);
    exit(EXIT_SUCCESS);
}

char* paramsToString(int argc, char *argv[]) {
	if(argc < 1) {
		return "";
	}

	char* ret = (char*) malloc(strlen(argv[1]));
	strcpy(ret, argv[1]);

	if(argc > 1) {
		for(int i = 2; i < argc; i++) {
			char* tmp = (char*) malloc(strlen(ret) + strlen(argv[i]) + 1);
			strcpy(tmp, ret);
			strcat(tmp, " ");
			strcat(tmp, argv[i]);
			strcpy(ret, tmp);
		}
	}

	return ret;
}