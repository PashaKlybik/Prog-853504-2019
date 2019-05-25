/*
Треугольник. Разработать программу, меню которой позволяет выполнить следующие функции: 
• Ввод координат вершин треугольника. 
• Определить вид треугольника (правильный, прямоугольный,равнобедренный, произвольного вида).  
• Вывод периметра треугольника 
• Вывод площади треугольника.  
• Вычислить и вывести радиусы вписанной и описанной вокруг треугольника окружностей.
• Информация о версии и авторе программы. 
• Выход из программы. 
*/



#include < stdio.h >
#include < math.h > // for sqrt

void EnterPosition(int Triangle[]);
void GetLenght(int Triangle[]);
void TriangleView(int Triangle[]);
float  GetPerimetr(int Triangle[]);
float  GetSquare(int Triangle[]);
void PerimetrOfCircleR(int Triangle[]);
void PerimetrOfCircler(int Triangle[]);
void Information();
void MainMenu(int Triangle[]);
int CorrectEnter(int max, int min);

int main()
{
	int Triangle[9];
	MainMenu(Triangle);
	return 0;
}


int CorrectEnter(int max,int min)
{
	int forReturn;

	do
	{
		if (!scanf("%d", &forReturn))
		{
			printf("ERROR\n");
			fflush(stdin);
			continue;
		}
			
	} while (forReturn > min && forReturn < max);
}

void MainMenu(int Triangle[])
{
	int temp;

	while (1)
	{
		printf("|------------------------------------------------------|\n");
		printf("| 1 --> Enter the coordinates of the triangle vertices |\n");
		printf("| 2 --> Determine the type of triangle                 |\n");
		printf("| 3 --> The output perimeter of the triangle           |\n");
		printf("| 4 --> The area of the triangle		       |\n");
		printf("| 5 --> Calculate and output radius		       |\n");
		printf("| 6 --> Information about the version and author       |\n");
		printf("| 7 --> Exit from the program			       |\n");
		printf("|------------------------------------------------------|\n");

		int key = CorrectEnter(1, 7);
		switch (key)
		{
		case 1:
			EnterPosition(Triangle);
			break;
		case 2:
			TriangleView(Triangle);
			break;
		case 3:
			temp = GetPerimetr(Triangle);
			printf("Perimetr = %d",temp);			
			break;
		case 4:
			temp = GetSquare(Triangle);
			printf("Square = %d", temp);
			
			break;
		case 5:
			PerimetrOfCircleR(Triangle);
			PerimetrOfCircler(Triangle);
			break;
		case 6:
			Information();
			break;
		case 7:
			return;
		default:
			printf("Incorrect");

		}
	}
}

void Information()
{
	printf("Author -- Gavrik Andrey\nVersion: 10.0.3\nGmail for communication : Trooman22@gmail.com\n");
}

void PerimetrOfCircleR(int Triangle[])
{
	double R = (Triangle[6] * Triangle[7] * Triangle[8]) / (4 * GetSquare(Triangle));
	printf("R = %f\n",R);
}


void PerimetrOfCircler(int Triangle[])
{
	double r = 2*GetSquare(Triangle)/GetPerimetr(Triangle);
	printf("r = %f\n", r);
}



float GetSquare(int Triangle[])
{
	float P = GetPerimetr(Triangle) / 2;
	P = P * (P - Triangle[6])*(P - Triangle[7])*(P - Triangle[8]);
	return sqrt(P);
}

float GetPerimetr(int Triangle[])
{
	return Triangle[6] + Triangle[7] + Triangle[8];
}

void TriangleView(int Triangle[])
{
	//regular triangle
	if ((Triangle[6] == Triangle[7]) && (Triangle[6] == Triangle[8]))
	{
		printf("Regular Triangle\n");
		return;
	}
	//isosceles triangle
	if ((Triangle[6] == Triangle[7]) || (Triangle[6] == Triangle[8]) || (Triangle[7] == Triangle[8]))
	{
		printf("Isosceles Triangle\n");
		return;
	}
	//Right Triangle
	if (Triangle[6] > Triangle[7] && Triangle[6] > Triangle[8])
	{
		int check = sqrt((Triangle[7] * Triangle[7] + Triangle[8] * Triangle[8]));
		if (check == Triangle[6])
		{
			printf("Right Triangle\n");
			return;
		}

	}
	///////
	if (Triangle[7] > Triangle[8] && Triangle[7] > Triangle[8])
	{
		int check = sqrt((Triangle[6] * Triangle[6] + Triangle[8] * Triangle[8]));
		if (check == Triangle[7])
		{
			printf("Right Triangle\n");
			return;
		}

	}
	//////
	if (Triangle[8] > Triangle[7] && Triangle[8] > Triangle[8])
	{
		int check = sqrt((Triangle[7] * Triangle[7] + Triangle[6] * Triangle[6]));
		if (check == Triangle[8])
		{			
			printf("Right Triangle\n");
			return;
		}

	}
		printf("Arbitrary Triangle\n");
}

void GetLenght(int Triangle[])//A = (0,3),B = (0,0),C = (4,0)
{
	//side AB
	Triangle[6] = sqrt((Triangle[0] - Triangle[2])*(Triangle[0] - Triangle[2]) + (Triangle[1] - Triangle[3])*(Triangle[1] - Triangle[3]));
	//side AC
	Triangle[7] = sqrt((Triangle[0] - Triangle[4])*(Triangle[0] - Triangle[4]) + (Triangle[1] - Triangle[5])*(Triangle[1] - Triangle[5]));
	//side BC
	Triangle[8] = sqrt((Triangle[2] - Triangle[4])*(Triangle[2] - Triangle[4]) + (Triangle[3] - Triangle[5])*(Triangle[3] - Triangle[5]));
	//printf("AB = %d\n AC = %d\n BC = %d\n", Triangle[6],Triangle[7],Triangle[8]);

}

void EnterPosition(int Triangle[])
{
	printf("Enter coordinates x and y for point A \n");
	Triangle[0] = CorrectEnter(0,1000);
	Triangle[1] = CorrectEnter(0, 1000);
	printf("Enter coordinates x and y for point B\n");
	Triangle[2] = CorrectEnter(0, 1000);
	Triangle[3] = CorrectEnter(0, 1000);
	printf("Enter coordinates x and y for point C\n");
	Triangle[4] = CorrectEnter(0, 1000);
	Triangle[5] = CorrectEnter(0, 1000);

	GetLenght(Triangle);
}
