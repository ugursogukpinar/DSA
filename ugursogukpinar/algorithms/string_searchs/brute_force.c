/*
	Brute force yöntemi aranan kelimenin ilk harfini text içerisinde bulup kelimenin kalan kısmını
	üzerine örtüştürerek aranan kelimeyi bulmaya çalışır.

	Author: ugursogukpinar

*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>	

#define MAX_LENGTH 1000


int brute_force(char *, char *);


int main()
{

	char text[MAX_LENGTH], str[MAX_LENGTH];
	int index;

	printf("Please enter text: \n");
	fgets(text, MAX_LENGTH - 1, stdin);


	printf("Please enter string: \n");
	fgets(str, MAX_LENGTH - 1, stdin);

	index = brute_force(text, str);

	if(index != -1)
	{
		printf("Aradığınız kelimenin başlangıç noktası : %d\n", index);
	} else
	{
		printf("Aradığınız kelime bulunamadı!\n");
	}
	return EXIT_SUCCESS;
}




/*
	@param char * text, Arama yapılacak yazı bloğu.
	@param char * str, Aranan kelime 

	@return int , Aranılan kelimenin başlangıç noktası.
*/
int brute_force(char *text, char *str)
{

	register int i=0, j;
	int found = 0;
	int text_length = strlen(text);
	int str_length = strlen(str);

	// Aranılan kelimedeki harf sayısı kadar harf kalmadığında işlemi sonlandırıyoruz.


	while(i < text_length - str_length - 1 && found != 1)
	{

		j=0;

		while(j < str_length - 1 && text[i + j] == str[j])
		{
			j++;
		}

		// Aranılan kelimenin uzunluğu kadar ilerleyebilmişsek , bütün harfler uyuşma göstermiş demektir.
		if(j == str_length - 1)
		{
			found = 1;
		} else
		{
			i++;
		}

		
	}

	if(found){
		return i;
	} 

	return -1;
}



