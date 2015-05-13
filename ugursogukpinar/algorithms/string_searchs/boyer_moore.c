/*
	Boyer-Moore String Arama algoritması aranan kelimeyi text bloğunda aranan kelimenin sonundan bakarak karşılaştırır.

	Eğer ki uyuşmayan harf, aranan kelime içerisinde bulunmuyorsa aramaya kelimenin uzunluğu kadar ileriden devam eder.
	Eğer ki uyuşmayan harf aranan kelime içerisinde bulunuyorsa arama işlemi bu iki harf üst üste gelecek şekilde devam eder.

	Author : ugursogukpinar
*/




#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define CHAR_SIZE 255
#define MAX_LENGTH 255

#define max(X,Y) ((X) > (Y) ? (X) : (Y))


int boyer_moore(char *, char *, int *);
int max(int,int);

int main()
{

	
	char text[MAX_LENGTH], str[MAX_LENGTH];
	int indexesFromRight[CHAR_SIZE];
	int adr;		
	int index;

	printf("Please enter text: \n");
	fgets(text, MAX_LENGTH - 1, stdin);


	printf("Please enter string: \n");
	fgets(str, MAX_LENGTH - 1, stdin);




	// Öncelikle harflerin kelime içerisinde kaçıncı indiste bulunduklarını saklamalıyız.
	// Böylece harflerin durumuna göre öteleme işlemlerini gerçekleştirebiliriz.

	for(register int i=0; i < CHAR_SIZE; i++)
		indexesFromRight[i] = -1;


	// Eğer bir harf birden fazla sayıda bulunuyorsa en sağdaki indis tutulur.
	for(register int i=0; i < strlen(str); i++){
		adr = str[i] - '\0';
		indexesFromRight[adr] = i;
	}	

	for(register int i =0; i < strlen(str) - 1; i++)
	{
		adr = str[i] - '\0';
	}



	index = boyer_moore(text, str, indexesFromRight);

	if(index != -1)
	{
		printf("Aradığınız kelimenin başlangıç noktası : %d\n", index);
	} else
	{
		printf("Aradığınız kelime bulunamadı!\n");
	}

	return EXIT_SUCCESS;
}	

int boyer_moore(char *text, char *str, int *indexesFromRight)
{
	int str_length = strlen(str) - 1;
	int text_length = strlen(text) - 1;

	int skip;
	int found = 0;
	register int i=0, j;

	// Kelimenin uzunluğundan daha az sayıda karakter kalana kadar aramaya devam ediyoruz.
	while(i <= text_length - str_length && found != 1)
	{

		// Kelimeyi sondan itibaren karşılaştıracağız.
		j = str_length - 1;


		while(j >= 0 && str[j] == text[i+j])
		{
			j--;
		}

		// Eğer tüm harfler karşılaştırılmışsa kelime bulunmuştur.
		if(j < 0)
		{
			found = 1;
		} else
		{

			// Bu durumda aramaya ne kadar ileriden başlayacağımızı hesaplamamız gerekir.
			skip = max(j - indexesFromRight[text[i + j] - '\0'] , 1);
				printf("%d\n", skip);
			i += skip;
		}
	}


	if(found)
	{
		return i;
	} 

	return -1;
}
