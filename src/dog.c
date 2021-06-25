#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "utils.h"
#include "dogos.h"

int main(int argc, char *argv[]) {

	int opt;
	int s;

	if (argc < 2) {
		render(bark);
	}

	while ((opt = getopt(argc, argv, "bgv::")) != -1) {
			
		switch (opt) {
			case 'v': 
				printf("Dog, v%s\n", version);
				break;
			case 'b':
				bark = "Bork!";
				render(bark);
				break;

			case 'g':
				bark = "Guau!";
				render(bark);
				break;					
		}

	}

	return 0;
}

void render(char* bark) {
	char buffer[32];

	for (int i = 0; i<5; i++) {
		if (i != 2) {
			sprintf(buffer, "%s\n", dog_one[0][i]);
		} else {
			sprintf(buffer, "%s  %s\n", dog_one[0][i], bark);
		}
		printf("%s", buffer);
	}
}

