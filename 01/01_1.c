//USAGE ./01_1 < 01.txt

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
const int MAX = 1000;

int main(void)
{

int i = 0;
for(int i2 = 0; i2 < MAX; i2++)
{
    char s[BUFSIZ];
    if (fgets(s, 20, stdin) != NULL) //loop through lines
    {
        i+=atoi(s); //add to total
    }
    else
    {
        printf("%i\n",i);
        return 0;
    }
}
}