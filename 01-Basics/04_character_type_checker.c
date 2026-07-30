#include <stdio.h>

/*
 * Task: Continuously check if an input character is an uppercase letter, lowercase letter, or non-alphabetic.
 * Concepts: ASCII comparison, while loop, user exit control, scanf buffer handling (" %c").
 */

int main() 
{
    char myCharacter;

    printf("=== Character Type Checker ===\n");
    printf("Enter 'q' or 'Q' to quit the program.\n\n");

    while (1) // Sonsuz döngü (Kullanıcı çıkış yapana kadar çalışır)
    {
        printf("Enter a character: ");
        // %c öncesindeki boşluk, hafızada kalan ENTER (\n) karakterini temizler
        scanf(" %c", &myCharacter);

        // Çıkış kontrolü (Exit condition)
        if (myCharacter == 'q' || myCharacter == 'Q') 
        {
            printf("Exiting program... Goodbye!\n");
            break; // Döngüyü sonlandırır
        }

        // Büyük harf kontrolü (ASCII 65 - 90 arası)
        if (myCharacter >= 'A' && myCharacter <= 'Z') 
        {
            printf("-> '%c' is an UPPERCASE letter.\n\n", myCharacter);
        }
        // Küçük harf kontrolü (ASCII 97 - 122 arası)
        else if (myCharacter >= 'a' && myCharacter <= 'z') 
        {
            printf("-> '%c' is a LOWERCASE letter.\n\n", myCharacter);
        }
        // Harf dışı karakter kontrolü (Rakam, sembol vb.)
        else 
        {
            printf("-> '%c' is NOT a letter.\n\n", myCharacter);
        }
    }

    return 0;
}