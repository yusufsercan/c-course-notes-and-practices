#include <stdio.h>

/* 
 * Uygulama: Dairenin Çevresini ve Alanını Hesaplama
 * Algoritma Adımları:
 * 1- Gerekli değişkenleri ve tiplerini belirle (radius, circumference, area)
 * 2- Sabit (const) değerleri tanımla (PI)
 * 3- Kullanıcıdan yarıçap verisini al
 * 4- Çevre (2 * PI * r) ve Alan (PI * r * r) formüllerini uygula
 * 5- Sonuçları ekrana formatlı olarak yazdır
 */

int main() {
    float radius, circumference, area;
    
    // const: Değerin kodun ilerleyen aşamalarında değiştirilmesini engeller.
    // Not: C dilinde ondalıklı sayılarda virgül değil nokta (.) kullanılır.
    const float PI = 3.1415f; 

    printf("Dairenin yaricapini girin: ");
    scanf("%f", &radius);

    // Hesaplamalar
    circumference = 2 * PI * radius;
    area = PI * radius * radius;

    // Çıktılar (%.2f ile virgülden sonra 2 basamak gösteriyoruz)
    printf("\n--- Sonuclar ---\n");
    printf("Dairenin Cevresi : %.2f\n", circumference);
    printf("Dairenin Alani   : %.2f\n", area);

    return 0;
}