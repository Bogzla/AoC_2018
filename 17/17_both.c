#include <stdio.h>
#include <stdlib.h>
#include <string.h>
const int MAX=1672; //input rows
//const int MAX=8;


// C substring function definition
// start counting at 0
void substr(char s[], char sub[], int p, int l)
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

int main(void)
{
    char map[2000][2000];
    int vein[MAX][4];
    int ymin = 500;
    int ymax = 500;
    int xmin = 500;
    int xmax = 500;
    for(int i=0;i<2000;i++)
    {
        for(int j=0;j<2000;j++)
        {
            map[i][j] = '.';
        }
    }
    for(int i=0;i<MAX;i++)
    {
        int x1=0;
        int x2=0;
        int y1=0;
        int y2=0;
        int dot;
        int len;
        int x;
        int y;
        char ss[5];
        char s[BUFSIZ];
        if (fgets(s, 25, stdin) != NULL) //loop through input lines, getting start / end coordinates of veins
        {
            for(int j=0;j<strlen(s);j++)
            {
                if(s[j]=='.')
                {
                    dot = j;
                }
                else if(s[j]=='y')
                {
                    y = j;
                }
                else if(s[j]=='x')
                {
                    x = j;
                }
            }
            len = strlen(s);
           // printf("%i %i %i %i\n",x,y,dot,len);

            if(x==0)
            {
                substr(s,ss,x+2,y-4);
                x1=atoi(ss);
                x2=atoi(ss);

                substr(s,ss,y+2,dot-y-3);
                y1=atoi(ss);

                substr(s,ss,dot+1,len+1-dot);
                y2=atoi(ss);
            }
            else if(y==0)
            {
                substr(s,ss,y+2,x-4);
                y1=atoi(ss);
                y2=atoi(ss);

                substr(s,ss,x+2,dot-x-3);
                x1=atoi(ss);

                substr(s,ss,dot+1,len+1-dot);
                x2=atoi(ss);
            }
            vein[i][0]=x1;
            vein[i][1]=x2;
            vein[i][2]=y1;
            vein[i][3]=y2;
//debug            printf("%i %i %i %i\n",x1,x2,y1,y2);
            if(y1<ymin)
            {
                ymin=y1; //find our min & max Y
            }
            if(y2>ymax)
            {
                ymax=y2;
            }
            if(y1>ymax)
            {
                ymax=y1;
            }
            if(x1<xmin)
            {
                xmin=x1; //find our min & max X
            }
            if(x2>xmax)
            {
                xmax=x2;
            }
            if(x1>xmax)
            {
                xmax=x1;
            }
        }

    }
//    printf("%i - %i\n",xmin,xmax);
  //  return 0;
    for(int k=0;k<MAX;k++)
    {
        for(int i=vein[k][0]; i<vein[k][1]+1;i++)
        {
            for(int j=vein[k][2]; j<vein[k][3]+1;j++)
            {
                map[i][j] = '#'; //add veins to the map
            }
        }
    }
    map[500][ymin-1]='|';
    for(int m=0; m<20000; m++)
    {
        for(int j=ymin; j<ymax+1; j++)
        {
            for(int i=xmin-1; i<xmax+2; i++)
            {
                if(map[i][j]=='.') //loop through testing where water should be
                {
                    if(map[i][j-1]=='|') //under downfall
                    {
                        map[i][j] = '|';
                    }
                    else if(((map[i-1][j]=='|') && ((map[i-1][j+1]=='#') || (map[i-1][j+1]=='~'))) || ((map[i+1][j]=='|') && ((map[i+1][j+1]=='#') || (map[i+1][j+1]=='~')))) //next to downfall contacting vein or pooled water
                    {
                        map[i][j] = '|';
                    }
                }
                else if(map[i][j]=='|') //downfalls bordered at 2 ends by veins turn to pooled water
                {
                    int x1=0;  //this code is very non-optimised
                    int x2=0;
                    int ctr=i;
                    while(map[ctr][j]=='|')
                    {
                        if(map[ctr-1][j]=='#')
                        {
                            x1=ctr;
                        }
                        ctr--;
                    }
                    ctr=i;
                    while(map[ctr][j]=='|')
                    {
                        if(map[ctr+1][j]=='#')
                        {
                            x2=ctr;
                        }
                        ctr++;
                    }
                    if((x1>0) && (x2>0))
                    {
                        for(int n=x1; n<x2+1; n++)
                        {
                            map[n][j] = '~';
                        }
                    }
                }

            }
        }
    }

    //debug
    for(int j=0;j<ymax+1;j++)
//    for(int j=0;j<500;j++)
    {
        for(int i=xmin-1;i<xmax+2;i++) //make a pretty picture
        {
            printf("%c",map[i][j]);
        }
        printf("\n");
    }
    int pt1=0;
    int pt2=0;
    for(int i=0;i<2000;i++)
    {
        for(int j=ymin; j<ymax+1; j++) //and count up downfall / pooled water tiles
        {
            if(map[i][j] == '~')
            {
                pt1++;
                pt2++;
               // printf("%i,%i\n",i,j);
            }
            else if(map[i][j] == '|')
            {
                pt1++;
            }
        }
    }
    printf("Part 1: %i\nPart 2: %i\n",pt1,pt2);


}