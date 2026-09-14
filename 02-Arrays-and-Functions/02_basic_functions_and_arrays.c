#include <stdio.h>
#include <stdlib.h>

/* Fonksiyon Prototipleri */
void printNumbers(const int arr[], int size);
int showMe(int x);

int main(void)
{
    int myNumbers[] = {1, 2, 3, 4, 5, 6};
    
    // Eleman sayısını dinamik hesaplama standardı:
    //sizeof(myNumbers) (Toplam Boyut): Belleğe gider ve tüm dizinin kapladığı alanı ölçer. 6 adet int yan yana durduğu için: 6 * sizeof(int) = 6 * 4 = 24 byte
    //sizeof(myNumbers[0]) (Tek Eleman Boyutu): Dizinin ilk elemanının boyutunu ölçer. 1 adet int için: sizeof(int) = 4 byte
    int size = sizeof(myNumbers) / sizeof(myNumbers[0]);

    // Fonksiyona hem dizinin başlangıç adresini hem de boyutunu teslim ediyoruz:
    printNumbers(myNumbers, size);

    printf("Sonuc: %d\n", showMe(10));

    return EXIT_SUCCESS;
}

/* const: Dizi elemanlarının yanlışlıkla değiştirilmesini engeller.
 * size: Döngünün dizi dışına taşıp çöp değer okumasını (Buffer Overflow) önler. */
void printNumbers(const int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("Index [%d] = %d\n", i, arr[i]);
    }
}

int showMe(int x)
{
    return 5 + x;
}