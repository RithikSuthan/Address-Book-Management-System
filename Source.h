#ifndef SOURCE_H_INCLUDED
#define SOURCE_H_INCLUDED
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<stdbool.h>
#include<string.h>
struct data
{
    char name[25];
    char address[50];
    char phone[11];
    char profession[25];
    char blood[6];
};
struct node
{
    struct data d1;
    struct node *next;
    struct node *prev;
    struct node *last;//Used for Sorting
};
struct node *head=NULL,*ptr=NULL;
struct node *first =NULL;
struct node *last = NULL;
struct node *merge(struct node *p1, struct node *p2) {
    struct node **pp;
    pp = &head;
    for (;;) {
        if (strcmp(p1->d1.name, p2->d1.name) <= 0) {
            *pp = p1;
            pp = &p1->next;
            p1 = p1->next;
            if (p1 == NULL) {
                *pp = p2;
                break;
            }
        } else {
            *pp = p2;
            pp = &p2->next;
            p2 = p2->next;
            if (p2 == NULL) {
                *pp = p1;
                break;
            }
        }
    }
    return head;
}
struct node *msort(struct node *np) {
    struct node *p1, *p2;
    if (np == NULL || np->next == NULL)
        return np;
    for (p1 = np, p2 = np->next; p2 && p2->next; p2 = p2->next->next)
        p1 = p1->next;
    p2 = p1->next;
    p1->next = NULL;
    p1 = np;
    p1 = msort(p1);
    p2 = msort(p2);
    return merge(p1, p2);
}
void sort() {
    struct node *p1, *p2;
    struct node *temp;
    temp=head;
    first = msort(temp);
    p1 = NULL;
    for (p2 = first; p2; p2 = p2->next) {
        p2->last = p1;
        p1 = p2;
    }
    last = p1;
}
void output()
{
    printf("\nPress 1 to Create\n");
    printf("Press 2 to Insert\n");
    printf("Press 3 to Display\n");
    printf("Press 4 to Search\n");
    printf("Press 5 to Modify\n");
    printf("Press 6 to Delete\n");
    printf("Press 7 to Back\n");
    printf("Press 8 to Exit\n");
    printf("Press 9 to Redo");
    printf("Enter your option\n");
}
void write_binary(FILE *f1)
{
    struct data s;
    struct node*dumpy=head;
	while(dumpy!=NULL)
	{
        s=dumpy->d1;
        fwrite(&s, sizeof(s), 1, f1);
        dumpy=dumpy->next;
	}
}
void insert_list(struct data d)
{
    struct node *newnode;
    newnode=(struct node *)malloc(sizeof(struct node));
    newnode->d1=d;
    if(head==NULL)
    {
        newnode->next=NULL;
        newnode->prev=NULL;
        ptr=newnode;
    }
    else
    {
        newnode->next=head;
        newnode->prev=0;
        newnode->next->prev=newnode;
    }
    head=newnode;
}
void read_binary(FILE *f1)
{
    struct data s;
    head=NULL;
	while(fread(&s,sizeof(s),1,f1))
        {
        insert_list(s);
        }
}
void create()
{
    int n,i=0;
    printf("The number of entries to be enterred\n");
    scanf("%d",&n);
        head=NULL;
        for(i=0;i<n;i++)
            {
        struct data d;
        fflush(stdin);
        printf("Person %d\n",i+1);
        printf("Enter the name of the person:\n");
        gets(d.name);
        fflush(stdin);
        printf("Enter the blood group of the person:\n");
        gets(d.blood);
        fflush(stdin);
        printf("Enter the profession of the person:\n");
        gets(d.profession);
        fflush(stdin);
        printf("Enter the address of the person:\n");
        gets(d.address);
        fflush(stdin);
        printf("Enter the phone number of the person:\n");
        gets(d.phone);
        insert_list(d);
    }
    FILE *f1;
    f1=fopen("Chamu.dat","wb");
    write_binary(f1);
    fclose(f1);
}
void insert()
{
    FILE *f1;
    f1=fopen("Chamu.dat","rb");
    if(!f1)
    {
        printf("File doesn't exit please create it\n");
        return;
    }
    read_binary(f1);
    fclose(f1);
    struct data d;
    fflush(stdin);
    printf("Enter the name of the person:\n");
    gets(d.name);
    fflush(stdin);
    printf("Enter the blood group of the person:\n");
    gets(d.blood);
    fflush(stdin);
    printf("Enter the profession of the person:\n");
    gets(d.profession);
    fflush(stdin);
    printf("Enter the address of the person:\n");
    gets(d.address);
    fflush(stdin);
    printf("Enter the phone number of the person:\n");
    gets(d.phone);
    insert_list(d);
    FILE *f2;
    f2=fopen("Chamu.dat","wb");
    write_binary(f2);
    fclose(f2);
}
void disp()
{
    struct node *temp=head;
    int i=0;
    while(temp!=NULL)
    {
        printf("Person %d\n",i+1);
        printf("The name of the person is %s\n",temp->d1.name);
        printf("The blood group of the person is %s\n",temp->d1.blood);
        printf("The profession of the person is %s\n",temp->d1.profession);
        printf("The address of the person is %s\n",temp->d1.address);
        printf("The phone number of the person is %s\n",temp->d1.phone);
        i++;
        temp=temp->next;
    }
}
void display()
{
        FILE *f1;
        f1=fopen("Chamu.dat","rb");
        read_binary(f1);
        fclose(f1);
        //sort();
        disp();
}
void search1()
{
    FILE *f1;
    f1=fopen("Chamu.dat","rb");
    read_binary(f1);
    fclose(f1);
    label:
    printf("To search details\n");
    printf("Press 1-To search by Name\n");
    printf("Press 2-To search by Profession\n");
    printf("Press 3-To search by Blood group\n");
    printf("Press 4-To search by Phone\n");
    int choice;
    printf("Enter your choice:\n");
    scanf("%d",&choice);
    fflush(stdin);
    switch(choice)
    {
        case 1:
            {
                //char name1[25];
                int flag=0;
                struct data k;
                fflush(stdin);
                printf("Enter the name you want to search:\n");
                gets(k.name);
                struct node *temp=head;
                while(temp!=NULL)
                {
                    if(strcmp(k.name,temp->d1.name)==0)
                    {
                        printf("The name of the person is %s\n",temp->d1.name);
                        printf("The blood group of the person is %s\n",temp->d1.blood);
                        printf("The profession of the person is %s\n",temp->d1.profession);
                        printf("The address of the person is %s\n",temp->d1.address);
                        printf("The phone number of the person is %s\n",temp->d1.phone);
                        flag++;
                    }
                    temp=temp->next;
                }
                if(flag==0)
                {
                    printf("The element is not found\n");
                }
                else
                {
                    printf("The element is found\n");
                }
                flag=0;
                break;
            }
        case 2:
            {
                int flag=0;
                char profession1[25];
                printf("Enter the profession you want to search:\n");
                gets(profession1);
                struct node *temp=head;
                while(temp!=NULL)
                {
                    if(strcmp(profession1,temp->d1.profession)==0)
                    {
                        printf("The name of the person is %s\n",temp->d1.name);
                        printf("The blood group of the person is %s\n",temp->d1.blood);
                        printf("The profession of the person is %s\n",temp->d1.profession);
                        printf("The address of the person is %s\n",temp->d1.address);
                        printf("The phone number of the person is %s\n",temp->d1.phone);
                        flag++;
                    }
                    temp=temp->next;
                }
                if(flag==0)
                {
                    printf("The element is not found\n");
                }
                else
                {
                    printf("The element is found\n");
                }
                flag=0;
                break;
            }
        case 3:
            {
                int flag=0;
                char blood1[6];
                printf("Enter the blood group you want to search:\n");
                gets(blood1);
                struct node*temp=head;
                while(temp!=NULL)
                {
                    if(strcmp(blood1,temp->d1.blood)==0)
                    {
                        printf("The name of the person is %s\n",temp->d1.name);
                        printf("The blood group of the person is %s\n",temp->d1.blood);
                        printf("The profession of the person is %s\n",temp->d1.profession);
                        printf("The address of the person is %s\n",temp->d1.address);
                        printf("The phone number of the person is %s\n",temp->d1.phone);
                        flag++;
                    }
                    temp=temp->next;
                }
                    if(flag==0)
                    {
                        printf("The element is not found\n");

                    }
                    else
                    {
                        printf("The element is found\n");
                    }
                    flag=0;
                break;
            }
        case 4:
            {
                int flag=0;
                char phone1[6];
                printf("Enter the phone number you want to search:\n");
                gets(phone1);
                struct node*temp=head;
                while(temp!=NULL)
                {
                    if(strcmp(phone1,temp->d1.phone)==0)
                    {
                        printf("The name of the person is %s\n",temp->d1.name);
                        printf("The blood group of the person is %s\n",temp->d1.blood);
                        printf("The profession of the person is %s\n",temp->d1.profession);
                        printf("The address of the person is %s\n",temp->d1.address);
                        printf("The phone number of the person is %s\n",temp->d1.phone);
                        flag++;
                    }
                    temp=temp->next;
                }
                    if(flag==0)
                    {
                        printf("The element is not found\n");

                    }
                    else
                    {
                        printf("The element is found\n");
                    }
                    flag=0;
                break;
            }
        default:
            printf("Invalid choice,");
            printf("Enter your choice again!!!\n");
            goto label;
    }
    FILE *f2;
    f2=fopen("Chamu.dat","wb");
    write_binary(f2);
    fclose(f2);
}
#endif // SOURCE_H_INCLUDED
