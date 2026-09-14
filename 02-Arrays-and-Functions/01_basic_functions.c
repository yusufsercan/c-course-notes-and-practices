/*
* 1. FONKSİYON PROTOTİPİ (DECLARATION) VE GÖVDE (DEFINITION):
 *    - Bildirim (Prototype): Derleyiciye fonksiyonun adını, dönüş tipini ve aldığı
 *      parametre tiplerini önceden tanıtır. Tek geçişli (single-pass) C derleyicisi
 *      için çağrıdan önce yazılmalıdır (örn: int topla(int, int);).
 *    - Tanım (Definition): Fonksiyonun icra edeceği mantığı içeren asıl kod bloğudur.
 *
 * 2. PARAMETRE VS. ARGÜMAN FARKI:
 *    - Parametre (Formal Parameter): Fonksiyon tanımında beklenen yerel değişkenler.
 *    - Argüman (Actual Argument): Fonksiyon çağrılırken fonksiyona gönderilen gerçek değerler.
 *
 * 3. HER ŞEY DEĞERLE AKTARILIR (STRICT PASS-BY-VALUE):
 *    - C dilinde "Pass-by-Reference" mekanizması YOKTUR. Argümanlar kopyalanarak iletilir.
 *    - Orijinal değişkeni fonksiyon içinden değiştirmek için referans değil;
 *      değişkenin bellek adresi kopyalanır (Pass-by-value of a pointer/address).
 *
 * 4. ÇAĞRI YIĞINI VE KAPSAM (CALL STACK & STACK FRAME):
 *    - Fonksiyon her çağrıldığında belleğin Stack bölgesinde bir "Stack Frame" açılır.
 *    - Yerel (local) değişkenler bu frame içinde yaşar; fonksiyon bittiğinde (return)
 *      frame yıkılır ve değişkenlerin ömrü sonlanır.
 *    - Ölümcül Hata: Fonksiyon içindeki yerel bir değişkenin adresini return etmek
 *      "Dangling Pointer" (askıda işaretçi) yaratır ve Undefined Behavior'a yol açar.
 *
 * 5. DÖNÜŞ TİPİ VE 'void' DİSİPLİNİ:
 *    - Geriye değer döndürmeyen fonksiyonlar 'void' ile belirtilir.
 *    - Parametre almayan fonksiyonlarda parantez içini boş bırakmak yerine 'void'
 *      yazmak (örn: void calistir(void)) C'de fonksiyonun kesinlikle parametre
 *      kabul etmediğini garanti eder.
 *
 * 6. 'static' YEREL DEĞİŞKENLER:
 *    - Fonksiyon içinde 'static' olarak tanımlanan bir değişken Stack'te değil,
 *      Data/BSS segmentinde tutulur.
 *    - Fonksiyon sonlansa dahi değerini korur ve bir sonraki çağrıda kaldığı
 *      değerden devam eder (yaşam süresi program boyunca sürer).
 *
 * 7. MODÜLERLİK VE HEADER (.h) MİMARİSİ:
 *    - Profesyonel mimaride fonksiyon prototipleri başlık (.h) dosyalarında,
 *      fonksiyon gövdeleri ise kaynak (.c) dosyalarında tutulur.
 *    - Çoklu eklemeleri engellemek için include guard (#ifndef, #define, #endif)
 *      veya '#pragma once' kullanılır.
 * 
*/

#include <stdlib.h>
#include <stdio.h>

 void myMessage()
{
   printf("Now I can  wriye functions in C language\n");
}

void nameList(char name[], int age)
{
    printf("Name: %s, Age: %d\n", name, age);
}

int main()
{
    myMessage();
    nameList("John Doe", 30);
    nameList("Jane Smith", 25);
    nameList("Alice Johnson", 28);
    return 0;
}









