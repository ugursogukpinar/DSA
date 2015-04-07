 #include<stdio.h>
 #include<conio.h>
 #include <time.h>
 #include<stdlib.h>


void mergesiralama(int dizi1[],int kucuk,int ortaeleman,int buyuk);
void bolme(int dizi1[],int kucuk,int buyuk);
void quicksiralama(int [100],int,int);


int main(){
	
   	srand((unsigned)time(0));
   	
    int dizi[1000],i,n,secim,secim2;
    printf("Siralama metodunu seciniz\n");
    printf("1-Merge Sort algoritmasiyla siralama yapmak icin seciniz\n");
    printf("2-Quick Sort algoritmasiyla siralama yapmak icin seciniz\n");
    
	scanf("%d",&secim);
	//printf("Seciminiz %d dir\n",secim);
	
    printf("Toplam eleman sayisini giriniz: ");
    scanf("%d",&n);

    printf("Dizi olusturma yontemi ile ilgili metodu seciniz\n");
    printf("1-Diziyi el ile kendiniz girmek icin seciniz\n");
    printf("2-Diziyi random uretmek icin seciniz\n");
    scanf("%d",&secim2);
    //printf("Seciminiz %d dir\n",secim2);
    	
	if(secim2==1){
	
	printf("Sirasiz dizinizi giriniz:\n");
    for(i=0;i<n;i++){
         scanf("%d",&dizi[i]);
    }
}
else if(secim2==2){

	
	for(i=0;i<n;i++)
	dizi[i]=rand()%100 ;
	
}

if(secim==1)
    bolme(dizi,0,n-1);
else if(secim==2)
    quicksiralama(dizi,0,n-1);

    printf("\nDiziniz siralandiktan sonra asagidaki gibi olur:");
    for(i=0;i<n;i++){
         printf("%d ",dizi[i]);
    }
   
   getch();
   return 0;
}

void bolme(int dizi1[],int kucuk,int buyuk){

    int ortaeleman;

    if(kucuk<buyuk){
         ortaeleman=(kucuk+buyuk)/2;
         bolme(dizi1,kucuk,ortaeleman);
         bolme(dizi1,ortaeleman+1,buyuk);
         mergesiralama(dizi1,kucuk,ortaeleman,buyuk);
    }
}

void mergesiralama(int dizi1[],int kucuk,int ortaeleman,int buyuk){

    int i,m,s,k,temp[500];

    k=kucuk;
    i=kucuk;
    m=ortaeleman+1;

    while((k<=ortaeleman)&&(m<=buyuk)){

         if(dizi1[k]<=dizi1[m]){
             temp[i]=dizi1[k];
             k++;
         }
         else{
             temp[i]=dizi1[m];
             m++;
         }
         i++;
    }

    if(k>ortaeleman){
         for(s=m;s<=buyuk;s++){
             temp[i]=dizi1[s];
             i++;
         }
    }
    else{
         for(s=k;s<=ortaeleman;s++){
             temp[i]=dizi1[s];
             i++;
         }
    }
   
    for(s=kucuk;s<=buyuk;s++){
         dizi1[s]=temp[s];
    }
}


 void quicksiralama(int dizi2[50],int ilk,int son){
    int pivot,j,temp2,i;

     if(ilk<son){
         pivot=ilk;
         i=ilk;
         j=son;

         while(i<j){
             while(dizi2[i]<=dizi2[pivot]&&i<son)
                 i++;
             while(dizi2[j]>dizi2[pivot])
                 j--;
             if(i<j){
                 temp2=dizi2[i];
                  dizi2[i]=dizi2[j];
                  dizi2[j]=temp2;
             }
         }

         temp2=dizi2[pivot];
         dizi2[pivot]=dizi2[j];
         dizi2[j]=temp2;
         quicksiralama(dizi2,ilk,j-1);
         quicksiralama(dizi2,j+1,son);

    }
}

