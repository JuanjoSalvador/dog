#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <getopt.h>
#include "functions.h"
#include "dogos.h"

int main(int argc, char *argv[]) {
	
	char* bark = "Whoof!";
	int opt;
	int long_index = 0;

	if (argc < 2) {
		render(bark, true);
	}

	static struct option long_options[] = {
		{"file",  required_argument, 0,  'f' },
		{"message",  required_argument, 0,  'm' },
		{"version",  no_argument, 0,  'v' },
		{"who-is-a-good-boy",  no_argument, 0,  'w' }
	};

	while ((opt = getopt_long(argc, argv, "vbg::m:f:", long_options, &long_index)) != -1) {
		switch (opt) {
			case 'v': 
				printf("Dog, v%s. Written by Juanjo Salvador <juanjosalvador(at)netc.eu>\n", version);
				break;

			case 'b':
				bark = "Bork!";
				render(bark, true);
				break;

			case 'f':
				renderFile(optarg);
				break;

			case 'g':
				bark = "Guau!";
				render(bark, true);
				break;

			case 'm':
				bark = optarg;
				render(bark, true);
				break;	

			case 'w':
				bark = "Whoof whoof whoof!!";
				render(bark, true);
				break;				
		}
	}

	return 0;
}

void render(char* bark, int finish) {
	char buffer[255];

	for (int i = 0; i<5; i++) {
		if (i != 2) {
			sprintf(buffer, "%s\n", dog_one[i]);
		} else {
			sprintf(buffer, "%s  %s\n", dog_one[i], bark);
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
		render(line, false);
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