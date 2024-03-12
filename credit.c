#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Checks credit card company using first 1 or 2 digits and the length of the number
// Checks credit card validity using Luhn's algorithm

bool check(long card);

int main(void)
{
    long card = get_long("enter card number: ");
    // check if propper number
    int test = card / 1000000000000;
    string type = "INVALID\n";         // sets invalid default incase no if condition is true
    if (test == 4 || test / 1000 == 4) // VISA
    {
        type = "VISA\n";
    }
    else if (test / 10 == 34 || test / 10 == 37) // AMEX
    {
        type = "AMEX\n";
    }
    else if ((test / 100 >= 51) && (test / 100 <= 55)) // MASTERCARD
    {
        type = "MASTERCARD\n";
    }
    if (check(card) && strcmp(type, "INVALID\n") != 0)
    {
        printf("%s", type);
    }
    else
    {
        printf("INVALID\n");
    }
}

bool check(long card)
{
    long i = 10;
    int evens = 0;
    do
    {
        int num = 2 * ((card % (10 * i)) / i);
        evens += num % 10;
        evens += num / 10;
        i *= 100;
    }
    while (card / i != 0);
    card *= 10;
    i = 10;
    int odds = 0;
    do
    {
        int num = ((card % (10 * i)) / i);
        odds += num;
        i *= 100;
    }
    while (card / i != 0);
    if ((odds + evens) % 10 == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
