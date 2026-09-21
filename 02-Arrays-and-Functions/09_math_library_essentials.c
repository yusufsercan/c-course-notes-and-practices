#include <stdio.h>
#include <stdlib.h>
#include <math.h> // math.h kütüphanesi, matematiksel fonksiyonları kullanmamıza olanak sağlar.

/* ==============================================================================
 * 08_math_library_essentials.c
 * Standart C Matematik Kütüphanesi (<math.h>) Çekirdek Mekanizmaları
 * ==============================================================================
 * KRİTİK MÜHENDİSLİK NOTLARI:
 * 1. TİP DİSİPLİNİ:
 *    - <math.h> fonksiyonları kural olarak 'double' parametre alır ve 'double' döndürür.
 *    - Bir 'int' yollarsan derleyici örtük olarak (implicit cast) 'double'a yükseltir.
 *    - Ekrana basarken '%d' değil, mutlaka '%f', '%.2f' veya '%lf' kullanılmalıdır.
 *
 * 2. abs() vs fabs() TUZAĞI:
 *    - abs()   -> <stdlib.h> içindedir, SADECE tamsayılar (int) içindir.
 *    - fabs()  -> <math.h> içindedir, ondalıklı sayılar (double/float) içindir.
 *    - fabs(-4.7) yerine abs(-4.7) yazarsan sayı 4'e kırpılır (hassasiyet kaybı).
 *
 * 3. ONDALIKLI MOD (%) İMKÂNSIZLIĞI:
 *    - C dilinde '%' operatörü ondalıklı sayılarda (float/double) DERLENMEZ.
 *    - Ondalıklı mod hesabı için fmod(x, y) fonksiyonu şarttır.
 *
 * 4. LİNKER (BAĞLAYICI) BAYRAĞI (-lm):
 *    - Linux / GCC ortamında derlerken sadece #include <math.h> yetmez.
 *    - Derleme komutunun sonuna matematik kütüphanesini bağlayan bayrak eklenmelidir:
 *      gcc 08_math_library_essentials.c -lm -o app
 * ==============================================================================
 */

 // bu fonksiyonlar, matematik kütüphanesinin temel mekanizmalarını örneklemek için yazılmıştır. 
 // mantıksal olarak üç ana başlık altında toplanmıştır: üs ve kök fonksiyonları, mutlak değer ve ondalıklı mod, yuvarlama mekanizmaları. her bir başlık altında ilgili fonksiyonlar kullanılarak örnekler gösterilmektedir.

void demo_powers_and_roots(void);
void demo_absolute_and_modulo(void);
void demo_rounding_mechanics(void);

int main(void)
{
    printf("=== C STANDART MATEMATİK KÜTÜPHANESİ (math.h) ÖRNEKLERİ ===\n\n");
    demo_powers_and_roots();
    demo_absolute_and_modulo();
    demo_rounding_mechanics();

    return EXIT_SUCCESS;
}


/* 1. Üs ve Kök Fonksiyonları: pow, sqrt, cbrt */
void demo_powers_and_roots(void)
{
    double taban = 2.0, us = 8.0;
    double karekok_girdi = 49.0;
    double kupkok_girdi = 27.0;

    printf("[1] US VE KOK MEKANIZMASI:\n");
    printf("  pow(%.1f, %.1f)   = %.2f  (2 uzeri 8)\n", taban, us, pow(taban, us));
    printf("  sqrt(%.1f)       = %.2f  (Karekok)\n", karekok_girdi, sqrt(karekok_girdi));
    printf("  cbrt(%.1f)       = %.2f  (Kupkok)\n", kupkok_girdi, cbrt(kupkok_girdi));
    
    /* Dikkat: Negatif karekök 'NaN' (Not a Number / Sayı Değil) üretir */
    printf("  sqrt(-9.0)        = %f (Tanim disi girdide NaN doner)\n\n", sqrt(-9.0));
}




/* 2. Mutlak Değer ve Ondalıklı Kalan: fabs, fmod */
void demo_absolute_and_modulo(void)
{
    double negatif_sayi = -15.75;
    double bolunen = 7.3, bolen = 2.0;

    printf("[2] MUTLAK DEĞER VE ONDALIKLI MOD:\n");
    /* fabs: Floating-point Absolute */
    printf("fabs(%.2f)    = %.2f (ondalikli mutlak deger)\n", negatif_sayi, fabs(negatif_sayi));

    /* fmod: Floating-point Modulo (7.3 = 2.0 * 3 + 1.3) */
    printf(" fmod(%.1f, %.1f) = %.2f (7.3 %% 2.0 yerine kullanilir)\n", bolunen, bolen, fmod(bolunen, bolen));
}




/* 3. Yuvarlama Mekanizmaları: ceil, floor, round, trunc */
void demo_rounding_mechanics(void)
{
    double pozitif = 4.3;
    double esik_deger = 4.5;
    double negatif = -4.7;

    printf("[3] YUVARLAMA DISIPLINI VE FARKLAR:\n");
    printf("  Girdi: %.1f\n", pozitif);
    printf("    ceil(%.1f)     = %.1f (Yukari tavan yuvarlama - her zaman buyuge)\n", pozitif, ceil(pozitif));
    printf("    floor(%.1f)    = %.1f (Asagi taban yuvarlama - her zaman kucuge)\n", pozitif, floor(pozitif));
    printf("    round(%.1f)    = %.1f (En yakin tamsayiya - 0.5 alti asagi)\n", pozitif, round(pozitif));

    printf("  Girdi: %.1f (Kritik 0.5 Esigi)\n", esik_deger);
    printf("    round(%.1f)    = %.1f (0.5 ve uzeri yukari yuvarlanir)\n", esik_deger, round(esik_deger));

    printf("  Girdi: %.1f (Negatif Sayi Mantigi)\n", negatif);
    printf("    floor(%.1f)    = %.1f (-4.7'den kucuk ilk tam sayi -5.0'dir)\n", negatif, floor(negatif));
    printf("    trunc(%.1f)    = %.1f (Kusurati atar, sifira dogru kirpar)\n", negatif, trunc(negatif));
}





