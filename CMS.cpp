#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include<fstream.h>

char username[20];
class Admin
{
	char name[25];
	int total_sub;
	char subject[15][15];
	char mobile[20],mail[50].father_name[30];
	char password[30],Recover_pswd[30];
	public:
	char rollno[20];

	void getstdata()
	{
		cout<<"\nEnter the Student Name: ";
		gets(name);
		cout<<"\nEnter the Student Roll No.: ";
		cin>>rollno;
		cout<<"\nEnter the student Father Name: ";
		gets(father_name);
		cout<<"\nEnter the Mobile No.: ";
		gets(mobile);
		cout<<"\nEnter the E-Mail ID: ";
		gets(mail);
		cout<<"\nEnter the Total Subjects: ";
		cin>>total_sun;

		for(int i=0;i<total_sub;i++)
		{
			cout<<"\nEnter the Subject "<<i+1<<" Name: ";
			cin>>subject[i];
		}

		cout<<"\nCreate Your Login Password: ";
		cin>>password;
		cout<<"\nEnter the Unique Keyword to Recover Password: ";
		cin>>Recover_pswd;
		cout<<"\n\nPlease note your Username is Roll No.: ";
	}

	int login()
	{
		if((strcmp(::username,rollno))==0)
		{
			cout<<"\nEnter the Login Password: ";
			int length=0;
			length=strlen(password);
			char input_pswd[30];
			for(int i=0;i<length;i++)
			{
				input_pswd[i]=getch();
				cout<"#";
			}
			input_pswd[i]=NULL;
			//cout<<"\nThe Entered Password is "<<input_pswd;
		if((strcmp(::un,rollno)==0)&&(strcmp(password,input_pswd)==0))
			return 1;
		else
			return 0;
		}
		else
			return 0;
	}

	int recover()
	{
		//cout<<"\nThe input Username is "<<:un;
		char key[20];
		if(strcmp(::username,rollno)==0)
		{
			cout<<"\nEnter the Unique Keyword (Provided by Admin) : ";
			cin>>key;
			if((strcmp(key,Recover_pswd)==0))
			{
				cout<"\nYou are a Valid User.";
				cout<<"\nYour Password is "<<password;
				cout<<"\nPlease exit to Login Again ";
				return 1;
			}
			else 
				return 0;
		}

		int Faculty_profile()
		{
			if((strcmp(::username,rollno)==0))
			{
				cout<<"\nFaculty Name              : "<<name;
				cout<<"\nFaculty Father's Name     : "<<father_name;
				cout<<"\nFaculty Mobile No.        : "<<mobile;
				cout<<"\nFaculty E-Mail ID         : "<<mail;
				return 1;
			}
			else
				return 0;
		}

		int Faculty_sub()
		{
			if((strcmp(::username,rollno))==0)
			{
				cout<<"\nFaculty Total Subjects : "<<total_sub;
				for(int i=0;i<total_sub;i++)
				{
					cout<<"\n\tSubject "<<i+1<<" : "<<subject[i];
				}
				return 1;
			}
			else 
				return 0;
		}

		void add_fasub()
		{
			if((strcmp(::username,rollno))==0)
			{
				cout<<"\nEnter the New Subject : ";
				cin>>subject[total_sub];
				total_sub++;
				cout<<"\n\nNew Subjects Added Successfully... ";
			}
		}

		void delet_fasub()
		{
			Faculty_sub();
			int d=0;
			if((strcmp(::username,rpllno))==0)
			{
				if(total_sub==0||total_sub<0)
				{
					total_sub=0;cout<<"\nNo Subject Entered... ";
					getch();
					exit(0);
				}
				cout<<"\nENter the Subjects No. to be Deleted : ";
				cin>>d;
				if(d==total_sub)
				{
					total_sub--;
					strcpy(subject[total_sub]," ");
				}
				else if(total_sub==1)
				{
					total_sub=0;
					strcpy(subject[total_sub]," ");
				}
				else
				{
					d--;
					strcpy(subject[total_sub]," ");
					for(int p=d;p<total_sub;p++)
					{
						strcpy(subject[p],subject[p+1]);
					}
					total_sub--;
				}
				cout<<"\nRecords Update Successfully... ";
			}
		}

		void modify_faprof()
		{
			if((strcmp(::username,rollno))==0)
			{
				cout<<"\nThe Profile Detailare : ";
				cout<<"\n 1. Faculty E-Mail : "<<mail;
				cout<<"\n w2. Faculty Mobile : "<<mobile;
				int g=-1;
				cout<<"\n\nEnter the Detail No. to be Modified :";
				cin>>g;
				if(g==1)
				{
					char new_mail[50];
					cout<<"\nEnter the New Mail Address: ";
					strcpy(mail,new_mail);
					cout<<"\nRecords Updated Successfully..";
				}
				else if(g==2)
				{
					char new_mobile[20];
					cout<<"\nEnter the New Mobile No. : ";
					gets(new_mobile);
					sttrcpy(mobile,new_mobile);
					cout<<"\nRecords Updated Successfully..";
				}
				else
					cout<<"\nInvalid Input Provided..";
			}
		}

		int Student_prof()
		{
			if((strcmp(::username,rollno))==0)
			{
				cout<<"\nStudent Name           : "<<name;
				cout<<"\nStudent Father's Name  : "<<father_name;
				cout<<"\nStudent Mobile No.     : "<<mobile;
				cout<<"\nStudent E-Mail ID      : "<<mail;
				return 1;
			}
			else
				return 0;
		}


		int Student_sub()
		{
			if((strcmp(::username,rollno))==0)
			{
				cout<<"\nStudent total subjects :- "<<total_sub;
				for(int i=0;i<total_sub;i++)
				{
					cout<<"\n\tSubjects "<<i+1<<" : "<<subject[i];
				}
				return 1;
			}
			else 
				return 0;
		}

		void add_stsub()
		{
			if((strcmp(::username,rollno))==0)
			{
				cout<<"\nEnter the New Subject : ";
				cin>>subject[total_sub];
				total_sub++;
				cout<<"\n\nNew Subject Added Successfully...";
			}
		}

		void delet_stsub()
		{
			Student_sub();
			int d1=0;
			if((strcmp(::username,rollno))==0)
			{
				if(total_sub==0||total_sub<0)
				{
					total_sub=0;
					cout<<"\nNo Subject Entered...";
					getch();
					exit(0);
				}
				cout<<"\nEnter the Subject No. to be Deleted : ";
				cin>>d1;
				if(d1==total_sub)
				{
					total_sub--;
					strcpy(subject[total_sub]," ");
				}
				else if(total_sub==1)
				{
					total_sub=0;
					strcpy(subject[total_sub]," ");
				}
				else
				{
					d1--;
					strcpy(subject[total_sub]," ");
					for(int i=d1;i<total_sub;i++)
					{
						strcpy(subject[i],subject[i+1]);
					}
					total_sub--;
					cout<<"\nRecords updates successfully...";
				}
			}
		}

		void modify_stprof()
		{
			if((strcmp(::username,rollno))==0)
			{
				cout<<"\nThe Profile Details are : ";
				cout<<"\n 1. Student E-Mail : "<<mail;
				cout<<"\n 2. Student Mobile : "<<mobile;
				int f=-1;
				cout<<"\n\nEnter the Detail No. to be Modified : ";
				cin>>f;
				if(f==1)
				{
					char new_mail[50];
					cout<<"]\nEnter the New Maail Address : ";
					strcpy(mail,new_mail);
					cout<<"\nRecord Added Successfully...";
				}
				else if(f==2)
				{
					char new_mobile[20];
					cout<<"\nEnter the New Mobile No. : ";
					gets(new_mobile);
					strcpy(mobile,new_mobile);
					cout<<"\nRecords Updated Successfully...";
				}
				else
					cout<<"\nInvalid Input Provided...";
			}
		}

		void faculty_data()
		{
			cout<<"\nEnter the Faculty Name : ";
			gets(name);
			cout<<"\nEnter the Faculty Roll No. : ";
			cin>>rollno;
			cout<<"\nEnter the Faculty Father's Name : ";
			gets(father_name);
			cout<<"\nEnter the Mobile No. : ";
			gets(mobile);
			cout<<"\nEnter the E-Mail ID : ";
			gets(mail);
			cout<<"\nENter the Total Subjects : ";
			cin>>total_sub;
			//cout<<"\nThe Total Subjects choosen are : "<<total_sub;
			for(int i=0;i<total_sub;i++)
			{
				cout<<"\nEnter the Subject "<<i+1<<":"<<" Name : ";
				cin>>subject[i];
			}
			cout<<"\ncreate Your Login password : ";
			cin>>password;
			cout<<"\nENter the Unique Keyword to Recover Pssword : ";
			cin>>Recover_pswd;
			cout<<"\n\nPlease note your Username is ID/Roll No.\n";
		}


		void st_display()
		{
			cout<<"\nStudent Name             : "<<name;
			cout<<"\nStudent Roll No.         : "<<rollno;
			cout<<"\nStudent Father's Name    : "<<father_name;
			cout<<"\nStudent Mobile No.       : "<<mobile;
			cout<<"\nStudent E-mail ID        : "<<mail;
			cout<<"\nStudent Subjects         : "<<total_sub;

			for(int i=0;i<total_sub;i++)
			{
				cout<<"\n  Subject "<<i+1<<" : "<<subject[i];
			}
			if(total_sub==0)
				cout<<"( No Subject Specified... )";
		}

		void fa_display()
		{
			cout<<"\nFaculty Name             : "<<name;
			cout<<"\nFaculty ID/Roll no.      : "<<rollno;
			cout<<"\nFaculty Father's Name    : "<<father_name;
			cout<<"\nFaculty Mobile No.       : "<<mobile;
			cout<<"\nFaculty E-mail ID        : "<<mail;
			cout<<"\nFaculty Subjects         : "<<total_sub;

			for(int i=0;i<total_sub;i++)
			{
				cout<<"\n  Subject "<<i+1<<" : "<<subject[i];
			}
			if(total_sub==0)
				cout<<" No Subject Specified....";
		}
	}a;
	Admin M;
	//a & M are the objects of the class Admin


