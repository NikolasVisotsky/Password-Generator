// Password generator program
// Autor: Nikolas Visotsky

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define PSWD_LEN_MIN 1
#define PSWD_LEN_MAX 1024

char *letters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
char *numbers = "0123456789";
char *symbols = "!@#$%^&*()_+-=/[]{}";

const size_t MAX = 23 * 2 + 10 + 19 + 1;

int main(int argc, char *argv[]) {
	unsigned password_size = 0;
	unsigned mode = 0;
	char choose[MAX];
	
	printf("Select mode:\n\t");
	printf("0 - all(numbers, latin letters, symbols)\n\t");
	printf("1 - numbers, latin letters\n\t");
	printf("2 - latin letters, symbols\n\t");
	printf("3 - numbers, symbols\n\t");
	printf("4 - latin letter only\n\t");
	printf("5 - numbers only\n\t");
	printf("6 - symbols only\n");
	
CHOOSE_MODE:
	printf(">");
	scanf("%u", &mode);
	
	switch(mode) {
		case 0:
			strcpy(choose, letters);
			strcat(choose, numbers);
			strcat(choose, symbols);
			
			break;
		case 1:
			strcpy(choose, letters);
			strcat(choose, numbers);
			
			break;
		case 2:
			strcpy(choose, letters);
			strcat(choose, symbols);
			
			break;
		case 3:
			strcpy(choose, numbers);
			strcat(choose, symbols);
			
			break;
		case 4:
			strcpy(choose, letters);
			
			break;
			
		case 5:
			strcpy(choose, numbers);
			
			break;
			
		case 6:
			strcpy(choose, symbols);
			
			break;
			
		default:
			puts("Choose correct mode");
			goto CHOOSE_MODE;
	}
	
PASSWORD_LEN_INP:
	printf("Password size: ");
	scanf("%u", &password_size);
	
	if(password_size < PSWD_LEN_MIN || password_size > PSWD_LEN_MAX ) {
		printf("Illegal password size(min - %d, max - %d)\n", PSWD_LEN_MIN, PSWD_LEN_MAX);
		goto PASSWORD_LEN_INP;
	}
	
	char password[password_size + 1];
	password[password_size] = '\0';
	
	srand(time(NULL));
	
	for(int i = 0; i < password_size; i++) {
		int R = rand() % strlen(choose);
		password[i] = choose[R];
	}
	
	puts(password);
	
	return 0;
}
