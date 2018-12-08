#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(void)
{
    int steps[26][3]; //each step stored as [ascii value]-65, with |Exists|Unavailable|Complete| flags
    int remain=0; //how many steps left to do
    char ins[101][50]; //store instructions
    int insct=101; //instruction count
    int step;
    for(int i=0;i<26;i++)
    {
        steps[i][0] = 0;
        steps[i][1] = 0;
        steps[i][2] = 0;
    }
    for(int i=0; i<insct;i++)
    {
        char s[BUFSIZ];
        if (fgets(s, 50, stdin) != NULL) //loop through input, put exists / unavailable flags into steps & count existing steps
        {
            strcpy(ins[i],s);
            int l=(int)ins[i][5]-65;
            int r=(int)ins[i][36]-65;
            if(steps[l][0]==0)
            {
                steps[l][0]=1;
                remain++;
            }
            if(steps[r][0]==0)
            {
                steps[r][0]=1;
                remain++;
            }
            steps[r][1]=1;
        }

    }
    //find next available step and do it
    printf("Part 1: ");
    for(int j=0;j<remain;j++)
    {
        step=27; //find next step to take
        for(int i=0;i<26;i++)
        {
           // printf("%i %i %i %i\n",i,steps[i][0], steps[i][1], steps[i][2]);
            if((steps[i][0]==1)&&(steps[i][1]==0)&&(steps[i][2]==0)&&(i<step))
            {
                step=i;
            }
        }
        printf("%c",(char)(step+65)); //report it
        steps[step][2]=1; //complete it
        //find next step
        for(int k=0;k<26;k++) //for every step
        {
            int avail = 1;
            for(int m=0;m<insct;m++) //loop through and find relevant instructions
            {
                int l=(int)ins[m][5]-65;
                int r=(int)ins[m][36]-65;
                if(r==k) //relevant instruction
                {
                    if(steps[l][2]==0) //prerequisite step not complete
                    {
                        avail = 0;  //this step is not available yet
                    }
                }
            }
            // update availability
            if(avail == 1)
            {
                steps[k][1]=0;
            }
        }
       // return 0;
    }
    printf("\n");
}