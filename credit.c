#include <cs50.h>
#include <stdio.h>

int main(void)
{
    long number = get_long("Number: ");
    long digit, digit_count = 0, temp, starting_digits, sum_double, sum_single, checksum = 0;

    temp = number;
    while (temp > 0)
    {
        temp /= 10;
        digit_count++;
    }

    if (digit_count != 16 && digit_count != 15 && digit_count != 13)
    {
        printf("INVALID\n");
        return 0;
    }
    long divisor = 1;
    for (int i = 1; i <= digit_count - 2; i++)
    {
        divisor *= 10;
    }
    starting_digits = number / divisor;

    long max_value = 1;
    for (long i = 0; i < digit_count; i++)
    {
        max_value *= 10;
    }
    for (long i = 1; i < max_value;)
    {
        digit = ((number / 10) / i) % 10;
        i *= 100;
        sum_double = digit * 2;
        if (sum_double > 9)
        {
            sum_double = (sum_double / 10) + (sum_double % 10);
        }
        checksum += sum_double;
    }

    for (long i = 1; i < max_value;)
    {
        digit = (number / i) % 10;
        i *= 100;
        sum_single = digit;
        checksum += sum_single;
    }

    if (checksum % 10 == 0)
    {
        if ((starting_digits == 34 || starting_digits == 37) && digit_count == 15)
        {
            printf("AMEX\n");
            return 0;
        }
        else if ((starting_digits == 51 || starting_digits == 52 || starting_digits == 53 ||
                  starting_digits == 54 || starting_digits == 55) &&
                 digit_count == 16)
        {
            printf("MASTERCARD\n");
            return 0;
        }
        else if (starting_digits / 10 == 4 && (digit_count == 13 || digit_count == 16))
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}
