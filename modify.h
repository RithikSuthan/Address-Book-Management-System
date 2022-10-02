#ifndef MODIFY_H_INCLUDED
#define MODIFY_H_INCLUDED
#include "Source.h"
void modify()
{
    FILE *f1;
    f1=fopen("Chamu.dat","rb");
    read_binary(f1);
    fclose(f1);
    prog:
    printf("To search and modify the details:\n");
    printf("Press-1 To search by Name\n");
    printf("Press-2 To search by Phone Number\n");
    int choice;
    printf("Enter your choice:\n");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:
            {
                char name1[25];
                int flag=0;
                //struct data k;
                fflush(stdin);
                printf("Enter the name you want to search:\n");
                gets(name1);
                struct node *temp=head;
                while(temp!=NULL)
                {
                    if(strcmp(name1,temp->d1.name)==0)
                    {
                        printf("Searched Details\n\n");
                        printf("Name :%s\n",temp->d1.name);
                        printf("Blood Group :%s\n",temp->d1.blood);
                        printf("Profession :%s\n",temp->d1.profession);
                        printf("Address :%s\n",temp->d1.address);
                        printf("Phone Number :%s\n",temp->d1.phone);

                        printf("Press 1 to make changes\n");
                        printf("Press 0 If the current Details are correct\n");
                        int opt;
                        printf("Enter your choice:\n");
                        scanf("%d",&opt);
                        if(opt==1)
                        {
                        label:
                            printf("Press 1-TO modify the name\n");
                            printf("Press 2-TO modify the blood\n");
                            printf("Press 3-TO modify the profession\n");
                            printf("Press 4-TO modify the address\n");
                            printf("Press 5-TO modify the phone number\n");
                            printf("Press 6-To modify whole record\n");
                            int prf;
                            printf("Enter your choice:\n");
                            scanf("%d",&prf);
                            switch(prf)
                            {
                            case 1:
                                {
                                    fflush(stdin);
                                    printf("Enter the name of the person:\n");
                                    gets(temp->d1.name);
                                    flag++;
                                if(flag==0)
                                {
                                    printf("The element is not modified\n");
                                }
                                else
                                {
                                    printf("The element is found and it has been modified\n");
                                }
                                    break;
                                }
                            case 2:
                                {
                                    fflush(stdin);
                                    printf("Enter the blood group of the person:\n");
                                    gets(temp->d1.blood);
                                    flag++;
                                                                    if(flag==0)
                                {
                                    printf("The element is not modified\n");
                                }
                                else
                                {
                                    printf("The element is found and it has been modified\n");
                                }
                                    break;
                                }
                            case 3:
                                {
                                    fflush(stdin);
                                    printf("Enter the profession of the person:\n");
                                    gets(temp->d1.profession);
                                    flag++;
                                                                    if(flag==0)
                                {
                                    printf("The element is not modified\n");
                                }
                                else
                                {
                                    printf("The element is found and it has been modified\n");
                                }
                                    break;
                                }
                            case 4:
                                {
                                    fflush(stdin);
                                    printf("Enter the address of the person:\n");
                                    gets(temp->d1.address);
                                    flag++;
                                                                    if(flag==0)
                                {
                                    printf("The element is not modified\n");
                                }
                                else
                                {
                                    printf("The element is found and it has been modified\n");
                                }
                                    break;
                                }
                            case 5:
                                {
                                    fflush(stdin);
                                    printf("Enter the phone number of the person:\n");
                                    gets(temp->d1.phone);
                                    flag++;
                                                                    if(flag==0)
                                {
                                    printf("The element is not modified\n");
                                }
                                else
                                {
                                    printf("The element is found and it has been modified\n");
                                }
                                    break;
                                }
                            case 6:
                                {
                                    fflush(stdin);
                                    printf("Enter the name of the person:\n");
                                    gets(temp->d1.name);
                                    fflush(stdin);
                                    printf("Enter the blood group of the person:\n");
                                    gets(temp->d1.blood);
                                    fflush(stdin);
                                    printf("Enter the profession of the person:\n");
                                    gets(temp->d1.profession);
                                    fflush(stdin);
                                    printf("Enter the address of the person:\n");
                                    gets(temp->d1.address);
                                    fflush(stdin);
                                    printf("Enter the phone number of the person:\n");
                                    gets(temp->d1.phone);
                                    flag++;
                                                                    if(flag==0)
                                {
                                    printf("The element is not modified\n");
                                }
                                else
                                {
                                    printf("The element is found and it has been modified\n");
                                }
                                    break;
                                }
                            default:
                                printf("Invalid choice,Please Enter your choice again:\n");
                                goto label;
                            }
                        }
                        else
                        {
                            printf("No changes required\n");
                        }
                }
                else
                    {
                        printf("The element is not found in the linked list\n");
                    }
                    temp=temp->next;
                }
                flag=0;
                free(temp);
                break;

            }
        case 2:
            {
                int flag=0;
                struct data k;
                fflush(stdin);
                printf("Enter the phone number you want to search:\n");
                gets(k.phone);
                struct node *temp=head;
                while(temp!=NULL)
                {
                    if(strcmp(k.phone,temp->d1.phone)==0)
                    {
                        printf("Searched Details\n\n");
                        printf("Name :%s\n",temp->d1.name);
                        printf("Blood Group :%s\n",temp->d1.blood);
                        printf("Profession :%s\n",temp->d1.profession);
                        printf("Address :%s\n",temp->d1.address);
                        printf("Phone Number :%s\n",temp->d1.phone);

                        printf("Press 1 to make changes\n");
                        printf("Press 0 If the current Details are correct\n");
                        int opt;
                        printf("Enter your choice:\n");
                        scanf("%d",&opt);
                        if(opt==1)
                        {
                        label1:
                            printf("Press 1-TO modify the name\n");
                            printf("Press 2-TO modify the blood\n");
                            printf("Press 3-TO modify the profession\n");
                            printf("Press 4-TO modify the address\n");
                            printf("Press 5-TO modify the phone number\n");
                            printf("Press 6-To modify whole record\n");
                            int prf;
                            printf("Enter your choice:\n");
                            scanf("%d",&prf);
                            switch(prf)
                            {
                            case 1:
                                {
                                    fflush(stdin);
                                    printf("Enter the name of the person:\n");
                                    gets(temp->d1.name);
                                    flag++;
                                                                    if(flag==0)
                                {
                                    printf("The element is not modified\n");
                                }
                                else
                                {
                                    printf("The element is found and it has been modified\n");
                                }
                                    break;
                                }
                            case 2:
                                {
                                    fflush(stdin);
                                    printf("Enter the blood group of the person:\n");
                                    gets(temp->d1.blood);
                                                                        flag++;
                                                                    if(flag==0)
                                {
                                    printf("The element is not modified\n");
                                }
                                else
                                {
                                    printf("The element is found and it has been modified\n");
                                }
                                    break;
                                }
                            case 3:
                                {
                                    fflush(stdin);
                                    printf("Enter the profession of the person:\n");
                                    gets(temp->d1.profession);
                                                                        flag++;
                                                                    if(flag==0)
                                {
                                    printf("The element is not modified\n");
                                }
                                else
                                {
                                    printf("The element is found and it has been modified\n");
                                }
                                    break;
                                }
                            case 4:
                                {
                                    fflush(stdin);
                                    printf("Enter the address of the person:\n");
                                    gets(temp->d1.address);
                                                                        flag++;
                                                                    if(flag==0)
                                {
                                    printf("The element is not modified\n");
                                }
                                else
                                {
                                    printf("The element is found and it has been modified\n");
                                }
                                    break;
                                }
                            case 5:
                                {
                                    fflush(stdin);
                                    printf("Enter the phone number of the person:\n");
                                    gets(temp->d1.phone);
                                                                        flag++;
                                                                    if(flag==0)
                                {
                                    printf("The element is not modified\n");
                                }
                                else
                                {
                                    printf("The element is found and it has been modified\n");
                                }
                                    break;
                                }
                            case 6:
                                {
                                    fflush(stdin);
                                    printf("Enter the name of the person:\n");
                                    gets(temp->d1.name);
                                    fflush(stdin);
                                    printf("Enter the blood group of the person:\n");
                                    gets(temp->d1.blood);
                                    fflush(stdin);
                                    printf("Enter the profession of the person:\n");
                                    gets(temp->d1.profession);
                                    fflush(stdin);
                                    printf("Enter the address of the person:\n");
                                    gets(temp->d1.address);
                                    fflush(stdin);
                                    printf("Enter the phone number of the person:\n");
                                    gets(temp->d1.phone);
                                    break;
                                                                        flag++;
                                                                    if(flag==0)
                                {
                                    printf("The element is not modified\n");
                                }
                                else
                                {
                                    printf("The element is found and it has been modified\n");
                                }
                            }
                                default:
                                printf("Invalid choice,Please Enter your choice again:\n");
                                goto label1;
                        }

                    }
                    else
                    {
                        printf("No changes required\n");
                    }
                }
                /*else
                    {
                        printf("The element not found\n");
                    }*/
                    temp=temp->next;
                    }
                        flag=0;
                        free(temp);
                        break;
                    }
                    default:
                        printf("Invalid choice,Please Enter your choice again\n");
                        goto prog;

                }
        FILE *f2;
        f2=fopen("Chamu.dat","wb");
        write_binary(f2);
        fclose(f2);
}

#endif // MODIFY_H_INCLUDED
