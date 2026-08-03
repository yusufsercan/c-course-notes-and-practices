#include <string.h> // strcmp fonksiyonu için şart!
#include <stdio.h>



int main()

{

   const char SABIT_SIFRE[] = "Giris123";

    char cikis_kontrol;

    int sayi;

    while (1)

    {

        printf("--- GUVENLIK GIRIS SISTEMI ANA MENUSU---\n");

        printf("Programdan cikmak icin 'q' veya 'Q' tusuna basin, devam etmek icin herhangi bir tusa basin: ");

        scanf(" %c", &cikis_kontrol);



        if (cikis_kontrol == 'q'|| cikis_kontrol == 'Q')

        {

            printf("Cikis talimati alindi. Program kapatiliyor...\n");

            break;

        }

        int sayi_x, sayi_y;

        printf("\n[Asama 1: Matematiksel Dogrulama]\n");

        printf("Lutfen iki adet tam sayi girin (sayi_x ve sayi_y): \n");

        printf("sayi_x: ");

        scanf("%d", &sayi_x);

        printf("sayi_y: ");

        scanf("%d", &sayi_y);

        if ((sayi_x * sayi_y > 100) && (sayi_x + sayi_y < 50))

        {

            printf("\n>>> Matematiksel Dogrulama BASARILI! Sifre Kontrolune Geciliyor.\n");

            char girilen_sifre[20];

            int basarili_giris = 0;



            printf("\n[Asama 2: Sifre Kontrolu]\n");

            for (int deneme = 1; deneme <= 3; deneme++)

            {

                printf("Sifrenizi girin (Deneme %d/%d): ", deneme, 3);

                scanf("%s", girilen_sifre);

                if (strcmp(girilen_sifre, SABIT_SIFRE) == 0)

                {

                    printf("\n*** Giris Tamamlandi! Sisteme HOS GELDINIZ! ***\n");

                    basarili_giris = 1;

                    return 0;

                }

            else

                {

                    printf("Hatali sifre. Kalan deneme: %d\n", 3 - deneme);

                }

            }

            if (basarili_giris == 0)

            {

                printf("\n!!! Sifre deneme hakkiniz bitti. Program Kapatiliyor. !!!\n");

                return 0;

            }



        }

        else

        {

            printf("\n!!! Matematiksel Dogrulama HATALI. Ana menuye donuluyor. !!!\n");

        }

    }


    return 0;

}