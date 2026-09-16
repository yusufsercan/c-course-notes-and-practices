#include <stdio.h>
#include <stdlib.h>

// bu program, kullanıcıdan dört basamaklı bir sayı alır ve bu sayıyı Türkçe olarak ekrana yazdırır. Örneğin, kullanıcı 1234 girerse, program "Bin Iki Yuz Otuz Dort" çıktısını verir.

void BirlikCevir(int number);
void OnlukCevir(int number);

int main(void)
{
    int number = 0;
    int d1, d2, d3, d4; // d1: Birler, d2: Onlar, d3: Yüzler, d4: Binler

    while (1)
    {
        printf("\nEnter a four-digit number (or -1 to exit): ");
        if (scanf("%d", &number) != 1 || number == -1) // !=1 yazmamızın sebebi, kullanıcıdan alınan değerin bir sayı olup olmadığını kontrol etmektir. Eğer kullanıcı geçersiz bir giriş yaparsa, program hata mesajı verir ve döngüye devam eder.
        {
            break;
        }

        if (number < 1000 || number > 9999)// kullanıcıdan alınan sayının dört basamaklı olup olmadığını kontrol ediyoruz. Eğer sayı dört basamaklı değilse kullanıcıya uyarı mesajı veriyoruz ve döngüye devam ediyoruz.
        {
            printf("Please enter a valid 4-digit number!\n");
            continue;
        }

        // Basamak ayrıştırma matematiği
        d1 = number % 10;            // Birler
        d2 = (number % 100) / 10;    // Onlar
        d3 = (number % 1000) / 100;  // Yüzler
        d4 = number / 1000;          // Binler

        // Binler Basamağı: 1 ise sadece "Bin", büyükse "İki Bin" vb.
        if (d4 > 1)
        {
            BirlikCevir(d4);
        }
        printf(" Bin ");

        // Yüzler Basamağı: 0 ise geç, 1 ise sadece "Yüz", büyükse "Üç Yüz"
        if (d3 > 1)
        {
            BirlikCevir(d3);
        }
        if (d3 >= 1)
        {
            printf(" Yuz ");
        }

        // Onlar Basamağı: 0 ise sessiz kal
        if (d2 > 0)
        {
            OnlukCevir(d2);
            printf(" ");
        }

        // Birler Basamağı: 0 ise sessiz kal
        if (d1 > 0)
        {
            BirlikCevir(d1);
        }

        printf("\n");
    }

    return EXIT_SUCCESS;
}

void BirlikCevir(int number) // 1-9 arasındaki sayıları Türkçe olarak yazdırır
{
    switch (number)
    {
        case 1: printf("Bir"); break;
        case 2: printf("Iki"); break;
        case 3: printf("Uc"); break;
        case 4: printf("Dort"); break;
        case 5: printf("Bes"); break;
        case 6: printf("Alti"); break;
        case 7: printf("Yedi"); break;
        case 8: printf("Sekiz"); break;
        case 9: printf("Dokuz"); break;
        default: break; // 0 veya geçersiz durumda susar
    }
}

void OnlukCevir(int number)// 10-90 arasındaki sayıları Türkçe olarak yazdırır  
{
    switch (number)
    {
        case 1: printf("On"); break;
        case 2: printf("Yirmi"); break;
        case 3: printf("Otuz"); break;
        case 4: printf("Kirk"); break;
        case 5: printf("Elli"); break;
        case 6: printf("Altmis"); break;
        case 7: printf("Yetmis"); break;
        case 8: printf("Seksen"); break;
        case 9: printf("Doksan"); break;
        default: break;
    }
}







