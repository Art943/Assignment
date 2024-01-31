#include <stdio.h>
#include <stdint.h>
#include <limits.h>
#include <math.h>

void primegenerator(void)
{
    
    unsigned int low, high, flag;
    printf("Enter two numbers(intervals): ");
    scanf("%d %d", &low, &high);
    printf("Prime numbers between %d and %d are: %d \n", low, high);

    while (low <= high)
    {
        flag = 0;
        //printf("%d", low);

        if (low <= 1)
        {
            ++low;
            continue;
        }

        for (int i = 2; i < low; ++i)
        {

            if (low % i == 0)
            {
                flag = 1;
                break;
            }
        }

        if (flag == 0)
        {
            printf("%d ", low);
        }

        ++low;
    }
}

void main(void)
{
    primegenerator();
}