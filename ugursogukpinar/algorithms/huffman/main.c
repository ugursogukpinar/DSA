/*
 
    Uğur Soğukpınar
    12011029 
 
    Huffman kodlamasının C dilinde implementasyonu.
 
    İşletim Sistemi : MacOSx 10.10.2 Yosemite
    İşlemci : Intel i5 4xxx serisi
    Derleyici : Apple LLVM version 6.0
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <math.h>

#define MAXINDEX 256 // Ascii tablosuna göre en büyük karakterin indisi değeri 255 olur.
#define DEBUG 1


// Bir karakterin huffman kodunu ve kendisini tutar.
typedef struct HASH{
    char *code;
    char letter;
}HASH;


/*
    Huffman ağacını huffman.txt ' dosyasından okur ve kod tablosunu oluşturur.
 
    @params
        Integer pointer [hashTableLength] , Oluşturulan hash tablosunun uzunluğu bu değişkende belirir.
        Char pointer [huffmanTree] , Dosyadan okunan huffman ikili ağacını tutar.
        Int [huffmanTreeLength] , Huffman ikili ağacının uzunluğunu tutar.
    @return
        HASH **[hashTable]
 */
HASH **createHashTable(int *,char *, int);


/*
    Encode edilmesi istenen dosyadaki karakterlerin frekansını ölçer.
    @params
        Integer pointer[counterList] , karakterlerin frekansı burada saklanır. Dizinin indisi karakterin ascii kodunu verir.
        Const char pointer[filename] , kaynak dosyanın adını tutar.
 
    @return
        Integer[totalCharacterCount] , okunan toplam karakter sayısını döndürür.
 */
int calculateFrequency(int *,const char *);


/*
    huffman.txt dosyasından huffman ikili ağacını okur
 
    @params 
        Integer pointer[huffmanTreeLength] , huffman ikili ağacının uzunluğunu tutar.
 
    @return 
        Char pointer[huffmanTree], dosyadan okunan huffman ikili ağacını döndürür.
 */
char *readHuffmanTree(int *);

/*
    Oluşturulan kod tablosuyla kaynak dosyayı encode eder.
 
    @params
        const char pointer [srcFile] , kaynak kodunun adını tutar.
        const char pointer [destFile] , encode işlemi sonunda oluşturulacak dosyanın ismini tutar.
        HASH double pointer [hashTable] , kod tablosunu tutar.
        integer [hashTableLength] , kod tablosunun uzunluğunu tutar.
 
    @return
        integer [encodedBitCount] , encode edilen toplam bit sayısını döndürür.
 */
int encodeFile(const char *, const char *, HASH **, int);


/*
    Daha önceden encode edilmiş dosyayı decode eder.
    @params
        const char pointer [srcFile] , encode edilmiş dosyanın adını tutar.
        const char pointer [destFile] , decode işlemi sonunda oluşacak dosyanın adını tutar.
        HASH double pointer [hashTable] , kod tablosunu tutar.
        integer [hashTableLength] , kod tablosunun uzunluğunu tutar.
        integer [encodedBitCount], encode işlemi yapılırken kaç bitin encode edildiğini tutar.
 
    @return void
 
 */
void decodeFile(const char *, const char *, HASH **, int,int);


int main(int argc,char **argv) {
    
    int selection; // Komut satırı argümanlarını kontrol etmek için kullanılır.
    char *filename = NULL; // Kaynak dosya olarak verilen dosya isimlerini tutar.
    char *target = NULL; // Hedef olarak verilen dosya isimlerini tutar.
    int posibiltyFlag = 0; // Frekans hesaplaması yapılacağında bu bayrak 1 değerini alır.
    int encodingFlag = 0; // Encode işlemi yapılacağında bu bayrak 1 değerini alır.
    int decodingFlag = 0; // Decode işlemi yapılacağında bu bayrak 1 değerini laır.
    int counterList[MAXINDEX]; // ASCII tablosu indis olarak kabul edilirse kaynak dosyadaki tüm karakterlerin kaç defa tekrarlandığını tutar.
    int totalCharacterCount = 0; // Kaynak dosyadaki toplam karakter sayısını tutar.
    HASH **hashTable; // Kod tablosunun tutar.
    int hashTableLength = 0; // Kod tablosunun uzunluğunu tutar.
    char *huffmanTree= NULL; // huffman.txt 'den okunan huffman ikili ağacının tutar.
    int huffmanTreeLength = 0; // huffman.txt 'den okunan huffman ikili ağacının uzunluğunu tutar.
    int encodedBitCount = 0; // Encode işlemi sırasında kaç bitin encode edildiğini tutar.
    
    for(register int i=0; i<MAXINDEX; i++)
    {
        counterList[i] = 0;
    }
    
    opterr = 0;
    
    while( (selection = getopt(argc, argv, "pef:t:d:")) != -1 )
    {
        
        switch (selection) {
            case 'f':
                filename = optarg;
                break;
            case 'p':
                posibiltyFlag = 1;
                break;
            case 'e':
                encodingFlag = 1;
                break;
            case 't':
                target = optarg;
                break;
            case 'd':
                encodedBitCount = atoi(optarg);
                printf("\n%d\n",encodedBitCount);
                decodingFlag = 1;
                break;
            default:
                printf("Eksik veya hatalı bir argüman girildi!");
                exit(EXIT_FAILURE);
        }
    }
    
    
    // Yapılacak her işlem için kaynak dosyaya ihtiyaç vardır.
    if(!filename)
    {
        printf("You have to enter a filename. Ex -f filename.txt");
        exit(EXIT_FAILURE);
    }
    
    // Yapılacak her işlem için hedef dosyaya ihtiyaç vardır.
    if(!target)
    {
        printf("You have to enter a target filename. Ex -t target.txt");
        exit(EXIT_FAILURE);
    }
    
    if(posibiltyFlag)
    {
        totalCharacterCount = calculateFrequency(counterList,filename);
     
        FILE *frequencyFp = fopen(target,"w");
        
        for(register int i=0; i<MAXINDEX; i++)
        {
            if(counterList[i]){
                #if DEBUG == 1
                printf("\n %c -> %.2lf\n",i, (double)counterList[i]/ totalCharacterCount );
                fprintf(frequencyFp, "\n %c -> %.2lf",i, (double)counterList[i]/ totalCharacterCount);
                #endif
            }

        }
        
        fclose(frequencyFp);
    }
    
    
    if(encodingFlag)
    {
        huffmanTree = readHuffmanTree(&huffmanTreeLength);
        hashTable = createHashTable(&hashTableLength, huffmanTree, huffmanTreeLength);

        
        #if DEBUG == 1
        printf("\n---------------Hash Tablosu-------------------\n");
        
        for(register int i=0; i<hashTableLength;i++)
        {
            printf("\nKarakter: %c\t\tKod: %s\n", hashTable[i]->letter, hashTable[i]->code);
        }
        
        printf("\n---------------Hash Tablosu-------------------\n");

        #endif
        
        encodedBitCount = encodeFile(filename, target, hashTable, hashTableLength);
        
        #if DEBUG == 1
        printf("\n\n");
        printf("\t\t Şifrelenen bit sayısı : %d", encodedBitCount);
        printf("\n\n");
        #endif
    }
    
    if(decodingFlag)
    {
        huffmanTree = readHuffmanTree(&huffmanTreeLength);
        hashTable = createHashTable(&hashTableLength, huffmanTree, huffmanTreeLength);
        
        #if DEBUG == 1
        printf("\n---------------Hash Tablosu-------------------\n");
        
        for(register int i=0; i<hashTableLength;i++)
        {
            printf("\nKarakter: %c\t\tKod: %s\n", hashTable[i]->letter, hashTable[i]->code);
        }
        
        printf("\n---------------Hash Tablosu-------------------\n");
        
        #endif
        decodeFile(filename, target, hashTable, hashTableLength,encodedBitCount);
    }
    
    
    return EXIT_SUCCESS;
}




int calculateFrequency(int *counterList,const char *filename)
{
    
    FILE *fp = fopen(filename, "r");
    
    char tmpChar;
    int totalCharacterCount = 0;
    
    
    do
    {
        tmpChar = fgetc(fp);
        
        
        if(tmpChar != EOF)
        {
            counterList[tmpChar]++;
            totalCharacterCount++;
        }
        
    }while(tmpChar != EOF);
    
    fclose(fp);
    
    return totalCharacterCount;
}


HASH **createHashTable(int *hashTableLength, char *huffmanTree, int huffmanTreeLength)
{
    
    (*hashTableLength) = 0;
    
    HASH **hashTable = (HASH **) malloc(sizeof(HASH *) * (*hashTableLength));
    
    int nodeIndex; // Kodun ağaçtaki indisini tutar.
    int codeLength; // Oluşacak kodun uzunluğunu tutar.
    for (register int i=0; i < huffmanTreeLength; i++) {

        if(huffmanTree[i])
        {
            
            HASH *new_hash = (HASH *) malloc(sizeof(HASH));
            
            if(!new_hash)
            {
                printf("Kod tablosu oluşturulurken hata!");
                exit(EXIT_FAILURE);
            }

            
            new_hash->letter = huffmanTree[i];
            nodeIndex = i;
            
            // Oluşacak kodun uzunluğu log2 ile hesaplanabilir.
            // 1 Ekleme işlemi kodun sonuna NULL karakteri koyulabilmesi içindir.
            codeLength = (int)log2(nodeIndex + 1) + 1;
            
            new_hash->code = (char *) malloc(sizeof(char) * codeLength);
            
            if(!new_hash->code)
            {
                printf("Kod tablosu oluşturulurken hata!");
                exit(EXIT_FAILURE);
            }
            
            
            new_hash->code[--codeLength] = '\0';
            
            do
            {
                if(nodeIndex % 2 == 1)
                {
                    // Tek indexli düğümler sol tarafta bulunur. Bu nedenle 0 kodu verilir.
                    new_hash->code[--codeLength] = '0';
                    
                } else
                {
                    // Çift idnexli düğümler ise sağ tarafta bulunur. Bu nedenle 1 kodu verilir.
                    new_hash->code[--codeLength] = '1';
                }
                
                nodeIndex = (nodeIndex - 1) / 2;

                
            }while( nodeIndex > 0);
            
            // Oluşan yeni kodu kod tablosuna ekleyelim.
            hashTable = (HASH **) realloc(hashTable, sizeof(HASH *) * ++(*hashTableLength));
            
            hashTable[ (*hashTableLength) -1 ] = new_hash;
           
        }
    }
    
    
    return hashTable;
}


char *readHuffmanTree(int *huffmanTreeLength)
{

    char *huffmanTreeFilename = "huffman.txt"; // Bu parametrik yapılabilirdi aslında.
    char *huffmanTree; // Huffman ağacı bu değişkende oluşacak.
    char *tmpCharPointer = NULL; // Bellek genişletme işlemlerinde ara değişken olarak kullanılır.
    FILE *fp;
    char tmpStr[3]; // Dosyadan okunan ikili ağacın her bir satırı en fazla 2 karakterden oluşabilir.

    fp = fopen(huffmanTreeFilename, "r");
    (*huffmanTreeLength) = 0;
    
    
    huffmanTree = (char *) malloc(sizeof(char) * (*huffmanTreeLength));
    if(huffmanTree && fp)
    {
        while(!feof(fp))
        {
            
            tmpCharPointer = (char *) realloc(huffmanTree, sizeof(char) * ((*huffmanTreeLength) + 1));
            
            if(tmpCharPointer)
            {
                fscanf(fp, "%s\n", tmpStr);
                
                // Dosyadan okunan ilk iki karakter '\0' ise bu null demektir.
                if(tmpStr[0] != '\\' && tmpStr[1] != '0')
                {
                    huffmanTree[ (*huffmanTreeLength)++ ] = tmpStr[0];
                }else
                {
                    huffmanTree[ (*huffmanTreeLength)++ ] = '\0';
                }
            } else
            {
                printf("Huffman ağacı yer düzenleme hatası!");
                exit(EXIT_FAILURE);
            }
            
        }
        
    }else
    {
        printf("\nHuffman ağacı için yer ayrılamadı veya dosya okunamadı!\n");
        exit(EXIT_FAILURE);
    }
    
    fclose(fp);

    return huffmanTree;
}


int encodeFile(const char *srcFile, const char *destFile, HASH **hashTable, int hashTableLength)
{
    
    FILE *src = fopen(srcFile, "r"); // Encode edilecek dosyanın adı
    FILE *dst = fopen(destFile, "wb"); // Encode işlemi sonunda oluşacak dosyanın adı
    char tmpChar; // Dosyadan okunacak her karakter bu değişkene işlenecek.
    int hashTableIndex; // Hashtablosunda kod aranırken kullanılacak.
    char bitBuffer = 0; // Karakterin kodu bulunduğunda kod büyüklüğü 8 bit olana kadar bu buffer'a yazılır.
    int codeIndex; // Kod tablosundan kod bulunduğunda, kod teker teker bitBuffer'a yazılacak. Bu sırada değişkenin değeri tutulur.
    int bitBufferCounter = 0; // bit buffer 'a her bit eklendiğinde bu değer artacak. Her 8 bitte bir dosyaya yazma işlemi yapılacak.
    int encodedBitCounter; // encode edilen toplam bit sayısını tutar.
    
    if(!src || !dst)
    {
        printf("Kaynak ve hedef dosyaya erişilemiyor!");
        exit(EXIT_FAILURE);
    }
    
    while(!feof(src))
    {
        tmpChar = fgetc(src);
        hashTableIndex = 0;
        codeIndex = 0;
        
        
        while(hashTableIndex < hashTableLength && hashTable[hashTableIndex]->letter != tmpChar)
        {
            hashTableIndex++;
        }
        
        if(hashTableIndex < hashTableLength)
        {
            tmpChar = hashTable[hashTableIndex]->code[codeIndex];

            while(tmpChar!= '\0'){

                bitBuffer <<= 1; // bitBuffer 1 bit sola kaydırılır.
                    
                if(tmpChar == '0')
                {
                    // Eğer okunan kod '0' ise bitBuffer'ın son bitine 0 yazılmalı.
                    bitBuffer |= 0x0;
                } else if(tmpChar == '1')
                {
                    // Eğer okunan kod '1' ise bitBuffer'ın son bitine 1 yazılmalı.
                    bitBuffer |= 0x1;
                }
                
                
                codeIndex++;
                bitBufferCounter++;
                if(bitBufferCounter % 8 == 0) // bitBuffer 8 olduğunda dosyaya 1byte'lık yazma işlemi yapılacak.
                {
                    fwrite (&bitBuffer, 1, 1, dst);
                    
                    bitBuffer = 0; // bitBuffer 'ın tüm bitleri 0 yapılmalı.
                }

                tmpChar = hashTable[hashTableIndex]->code[codeIndex];    
            }
            
        }
        
    }
    
    
    encodedBitCounter = bitBufferCounter;
    
    // Eğer encode edilen bit sayısı 8 in katları değilse ,8 in katı olana kadar bitBuffer'ın sonuna 0 eklenecek.
    // Burdan sonraki bitler doldurma işlemi için olduğundan encode edilmiş bit sayısını önce saklıyoruz.
    if(bitBufferCounter % 8 != 0)
    {
        while(bitBufferCounter % 8 != 0)
        {
            bitBufferCounter++;
            bitBuffer <<= 1;
            bitBuffer |= (0x0);
        }
        
        fwrite (&bitBuffer, 1, 1, dst);
    }

    fclose(dst);
    fclose(src);
    
    return encodedBitCounter;
}


void decodeFile(const char *srcFile, const char *destFile, HASH **hashTable, int hashTableLength, int encodedBitCount)
{
    FILE *src = fopen(srcFile, "rb"); // Encode edilmiş dosyanın ismi
    FILE *dst = fopen(destFile, "w"); // Decode işleminden sonra oluşacak dosyanın ismi
    
    int hashTableIndex; // Kod tablosunda arama yapılacağı sırada kullanılacak.
    char bitBuffer = 0; // Dosyadan her bir hamlede 1 byte okuma yapacağız.
    int bitBufferCounter = 0; // Her okuma işleminde okunan bit sayısı (8 bit) bu değişkene yazılır.
    int totalBitCounter = 0; // Decode edilen toplam bit sayısını tutar.
    
    char *codeStr = (char *) malloc(sizeof(char)); // Dosyadan okunan her bit bu buffera karakter olarak yazdırılacak.
    int codeLength; // codeStr bufferına yazılan karakterlerin sayısını tutar.
    char tmpChar; // codeStr 'de oluşan bir kod , kod tablosunda karşılığını bulursa, karakter olarak bu değişkene işlenecek.
    
    if(!src || !dst)
    {
        printf("Kaynak ve hedef dosyaya erişilemiyor!");
        exit(EXIT_FAILURE);
    }
    
    
    printf("\n--------------DECODED------------------\n");
    codeLength = 1; // Kod uzunluğumuzu 1 den başlatıyoruz, çünkü codeStr'nin sonuna her zaman NULL karakteri koyacağız.
    while(!feof(src) && totalBitCounter < encodedBitCount)
    {
        fread(&bitBuffer, 1, 1, src); // Her işlemde 1 byte okuyoruz.
        bitBufferCounter = 8; // 1 byte okuma sonucunda bitBuffer'da 8 bitlik değer  bulunuyor.
        
        while(bitBufferCounter > 0 && totalBitCounter < encodedBitCount)
        {
            bitBufferCounter--;
            totalBitCounter++;
            codeStr = (char * ) realloc(codeStr, ++codeLength);
            
            if(!codeStr)
            {
                printf("Kod çözme sırasında hata oluştu!");
                exit(EXIT_FAILURE);
            }
            
            
            // bitBuffer en enlamlı bitin değerini kontrol ediyoruz.
            if(0x80 & bitBuffer)
            {
                // En anlamlı bit 1 ise codeStr'ye '1' karakterini ekleyelim.
                codeStr[codeLength - 2] = '1';
            } else
                
            {
                // En anlamlı bit 0 ise codeStr'ye '0' karakterini eklersin.
                codeStr[codeLength - 2] = '0';
            }
            
            bitBuffer <<= 1;
            codeStr[codeLength - 1] = '\0';
            
            // Hash tablosunda kodu arayalım.
            hashTableIndex = 0;
            while(hashTableIndex < hashTableLength && strcmp(hashTable[hashTableIndex]->code, codeStr))
            {
                hashTableIndex++;
            }
            
            // Kod bulunmuş ise gerekli harfi yazdıralım.
            if(hashTableIndex < hashTableLength)
            {
                tmpChar = hashTable[hashTableIndex]->letter;
                printf("%c", tmpChar);
                fputc(tmpChar, dst);
                memset(codeStr, '\0', codeLength);
                codeLength = 1;
            }
            
            
        }
    }
    printf("\n--------------DECODED------------------\n");
    fclose(src);
    
}







