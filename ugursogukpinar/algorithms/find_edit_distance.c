/*
* Bu program verilen ilk kelimenin ikinci gelimeye dönüştürülebilmesi için
* yapılacak en az hamleyi hesaplar.
* 
* author: Uğur Soğukpınar<sogukpinar.ugur@gmail.com>
* date: 11 November 2015
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct ED_STRUCT {

	char *word_1;
	char *word_2;
	int word_1_length;
	int word_2_length;
	int **ed_matrix;
}ED_STRUCT;



char *read_word(char *, int *);
int insert(ED_STRUCT *edstruct, int row, int column);
int delete(ED_STRUCT *edstruct, int row, int column);
int mapped(ED_STRUCT *edstruct, int row, int column);


int main() 
{
	ED_STRUCT edstruct; 
	int min;

	edstruct.word_1 = (char *) malloc (sizeof(char));
	edstruct.word_2 = (char *) malloc (sizeof(char));


	printf("Please enter first word: ");
	edstruct.word_1 = read_word(edstruct.word_1, &edstruct.word_1_length);

	
	printf("Please enter second word: ");
	edstruct.word_2 = read_word(edstruct.word_2, &edstruct.word_2_length);


	edstruct.ed_matrix = (int **) malloc (sizeof(int *) * edstruct.word_1_length);

	for (int i = 0; i < edstruct.word_1_length; ++i)
	{
		edstruct.ed_matrix[i] = (int *) malloc (sizeof(int) * edstruct.word_2_length);
		edstruct.ed_matrix[i][0] = i;
	}

	for (int i = 0; i < edstruct.word_2_length; ++i)
	{
		edstruct.ed_matrix[0][i] = i;
	}


	for (int i = 1; i < edstruct.word_1_length; ++i)
	{
		for (int j = 1; j < edstruct.word_2_length; ++j)
		{
			min = insert(&edstruct, i, j);

			if (min > delete(&edstruct, i , j))
			{
				min = delete(&edstruct, i , j);
			}

			if (min > mapped(&edstruct, i, j))
			{
				min = mapped(&edstruct, i, j);
			}

			edstruct.ed_matrix[i][j] = min;			
		}
	}

	for (int i = 0; i < edstruct.word_1_length; ++i)
	{
		for (int j = 0; j < edstruct.word_2_length; ++j)
		{
			
			printf(" %d ", edstruct.ed_matrix[i][j]);
		}
		printf("\n");
	}

	return EXIT_SUCCESS;
}



char *read_word(char *word, int *length) 
{
	char tmp_char;
	*length = 1;

	while ( (tmp_char = getc(stdin)) != '\n')
	{
		word = (char *) realloc(word, sizeof(char) * ++(*length)); 
		word[*length-2] = tmp_char;		
	}	

	word[*length - 1] = '\0';

	return word;
}


int insert(ED_STRUCT *edstruct, int row, int column) 
{
	return 1 + edstruct->ed_matrix[row][column - 1];
}


int delete(ED_STRUCT *edstruct, int row, int column)
{
	return 1 + edstruct->ed_matrix[row - 1][column];
}


int mapped(ED_STRUCT *edstruct, int row, int column)
{
	int diff = 0;

	if (edstruct->word_1[row - 1] != edstruct->word_2[column - 1])
	{
		diff = 1;
	}

	return diff + edstruct->ed_matrix[row - 1][column - 1];
}