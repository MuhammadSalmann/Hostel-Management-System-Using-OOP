#ifndef Person_H
#define Person_H
#include <iostream>
#include <string>
#include <conio.h>
#include <fstream>
#include <iomanip>
#include <stdio.h>
using namespace std;

class Address {         

	int hno;     
	string area, city;

public:

	Address() {
		
		hno = 0;
		area = city = "Null";
	}
	Address(int hno, string area, string city) {
		
		this->hno = hno;     this->area = area;      this->city = city;
	}

	void setaddress(int hno, string area, string city) {
		
	    this->hno = hno;     this->area = area;      this->city = city;
	}

	void getaddress() {

	cout<<"\n Allotee House No =       "<<hno;
	cout<<"\n Allotee Area     =       "<<area;
	cout<<"\n Allotee City     =       "<<city;
	}
	
	void usersetaddress() {
		
			
	fstream file;
	file.open("AlloteesDetails.txt", ios :: app );
		
	cout<<"\n         ADDRESS         \n";
	cout<<"______________________________\n";
	cout<<"\n Enter Allotee House No =     ";     cin>>hno;
	cout<<"\n Enter Allotee Area     =     ";     cin>>area;
	cout<<"\n Enter Allotee City     =     ";     cin>>city;
	cout<<"\n______________________________";


	file<<setw(17)<<hno;
	file<<setw(18)<<area;
	file<<setw(21)<<city;
		file.close();	
	
	}

};


class Person {  

	int id;
	string name;
	Address a;

public:
	Person() {
		
		id = 0;
		name = "Null";
	}

	Person(int id, string name, int hno, string area, string city) {
		
		this->id = id;       this->name = name;
		a.setaddress(hno, area, city);
	}

	void setperson (int id, string name, int hno, string area, string city) {
		
		this->id = id;       this->name = name;
		a.setaddress(hno, area, city);
	}

	void getperson() {

		cout<<"\n Allotee ID   =       "<<id;
	    cout<<"\n Allotee Name =       "<<name;
		a.getaddress();

	}
	
	void usersetperson() {	
	
				
		fstream file;
	file.open("AlloteesDetails.txt", ios :: out | ios :: app );
	
	cout<<"______________________________\n";
	cout<<"\n         IDENTITY         \n";
	cout<<"______________________________\n";
	cout<<"\n Enter Allotee ID     =       ";     cin>>id;
	cout<<"\n Enter Allotee Name   =       ";     cin>>name;
	cout<<"\n______________________________\n";

		
	file<<setw(7)<<id;
	file<<setw(17)<<name;
	
		file.close();	
	
		a.usersetaddress();
	}
};

#endif

