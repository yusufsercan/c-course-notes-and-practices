#include <stdio.h>
#include <stdlib.h> // rand(), srand(), EXIT_SUCCESS için
#include <time.h>   // time() fonksiyonu için zorunludur

//  Oyuncu doğru sayıyı bulana kadar tahmin yapabilir ve her yanlış tahminde puanı düşer. Oyuncu istediği zaman -1 yazarak oyundan çıkabilir.

/*
* 1. PRNG (PSEUDO-RANDOM NUMBER GENERATOR) VE DETERMINIZM:
 *    - Bilgisayarlar gerçek anlamda rastgele sayı üretemez; deterministik matematiksel
 *      formüller (genellikle Linear Congruential Generator) kullanırlar.
 *    - 'rand()' fonksiyonu (<stdlib.h>) her çağrıldığında bu matematiksel zincirden
 *      bir sonraki sayıyı çeker (0 ile RAND_MAX arasında, RAND_MAX en az 32767'dir).
 *    - KRİTİK KURAL: Eğer bir tohum (seed) belirlemezsen, 'rand()' her program
 *      başlatıldığında varsayılan tohumu (1) kullanır ve HER SEFERİNDE TAMAMEN AYNI
 *      sayı dizisini üretir!
 *
 * 2. TOHUMLAMA (SEEDING) MEKANİZMASI: 'srand()' VE 'time(NULL)':
 *    - 'srand(seed)' fonksiyonu (<stdlib.h>), rastgele sayı üretecinin başlangıç
 *      noktasını ayarlar.
 *    - 'time(NULL)' fonksiyonu (<time.h>), 1 Ocak 1970'ten (Unix Epoch) bu yana geçen
 *      toplam saniyeyi döndürür. Zaman sürekli aktığı için her çalıştırmada farklı
 *      bir tohum elde edilir.
 *    - USTA KURALI: 'srand()' program boyunca SADECE BİR KEZ (tercihen 'main' girişinde)
 *      çağrılır. Döngü içine yazılırsa aynı saniye içinde aynı sayılar üretilir.
 *
 * 3. ARALIK SINIRLANDIRMA MATEMATİĞİ (MODULO ARİTMETİĞİ):
 *    - 'rand() % N' ifadesi [0, N - 1] aralığında kalan üretir.
 *    - [min, max] kapalı aralığında rastgele sayı üretmenin genel mühendislik formülü:
 *        sayi = min + (rand() % (max - min + 1));
 *        Örnek [1, 100]: 1 + (rand() % (100 - 1 + 1))  =>  (rand() % 100) + 1
 *
 * 4. STACK SEGMENTİ VE ÇÖP DEĞER (GARBAGE VALUE) RİSKİ:
 *    - Fonksiyon içinde tanımlanan yerel değişkenler (örn: 'int guessCount;') belleğin
 *      Stack segmentinde açılır.
 *    - C derleyicisi bu değişkenlerin içini otomatik olarak sıfırlamaz! O bellek
 *      adresinde daha önceden kalmış rastgele bitler (çöp değer) neyse o kalır.
 *    - Başlangıç değeri atanmadan ('= 0') yapılan artırma ('guessCount++') tanımsız
 *      davranıştır (Undefined Behavior) ve programı bozar.
 *
 * 5. GİRDİ TAMPONU (INPUT BUFFER / stdin) VE 'getchar()' SÜPÜRGESİ:
 *    - Kullanıcı klavyeden bir metin girip Enter'a bastığında veriler önce 'stdin'
 *      tamponuna (yürüyen banda) yazılır.
 *    - 'scanf("%d", ...)' bir sayı beklerken harf ('abc\n') gelirse okuyamaz, '0'
 *      döner ve o harfleri TAMPONDA BIRAKIR.
 *    - Tampon temizlenmezse sonraki döngü turunda 'scanf' aynı harfleri tekrar okumaya
 *      çalışır ve program SONSUZ DÖNGÜYE (infinite loop) girer.
 *    - 'while (getchar() != '\n');' kalıbı, hatalı karakterleri Enter görene kadar
 *      tampondan tek tek çekip atarak bandı tertemiz yapar.
 * ==============================================================================
 */

int main(void)
{
    int randomNumber, guessNumber = 0;
    int guessCount = 0; // Stack'teki çöp değeri engellemek için MUTLAKA 0 atanmalı
    int score = 100; // Oyuncunun başlangıç puanı her yanlış tahminde 10 puan düşecek

    // Rastgele sayı üretecini o anki zamanla (seed) besliyoruz
    srand((unsigned int)time(NULL));// Bu sayede her çalıştırmada farklı bir sayı üretilir
    randomNumber = rand() % 100 + 1; // [1, 100] kapalı aralığında sayı üretir

    printf("=========================================\n");
    printf("1 ile 100 arasinda bir sayi tuttum!\n");
    printf("Cikmak icin istediginiz an -1 yazabilirsiniz.\n");
    printf("=========================================\n\n");

    while (1)
    {
        printf("Tahmininizi girin: ");
        if (scanf("%d", &guessNumber) != 1)
        {
            printf("Gecersiz girdi! Lutfen bir tam sayi girin.\n");
            while (getchar() != '\n'); // Tamponu (buffer) temizle
            continue;
        }

        if (guessNumber == -1)
        {
            printf("Oyundan cikiliyor...\n");
            break;
        }

        if (guessNumber < 1 || guessNumber > 100)
        {
            printf("Lutfen 1 ile 100 arasinda bir sayi girin.\n");
            continue;
        }

        guessCount++;

        if (guessNumber == randomNumber)
        {
            printf("\nTebrikler! %d. denemede bildiniz.\n", guessCount);
            break;
        }
        else if (guessNumber < randomNumber)
        {
            printf("Daha BUYUK bir sayi girin.\n");
        }
        else
        {
            printf("Daha KUCUK bir sayi girin.\n");
        }

        score -= 10;
        if (score < 0) score = 0; // Puanın eksiye inmesini engelliyoruz
    }

    printf("\nOyun Bitti! Dogru Sayi : %d\n", randomNumber);
    printf("Toplam Tahmin         : %d\n", guessCount);
    printf("Final Puaniniz        : %d\n", score);

    return EXIT_SUCCESS;
}
