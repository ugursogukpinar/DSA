#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>





int main(){
	srand((unsigned)time(0));
	int satirsayisi, sutunsayisi,i,j,matris[31][31],k,temp,bagintimatrisi[31][31],a=0,deger,b,bulunan,secim,dugumlermatrisi[100][3],s=0,renk=0,sakliadres=0,h=2,g,color=45,ilksefer=0,gun=0;
	
	printf("Asagidaki kriterlere gore seciminizi gerceklestiriniz\n");
	printf("1-Random elemanlarla ve random satir sutun sayili bir matris olusturmak icin seciniz\n");
	printf("2-Matrisinizi kendiniz olusturmak icin seciniz\n");
	printf("3-Odevde verilen matris icin seciniz\n");
	scanf("%d",&secim);
	
	if( secim==1){
	
	printf("Matrisiniz rastgele satir sutun sayisi ve elemanlarla olusturulacaktir\n");
	satirsayisi=(rand()%10)+2;
	printf("Satir sayisi: %d\n",satirsayisi);
	sutunsayisi=(rand()%10)+2;
	printf("Sutun sayisi: %d\n",sutunsayisi);
	
	printf("\n");
	
	printf("Siralanmamis ve rastgele degerlerle uretilen matris olusturuldu\n");
	
	for (i=0;i<satirsayisi;i++){
	   for (j=0;j<sutunsayisi;j++){
	             matris[i][j]=(rand()%35)+1;
				 printf("%d        ",matris[i][j]);
			}
			printf("\n");
		}
}

else if( secim==2){
	printf("Satir ve sutun sayisini sirayla giriniz\n");
	scanf("%d",&satirsayisi);
	scanf("%d",&sutunsayisi);
	
	for (i=0;i<satirsayisi;i++){
	   for (j=0;j<sutunsayisi;j++){
	    
			scanf("%d",&matris[i][j]);
			}
			printf("\n");
		}
	
}

else if( secim==3){
 int ematris[6][9] = { {11 , 13 , 15 , 17 , 19 , 21 , 23 , 25 , 33 }, {12 , 14 , 16 , 20 , 22 , 24 , 26 , 35 , 43} , {1 , 17 , 24 , 31 , 33 , 35 , 39 , 43 , 45 } , { 32 , 34 , 36 , 38 , 39 , 42 , 44 , 46 , 48 } , { 16 , 38 , 43 , 51 , 57 , 61 , 63 , 45 , 58} , {34 , 54 , 57 , 58 , 59 , 63 , 64 , 71 , 72 } };
	satirsayisi=6;
	sutunsayisi=9;
		for (i=0;i<satirsayisi;i++){
	   for (j=0;j<sutunsayisi;j++){
	    
			matris[i][j]=ematris[i][j];
			}
			printf("\n");
		}
	
}
	
		printf("\n");
		printf("Her satir kendi icinde sirali forma donusturuldukten sonra matrisin yeni hali\n");
		
	for(k=0;k<satirsayisi;k++){
		for(i=0;i<sutunsayisi-1;i++){
             for(j=i+1;j<sutunsayisi;j++){
             	if(matris[k][i]>matris[k][j]){
			      temp=matris[k][i];
			      matris[k][i]=matris[k][j];
			      matris[k][j]=temp;
			  }
		}
	}
}

	
		printf("\n");
	for (i=0;i<satirsayisi;i++){
	   for (j=0;j<sutunsayisi;j++){
				 printf("%d        ",matris[i][j]);
			}
			printf("\n");
		}
		
	printf("\n");	
	printf("Her satiri kendi icinde sirali rastgele matristen olusturulan baglanti matrisi asagidaki gibidir\n");
	
	for(i=0;i<satirsayisi;i++){
		for(j=0;j<satirsayisi;j++){
		         bagintimatrisi[i][j]=0;
		}
	}
	printf("\n");	
   // for (i=0;i<satirsayisi;i++){
   // if(i==0)
//	printf("Dugum Numarasi:%d           ",i);
//	else
	//	printf("%d      ",i);
   // }
	for (i=0;i<satirsayisi;i++){
	   for (j=0;j<satirsayisi;j++){
	   	    //    if(j==0){
			//	   a++;
			//	 printf("Dugum Numarasi %d:%d        ",a,bagintimatrisi[i][j]);
		//	printf("%d        ",bagintimatrisi[i][j]);
			    }
				//else
	//		printf("\n");	
			}
	i=0;
	j=0;		
	a=1;
	k=0;
/*
while(i+1<satirsayisi){
deger=matris[i][k];
bulunan=matris[i+a][j];
printf("Deger:%d Bulunan:%d\n",deger,bulunan);
if(bulunan<deger){
j++;	
printf("Kucukse j:%d\n",j);
}
else if(bulunan==deger){
if((a)==satirsayisi){
i++;
a=1;
printf("Satira esitse a:%d i:%d\n",a,i);
}
else{
bagintimatrisi[i][a]=1;
a++;
printf("Bulunduysa a:%d\n",a);	
}
}
else if(bulunan>deger){
if((k)==satirsayisi){
a++;
printf("k Satira esitse a:%d\n",a);	
}
else{
k++;	
printf("Buyukse k:%d\n",k);
}
}
}
*/
/*
while(i+1<satirsayisi){
deger=matris[i][k];
bulunan=matris[i+a][j];
printf("Deger:%d Bulunan:%d\n",deger,bulunan);
while(bulunan<=deger){
	j++;
	printf("Kucukse j:%d\n",j);
}
if(bulunan==deger){
	bagintimatrisi[i][a]=1;
	a++;
	if(a>=satirsayisi-1){
i++;
a=1;
printf("Satira esitse a:%d i:%d\n",a,i);
}
}
else{
	k++;	
printf("Buyukse k:%d\n",k);
if((k)>=satirsayisi-1){
a++;
printf("k Satira esitse a:%d\n",a);	
}
}
}
*/	
while(i<=satirsayisi-1){


while(k<=sutunsayisi && deger!=0 && (i+a)<satirsayisi){
deger=matris[i][k];
bulunan=matris[i+a][j];
//printf("Deger:%d Bulunan:%d\n",deger,bulunan);
while(bulunan<deger && j<sutunsayisi){
	bulunan=matris[i+a][j];
	j++;
	printf("Deger:%d Bulunan:%d\n",deger,bulunan);
}
if(bulunan==deger){
	bagintimatrisi[i][a+i]=1;
	dugumlermatrisi[s][1]=i;
	dugumlermatrisi[s][2]=a+i;
	dugumlermatrisi[s][3]=bulunan;
	a++;
	k=0;
	j=0;
	s++;
	printf("Bulundu i:%d a:%d\n",i,a);
}
else{
    
	k++;
	j=0;
	printf("%d. satirda satirda %d. dizi elemami karsilastiriliyor\n",i,k);
}

if(k==sutunsayisi){
	a++;
	k=0;
	j=0;
}

}
i++;
a=1;
k=0;
j=0;
printf("Satir no guncellendi artik %d .satira bakiliyor\n",i);
}
	
		printf("\n");	
	printf("Her satiri kendi icinde sirali rastgele matristen olusturulan baglanti matrisi asagidaki gibidir\n");
	printf("\n");	
		for (i=0;i<satirsayisi;i++){
	   for (j=0;j<satirsayisi;j++){
	   	    //    if(j==0){
			//	   a++;
			//	 printf("Dugum Numarasi %d:%d        ",a,bagintimatrisi[i][j]);
			printf("%d        ",bagintimatrisi[i][j]);
			    }
				//else
			printf("\n");	
			}
			
		printf("\n");
		printf("Transpozesi alinan baglanti matrisi\n");	
		
			for (i=0;i<satirsayisi;i++){
	   for (j=0;j<satirsayisi;j++){
	   	if(j>i){
	   	if(bagintimatrisi[i][j]==1){
	   	bagintimatrisi[j][i]=1;
       }
	   }
	   }
       }
	
	
		printf("\n");	
		for (i=0;i<satirsayisi;i++){
	   for (j=0;j<satirsayisi;j++){
	   	    //    if(j==0){
			//	   a++;
			//	 printf("Dugum Numarasi %d:%d        ",a,bagintimatrisi[i][j]);
			printf("%d        ",bagintimatrisi[i][j]);
			    }
				//else
			printf("\n");	
			}
			
			
				printf("\n");	
	printf("Dugumler matrisi asagadaki gibidir\n");
	printf("\n");
	printf("Dugum Numarasi         Dugum Numarasi            Baglanti Degeri\n");	
	printf("\n");
		for (i=0;i<s;i++){
	   for (j=1;j<4;j++){
	   	    //    if(j==0){
			//	   a++;
			//	 printf("Dugum Numarasi %d:%d        ",a,bagintimatrisi[i][j]);
			printf("%d                           ",dugumlermatrisi[i][j]);
			    }
				//else
			printf("\n");	
			}
		
	
	bagintimatrisi[0][0]=color;	
	i=0;
	j=i+1;	
	printf("\n");
	printf("Graf boyamasi sonuclari asagidaki gibidir\n");	
	//printf("Satirsayisi %d",satirsayisi);
//	for(i=0;i<satirsayisi;i++){
    while(i<satirsayisi){
    	
    	
    	if(bagintimatrisi[i][i]!=0 && i!=0){
    	//	if(ilksefer==0){
    		printf("Baginti matrisi[i][i]:%d i:%d Girdimi\n",bagintimatrisi[i][i],i);
    		i++;
    		j=i+1;	
		    g=0;
            sakliadres=0;
            h=0;
        //}
    	}
    else{
    
    ilksefer=1;
    bagintimatrisi[i][i]=color;
    color++;	
    
	while(j<satirsayisi){
//	for(j=0;j<satirsayisi;j++){
		if(sakliadres==0){
			printf("J nin artirilmis degeri %d i %d",j,i);
		while (bagintimatrisi[i][j]!=0){
			printf("0 degil\n");
			j++;
			printf("J nin artirilmis degeri %d",j);
		}
		sakliadres=j;
		bagintimatrisi[j][j]=bagintimatrisi[i][i] ;
			
			for(k=i+1;k<j;k++)	{
			bagintimatrisi[k][j]=-9;
			}
}
else{
	j=sakliadres+1;
	if (bagintimatrisi[i][j]==0){
		printf("%d. 0i bulduk %d\n",h,j);
	  //	bagintimatrisi[j][j]=bagintimatrisi[i][i] ;
		sakliadres++;
		h++;
		g=sakliadres;
		while(g>0){
			g--;
			if(bagintimatrisi[i][g]==0){
				if(bagintimatrisi[i][i]==bagintimatrisi[g][g]){
				if(bagintimatrisi[sakliadres][g]==0){
						bagintimatrisi[j][j]=bagintimatrisi[i][i] ;
							for(k=i+1;k<j;k++)	{
			bagintimatrisi[k][j]=-9;
			}
				}
				else{
					g=0;
				}
			}
			}
			
		}	
	}
	else {
		sakliadres++;
	}
	
	   // j=sakliadres;
		
}
}

//	color++;
  //  bagintimatrisi[i][i]=color;

i=i+1;
j=i+1;
g=0;
sakliadres=0;
h=0;
printf("\n");
printf("Satir degisti");
}


}
		
	/*	if(bagintimatrisi[i][j]==0){
			
			for(s=j;s>0;s--){
			
			if(s==0){
			
			if(bagintimatrisi[s][j]==1){
			
			printf("0 Var ama daha once baglatisi var\n");
			}
			
			if(s==1){
				
			printf("1 var\n");	
			
			}
			
			
			bagintimatrisi[j[j]=bagintmatrisi[i][i] ;
			
			for(k=i;k<satirsayisi;k++)	{
			bagintimatrisi[k][j]=-9;
			}
			
			}
		}*/
	//	}
//	}		
 //   }
			
			
		printf("\n");	
		for (i=0;i<satirsayisi;i++){
	   for (j=0;j<satirsayisi;j++){
	   	    //    if(j==0){
			//	   a++;
			//	 printf("Dugum Numarasi %d:%d        ",a,bagintimatrisi[i][j]);
			printf("%d        ",bagintimatrisi[i][j]);
			    }
				//else
			printf("\n");	
			}		
	
	
	
	//Gunler
	
 char gunler[7] ;
 
gunler[0] ="Pazartesi";
gunler[1] ="Salý";
gunler[2] ="Çarsamba";
gunler[3] ="Persembe";
gunler[4] ="Cuma";
gunler[5] ="Cumartesi";
gunler[6] ="Pazar";
 
 
 
	gun=0;
	
	for(i=0;i<satirsayisi;i++){
		for(k=0;k<satirsayisi;k++){
			if(bagintimatrisi[i][i]=bagintimatrisi[k][k]){
		deger=bagintimatrisi[i][i];
		printf("%d. ders %d. ders ile ayni gun yapilabilir ve ders %s olabilir",bagintimatrisi[i][i],bagintimatrisi[k][k],gunler[gun][30]);
		gun++;
	                 }
		
	}
}
	
	getch();
	return 0;
}
