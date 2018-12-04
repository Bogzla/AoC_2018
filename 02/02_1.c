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
    for(int i=0; i<250; i++)
    {
        char s[BUFSIZ];
        if (fgets(s, 28, stdin) != NULL) //loop through lines and test regex
        {
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
}
