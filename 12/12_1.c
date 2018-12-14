#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//todo this needs to be extended to consider more empty pots to left and right, then sum the indeces of all non empty pots based on initial 0
int main(void)
{
    char pots[104];
    char pots2[104];
    char combos[13][6];
    strcpy(pots,"..#..####.##..#.##.#..#.....##..#.###.#..###....##.##.#.#....#.##.####.#..##.###.#.......#.............."); //expanded to include 2x '.' at each end
    strcpy(combos[0],".#.#.\0");
    strcpy(combos[1],"#.###\0");
    strcpy(combos[2],"####.\0");
    strcpy(combos[3],"...##\0");
    strcpy(combos[4],"..###\0");
    strcpy(combos[5],"#.#.#\0");
    strcpy(combos[6],"###.#\0");
    strcpy(combos[7],"#...#\0");
    strcpy(combos[8],".##..\0");
    strcpy(combos[9],".#...\0");
    strcpy(combos[10],".##.#\0");
    strcpy(combos[11],"#####\0");
    strcpy(combos[12],"..#..\0");

    for(int j=0;j<20;j++)
    {
        pots2[0] = '.';
        pots2[1] = '.';
        pots2[102] = '.';
        pots2[103] = '.';
        for(int i=2;i<102;i++)
        {
            char sample[6];
            sample[0] = pots[i-2];
            sample[1] = pots[i-1];
            sample[2] = pots[i];
            sample[3] = pots[i+1];
            sample[4] = pots[i+2];
            sample[5] = '\0';

            pots2[i] = '.';
            for(int k=0;k<13;k++)
            {
//                printf("%s - %s\n",sample,combos[k]);
                if(strcmp(sample,combos[k])==0)
                {
//                    printf("match\n");
                    pots2[i] = '#';
                    break;
                }
            }
        }
//        printf("\n");
        strcpy(pots,pots2);

    }
    int ctr=0;
    for(int i = 2;i<102;i++)
    {
        if(pots[i]=='#')
        {
            ctr++;
        }
    }
    printf("%i\n",ctr);
}