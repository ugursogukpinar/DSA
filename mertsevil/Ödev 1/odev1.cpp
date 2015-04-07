#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>


int main(){
  srand((unsigned)time(0));
  int boyut=0,secim=1,i=1,aranan=1,eleman=1,rastgele,adimsayisi;
  printf("Agaciniza girilebilecek maksimum eleman sayisini giriniz:\n");  
  scanf("%d",&boyut);                         //Maksimum eleman sayýsý kullanýcýdan alýnarak dinamik dizi için yer ayýrýlacak
  int* dizi;                                  // Aðaç veri yapýsý dizi üzerinde tutulacak
  dizi=(int *)malloc((boyut*sizeof(int)));   //Dinamik olarak dizi oluþturuldu
	
  for(i=0;i<boyut;i++)     //Dizinin dolayýsla aðacýn bütün gözleri 0 bilgisini tutuyor
  dizi[i]=0;	//Dizinin dolayýsla aðacýn bütün gözleri 0 bilgisini tutuyor
  
  while(secim!=0){
  printf("Menu\n");
  printf("1-Eleman Eklemek icin 1'e basin\n");
  printf("2-Eklediginiz elemanini aramak icin 2'ye basin\n");
  printf("3-Agaci lineer bir dizi olarak gozlemlemek icin 3'e basin\n");
  printf("4-Agacin tum elemanlarini sifirlamak ve tum elemanlari silmek icin 4'e basin\n");
  printf("5-Random elemanlarla butun dizi boyutu kadar elemanla doldurulmus rastgele bir agac yaratmak icin 5'e basin\n");
  printf("6-Aramayi lineer bir diziymis gibi yapmak icin 6'ya basin (Binary Tree Search ile adim sayisini karsilastirmak icin\n");
  printf("7-Programi tamamen sonladirmak icin 0'a basin\n");
  
  
  scanf("%d",&secim);
  aranan=1;
  eleman=1;
  
  
  if(secim==1){                  //Tek tek eleman ekleyerek agaci olusturmak icin
  while(eleman!=0){
  i=1;
  printf("Diziye tek tek eleman ekleyin!!!\nMaksimum eleman sayisini asmayin!!\nMenuyedonmek icin 0'a basin\n");
  printf("Eklenmesi istenilen elemani giriniz\n");
  scanf("%d",&eleman);
  while(dizi[i]!=0 || (2*i+1)>boyut){
  	if(eleman>dizi[i])
  	i=2*i+1;
  	else
  	i=2*i;
  }
  dizi[i]=eleman;
  printf("Eleman basariyla eklendi\n%d. gozde %d degerine sahip eleman bulunmaktadir\n",i,eleman);
}
}


else if(secim==2){    //Binary Search Tree Arama Algoritmasý için
   i=1;
   while(aranan!=0){
   i=1;
  printf("Aranan sayiyi giriniz\nMenuyedonmek icin 0'a basin\n");
  printf("Aranan elemani giriniz\n");
  scanf("%d",&aranan);
   while(!((dizi[i]==0 ) || (aranan==dizi[i])) && (2*i+1<boyut)){
  	if(aranan>dizi[i]){
  	printf("Aranan:%d Dizi[i]:%d Aranan Daha Kucuk i:%d\n",aranan,dizi[i],i);
  	i=2*i+1;
    }
	  else{
  	i=2*i;
  	printf("Aranan:%d Dizi[i]:%d Aranan Daha Buyuk i:%d\n",aranan,dizi[i],i);
    }
  	adimsayisi++;
  }
  if(0==dizi[i]) 
  printf("Adim sayisi:%d Aranan sayi agacta mevcut degildir\n",adimsayisi);
  else
  printf("Adim sayisi:%d Aranan eleman bulundu\nBu eleman %d. indisli agac gozunde bulunup degeri %d dir\n",adimsayisi,i,aranan);
  
  adimsayisi=0;
  }
}

else if (secim==3){     //Agaci Lineer bir dizi olarak görmek için
	printf("Agaciniz yatay olarak lineer bir dizi olarak gösterilmektedir\n");
	for(i=0;i<boyut;i++)
	printf("%d    ",dizi[i]);
	
	printf("\n");
}
 
else if(secim==4){     //Agacin tüm elemanlarýný sýfýrlamak icin
	 for(i=0;i<boyut;i++)     //Dizinin dolayýsla aðacýn bütün gözleri 0 bilgisini tutuyor
     dizi[i]=0;	//Dizinin dolayýsla aðacýn bütün gözleri 0 bilgisini tutuyor
}

else if (secim==5){   // Rastgele bir agac olusturmak icin, degerler agacin boyut sayisini asmayacagi ilk degerde kesilir
  i=1;
  adimsayisi=1;
  rastgele=rand()%60;
  dizi[1]=rastgele;
    printf("Rastgele eleman basariyla eklendi\n1. gozde %d degerine sahip eleman bulunmaktadir\n",rastgele);
//hile(adimsayisi^2<boyut){
 //=1;
 //dimsayisi++;
 	//for(i=0;i<boyut/2;i++){
  rastgele=rand()%60;
 while( dizi[i]!=0){
 
 
  	if(rastgele>dizi[i])
  	i=2*i+1;
  	else
  	i=2*i;
}
//
  dizi[i]=rastgele;
  printf("Rastgele eleman basariyla eklendi\n%d. gozde %d degerine sahip eleman bulunmaktadir\n",i,rastgele);
//}
}

else if (secim==6){    // Binary tree search ile karsilastirma yapabilmek icin adim sayisini gorebilecegimiz lineer search algoritmasi
	i=0;
  printf("Lineer bir dizi gibi arama yapilacak\n");
  printf("Aranan sayiyi giriniz\nMenuyedonmek icin 0'a basin\n");
  printf("Aranan elemani giriniz\n");
  scanf("%d",&aranan);
  
  while (aranan!=dizi[i] && i<boyut){
  	i++;
  	adimsayisi++;
  }
  if(aranan==dizi[i])
  printf("Adim Sayisi:%d Aranan eleman bulundu\nBu eleman %d. indisli agac gozunde bulunup degeri %d dir\n",adimsayisi,i,aranan);
  else
  printf("Adim Sayisi:%d Aranan sayi agacta mevcut degildir\n",adimsayisi);
  
  adimsayisi=0;
}

adimsayisi=0;
}

printf("Program sonlandirildi\n");   //Program kullanici istegiyle sonlandirildi
getch();
return 0;
}
