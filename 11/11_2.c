#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void)
{
    int serial=5177;
    int cells[300][300];
    int highestx=0;
    int highesty=0;
    int highestscore=0;
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
            cells[i][j]=lvl;
        }
    }
    //part 2 check for any size square 1x1 to 300x300. very slow brute force. Thank fuck it wasn't rectangles.
    int highestk=0;
    for(int k=1; k<301; k++)
    {
        int max = 301-k;
        for(int i=0; i<max; i++) //calculate region with highest level
        {
            for(int j=0; j<max; j++)
            {
                int score = 0;
                for(int ii=0; ii<k; ii++)
                {
                    for(int jj=0; jj<k; jj++)
                    {
                        score += cells[i+ii][j+jj];
                    }
                }
                if(score>highestscore)
                {
                    highestscore = score;
                    highestx = i+1;
                    highesty = j+1;
                    highestk = k;
                }
            }
        }
        printf("%i,%i,%i\n",highestx,highesty,highestk); //monitor answer as we go
    }
    printf("Part 2: %i,%i,%i\n",highestx,highesty,highestk);

}