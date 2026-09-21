#include <stdio.h>
#include <stdlib.h>
#include <math.h> // math.h kütüphanesi, matematiksel fonksiyonları kullanmamıza olanak sağlar.

/* ==============================================================================
 * 08_math_library_essentials.c
 * Standart C Matematik Kütüphanesi (<math.h>) Çekirdek Mekanizmaları ve Sözlüğü
 * ==============================================================================
 * 
 * ------------------------------------------------------------------------------
 * 1. FONKSİYON SÖZLÜĞÜ (NE İŞE YARARLAR?):
 * ------------------------------------------------------------------------------
 * • abs(x)   [<stdlib.h>] : TAMSAYI (int) mutlak değerini alır. 
 *                          Negatif sayıyı pozitife çevirir. (|x|)
 *                          Örn: abs(-5) -> 5
 *
 * • fabs(x)  [<math.h>]   : ONDALIKLI (double/float) mutlak değerini alır.
 *                          Fark veya hata toleransı hesaplarında (epsilon) kullanılır.
 *                          Örn: fabs(-4.75) -> 4.75
 *
 * • pow(x, y)             : Üs alma fonksiyonudur (x^y). 
 *                          x taban, y üstür. Fizik, faiz veya geometri hesaplarında kullanılır.
 *                          Örn: pow(2.0, 8.0) -> 256.00
 *
 * • sqrt(x)               : Karekök alır (√x). Hipotenüs veya mesafe hesaplarında temeldir.
 *                          Kural: x negatif olamaz; olursa 'NaN' (Not a Number) döner.
 *                          Örn: sqrt(49.0) -> 7.00
 *
 * • cbrt(x)               : Küpkök alır (∛x). Hacimden kenar uzunluğu bulurken kullanılır.
 *                          sqrt'nin aksine negatif sayıların da küpkökünü hesaplayabilir.
 *                          Örn: cbrt(-27.0) -> -3.00
 *
 * • fmod(x, y)            : Ondalıklı sayılarda mod alma (kalan bulma) işlemidir.
 *                          C'de '%' operatörü float/double için çalışmadığından zorunludur.
 *                          Örn: fmod(7.3, 2.0) -> 1.30  (7.3 = 2.0 * 3 + 1.3)
 *
 * • ceil(x)  (Ceiling)    : TAVANA YUVARLAMA yapar. Sayıyı kendisinden büyük ilk tam sayıya 
 *                          (daima +sonsuz yönüne) çeker. Paketleme/sayfalama (pagination) 
 *                          hesaplarında (örn: 21 ürün, 5'li kutulara 5 kutu gerekir) kullanılır.
 *                          Örn: ceil(4.1) -> 5.0  |  ceil(-4.8) -> -4.0
 *
 * • floor(x) (Floor)      : TABANA YUVARLAMA yapar. Sayıyı kendisinden küçük ilk tam sayıya 
 *                          (daima -sonsuz yönüne) çeker. Oyun ızgara (grid) koordinatlarında kullanılır.
 *                          Örn: floor(4.9) -> 4.0  |  floor(-4.2) -> -5.0
 *
 * • round(x)              : EN YAKIN TAM SAYIYA yuvarlar. Standart bakkal/matematik yuvarlamasıdır.
 *                          Virgülden sonrası 0.5 ve üzeri ise yukarı, altı ise aşağı yuvarlar.
 *                          Örn: round(4.4) -> 4.0  |  round(4.5) -> 5.0
 *
 * • trunc(x) (Truncate)   : KESME/KIRPMA yapar. Virgülden sonrasını makasla kesip atar, 
 *                          sayıyı sıfıra doğru çeker. floor'dan farkı negatif sayılarda ortaya çıkar.
 *                          Örn: trunc(4.9) -> 4.0  |  trunc(-4.9) -> -4.0
 *
 * ------------------------------------------------------------------------------
 * 2. KRİTİK MÜHENDİSLİK NOTLARI VE DERLEYİCİ TUZAKLARI:
 * ------------------------------------------------------------------------------
 * 1. TİP UYUMU (TYPE COERCION):
 *    - <math.h> fonksiyonları istisnasız 'double' ile çalışır ve geriye 'double' döner.
 *    - Bu fonksiyonların sonuçlarını ekrana basarken asla '%d' kullanma; derleyici çöp 
 *      değer basar. Her zaman '%f', '%.2f' veya '%lf' kullan.
 *
 * 2. abs() vs fabs() TUZAĞI (SESSİZ HATA):
 *    - Eğer ondalıklı bir sayıda 'fabs()' yerine 'abs()' yazarsan kod derlenir ancak 
 *      sayı 'int'e kırpılır (cast edilir) ve virgülden sonrası kaybolur (Hassasiyet kaybı).
 *
 * 3. LİNKER (BAĞLAYICI) BAYRAĞI (-lm):
 *    - Linux ve GCC ortamında matematik kütüphanesi çekirdekten ayrı bir dosyada tutulur.
 *    - Derlerken komutun sonuna mutlaka '-lm' (link math library) bayrağı eklenmelidir:
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





