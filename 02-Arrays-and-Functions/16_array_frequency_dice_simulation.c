/* ==============================================================================
 * 16_array_frequency_dice_simulation.c
 * Frekans Dizisi (Histogram) Mantigi ve Rastgele Zar Simulasyonu
 * ==============================================================================
 * 
 * 1. MANTIK (FREQUENCY / COUNTER ARRAY):
 *    - Bir olayin kac kez gerceklestigini saymak icin ayri ayri degiskenler
 *      (zar1, zar2, zar3...) tanimlamak yerine, sonuclari indeks olarak kullaniriz.
 *    - 'howMany[dice]++' satiri: Zar ne geldiyse, dogrudan o numarali kutucugun
 *      sayacini 1 artirir. Tek satirda O(1) maliyetle sayim yapilir.
 *
 * 2. KRITIK MUHENDISLIK NOTLARI:
 *    A) Sayac Dizileri MUTLAKA '{0}' ile baslatilmalidir. Aksi halde cop degerler
 *       artirilarak hatali sonuclar uretilir. = örnek olarak howMany[7] = {0};
 *    B) Zarlar 1-6 arasinda oldugu icin 7 elemanli dizi acilmistir. 0. indeks
 *       kullanilmaz; boylece 'zar - 1' ofset hesaplamasi yapilmadan zar yuzuyle
 *       indeks birebir eslestirilir.
 *    C) 'time(NULL)' fonksiyonu icin '<time.h>' eklenmesi zorunludur.
 * ==============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ATIS_SAYISI 6000 // Buyuk Sayilar Yasasi geregi sayi arttikca dagilim esitlenir

int main(void)
{
    // 7 elemanli sifirlanmis dizi (0. indeks bosta, 1-6 arasi zarlar icin)
    int howMany[7] = {0};
    int dice;

    // Rastgele sayi uretecini sistem saatine gore besliyoruz
    srand((unsigned int)time(NULL));//  srand() fonksiyonu ise rastgele sayı üreteciyi başlatmak için kullanılır. time(NULL) fonksiyonu, sistem saatini saniye cinsinden döndürür ve bu değeri unsigned int türüne dönüştürerek srand() fonksiyonuna geçiririz. Bu sayede her program çalıştırıldığında farklı bir başlangıç noktası ile rastgele sayılar üretilir.

    // Zarlari at ve frekans dizisine isle
    for (int i = 0; i < ATIS_SAYISI; i++)
    {
        dice = rand() % 6 + 1; // 1 ile 6 arasi rastgele zar
        howMany[dice]++;       // örnek olay: zar 4 gelirse howMany[4] sayaci 1 artar yani 4. indeksin sayaci 1 artar. Bu sayede her zar atışında hangi yüzün kaç kez geldiğini sayabiliriz.
    }

    printf("=== ZAR ATIS FREKANS ANALIZI (%d Atis) ===\n\n", ATIS_SAYISI);
    printf("Zar Yuzu | Gelme Sayisi | Yuzdelik Oran\n");
    printf("---------+--------------+--------------\n");

    // 1'den 6'ya kadar olan sonuclari ekrana yazdir
    for (int yuz = 1; yuz <= 6; yuz++)
    {
        float yuzde = ((float)howMany[yuz] / ATIS_SAYISI) * 100.0f;
        printf("   [%d]   |    %5d     |   %%%5.2f\n", yuz, howMany[yuz], yuzde);// howMany dizisinin her bir indeksinde kaç kez zarın o yüzü geldiğini sayıyoruz. yuz değişkeni 1'den 6'ya kadar döner ve her bir yüz için howMany dizisindeki sayacı alırız. Yüzdelik oranı hesaplamak için, o yüzün gelme sayısını toplam atış sayısına bölüp 100 ile çarparız. Son olarak, printf ile zar yüzü, gelme sayısı ve yüzdelik oranı ekrana yazdırırız.
    }

    return EXIT_SUCCESS;
}