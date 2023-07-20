#ifndef Rooms_H              //used to prevent headerfiles to be added multiple times in the source code
#define Rooms_H               //to give a name to constant values before the program is compiled
#include <iostream>
#include <iomanip>
#include <conio.h>
#include <fstream>
using namespace std;

class Rooms {
	
	private:                  // Private Access Specifier	             
    int id;   int* roomno;    // Class Members
	string floor, block;	  
	
	public:		                 // Public Access Specifier
	
Rooms() {       // Default Constructor
	id = 0;  
	floor = block = "-";
	roomno = new int;
   *roomno = 0;
}

Rooms(int id, string block , string floor, int roomno) {    //Constructor Overloading
	this->id = id;      this->block = block;  this->floor = floor;
    this->roomno = new int;
    *(this->roomno) = roomno;
}

Rooms(Rooms& R){           //Copy Constructor
	id = R.id;        block = R.block;   
	floor = R.floor;    
	roomno = new int;          // Dynamic Space for Deep Copy
	*roomno = *(R.roomno);
	}
	
~Rooms() {                     //Destructor
	delete[] roomno;
}

// Mutator
void setid(int i) {
	id = i;
}
void setblock(string cont) {
	block = cont;
}
void setfloor(string n) {
	floor = n;
}
void setroom(int c) {
	*roomno = c;
}
// Accessor		
int getid() {
	return id;
}
string getblock() {
	return block;
}
string getfloor() {
	return floor;
}
int getroom() {
	return *roomno;
}

void add() {    
      
	fstream file;	
	file.open("Rooms.txt", ios :: out | ios :: app );
	 
	cout<<"\nEnter Hostelite ID =             ";     cin>>id;
	cout<<"\nEnter Hostelite Room No =        ";     cin>>*roomno;   file<<setw(15)<<*roomno;
	cout<<"\nEnter Hostelite Block =          ";     cin>>block;     file<<setw(20)<<block;
	cout<<"\nEnter Hostelite Floor =          ";     cin>>floor;     file<<setw(20)<<floor<<endl;
	  file.close();
}

static void DisplayFile() {
	
		fstream file;
	
	file.open("Rooms.txt", ios :: in);
	
	if (!file) {      cout<<"\n\n\n\n\t\t\t\t\t****** No File Created ******\n";         }
	
	else {
	string view;
	            cout<<"\t\t  ________________________________"<<endl;
		        cout<<"\t\t  |                              |"<<endl;
				cout<<"\t\t  |       AVAILABLE ROOMS        |"<<endl;
				cout<<"\t\t  |______________________________|"<<endl;
				
	cout<<"\n\t_______________________________________________________"<<"\n\n";
  	cout<<"\t"<<setw(10)<<"ROOM NO"<<setw(18)<<"BLOCK"<<setw(19)<<"FLOOR";
  	cout<<"\n\t_______________________________________________________";	
		
		
		while (!file.eof()) {     
		
		getline(file, view);
		cout<<"\n\n"<<view;
		} 
	
		file.close();	
}
}

static void DeleteFile() {
	
	fstream file;
	file.open("Rooms.txt", ios :: in);
	
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
	remove("Rooms.txt");
}


void view() {       
	 
	cout<<setw (9)<<id<<setw (11)<<"  | "<<setw (15)<<block<<setw (10)<<"  | ";
	cout<<setw (15)<<floor<<setw (10)<<"  | "<<setw (15)<<*roomno<<setw (10)<<"  | "<<endl;	
}

static int search(Rooms* R, int n, int s) {           //  Search Function

	int i;
	
	for(i=0; i < n; i++) {
		
		if(s == R[i].id) {                  // Condition to Compare all Records in the Array 
			
	cout<<"\n\n\n\n\t\t\t\t\t****** Record Found ******\n"<<endl;
	cout<<"\t\t\t\t______________________________________________"<<endl;
	cout<<"\t\t\t\t|_____________________|______________________|"<<endl;
	cout<<"\t\t\t\t|Hostelite ID         |"<<setw (20)<<R[i].id<<       "  |"<<endl;       
	cout<<"\t\t\t\t|Hostelite Block      |"<<setw (20)<<R[i].block<<    "  |"<<endl; 
	cout<<"\t\t\t\t|Hostelite Floor      |"<<setw (20)<<R[i].floor<<    "  |"<<endl;       
	cout<<"\t\t\t\t|Hostelite Room No    |"<<setw (20)<<*(R[i].roomno)<<"  |"<<endl; 
	cout<<"\t\t\t\t|____________________________________________|"<<endl;      
	break;  }
	}
	
	if (i == n)                // Condition if user enters Wrong ID
	cout<<"\n****** No Record Found ****** ";
	
	return i;	   
}

static void update(Rooms* R, int n, int s) {        // Update Function

    int i = search(R, n, s);
    
    if (i != n){   
	int choice;
	do{ cout<<"\n\n=====================================================================================================\n";
	    cout<<"\n\t\t\t********* HOSTEL UPDATE SYSTEM ********* \n";
	    cout<<"\n=====================================================================================================\n";
	    cout<<"\n\n\tMain Menu :\n";
		cout<<"\n\t1->UPDATE FLOOR. ";
		cout<<"\n\t2->UPDATE BLOCK.";
		cout<<"\n\t3->UPDATE ROOM NO.\n";  
		cout<<"\n\t Press any Other Number to go to Back To Menu.\n";     
		cout<<"\n\nEnter Choice = ";    cin>>choice;  
		    
		switch(choice) {
			
		case 1:   cout<<"\nEnter New FLOOR =  ";  cin >>   R[i].floor     ;  system("cls"); break;
	    case 2:   cout<<"\nEnter New Contact= ";  cin >>   R[i].block     ;  system("cls"); break;
	    case 3:   cout<<"\nEnter New Room No= ";  cin >> *(R[i].roomno)   ;  system("cls"); break;
		default:           system("cls");   	}
	}
	         while(choice<4); 
		 
}
}	

static void Menu(Rooms* R, int n)	{
	system("COLOR FC" );
	int choice, s;           

	do { 
	cout<<"\n\n\tXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n"                           
	   	  "\n\n\t\t\t\t********* HOSTEL MANAGEMENT SYSTEM ********* \n"
	      "\n\n\tXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n"
		        "\n\t\t\t\t***************** Menu ****************** \n"
		        "\n\t\t\t\t\t      _____________________"
				"\n\t\t\t\t\t     |                     |"
				"\n\t\t\t\t\t     | 1->  ADD ROOMS      |"
				"\n\t\t\t\t\t     | 2->  VIEW ROOMS     |"
				"\n\t\t\t\t\t     | 3->  SEARCH ROOMS   |"
				"\n\t\t\t\t\t     | 4->  UPDATE ROOMS   |"
				"\n\t\t\t\t\t     | 5-> CLEAR ALL ROOMS |"
				"\n\t\t\t\t\t     | 6->  EXIT           |"
				"\n\t\t\t\t\t     | 7->  MAIN MENU      |"
				"\n\t\t\t\t\t     |_____________________|"       
		        "\n\n\t\t\t\t\tEnter Choice = ";    cin>>choice;   system("cls");
	
	switch(choice) {
	
	case 1:  {               // To Add Records
    
     cout<<"\n\t\t\tEnter Number of Records To Input = ";   
	 cin>>n;   	R = new Rooms[n];          system("cls"); 
     
        for(int i=0;i<n;i++) {         //Loop to Add Multiple Records in the Array
        	
	cout<<"\n\n\t\t\t****** ENTER RECORD "<<i+1<<" ******\n";   
	R[i].add();      } 
	system("cls"); }   break;
	 
	case 2:                        // To Display All recocrds in Tabular Form
	
	if(n == 0) {                  // Condition to Perform Add function First
		
	cout<<"\a\n\n\n\t\t\t\t******No Record Found******\n";
	cout<<"\n\t\t Press any Key to go to Back To Menu.\n";    
	getch();  }
	
	else {
		
		
		cout<<"\n\t\t\t\t\t*******All Records*******\n\n"<<endl;
		cout<<" ____________________________________________________________________________________________________________"<<endl;
			cout<<"|"<<" RECORDS"<<setw (6)<<"|"<<setw (11)<<"ID"<<setw (10)<<"  | "<<setw (15)<<"Block"<<setw (10);
		    cout<<"  | "<<setw (15)<<"Floor"<<setw (10)<<"  | "<<setw (15)<<"Room No"<<setw (10)<<"  | "<<endl;
		    
	        for(int i=0;i<n;i++) {
	           cout<<"| RECORD# "<<i+1<<setw (5)<<" | ";    
			   R[i].view();   }
		cout<<"|____________________________________________________________________________________________________________|"<<endl;
			    getch();     }   break;
			      
	case 3:                  // To Search any Data in Tabular form
	
	if(n == 0) {             // Condition to Perform Add function First
		
	cout<<"\a\n\n\n\t\t\t\t******No Record Found******\n";
	cout<<"\n\t\t Press any Key to go to Back To Menu.\n";    
	getch();  }
	
	else {
		
	cout<<"\n\t\t\tEnter ID To Search = ";   
	cin>>s;  system("cls");
    Rooms :: search(R, n, s);                                             //Calling static function
	getch();   system("cls");  }    break;                    
	
	case 4:                // To Update Specific Data
	  
	if(n == 0) {          // Condition to Perform Add function First
		
	cout<<"\a\n\n\n\t\t\t\t******No Record Found******\n";
	cout<<"\n\t\t\t\t Press any Key to go to Back To Menu.\n";     
	getch();    }
	
	else {
		
	cout<<"\n\t\t\tEnter ID To Update = ";   
	cin>>s;   system("cls");
	Rooms :: update(R, n, s) ;  }   break;              
	
	case 5:
		
		Rooms :: DeleteFile();     break;
	
	case 6: 
	
	cout<<"\n\tXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX"                             
		          "\n\t\t\t\t\t_____________________________________"
		          "\n\t\t\t\t\t|                                   |"
				  "\n\t\t\t\t\t|  THANK YOU FOR USING THE SYSTEM   |"
				  "\n\t\t\t\t\t|___________________________________|"
				  "\n\n\tXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n";    
				  exit(0);   
	
	default:    	system("cls");
				        
    }
}        while (choice < 6);

}

};
#endif
