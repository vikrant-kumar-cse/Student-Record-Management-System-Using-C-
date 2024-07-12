#include<stdio.h>
#include<conio.h>
struct Student
{
	char Name[100];
	int roll;
	char branch[100];
};
void write()
{
   system("cls");
   printf("\t\t\t\t\t\t\t ADD STUDENT INFORMATIONS\n");
   printf("\n");
   struct Student s1;
   FILE *fptr;
   fptr=fopen("Student2.txt","a");
   printf("\t\t\t\t\t\t Enter your Name\n");
   printf("\t\t\t\t\t\t");
   scanf("%s",s1.Name);
   printf("\t\t\t\t\t\t Enter your Roll N0\n");
   printf("\t\t\t\t\t\t");
   scanf("%d",&s1.roll);
   printf("\t\t\t\t\t\t Enter your Branch\n");
   printf("\t\t\t\t\t\t");
   scanf("%s",s1.branch);
   fwrite(&s1,sizeof(s1),1,fptr);
   fclose(fptr);  	
}
void read()
{
	struct Student s1;
	FILE *fptr;
	fptr=fopen("Student2.txt","r");
	while(fread(&s1,sizeof(s1),1,fptr)>0)
	{
		printf("\t\t\t\t_______________________________\n");
		printf("\t\t\t\t Name:%s\n",s1.Name);
		printf("\t\t\t\t Roll_No:%d\n",s1.roll);
		printf("\t\t\t\t Branch:%s\n",s1.branch);
		printf("\t\t\t\t_______________________________\n");	
	}
	fclose(fptr);
}
void search()
{
	printf("\t\t\t\t\t\t SEARCH THE STUDENT\n");
	printf("\n");
	struct Student s1;
	int roll;
	printf("\t\t\t\t\t\Enter the Roll_no\n");
	printf("\t\t\t\t\t\\n");
	scanf("%d",&roll);
	FILE *fptr;
	int flag;
	fptr=fopen("Student2.txt","r");
	while(fread(&s1,sizeof(s1),1,fptr)>0)
	{
		if(roll==s1.roll)
		{
			flag=1;
			printf("\t\t\t\t\t\t\t_________________________\n");
			printf("\t\t\t\t\t\t\t %s\n",s1.Name);
			printf("\t\t\t\t\t\t\t %d\n",s1.roll);
			printf("\t\t\t\t\t\t\t %s\n",s1.branch);
		}
		if(flag==0)
		{
			printf("User Not Found\n");
		}
	}
	fclose(fptr);
}
int main()
{
	int choice;
	do
	{
		printf("\t\t\t\t\t STUDENT MANAGEMENT SYSTEM \n");
		printf("\t\t\t\t\t\n");
		printf("\t\t\t\t\t 1.Addd Student\n");
		printf("\t\t\t\t\t 2.Watch All Student Informations\n");
		printf("\t\t\t\t\t 3.For Searching the student\n");
		printf("\t\t\t\t\t 4. Exit\n");
		printf("\t\t\t\t\t________________________________\n");
		printf("\t\t\t\t\t");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:system("cls");
			       write();
			       system("cls");
			       break;
			case 2:system("cls");
			       read();
			       getch();
			       system("cls");
			       break;
			case 3:system("cls");
			       search();
			       getch();
			       system("cls");
			       break;
		    default:
		    	system("cls");
		    	printf("\t\t\t\tINVALID OPTION\n");
		    	system("cls");
		    	break;
		}		
	}while(choice);
}