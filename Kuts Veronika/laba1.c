int _tmain()
{
	double vvod;

	int summa_do=0,int_vvod=0,m=0,summa_posle=0;

	printf("Vvedite veschestvennoe chislo: ");

	scanf("%lf",&vvod);

	int_vvod=vvod;

	while(int_vvod!=0)

	{

			summa_do=summa_do+int_vvod%10;

			int_vvod=int_vvod/10;

	}

	int_vvod=vvod+1e-9;

	while (int_vvod==0)

	{

		vvod=vvod*10;

		int_vvod=vvod+1e-9;

		summa_posle=summa_posle+int_vvod;

	}

	while (int_vvod!=0)

	{

		vvod=vvod-int_vvod;

		vvod=vvod*10;

		int_vvod=vvod+1e-9;

		while (int_vvod==0)

		{

		   vvod=vvod*10;

		   int_vvod=vvod+1e-9;

		   m++;

		   if (m==6)

		   {

			   break;

		   }

		}

		summa_posle=summa_posle+int_vvod;

	}

	if(summa_do==summa_posle)

	{

		printf("summa cifr posle tochki: %d\n",summa_posle);

		printf("summa cifr do tochki: %d\n",summa_do);

	}

	if(summa_do<summa_posle)

	{

		printf("summa cifr posle tochki: %d\n",summa_posle);

	}

	else if(summa_do>summa_posle)

	{

		printf("summa cifr do tochki: %d\n",summa_do);

	}

	getch();

	return 0;
}
