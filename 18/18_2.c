#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(void)
{
    char map1[52][52];
    char map2[52][52];
    char map3[52][52];
    int out[1000000][2] = {{0}};
    int out2[1000] = {0};

    for(int i=0;i<52;i++)
    {
        for(int j=0;j<52;j++)
        {
            map1[i][j]='0';
            map2[i][j]='0';
            map3[i][j]='0';
        }
    }

    for(int i=0;i<50;i++)
    {
        char s[BUFSIZ];
        if (fgets(s, 52, stdin) != NULL) //loop through input lines & create map
        {
            for(int j=0;j<50;j++)
            {
                map1[j+1][i+1]=s[j]; //leave single border of '0' around map for easier testing of surrounding squares
            }
        }

    }
    int t=0;
    int l=0;
    int chk=0;
    int period;
    int first;

    for(int m=0;m<1000000000;m++)  //part 2: insane amount of passes through..see maths below for checking for repeats
    {
 /*   system("clear"); //funky animations - uncomment for lagsational graphix!
    for(int i=0; i<52;i++)
    {
        for(int j=0; j<52; j++)
        {
            printf("%c",map1[j][i]);
        }
        printf("\n");
    }
    printf("\n"); */
        for(int i=1;i<52;i++) //rows
        {
            for(int j=1;j<52;j++) //cols
            {
                switch(map1[j][i])
                {
                    case('.'): //count trees around open spaces
                        t=0;
                        for(int x=i-1;x<i+2;x++)
                        {
                            for(int y=j-1;y<j+2;y++)
                            {
                                if(map1[y][x]=='|')
                                {
                                    t++;
                                }
                            }
                        }
                        if(t>2)
                        {
                            map2[j][i] = '|';
                        }
                        else
                        {
                            map2[j][i] = '.';
                        }
                        break;
                    case('|'): //count lumberyards around trees
                        l=0;
                        for(int x=i-1;x<i+2;x++)
                        {
                            for(int y=j-1;y<j+2;y++)
                            {
                                if(map1[y][x]=='#')
                                {
                                    l++;
                                }
                            }
                        }
                        if(l>2)
                        {
                            map2[j][i] = '#';
                        }
                        else
                        {
                            map2[j][i] = '|';
                        }
                        break;
                    case('#'): //count trees & lumberyards aroud lumberyard
                        t=0;
                        l=0;
                        for(int x=i-1;x<i+2;x++)
                        {
                            for(int y=j-1;y<j+2;y++)
                            {
                                if(map1[y][x]=='#')
                                {
                                    l++;
                                }
                                else if(map1[y][x]=='|')
                                {
                                    t++;
                                }
                            }
                        }
                        if((t>0) && (l>1))
                        {
                            map2[j][i] = '#';
                        }
                        else
                        {
                            map2[j][i] = '.';
                        }
                        break;

                }
            }

        }
        for(int i=0;i<52;i++)
        {
            for(int j=0;j<52;j++)
            {
                map1[i][j]=map2[i][j];
            }
        }
        t=0;
        l=0;
        int score=0;
        for(int i=0; i<52;i++) //count resource
        {
            for(int j=0; j<52; j++)
            {
                if(map1[i][j]=='|')
                {
                    t++;
                }
                else if(map1[i][j]=='#')
                {
                    l++;
                }
            }
        }
        score=t*l;


//here's where we do some math to predict score after 1,000,000,000th minute
        out2[m+1]=score; // store each score to start with
// debug        printf("%i - %i\n",m+1,score);
        if(out[score][0]==1) //waitaminnit, we've seen this score before...
        {
            if(chk==1) //OK 2 repeated values in a row must be more than co-incidence
            {
                printf("Part 2: %i\n",out2[((1000000000-first)%period)+first]); //calculate index of nth answer like: [(n-index of first value in repeat) % period between repeats] + first, and look it up from previously stored.
                return 0;
            }
            else // first time we've seen a repeat. Store some numbers to use in calculating the answer, flag it, and go around again to see if 2 in a row to make sure we're in repeated section
            {
                chk=1;
                first= out[score][1]; //where did we see this before?
                period = m+1-first; //how long ago?

            }
        }
        else //we haven't seen this score before. Flag it as seen and store it's index.
        {
            chk=0;
            out[score][0]=1;
            out[score][1]=m+1;
        }

    }
}