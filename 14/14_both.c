#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void)
{
    int c1=0; //Elf 1 current
    int c2=1; //Elf 2 current
    int n=2; //# recipes stored
    int* rec = malloc(200000000*sizeof(int)); //allocate memory for recipes
    rec[0]=3; //initial state
    rec[1]=7;
    int inp=209231; //input formatted for part 1
    int inp2[6] = {2,0,9,2,3,1}; //input formatted for part 2
    for(int i=0;i<100000000;i++)
    {
        int addct=0; //count of recipes added this turn (needed for part 2)
        int j=rec[c1] + rec[c2];
        if(j>9)
        {
            rec[n]=(int)(floor(j/10)); // add recipe for 10s digit
            addct++;
            n++;
        }
        rec[n]=j%10; //add recipe for 1s digit
        addct++;
        n++;
        c1=(c1+rec[c1]+1)%n; // update current recipe. Use mod to loop.
        c2=(c2+rec[c2]+1)%n;
        if(n==inp+10) // part 1 solution found after # iterations in input plus 10
        {
            printf("Part 1: ");
            for(int k=0;k<10;k++)
            {
                printf("%i",rec[k+inp]);
            }
            printf("\n");
        }
        if(n>7) // for part 2, check recently added recipes for match to input
        {
            for(int l=-1;l<addct-1;l++) // up to 2 recipes can be added per iteration so check back one position too if needed
            {
                int score=0;
                for(int k=0;k<6;k++)
                {
                    if(rec[n-6+k+l]!=inp2[k]) //stop checking at first mismatched digit
                    {
                        break;
                    }
                    else
                    {
                        score++;
                    }
                }
                if(score==6) //when all 6 digits match answer is found
                {
                    printf("Part 2: %i\n",n-6+l);
                    free(rec); //free up memory when done
                    return 0;
                }
            }
        }
    }
    free(rec);
}