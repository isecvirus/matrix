#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdlib.h>

char letters[26] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};

int get_pos(const char letter, const char string[]) {
	int index = 0;
	for (int _=0;_<strlen(string);_++) {
		if (string[_] == letter) {
			return index;
		}
		index++;
	}
	return -1;
}

bool XinY(const char letter, const char string[]) {
	for (int _=0;_<strlen(string);_++) {
		if (letter == string[_]) {
			return true;
		}
	}
	return false;
}

char encrypt(char *message, int shift) {
	printf("> ");
	for (int i=0;i<strlen(message);i++) {
		char letter = message[i];
		if (XinY(toupper(letter), letters)) {
			int pos = (get_pos(toupper(letter), letters) + shift) % 26;
			printf("%c", letters[pos]);
		} else {
			printf("%c", letter);
		}
	}
	printf("\n");
}

char decrypt(char *message, int shift) {
	printf("> ");
        for (int i=0;i<strlen(message);i++) {
                char letter = message[i];
                if (XinY(toupper(letter), letters)) {
                        int pos = (get_pos(toupper(letter), letters) - shift) % 26;
                        printf("%c", letters[pos]);
                } else {
                        printf("%c", letter);
                }
        }
	printf("\n");
}

int main(int argc, char *argv[]) {
	const char *operations[] = {"enc", "dec"};
	if (argc == 3) {
		const char *operation = argv[1];
		const int shift = atoi(argv[2]);
		if (strcmp(operation, "enc") == 0 || strcmp(operation, "dec") == 0) {
			printf("Type and hit ENTER; github@virus (v1.0.0)\n");
			while (1) {
				char message[1024];
				printf("< ");
				scanf("%s", message);
				if (strcmp(operation, "enc") == 0) {
					encrypt(message, shift);
				} else if (strcmp(operation, "dec") == 0) {
					decrypt(message, shift);
				}
			}
		} else {
			printf("Only enc|dec are valid operations.");
		}
	} else {
		printf("Usage: %s <OPERATION> <SHIFT>\n", argv[0]);
		printf("OPERATIONS: enc|dec\n");
		printf("SHIFT     : 1 -> 26");
	}
	return 0;
}
