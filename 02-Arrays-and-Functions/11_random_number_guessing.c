#include <stdio.h>
#include <stdlib.h> // rand(), srand(), EXIT_SUCCESS için
#include <time.h>   // time() fonksiyonu için zorunludur

//  Oyuncu doğru sayıyı bulana kadar tahmin yapabilir ve her yanlış tahminde puanı düşer. Oyuncu istediği zaman -1 yazarak oyundan çıkabilir.

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