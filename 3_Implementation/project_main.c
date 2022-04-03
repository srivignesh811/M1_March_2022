
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "adm.h"

static int userindex=1,deptindex=1;

void adddepartment()
{
		printf("\nEnter details:\n");
		deptdb[deptindex].deptid=deptindex;
		printf("Departmentname:");
		scanf("%s",deptdb[deptindex].deptname);
		printf("Department Hod name:");
		scanf("%s",deptdb[deptindex].hodname);
		printf("Number of Employees:");
		scanf("%d",&deptdb[deptindex].empcount);
		deptindex++;
		printf("DEPARTMENT ADDED SUCCESSFULLY\n\n");
}

void editdepartment()
{
	int dep,option;
	displaydepartment();
	printf("\nEnter the department-id to edit:");
	scanf("%d",&dep);
	if(dep>=deptindex || dep<=0)
	{
		printf("\nINVALID DEPARTMENT-ID!!\n");
		return;
	}

while(1)
	{
		printf("\n1.DEPARTMENTNAME\n2.DEPARTMENT HOD NAME\n3.NUMBER OF EMPLOYEES\n4.MAIN MENU\n");
		printf("Choose item to edit:");
		scanf("%d",&option);

		switch(option)
		{
			case 1:printf("Enter the new value:");
					scanf("%s",deptdb[dep].deptname);
					printf("UPDATED SUCCESSFULLY!");
					displaydepartment();
					break;
			case 2:printf("Enter the new value:");
					scanf("%s",deptdb[dep].hodname);
					printf("UPDATED SUCCESSFULLY!");
					displaydepartment();
					break;
			case 3:printf("Enter the new value:");
					scanf("%d",&deptdb[dep].empcount);
					printf("UPDATED SUCCESSFULLY!");
					displaydepartment();
					break;
			case 4:return;
			default:printf("Invalid choice");
		}
	}
}

void displaydepartment()
{
	if(deptindex==1)
	{
		printf("\nNO DEPARTMENTS HAS BEEN ADDED YET!!\n");
		return;
	}
	printf("\nDEPARTMENT DETAILS\n");
	printf("DEPARTMENTID\tDEPARTMENTNAME\tDEPARTMENT HOD NAME\tNUMBER OF EMPLOYEES\n");
	for(int i=1;i<deptindex;i++)
	{
		printf("\t%d\t\t%s\t\t%s\t\t\t%d\n",deptdb[i].deptid,deptdb[i].deptname,deptdb[i].hodname,deptdb[i].empcount);
	}

}

int main()
{
	strcpy(userdb[0].usertype,"Admin");
	userdb[0].userid=0;
	userdb[0].deptid=0;
	strcpy(userdb[0].username,"admin");
	userdb[0].password=123;

    deptdb[0].deptid=0;
	strcpy(deptdb[0].deptname,"Admin");
	deptdb[0].empcount=1;
	deptdb[0].hodname[0]='\0';

	int userchoice;
	char userid[50];
	while(1)
	{
    printf("----------");
	printf("\n  LOGIN\n");
    printf("----------");
	printf("\n1.Admin\n2.HOD\n3.Exit");
	printf("\n\nChoose an option to login:");
	scanf("%d",&userchoice);
	switch(userchoice)
	{
		case 1:adminmodule();
			   break;
		case 2:displaydepartment();
               break;
        case 3:break;
		default:printf("Invalid choice");
	}
}
}
