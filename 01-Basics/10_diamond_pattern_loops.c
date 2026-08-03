

 // * KONU        : Baklava Dilimi / Elmas (Diamond Pattern) Algoritması
 // * AÇIKLAMA    : İç içe döngüler kullanılarak karmaşık ve simetrik şekil oluşturma.
 //NOT: mantığı anlamak için önce üst kısmı, sonra alt kısmı ayrı ayrı düşünmek gerekir.



#include <stdio.h>

int main()
{
    int i, j, N;

    printf("Bir sayi giriniz (N): ");
    scanf("%d", &N);

    // --- 1. ÜST KISIM (Genişleyen Piramit) ---
    for (i = 1; i <= N; i++)
    {
        // Boşlukları basar (N - i adet)
        for (j = 1; j <= N - i; j++)
        {
            printf(" ");
        }

        // Yıldızları basar (i adet)
        for (j = 1; j <= i; j++)
        {
            printf(" *");
        }

        printf("\n"); 
    }

    // --- 2. ALT KISIM (Daralan Piramit) ---
    for (i = N - 1; i >= 1; i--)
    {
        // Boşlukları basar (N - i adet)
        for (j = 1; j <= N - i; j++)
        {
            printf(" ");
        }

        // Yıldızları basar (i adet)
        for (j = 1; j <= i; j++)
        {
            printf(" *");
        }

        printf("\n"); 
    }

    return 0;
}