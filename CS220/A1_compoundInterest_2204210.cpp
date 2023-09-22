#include <stdio.h>
int main()
{
    /*
    Name: Atharva Keny
    Roll No: 2204210
    Date: 29th July, 2023.
    Purpose: To calculate amount accumulated in 3 years using compound interest formula
    */


    float principal, rate_of_interest;
    // to input principal amount as floating variable
    scanf("%f", &principal);
    // to input rate of interest as a floating variable
    scanf("%f", &rate_of_interest);
    // calculating the amount accumulated in 3 years
    float amount = principal * (1 + rate_of_interest) * (1 + rate_of_interest) * (1 + rate_of_interest);
    // display amount accumulated in 3 years
    printf("Amount accumulated after 3 years = %f", amount);
}