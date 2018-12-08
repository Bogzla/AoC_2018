#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void substring(char s[], char sub[], int p, int l);

int main(void)
{
    int grid[400][400]; //grid
    for(int k=0; k<50; k++)
    {
        int x=0;
        int y=0;
        char s[BUFSIZ];
        if (fgets(s, 8, stdin) != NULL) //loop through input and put coords into grid, numbered 1 to 50
        {
            for(int i=0; i<strlen(s)+1;i++)
            {
                if(s[i]==',')
                substring(s,x,0,i);
                substring(s,y,i+2,strlen(s)-i-2;
            }
            grid[x][y]=i+1;
        }
    }

    for(int x=0; x<400; x++) //go through each position in grid
    {
        for(int y=0; y<400; y++)
        {
            if(grid[x],[y]>0) //skip coords
            {
            }
            else //check increasing 'manhattan rings' for coords
            {
                int flag = 999;
                int i = 1;
                while(flag==999)
                {
                    for(X=0; X<i+1; X++) // find valid points in this ring
                    {
                        for(Y=0;Y<i+1; Y++)
                        {
                            if(Y+X==i) //4 points to check ToDo - this will end up checking points more than once if one co-ord is zero though. need to refine.
                            {
                                int xx=x-X;
                                int yy=y-Y;
                                if((xx<0)||(yy<0)) //outside lower bounds
                                {
                                }
                                else
                                {
                                    if((grid[xx][yy]>0)&&(grid[xx][yy]<51))
                                    {
                                        if(grid[x][y]>0)
                                        {
                                            grid[x][y] = 999;
                                            // ToDo then we are done with this x,y - need to break out
                                        }
                                        else
                                        {
                                            grid[x][y] = grid[xx][yy]+100;
                                        }
                                    }
                                }
                                if(X!=0)
                                {
                                    xx=x+X;
                                    yy=y-Y;
                                    if((xx>399)||(yy<0))
                                    {
                                    }
                                    else
                                    {
                                        if((grid[xx][yy]>0)&&(grid[xx][yy]<51))
                                        {
                                            if(grid[x][y]>0)
                                            {
                                                grid[x][y] = 999;
                                                // ToDo then we are done with this x,y - need to break out
                                            }
                                        }
                                        else
                                        {
                                            grid[x][y] = grid[xx][yy]+100;
                                        }
                                    }
                                }
                                if(Y!=0)
                                {
                                    xx=x+X;
                                    yy=y+Y;
                                    if((yy>399)||(xx>399))
                                    {
                                    }
                                    else
                                    {
                                        if((grid[xx][yy]>0)&&(grid[xx][yy]<51))
                                        {
                                            if(grid[x][y]>0)
                                            {
                                                grid[x][y] = 999;
                                                // ToDo then we are done with this x,y - need to break out
                                            }
                                        }
                                        else
                                        {
                                            grid[x][y] = grid[xx][yy]+100;
                                        }
                                    }
                                }
                                if((X!=0)&&(Y!=0))
                                {
                                    xx=x-X;
                                    yy=y+Y;
                                    if((xx<0)||(yy>399))
                                    {
                                    }
                                    else
                                    {
                                        if((grid[xx][yy]>0)&&(grid[xx][yy]<51))
                                        {
                                            if(grid[x][y]>0)
                                            {
                                                grid[x][y] = 999;
                                                // ToDo then we are done with this x,y - need to break out
                                            }
                                        }
                                        else
                                        {
                                            grid[x][y] = grid[xx][yy]+100;
                                        }
                                    }
                                }
                            }
                        }
                    }
                    //ToDo test if single nearest was found in this ring and break out if so
                    i++;
                }
            }
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