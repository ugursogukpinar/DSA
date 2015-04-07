#include <stdio.h>
#include <conio.h>
#include <stdlib.h>


int main(){
	
	int hufmann[51],N,M,i,Mesajdizisi[100],adresleri[10],k=0,s=0,j=0,Toplam=0,bitsayisi=0,Toplamsikistirilmadan=0;
	char karekterler[10],cozulenmetin[50];
	float verim=0;
	
	M=25 ;// Huffman treenin eleman sayisi
	N=2*M+5 ; // Hufmanin gözlerini sifirlamak icin
	
	for(i=1;i<N;i++){           //Hufmann dizisi 2 kati elemandan fazlasiyla sifirlandi
		hufmann[i]=0;
	}
	
	hufmann[1]=410;            //HUFMANN ELLE OLUSTURULDU
	hufmann[2]=167;
	hufmann[3]=243;
	hufmann[4]=77;
	hufmann[5]=90;
	hufmann[6]=113;             //HUFMANN ELLE OLUSTURULDU
	hufmann[7]=130;
	hufmann[8]=37;
	hufmann[9]=40;
	hufmann[10]=0;
	hufmann[11]=0;
	hufmann[12]=55;             //HUFMANN ELLE OLUSTURULDU
	hufmann[13]=58;
	hufmann[14]=60;
	hufmann[15]=70;
	hufmann[16]=17;
	hufmann[17]=20;
	hufmann[18]=0;              //HUFMANN ELLE OLUSTURULDU
	hufmann[19]=0;
	hufmann[20]=0;
	hufmann[21]=0;              //HUFMANN ELLE OLUSTURULDU
	hufmann[22]=0;
	hufmann[23]=0;
	hufmann[24]=25;
	hufmann[25]=30;             //HUFMANN ELLE OLUSTURULDU
	
	printf("Verilenler:\n");
	printf("\n1-Hufmann agaci\n");
		for(i=1;i<N;i++){           //Hufmann dizisi yazdiriliyor
		printf("%d  ",hufmann[i]);
	}
	
	
	Mesajdizisi[1]=0;      // 0 ve 1 ile kodlanmis dizinin olusturulmasi
	Mesajdizisi[2]=1;
	
	Mesajdizisi[3]=0;
	Mesajdizisi[4]=0;
	Mesajdizisi[5]=1;
	
	Mesajdizisi[6]=0;
	Mesajdizisi[7]=0;
	Mesajdizisi[8]=1;
	
	Mesajdizisi[9]=1;     // 0 ve 1 ile kodlanmis dizinin olusturulmasi          
	Mesajdizisi[10]=1;
	Mesajdizisi[11]=1;
	
	Mesajdizisi[12]=1;
	Mesajdizisi[13]=0;
	Mesajdizisi[14]=0;
	Mesajdizisi[15]=0;
	                     // 0 ve 1 ile kodlanmis dizinin olusturulmasi
	Mesajdizisi[16]=1;
	Mesajdizisi[17]=1;
	Mesajdizisi[18]=1;
	
	Mesajdizisi[19]=1;
	Mesajdizisi[20]=0;
	Mesajdizisi[21]=0;
	Mesajdizisi[22]=1;  
	                    // 0 ve 1 ile kodlanmis dizinin olusturulmasi  
	Mesajdizisi[23]=1;
	Mesajdizisi[24]=1;
	Mesajdizisi[25]=0;
	
	Mesajdizisi[26]=0;
	Mesajdizisi[27]=0;  
    Mesajdizisi[28]=0;   // 0 ve 1 ile kodlanmis dizinin olusturulmasi
	Mesajdizisi[29]=0;
	
	Mesajdizisi[30]=1;
	Mesajdizisi[31]=1;
	Mesajdizisi[32]=0;
	
	Mesajdizisi[33]=0;     // 0 ve 1 ile kodlanmis dizinin olusturulmasi
	Mesajdizisi[34]=0;
	Mesajdizisi[35]=0;  
	Mesajdizisi[36]=1;
	
	
	
	Mesajdizisi[37]=-1;
	Mesajdizisi[38]=-1;
	Mesajdizisi[39]=-1;
	Mesajdizisi[40]=-1;   //Bitiþ noktasini gosteriyor diger 0'larla karismasin diye
	Mesajdizisi[41]=-1;	
	Mesajdizisi[42]=-1;	
	Mesajdizisi[43]=-1;	
	Mesajdizisi[44]=-1;	
	printf("\n");
	printf("\n2-0 ve 1lerden olusan ve cozulmesi beklenen mesaj bilgisi\n");
	
			for(i=1;i<36;i++){           //Mesaj dizisi dizisi yazdiriliyor
		printf("%d  ",Mesajdizisi[i]);
	}
	
	karekterler[1]='A';     adresleri[1]=5;
	karekterler[2]='N';     adresleri[2]=9;
	karekterler[3]='B';     adresleri[3]=13;
	karekterler[4]='I';     adresleri[4]=14;
	karekterler[5]='E';     adresleri[5]=15;
	karekterler[6]='M';     adresleri[6]=16;
	karekterler[7]='Z';     adresleri[7]=17;
	karekterler[8]='L';     adresleri[8]=24;
	karekterler[9]='R';     adresleri[9]=25;

	printf("\n");
	printf("\n3-Karekterler ve hufmann agacindaki adresleri\n");
		
			for(i=1;i<10;i++){           //Mesaj dizisi dizisi yazdiriliyor
		printf("%d  ",adresleri[i]);
	}
			printf("\n");
			for(i=1;i<10;i++){           //Mesaj dizisi dizisi yazdiriliyor
		printf("%c   ",karekterler[i]);
	}
	
	//Cozum icin gelistirlen algoritma baslangici
	i=1;
	k=1;
	s=1;
	j=1;
	printf("\n");
	while(Mesajdizisi[j]!=-1){
	//printf("i:%d\n",i); //Analiz için yazdirma
	while(hufmann[i]!=0){
		//printf("Dongu Ýci:Mesajdizisi[i]:%d\n",Mesajdizisi[j]);  //Analiz için yazdirma
		if(Mesajdizisi[j]==0)
		i=2*i;
		else
		i=2*i+1;
		
		bitsayisi++;
		j++;
	//	printf("Dongu Ýci:j:%d\n",j);  //Analiz için yazdirma
	}
	bitsayisi--;
		//printf("\ni:%d\n",bitsayisi); //Analiz icin yazdirma
	j--;
	i=i/2;
	Toplam=Toplam+hufmann[i]*bitsayisi;
	Toplamsikistirilmadan=Toplamsikistirilmadan+hufmann[i]*8;
	bitsayisi=0;
	//	printf("\nToplam:%d\n",Toplam);     // Analiz için yazdirma
	//		printf("\nToplamsikistirilmadan:%d\n",Toplamsikistirilmadan);   //Analiz için yazdirma
//	printf("\ni:%d\n",i);  //Analiz için yazdirma
//	printf("j:%d\n",j);   //Analiz için yazdirma
	while(i!=adresleri[k])
	k++;
	
	
//	printf("k:%d\n",k);    //Analiz için yazdirma
	cozulenmetin[s]=karekterler[k];
	
	s++;
	// printf("s:%d\n",s); //Analiz için yazdirma
//	 printf("%c\n",cozulenmetin[s-1]);  //Analiz için yazdirma
	k=1;
	i=1;
    }
     // printf("%d",s);
    printf("\n");
    printf("\n");
    printf("\nSonuclar:\n");
    printf("\n");
	printf("1-Uretilen metin:\n");
	for(i=1;i<s;i++){           //Sonuc dizisi
	printf("%c",cozulenmetin[i]);
	}
	
	printf("\n");
    printf("\n");
	printf("2-Sikistirma verimi:\n");
	printf("\n");
	    printf("\nToplam Sikistirilinca:%d (bit sayisi)\n",Toplam);     // Analiz için yazdirma
		printf("\nToplam Sikistirilmadan:%d (bit sayisi)\n",Toplamsikistirilmadan);   //Analiz için yazdirma
	   verim=(float(float(Toplamsikistirilmadan-Toplam))/(float (Toplamsikistirilmadan)))*100 ;
	    printf("\nVerim(Yuzde):%f\n",verim);
	
	
	return 0;
	getch();
}
