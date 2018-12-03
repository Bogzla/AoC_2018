//USAGE ./01_2 < 01.txt
//this would be better with better data structure (trie?) as lookup reaches ~133,000 entries

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
const int MAX = 953;

int main(void)
{
    int i = 0;
    int j[MAX];
    for(int i2 = 0; i2 < MAX; i2++)
    {
        char s[BUFSIZ];
        if (fgets(s, 20, stdin) != NULL) //loop through lines and place in array
        {
            j[i2] = atoi(s);
        }
    }
    int j2[1000000]; //frequency storage
    int i3=0;
    j2[0] = 0; //initial frequency
    while(1)
    {
        for(int i2 = 0; i2 < MAX; i2++)
        {
            i+=j[i2]; //loop through array & change frequency
            for(int i4=0;i4<i3+1;i4++) //check frequency against previous, report & break out when duplicate found
            {
                if(i==j2[i4])
                {
                    printf("%i\n",i);
                    return 0;
                }
            }
            //wasn't in list so add it
            i3++;
            j2[i3] = i;
        }
    }
}