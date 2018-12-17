#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

void addr(int register[], int a, int b, int c)
{
    register[c] = register[a] + register[b];
}

void addi(int register[], int a, int b, int c)
{
    register[c] = register[a] + b;
}

void mulr(int register[], int a, int b, int c)
{
    register[c] = register[a]*register[b]
}

void muli(int register[], int a, int b, int c)
{
    register[c] = register[a]*b
}

void banr(int register[], int a, int b, int c)
{
    register[c] = register[a] & register [b];
}

void bani(int register[], int a, int b, int c)
{
    register[c] = register[a] & b;
}

void borr(int register[], int a, int b, int c)
{
    register [c] = register[a] | register[b];
}

void bori(int register[], int a, int b, int c)
{
    register[c] = register[a] | b;
}

void setr(int register[], int a, int b, int c)
{
    register[c] = register[b];
}

void seti(int register[],  int a, int b, int c)
{
    register[c] = a;
}

void gtir(int register[], int a, int b, int c)
{
    if(a>register[b])
    {
        register[c] = 1;
    }
    else
    {
        register[c] = 0;
    }
}

void gtri(int register[], int a, int b, int c)
{
    if(register[a]>b)
    {
        register[c] = 1;
    }
    else
    {
        register[c] = 0;
    }
}

void gtrr(int register[], int a, int b, int c)
{
    if(register[a]>register[b])
    {
        register[c] = 1;
    }
    else
    {
        register[c] = 0;
    }
}

void eqir(int register[], int a, int b, int c)
{
    if(a == register[b])
    {
        register[c] = 1;
    }
    else
    {
        register[c] = 0;
    }
}

void eqri(int register[], int a, int b, int c)
{
    if(register[a] == b)
    {
        register[c] = 1;
    }
    else
    {
        register[c] = 0;
    }
}

void eqrr(int register[], int a, int b, int c)
{
    if(register[a] == register[b])
    {
        register[c] = 1;
    }
    else
    {
        register[c] = 0;
    }
}

int main(void)
{
    int before[1000][4];
    int after[1000][4];
    int register[4];
    int instr[1000][4];
    int cnt = 0;
    for(i=0;i<3259;i++)
    {
        char s[BUFSIZ];
        if (fgets(s, 25, stdin) != NULL) //loop through input lines (first half of input)
        {
            if(s[0]=='B')
            {
                before[cnt][0] = atoi(s[9]);
                before[cnt][1] = atoi(s[12]);
                before[cnt][2] = atoi(s[15]);
                before[cnt][3] = atoi(s[18]);
            }
            Else If(s[0]=='A')
            {
                after[cnt][0] = atoi(s[9]);
                after[cnt][1] = atoi(s[12]);
                after[cnt][2] = atoi(s[15]);
                after[cnt][3] = atoi(s[18]);
            }
            else if(((int)s[0]>47) && ((int)s[0]<58))
            {
                char ss[3];
                substring(s,ss,0,2);

            }

        }
    }
}