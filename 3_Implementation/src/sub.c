#include<stdio.h>
#include<string.h>
#include "adm.h"

void adminmodule()
{
	int pass,option;
	printf("\nEnter your password:");
	scanf("%d",&pass);
	if(pass==userdb[0].password)
	{
		printf("Logged in successfully!!\n");
		printf("------------------");
        printf("\n  WELCOME ADMIN\n");
        printf("------------------");
	}
	else
	{
		printf("PASSWORD INCORRECT");
		return;
	}

	while(1)
	{
	printf("\n\n1.Add Department\n2.View Department\n3.Edit Department\n4.Logout\n");
	printf("Choose an action:");
	scanf("%d",&option);
	switch(option)
	{
		case 1:adddepartment();
				break;
		case 2:displaydepartment();
				break;
		case 3:editdepartment();
				break;
		case 4:printf("LOGGED OUT SUCCESSFULLY\n");
				return;
		default:printf("Invalid choice");
	}
	}
}
