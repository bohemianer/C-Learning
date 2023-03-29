#include <stdio.h>
int sj = 0;
int si = 0;
int sk = 0;

int n = 5;
int main()
{
    for (int i = 0; i < n; i++)
    {
        si++;
        for(int j = 0; j < i; j++)
        {
            sj++;
            for(int k = 0; k < j; k++)
            {
                sk++;
            }
        }
    }
    printf("si:%d sj:%d sk:%d", si, sj, sk);

}

   
