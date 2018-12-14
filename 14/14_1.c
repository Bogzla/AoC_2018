#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void)
{
    int c1=0;
    int c2=1;
    int n=2;
    int* rec = malloc(420000*sizeof(int));
    rec[0]=3;
    rec[1]=7;
    int inp=209231;
    for(int i=0;i<209250;i++)
    {
        int j=rec[c1] + rec[c2];
        if(j>9)
        {
            rec[n]=(int)(floor(j/10));
            n++;
        }
        rec[n]=j%10;
        n++;
        c1=(c1+rec[c1]+1)%n;
        c2=(c2+rec[c2]+1)%n;
        if(n==inp+10)
        {
            printf("Part 1: ");
            for(int k=0;k<10;k++)
            {
                printf("%i",rec[k+inp]);
            }
            printf("\n");
            free(rec);
            return 0;
        }
    }

}