/* ==============================================================================
 * Karakter Seviyesinde Girdi/Çıktı (I/O) ve Akış (Stream) Mekaniği
 * ==============================================================================
 *
 * 1. TEMEL TANIM VE GÖREV:
 *    - 'getchar()': Standart girdi akışından ('stdin' / klavye) SIRADAKİ TEK BİR
 *      karakteri okur ve tampondan çeker.
 *    - 'putchar(c)': Verilen tek bir karakteri standart çıktı akışına ('stdout' /
 *      ekran) basar. 'printf("%c", c)'ye göre biçimlendirme ayrıştırması (format
 *      parsing) yapmadığı için donanım seviyesinde çok daha hızlı ve hafiftir.
 *
 * 2. EN KRİTİK MÜHENDİSLİK SORUSU: NEDEN 'char' DEĞİL DE 'int'?
 *    - 'getchar()' fonksiyonunun prototipi: 'int getchar(void);' şeklindedir.
 *    - Okunan değişken MUTLAKA 'int ch;' olarak tanımlanmalıdır, 'char ch;' DEĞİL!
 *    - SEBEP:
 *      * Bir 'char' bellekte 1 byte (genellikle 8-bit) yer kaplar ve 0-255 (veya
 *        -128 ile +127) arasındaki değerleri tutabilir.
 *      * Girdi akışı kapandığında veya bittiğinde (Ctrl+D / Ctrl+Z), fonksiyon
 *        'EOF' (End Of File) sabitini döndürür. C standartlarında EOF genellikle -1'dir.
 *      * Eğer değişkeni 'char' yaparsan, 255 kodlu geçerli bir karakter (örneğin 'ÿ')
 *        ile 'EOF (-1)' değeri birbirine karışabilir; akış erken kesilebilir veya
 *        sonsuz döngüye girebilir.
 *      * 'int' (32-bit) tipi, hem 0-255 arasındaki tüm 256 karakteri hem de bu
 *        kümenin dışındaki '-1' (EOF) değerini ayırt edebilecek genişliğe sahiptir.
 *
 * 3. SATIR TAMPONLAMA (LINE BUFFERING) GERÇEĞİ:
 *    - İşletim sistemleri konsol girdilerini "satır tamponlamalı" (line-buffered) işler.
 *    - Sen klavyede 'A' tuşuna bastığın anda 'getchar()' hemen çalışmaz.
 *    - Karakterler işletim sisteminin tamponuna yazılır; ta ki kullanıcı ENTER tuşuna
 *      basana kadar. ENTER basıldığı an girdi akışına bir de '\n' eklenir ve bant
 *      'getchar()'ın önüne akar.
 *    - 'getchar()' tamponun en başındaki ilk karakteri alır; kalan karakterler ve '\n'
 *      tamponda sonraki çağrılar için sırada bekler.
 *
 * 4. YAYGIN MÜHENDİSLİK KALIPLARI (IDIOMS):
 *    - Tampon Temizleme:
 *        while ((ch = getchar()) != '\n' && ch != EOF);
 *    - Akış Kopyalama (Echo Loop):
 *        while ((ch = getchar()) != EOF) { putchar(ch); }
 * ==============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

void demo_single_character(void);
void demo_stream_processing(void);
void demo_buffer_clearing_pattern(void);

int main(void)
{
    printf("=== C DILINDE getchar() VE putchar() DERINLEMESINE ANALIZ ===\n\n");

    demo_single_character();
    demo_stream_processing();
    demo_buffer_clearing_pattern();

    return EXIT_SUCCESS;
}

/* 1. Tek Karakter Okuma ve '\n' Tuzağı */
void demo_single_character(void)
{
    int ch; // KRİTİK: 'char' değil 'int' tanımlıyoruz!

    printf("[1] TEK KARAKTER OKUMA:\n");
    printf("Bir karakter yazip Enter'a basin: ");

    ch = getchar(); //getch ile aynı mantıkta çalışır. Tek karakteri okur ve tampondan çeker. enter tuşuna basılana kadar bekler. enter tuşuna basıldığında '\n' karakteri de tamponda oluşur.

    printf("Girilen Karakter: '");
    putchar(ch);
    printf("' | ASCII Kodu: %d\n", ch);

    /* 
     * TUZAK: Kullanıcı 'A' yazıp Enter'a bastığında, tamponda 'A' ve '\n' oluşur.
     * 'getchar()' yukarıda 'A'yı aldı ama '\n' (ASCII 10) hala tamponda bekliyor!
     * Sonraki örneğe geçmeden önce o '\n' karakterini süpürüyoruz:
     */
    while (getchar() != '\n');
    printf("\n");
}

/* 2. Dizi/Bellek Ayrımı Yapmadan Gerçek Zamanlı Akış İşleme */
void demo_stream_processing(void)
{
    int ch;

    printf("[2] AKIS ISLEME (BELLEK HARCAMADAN BUYUK HARFE CEVIRME):\n");
    printf("Bir cumle yazip Enter'a basin: ");

    /* 
     * String tanımlayıp 'char str[100]' gibi belleği şişirmeden,
     * veriyi akıştan geldiği anda anlık işleyip ekrana basıyoruz:
     */
    while ((ch = getchar()) != '\n' && ch != EOF) // burada EOF kontrolü de yapıyoruz, çünkü kullanıcı Ctrl+D (Linux) veya Ctrl+Z (Windows) ile akışı kapatabilir. /n kontrolü ise ENTER tuşuna basıldığında döngüyü kırmak için.
    {
        // Küçük harf ise ASCII aritmetiğiyle büyük harfe dönüştür ('a' - 'A' = 32)
        if (ch >= 'a' && ch <= 'z')
        {
            ch = ch - ('a' - 'A');
        }
        putchar(ch); // Anlık ekrana gönder
    }
    putchar('\n'); // Cümle bitince yeni satıra geç
    printf("\n");
}

/* 3. Tampon Temizleme Mekanizmasının İç Yapısı */
void demo_buffer_clearing_pattern(void)
{
    int sayi;
    int copKarakter;

    printf("[3] scanf SONRASI TAMPON TEMIZLIGI:\n");
    printf("Bir tam sayi girin (ardindan fazladan harfler de yazabilirsiniz): ");
    
    scanf("%d", &sayi);
    printf("scanf tarafindan okunan sayi: %d\n", sayi);

    printf("Tamponda arta kalan ve supürülen karakterler: ");
    /* 
     * Kullanıcı '42xyz' yazıp Enter'a basarsa:
     * scanf sadece 42'yi alır. 'x', 'y', 'z' ve '\n' tamponda kalır.
     * Aşağıdaki döngü bu çöpleri tek tek çeker ve tamponu sıfırlar:
     */
    while ((copKarakter = getchar()) != '\n' && copKarakter != EOF)
    {
        putchar(copKarakter); // Hangi çöplerin atıldığını gör
    }
    printf("\n[Tampon basariyla temizlendi]\n");
}