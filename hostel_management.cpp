/*
	Name: Hostel Management System
	Copyright: GNU General Public Liscence v3.0
	Author: Saad Rajpoot
	Date: 17/06/19 05:35
	Description: C++ code for Hostel Management System Program.
	
	Features:
	
		1. Add a Client
			a. Feature of Having Mes or Not
			b. Feature of automatically aloting Room to new client
		2. Bill History
			a. Automatically Billing according to room Type and Mess Service
		3. Remove a Client
			a. Automatically Removes a Client & Display vaccant Room next Time
		4. Return Exit to DOS
*/


#include<iostream>
#include<fstream>
using namespace std;
fstream file;

struct clients{
	string name;
	string fname;
	string cnic;
	int fee;
};
clients cl[50];

class hostel{
	public:
		void book(){
			system("cls");
			string name,fname,cnic,mess;
			string tempname,tempfname,tempcnic;
			int count=0,roomtype,fee,tempfee;
			
			cout<<"Client\'s name : ";
			cin>>name;
			cout<<"Father name : ";
			cin>>fname;
			cout<<"CNIC No : ";
			cin>>cnic;
			cout<<"\nWith Mess = 8000\nWithout Mess = 5000\n";
			cout<<"Mess ? (y/n) ";
			cin>>mess;
			cout<<"3 seater or 5 seator ? (3/5) : ";
			cin>>roomtype;
			
			if(mess=="y"){
				fee=8000;
			}
			else{
				fee=5000;
			}
			
			if(roomtype==3){
				count=0;
				file.open("threefirst.txt",ios::in);
				while(file>>tempname>>tempfname>>tempcnic>>fee){
					count++;
				}
				file.close();
				
				if(count<3){
					file.open("threefirst.txt",ios::app);
					file<<name<<" "<<fname<<" "<<cnic<<" "<<fee<<"\n";
					cout<<"Client Added successfully !!";
					file.close();
					
					if(mess=="y"){
						file.open("messhistory.txt",ios::app);
						file<<8000<<"\n";
						file.close();
					}
					else{
						file.open("withoutmesshistory.txt",ios::app);
						file<<5000<<"\n";
						file.close();
					}
				}
				else{
					string tempcheck;
					cout<<"First Three Seator Room is Full.\nPress \'y\' to Check for Second room\n";
					cin>>tempcheck;
					
					if(tempcheck=="y"){
						file.open("threesecond.txt",ios::in);
						count=0;
						while(file>>tempname>>tempfname>>tempcnic>>tempfee){
							count++;
						}
						file.close();
						
						if(count<3){
							file.open("threesecond.txt",ios::app);
							file<<name<<" "<<fname<<" "<<cnic<<" "<<fee<<"\n";
							cout<<"Client Added successfully !!";
							file.close();
							
							if(mess=="y"){
								file.open("messhistory.txt",ios::app);
								file<<8000<<"\n";
								file.close();
							}
							else{
								file.open("withoutmesshistory.txt",ios::app);
								file<<5000<<"\n";
								file.close();
							}	
						}
						else{
							cout<<"\nBoth 3 seator Rooms are Full !!\n";
						}
					}
				}
			}
			else if(roomtype==5){
				count=0;
				file.open("fivefirst.txt",ios::in);
				while(file>>tempname>>tempfname>>tempcnic>>tempfee){
					count++;
				}
				file.close();
				
				if(count<5){
					file.open("fivefirst.txt",ios::app);
					file<<name<<" "<<fname<<" "<<cnic<<" "<<fee<<"\n";
					cout<<"Client Added successfully !!";
					file.close();
					if(mess=="y"){
						file.open("messhistory.txt",ios::app);
						file<<8000<<"\n";
						file.close();
					}
					else{
						file.open("withoutmesshistory.txt",ios::app);
						file<<5000<<"\n";
						file.close();
					}
				}
				else{
					string tempcheck;
					cout<<"First Five Seator Room is Full.\nPress \'y\' to Check for Second room\n";
					cin>>tempcheck;
					
					if(tempcheck=="y"){
						file.open("fivesecond.txt",ios::in);
						count=0;
						while(file>>tempname>>tempfname>>tempcnic>>tempfee){
							count++;
						}
						file.close();
						
						if(count<5){
							file.open("fivesecond.txt",ios::app);
							file<<name<<" "<<fname<<" "<<cnic<<" "<<fee<<"\n";
							cout<<"Client Added successfully !!";
							file.close();
							
							if(mess=="y"){
								file.open("messhistory.txt",ios::app);
								file<<8000<<"\n";
								file.close();
							}
							else{
								file.open("withoutmesshistory.txt",ios::app);
								file<<5000<<"\n";
								file.close();
							}
						}
						else{
							cout<<"\nBoth 5 seator Rooms are Full !!\n";
						}
					}
				}
			}
			else{
				cout<<"\nWrong Option Selected !!\n";
			}
		}
		
		void billing(){
			system("cls");
			int fee=0,totalfee=0;
			file.open("messhistory.txt",ios::in);
			while(file>>fee){
				totalfee+=fee;
			}
			cout<<"\nMess Total Fee : "<<totalfee<<"\n";
			file.close();
			
			fee=0,totalfee=0;
			file.open("withoutmesshistory.txt",ios::in);
			while(file>>fee){
				totalfee+=fee;
			}
			cout<<"\nWithout Mess Total Fee : "<<totalfee<<"\n";
			file.close();
		}
		
		void remove(){
			system("cls");
			int roomtype,option,i=0;
			string cnic;
						
			cout<<"3 or 5 Seator Room ? (3/5)";
			cin>>roomtype;
			cout<<"First or Second ? (1/2)";
			cin>>option;
			cout<<"Enter CNIC";
			cin>>cnic;
			
			if(roomtype==3 && option==1){
				file.open("threefirst.txt",ios::in);
				while(file>>cl[i].name>>cl[i].fname>>cl[i].cnic>>cl[i].fee){
					i++;
				}
				file.close();
				
				int j=0;
				file.open("threefirst.txt",ios::out);
				while(j<i){
					if(cl[j].cnic!=cnic){
						file<<cl[j].name<<" "<<cl[j].fname<<" "<<cl[j].cnic<<" "<<cl[j].fee<<"\n";
					}
					j++;
				}
				file.close();
				cout<<"Employee Deleted Successfully !!"<<endl;
			}
			else if(roomtype==3 && option==2){
				file.open("threesecond.txt",ios::in);
				while(file>>cl[i].name>>cl[i].fname>>cl[i].cnic>>cl[i].fee){
					i++;
				}
				file.close();
				
				int j=0;
				file.open("threesecond.txt",ios::out);
				while(j<i){
					if(cl[j].cnic!=cnic){
						file<<cl[j].name<<" "<<cl[j].fname<<" "<<cl[j].cnic<<" "<<cl[j].fee<<"\n";
					}
					j++;
				}
				file.close();
				cout<<"Employee Deleted Successfully !!"<<endl;
			}
			else if(roomtype==5 && option==1){
				file.open("fivefirst.txt",ios::in);
				while(file>>cl[i].name>>cl[i].fname>>cl[i].cnic>>cl[i].fee){
					i++;
				}
				file.close();
				
				int j=0;
				file.open("fivefirst.txt",ios::out);
				while(j<i){
					if(cl[j].cnic!=cnic){
						file<<cl[j].name<<" "<<cl[j].fname<<" "<<cl[j].cnic<<" "<<cl[j].fee<<"\n";
					}
					j++;
				}
				file.close();
				cout<<"Employee Deleted Successfully !!"<<endl;
			}
			else if(roomtype==5 && option==2){
				file.open("fivesecond.txt",ios::in);
				while(file>>cl[i].name>>cl[i].fname>>cl[i].cnic>>cl[i].fee){
					i++;
				}
				file.close();
				
				int j=0;
				file.open("fivesecond.txt",ios::out);
				while(j<i){
					if(cl[j].cnic!=cnic){
						file<<cl[j].name<<" "<<cl[j].fname<<" "<<cl[j].cnic<<" "<<cl[j].fee<<"\n";
					}
					j++;
				}
				file.close();
				cout<<"Employee Deleted Successfully !!"<<endl;
			}
		}
};

int main(){
	hostel obj;
	int op;
	
	cout<<"\n1.Add Client"<<endl;
	cout<<"2.Bill History"<<endl;
	cout<<"3.Remove Client"<<endl;
	cout<<"4.exit"<<endl;
	cin>>op;
	
	if(op==1){
		obj.book();
		main();
	}
	else if(op==2){
		obj.billing();
		main();
	}
	else if(op==3){
		obj.remove();
		main();
	}
	else if(op==4){
		system("exit");
	}
	else{
		system("cls");
		cout<<"wrong option selected\n\n";
		main();
	}
	
	return 0;
}
