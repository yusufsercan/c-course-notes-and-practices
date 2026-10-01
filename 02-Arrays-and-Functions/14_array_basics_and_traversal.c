/* ==============================================================================.c
 * C Dilinde Dizilere Giriş, Bellek Düzeni ve Boyut Hesaplama Disiplini
 * ==============================================================================
 * 
 * 1. DİZİ (ARRAY) NEDİR VE BELLEKTE NASIL YAŞAR?
 *    - Dizi, AYNI TİPTEN verilerin belleğin STACK bölgesinde KESİNTİSİZ ve ARDIŞIK
 *      (contiguous) bir blok halinde saklanmasıdır.
 *    - Bir 'int' değişkeni 4 bayt ise, 5 elemanlı bir 'int' dizisi bellekte yan yana
 *      tam 20 baytlık (5 x 4) tek parça yer kaplar.
 *
 * 2. İNDEKSLEME MANTIĞI (NEDEN 0'DAN BAŞLAR?):
 *    - 'notes[0]' ifadesi 1. sıra anlamına gelmez; "Dizinin başlangıç adresinden
 *      itibaren 0 bayt ötelen" demektir.
 *    - 'notes[1]' demek, başlangıç adresinden 1 'int' boyutu (4 bayt) ileri git demektir.
 *
 3. DİZİ BOYUTU HESAPLAMA STANDARTLARI:
 *    - 'sizeof(notes)' : Dizinin bellekte kapladığı toplam alanı verir (byte cinsinden).
 *    - 'sizeof(notes[0])' : Dizinin tek bir elemanının boyutunu verir (byte cinsinden).
 *    - 'sizeof(notes) / sizeof(notes[0])' : Dizinin eleman sayısını verir. Bu, C dilinde dizilerle çalışırken en güvenli ve standart yöntemdir.
 *
 4. C DIZILERININ C++'TAN FARKI:
 *    - C'de 'vector' yoktur, '.size()' metodu yoktur.
 *    - Dizi boyutu tanimlandiktan sonra DEGISMEZ (Sabittir).
 *    - Sinir kontrolu yoktur: 5 elemanli diziye 6. elemani yazarsan C uyarmaz,
 *      bellekteki baska bir veriyi bozar (Buffer Overflow).
 */

#include <stdio.h>

#define BOYUT 5 // Dizi boyutunu tek bir yerden yonetmek icin sabit tanimliyoruz

int main(void)
{
    // 1. Tanimlama ve Ilk Deger Verme (Initialization)
    int notlar[BOYUT] = {70, 85, 90, 65, 100};

    // 2. Elemana Indeksle Erisme ve Degerini Degistirme
    printf("1. elemanin eski degeri (notlar[0]): %d\n", notlar[0]);
    notlar[0] = 75; // 70 olan ilk notu 75 olarak guncelledik
    printf("1. elemanin yeni degeri (notlar[0]): %d\n\n", notlar[0]);

    // 3. Dongu ile Dizi Elemanlarini Gezme ve Toplama (Traversal)
    int toplam = 0;

    printf("--- Ogrenci Not Listesi ---\n");
    for (int i = 0; i < BOYUT; i++) // boyutu yukarıda define ettiğimiz sabitten alıyoruz, böylece ileride boyutu değiştirmek istersek sadece bir yerden değişiklik yapmamız yeterli olur.
    {
        printf("%d. Ogrencinin Notu: %d\n", i + 1, notlar[i]);
        toplam += notlar[i]; // Her adimdaki notu toplama ekliyoruz
    }

    // 4. Ortalama Hesabi
    // Tip donusumu (float)toplam yapmazsak C tamsayi bolmesi yapar ve kusurat gider!
    float ortalama = (float)toplam / BOYUT;

    printf("---------------------------\n");
    printf("Notlar Toplami : %d\n", toplam);
    printf("Sinif Ortalamasi: %.2f\n\n", ortalama);

    // 5. C Klasigi: Tum Elemanlari Sifir Olan Dizi Olusturma
    int sifirDizisi[3] = {0}; // Geriye kalan tum elemanlar otomatik 0 olur
    printf("Sifirlanmis dizi elemanlari: %d, %d, %d\n", 
           sifirDizisi[0], sifirDizisi[1], sifirDizisi[2]); // buradaki amaç, dizinin tüm elemanlarının 0 olduğunu göstermek

    return 0;
}
