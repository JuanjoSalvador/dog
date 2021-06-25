#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "utils.h"

int main(int argc, char *argv[]) {

	int opt;
	int s;
	char buffer[32];

	sprintf(buffer, "%s", whoof);

	while ((opt = getopt(argc, argv, "v")) != -1) {
			
		switch (opt) {
			case 'v': 
				sprintf(buffer, "Dog, v%s", version); 
				break;
		}

	}

	printf("%s\n", buffer);

	return 0;
}

