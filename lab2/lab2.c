/* Air Comfort. Компания занимается установкой стеклопакетов;
 планируется, что после открытия сайта компании, пользователи
 смогут спроектировать и рассчитать стоимость установки
 стеклопакетов прямо в интернете. Вам поручается разработать
 модуль на С, выполняющий следующие функции:
 • Ввод количества окон в квартире
 • Ввод количества балконов.
 • Ввод этажа, на котором находится квартира
 • Расчет и вывод параметров проекта: общая площадь
 застекления, стоимость застекления окон, стоимость установки
 балконной двери, процентная надбавка.
 • Вывод общей стоимости проекта
 • Краткая информация о компании и контакты.
 • Выход из программы
 Справочные сведения. Стоимость одного стандартного оконного
 пакета(2,15х1,50 м) составляет $100, включая установку.
 Стоимость балконной двери (0,70х2,15 м) составляет $150,
 включая установку. Если квартира находится выше первого
 этажа, за установку каждого стеклопакета взимается
 дополнительно 15% его стоимости.
 */
#include <stdio.h>
#include <stdlib.h>

char s[30]; //переменная для проверки ввода

oid InfoAboutUs(void) {
	printf("\nCompany: New-Design\nAdress: Minsk, Mazurova, 1, second floor\nPhone: +375296801013\n");
}

void Information(int balcony, int floor, int window) {
	float i = (floor <= 1 ? 0 : 100 * window * 0.15 + 150 * balcony * 0.15); //считаем надбавку, если этаж первый, то надбавка 0
	printf("\nTotal area: %.3f square metres\n", 2.15*1.5*window + 0.7*2.15*balcony);
	printf("Cost of windows: %u$\n", 100*window);
	printf("Cost of balconies: %u$\n", 150*balcony);
	printf("Surcharge: %.1f$\n", i);
	printf("Total cost: %.1f$\n", i + 100*window + 150*balcony);
}

void Menu(void) {
	printf("\n________________________________________________\n\n");
	printf("1 - Input data and get information about project");
	printf("\n2 - Print information about us ");
	printf("\n3 - Exit");
	printf("\n________________________________________________\n\n");
	printf("Your answer: ");
}

int CheckAnswer(void) {
	int i = 0;
	while (!i) {
		scanf("%s", s);
		i = atoi(s);
		if (i <= 0) {
			i = 0;
			printf("Incorrect answer! Input 1, 2 or 3.\nYour answer: ");
		}
	}
	return i;
}

int main() {
	int answer = 0, balcony = 0, floor = 0, window = 0;
	while (1) {
		Menu();
		answer = CheckAnswer();
		switch (answer) {
		case 1:
			printf("\nInput the number of balconies: ");
			balcony = CheckAnswer();
			printf("Input the number of windows: ");
			window = CheckAnswer();
			printf("Input the number of floor: ");
			floor = CheckAnswer();
			Information(balcony, floor, window);
			break;
		case 2:
			InfoAboutUs();
			break;
		case 3:
			printf("Goodbye!");
			return 0;
		default:
			printf("Incorrect answer! Input 1, 2 or 3.\n");
		}
	}
}
