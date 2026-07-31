#include <stdio.h>


/* NOT:
char dayName; ---> Sadece 'A', 'b', '5' gibi TEK BİR harf tutar.
char *dayName; ---> "Pazartesi", "Salı" gibi METİNLERİN adresini tutar. */


/*
 * Task: Calculate cumulative product sales up to a given day of the week.
 * Concept: Intentional switch-case fall-through (omitting 'break' statements) for accumulation.
 */

int main() 
{
    int day = 0;
    int numberOfProducts = 0;
    const char *dayName = "";

    printf("Enter a number of day (1-7): ");
    scanf("%d", &day);

    // Input validation for invalid day inputs
    if (day < 1 || day > 7) 
    {
        printf("Error: Invalid day number! Please enter a value between 1 and 7.\n");
        return 1; // Terminate with error code
    }

    /* 
     * NOTE ON FALL-THROUGH LOGIC:
     * We intentionally omit 'break' statements.
     * When execution hits the matching 'case', it updates the day's name,
     * then falls through all lower cases to sum up previous sales cumulatively.
     */
    switch (day) 
    {
        case 7:
            dayName = "Pazar";
            numberOfProducts += 25; // Intentional fall-through
        case 6:
            if (day == 6) dayName = "Cumartesi";
            numberOfProducts += 19; // Intentional fall-through
        case 5:
            if (day == 5) dayName = "Cuma";
            numberOfProducts += 15; // Intentional fall-through
        case 4:
            if (day == 4) dayName = "Persembe";
            numberOfProducts += 10; // Intentional fall-through
        case 3:
            if (day == 3) dayName = "Carsamba";
            numberOfProducts += 7;  // Intentional fall-through
        case 2:
            if (day == 2) dayName = "Sali";
            numberOfProducts += 5;  // Intentional fall-through
        case 1:
            if (day == 1) dayName = "Pazartesi";
            numberOfProducts += 2;
            break;
            
        default:
            break;
    }

    printf("\n%s gunu sonunda toplam %d urun satisi yapildi.\n", dayName, numberOfProducts);

    return 0;
}