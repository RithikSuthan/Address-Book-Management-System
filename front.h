#ifndef FRONT_H_INCLUDED
#define FRONT_H_INCLUDED
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include <windows.h>
#include<limits>
#include<ctype.h>
#include"Source.h"
#include "deletion.h"
#include "modify.h"
int front_page();
void admin_options();
bool isChar(char c)
{
	return ((c >= 'a' && c <= 'z')
			|| (c >= 'A' && c <= 'Z'));
}

bool isDigit(const char c)
{
	return (c >= '0' && c <= '9');
}

bool Validity(char *t_mail)
{
	int i;
   if(!isChar(t_mail[0]))
   {
   	 return 0;
   }

   int at=-1,dot=-1;


   for(i=0;i<strlen(t_mail);i++)
   {
   	    if(t_mail[i] == '@')
   	    {
   	  	   at = i;
		}
		else if(t_mail[i]== '.')
		{
			dot = i;
		}

   }

   if (at == -1 || dot == -1)
		{
		  return 0;
        }

	    if (at > dot)
	    {
		  return 0;
	    }

   return 1;
}
struct login
{
	char name[50];
	char passwor[20];
};
void loadingBar()
{
    system("color 0A");
    char a = 177, b = 219;
    printf("\n\n\n\n");
    printf("\n\n\n\n\t\t\t\t\tLoading...\n\n");
    printf("\t\t\t\t\t");
    for (int i = 0; i < 15; i++)
        printf("%c", a);
    printf("\r");
    printf("\t\t\t\t\t");
    for (int i = 0; i < 15; i++) {
        printf("%c", b);
        Sleep(100);
    }
}
void empty_stdin (void)
{
    int c = getchar();
    while (c != '\n' && c != EOF)
        c = getchar();
}
void sign_up()
{
	char u_pass[20];
	int i;
	int flag=0;
	struct login l;
	struct login c;
	FILE *ln;
	FILE *lo;
	lo = fopen("login.bin","ab+");
	printf("\n\n\t\t\tSIGN UP");
	fflush(stdin);
	printf("\n\n\tUsername  :");
	gets(l.name);
	fflush(stdin);
	fflush(stdin);
	fflush(stdin);
	printf("\n\n\tPassword  :");
	for( i=0 ; ; )
	{
		u_pass[i] = getch();
		if((u_pass[i]>='a'&&u_pass[i]<='z')||(u_pass[i]>='A'&&u_pass[i]<='Z')||(u_pass[i]>='!'&&u_pass[i]<='@'))
		{
			l.passwor[i] = u_pass[i];
			++i;
			u_pass[i]='*';
			printf("%c",u_pass[i]);
		}
		if(u_pass[i] == '\b' && i>=1)
		{
		    printf("\b \b");
		    --i;
		}
		if(u_pass[i] == '\r')
		{
			l.passwor[i] = '\0';
			break;
		}
	}
    fwrite(&l, sizeof(login),1,lo);
	fclose(lo);
	front_page();
   }


//----------------------------------------------------------------------------------------------------------//
// LOGIN
//----------------------------------------------------------------------------------------------------------//
void sign_in()
{
	int l_times = 0;
	while(l_times<3)
	{
	int flag=0;
	char u_pass[20],pass[20];
	int i;
	char username[50];
	struct login l;
	FILE *lo;
	printf("\n\n\t\t\tLOGIN");
	fflush(stdin);
	printf("\n\n\tUsername  :");
	gets(username);
	fflush(stdin);
	printf("\n\n\tPassword  :");
	for( i=0 ; ; )
	{
		u_pass[i] = getch();
		if((u_pass[i]>='a'&&u_pass[i]<='z')||(u_pass[i]>='A'&&u_pass[i]<='Z')||(u_pass[i]>='!'&&u_pass[i]<='@'))
		{
			pass[i] = u_pass[i];
			++i;
			u_pass[i]='*';
			printf("%c",u_pass[i]);
		}
		if(u_pass[i] == '\b' && i>=1)
		{
		    printf("\b \b");
		    --i;
		}
		if(u_pass[i] == '\r')
		{
			pass[i] = '\0';
			break;
		}
	}
	lo = fopen("login.bin","rb");

	while(fread(&l,sizeof(login),1,lo))
	{
		if(strcmpi(username,l.name)==0 && strcmpi(pass,l.passwor)==0)
		{
			flag = 1;
			printf("\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\tLogged in Successfully!!!");
			admin_options();
		}
	}
	if(flag == 0)
	{
		l_times++;
		printf("\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\tInvalid Username/Password...");
	}
  }
  printf("\n\n\tToo many login attempts! Try again later...\n\n\tThank you...!\n\n\n");
}
//
//
int userlogin(void){
    int n,rtn;
        for (;;) {
        printf("\n\n\n\t\t\t1. LOGIN\t\t2. REGISTER\t\t3. BACK");
    printf("\n\n\n\t\t\t\tENTER YOUR CHOICE: ");
        rtn = scanf("%d",&n);
        if (rtn == EOF) {
            fputs ("(user canceled input.)\n", stderr);
            return 1;
        }
        else if (rtn == 0) {
            fputs (" error: invalid integer input.\n", stderr);
            empty_stdin();
        }
        else if (n<1 || 3<n) {
            fputs (" error: integer out of range [1-3]\n", stderr);
            empty_stdin();
        }
        else {
            empty_stdin();
            break;
        }
        system("pause");
    }
    switch(n){
        case 1:{
            sign_in();
            break;
                }
        case 2:
            {
                sign_up();
                break;
            }
        case 3:
            {
                front_page();
                break;
            }
    }
}
void admin_options()
{
    int choice;
    while(true)
    {
        label:
        output();
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            {
                char ch;
                printf("If we create a file ,The existing file will be deleted\n");
                printf("Press y Or Y--->To create new file\n");
                printf("Press n-->To skip\n");
                fflush(stdin);
                scanf("%c",&ch);
                if(ch=='y'||ch=='Y')
                    {
                        create();
                    }
                break;
            }
        case 2:
            insert();
            break;
        case 3:
            display();
            break;
        case 4:
            search1();
            break;
        case 5:
            modify();
            break;
        case 6:
            delete1();
            break;
        case 7:
            userlogin();
            break;
        case 8:
            exit(0);
            break;
        case 9:
            redo();
            break;
        default:
            printf("Invalid choice\n");
            printf("Please enter your choice again\n");
            goto label;
                }
            }
}
int front_page()
{
   dsa:
    int final1;
    int rtn = 0;
    for (;;) {
    //system("cls");
    printf("\n\n\n\n\n\t\t\t\tWELCOME TO ADDRESS BOOK");
    printf("\nPress 1-For Admin\n");
    printf("Press 2-For User\n");
    printf("Press 3-To exit\n");
        rtn = scanf (" %d", &final1);
        printf("%d",rtn);
        if (rtn == EOF) {
            fputs ("(user canceled input.)\n", stderr);
            return 1;
        }
        else if (rtn == 0) {
            fputs (" error: invalid integer input.\n", stderr);
            empty_stdin();
        }
        else if (final1<1 || 3<final1) {
            fputs (" error: integer out of range [1-3]\n", stderr);
            empty_stdin();
        }
        else {
            empty_stdin();
            break;
        }
        system("pause");
    }
    if(final1==3)
    {
        printf("Thank you for your response!!!");
        printf("\n");
        system("pause");
    }
    else
    {
        loadingBar();
    }
    if(final1==1)
    {
        //system("cls");
        printf("\n\n\n\n\n\t\t\t\tWELCOME TO ADDRESS BOOK");
        printf("\n\t\t\t\t=====================");
        printf("\n\n\n\n\t\t\tPress Enter to proceed...!!");
        if(getch()==13)
            //system("cls");
        userlogin();
    }
    else if(final1==3)
    {
        exit(0);
    }
    else
    {
            //system("cls");
            printf("\n\n\n\n\n\t\t\t\tWELCOME TO ADDRESS BOOK");
            printf("\n\t\t\t\t=====================");
            printf("\n\n\n\n\t\t\tPress Enter to proceed...!!");
            if(getch()==13)
            {
                //system("cls");
            }
                int choice;
        while(true)
        {
            label:
            printf("Press 1-Display\n");
            printf("Press 2-To Back\n");
            scanf("%d",&choice);
            switch(choice)
            {
            case 1:
                search1();
                break;
            case 2:
                goto dsa;
                break;
            default:
                printf("Invalid choice\n");
                printf("Please enter your choice again\n");
                goto label;

            }
    }
    }
}
#endif // FRONT_H_INCLUDED
