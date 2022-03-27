#include<stdio.h>
#include<string.h>

struct user
{
char usertype[20];
int userid;
char username[20];
int deptid;
int password;
}userdb[10];

struct department
{
int deptid;
char deptname[20];
char manager[20];
int empcount;
}deptdb[10];

struct spending
{
int spendingid;
char spendingname[20];
int userid;
int deptid;
float amount;
int isrefundreq;
int isrefunded;
}spendingdb[10];


static int userindex=1,deptindex=1,spendingindex=0;

void adminmodule()
{
	int pass,option;
	printf("\nEnter your password:");
	scanf("%d",&pass);
	if(pass==userdb[0].password)
	{
		printf("Logged in successfully!!");
		printf("\nWELCOME ADMIN\n");
	}
	else
	{
		printf("PASSWORD INCORRECT");
		return;
	}
	while(1)
	{
	printf("\n\n1.Add Department\n2.View Department\n3.Edit Department\n4.Add User\n5.View User\n6.Edit User\n7.Add spending\n8.View spending\n9.Edit spendings\n10.Logout\n");		
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
		case 4:adduser();
				break;
		case 5:displayuser();
				break;
		case 6:edituser();
				break;		
		case 7:addspending();
				break;
		case 8:displayspending();
				break;
		case 9:editspending();
				break;
		case 10:printf("LOGGED OUT SUCCESSFULLY\n");
				return;
		default:printf("Invalid choice");
	}
	}
	
	
}

void accountantmodule()
{
	int id,pass,option;
	printf("\nEnter your userid:");
	scanf("%d",&id);
	if(id>=userindex || id<=0)
	{
		printf("\nINVALID USER-ID\n");
		return;
	}
	printf("Enter your password:");
	scanf("%d",&pass);
	if(pass==userdb[id].password && (strcmp(userdb[id].usertype,"Accountant")==0))
	{
		printf("Logged in successfully!!");
		printf("\nWelcome %s!!\n",userdb[id].username);
	}
	else
	{
		printf("\nINVALID PASSWORD\n");
		return;
	}
	while(1)
	{
	printf("\n\n1.Add spending\n2.View spending\n3.Edit spendings\n4.View refund requests\n5.Logout\n");		
	printf("Choose an action:");
	scanf("%d",&option);
	switch(option)
	{
		case 1:addspending();
				break;
		case 2:displayspending();
				break;
		case 3:editspending();
				break;
		case 4:displayrefundreq();
				break;
		case 5:printf("LOGGED OUT SUCCESSFULLY\n");
				return;
		default:printf("Invalid choice");
	}
	}		
}

void normalusermodule()
{
	int id,pass,option;
	printf("\nEnter your userid:");
	scanf("%d",&id);
	if(id>=userindex || id<=0)
	{
		printf("\nINVALID USER-ID\n");
		return;
	}
	printf("Enter your password:");
	scanf("%d",&pass);
	if(pass==userdb[id].password && (strcmp(userdb[id].usertype,"User")==0))
	{
		printf("Logged in successfully!!");
		printf("\nWelcome %s!!\n",userdb[id].username);
	}
	else
	{
		printf("\nINVALID PASSWORD\n");
		return;
	}
	while(1)
	{
	printf("\n\n1.Add refund request\n2.Logout\n");		
	printf("Choose an action:");
	scanf("%d",&option);
	switch(option)
	{
		case 1:addrefundreq(id);
				break;
		case 2:printf("LOGGED OUT SUCCESSFULLY\n");
				return;
		default:printf("Invalid choice");
	}
	}
		
}

void adddepartment()
{
		printf("\nEnter details\n");
		deptdb[deptindex].deptid=deptindex;
		printf("Departname:");
		scanf("%s",deptdb[deptindex].deptname);
		printf("Manager:");
		scanf("%s",deptdb[deptindex].manager);
		printf("Number of employees:");	
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
		printf("\n1.DEPARTMENTNAME\n2.MANAGERNAME\n3.NUMBER OF EMPLOYEES\n4.MAIN MENU\n");
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
					scanf("%s",deptdb[dep].manager);
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
	printf("DEPARTMENTID\tDEPARTMENTNAME\tMANAGERNAME\tNUMBER OF EMPLOYEES\n");
	for(int i=1;i<deptindex;i++)
	{
		printf("\t%d\t\t%s\t\t%s\t\t\t%d\n",deptdb[i].deptid,deptdb[i].deptname,deptdb[i].manager,deptdb[i].empcount);
	}
	
}

void adduser()
{
	
		printf("\nEnter details\n");
		userdb[userindex].userid=userindex;
		printf("Enter usertype(Accountant/User):");
			scanf("%s",userdb[userindex].usertype);
		if(strcmp(userdb[userindex].usertype,"Accountant")!=0 && strcmp(userdb[userindex].usertype,"User")!=0 )
			{
				printf("\nINVALID USER TYPE!!\n");
				return;
			}
		printf("Enter username:");
		scanf("%s",userdb[userindex].username);
		printf("Departmentid:");
		scanf("%d",&userdb[userindex].deptid);
		if(userdb[userindex].deptid>=deptindex || userdb[userindex].deptid<=0 )
			{
				printf("\nINVALID DEPARTMENT-ID!!\n");
				return;
			}
		printf("Password:");
		scanf("%d",&userdb[userindex].password);	
		userindex++;
		printf("USER ADDED SUCCESSFULLY\n\n");
}

void edituser()
{
	int u,option;
	displayuser();
	printf("\nEnter the user-id to edit:");
	scanf("%d",&u);
	if(u>=userindex || u<=0)
		{
		printf("\nINVALID USER-ID!!\n");
		return;
		}
	while(1)
	{
		int tempdata;
		char temp[20];
		printf("\n1.USERTYPE\n2.USERNAME\n3.DEPARTMENTID\n4.PASSWORD\n5.MAIN MENU\n");
		printf("Choose item to edit:");
		scanf("%d",&option);
		
		switch(option)
		{
			case 1:printf("Enter the new value:");
					scanf("%s",temp);
					if(strcmp(temp,"Accountant")!=0 && strcmp(temp,"User")!=0 )
					{
						printf("\nINVALID USER TYPE!!\n");
						break;
					}
					strcpy(userdb[u].usertype,temp);
					printf("UPDATED SUCCESSFULLY!");
					displayuser();
					break;
			case 2:printf("Enter the new value:");
					scanf("%s",userdb[u].username);
					printf("UPDATED SUCCESSFULLY!");
					displayuser();
					break;
			case 3:printf("Enter the new value:");
					scanf("%d",&tempdata);
					if(tempdata>=deptindex || tempdata<=0 )
					{
						printf("\nINVALID DEPARTMENT-ID!!\n");
						break;
					}
					userdb[u].deptid=tempdata;
					printf("UPDATED SUCCESSFULLY!");
					displayuser();
					break;
			case 4:printf("Enter the new value:");
					scanf("%d",&userdb[u].password);
					printf("UPDATED SUCCESSFULLY!");
					displayuser();
					break;
			case 5:return;
			default:printf("Invalid choice");
		}	
	}
}

void displayuser()
{
	if(userindex==1)
	{
	printf("\nNO USERS HAVE BEEN ADDED BY ADMIN YET!!\n");
	return;
	}
	printf("\nUSER DETAILS\n");
	printf("USERTYPE\tUSERID\tUSERNAME\tDEPARTMENTID\tPASSWORD\n");
	for(int i=1;i<userindex;i++)
	{
		printf("%s\t\t%d\t%s\t\t%d\t\t%d\n",userdb[i].usertype,userdb[i].userid,userdb[i].username,userdb[i].deptid,userdb[i].password);
	}
}

void addspending()
{
		printf("\nEnter details\n");
		spendingdb[spendingindex].spendingid=spendingindex;
		spendingdb[spendingindex].isrefundreq=0;
		spendingdb[spendingindex].isrefunded=0;
		printf("Spending purpose:");
		scanf("%s",spendingdb[spendingindex].spendingname);
		printf("Enter userid:");
		scanf("%d",&spendingdb[spendingindex].userid);
		if(spendingdb[spendingindex].userid>=userindex || spendingdb[spendingindex].userid<=0 )
		{
				printf("\nINVALID USER-ID!!\n");
				return;
		}
		printf("Departmentid:");
		scanf("%d",&spendingdb[spendingindex].deptid);
		if(spendingdb[spendingindex].deptid>=deptindex || spendingdb[spendingindex].deptid<=0 )
		{
				printf("\nINVALID DEPARTMENT-ID!!\n");
				return;
		}
		printf("Amount:");
		scanf("%f",&spendingdb[spendingindex].amount);
		spendingindex++;
		printf("SPENDING ADDED SUCCESSFULLY\n\n");
}

void displayspending()
{
	if(spendingindex==0)
		{
		printf("\nNO SPENDINGS HAVE BEEN ADDED YET!!\n");
		return;
		}
	printf("\nSPENDING DETAILS\n");
	printf("SPENDINGID\tSPENDINGNAME\tUSERID\tDEPARTMENTID\tAMOUNT\tREFUNDREQUEST(1-YES/0-NO)\tREFUNDED(1-YES/0-NO)\n");
	for(int i=0;i<spendingindex;i++)
	{
		printf("\t%d\t%s\t\t%d\t\t%d\t%g\t\t%d\t\t\t\t%d\n",spendingdb[i].spendingid,spendingdb[i].spendingname,spendingdb[i].userid,spendingdb[i].deptid,spendingdb[i].amount,spendingdb[i].isrefundreq,spendingdb[i].isrefunded);
	}
	
}



void editspending()
{
	int id,option;
	displayspending();
	printf("\nEnter the spending-id to edit:");
	scanf("%d",&id);
	if(id>=spendingindex || id<0)
		{
			printf("\nINVALID SPENDING-ID!!\n");
			return;
		}
	while(1)
	{
		int tempdata;
		printf("\n1.SPENDING PURPOSE\n2.USERID\n3.DEPARTMENTID\n4.AMOUNT\n5.REFUNDED\n6.MAIN MENU\n");
		printf("Choose item to edit:");
		scanf("%d",&option);
		
		switch(option)
		{
			case 1:printf("Enter the new value:");
					scanf("%s",spendingdb[id].spendingname);
					printf("UPDATED SUCCESSFULLY!");
					displayspending();
					break;
			case 2:printf("Enter the new value:");
					scanf("%d",&tempdata);
					if(tempdata>=userindex || tempdata<=0 )
					{
						printf("\nINVALID USER-ID!!\n");
						break;
					}
					spendingdb[id].userid=tempdata;
					printf("UPDATED SUCCESSFULLY!");
					displayspending();
					break;
			case 3:printf("Enter the new value:");
					printf("Departmentid:");
					scanf("%d",&tempdata);
					if(tempdata>=deptindex || tempdata<=0 )
					{
						printf("\nINVALID DEPARTMENT-ID!!\n");
						break;
					}
					spendingdb[id].deptid=tempdata;
					printf("UPDATED SUCCESSFULLY!");
					displayspending();
					break;
			case 4:printf("Enter the new value:");
					scanf("%f",&spendingdb[id].amount);
					printf("UPDATED SUCCESSFULLY!");
					displayspending();
					break;
			case 5:printf("1-Yes 0-No:");
					scanf("%d",&spendingdb[id].isrefunded);
					printf("UPDATED SUCCESSFULLY!");
					displayspending();
					break;
			case 6:return;
			default:printf("Invalid choice");
		}	
	}
}

void addrefundreq(int id)
{
		int flag=0;
		float amount;
		printf("\nEnter details\n");
		printf("Amount:");
		scanf("%f",&amount);
		for(int i=0;i<spendingindex;i++)
		{
			if((spendingdb[i].userid==id)&&(spendingdb[i].amount==amount))
			{
				spendingdb[i].isrefundreq=1;
				printf("\nYOUR REQUEST HAS BEEN ACCEPTED\nYOU WILL BE REFUNDED SOON!!!\n\n");
				flag=1;
				break;
			}
		}
		if(flag==0)
		{
			printf("INVALID REQUEST...YOUR SPENDING IS NOT ADDED FOR REFUND YET!!!\n\n");
		}	
}
void displayrefundreq()
{
	int flag=0;
	for(int i=0;i<spendingindex;i++)
	{
		if(spendingdb[i].isrefundreq==1)
		{
			if(flag==0)
			{
				printf("\nREFUND-REQUEST DETAILS\n");
				printf("\nUSERID\tDEPARTMENTID\tSPENDING PURPOSE\tAMOUNT\n");
			}
			flag=1;
			printf("%d\t\t%d\t%s\t\t\t%g\n",spendingdb[i].userid,spendingdb[i].deptid,spendingdb[i].spendingname,spendingdb[i].amount);
		}
	}
	if(flag==0)
	printf("\nNO REFUND REQUESTS HAS BEEN GIVEN BY ANY USERS!!\n");
}

int main()
{	
	strcpy(userdb[0].usertype,"Admin");
	userdb[0].userid=0;
	userdb[0].deptid=0;
	strcpy(userdb[0].username,"admin");
	userdb[0].password=12345;
	
	deptdb[0].deptid=0;
	strcpy(deptdb[0].deptname,"Admin");
	deptdb[0].empcount=1;
	deptdb[0].manager[0]='\0';
	
	int userchoice;
	char userid[50];
	while(1)
	{
	printf("\n\n!!LOGIN!!\n");
	printf("\n1.Admin\n2.Accountant\n3.Normal User\n4.Exit");
	printf("\n\nChoose an option to login:");
	scanf("%d",&userchoice);
	switch(userchoice)
	{
		case 1:adminmodule();
			   break;
		case 2:accountantmodule();
				break;
		case 3:normalusermodule();
				break;
		case 4:exit(1);
		default:printf("Invalid choice");			
	}
}
}
