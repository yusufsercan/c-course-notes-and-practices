#include <stdio.h>

int main()
 {
    int number, i, j, control;

    // 1. GİRDİ KONTROL DÖNGÜSÜ
    // Kullanıcı pozitif ve 1'den büyük sayı girene kadar buradan çıkamaz.
    while (1) 
    {
        printf("Enter a Number: ");
        scanf("%d", &number);

        if (number <= 1) 
        {
            printf("Please enter a positive number greater than 1\n\n");
            continue; // Artık bir while döngüsünün içinde olduğumuz için continue ÇALIŞIR!
        }
        
        // Geçerli bir sayı girildiyse döngüyü kırıp aşağı geçiyoruz
        break; 
    }

    // 2. ASAL SAYI HESAPLAMA DÖNGÜSÜ
    for (i = 2; i <= number; i++) 
    {
        control = 1;
        
        for (j = 2; j <= i / 2; j++) 
        {
            if (i % j == 0) {
                control = 0;
                break;
            }
        }

        if (control != 0) 
        {
            printf("%d ", i);
        }
    }

    printf("\n");
    return 0;
}