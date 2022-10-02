#ifndef DELETION_H_INCLUDED
#define DELETION_H_INCLUDED
#include "Source.h"
struct node *point[25];
int Top=-1;
void push(struct node *pt)
{
    if(Top==24)
    {
        printf("Overflow\n");
    }
    else
    {
        Top++;
        point[Top]=pt;
    }
    return;
}
struct node* pop()
{
    return point[Top--];
}
void redo()
{
    if(Top==-1)
    {
        return;
    }
    printf("%d",Top);
    struct node *n=pop();
    printf("%s",n->d1.name);
    printf("%s",head->d1.name);
    if(head==NULL)
    {
        head=n;
    }
    else if(n->prev==NULL)
    {
        head->prev=n;
        head=n;
    }
    else if(n->next==NULL)
    {
        printf("%s",n->prev->d1.name);
        n->prev->next=n;
    }
    else
    {
            printf("%s",n->d1.name);
            n->prev->next=n;
            n->next->prev=n;
    }
    FILE *f2;
    f2=fopen("Chamu1.dat","wb");
    write_binary(f2);
    fclose(f2);
    remove("Chamu.dat");
    rename("Chamu1.dat","Chamu.dat");
    if(head==NULL)
    {
        printf("It is null\n");
    }
    for(int i=0;i<=Top;i++)
    {
        printf("\n%s",point[i]->d1.name);
    }
    printf("%s",n->d1.name);
    printf("%s",head->d1.name);
    disp();
}
void delete1()
{
    FILE *f1;
    f1=fopen("Chamu.dat","rb");
    read_binary(f1);
    fclose(f1);
    struct node *temp=head;
    char str[25];
    fflush(stdin);
    printf("Enter the name of the customer to be deleted:\n");
    gets(str);
    fflush(stdin);
    while (temp!=NULL)
    {
        if(strcmp(temp->d1.name,str)==0)
        {
            printf("Details of the customer which you want to delete is\n");
            printf("The name of the person is %s\n",temp->d1.name);
            printf("The blood group of the person is %s\n",temp->d1.blood);
            printf("The profession of the person is %s\n",temp->d1.profession);
            printf("The address of the person is %s\n",temp->d1.address);
            printf("The phone number of the person is %s\n",temp->d1.phone);
           if(strcmp(head->d1.name,str)==0)
            {
                printf("It is at head \n");
              if(head->next != NULL)
                    {
                     head->next->prev = NULL;
                     push(head);
                     head = head->next;
                     //return;
                    }
                    else
                        {
                            push(head);
                         head = NULL;
                         printf("List is empty now");
                         FILE *f2;
                            f2=fopen("Chamu1.dat","wb");
                            write_binary(f2);
                            fclose(f2);
                            remove("Chamu.dat");
                            rename("Chamu1.dat","Chamu.dat");
                            free(temp);
                         return;
                        }
           }
           else if(strcmp(head->d1.name,str)!=0 && head->next == NULL)
                {
              printf("%s not found in the list\n",temp->d1.name);
              //return;
                }
           struct node *current,*pre_node;
           current = head;
           while(current->next != NULL && strcmp(current->d1.name,str)!=0)
           {
              pre_node = current;
              current = current->next;
           }
           if(strcmp(current->d1.name,str)==0)
            {
              pre_node->next = pre_node->next->next;
              if(pre_node->next != NULL)
              {
                  pre_node->next->prev = pre_node;
              }
               else
               {
                last = pre_node;
               }
                push(current);
              //free(current);
           }
           else
              printf("%s not found in the list.",temp->d1.name);
            //return;
 }
temp=temp->next;
    }
FILE *f2;
f2=fopen("Chamu1.dat","wb");
write_binary(f2);
fclose(f2);
remove("Chamu.dat");
rename("Chamu1.dat","Chamu.dat");
free(temp);
}
#endif // DELETION_H_INCLUDED
