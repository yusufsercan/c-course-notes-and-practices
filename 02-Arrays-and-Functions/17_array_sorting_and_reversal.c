/* ==============================================================================
 * Dizi Elemanlarini Kucukten Buyuge Siralama (Exchange Sort) ve Tersten Yazdirma
 * ==============================================================================
 * 
 * 1. ALGORITMA MANTIGI (EXCHANGE SORT - O(N^2)):
 *    - Ic ice iki dongu kullanilir.
 *    - Dis dongu (i) siralanacak konumu belirler (0'dan BOYUT-1'e).
 *    - Ic dongu (j = i + 1) i'den sonraki tum elemanlari tarar.
 *    - Eger 'arr[i] > arr[j]' ise iki deger gecici bir degisken (temp)
 *      yardimiyla takas edilir (swap).
 *
 * 2. MUHENDISLIK STANDARTLARI:
 *    - Global degisken yerine yerel (local) degiskenler ve fonksiyon parametreleri
 *      kullanilmistir.
 *    - Okuma amaciyla dizi alan fonksiyonlarda veri guvenligi icin 'const' kullanilir.
 * ==============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#define SIZE 7

/* Fonksiyon Prototipleri */
void sort_array(int arr[], int size);
void print_array(const int arr[], int size); // const kullanmamızın sebebi, fonksiyonun diziyi değiştirmeyeceğini garanti etmektir. Bu, veri güvenliği ve kodun anlaşılabilirliği açısından önemlidir.
void print_array_reverse(const int arr[], int size);

int main(void)
{
    int numbers[SIZE] = {0}; // 7 elemanlı bir tamsayı dizisi tanımlıyoruz ve tüm elemanlarını 0 ile başlatıyoruz. Bu, dizinin başlangıçta temiz bir durumda olmasını sağlar ve ileride kullanılacak değerlerin önceden belirlenmiş olmasını garanti eder.

    printf("Lutfen %d adet tamsayi girin:\n", SIZE);
    for (int i = 0; i < SIZE; i++)
    {
        printf("Eleman [%d]: ", i);
        scanf("%d", &numbers[i]);
    }   

    printf("\n--- Siralamadan Once ---\n");
    print_array(numbers, SIZE); // numbers ve SIZE parametrelerini print_array fonksiyonuna geçiriyoruz. numbers dizisinin elemanlarını ekrana yazdırmak için bu fonksiyonu kullanıyoruz. SIZE parametresi, dizinin boyutunu belirtir ve fonksiyonun kaç elemanı yazdıracağını bilmesini sağlar.

    // Diziyi kucukten buyuge sirala
    sort_array(numbers, SIZE);

    printf("\n--- Siralandiktan Sonra (Kucukten Buyuge) ---\n");
    print_array(numbers, SIZE);

    printf("\n--- Tersten Siralama (Buyukten Kucuge) ---\n");
    print_array_reverse(numbers, SIZE);

    return EXIT_SUCCESS;
}

/* Diziyi kucukten buyuge siralayan fonksiyon (Exchange Sort) */
void sort_array(int arr[], int size)
{
    int temp;
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (arr[i] > arr[j])
            {
                // Takas (Swap) operasyonu
                temp = arr[i]; // temp degiskeni ile gecici olarak arr[i] degerini sakla
                arr[i] = arr[j]; // arr[i] degerini arr[j] ile degistir
                arr[j] = temp; // arr[j] degerini temp ile degistir (eski arr[i] degeri)
            }
        }
    }
}

/* Diziyi bastan sona ekrana basan fonksiyon */
void print_array(const int arr[], int size) 
{
    for (int i = 0; i < size; i++) // yukarıdaki  print_array içindeki numbers ve SIZE parametrelerini kullanarak dizinin elemanlarını ekrana yazdırıyoruz. for döngüsü, dizinin tüm elemanlarını tek tek dolaşır ve her bir elemanı printf ile ekrana basar.
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

/* Diziyi sondan basa dogru ekrana basan fonksiyon */
void print_array_reverse(const int arr[], int size)
{
    for (int i = size - 1; i >= 0; i--)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}