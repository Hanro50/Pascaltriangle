#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main()
{
    int rows, i, i2,i3,i4; //counters
    double n, k, z, x, y; //doubles are garanteed to be 64 bit numbers
    long long int f; //recommend 64 bit ints here if possible, system is buggy

    printf("Input number of rows: "); //gets the input to set the whole thing in motion
    scanf("%d", &rows);
    rows=rows;
    printf("\npreparing to calculate spacing...\n");

    //setting up spacing
    n  =1;
    z  =1;
    k  =1;
    x  =1;
    y  =1;
    i  =rows;
    i2 =(rows+1)/2;
    i3 =1;
    printf("calculating spacing...\n");
    printf("N...");
    for (i3=1;i3<=i;++i3) //Determines the factorial of N
    {
        n *=i3;
    }
    printf("K...");
    for (i3=1;i3<=i2;++i3) //Determines the factorial of K
    {
        k *=i3;
    }
    printf("Z...");
    for (i3=1;i3<=(i-i2);++i3) //Determines the factorial of N-K
    {
        z *=i3;
    }
    f=n/(k*z);
    if (f<=0) //Catches an overflow before it makes it down to the spacer rutine
    {
        printf("\nError Integer overflow!");
        printf("F: %d \n"  , f);
        printf("N: %g \n"  , n);
        printf("K: %g \n"  , k);
        printf("Z: %g \n"  , z);
        printf("KZ: %g\n"  , z*k);
        return 0;
    }
    n=1;
    printf("Getting y...\n");
    while (x<f) //Spacer rutine for making it look nice
    {
        x*=10;
        n+=0.5;
    }
    y=x;
    i4=n;
    if (i4 == n) //Even numbered spaces cause problems with alignment...
    {
        y*=10;
    }
    //printf("Y: %g \n"  , y);
    printf("Generating triangle...\n");
    for (i=0;i<rows;++i)
    {
        printf("\n%d\t", i+1);
        n=1;
        for (i2=i;(i2)<(rows);++i2) //Spacer rutine, places 4 spaces to make the perimid shape
        {
            for (i3=1; (i3)<=(i4); ++i3) //i4 is generated earlier
            {
                printf(" ");
            }
        }
        for (i3=1;i3<=i;++i3) //Determines the factorial of N
        {
            n *=i3;
        }

        for (i2=0;i2<(i+1);++i2) //The rutine for generating 1 whole row
        {
            z  =1;
            k  =1;
            for (i3=1;i3<=i2;++i3) //Determines the factorial of K
            {
                k *=i3;
            }
            for (i3=1;i3<=(i-i2);++i3) //Determines the factorial of N-K
            {
                z *=i3;
            }
            f=n/(k*z);
            //printf("%d (%d,%d,%d)", f, n, k, z );
            x=y;
            printf("%d", f);
            if (f<=0) //Catches an overflow before it makes it down to the spacer rutine
            {
                printf("\n Error Integer overflow");
                printf("F: %d \n"  , f);
                printf("N: %g \n"  , n);
                printf("K: %g \n"  , k);
                printf("Z: %g \n"  , z);
                printf("KZ: %g\n"  , z*k);
                return 0;
            }
            while (x>f) //Spacer rutine for making it look nice
            {
                x/=10;
                printf(" ");
            }

        }

    }
    return 0;
}
