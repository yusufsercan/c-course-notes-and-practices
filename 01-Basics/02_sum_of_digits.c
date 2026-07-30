#include <stdio.h>
#include <stdlib.h> // Required for abs() function

/*
 * Task: Calculate the sum of digits of any given integer using a loop.
 * Concepts: Dynamic loop execution (while), modulo operator (%), and integer division (/=).
 */

int main() 
{
    int myNumber, tempNumber, sum = 0;

    printf("Enter an integer number: ");
    scanf("%d", &myNumber);

    // Handle negative numbers by taking absolute value
    tempNumber = abs(myNumber); 

    // Extract each digit from right to left until tempNumber becomes 0
    while (tempNumber > 0) 
    {
        sum += tempNumber % 10;  // Extract the last digit and add to sum
        tempNumber /= 10;        // Remove the last digit
    }

    printf("The sum of the digits of %d: %d\n", myNumber, sum);

    return 0;
}