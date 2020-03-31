#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include<conio.h>
#include<fstream>

using namespace std;

char username[20];

class Admin
{
	char name[25];
	int total_sub;
	char subject[15][15];
	char mobile[20],mail[50],father_name[30];
	char password[30],Recover_pswd[30];
	public:
	char rollno[20];

	void getstdata()
	{
		cout<<"\nEnter the Student Name: ";
		cin>>name;
		cout<<"\nEnter the Student Roll No.: ";
		cin>>rollno;
		cout<<"\nEnter the student Father Name: ";
		cin>>father_name;
		cout<<"\nEnter the Mobile No.: ";
		cin>>mobile;
		cout<<"\nEnter the E-Mail ID: ";
		cin>>mail;
		cout<<"\nEnter the Total Subjects: ";
		cin>>total_sub;

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
			int i;
			for( i=0;i<length;i++)
			{
				input_pswd[i]=getch();
				cout<<"#";
			}
		   input_pswd[i]='\0';
        //cout<<"\nThe Entered Password is "<<input_pswd;
		if((strcmp(::username,rollno)==0)&&(strcmp(password,input_pswd)==0))
			return 1;
		else
			return 0;
		}
		else
			return 0;
	}

	int recover()
	{
		//cout<<"\nThe input Username is "<<::username;
		char key[20];
		if(strcmp(::username,rollno)==0)
		{
			cout<<"\nEnter the Unique Keyword (Provided by Admin) : ";
			cin>>key;
			if((strcmp(key,Recover_pswd)==0))
			{
				cout<<"\nYou are a Valid User.";
				cout<<"\nYour Password is "<<password;
				cout<<"\nPlease exit to Login Again ";
				return 1;
			}
			else
				return 0;
		}
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
			if((strcmp(::username,rollno))==0)
			{
				if(total_sub==0||total_sub<0)
				{
					total_sub=0;cout<<"\nNo Subject Entered... ";
					system("PAUSE");
				        exit(0);
				}
				cout<<"\nEnter the Subjects No. to be Deleted : ";
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
				cout<<"\nThe Profile Detail are : ";
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
					cin>>new_mobile;
					strcpy(mobile,new_mobile);
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
					system("pause");
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
					cout<<"]\nEnter the New Mail Address : ";
					strcpy(mail,new_mail);
					cout<<"\nRecord Added Successfully...";
				}
				else if(f==2)
				{
					char new_mobile[20];
					cout<<"\nEnter the New Mobile No. : ";
					cin>>new_mobile;
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
            cin>>name;
            cout<<"\nEnter the Faculty Roll No. : ";
			cin>>rollno;
			cout<<"\nEnter the Faculty Father's Name : ";
		    cin>>father_name;
			cout<<"\nEnter the Mobile No. : ";
			cin>>mobile;
			cout<<"\nEnter the E-Mail ID : ";
			cin>>mail;
			cout<<"\nEnter the Total Subjects : ";
			cin>>total_sub;
			//cout<<"\nThe Total Subjects choosen are : "<<total_sub;
			for(int i=0;i<total_sub;i++)
			{
				cout<<"\nEnter the Subject "<<i+1<<":"<<" Name : ";
				cin>>subject[i];
			}
			cout<<"\nCreate Your Login password : ";
			cin>>password;
			cout<<"\nEnter the Unique Keyword to Recover Password : ";
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
				cout<<"(\n No Subject Specified... \n)";
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
				cout<<"\nSubject    "<<i+1<<" : "<<subject[i]<<endl;
			}
			if(total_sub==0)
				cout<<"\n\nNo Subject Specified....\n";
           // system("PAUSE");
           // exit(0);

		}
	}a;
    Admin m;
	//a & M are the objects of the class Admin

	int main()
	{
		int ch;
		system("CLS");
		cout<<"\n\n\n\t\t\tWelcome to IPEC Database Portal ";
		cout<<"\n\n\n\t\t\t\tEnter to Continue ";
		system("PAUSE");
         	system("CLS");

		cout<<"\n\n\n\t\t\tPress 1 for Admin Portal";
		cout<<"\n\t\t\tPress 2 for Faculty Portal";
		cout<<"\n\t\t\tPress 3 for Student Portal";
		cout<<"\n\n\t\t\tEnter Your Choice : ";
		cin>>ch;
		system("CLS");
		if(ch==1)
		{
			char adminuser[20],adminpass[20];
			cout<<"\n\t\t\tWelcome To Admin Login Portal ";
			cout<<"\n\nEnter the User Name : ";
			cin>>adminuser;
			cout<<"\nEnter the Password : ";
			int k;
			for(k=0;k<8;k++)
			{
				adminpass[k]=getch();
				cout<<"*";
			}
		        system("PAUSE");
			adminpass[k]='\0';
			if((strcmp(adminuser,"admin")==0)&&(strcmp(adminpass,"password")==0))
			{
		    system("CLS");
			}
			else
			{
				cout<<"\n\n\t\t\t  Invalid Access to Portal ";
				cout<<"\n\n\t\t\t\tThank You !!!";
				system("PAUSE");
				exit(0);
			}
			char op='y';

			do
			{
				int tmp;
				cout<<"\n\t\t\t\tWelcome To Admin Panel";
				cout<<"\n\nPress 1 to Add a Faculty Record ";
				cout<<"\nPress 2 Add Multiple Records of Faculty ";
				cout<<"\nPress 3 to View All Records of Faculty ";
				cout<<"\nPress 4 to Delete a faculty Record ";
				cout<<"\nPress 5 to Add a Student Record ";
				cout<<"\nPress 6 to Add Multiple Records of Students ";
				cout<<"\nPress 7 to View All Records Of Students ";
				cout<<"\nPress 8 to Delete a Student Rcord ";
				cout<<"\nPress 9 to Exist ";
				cout<<"\n\n\t Enter Your Choice : ";
				cin>>tmp;
				system("CLS");
				if(tmp==1) //for inserting single faculty record
				{
					cout<<"\n\tEnter the Details : \n";
					fstream fs;
					fs.open("fainfo.txt",ios::in|ios::out|ios::ate);
					a.faculty_data();
					fs.write((char *)&a,sizeof(Admin));
					fs.close();
					cout<<"\nRecord Entered Successfully...";
				}

				if(tmp==2)  // for inserting multiple faculty record
				{
					int m=0;
					fstream fs;
					fs.open("fainfo.txt",ios::in|ios::out|ios::ate);
					do
					{
						cout<<"\nEnter the Details : ";
						a.faculty_data();
						fs.write((char *)&a,sizeof(Admin));
						cout<<"\nPress 0 if you want to Enter More Records : ";
						cin>>m;
					}while(m==0);
					fs.close();
					cout<<"\nRecord Entered Successfully...";
				}

				if(tmp==3)   //for view all faculty records
				{
					fstream fs;
					fs.open("fainfo.txt",ios::in);
					fs.seekg(0);
					while(!fs.eof())
					{
						fs.read((char *)&a,sizeof(Admin));
						a.fa_display();
					}
					fs.close();
					exit(0);
				}

				if(tmp==4)  //for deleting a faculty record
				{
					char fa_id[20];
					int d=0,result=-1;
					cout<<"\nEnter the Faculty ID/Roll No. : ";
					cin>>fa_id;
					ifstream inFile;
					inFile.open("fainfo.dat",ios::binary);
					ofstream outFile;
					outFile.open("fanewinfo.dat",ios::binary);
					while(!inFile.eof())
					{
						inFile.read((char *)&a,sizeof(Admin));
						result=strcmp(fa_id,a.rollno);
						if(result==0)
						{
							d=1;
						}
						else
							outFile.write((char *)&a,sizeof(Admin));
					}
					if(d==1)
					{
						cout<<"\nRecord Deleted Successfully...";
					}
					else
					{
						cout<<"\nRecord not Found...";
					}
					inFile.close();
					outFile.close();
					remove("fainfo.dat");
					rename("fanewinfo.dat","fainfo.dat");
				}

				if(tmp==5)   //for single  student record
				{

					cout<<"\nEnter the Details : ";
					fstream fs;
					fs.open("st_info.txt",ios::in|ios::out|ios::ate);
					a.getstdata();
					fs.write((char *)&a,sizeof(Admin));
					fs.close();
					cout<<"\nRecord Entered Successfully...";
				}

				if(tmp==6) //for multiple input record
				{
					int m=0;
					fstream fs;
					fs.open
					("st_info.txt",ios::in|ios::out|ios::ate);
					do
					{
						cout<<"\nEnter the Details : ";
						a.getstdata();
						fs.write((char *) &a,sizeof(Admin));
						cout<<"\nPress 0 if you want to Enter More Records : ";
						cin>>m;
					}while(m==0);
					fs.close();
					cout<<"\nRecord Entered Successfully...";
				}

				if(tmp==7)  //for view of all student record
				{
					fstream fs;
					fs.open("st_info.txt",ios::in);
					fs.seekg(0);
					while(!fs.eof())
					{
						fs.read((char *)&a,sizeof(Admin));
						a.st_display();
					}
					fs.close();
					//exit(0);
				}

				if(tmp==8)   // for deleting a student record
				{
					char st_id[20];
					int d=0,result=-1;
					cout<<"\nEnter the Student ID/Rollno : ";
					cin>>st_id;
					fstream fs;
					fs.open("st_info.txt",ios::in);
					fstream fs1;
					fs1.open("st_new_info.txt",ios::out|ios::ate);
					while(!fs.eof())
					{
						fs.read((char *)&a,sizeof(Admin));
						result=strcmp(st_id,a.rollno);
						if(result==0)
						{
							d=1;
						}
						else
							fs1.write((char *)&a,sizeof(Admin));
					}
					if(d==1)
					{
						cout<<"\nRecord Deleted Successfully...";
					}
					else
					{
						cout<<"\nRecord not found...";
					}
					fs.close();
					fs1.close();
					remove("st_info.txt");
					rename("st_new_info.txt","st_info.txt");
				}

				if(tmp==9)    //for exit
				{
					cout<<"\n\n\n\n\t\t\t\tThank You !!!";
					system("PAUSE");
					exit(0);
				}

				if(tmp<1||tmp>9)  //for invalid input
				{
			         	system("CLS");
					cout<<"\n\n\n\t\t\t\tInvalid Input....... ";
				}
				system("PAUSE");
				cout<<"\n\nPress y for more opertion otherwise n :";
				cin>>op;
				if(op!='y')
				{
					system("PAUSE");
					system("CLS");
					cout<<"\n\n\n\n\n\t\t\t\t\tThank you !!!";
					system("PAUSE");
				}
			}while(op=='Y'||op=='y');
		}//closing Admin Login

      	if(ch==2)  //begin of faculty view portal
		{
		    system("CLS");
			char username[20];
			int val,s=0;
			cout<<"\n\t\tWelcome to Faculty Login Page";
			cout<<"\n\nEnter the UserName : ";
			cin>>::username;
			fstream fs;
			fs.open("fainfo.txt",ios::in|ios::binary);
			fs.seekg(0);
			while(!fs.eof())
			{
				val=-1;
				fs.read((char *)&m,sizeof(Admin));
				val=m.login();
				if(val==1)
				{
					s=1;
					break;
				}
			}
				fs.close();
				if(s==1)
				{
				    system("CLS");
				} //if first login valid

				if(s!=1)//if first login in-valid
				{
				    system("CLS");
					int h=0;
					cout<<"\n\n\t\tYour Login Credentials are In-Correct";
					cout<<"\nThe UserName is Your ID/Roll No.";
					cout<<"\nThe Password is Case-Sensitive.";
					cout<<"\nPress 1 to Re-Cover Password & 2 to Re-Attempt Login ";
					cout<<"\nEnter the Choice : ";
					cin>>h;
					if(h==1)  //recover password
					{
						cout<<"Enter the UserName : ";
						cin>>::username;
						fstream fs;
						fs.open
						("fainfo.txt",ios::in|ios::binary);
						fs.seekg(0);
						int r,s=-1;
						while(!fs.eof())
						{
							r=-1;
							fs.read((char *)&m,sizeof(Admin));
							r=m.recover();
							if(r==1)
							{
								s=1;
								break;
							}
						}
						fs.close();
						if(s==1)
						{
							system("PAUSE");
							system("CLS");
							cout<<"\n\n\n\n\t\t\tThank You !!! ";
							system("PAUSE");
							exit(0);
						}
						else
						{
							cout<<"\nYou are a Invalid User.";
							system("PAUSE");
							exit(0);
						}
      				}//recover password

      				if(h==2)//re-attempt of login
                    {
                        cout<<"\n\nEnter the UserName : ";
                        cin>>::username;
                        fstream fs;
                        fs.open
                        ("fainfo.txt",ios::in|ios::binary);
                        fs.seekg(0);
                        int s1=-1,val;   //val for storing login() returnd value s for success login

                        while(!fs.eof())
                        {
                            val=-1;
                            fs.read((char *)&m,sizeof(Admin));
                            val=m.login();
                            if(val==1)
                            {
                                s=1;
                                break;
                            }
                        }
                        fs.close();
                        if(s==1)
                        {

                            system("CLS");
                        }
                        else
                        {
                            system("PAUSE");
                            cout<<"\nYou are an Invalid User... ";
                            cout<<"\nThank You !!! ";
                            system("PAUSE");
                            exit(0);
                            exit(0);
                        }
                    }
                    if(h!=1&&h!=2)
                    {
                        cout<<"\n\nTnvalid Input Provided. ";
                        cout<<"\n\n\t\t\tThank YOU !!!";
                        system("PAUSE");
                        exit(0);
                    }
				}

				char c='y';
				do
                {
                    system("CLS");
                    cout<<"\n\n\t\t\tWelcome to Faculty Panel ";
                    cout<<"\n\n\t\t\t\t\t\t    Your UserId is : "<<::username;
                    cout<<"\n\nPress 1 to View Your Profile ";
                    cout<<"\nPress 2 to Know Your Subjects.";
                    cout<<"\nPress 3 to Add a Subjects. ";
                    cout<<"\nPress 4 to Delete a Subject.";
                    cout<<"\nPress 5 to Modify Your Profile.";
                    int choice;
                    if(choice==1)
                    {

                        fstream fs;
                        fs.open("fainfo.txt",ios::in);
                        fs.seekg(0);
                        int x;
                        while(!fs.eof())
                        {
                            x=0;
                            fs.read((char *)&m,sizeof(Admin));
                            x=m.Faculty_profile();
                            if(x==1)
                            {
                                break;
                            }
                        }
                        fs.close();
                    }//closing choice = 1
                    if(choice==2)
                    {

                        fstream fs;
                        fs.open("fainfo.txt",ios::in);
                        fs.seekg(0);
                        int y;
                        while(!fs.eof())
                        {
                            y=0;
                            fs.read((char *)&m,sizeof(Admin));
                            y=m.Faculty_sub();
                            if(y==1)
                            {
                                break;
                            }
                        }
                        fs.close();
                    }//closing choice = 2
                    if(choice==3)
                    {
                        fstream fs;
                        fstream fs1;
                        fs.open("fainfo.txt",ios::in|ios::binary);
                        fs1.open("tmpfainfo.txt",ios::out|ios::ate);
                        fs.seekg(0);
                        while(!fs.eof())
                        {
                            fs.read((char *)&m,sizeof(Admin));
                            m.add_fasub();
                            fs1.write((char *)&m,sizeof(Admin));
                        }
                        fs.close();
                        fs1.close();
                        remove("fainfo.txt");
                        rename("tmpfainfo.txt","fainfo.txt");
                    }//closing choice = 3
                    if(choice==4)
                    {
                        fstream fs;
                        fstream fs1;
                        fs.open("fainfo.txt",ios::in|ios::binary);
                        fs1.open("fadelinfo.txt",ios::out|ios::ate);
                        fs.seekg(0);
                        while(!fs.eof())
                        {
                            fs.read((char *)&m,sizeof(Admin));
                            m.delet_fasub();
                            fs1.write((char *)&m,sizeof(Admin));
                        }
                        fs.close();
                        fs1.close();
                        remove("fainfo.txt");
                        rename("fadelinfo.txt","fainfo.txt");
                    }//closing choice = 4
                    if(choice==5)
                    {
                        fstream fs;
                        fstream fs1;
                        fs.open("fainfo.txt",ios::in|ios::binary);
                        fs1.open("modfainfo.txt",ios::out|ios::ate);
                        fs.seekg(0);
                        while(!fs.eof())
                        {
                            fs.read((char *)&m,sizeof(Admin));
                            m.modify_faprof();
                            fs1.write((char *)&m,sizeof(Admin));
                        }
                        fs.close();
                        fs1.close();
                        remove("fainfo.txt");
                        rename("modfainfo.txt","fainfo.txt");
                    }//closing choice = 5
                    if(choice<1||choice>5)
                        cout<<"\nInvalid Input Provided !!! ";

                        cout<<"\n\n\t\t\tEnter to Continue";
                        system("PAUSE");
                        cout<<"\n\nPress y to Continue ; Otherwise n : ";
                        cin>>c;
                        if(c=='Y'&&c=='y')
                        {
                            system("CLS");
                            cout<<"\n\n\n\n\n\t\t\t\tThank You !!! ";
                            system("PAUSE");
                            exit(0);
                        }
                    }while(c=='Y'||c=='y');
                }//close of faculty view

                if(ch==3)  //begin of Student view portal
		{
		    system("CLS");
			//char un[20];
			int var,s1=0;
			cout<<"\n\t\tWelcome to Student Login Page";
			cout<<"\n\nEnter the UserName : ";
			cin>>::username;
			fstream fs;
			fs.open("st_info.txt",ios::in|ios::binary);
			fs.seekg(0);
			while(!fs.eof())
			{
				var=-1;
				fs.read((char *)&m,sizeof(Admin));
				var=m.login();
				if(var==1)
				{
					s1=1;
					break;
				}
			}
				fs.close();
				if(s1==1)
				{
				    system("CLS");
				} //if first login valid

				if(s1!=1)//login invalid
				{
				    system("CLS");
					int h=0;
					cout<<"\n\n\t\tYour Login Credentials are In-Correct";
					cout<<"\nThe UserName is Your ID/Roll No.";
					cout<<"\nThe Password is Case-Sensitive.";
					cout<<"\nPress 1 to Re-Cover Password & 2 to Re-Attempt Login ";
					cout<<"\nEnter the Choice : ";
					cin>>h;
					if(h==1)  //recover password
					{
						cout<<"Enter the UserName : ";
						cin>>::username;
						fstream fs;
						fs.open("st_info.txt",ios::in|ios::binary);
						fs.seekg(0);
						int r,s2=-1;
						while(!fs.eof())
						{
							r=-1;
							fs.read((char *)&m,sizeof(Admin));
							r=m.recover();
							if(r==1)
							{
								s2=1;
								break;
							}
						}
						fs.close();
						if(s2==1)
						{
							system("PAUSE");
							system("CLS");
							cout<<"\n\n\n\n\t\t\tThank You !!! ";
							system("PAUSE");
							exit(0);
						}
						else
						{
							cout<<"\nYou are a Invalid User.";
							system("PAUSE");
							exit(0);
						}
      				}//recover password

      				if(h==2)
                    {
                        cout<<"\n\nEnter the UserName : ";
                        cin>>::username;
                        fstream fs;
                        fs.open("st_info.txt",ios::in|ios::binary);
                        fs.seekg(0);
                        int s1=-1,val;   //val for storing login() returnd value s for success login

                        while(!fs.eof())
                        {
                            val=-1;
                            fs.read((char *)&m,sizeof(Admin));
                            val=m.login();
                            if(val==1)
                            {
                                s1=1;
                                break;
                            }
                        }
                        fs.close();
                        if(s1==1)
                        {

                            system("CLS");
                        }
                        else
                        {
                            system("PAUSE");
                            cout<<"\nYou are an Invalid User... ";
                            cout<<"\nThank You !!! ";
                            system("PAUSE");
                            exit(0);
                            exit(0);
                        }
                    }
                    if(h!=1&&h!=2)
                    {
                        cout<<"\n\nTnvalid Input Provided. ";
                        cout<<"\n\n\t\t\tThank YOU !!!";
                        system("PAUSE");
                        exit(0);
                    }
				}

				char m1='y';
				do
                {
                    system("CLS");
                    cout<<"\n\n\t\t\tWelcome to Student Panel ";
                    cout<<"\n\n\t\t\t\t\t\t    Your UserId is : "<<::username;
                    cout<<"\n\nPress 1 to View Your Profile ";
                    cout<<"\nPress 2 to Know Your Subjects.";
                    cout<<"\nPress 3 to Add a Subjects. ";
                    cout<<"\nPress 4 to Delete a Subject.";
                    cout<<"\nPress 5 to Modify Your Profile.";
                    int choice1;
                    if(choice1==1)
                    {

                        fstream fs;
                        fs.open("st_info.txt",ios::in);
                        fs.seekg(0);
                        int x;
                        while(!fs.eof())
                        {
                            x=0;
                            fs.read((char *)&m,sizeof(Admin));
                            x=m.Student_prof();
                            if(x==1)
                            {
                                break;
                            }
                        }
                        fs.close();
                    }//closing choice = 1
                    if(choice1==2)
                    {

                        fstream fs;
                        fs.open("st_info.txt",ios::in);
                        fs.seekg(0);
                        int y;
                        while(!fs.eof())
                        {
                            y=0;
                            fs.read((char *)&m,sizeof(Admin));
                            y=m.Student_sub();
                            if(y==1)
                            {
                                break;
                            }
                        }
                        fs.close();
                    }//closing choice = 2
                    if(choice1==3)
                    {
                        fstream fs;
                        fstream fs1;
                        fs.open("st_info.txt",ios::in|ios::binary);
                        fs1.open("st_new_info.txt",ios::out|ios::ate);
                        fs.seekg(0);
                        while(!fs.eof())
                        {
                            fs.read((char *)&m,sizeof(Admin));
                            m.add_stsub();
                            fs1.write((char *)&m,sizeof(Admin));
                        }
                        fs.close();
                        fs1.close();
                        remove("st_info.txt");
                        rename("st_new_info.txt","st_info.txt");
                    }//closing choice = 3
                    if(choice1==4)
                    {
                        fstream fs;
                        fstream fs1;
                        fs.open("st_info.txt",ios::in|ios::binary);
                        fs1.open("st_del_info.txt",ios::out|ios::ate);
                        fs.seekg(0);
                        while(!fs.eof())
                        {
                            fs.read((char *)&m,sizeof(Admin));
                            m.delet_stsub();
                            fs1.write((char *)&m,sizeof(Admin));
                        }
                        fs.close();
                        fs1.close();
                        remove("st_info.txt");
                        rename("st_del_info.txt","st_info.txt");
                    }//closing choice = 4
                    if(choice1==5)
                    {
                        fstream fs;
                        fstream fs1;
                        fs.open("st_info.txt",ios::in|ios::binary);
                        fs1.open("st_mod_info.txt",ios::out|ios::ate);
                        fs.seekg(0);
                        while(!fs.eof())
                        {
                            fs.read((char *)&m,sizeof(Admin));
                            m.modify_stprof();
                            fs1.write((char *)&m,sizeof(Admin));
                        }
                        fs.close();
                        fs1.close();
                        remove("st_info.txt");
                        rename("st_mod_info.txt","st_info.txt");
                    }//closing choice = 5
                    if(choice1<1||choice1>5)
                        cout<<"\nInvalid Input Provided !!! ";

                        cout<<"\n\n\t\t\tEnter to Continue";
                        system("PAUSE");
                        cout<<"\n\nPress y to Continue ; Otherwise n : ";
                        cin>>m1;
                        if(m1=='Y'&&m1=='y')
                        {
                           system("CLS");
                           cout<<"\n\n\n\n\n\t\t\t\tThank You !!! ";
                           system("PAUSE");
                            exit(0);
                        }
                    }while(m1=='Y'||m1=='y');
                    system("PAUSE");
                }//close of student panel

                if(ch<1||ch>3)
                {

                    cout<<"\nInvalid Input Provided !!!";
                    system("PAUSE");
                    system("CLS");
                    cout<<"\n\n\n\t\t\tThank You";
                }
	}



