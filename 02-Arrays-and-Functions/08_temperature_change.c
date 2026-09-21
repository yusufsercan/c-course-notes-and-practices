#include <stdio.h>
#include <stdlib.h>

// bu program, kullanıcıdan sıcaklık değerini alır ve Fahrenheit ile Celsius arasında dönüşüm yapar. Kullanıcıya hangi dönüşümü yapmak istediği sorulur ve ardından ilgili dönüşüm gerçekleştirilir.
int CelToFah(int);
int FahToCel(int);

int main()
{
    char choose;
    int number;

    printf("Fahrenheit -> Celsius (F) or Celsius -> Fahrenheit (C) ?\n");
    printf("Please enter your choice (F/C): ");
    scanf(" %c", &choose);
    switch (choose)
    {
        case 'F': printf("Enter the temperature in Fahrenheit: ");
                  scanf("%d", &number);
                  printf("%d Fahrenheit = %d Celsius\n", number, FahToCel(number));
                  break;
        case 'C': printf("Enter the temperature in Celsius: ");
                  scanf("%d", &number);
                  printf("%d Celsius = %d Fahrenheit\n", number, CelToFah(number));
                  break;
        default: printf("Invalid choice! Please enter 'F' or 'C'.\n");
    }


    return 0;   
}

int CelToFah(int c)
{
    return (c * 9 / 5) + 32;
}
int FahToCel(int f)
{
    return (f - 32) * 5 / 9;
}