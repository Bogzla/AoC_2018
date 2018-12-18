#include <stdio.h>
#include <stdlib.h>
// sure this should be done with 2x arrays in heap and pointers
//answer coming out too low, but OK for test input.. //solved - fgets length was one too low cutting of nul terminetor..
int main(void)
{
    char map1[52][52];
    char map2[52][52];
    char map3[52][52];

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

    for(int m=0;m<10;m++)  //print maps after each pass for fun
    {
    for(int i=0; i<52;i++)
    {
        for(int j=0; j<52; j++)
        {
            printf("%c",map1[j][i]);
        }
        printf("\n");
    }
    printf("\n");
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
    }

    t=0;
    l=0;
    for(int i=0; i<52;i++) //print final map and count resource
    {
        for(int j=0; j<52; j++)
        {
            printf("%c",map1[j][i]);
            if(map1[i][j]=='|')
            {
                t++;
            }
            else if(map1[i][j]=='#')
            {
                l++;
            }
        }
        printf("\n");
    }
    printf("Part 1: %i\n",t*l);
/*    printf("\n");
    for(int i=0; i<52;i++)
    {
        for(int j=0; j<52; j++)
        {
            printf("%c",map2[j][i]);
        }
        printf("\n");
    }
*/
}