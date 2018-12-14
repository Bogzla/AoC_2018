#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void)
{
    int c1=0;
    int c2=1;
    int n=2;
    int* rec = malloc(200000000*sizeof(int));
    rec[0]=3;
    rec[1]=7;
    int inp=209231;
    int inp2[6] = {2,0,9,2,3,1};
    for(int i=0;i<100000000;i++)
    {
        int addct=0;
        int j=rec[c1] + rec[c2];
        if(j>9)
        {
            rec[n]=(int)(floor(j/10));
            addct++;
            n++;
        }
        rec[n]=j%10;
        addct++;
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
        }
        if(n>7)
        {
            for(int l=-1;l<addct-1;l++)
            {
                int score=0;
                for(int k=0;k<6;k++)
                {
                    if(rec[n-6+k+l]!=inp2[k])
                    {
                        break;
                    }
                    else
                    {
                        score++;
                    }
                }
                if(score==6)
                {
                    printf("Part 2: %i\n",n-6+l);
                    free(rec);
                    return 0;
                }
            }
        }
    }
    free(rec);
}