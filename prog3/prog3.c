#include <stdio.h>

/* Function to print bits of an integer */
void printBits(int n)
{
    for(int i = 31; i >= 0; i--)
    {
        printf("%d", (n >> i) & 1);

        if(i % 8 == 0)
            printf(" ");
    }

    printf("\n");
}

/* Function to count number of 1 bits */
int countBits(int n)
{
    int count = 0;

    while(n)
    {
        n = n & (n - 1);
        count++;
    }

    return count;
}

/* Function to check endian */
void checkEndian()
{
    int n = 1;

    char *ptr = (char *)&n;

    if(*ptr == 1)
        printf("System is Little Endian\n");
    else
        printf("System is Big Endian\n");
}

/* Function to print float bits */
void printFloatBits(float f)
{
    int *ptr = (int *)&f;

    for(int i = 31; i >= 0; i--)
    {
        printf("%d", (*ptr >> i) & 1);

        if(i == 31 || i == 23)
            printf(" ");
    }

    printf("\n");
}

/* Function to display memory bytes */
void displayBytes(int n)
{
    char *ptr = (char *)&n;

    printf("Memory bytes:\n");

    for(int i = 0; i < 4; i++)
    {
        printf("%x ", ptr[i]);
    }

    printf("\n");
}

int main()
{
    int n;
    float f;

    /* Integer input */
    printf("Enter an integer: ");
    scanf("%d", &n);

    printf("\nBits of integer:\n");
    printBits(n);

    printf("\nNumber of 1 bits = %d\n", countBits(n));

    /* Odd or Even */
    if(n & 1)
        printf("\n%d is Odd\n", n);
    else
        printf("\n%d is Even\n", n);

    /* Multiply and Divide */
    printf("\nMultiply by 2 = %d\n", n << 1);
    printf("Divide by 2 = %d\n", n >> 1);

    /* Endian */
    printf("\n");
    checkEndian();

    /* Memory bytes */
    printf("\n");
    displayBytes(n);

    /* Float input */
    printf("\nEnter a floating point number: ");
    scanf("%f", &f);

    printf("\nBits of floating point number:\n");
    printFloatBits(f);

    return 0;
}