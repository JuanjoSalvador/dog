#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <getopt.h>
#include "utils.h"
#include "dogos.h"

int main(int argc, char *argv[]) {
	
	char* bark = "Whoof!";
	int opt;
	int long_index = 0;

	if (argc < 2) {
		render(bark);
	}

	static struct option long_options[] = {
        {"version",  no_argument, 0,  'v' },
        {"who-is-a-good-boy",  no_argument, 0,  'w' }
    };

	while ((opt = getopt_long(argc, argv, "vbg::", long_options, &long_index)) != -1) {
			
		switch (opt) {
			case 'v': 
				printf("Dog, v%s. Written by Juanjo Salvador <juanjosalvador(at)netc.eu>\n", version);
				break;

			case 'b':
				bark = "Bork!";
				render(bark);
				break;

			case 'g':
				bark = "Guau!";
				render(bark);
				break;	

			case 'w':
				bark = "Whoof whoof whoof!!";
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

