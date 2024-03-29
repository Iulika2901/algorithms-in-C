#include <stdio.h>
#include <stdlib.h>
#include "t12.h"

void calc(int s[], int len, long long unsigned  N)
{

    long long unsigned  sum=0,r=0;

    for (int i = 1; i < (1 << len); i++)
    {
        int sub[len];
        int dim_sub = 0;


        for (int j = 0; j < len; j++)
        {
            if (i & (1 << j))
            {
                if(sub[dim_sub-1]<=N)
                {
                    sub[dim_sub] = s[j];
                    dim_sub++;
                }

            }
        }

       long long unsigned result = 1;
        for (int j = 0; j < dim_sub; j++)
        {
            long long unsigned a = result;
            long long unsigned b = sub[j];
            while (b != 0)
            {
                long long unsigned temp = b;
                b = a % b;
                a = temp;
            }
            result = (result * sub[j]) / a;
        }


        if(dim_sub%2==1)
        {
            sum=sum+N/result;
        }
        else
        {
            sum=sum-N/result;
        }

    }
    printf("%llu\n",sum);
}
