//usage ./03_2.c < 03.txt
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void substring(char s[], char sub[], int p, int l);

int main(void)
{
    int fabric[1200][1200]; //note this is about the largest a static array can be, bigger causes seg faults
    int claim[1349][4]; //store input for part 2
    int x = 0; //curser x
    int y = 0; //curser y
    int w = 0; // cut width (in x)
    int h = 0; //cut height (in y)
    int d = 0; // #squares duplicated
    //string processing
    int at;
    int comma;
    int colon;
    int mult;

    for(int k = 0; k< 1349; k++)
    {
        char s[BUFSIZ];
        if (fgets(s, 25, stdin) != NULL) //loop through lines
        {
            for(int i2=0; i2 < 25; i2++) //process string to get measurements
            {
                switch(s[i2])
                {
                    case '@':
                        at = i2;
                        break;
                    case ',':
                        comma = i2;
                        break;
                    case ':':
                        colon = i2;
                        break;
                    case 'x':
                        mult = i2;
                        break;
                }
            }
            char ss[5];
            substring(s,ss,at + 2, comma - at - 2);
            x = atoi(ss);
            claim[k][0] = x;
            substring(s,ss,comma + 1, colon - comma - 1);
            y = atoi(ss);
            claim[k][1] = y;
            substring(s,ss,colon + 2, mult - colon - 2);
            w = atoi(ss);
            claim[k][2] = w;
            substring(s,ss,mult + 1, strlen(s) - mult - 1);
            h = atoi(ss);
            claim[k][3] = h;
         //   printf("%i %i %i %i\n",x,y,w,h);  //debugging

            // draw on fabric
            for(int i = 0; i < w; i++)
            {
                for(int j = 0; j < h; j++)
                {
                    fabric[x+i][y+j]++;
                    if(fabric[x+i][y+j] == 2) //count the first time a square is duplicated
                    {
                        d++;
                    }
                }
            }
        }
        else
        {
            break;
        }
    }
    printf("Part one: %i\n",d);

//part two, run through again, but look at marked up pattern and report claim that has all ones on the fabric
    for(int k = 0; k< 1349; k++)
    {
        // look at claim area of fabric
        d=1;
        for(int i = 0; i < claim[k][2]; i++)
        {
            for(int j = 0; j < claim[k][3]; j++)
            {
                if(fabric[claim[k][0]+i][claim[k][1]+j] != 1) //check for unused or duplicate squares
                {
                    d=0;
                }
            }
        }
        if(d==1) //no unused or duplicate squares encountered: this is the winning claim
        {
            printf("Part two: %i\n", k+1);
            return 0;
        }

    }
}

// C substring function definition
// start counting at 0
void substring(char s[], char sub[], int p, int l)
{
    int sl = strlen(s);
    if (p > sl - 1)
    {
        exit(1);
    }
    else if (l > sl - p)
    {
        l = sl - p;
    }
    int c = 0;

    while (c < l)
    {
      sub[c] = s[p+c];
      c++;
    }
    sub[c] = '\0';
}