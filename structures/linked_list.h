

typedef struct NODE
{
	unsigned int value; // Biz her bir düğüm için tek veri saklayacağız. 
	struct NODE *next; // Burada bir sonraki elemanın yerini saklayacağız. Bir sonraki elemanda NODE tipinde olmalı.
}NODE;



NODE* insert(NODE *, int); 
void search(NODE *, int); 
NODE* delete(NODE *, int); 
void write(NODE *);
NODE* readAllElements(NODE *);





