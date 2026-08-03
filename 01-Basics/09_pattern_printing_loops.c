/* =====================================================================================
                    C DİLİNDE İÇ İÇE DÖNGÜ VE DEĞİŞKEN MANTIĞI
=====================================================================================

📌 TEMEL İLKELER:
 1. İçerideki iki döngü de işini TAMAMEN BİTİRMEDEN dış döngünün `i++` işlemi ÇALIŞMAZ.
 2. İç döngülerdeki `j++`, sadece o iç döngünün gövdesi çalıştıkça (her x veya 0 basımında) artar.
 3. Her yeni iç döngüye girildiğinde `j` değişkeni SIFIRLANIP tekrar 1 yapılır.

1. DIŞ DÖNGÜ (i) VE 'i' DEĞİŞKENİ:
   - Dış döngü ana patron/yöneticidir.
   - 'i = 1' ifadesi SADECE DÖNGÜYE İLK GİRİŞTE 1 kere çalışır.
   - 'i' değişkeni sıfırlanmaz; her ana adımın sonunda kalıcı olarak 'i++' ile artar.
   - Kitabın SAYFA NUMARASI gibidir; hep ileri gider (1, 2, 3...).

2. İÇ DÖNGÜLER (j) VE 'j' DEĞİŞKENİ:
   - İç döngüler alt işçilerdir.
   - Dış döngü her yeni tura geçtiğinde, kod yukarıdan aşağıya akarken içteki 'for' 
     satırıyla SANKİ İLK DEFA KARŞILAŞIYORMUŞ gibi sıfırdan başlar.
   - 'j = 1' komutu gereği 'j' her yeni adımda MECBUREN YENİDEN 1 Yapılır (sıfırlanır).
   - Sayfadaki KELİMELERİ OKUYAN PARMAK gibidir; yeni sayfaya ('i') geçince parmak 
     mecburen ilk kelimeye ('j=1') geri döner.

3. ARTIŞ (i++ ve j++) ZAMANLAMASI:
   - j++ : İç döngü gövdesindeki eylem (printf) her çalıştığında anında artar.
   - i++ : İçerideki TÜM İÇ DÖNGÜLER İŞİNİ TAMAMEN BİTİRİP kapandıktan sonra 
           en dıştaki süslü paranteze (}) gelindiğinde 1 kere artar.

===================================================================================== */

#include <stdio.h>

int main()
{
    int i, j;

    // Dış Döngü: Satırları kontrol eder (i=1'den 11'e). 
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


















