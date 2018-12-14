//ToDo: figure out why they're not cornering properly

#include <stdio.h>
#include <stdlib.h>
//j=x, i=y, 0,0 is top left
int main(void)
{
    char track[150][150]; //replicate track
    int track2[150][150]; //track positions of carts
    int cart[18][4]; //cart # (start at 1) direction in x (-1, 0, 1), direction in y (-1, 0, 1), next switch direction (L=0), tick of last move
    int carts = 1;
    int tick = 1;
    for(int i=0;i<150;i++)
    {
        for(int j=0;j<150;j++)
        {
            track2[j][i] = 0;
        }
    }
    for(int i=0;i<150;i++)
    {
        char s[BUFSIZ];
        if (fgets(s, 155, stdin) != NULL) //loop through input lines, setup maps and carts
        {
            for(int j=0;j<150;j++)
            {
                char a = s[j];
//                printf("%c",a);
                switch(a)
                {
                    case('-'):
                    case('|'):
                    case('\\'):
                    case('/'):
                    case('+'):
                        track[j][i] = a;
                        break;
                    case('^'):
                        track[j][i] = '|';
                        cart[carts][0] = 0;
                        cart[carts][1] = -1;
                        cart[carts][2] = 0;
                        cart[carts][3] = 0;
                        track2[j][i] = carts;
                    //    printf("%i: %c %i,%i\n",carts,a,j,i);
                        carts++;
                        break;
                    case('>'):
                        track[j][i] = '-';
                        cart[carts][0] = 1;
                        cart[carts][1] = 0;
                        cart[carts][2] = 0;
                        cart[carts][3] = 0;
                        track2[j][i] = carts;
                    //    printf("%i: %c %i,%i\n",carts,a,j,i);
                        carts++;
                        break;
                    case('v'):
                        track[j][i] = '|';
                        cart[carts][0] = 0;
                        cart[carts][1] = 1;
                        cart[carts][2] = 0;
                        cart[carts][3] = 0;
                        track2[j][i] = carts;
                    //    printf("%i: %c %i,%i\n",carts,a,j,i);
                        carts++;
                        break;
                    case('<'):
                        track[j][i] = '-';
                        cart[carts][0] = -1;
                        cart[carts][1] = 0;
                        cart[carts][2] = 0;
                        cart[carts][3] = 0;
                        track2[j][i] = carts;
                    //    printf("%i: %c %i,%i\n",carts,a,j,i);
                        carts++;
                        break;
                }


            }
//            printf("\n");
        }
    }
    while(1)
    {
        for(int i=0;i<150;i++)
        {
            for(int j=0; j<150;j++)
            {
                int a = track2[j][i];
                if((a>0) && (cart[a][3]!=tick))
                {
                    track2[j][i] = 0; //remove from current
                    int jj=j+cart[a][0]; //this is new location
                    int ii=i+cart[a][1];
                    printf("%i: %i,%i -> %i,%i\n",a,j,i,jj,ii);
                    if(track2[jj][ii]>0) //collision
                    {
                        printf("Part 1: %i,%i\n",jj,ii);
                        return 0;
                    }
                    else
                    {
                        track2[jj][ii] = a; //put in new location
                        cart[a][3]++; //mark as moved
                        switch(track[jj][ii]) //and reset direction for next move
                        {
                            case('|'):
                            case('-'): //no direction change
                                break;
                            case('/'):
                                switch(cart[a][0])
                                {
                                    case(-1): //going left, switch to down
                                        cart[a][0]=0;
                                        cart[a][1]=1;
                                        break;
                                    case(1): //going right, switch to up
                                        cart[a][0]=0;
                                        cart[a][1]=-1;
                                        break;
                                }
                                switch(cart[a][1])
                                {
                                    case(-1): //going up, switch to right
                                        cart[a][0]=1;
                                        cart[a][1]=0;
                                        break;
                                    case(1): //going down, switch to left
                                        cart[a][0]=-1;
                                        cart[a][1]=0;
                                        break;
                                }
                                break;
                            case('\\'):
                                switch(cart[a][0])
                                {
                                    case(-1): //going left, switch to up
                                        cart[a][0]=0;
                                        cart[a][1]=-1;
                                        break;
                                    case(1): //going right, switch to down
                                        cart[a][0]=0;
                                        cart[a][1]=1;
                                        break;
                                }
                                switch(cart[a][1])
                                {
                                    case(-1): //going up, switch to left
                                        cart[a][0]=-1;
                                        cart[a][1]=0;
                                        break;
                                    case(1): //going down, switch to right
                                        cart[a][0]=1;
                                        cart[a][1]=0;
                                        break;
                                }
                                break;
                            case('+'):
                                switch(cart[a][2])
                                {
                                    case(1): //straight on
                                        cart[a][2]=2;
                                        break;
                                    case(0): //turn left
                                        switch(cart[a][0])
                                        {
                                            case(-1): //going left, switch to down
                                                cart[a][0]=0;
                                                cart[a][1]=1;
                                                break;
                                            case(1): //going right, switch to up
                                                cart[a][0]=0;
                                                cart[a][1]=-1;
                                                break;
                                        }
                                        switch(cart[a][1])
                                        {
                                            case(-1): //going up, switch to left
                                                cart[a][0]=-1;
                                                cart[a][1]=0;
                                                break;
                                            case(1): //going down, switch to right
                                                cart[a][0]=1;
                                                cart[a][1]=0;
                                                break;
                                        }
                                        cart[a][2]=1;
                                        break;
                                    case(2): //turn right, like European politics
                                        switch(cart[a][0])
                                        {
                                            case(-1): //going left, switch to up
                                                cart[a][0]=0;
                                                cart[a][1]=-1;
                                                break;
                                            case(1): //going right, switch to down
                                                cart[a][0]=0;
                                                cart[a][1]=1;
                                                break;
                                        }
                                        switch(cart[a][1])
                                        {
                                            case(-1): //going up, switch to right
                                                cart[a][0]=1;
                                                cart[a][1]=0;
                                                break;
                                            case(1): //going down, switch to left
                                                cart[a][0]=-1;
                                                cart[a][1]=0;
                                                break;
                                        }
                                        cart[a][2]=0;
                                        break;
                                }

                        }

                    }
                }
            }
        }
        tick++;
    }
}
