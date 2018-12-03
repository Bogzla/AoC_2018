//REGEXP. expression below matches 2 or more, how make it match exactly 2??!
#include <stdio.h>
#include <regex.h>

int match(const char *string, const char *pattern)
{
    regex_t re;
    if (regcomp(&re, pattern, REG_EXTENDED|REG_NOSUB) != 0) return 0;
    int status = regexec(&re, string, 0, NULL, 0);
    regfree(&re);
    printf("%i\n",status);
    if (status != 0) return 0;
    return 1;
}

int main(void)
{
    for(int i=0; i<100; i++)
    {
        char s[BUFSIZ];
        if (fgets(s, 20, stdin) != NULL) //loop through lines and test regex
        {
    //    const char* s1 = "abcdefghi";
    //    const char* s2 = "abgcdgefghj";
        //    char* re = "(.).*\\1.*\\1";
        const char* re = "(j)(.*?\\1){1}";
            printf("%s matches %s? %s\n", s, re, match(s, re) ? "true" : "false");
        }
    }
}

/* regexp WIP
(.+?).*?\1(?=.*\1)
matches 3 or more of any character by using lookahead */