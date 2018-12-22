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

void addr(int Reg[], int a, int b, int c)
{
    Reg[c] = Reg[a] + Reg[b];
}

void addi(int Reg[], int a, int b, int c)
{
    Reg[c] = Reg[a] + b;
}

void mulr(int Reg[], int a, int b, int c)
{
    Reg[c] = Reg[a]*Reg[b];
}

void muli(int Reg[], int a, int b, int c)
{
    Reg[c] = Reg[a]*b;
}

void banr(int Reg[], int a, int b, int c)
{
    Reg[c] = Reg[a] & Reg [b];
}

void bani(int Reg[], int a, int b, int c)
{
    Reg[c] = Reg[a] & b;
}

void borr(int Reg[], int a, int b, int c)
{
    Reg [c] = Reg[a] | Reg[b];
}

void bori(int Reg[], int a, int b, int c)
{
    Reg[c] = Reg[a] | b;
}

void setr(int Reg[], int a, int b, int c)
{
    Reg[c] = Reg[a];
}

void seti(int Reg[],  int a, int b, int c)
{
    Reg[c] = a;
}

void gtir(int Reg[], int a, int b, int c)
{
    if(a>Reg[b])
    {
        Reg[c] = 1;
    }
    else
    {
        Reg[c] = 0;
    }
}

void gtri(int Reg[], int a, int b, int c)
{
    if(Reg[a]>b)
    {
        Reg[c] = 1;
    }
    else
    {
        Reg[c] = 0;
    }
}

void gtrr(int Reg[], int a, int b, int c)
{
    if(Reg[a]>Reg[b])
    {
        Reg[c] = 1;
    }
    else
    {
        Reg[c] = 0;
    }
}

void eqir(int Reg[], int a, int b, int c)
{
    if(a == Reg[b])
    {
        Reg[c] = 1;
    }
    else
    {
        Reg[c] = 0;
    }
}

void eqri(int Reg[], int a, int b, int c)
{
    if(Reg[a] == b)
    {
        Reg[c] = 1;
    }
    else
    {
        Reg[c] = 0;
    }
}

void eqrr(int Reg[], int a, int b, int c)
{
    if(Reg[a] == Reg[b])
    {
        Reg[c] = 1;
    }
    else
    {
        Reg[c] = 0;
    }
}

int main(void)
{
    int reg[6] = {0};
    char inst[36][5];
    int instval[36][3];
    int ip;
    int p=0;
    for(int i=0;i<37;i++)
    {
        char s[BUFSIZ];
        if (fgets(s, 25, stdin) != NULL) //loop through input lines
        {
            if(s[0]=='#')
            {
                ip=atoi(&s[4]); //set which register bound to pointer
            }
            else
            {
                substring(s,inst[i-1],0,4); //save instruction set in arrays for ease of reference
                instval[i-1][0]=atoi(&s[5]);
                char tmp[3];
                substring(s,tmp,7,2);
                instval[i-1][1]=atoi(tmp);
                substring(s,tmp,9,2);
                instval[i-1][2]=atoi(tmp);
            }
        }
    }
    while(p<37)
    {
        reg[ip]=p; // update bound register to current pointer value then carry out instruction referenced by pointer value
        if(strcmp(inst[p],"addr")==0)
        {
            addr(reg,instval[p][0],instval[p][1],instval[p][2]);
        }
        else if(strcmp(inst[p],"addi")==0)
        {
            addi(reg,instval[p][0],instval[p][1],instval[p][2]);
        }
        else if(strcmp(inst[p],"mulr")==0)
        {
            mulr(reg,instval[p][0],instval[p][1],instval[p][2]);
        }
        else if(strcmp(inst[p],"muli")==0)
        {
            muli(reg,instval[p][0],instval[p][1],instval[p][2]);
        }
        else if(strcmp(inst[p],"banr")==0)
        {
            //not in input
        }
        else if(strcmp(inst[p],"bani")==0)
        {
            //not in input
        }
        else if(strcmp(inst[p],"borr")==0)
        {
            //not in input
        }
        else if(strcmp(inst[p],"bori")==0)
        {
            //not in input
        }
        else if(strcmp(inst[p],"setr")==0)
        {
            setr(reg,instval[p][0],instval[p][1],instval[p][2]);
        }
        else if(strcmp(inst[p],"seti")==0)
        {
            seti(reg,instval[p][0],instval[p][1],instval[p][2]);
        }
        else if(strcmp(inst[p],"gtir")==0)
        {
            gtir(reg,instval[p][0],instval[p][1],instval[p][2]);
        }
        else if(strcmp(inst[p],"gtri")==0)
        {
            gtri(reg,instval[p][0],instval[p][1],instval[p][2]);
        }
        else if(strcmp(inst[p],"gtrr")==0)
        {
            gtrr(reg,instval[p][0],instval[p][1],instval[p][2]);
        }
        else if(strcmp(inst[p],"eqir")==0)
        {
            eqir(reg,instval[p][0],instval[p][1],instval[p][2]);
        }
        else if(strcmp(inst[p],"eqri")==0)
        {
            eqri(reg,instval[p][0],instval[p][1],instval[p][2]);
        }
        else if(strcmp(inst[p],"eqrr")==0)
        {
            eqrr(reg,instval[p][0],instval[p][1],instval[p][2]);
        }
        p=reg[ip]; //copy bound register value back to pointer
        p++; //increment pointer
    }
    printf("Part 1: %i\n",reg[0]);




/*debug    for(int i=0;i<36;i++)
    {
        printf("%s %i %i %i\n",inst[i],instval[i][0],instval[i][1],instval[i][2]);
        printf("%i\n",p);
    } */
}