#include <stdio.h>
#include <regex.h>
#include <string.h>

// regex match?
int match(const char *string, const char *pattern)
{
    regex_t re;
    if (regcomp(&re, pattern, REG_EXTENDED|REG_NOSUB) != 0) return 0;
    int status = regexec(&re, string, 0, NULL, 0);
    regfree(&re);
    if (status != 0) return 0;
    return 1;
}

int main(void)
{
    int tw=0; //counter for twice
    int th=0; //counter for thrice
    char ID[250][28]; //store IDs for comparison
    for(int i=0; i<250; i++)
    {
        char s[BUFSIZ];
        if (fgets(s, 28, stdin) != NULL) //loop through lines and test regex
        {
            strcpy(ID[i],s); //read IDs in for part 2
            for(int j=97; j < 123; j++) //loop through alphabet
            {
                char re[15] = "(.)(.*?\\1){1}";
                re[1] = (char)j;
                if(match(s,re)==1)
                {
                    strcpy(re,"(.)(.*?\\1){2}");
                    re[1] = (char)j;
                    if(match(s,re)!=1)
                    {
                        tw++; //2 repeats but not 3 = exactly 2
                        break;
                    }
                }
            }
            for(int j=97; j < 123; j++)
            {
                char re[15] = "(.)(.*?\\1){2}";
                re[1] = (char)j;
                if(match(s,re)==1)
                {
                    strcpy(re,"(.)(.*?\\1){3}");
                    re[1] = (char)j;
                    if(match(s,re)!=1)
                    {
                        th++; //3 repeats but not 4 = exactly 3
                        break;
                    }
                }
            }

        }
        else
        {
            return 0;
        }
    }
    printf("Part 1: %i\n",tw*th);


//now for part 2
    int k=0;
    for(int i=0; i < 249; i++) //loop through each entry (except last)
    {
        for(int j=k+1; j < 250; j++) //checking against all subsequent entries
        {
            int m=0;
            for(int l=0;l<26;l++)
            {
                if((int)ID[i][l]==(int)ID[j][l]) //compare byte-wise
                {
                    m++;
                }
            }
            if(m==25) //strings with only 1 difference will score 25
            {
                printf("Part 2: ");
                for(int l=0;l<26;l++)
                {
                    if((int)ID[i][l]==(int)ID[j][l]) //print answer (all except non-matching char)
                    {
                        printf("%c",ID[i][l]);
                    }
                }
                printf("\n");
                return 0;
            }
        }
        k++; //offset for subsequent entries
    }
}
