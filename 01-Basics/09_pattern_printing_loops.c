#include <stdio.h>

int main()
{
    int i, j;

    // Dış Döngü: Satırları kontrol eder (i=1'den 12'ye). 
    // NOT: İç döngüler tamamen bitmeden i++ ÇALIŞMAZ!
    for (i = 1; i <= 11; i++)
    {
        // 1. İç Döngü: (12 - i) adet 'x' basar. 
        // Her x basımından sonra j++ çalışır; bittiğinde j sıfırlanacaktır.
        for (j = 1; j <= 12 - i; j++)
        {
            printf("x");
        }
        printf("\n");

        // 2. İç Döngü: (i) adet '0' basar. 
        // j yeniden 1 yapılır ve i değerine ulaşana kadar j++ ile ilerler.
        for (j = 1; j <= i; j++)
        {
            printf("0");
        }
        printf("\n");
        
        // --- İki iç döngü de kapandı; şimdi dış döngünün i++ işlemi gerçekleşecek! ---
    }

    return 0;
}