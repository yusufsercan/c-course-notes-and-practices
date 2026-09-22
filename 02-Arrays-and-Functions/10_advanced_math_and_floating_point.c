/* ==============================================================================
 * 10_advanced_math_and_floating_point.c
 * C99 İleri Seviye Matematik, Sayı Teşhis Makroları ve Kayan Nokta Mekaniği
 * ==============================================================================
 * 
 * ------------------------------------------------------------------------------
 * 1. FONKSİYON VE MAKRO SÖZLÜĞÜ (NE İŞE YARARLAR?):
 * ------------------------------------------------------------------------------
 * • isnan(x)         : Sayının NaN (Not a Number - Tanımsız/Sayı Değil) olup 
 *                      olmadığını sorgular (örn: 0.0 / 0.0 veya sqrt(-1.0)).
 *
 * • isinf(x)         : Sayının pozitif veya negatif SONSUZLUK (+inf / -inf) olup 
 *                      olmadığını denetler (örn: 1.0 / 0.0).
 *
 * • isfinite(x)      : Sayının 'geçerli ve sonlu' bir sayı olup olmadığını doğrular.
 *                      (Sayı ne NaN ne de Sonsuz ise 1 döner). Sensör verisi doğrulamada şarttır.
 *
 * • signbit(x)       : Sayının İŞARET BİTİNİ (en soldaki sign bit) okur. 
 *                      Negatifse 1 (true), pozitifse 0 döner. 
 *                      '-0.0' değerini sıradan 'x < 0' şartı yakalayamaz ama 'signbit' yakalar!
 *
 * • remainder(x, y)  : IEEE 754 standardına göre kalan (mod) hesaplar. 
 *                      Bölümü en yakın tam sayıya yuvarlayarak kalan bulur.
 *                      fmod(x, y)'den farkı: fmod sıfıra doğru kırpar, remainder en yakına yuvarlar.
 *
 * • round(x)         : Standart yuvarlama (0.5 ve üzerini mutlak olarak sıfırdan uzağa yuvarlar).
 *
 * • rint(x)          : (Round to INTeger) Donanımın geçerli kayan nokta yuvarlama moduna göre 
 *                      en yakın tam sayıya yuvarlar (genellikle 'en yakın çifte' yuvarlar - bankers rounding).
 *
 * • isgreater(x, y)      : x > y kontrolünün güvenli (quiet) halidir.
 * • isgreaterequal(x, y) : x >= y kontrolünün güvenli halidir.
 * • isless(x, y)         : x < y kontrolünün güvenli halidir.
 * • islessequal(x, y)    : x <= y kontrolünün güvenli halidir.
 *
 * ------------------------------------------------------------------------------
 * 2. KRİTİK MÜHENDİSLİK TUZAKLARI VE "NEDEN BU ARAÇLAR VAR?":
 * ------------------------------------------------------------------------------
 * 1. BÜYÜK TUZAK: 'x == NAN' ASLA ÇALIŞMAZ!
 *    - IEEE 754 standardına göre NaN kendisi dahil DÜNYADAKİ HİÇBİR ŞEYE EŞİT DEĞİLDİR.
 *    - 'NAN == NAN' ifadesinin sonucu daima 0'dır (False)!
 *    - Bu yüzden bir sayının bozulduğunu anlamanın TEK geçerli yolu 'isnan(x)' makrosudur.
 *
 * 2. STANDART OPERATÖR (<, >) TUZAĞI:
 *    - Eğer bir değişkende NaN varsa ve sen 'if (x > y)' dersen, işlemci donanımsal 
 *      bir kayan nokta istisnası (FE_INVALID exception) fırlatabilir.
 *    - 'isgreater(x, y)' gibi makrolar sessizdir (quiet comparison); NaN olsa bile 
 *      hata fırlatmadan güvenle 0 (false) döndürür.
 *
 * 3. DERLEME NOTU:
 *    - Linux / GCC ortamında derlerken matematik kütüphanesini bağla:
 *      gcc 10_advanced_math_and_floating_point.c -lm -o app
 * ==============================================================================
 */


#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void demo_floating_point_diagnostics(void);
void demo_quiet_comparisons(void);
void demo_remainder_vs_fmod(void);
void demo_round_vs_rint(void);

int main(void)
{
    printf("=== ILERI SEVIYE C <math.h> VE FLOATING-POINT MEKANIZMASI ===\n\n");

    demo_floating_point_diagnostics();
    demo_quiet_comparisons();
    demo_remainder_vs_fmod();
    demo_round_vs_rint();

    return EXIT_SUCCESS;
}

/* 1. Sayı Teşhis ve Doğrulama Araçları */
void demo_floating_point_diagnostics(void)
{
    double gecerli_sayi = 42.5;
    double tanimsiz = 0.0 / 0.0;    // NaN üretir
    double sonsuz = 1.0 / 0.0;      // +Infinity üretir
    double eksi_sifir = -0.0;       // IEEE 754'te -0.0 vardır!

    printf("[1] SAYI TESHIS VE GUVENLIK MAKROLARI:\n");

    // isnan() İncelemesi:
    printf("  tanimsiz (0.0/0.0) degeri: %f\n", tanimsiz);
    printf("    isnan(tanimsiz)        -> %d (1: Sayi bozuk/NaN)\n", isnan(tanimsiz));
    printf("    tanimsiz == tanimsiz   -> %d (0: NaN kendisine bile esit olamaz!)\n", tanimsiz == tanimsiz);

    // isinf() ve isfinite() İncelemesi:
    printf("\n  sonsuz (1.0/0.0) degeri  : %f\n", sonsuz);
    printf("    isinf(sonsuz)          -> %d (1: Sonsuzluk tespit edildi)\n", isinf(sonsuz));
    printf("    isfinite(sonsuz)       -> %d (0: Sonlu degil)\n", isfinite(sonsuz));
    printf("    isfinite(gecerli_sayi) -> %d (1: Sayi temiz ve guvenli)\n", isfinite(gecerli_sayi));

    // signbit() ve Negatif Sıfır (-0.0) İncelemesi:
    printf("\n  eksi_sifir degeri        : %f\n", eksi_sifir);
    printf("    eksi_sifir < 0.0       -> %d (0: Standart karsilastirma yakalayamaz!)\n", eksi_sifir < 0.0);
    printf("    signbit(eksi_sifir)    -> %d (1: Donanimsal isaret biti 1/negatif)\n\n", signbit(eksi_sifir) != 0);
}

/* 2. Güvenli (Quiet) Kıyaslama Makroları */
void demo_quiet_comparisons(void)
{
    double a = 10.5;
    double b = 20.3;
    double bozuk_sayi = 0.0 / 0.0; // NaN

    printf("[2] GUVENLI (QUIET) KIYASLAMA MAKROLARI:\n");
    printf("  isgreater(%.1f, %.1f)     -> %d\n", a, b, isgreater(a, b));
    printf("  isless(%.1f, %.1f)        -> %d\n", a, b, isless(a, b));
    printf("  isgreaterequal(%.1f, 10.5)-> %d\n", a, isgreaterequal(a, 10.5));

    // NaN ile kıyaslama donanımı patlatmaz, guvenle 0 doner:
    printf("  isgreater(bozuk_sayi, 5.0)-> %d (NaN ile guvenli karsilastirma)\n\n", isgreater(bozuk_sayi, 5.0));
}

/* 3. remainder() vs fmod() Farkı */
void demo_remainder_vs_fmod(void)
{
    /* 
     * fmod(7.0, 2.0): Bölüm 3.5'tir, sıfıra doğru kırpar (3 alır). 7 - (2 * 3) = 1.0 döner.
     * remainder(7.0, 2.0): Bölüm 3.5'tir, en yakın çift tamsayıya yuvarlar (4 alır). 7 - (2 * 4) = -1.0 döner!
     */
    double x = 7.0, y = 2.0;

    printf("[3] remainder() VS fmod() HASSAS FARKI:\n");
    printf("  Girdi: x = %.1f, y = %.1f\n", x, y);
    printf("    fmod(x, y)      = %.2f (Sifira kirparak kalan bulur)\n", fmod(x, y));
    printf("    remainder(x, y) = %.2f (En yakin tam sayiya yuvarlayarak kalan bulur)\n\n", remainder(x, y));
}

/* 4. round() vs rint() Farkı */
void demo_round_vs_rint(void)
{
    double sayi1 = 2.5;
    double sayi2 = 3.5;

    printf("[4] round() VS rint() YUVARLAMA STRATEJILERI:\n");
    /* round: Her zaman 0.5'i sıfırdan uzağa atar (2.5 -> 3, 3.5 -> 4) */
    printf("  round(2.5) = %.1f | round(3.5) = %.1f (Standart aritmetik yuvarlama)\n", 
           round(sayi1), round(sayi2));

    /* rint: Donanım kuralını uygular. Varsayılan olarak 'en yakın çifte' yuvarlar (Banker's Rounding) */
    printf("  rint(2.5)  = %.1f | rint(3.5)  = %.1f (En yakin cift tamsayiya yuvarlama)\n", 
           rint(sayi1), rint(sayi2));
}