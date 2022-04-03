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
char hodname[20];
int empcount;
}deptdb[10];


extern struct user userdb[];
extern struct department deptdb[];

extern void adminmodule(void);
