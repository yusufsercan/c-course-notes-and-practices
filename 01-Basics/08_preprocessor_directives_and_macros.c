 // * Amaç: #define, #undef, #ifdef, #ifndef, #error ve #include yapılarının 

 

// 1. INCLUED DIRECTIVES (Kütüphane Dahil Etme)
#include <stdio.h> // Standart Giriş/Çıkış kütüphanesi (Sistem Kütüphanesi)

// 2. DEFINE DIRECTIVES (Simgesel Sabitler ve Makrolar)
#define PI 3.14159
#define BUFFER_SIZE 1024

// Güvenli Makro Tanımı: İşlem önceliği hatası almamak için tüm parametreler parantez içine alınmalıdır!
// Örn: KARE(3 + 1) -> ((3 + 1) * (3 + 1)) = 16 sonucunu doğru verir.
#define KARE(x) ((x) * (x))

// 3. UNDEF DIRECTIVES (Makro İptali)
#define ESKI_MESAJ "Bu mesaj gecersizdir."
#undef ESKI_MESAJ // ESKI_MESAJ makrosunu iptal ettik.

// 4. CONDITIONAL COMPILATION (Koşullu Derleme Anahtarları)
// Geliştirme aşamasında log basmak için DEBUG anahtarını açıyoruz.
// Canlıya (Release) çıkarken bu satır yoruma alınır veya silinir.
#define DEBUG

// 5. SAFETY & COMPILER CHECKS (#error Kontrolü)
// Projede kritik bir konfigürasyonun unutulup unutulmadığını kontrol eder.
#ifndef BUFFER_SIZE
    #error "HATA: BUFFER_SIZE tanimlanmadan bu program derlenemez!"
#endif

int main() {
    printf("==================================================\n");
    printf("     C ON ISLEMCI KOMUTLARI & MAKRO ORNEGI       \n");
    printf("==================================================\n\n");

    // --- A. Sabit ve Makro Kullanımı ---
    printf("[1] SABIT VE MAKRO KULLANIMI:\n");
    printf(" -> Yaricapi 5 olan dairenin alani : %.2f\n", PI * KARE(5));
    printf(" -> (3 + 1)'in karesi (Guvenli Makro): %d\n\n", KARE(3 + 1));

    // --- B. #ifdef / #ifndef (Debug ve Mod Kontrolleri) ---
    printf("[2] KOSULLU DERLEME KONTROLLER:\n");

    #ifdef DEBUG
        // Sadece #define DEBUG tanımlıysa derlenir ve koda dahil edilir.
        printf(" -> [DEBUG MODU ACIK]: Arka plan bellek boyutu: %d byte\n", BUFFER_SIZE);
        printf(" -> [DEBUG MODU ACIK]: Sistem degiskenleri kontrol edildi.\n");
    #endif

    #ifndef RELEASE
        // RELEASE tanımlı OLMADIĞI için bu blok çalışır.
        printf(" -> [DURUM]: Program henuz canli yayin (Release) modunda degil.\n");
    #endif

    printf("\nProgram basariyla tamamlandi.\n");
    return 0;
}
