#ifndef Allotees_H
#define Allotees_H
#include "Person.h"
#include "Rooms.h"

class Allotees : public Person, public Rooms {     

	int rent;   
	string status;

public:
	Allotees()  {
		
		status = "Null";       rent = 0;
	}

	Allotees(string status, double rent, int id, string name, int hno, string area, string city) : Person(id, name, hno, area, city) {
		
		this->status = status;          this->rent = rent;
	}

	void setAllotees( int id, string name, int hno, string area, string city, string status, double rent) {
		
		setperson(id, name, hno, area, city);
		this->status = status;       this->rent = rent;
	}

	void getAllotees() {
		
	getperson();
	cout<<"\n Allotee Rent   =      "<<rent;
	cout<<"\n Allotee Status =      "<<status;
	}
	
	void usersetAllotees() {
		
	usersetperson();
	cout<<"\n\n         CHECK         \n";
	cout<<"______________________________\n";
	cout<<"\n Enter Allotee Rent   =      ";     cin>>rent;
	cout<<"\n Enter Allotee Status =      ";     cin>>status;
	cout<<"\n______________________________";
	
			fstream file;	
	file.open("AlloteesDetails.txt", ios :: app );
	
	file<<setw(19)<<rent;
	file<<setw(16)<<status<<endl;
		file.close();	
		 
	}
	
	void Add()  {       	usersetAllotees();			}
	
	static void DisplayFile() {
		
		fstream file;
	
	file.open("AlloteesDetails.txt", ios :: in);
	
	if (!file) {      cout<<"\n\n\n\n\t\t\t\t\t****** No File Created ******\n";         }
	
	else {
	string view;
	            cout<<"\t\t\t\t\t________________________________"<<endl;
		        cout<<"\t\t\t\t\t|                              |"<<endl;
				cout<<"\t\t\t\t\t|         All Allotees         |"<<endl;
				cout<<"\t\t\t\t\t|______________________________|"<<endl;
				
	cout<<"\n________________________________________________________________________________________________________________________"<<"\n\n";
  	cout<<setw(6)<<"ID"<<setw(18)<<"Name"<<setw(19)<<"H.No"<<setw(17)<<"Area"<<setw(20)<<"City"<<setw(19)<<"Rent"<<setw(18)<<"Status";
  	cout<<"\n________________________________________________________________________________________________________________________";	
		
		
		while (!file.eof()) {     
		
		getline(file, view);
		cout<<"\n\n"<<view;
		} 
	
		file.close();	
}

	}
	
    static int Search(int search) {
		
		fstream file;
		int id, flag=0;
		string name, hno, area, city, rent, status ;
	
	file.open("AlloteesDetails.txt", ios :: in);
	
	if (!file)   {    cout<<"\n\n\n\n\t\t\t\t\t****** No File Created ******\n";     }
		
	else {
		
		while (!file.eof()) {
		 
	    file>>id>>name>>hno>>area>>city>>rent>>status;
	    
				if(search == id) {

    cout<<"\n\n\n\n\t\t\t\t\t****** Record Found ******\n"<<endl;
	cout<<"\t\t\t\t______________________________________________"<<endl;
	cout<<"\t\t\t\t|_____________________|______________________|"<<endl;
	cout<<"\t\t\t\t|Allotee ID           |"<<setw (20)<<id<<       "  |"<<endl;       
	cout<<"\t\t\t\t|Allotee Name         |"<<setw (20)<<name<<  "  |"<<endl; 
	cout<<"\t\t\t\t|Allotee House No     |"<<setw (20)<<hno<<     "  |"<<endl;       
	cout<<"\t\t\t\t|Allotee Area         |"<<setw (20)<<area<<"  |"<<endl;
	cout<<"\t\t\t\t|Allotee City         |"<<setw (20)<<city<<"  |"<<endl;
	cout<<"\t\t\t\t|Allotee Rent         |"<<setw (20)<<rent<<"  |"<<endl;
	cout<<"\t\t\t\t|Allotee Status       |"<<setw (20)<<status<<"  |"<<endl; 
	cout<<"\t\t\t\t|____________________________________________|"<<endl;
				
				flag++;
				break;

				}		
	}
		file.close();
		
		if (flag == 0) {
			
			cout<<"\n\n\n\n\t\t\t\t\t****** No Record Found ******\n";   
		}
	}
	
	return flag;
	}	
	
		
    static void Update(int search) {

    int flag = Search(search);     getch();    system("cls");
     
	 	if (flag == 1)   {	 
	
	fstream file, file1;
	int id;
	string name, hno, area, city, rent, status;
	
	file1.open("AlloteesDetails.txt", ios :: in);
	
	if (!file1)    {   cout<<"\n\n\n\n\t\t\t\t\t****** No File Created ******\n";     }
	
	else {
		
		file.open("AlloteesDetails1.txt", ios :: out | ios :: app);
		
		file1>>id>>name>>hno>>area>>city>>rent>>status;
		
		while (!file1.eof()) {
			
			if (search == id) {
				
	      cout<<"\n\tXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX"                             
		        "\n\t\t\t\t\t________________________________"
		        "\n\t\t\t\t\t|                              |"
				"\n\t\t\t\t\t|    Hostel Update System      |"
				"\n\t\t\t\t\t|______________________________|"
	            "\n\n\tXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n";
	            
				cout<<"\n\t\t\t\t\tEnter New ID       =      ";      cin >> id    ; file<<setw(7)<<id;
				cout<<"\n\t\t\t\t\tEnter New Name     =      ";      cin >> name  ; file<<setw(17)<<name;
				cout<<"\n\t\t\t\t\tEnter New House No =      ";      cin >> hno   ; file<<setw(17)<<hno;
				cout<<"\n\t\t\t\t\tEnter New Area     =      ";      cin >> area  ; file<<setw(18)<<area;
				cout<<"\n\t\t\t\t\tEnter New City     =      ";      cin >> city  ; file<<setw(21)<<city;
				cout<<"\n\t\t\t\t\tEnter New Rent     =      ";      cin >> rent  ; file<<setw(19)<<rent;
				cout<<"\n\t\t\t\t\tEnter New Status   =      ";      cin >> status; file<<setw(16)<<status<<endl;    system("cls");
				
			    cout<<"\n\n\n\n\n\tXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX"                             
		        "\n\t\t\t\t\t________________________________"
		        "\n\t\t\t\t\t|                              |"
				"\n\t\t\t\t\t|        Record Updated        |"
				"\n\t\t\t\t\t|______________________________|"
	            "\n\n\tXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n";
	            getch();  system("cls");
				
				
			}
			
		else  {
		
	file<<setw(7)<<id;
	file<<setw(17)<<name;
	file<<setw(17)<<hno;
	file<<setw(18)<<area;
	file<<setw(21)<<city;
	file<<setw(19)<<rent;
	file<<setw(16)<<status<<endl;
	}
		file1>>id>>name>>hno>>area>>city>>rent>>status;			
		}
			
	}
	file1.close();
	file.close();
	remove("AlloteesDetails.txt");
	rename("AlloteesDetails1.txt", "AlloteesDetails.txt");
}
}
		
    static void Delete(int search) {

    int flag = Search(search);     getch();    system("cls");
     
	 	if (flag == 1)   {	 
	
	fstream file, file1;
	int id;
	string name, hno, area, city, rent, status;
	
	file1.open("AlloteesDetails.txt", ios :: in);
	
	if (!file1)    {   cout<<"\n\n\n\n\t\t\t\t\t****** No File Created ******\n";   }
	
	else {
		
		file.open("AlloteesDetails1.txt", ios :: out | ios :: app);
		
		file1>>id>>name>>hno>>area>>city>>rent>>status;
		
		while (!file1.eof()) {
			
			if (search == id) {
				
	      cout<<"\n\n\n\n\n\tXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX"                             
		        "\n\t\t\t\t\t________________________________"
		        "\n\t\t\t\t\t|                              |"
				"\n\t\t\t\t\t|        Record Deleted        |"
				"\n\t\t\t\t\t|______________________________|"
	            "\n\n\tXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n";
	            getch();  system("cls");
					
			}
		else  {
		
	file<<setw(7)<<id;
	file<<setw(17)<<name;
	file<<setw(17)<<hno;
	file<<setw(18)<<area;
	file<<setw(21)<<city;
	file<<setw(19)<<rent;
	file<<setw(16)<<status<<endl;
	}
		file1>>id>>name>>hno>>area>>city>>rent>>status;			
		}			
	}
	file1.close();
	file.close();
	remove("AlloteesDetails.txt");
	rename("AlloteesDetails1.txt", "AlloteesDetails.txt");
}
}

    static void DeleteFile() {
	
	fstream file;
	file.open("AlloteesDetails.txt", ios :: in);
	
	if (!file)   {    cout<<"\n\n\n\n\t\t\t\t\t****** No File Created ******\n";     }
	
	else{
		
	cout<<"\n\n\n\n\n\tXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX"                             
		    "\n\t\t\t\t\t________________________________"
		    "\n\t\t\t\t\t|                              |"
			"\n\t\t\t\t\t|        File Deleted          |"
			"\n\t\t\t\t\t|______________________________|"
	        "\n\n\tXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n";
	            
	}	
	file.close();
	remove("AlloteesDetails.txt");
}

    static void Menu(Allotees* A) {
	    system("COLOR F9" );    
		int size, choice, search;
	
	do { 
	    cout<<"\n\tXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX"                             
		        "\n\t\t\t\t\t________________________________"
		        "\n\t\t\t\t\t|                              |"
				"\n\t\t\t\t\t|  Hostel Management System    |"
				"\n\t\t\t\t\t|______________________________|"
	            "\n\n\tXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX"  
		        "\n\t\t\t\t\t________________________________"
		        "\n\t\t\t\t\t|                              |"
				"\n\t\t\t\t\t|             Menu             |"
				"\n\t\t\t\t\t|______________________________|"
		        "\n\n\tXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX"
				"\n\t\t\t\t\t      _____________________"
				"\n\t\t\t\t\t     |                     |"
				"\n\t\t\t\t\t     | 1->  ADD RECORD     |"
				"\n\t\t\t\t\t     | 2->  VIEW RECORD    |"
				"\n\t\t\t\t\t     | 3->  SEARCH RECORD  |"
				"\n\t\t\t\t\t     | 4->  UPDATE RECORD  |"
				"\n\t\t\t\t\t     | 5->  DELETE RECORD  |"
				"\n\t\t\t\t\t     | 6->  DELETE FILE    |"
				"\n\t\t\t\t\t     | 7->  EXIT           |"
				"\n\t\t\t\t\t     | 8->  MAIN MENU      |"
				"\n\t\t\t\t\t     |_____________________|"
		        "\n\n\tXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n\n"        
		              "\t\t\t\t\t      Choice =      ";    cin>>choice;   system("cls");     
		
		switch(choice) {
			
			case 1:
				cout<<"\n Enter Number of Allotees =     ";   cin>>size;   A = new Allotees[size];
				system("cls");
				
			for (int i=0;i<size;i++) { 
			cout<<"\n\t\t\t\t\t***** ENTER NEW ALLOTEE DATA *****"<<endl;    
			  A[i].Add();
			  system("cls");    
            }
			break;
			
			case 2:
			Allotees :: DisplayFile();      getch();      system("cls");
	    	break;
			
			case 3:  
			cout<<"\n Enter ID =     ";     cin>>search;  system("cls"); 
			Allotees :: Search (search);   getch();    system("cls");
			break;
			
			case 4:   
			cout<<"\n\t\t\t\t\t Enter ID =     ";     cin>>search;  system("cls");
			Allotees :: Update (search);
			break;
			
			case 5:   
			cout<<"\n\t\t\t\t\t Enter ID =     ";     cin>>search;  system("cls");
			Allotees :: Delete (search);
			break;
			
			case 6:  
			Allotees :: DeleteFile();     getch();    system("cls");
			break;
			
			case 7:  
		    cout<<"\n\tXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX"                             
		          "\n\t\t\t\t\t_____________________________________"
		          "\n\t\t\t\t\t|                                   |"
				  "\n\t\t\t\t\t|  THANK YOU FOR USING THE SYSTEM   |"
				  "\n\t\t\t\t\t|___________________________________|"
				  "\n\n\tXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n";    
				  exit(0);
			
			default:     system("cls");	
		}
	}        while (choice < 8);	
}  


    static void AssignMenu(Rooms* R, int n) {
    	system("COLOR 0F" );
    	int choice;
    	do {
    		cout<<"\n\tXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX"                             
		        "\n\t\t\t\t\t    ________________________________"
		        "\n\t\t\t\t\t    |                              |"
				"\n\t\t\t\t\t    |  Hostel Management System    |"
				"\n\t\t\t\t\t    |______________________________|"
	            "\n\n\tXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX"  
		        "\n\t\t\t\t\t    ________________________________"
		        "\n\t\t\t\t\t    |                              |"
				"\n\t\t\t\t\t    |             Menu             |"
				"\n\t\t\t\t\t    |______________________________|"
		        "\n\n\tXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX"
				"\n\t\t\t\t\t      ______________________________"
				"\n\t\t\t\t\t     |                              |"
				"\n\t\t\t\t\t     | 1->  DISPLAY ALL ALLOTEES    |"
				"\n\t\t\t\t\t     | 2->  DISPLAY ALL ROOMS       |"
				"\n\t\t\t\t\t     | 3->  ALLOT A ROOM            |"
				"\n\t\t\t\t\t     | 4->  DISPLAY ALLOTTED ROOMS  |"
				"\n\t\t\t\t\t     | 5->  EXIT                    |"
				"\n\t\t\t\t\t     | 6->  MAIN MENU               |"
				"\n\t\t\t\t\t     |______________________________|"
		        "\n\n\tXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n\n"        
		              "\t\t\t\t\t      Choice =      ";    cin>>choice;   system("cls");
    		
    		switch (choice) {
    			
    			case 1:
    				DisplayFile();              getch();    system("cls");   break;
    				
    			case 2:
    				Rooms :: DisplayFile();     getch();      system("cls");   break;
    			
    			case 3:
    				AssignRoom();   getch();      system("cls");   break;
    				
    			case 4:
    				ViewAllotedRooms();   getch();      system("cls");   break;
    				
    			case 5: 
    			 cout<<"\n\tXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX"                             
		          "\n\t\t\t\t\t_____________________________________"
		          "\n\t\t\t\t\t|                                   |"
				  "\n\t\t\t\t\t|  THANK YOU FOR USING THE SYSTEM   |"
				  "\n\t\t\t\t\t|___________________________________|"
				  "\n\n\tXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n";    
				  exit(0);
    			
    			default:   system("cls");	
			}		
		}    while (choice < 5);	
	} 


    static void AssignRoom() {
    	
    	fstream file;
    	file.open("AllottedRooms.txt", ios :: out | ios :: app );
    	int id, room;
    	string floor, block, name;
    				DisplayFile();
    				cout<<"\n\nEnter Allotee ID From the Above to Allot a Room =   ";    cin>>id;     file<<setw(5)<<id;
    				cout<<"\nConfirm Allotee Name =  ";                                  cin>>name;   file<<setw(20)<<name;
					system("cls");
    				Rooms :: DisplayFile();
    				cout<<"\n\nEnter Room No From the Above to Allot =  ";     cin>>room;            file<<setw(15)<<room; 
    				cout<<"\nConfirm Block No =  ";                            cin>>block;           file<<setw(20)<<block;
    				cout<<"\nConfirm Floor No =  ";                            cin>>floor;           file<<setw(20)<<floor<<endl;
    			system("cls");	
      cout<<"\n\n\n\n\n\tXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX"                             
		    "\n\t\t\t\t\t________________________________"
		    "\n\t\t\t\t\t|                              |"
			"\n\t\t\t\t\t|        ROOM ALLOTED          |"
			"\n\t\t\t\t\t|______________________________|"
	        "\n\n\tXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n";
			file.close();				
	}
	
	static void ViewAllotedRooms() {
		
		fstream file;
	file.open("AllottedRooms.txt", ios :: in);
	
	if (!file) {      cout<<"\n\n\n\n\t\t\t\t\t****** No File Created ******\n";         }
	
	else {
	string view;
	        cout<<"\t\t\t\t\t________________________________"
		        "\n\t\t\t\t\t|                              |"
				"\n\t\t\t\t\t|        Alloted ROOMS         |"
				"\n\t\t\t\t\t|______________________________|"<<endl;
			
			
			
	cout<<"\n_______________________________________________________________________________________"<<"\n\n";
  	cout<<setw(6)<<"ID"<<setw(19)<<"Name"<<setw(19)<<"ROOM NO"<<setw(17)<<"BLOCK"<<setw(20)<<"FLOOR";
  	cout<<"\n_______________________________________________________________________________________";
		
		
		while (!file.eof()) {     
		
		getline(file, view);
		cout<<"\n\n"<<view;
		} 
	
		file.close();	
}
	}



};

#endif

