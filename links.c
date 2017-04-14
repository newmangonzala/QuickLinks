#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 250

int userChoice(void){
	int input;
	printf("\nHello!\nWhat would you like to do?\n");
	printf("Please enter one of the following options:\n\n");
	printf("1- Access a link\n");
	printf("2- Add a link\n");
	printf("3- Delete a link\n");
	printf("4- Exit\n");
	scanf("%d", &input);
	
	return input;
}
void acessLink(){
	int choice, i, d;
	char str[MAX];
	
	FILE *pages = fopen("links.txt", "r");
	
	while ((d = getchar()) != EOF && d != '\n')
    continue;

	printf("\nOpening link:...\n\n");
	while (!feof(pages)){
		i = 1;
		strcpy(str, "\0");
		fgets(str, MAX, pages);
		printf("%d- %s", i, str);
		i++;
	}
	printf("\n\nPlease enter the link you wish to enter:\n");
	scanf("%d", &choice);
	
	rewind(pages);
	while (!feof(pages)){
		i = 0;
		i++;
		strcpy(str, "\0");
		fgets(str, MAX, pages);
		if (i == choice){
			printf("%s", str);
			break;
		} 
		printf("SOMETHING IS WRONG");
	}
	fclose(pages);
}

void addLink(){
	int i = 1, replaceLine, d;
	char singleLine[MAX];
	char str[MAX], comment[MAX];
	
	FILE *pages = fopen("links.txt", "r");
	FILE *tempFile;
	
	while ((d = getchar()) != EOF && d != '\n')
    continue;

	printf(" Input the new website's link: ");
	fgets(singleLine, MAX, stdin);
	
	printf(" Input the link number where you want to replace it: ");
    scanf("%d", &replaceLine);
	int ln;
	ln = strlen(singleLine);
	singleLine[ln-1] = '\0';
	
	while ((d = getchar()) != EOF && d != '\n')
    continue;

	printf(" Input a comment of the website : ");
	fgets(comment, MAX, stdin);

	tempFile = fopen("temp.txt", "w");
	while (!feof(pages)){
		strcpy(str, "\0");
		fgets(str, MAX, pages);
		
			
		if (i != replaceLine) {
			fprintf(tempFile, "%s", str);
		} 
		else {
			fprintf(tempFile, "%s %s", singleLine, comment);
		}
		i++;
	}
	fclose(pages);
	fclose(tempFile);
	remove("links.txt");
	rename("temp.txt", "links.txt");
	printf(" Replacement did successfully..!! \n");
	return;
}
void DeleteLink(){
	
}

int main(void) {
	int choice;
	
	choice = userChoice();
	
	switch(choice){
		case 1: acessLink(); break;
		case 2: addLink(); break;
		case 3: DeleteLink(); break;
		case 4: printf("Bye"); return 0;
		//default: break;
	}

	return 0;
}
