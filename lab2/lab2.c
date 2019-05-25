#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

void Information(void) {
	char str[20];
	char str1[20];
	char str2[20];
	int h = 0;
	float window = 0, balcony = 0, floor = 0;
	int costw = 0, costb = 0;
	float i = 0;
	printf("Input the number of windows: ");
	fgets(str,20,stdin);
	
	window = atoi(str);
	if (window < 0 || window != (int)window) {
		printf("Error");
		exit(0);
	}
	costw = 100 * window;
	h = 0;
	printf("Input the number of balconies: ");
	fgets(str1,20,stdin);
	while (str1[h]) {
		if (isalpha(str1[h])) {
			printf("error");
			exit(0);
		}
		h++;
	}
	balcony = atoi(str1);
	if (balcony < 0 || balcony != (int)balcony) {
		printf("Error");
		exit(0);
	}
	costb = 150 * balcony;
	h = 0;
	printf("Input the floor number: ");
	fgets(str2,20,stdin);
	while (str2[h]) {
		if (isalpha(str2[h])) {
			printf("Error");
			exit(0);
		}
		h++;
	}
	floor = atoi(str2);
	if (floor < 0 || floor != (int)floor) {
		printf("Error");
		exit(0);
	}
	i = (floor <= 1 ? 0 : costw * 0.15 + costb * 0.15);
	printf("\nTotal area: %.3f square metres\n", 2.15*1.5*window + 0.7*2.15*balcony);
	printf("Cost of windows: %u$\n", costw);
	printf("Cost of balconies: %u$\n", costb);
	printf("Surcharge: %.1f$\n", i);
	printf("Total cost: %.1f$\n", i + costw + costb);
	printf("Information about us\nCompany: New-Design\nAdress: Minsk, Mazurova, 1, second floor\nPhone: +375296801013\n");
}
void TryAgain(char answer)
{

	if (answer=='n')
	{
		printf("Goodbye!\n");
	}
	else if (answer!='y')
	{
		printf("Wrong input!\nDo you want to try again?(y or n): ");
		scanf(" %c", &answer);
		TryAgain(answer);
	}
}

int main()
{
	char answer;
	Information();
	printf("\n\nDo you want to try again?(y or n): ");
	scanf(" %c", &answer);
	TryAgain(answer);
	while (answer=='y')
	{
		Information();
		printf("\nDo you want to try again?(y or n): ");
		scanf(" %c", &answer);
		TryAgain(answer);
	}
	return 0;
}
