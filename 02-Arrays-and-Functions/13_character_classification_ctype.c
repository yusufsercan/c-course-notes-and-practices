/* ==============================================================================
 * 13_character_classification_ctype.c
 * Karakter Tip Sorgulama ve Dönüştürme Araçları (<ctype.h>)
 * ==============================================================================
 * NE İŞE YARAR?
 * Bir karakterin rakam mı, harf mi, boşluk mu olduğunu tek tek ASCII kodlarıyla
 * (örn: 'c >= '0' && c <= '9'') uğraşmadan tek adımda denetler.
 *
 * EN ÇOK KULLANILAN 8 TEMEL ARAÇ:
 * 1. isdigit(c) : Rakam mı? ('0' - '9')
 * 2. isalpha(c) : Harf mi? ('a'-'z', 'A'-'Z')
 * 3. isalnum(c) : Harf VEYA Rakam mı?
 * 4. isupper(c) : Büyük harf mi?
 * 5. islower(c) : Küçük harf mi?
 * 6. ispunct(c) : Noktalama işareti veya sembol mü? (., !, ?, # vb.)
 * 7. isspace(c) : Boşluk mu? (' ', '\t', '\n')
 * 8. toupper(c) / tolower(c) : Harfi BÜYÜK / KÜÇÜK harfe dönüştürür.
 * ==============================================================================
 */

#include <stdio.h>
#include <ctype.h>

int main(void)
{
    char ch;

    printf("Herhangi bir karaktere basip Enter'a basin: ");
    /* "%c"nin basindaki bosluk, onceden kalan Enter karakterlerini atlar */
    scanf(" %c", &ch);

    printf("\n--- '%c' Karakterinin Analizi ---\n", ch);

    // 1. Rakam Kontrolü
    if (isdigit(ch))
    {
        printf("-> Bu bir RAKAMDIR.\n");
    }

    // 2. Harf Kontrolü ve Dönüştürme
    if (isalpha(ch))
    {
        printf("-> Bu bir HARFTIR.\n");

        if (isupper(ch))
        {
            printf("   (Buyuk harf. Kucuk hali: '%c')\n", tolower(ch));
        }
        else if (islower(ch))
        {
            printf("   (Kucuk harf. Buyuk hali: '%c')\n", toupper(ch));
        }
    }

    // 3. Noktalama / Sembol Kontrolü
    if (ispunct(ch))
    {
        printf("-> Bu bir NOKTALAMA ISARETI veya SEMBOLDUR.\n");
    }

    // 4. Boşluk Kontrolü
    if (isspace(ch))
    {
        printf("-> Bu bir BOSLUK karakteridir.\n");
    }

    return 0;
}