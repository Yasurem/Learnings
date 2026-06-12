#include <stdio.h>

int main(void)
{
    float ft, in, cm, m;

    printf("Input feet: ");
    scanf("%f", &ft);

    // Convert to inches
    in = ft * 12;
    cm = in * 2.54;
    m = cm / 100;

    // Print
    printf("THE OUTPUTS SHOULD HAVE BEEN:\nFeet: %.2f\nInches: %.2f\nCentimeters: %.2f\nMeters: %.2f", ft, in, cm, m);
    return 0;
}