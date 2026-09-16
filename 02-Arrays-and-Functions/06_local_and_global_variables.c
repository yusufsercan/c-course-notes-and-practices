#include <stdio.h>
#include  <stdlib.h>

// bu kodda global ve local değişkenlerin nasıl çalıştığını gösteren bir örnek bulunmaktadır.

void  Increase(); // Increase fonksiyonu global değişkeni 1 artırır.
void  Decrease(); // Decrease fonksiyonu global değişkeni 1 azaltır.
int x=7; // global değişken x, tüm fonksiyonlar tarafından erişilebilir.

int main()
{
    printf("Initial value of x: %d\n", x); // global değişkenin başlangıç değeri ekrana yazdırılır.
    Increase(); // Increase fonksiyonu çağrılır ve x 1 artırılır.
    printf("Value of x after Increase(): %d\n", x); 
    Decrease(); // Decrease fonksiyonu çağrılır ve x 1 azaltılır.
    Decrease(); 
    printf("Value of x after Decrease(): %d\n", x); 
    return 0;
}
void Increase() 
{
    x++; 
}
void Decrease() 
{
    x--; 
}