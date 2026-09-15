#include <stdio.h>
#include "myMath.h"//kendi fonksiyonlarımızı yazarken prototiplerini myMath.h dosyasında tanımladık. bu sayede main fonksiyonu içerisinde bu fonksiyonları çağırabiliriz.
#include <stdlib.h>

int main()
{
    int choose;
    menu();//menu fonksiyonunu çağırıyoruz. bu fonksiyon kullanıcıya hangi işlemi yapmak istediğini sorar ve seçilen işleme göre ilgili fonksiyonu çağırır.
    printf("Please choose an operation (1-5): ");
    scanf("%d", &choose);
    printf("\n");
    switch (choose)//switch-case yapısı ile kullanıcının seçtiği işleme göre ilgili fonksiyonu çağırıyoruz.
    {
    case 1:
        {
            int a, b;
            printf("Enter two integers: ");
            scanf("%d %d", &a, &b);
            printf("Minimum: %d\n", min(a, b));
            break;
        }
    case 2:
        {
            int a, b;
            printf("Enter two integers: ");
            scanf("%d %d", &a, &b);
            printf("Maximum: %d\n", max(a, b));
            break;
        }
    case 3:
        {
            int x;
            printf("Enter an integer: ");
            scanf("%d", &x);
            printf("Square: %d\n", square(x));
            break;
        }
    case 4:
        {
            int x;
            printf("Enter an integer: ");
            scanf("%d", &x);
            printf("Cube: %d\n", cube(x));
            break;
        }
    case 5:
        {
            int x;
            printf("Enter an integer: ");
            scanf("%d", &x);
            printf("Absolute Value: %d\n", my_abs(x));
            break;
        }
    default: //default case ile kullanıcı geçersiz bir seçim yaptığında uyarı mesajı veriyoruz.
        printf("Invalid choice!\n");
    }
    return 0;
}

void menu() //menu fonksiyonu kullanıcıya hangi işlemi yapmak istediğini sorar ve seçilen işleme göre ilgili fonksiyonu çağırır. 
{
    printf("\n");
    printf("************\n");
    printf("*    MENU   *\n");
    printf("************\n");
    printf("1. Find Minimum\n");
    printf("2. Find Maximum\n");
    printf("3. Calculate Square\n");
    printf("4. Calculate Cube\n");
    printf("5. Calculate Absolute Value\n");
}
int min(int a, int b)
{
    if (a < b)
        return a;
    else
        return b;
}
int max(int a, int b)
{
    if (a > b)
        return a;
    else
        return b;
}
int square(int x)
{
    return x * x;
}
int cube(int x)
{
    return x * x * x;
}
int my_abs(int x)
{
    if (x < 0)
        return -x;
    else
        return x;
}
