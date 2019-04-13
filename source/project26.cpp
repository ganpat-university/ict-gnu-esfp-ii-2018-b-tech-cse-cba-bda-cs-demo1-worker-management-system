
#include<iostream>
#include<cstring>
#include<fstream>
#include<iomanip>
#include<cctype>
using namespace std;

class worker_mgmt
{
	public:
	int wrk_id,wrk_daily_rate,wrk_overtime_hrs,k;
	int wrk_over_time_date,wrk_over_time_month,wrk_over_time_year;
	int date_of_joining,month_of_joining,year_of_joining;
	char wrk_name[10],wrk_gender[10],wrk_bankac_details[10],wrk_addar_updated[10],n[10];
	
	void getdata()
	{
		cout<<"\nEnter Worker ID:";
		cin>>wrk_id;
		cout<<"Enter Worker Name:";
		cin>>wrk_name;
		for(k=0;wrk_name[k]!='\0';k++)
 		{
  			if(isalpha(wrk_name[k])==0)
  			{
  			 cout<<"Enter name again:";
  			 cin>>n;
  			 strcpy(wrk_name,n);
  			}
  		}
		cout<<"Enter Worker Bank Updated (yes/no):";
		cin>>wrk_bankac_details;
		cout<<"Enter Worker Gender:";
		cin>>wrk_gender;
		cout<<"Enter Worker Adhaar Updated (yes/no):";
		cin>>wrk_addar_updated;
		cout<<"Enter Worker Daily Rate:";
		cin>>wrk_daily_rate;
		cout<<"Enter Worker Overtime Hours:";
		cin>>wrk_overtime_hrs;
		cout<<"Enter Worker Overtime Date:";
		cin>>wrk_over_time_date;
		cout<<"Enter Worker Overtime Month:";
		cin>>wrk_over_time_month;
		cout<<"Enter Worker Overtime Year:";
		cin>>wrk_over_time_year;
		cout<<"Enter Worker Date of joining:";
		cin>>date_of_joining;
		cout<<"Enter Worker Month of joining:";
		cin>>month_of_joining;
		cout<<"Enter Worker Year of joining:";
		cin>>year_of_joining;
	}
	
	void putdata()
	{
		cout<<"\nWorker Details"<<endl;
		cout<<"\nID \t Name \t Bank name \t Gender \t Adhaar Updated \t Daily rate \t Overtime hours \t Overtime Date \t Date of joining\n";
		cout<<wrk_id<<"\t"<<wrk_name<<"\t"<<wrk_bankac_details<<"\t\t"<<wrk_gender<<"\t\t"<<wrk_addar_updated<<"\t\t\t"<<
wrk_daily_rate<<"\t\t"<<wrk_overtime_hrs<<"\t\t\t"<<wrk_over_time_date<<"/"<<wrk_over_time_month<<"/"<<wrk_over_time_year<<"\t"<<
date_of_joining<<"/"<<month_of_joining<<"/"<<year_of_joining<<endl;
	}
};
int main()
{
	int i,j,choice;
	char ch;
	worker_mgmt ob[20],temp,g[20];
	for(i=0;i<5;i++)
	{
		ob[i].getdata();
	}

	cout<<endl<<"The workers names whose gender is ‘Male’:"<<endl;
	for(i=0;i<5;i++)
	{
		if(strcmp(ob[i].wrk_gender,"male")==0)
		{
			ob[i].putdata();
		}
	}

	cout<<endl<<"The workers details whose rate per day is between 200 -350:"<<endl;
	for(i=0;i<5;i++)
	{
		if(ob[i].wrk_daily_rate>200 && ob[i].wrk_daily_rate<350)
		{
			ob[i].putdata();
		}
	}

	cout<<endl<<"The workers whose over time hours are less than 5:"<<endl;
	for(i=0;i<5;i++)
	{
		if(ob[i].wrk_overtime_hrs<5)
		{
			ob[i].putdata();
		}
	}

	cout<<endl<<"Workers whose aadhar details are updated:"<<endl;
	for(i=0;i<5;i++)
	{
		if((strcmp(ob[i].wrk_addar_updated,"yes")==0))
		{
			ob[i].putdata();
		}
	}
	
	cout<<endl<<"Workers whose bank details are not updated:"<<endl;
	for(i=0;i<5;i++)
	{
		if((strcmp(ob[i].wrk_bankac_details,"no")==0))
		{
			ob[i].putdata();
		}
	}

	cout<<endl<<"Worker whose overtime done this month:"<<endl;
	for(i=0;i<5;i++)
	{
		if(((ob[i].wrk_over_time_date>=1)&&(ob[i].wrk_over_time_date<=31)) && (ob[i].wrk_over_time_month==3) && (ob[i].wrk_over_time_year==2019))
		{
			ob[i].putdata();
		}
	}

	cout<<"\nThe workers sorted by date_of_joining latest to earliest.\n";
	
    for (i=0; i<5; i++) 
    { 
        for (j=i; j<5; j++) 
        { 
            if (ob[i].year_of_joining < ob[j].year_of_joining) 
            { 
                temp = ob[i]; 
                ob[i] = ob[j]; 
                ob[j] = temp; 
            } 
            else if (ob[i].year_of_joining == ob[j].year_of_joining && ob[i].month_of_joining < ob[j].month_of_joining) 
            { 
                temp = ob[i]; 
                ob[i]= ob[j]; 
                ob[j]= temp; 
            } 
            else if (ob[i].year_of_joining == ob[j].year_of_joining && ob[i].month_of_joining == ob[j].month_of_joining && ob[i].date_of_joining < ob[j].date_of_joining) 
            { 
                temp = ob[i]; 
                ob[i] = ob[j]; 
                ob[j]= temp; 
            } 
  
        } 
    } 
	
	
	for(i=0;i<5;i++)
	{
		ob[i].putdata();
	}

	cout<<"\nThe workers whose gender is female and also rate per day is less than 200/-\n";
	for(i=0;i<5;i++)
	{
		if((strcmp(ob[i].wrk_gender,"female")==0) && (ob[i].wrk_daily_rate<200))
		{
			ob[i].putdata();
		}
	}

	cout<<"\n\n\n\n=================================   FILE HANDLING   ==============================\n\n";
	
	do
	{
		cout<<"1.To display the given recors in a file\n";
		cout<<"2.To append records in a file\n";
		cout<<"3.To read from file and display\n";
		cout<<"4.Exit\n";
		cout<<"Enter your choice\n";
		cin>>choice;
		if(choice==1)
		{
			ofstream obj("file1234.txt",ios::out);
			obj<<"\nWorker Details"<<endl;
			obj<<"\nID \t Name \t Bank name \t Gender \t Adhaar Updated \t Daily rate \t Overtime hours \t Overtime Date \t Date of joining\n";
			for(i=0;i<5;i++)
			{
			obj<<ob[i].wrk_id<<"\t"<<ob[i].wrk_name<<"\t"<<ob[i].wrk_bankac_details<<"\t\t"<<ob[i].wrk_gender<<"\t\t"<<
ob[i].wrk_addar_updated<<"\t\t\t"<<ob[i].wrk_daily_rate<<"\t\t"<<ob[i].wrk_overtime_hrs<<"\t\t\t"<<
ob[i].wrk_over_time_date<<"/"<<ob[i].wrk_over_time_month<<"/"<<ob[i].wrk_over_time_year<<"\t"<<
ob[i].date_of_joining<<"/"<<ob[i].month_of_joining<<"/"<<ob[i].year_of_joining<<endl;
			}
		obj.close();    
		}
		
		if(choice==2)
		{
			ofstream obj("file1234.txt",ios::app|ios::binary|ios::out);
 			for(i=0;i<2;i++)
 			{
 			 g[i].getdata();
 			}
 			for(i=0;i<2;i++)
 			{
 			 obj<<g[i].wrk_id<<"\t"<<g[i].wrk_name<<"\t"<<g[i].wrk_bankac_details<<"\t\t"<<g[i].wrk_gender<<"\t\t"<<
g[i].wrk_addar_updated<<"\t\t\t"<<g[i].wrk_daily_rate<<"\t\t"<<g[i].wrk_overtime_hrs<<"\t\t\t"<<
g[i].wrk_over_time_date<<"/"<<g[i].wrk_over_time_month<<"/"<<g[i].wrk_over_time_year<<"\t"<<
g[i].date_of_joining<<"/"<<g[i].month_of_joining<<"/"<<g[i].year_of_joining<<endl;
 			}
 		obj.close();
		}

		if(choice==3)
		{
 			ifstream fin("file1234.txt",ios::in);
			while(fin.get(ch))
			{
			cout<<ch;
			}
		}
		if(choice==4)
		{
			break;
		}
		}while(choice!=4);
}
