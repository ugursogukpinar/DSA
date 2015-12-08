#include <stdio.h>
#include <stdlib.h>
#include <math.h>


/*
	1 ila N arasındaki asal sayıları bulur.

	Bu sayılar bulunurken,
		
	1- 1-N arasındaki tüm sayılar bir diziye alınır. ( 1 'in asal olmadığını biliyoruz. )
	2- 1-Karekök N 'e kadar olan sayılar ele alınır.
	3- Ele alınan tüm sayıların kendi katları, 1-N dizisinden silinir.
	4- 1-N dizisinde kalan tüm sayılar asal olmuş olur.
	
*/

int main()
{

	int N, *list, N_SQRT;

	printf("Lütfen N sayısını giriniz: ");
	scanf("%d", &N);

	list = (int *) malloc(sizeof(int) * (N+1));

	// Sayıları bir listeye alıyoruz.
	for(register int i=1; i<=N; i++)
		list[i] = i;


	N_SQRT = sqrt(N);

	for(register int i=1; i <= N_SQRT; i++)
	{

		if( *(list + i) != 1 )
		{
			// i'nin katlarını 1-N lik diziden silelim.
			for (register int j = i * i; j<= N; j += i)
			{
				*(list + j) = 0;
			}
			
		} else
		{
			*(list + i) = 0; // 1 Asal değil.
		}
	}



	for(register int i=1; i <= N; i++)
	{
		if(*(list + i))
		{
			printf("%d\n", *(list + i) );
		}
	}

}