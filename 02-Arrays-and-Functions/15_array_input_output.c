#include <stdio.h>
#include <stdlib.h>
#include <math.h> 
/*
 * 1. TEMEL AMAC VE MANTIK:
 *    - Bir dizinin bellekteki herhangi bir hucresine dogrudan eriserek (Random Access)
 *      kullanici kontrolunde veri yazma ('Write') ve veri okuma ('Read') operasyonlarini
 *      guvenli bir kontrol mekanizmasiyla (Guard Clauses) gerceklestirmek.
 * 
 * 2. Sinir Denetimi (Bounds Checking) ve Siber Guvenlik:
 *       - C dilinde "dizi sinir kontrolu" derleyici tarafindan YAPILMAZ.
 *       - 10 elemanli bir dizinin meşru indeksleri yalnizca 0 ile 9 arasidir.
 *       - 'if (index < 0 || index >= BOYUT)' kontrolu manuel yazilmazsa, kullanici
 *         15. veya -2. indekse veri yazarak bellegi bozar (Buffer Overflow /
 *         Segmentation Fault). Kodun en kritik savunma hatti bu kontroldur.
*/

int main(void)
{
    double myValue,myArray[10]; // 10 elemanlı double tipinde bir dizi tanımladık
    int choice,index;
    do
    {
        printf("Make a choice (-1 to Exit):\n");
        printf("\t1. Write to array\n");
        printf("\t2. Read from array\n");
        scanf("%d",&choice);
        if(choice==-1)
        {
            break;
        }
        if(choice!=1 && choice!=2)
        {
            printf("Invalid choice! Please try again.\n");
            continue;
        }
        printf("Enter an index (0-9): ");
        scanf("%d",&index);
        if(index<0 || index>9)// burada kullanıcıdan alınan indeksin geçerli olup olmadığını kontrol ediyoruz. eğer indeks 0 ile 9 arasında değilse kullanıcıya uyarı mesajı veriyoruz ve döngüye devam ediyoruz.
        {
            printf("Invalid index! Please try again.\n");
            continue;
        }
        switch(choice)
        {
            case 1:
                printf("Enter a value to store at index %d: ",index); // mantığı şöyle: kullanıcıdan bir değer alıyoruz ve bu değeri dizinin belirli bir indeksine kaydediyoruz. scanf ile kullanıcıdan alınan değeri myValue değişkenine atıyoruz ve ardından bu değeri myArray dizisinin belirtilen indeksine atıyoruz. Son olarak, kullanıcıya hangi değerin hangi indekse kaydedildiğini bildiriyoruz.
                scanf("%lf",&myValue);
                myArray[index]=myValue; // burada da kullanıcıdan alınan değeri dizinin belirli bir indeksine kaydediyoruz. myArray[index] ifadesi, myArray dizisinin index numarasına karşılık gelen elemanını temsil eder ve bu elemanı myValue değişkeninin değeri ile güncelliyoruz.
                printf("Value %.2f stored at index %d.\n",myValue,index);
                break;
            case 2:
                printf("Value at index %d is %.2f\n",index,myArray[index]);
                break;
        }

    }
    while(choice!=-1); // kullanıcı -1 girene kadar döngü devam eder. bu sayede kullanıcı istediği kadar diziye değer yazabilir veya okuyabilir.
    

    return EXIT_SUCCESS;
}