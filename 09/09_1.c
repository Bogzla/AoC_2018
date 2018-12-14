#include <stdio.h>
#include <stdlib.h>
//marble game with a linked list

typedef struct node {
    int val;
    struct node * next;
} node;

int main(void)
{
    node *marbles = malloc(sizeof(node)); //allocate memory and setup '0' marble circle
    marbles->val = 0;
    marbles->next = marbles;
    node *ptr = marbles; //create referencing pointer
    int marblecount = 1;
    int elfcount = 10;
    int elves[10]={0};
    int elf = 0;
    int hiscore = 0;
    for(int i=1;i<1618;i++)
    {
        if(i%23!=0)
        {
            node *n = malloc(sizeof(node)); //create new node
            n->val = i;
            ptr = ptr->next; //move the pointer one node clockwise
            n->next = ptr->next; //insert new node clockwise of pointer
            ptr->next = n;
            ptr = ptr->next; //move pointer onto new node
            marblecount++;
            elf++;
        }
        else
        {
            elves[elf%elfcount] += i;
            //go clockwise until we're at node before the one to remove
            int remove = marblecount-8;
            int j=0;
            while(j<remove)
            {
                ptr = ptr->next;
                j++;
            }
            node *tmp = ptr->next; //create pointer to node to remove
            elves[elf%elfcount] += tmp->val;
       //     printf("%i\n",elf%elfcount);
            ptr->next = tmp->next;
            free(tmp);
            marblecount--;
            ptr=ptr->next;
            if(elves[elf%elfcount]>hiscore)
            {
                hiscore=elves[elf%elfcount];
            }
        }

    }
    node *tmp = marbles;
    int i=0;
    while(i<marblecount)
    {
//        printf("%i ",tmp->val);
        node *tmp2 = tmp;
        tmp = tmp->next;
        i++;
        free(tmp2);
    }


    printf("%i\n",hiscore);
    free(marbles);
}