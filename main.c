#include <stdio.h>
#include <stdlib.h>

typedef struct node{
  struct node* nt;
  int id;
}node;
struct node *H_table[11];

void build_Htable(int x, int y)
{
    node*temp;
    temp = (struct node*)malloc(sizeof(struct node));
    temp->id = x;
    temp->nt = NULL;

    if(H_table[y] == NULL)
        H_table[y] = temp;

    else
    {
        node*current = H_table[y];
        while(current->nt != NULL)
            current = current->nt;
        current->nt = temp;
    }
}

void print()
{
    struct node *temp[11];
    int i, counter;
    for(i = 0; i < 11; i++)
        temp[i] = H_table[i];
    for (i = 0; i < 11; i++)
    {
        counter = 1;
        while(temp[i] != NULL)
        {
            printf("%d. Element of Table %d = %d\n", counter, i, temp[i]->id);
            temp[i] = temp[i] -> nt;
            counter++;
        }
    }
}

int main()
{
    int k[] = {14, 7, 46, 28, 3, 17, 53 ,19};
    int i = 0, key;
    i = 0;
    while(i < 8)
    {
        key = k[i]%11;
        build_Htable(k[i], key);
        i++;
    }
    print();
    return 0;
}
