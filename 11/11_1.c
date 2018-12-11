#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void)
{
    int serial=5177;
//test    int serial = 71;
    int cells[300][300];
    int highestx=0;
    int highesty=0;
    int highestscore=0;
//test    int i=100;
//test    int j=152;
    for(int i=0;i<300;i++) //calculate power levels according to da formula
    {
        for(int j=0;j<300;j++)
        {
            int x=i+1;
            int y=j+1;
            int ID = x+10;
            int lvl = ((ID*y)+serial)*ID;
            int hdrs = (int)(floor(lvl/100)) % 10;
            lvl = hdrs - 5;
//test            printf("%i\n",lvl);
            cells[i][j]=lvl;
        }
    }
    for(int i=0; i<298; i++) //calculate 3x3 region with highest level
    {
        for(int j=0; j<298; j++)
        {
            int score = 0;
            for(int ii=0; ii<3; ii++)
            {
                for(int jj=0; jj<3; jj++)
                {
                    score += cells[i+ii][j+jj];
                }
            }
            if(score>highestscore)
            {
                highestscore = score;
                highestx = i+1;
                highesty = j+1;
            }
        }
    }
    printf("Part 1: %i,%i\n",highestx,highesty);

}