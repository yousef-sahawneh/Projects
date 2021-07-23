#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    // To get the number
    long n = get_long("Number:");
    long original = n;
    
    // sum in which we will add things
    long sum = 0;
    
    //loop to add the individuale digits starting with second last
    for (long i = 100; i <= (n * 100); i *= 100)
    {
        long x = n % i;                 //recieve remainder
        x = x / (i / 10);               // seperate reminder into one digit
        x = x * 2;                      // multiply it by two
        if (x >= 10)                    // if two digits, need to divide them and add them seperatly
        {
            long z = x % 10;            
            long y = x / 10;
            sum += z;
            sum += y;
        }
        else                            // otherwise, just add it normally
        {
            sum += x;
        }
    }
    
    // add the single digits starting with last digit
    for (long i = 10; i <= (n * 100); i *= 100)     
    {
        long x = n % i;
        x = x / (i / 10);
        sum += x;
    }
    
    // if sume does not end with 0, it is invalid
    if ((sum % 10) != 0)
    {
        printf("INVALID\n");
        return 0;
    }
    
    // count the number of digits (divide by 10 until it equals 0 and count how many time it did that)
    long counter = 0;
    for (long i = 0; n != 0; i++)
    {
        n = n / 10;
        counter += 1;
    }
    
    
    // to get the first two digit numbers
    long two = pow(10, (counter - 2));
    long one = pow(10, (counter - 1));
    long z = original / two;
    long w = original / one;
    
    // rules to match the right number with the right kind of card
    if (counter == 15 && (z == 43 || z == 37))
    {
        printf("AMEX\n");
    }
    else if (counter == 16 && (z == 51 || z == 52 || z == 53 || z == 54 || z == 55))
    {
        printf("MASTERCARD\n");
    }
    else if ((counter == 13 || counter == 16) && w == 4)
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }
    
}
