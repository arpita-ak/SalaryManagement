#include <iostream>
#include <stdio.h>
#include <string.h>
#include <fstream>
using namespace std;

class data
{
   protected:
        char p[30];
        unsigned long int day1,month1,year1,day2,month2,year2,tax,d,m,n,a,b,c,e,f,g,absent;
        int des;
        double basic,permon,EMI,EPF;
    public:
        void getdata()
        {
             cout<<"\n Enter name: ";
             cin>>p;
             cout<<"\n Enter Employee Number: ";
             cin >>des;
         }
  };

class salary:public virtual data
{
    public:
        int WhatFurther(void);
        void time_date(void);
        unsigned long int daycount(int,int,int,int,int,int,int);
        void manager(int);
        void search_employee(void);
 };

 int salary::WhatFurther(void)
 {
  char w;
  cout<<"\n\n\t\t\t";
  cout<<"If you want to continue, press 'y' or press 'n':";
  cin>>w;
  if(w=='y')
        return 1;
  else
        return 0;
  }

 unsigned long int salary::daycount(int day1,int month1,int year1,int day2,int month2,int year2,int absent)
  {
    year1=year1*365;
    month1=month1*30;
    day1=day1+year1+month1;

    year2=year2*365;
    month2=month2*30;
    day2=day2+year2+month2;

    return day2-day1-absent;
  }

void salary::manager(int salaryType)
{
     cout<<"\n Employee name: "<<p;
     cout<<"\n Employee number: "<<des;
     switch (salaryType)
         {
             case (0):
                 {
                     cout<<"\n Designation: Manager";
                     break;
                 }
             case (1):
                {
                    cout<<"\n Designation: Executive manager";
                    break;
                }
             case (2):
                {
                    cout<<"\n Designation: Programmer";
                    break;
                }
             case (4):
                {
                    cout<<"\n Designation: Software developer";
                     break;
                }

         }


     cout<<"\n Joining date (<Day>space<Month>space<Year>) : ";
     cin>>day1>> month1>>year1;
     cout<<"Today's date (<Day>space<Month>space<Year>) : ";
     cin>>day2>> month2>>year2;
     cout<<"\n Total days of absence:";
     cin>>absent;
     cout<<"\n Enter the basic salary per annum (<rupee>dot<paise>): ";
     cin >> basic;
     cout<<"\n EMI per annum (enter 0 if no EMI): ";
     cin>>EMI;

     d=daycount(day1,month1,year1,day2,month2,year2,absent);
     permon=basic/12;

     cout<<"\n\n\t\t SALARY SHEET ";

     cout<<"\n\n Salary per month: "<<permon;

     cout<<"\n Total "<<d/365<<" years of experience in this.";
     cout<<"\n After each year the company will increment the salary by: ";

     if(salaryType==0)
     {
         cout<<"25% of basic.";
         n=((basic)*((d/365.0)*0.25));
         tax=250;
     }
     else if(salaryType==1)
     {
         cout<<"20% of basic.";
         n=((basic)*((d/365.0)*0.20));
         tax=200;
     }
     else if(salaryType==2)
     {
         cout<<"15% of basic.";
         n=((basic)*((d/365.0)*0.15));
         tax=150;
     }
     else
     {
         cout<<"10% of basic.";
         n=((basic)*((d/365.0)*0.10));
         tax=100;
     }

     EPF=(basic)*0.12;
     cout<<"\n Employees Provident Fund (EPF) per annum is 12% of basic salary:"<<EPF;
     cout<<"\n Professional Tax (PT) per annum:"<<tax;
     cout<<"\n Festival bonus is 10% of the basic salary:"<<0.1*basic;
     cout<<"\n\n Net Salary = Total salary + bonus - EPF - EMI - PT";
     n = basic + n - EPF - EMI - tax;
     cout<<"\n\n\n\n\t\tNet Salary per annum: "<<n;
}

void salary::search_employee()
{
    cout<<"\nEnter the employee name whom you want to search:";
    char q[30];
    cin>>q;
    strcat(q,".txt");
    fstream z;
    z.open(q,ios::in);
    z.seekg(0);
    if(!z)
    {
         cout<<"\n\t\t\t Searching...";
         cout<<"\n\t\t\t File not found!";
     }
     else
     {
        char ch;
        while(z)
        {
             z.get(ch);
             cout<<ch;
        }
     }

}

class file:public virtual data, public salary
{
 public:
    void file_manager(int);
 };

void file::file_manager(int salaryType=0)
{
     char mng[30];
     strcpy(mng,p);
     strcat(mng,".txt");
     fstream k;
     k.open(mng,ios::out);
     k<<"\n Our Employee: "<<p<<endl;
     k<<"\n Employee number: "<<des<<endl;
     k<<"\n Joined on:";
     k<<day1<<"/"<<month1<<"/"<<year1<<endl;

     switch (salaryType)
         {
             case (0):
                 {
                     k<<"\n Designation: Manager"<<endl;
                     break;
                 }
             case (1):
                {
                    k<<"\n Designation: Executive manager"<<endl;
                    break;
                }
             case (2):
                {
                    k<<"\n Designation: Programmer"<<endl;
                    break;
                }
             case (4):
                {
                    k<<"\n Designation: Software developer"<<endl;
                     break;
                }

         }

     k<<"Total days of absence:"<<absent<<"as on"<<day2<<"/"<<month2<<"/"<<year2<<endl;

     k<<"Basic salary per annum:"<<basic<<endl;
     k<<"Salary per month:"<<permon<<endl;
     k<<"\n EMI per annum:"<<EMI<<endl;
     k<<"Total "<<d/365<<" years of experience in this."<<endl;
     k<<"\n After each year the company will increment the salary by:";

     if(salaryType==0)
     {
         k<<"25% of basic."<<endl;
         n=((basic)*((d/365.0)*0.25));
         tax=250;
     }
     else if(salaryType==1)
     {
         k<<"20% of basic."<<endl;
         n=((basic)*((d/365.0)*0.20));
         tax=200;
     }
     else if(salaryType==2)
     {
         k<<"15% of basic."<<endl;
         n=((basic)*((d/365.0)*0.15));
         tax=150;
     }
     else
     {
         k<<"10% of basic."<<endl;
         n=((basic)*((d/365.0)*0.10));
         tax=100;
     }

     EPF=(basic)*0.12;
     k<<"Employees Provident Fund (EPF) per annum is 12% of basic salary:"<<EPF<<endl;
     k<<"Professional Tax (PT) per annum:"<<tax<<endl;
     k<<"Festival bonus is 10% of the basic salary:"<<0.1*basic<<endl;
     k<<"Net Salary = Total salary + bonus - EPF - EMI - PT"<<endl;
     n = basic + n - EPF - EMI - tax;
     k<<"\n\n\t\tNet Salary per annum: "<<n;
     k.close();
}

int main()
{
     int a,a1;
     data d;
     salary s;
     file f;
     cout<<"\n\n\n ==============================================================================================";
     cout<<"\n \t\t\tWELCOME TO THE SALARY MANAGEMENT SYSTEM\n";
     cout<<"=================================================================================================\n\n\n";
     do
     {
      cout<<"\n Enter your choice:\n 1.Add an employee\n 2.Search an employee\n 3.Quit";
      cout<<"\n Choose (1 to 3): ";
      cin>>a1;

      if(a1==1)
      {
       f.getdata();
       cout<<"\n Enter Employees's designation:\n 1.Manager\n 2.Executive manager\n 3.Programmer\n 4.Software developer";
       cout<<"\n Choose (1 to 4): ";
       cin>>a;
       switch(a)
       {
        case 1:
           f.manager(0);
           f.file_manager(0);
           break;
        case 2:
           f.manager(1);
           f.file_manager(1);
           break;
        case 3:
           f.manager(2);
           f.file_manager(2);
           break;
        case 4:
           f.manager(3);
           f.file_manager(3);
           break;
        default:
           cout<<"\n\n\t You entered an invalid number";
           break;
           }
        }
      if(a1==2)
      {
        f.search_employee();
      }
      if(a1==3)
            break;
      int l;
      l=f.WhatFurther();
      if(l==0)
        break;
     }
      while(a!=3);

     return 0;
}
