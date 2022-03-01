#include <cs50.h>
#include <stdio.h>
#include <math.h>


int main (void)
{

    int length = 0;
    
    long number = get_long("Number: ");
    long n = number;
    
    //find length of number
    do
    {
        n /= 10;
        length++;
    }
    while (n != 0);

    //printf ("Length: %i\n", length);   
    
    //checksum
    n = number; 
    int sum = 0;
    for (int i = 0; i < length / 2; i++)
    {
        //  printf("every other digit: %li ", n % 100 / 10);
        int x = 2 * (n % 100 / 10);
        // printf("every other digit times 2: %i\n", x);
        
        //sum of digits times 2
        if (x >= 10)
        {
            sum += x / 10 + x % 10;
        }
        else
        {
            sum += x;
        }
        n = n / 100;
    //printf("Sum: %i\n", sum);
    }
    
    n = number;
    while (n > 0)
    {
        //printf("every digits that weren't multiplied by 2: %li\n", n % 10);
        //sum of remaining digits
        sum += n % 10;
    
        n = n / 100;
    }
    
    //printf("Sum: %i\n", sum);
    
    if (sum % 10 == 0)
    {
        //check sum pass 
        if (length == 15 && (number / 10000000000000 == 34 || number / 10000000000000 == 37) )
        {
            printf("AMEX\n");
        }
        else if (length == 16 && (number / 100000000000000 >= 51 && number / 100000000000000 <= 55))
        {
            printf("MASTERCARD\n");
        }    
        else if ((length == 13 && (number / 1000000000000 == 4)) || (length == 16 && (number / 1000000000000000 == 4)))
        {
            printf("VISA\n");
        } 
        else 
        {
            printf("INVALID\n");
        }
    }
    else{
        printf("INVALID\n");
    }

//printf ("first 2 digit: %li\n", number / 100000000000000);

    //1. every other digit from 2nd last 

//    printf("2nd last digit: %li\n", (number % 100) / 10);
//    printf("4th last digit: %li\n", (number % 10000) / 1000);

}


