// you forgot to implement calls to bitwise functions in main !!
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
        printf("Error 1 in substring function\n");
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

void addr(long long reg[], int a, int b, int c)
{
    reg[c] = reg[a] + reg[b];
}

void addi(long long reg[], int a, int b, int c)
{
    reg[c] = reg[a] + b;
}

void mulr(long long reg[], int a, int b, int c)
{
    reg[c] = reg[a]*reg[b];
}

void muli(long long reg[], int a, int b, int c)
{
    reg[c] = reg[a]*b;
}

void banr(long long reg[], int a, int b, int c)
{
    reg[c] = reg[a] & reg [b];
}

void bani(long long reg[], int a, int b, int c)
{
    reg[c] = reg[a] & b;
}

void borr(long long reg[], int a, int b, int c)
{
    reg [c] = reg[a] | reg[b];
}

void bori(long long reg[], int a, int b, int c)
{
    reg[c] = reg[a] | b;
}

void setr(long long reg[], int a, int b, int c)
{
    reg[c] = reg[a];
}

void seti(long long reg[],  int a, int b, int c)
{
    reg[c] = a;
}

void gtir(long long reg[], int a, int b, int c)
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

void gtri(long long reg[], int a, int b, int c)
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

void gtrr(long long reg[], int a, int b, int c)
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

void eqir(long long reg[], int a, int b, int c)
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

void eqri(long long reg[], int a, int b, int c)
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

void eqrr(long long reg[], int a, int b, int c)
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
    long long reg[6] = {0,0,0,0,0,0};
    long long outp[15000000][6] = {{0}}; //todo dynamically allocate this so doesn't seg fault
    char inst[36][5];
    int instval[36][3];
    int ip;
    int p=0;
    for(int i=0;i<32;i++)
    {
        int a=5; //position of these in input string
        int b=0;
        int c=0;
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
                for(int j=a, k=strlen(s);j<k;j++)
                {
                    if(s[j]==' ' && b==0)
                    {
                        b=j+1;
//                        printf("%i\n",b);
                    }
                    else if(s[j]==' ' && c==0)
                    {
                        c=j+1;
                        break;
                    }
                }
//                printf("%i %i %i",a,b,c);
                char tmp[10];
//                printf("1\n");
                substring(s,tmp,a,b-a-1);
//                printf("2\n");
                instval[i-1][0]=atoi(tmp);
//                printf("3\n");
                substring(s,tmp,b,c-b-1);
//                printf("4\n");
                instval[i-1][1]=atoi(tmp);
//                printf("5\n");
                substring(s,tmp,c,strlen(s)-c-1);
//                printf("6\n");
                instval[i-1][2]=atoi(tmp);
                printf("%i %i %i\n",instval[i-1][0],instval[i-1][1],instval[i-1][2]);

            /*
                instval[i-1][0]=atoi(&s[5]);
                char tmp[3];
                substring(s,tmp,7,2);
                instval[i-1][1]=atoi(tmp);
                substring(s,tmp,9,2);
                instval[i-1][2]=atoi(tmp); */
            }
        }
    }
//    int ch=0;
//    while(ch<1000)
    while(p<31)
    {
        if(p==28)
        {
            if((outp[reg[5]][0]==reg[0]) && (outp[reg[5]][1]==reg[1]) && (outp[reg[5]][2]==reg[2]) && (outp[reg[5]][3]==reg[3]) && (outp[reg[5]][4]==reg[4]) && (outp[reg[5]][5]==reg[5]))
            {
                return 0;
            }
            else if(outp[reg[5]][5]==reg[5])
            {
                printf("need more work\n");
                return 0;
            }
            else
            {
                outp[reg[5]][0]=reg[0];
                outp[reg[5]][1]=reg[1];
                outp[reg[5]][2]=reg[2];
                outp[reg[5]][3]=reg[3];
                outp[reg[5]][4]=reg[4];
                outp[reg[5]][5]=reg[5];
            }
          //printf("%lli\n",reg[5]);
          //  return 0;
        }
 //       printf("%lli %lli %lli %lli %lli %lli; Set reg[1] to %i then %s %i %i %i\n",reg[0],reg[1],reg[2],reg[3],reg[4],reg[5], p, inst[p],instval[p][0],instval[p][1],instval[p][2]);
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
            banr(reg,instval[p][0],instval[p][1],instval[p][2]);
        }
        else if(strcmp(inst[p],"bani")==0)
        {
            bani(reg,instval[p][0],instval[p][1],instval[p][2]);
        }
        else if(strcmp(inst[p],"borr")==0)
        {
            borr(reg,instval[p][0],instval[p][1],instval[p][2]);
        }
        else if(strcmp(inst[p],"bori")==0)
        {
            bori(reg,instval[p][0],instval[p][1],instval[p][2]);
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
//        printf("%i %i %i %i %i %i; %s %i %i %i\n",reg[0],reg[1],reg[2],reg[3],reg[4],reg[5], inst[p],instval[p][0],instval[p][1],instval[p][2]);
        p++; //increment pointer
//        ch++;
    }
    printf("Out: %lli\n",reg[0]);




/*debug    for(int i=0;i<36;i++)
    {
        printf("%s %i %i %i\n",inst[i],instval[i][0],instval[i][1],instval[i][2]);
        printf("%i\n",p);
    } */
}