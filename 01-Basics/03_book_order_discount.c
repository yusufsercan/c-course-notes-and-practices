#include <stdio.h>

/*
 * Task: Calculate book order total with quantity-based tier discounts.
 * Concepts: Conditional statements (if-else ladder), basic arithmetic, float formatting.
 */
// The discount logic will continue as follows: quantity >= 60, 30% discount / 30 < quantity < 60, 20% discount / 10 < quantity < 30, 12% discount / quantity < 10, 0.01% discount.
int main() 
{
    // Hardcoded unit price for a single book
    const int bookPrice = 20; 
    
    int orderQuantity = 0;
    float discountRate = 0.0;
    float nodiscountPrice, discountPrice, sum;

    printf("Kac adet kitap siparis etmek istiyorsunuz: ");
    scanf("%d", &orderQuantity);

    // Input validation: Negative order protection
    if (orderQuantity < 0) 
    {
        printf("Hata: Gecersiz siparis miktari!\n");
        return 1; // Terminate program with error code
    }

    // Determine discount rate based on order quantity
    if (orderQuantity >= 60) 
    {
        discountRate = 0.30; // 30% discount
    } 
    else if (orderQuantity >= 30) 
    {
        discountRate = 0.20; // 20% discount
    } 
    else if (orderQuantity >= 10) 
    {
        discountRate = 0.12; // 12% discount
    } 
    else 
    {
        discountRate = 0.01; // 1% discount
    }

    // Calculations
    nodiscountPrice = orderQuantity * bookPrice;
    discountPrice = nodiscountPrice * discountRate;
    sum = nodiscountPrice - discountPrice;

    // Output with formatted floating point values (2 decimal places)
    printf("\n--- Siparis Ozeti ---\n");
    printf("Kitabin indirimsiz fiyati : %.2f TL\n", nodiscountPrice);
    printf("Indirim tutariniz         : %.2f TL (%%%.0f indirim)\n", discountPrice, discountRate * 100);
    printf("Siparislerinizin toplami  : %.2f TL\n", sum);

    return 0;
}