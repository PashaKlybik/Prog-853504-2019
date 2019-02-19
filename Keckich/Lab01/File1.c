//---------------------------------------------------------------------------

#include <stdio.h>
#pragma hdrstop

#include <tchar.h>
//---------------------------------------------------------------------------

#include <conio.h>
#include <malloc.h>
#include <stdlib.h>
#pragma argsused
int _tmain (int argc, _TCHAR * argv[])
{
  _Bool t = 1;
  int m, i, j, lenb, lena;
  char b[50], *a;

  printf("Your number:");
  scanf_s("%d",&m);
  itoa(m, b, 2);

  lenb = strlen (b);
  a = (char*)malloc(lenb * sizeof(char));

  for (i = 1; i <= m; i++)
	{
	  itoa (i, a, 2);
	  lena = strlen (a);
	  for (j = 0; j < lena; j += 2)
	  {
	   if (a[j] == a[j + 2] || a[j + 1] == a[j + 3] || a[j] != a[j + 1]
		   || a[j + 2] != a[j + 3] || lena % 2 != 0 || lena < 4)
		{
		  t = 0;
		}
	  }

	  if (t == 1)
	  {
	   printf("\n%s", a);
	   printf(" - %d", i);
	  }
	  t = 1;
	}
  free(a);
  getch ();
  return 0;
}
//---------------------------------------------------------------------------
