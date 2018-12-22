// is giving 136, which is too low. check function implementations with some test cases, also are we reading in all instructions correctly?

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

void addr(int reg[], int a, int b, int c)
{
    reg[c] = reg[a] + reg[b];
}

void addi(int reg[], int a, int b, int c)
{
    reg[c] = reg[a] + b;
}

void mulr(int reg[], int a, int b, int c)
{
    reg[c] = reg[a]*reg[b];
}

void muli(int reg[], int a, int b, int c)
{
    reg[c] = reg[a]*b;
}

void banr(int reg[], int a, int b, int c)
{
    reg[c] = reg[a] & reg [b];
}

void bani(int reg[], int a, int b, int c)
{
    reg[c] = reg[a] & b;
}

void borr(int reg[], int a, int b, int c)
{
    reg [c] = reg[a] | reg[b];
}

void bori(int reg[], int a, int b, int c)
{
    reg[c] = reg[a] | b;
}

void setr(int reg[], int a, int b, int c)
{
    reg[c] = reg[a];
}

void seti(int reg[],  int a, int b, int c)
{
    reg[c] = a;
}

void gtir(int reg[], int a, int b, int c)
{
    if(a>reg[b])
    {
        reg[c] = 1;
    }
    else
    {
        reg[c] = 0;
    }
}

void gtri(int reg[], int a, int b, int c)
{
    if(reg[a]>b)
    {
        reg[c] = 1;
    }
    else
    {
        reg[c] = 0;
    }
}

void gtrr(int reg[], int a, int b, int c)
{
    if(reg[a]>reg[b])
    {
        reg[c] = 1;
    }
    else
    {
        reg[c] = 0;
    }
}

void eqir(int reg[], int a, int b, int c)
{
    if(a == reg[b])
    {
        reg[c] = 1;
    }
    else
    {
        reg[c] = 0;
    }
}

void eqri(int reg[], int a, int b, int c)
{
    if(reg[a] == b)
    {
        reg[c] = 1;
    }
    else
    {
        reg[c] = 0;
    }
}

void eqrr(int reg[], int a, int b, int c)
{
    if(reg[a] == reg[b])
    {
        reg[c] = 1;
    }
    else
    {
        reg[c] = 0;
    }
}

int main(void)
{
    int before[1100][4] = {{0}};
    int after[1100][4] = {{0}};
    int reg[4] = {0};
    int instr[1100][4] = {{0}};
    int cnt = 0;
    for(int i=0;i<3259;i++)
    {
        char s[BUFSIZ];
        if (fgets(s, 25, stdin) != NULL) //loop through input lines (first half of input)
        {
            if(s[0]=='B') // before
            {
                before[cnt][0] = atoi(&s[9]);
                before[cnt][1] = atoi(&s[12]);
                before[cnt][2] = atoi(&s[15]);
                before[cnt][3] = atoi(&s[18]);
            }
            else if(s[0]=='A') // after
            {
                after[cnt][0] = atoi(&s[9]);
                after[cnt][1] = atoi(&s[12]);
                after[cnt][2] = atoi(&s[15]);
                after[cnt][3] = atoi(&s[18]);
                cnt++;
            }
            else if(((int)s[0]>47) && ((int)s[0]<58)) // instruction line starts with 0-9
            {
                char ss[3];
                substring(s,ss,0,2);
                instr[cnt][0] = atoi(ss);
                instr[cnt][1] = atoi(&s[strlen(s)-6]);
                instr[cnt][2] = atoi(&s[strlen(s)-4]);
                instr[cnt][3] = atoi(&s[strlen(s)-2]);
            }

        }
    }
    int instcnt = cnt;
    char OPS[16][5];
    strcpy(OPS[0],"addr");
    strcpy(OPS[1],"addi");
    strcpy(OPS[2],"mulr");
    strcpy(OPS[3],"muli");
    strcpy(OPS[4],"banr");
    strcpy(OPS[5],"bani");
    strcpy(OPS[6],"borr");
    strcpy(OPS[7],"bori");
    strcpy(OPS[8],"setr");
    strcpy(OPS[9],"seti");
    strcpy(OPS[10],"gtir");
    strcpy(OPS[11],"gtri");
    strcpy(OPS[12],"gtrr");
    strcpy(OPS[13],"eqir");
    strcpy(OPS[14],"eqri");
    strcpy(OPS[15],"eqrr");

    //how many instructions in 1st half of input have 3 valid OPS to go from Before to After state?
    int pt2=0;
    for(int i=0;i<instcnt;i++)
    {
        for(int j=0; j<4; j++)
        {
            reg[j]=before[i][j];
        }
//        printf("register: %i %i %i %i\n",reg[0],reg[1].reg[2],reg[3])
//        printf("instruction: %i %i %i\n",inst[i][1],inst[i][2],inst[i][3])
        cnt=0;
        for(int j=0; j<16; j++)
        {
            for(int k=0; k<4; k++)
            {
                reg[k]=before[i][k];
            }
        printf("register: %i %i %i %i\n",reg[0],reg[1],reg[2],reg[3]);
        printf("instruction: %s %i %i %i\n",OPS[j],instr[i][1],instr[i][2],instr[i][3]);
            switch(j)
            {
                case(0):
                    addr(reg,instr[i][1],instr[i][2],instr[i][3]);
                    break;
                case(1):
                    addi(reg,instr[i][1],instr[i][2],instr[i][3]);
                    break;
                case(2):
                    mulr(reg,instr[i][1],instr[i][2],instr[i][3]);
                    break;
                case(3):
                    muli(reg,instr[i][1],instr[i][2],instr[i][3]);
                    break;
                case(4):
                    banr(reg,instr[i][1],instr[i][2],instr[i][3]);
                    break;
                case(5):
                    bani(reg,instr[i][1],instr[i][2],instr[i][3]);
                    break;
                case(6):
                    borr(reg,instr[i][1],instr[i][2],instr[i][3]);
                    break;
                case(7):
                    bori(reg,instr[i][1],instr[i][2],instr[i][3]);
                    break;
                case(8):
                    setr(reg,instr[i][1],instr[i][2],instr[i][3]);
                    break;
                case(9):
                    seti(reg,instr[i][1],instr[i][2],instr[i][3]);
                    break;
                case(10):
                    gtir(reg,instr[i][1],instr[i][2],instr[i][3]);
                    break;
                case(11):
                    gtri(reg,instr[i][1],instr[i][2],instr[i][3]);
                    break;
                case(12):
                    gtrr(reg,instr[i][1],instr[i][2],instr[i][3]);
                    break;
                case(13):
                    eqir(reg,instr[i][1],instr[i][2],instr[i][3]);
                    break;
                case(14):
                    eqri(reg,instr[i][1],instr[i][2],instr[i][3]);
                    break;
                case(15):
                    eqrr(reg,instr[i][1],instr[i][2],instr[i][3]);
                    break;
            }
            printf("after: %i %i %i %i\n\n",reg[0],reg[1],reg[2],reg[3]);
            if((reg[0]==after[i][0]) && (reg[1]==after[i][1]) && (reg[2]==after[i][2]) && (reg[3]==after[i][3]))
            {
                cnt++;
            }

        }
        if(cnt==3)
        {
            pt2++;
        }
    }
    printf("Part 1: %i\n",pt2);
}