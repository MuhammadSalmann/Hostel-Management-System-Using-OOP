#include "Allotees.h"

int main() {
	system("COLOR 4E" );  
	Rooms* R = new Rooms;
	Allotees* A = new Allotees;
	int choice, n= 0;
	
    cout <<  "\n\t                               ||========================||" 
             "\n\t                               ||                        ||" 
             "\n\t                               ||                        ||" 
             "\n\t                      ||-------                            -------||" 
             "\n\t                      ||                                          ||" 
             "\n\t                      ||                                          ||" 
             "\n\t             ||-------                                              -------||" 
             "\n\t             ||                                                            ||" 
             "\n\t             ||                                                            ||" 
             "\n\t    ||-------                                                                -------||" 
             "\n\t    ||                                                                              ||" 
             "\n\t    ||                                 H O S T E L                                  ||" 
             "\n\t    ||                                                                              ||" 
             "\n\t    ||                                                                              ||" 
             "\n\t    ||                             M A N A G E M E N T                              ||" 
             "\n\t    ||                                                                              ||" 
             "\n\t    ||                                                                              ||" 
             "\n\t    ||                                 S Y S T E M                                  ||" 
             "\n\t    ||-------                                                                -------||" 
             "\n\t             ||                                                            ||" 
             "\n\t             ||                                                            ||" 
             "\n\t             ||-------                                              -------||"
             "\n\t                      ||                                          ||" 
             "\n\t                      ||                                          ||" 
             "\n\t                      ||-------                            -------||" 
             "\n\t                               ||                        ||" 
             "\n\t                               ||                        ||"
             "\n\t                               ||========================||" ;         getch();   system("cls");

    
   while(1) {
	
    cout <<"\n======================================================"              
           "==================================================================\n"
           "\n\n\t\t\t\t\t\t     MAIN MENU \n\n\n"        
           "=============================================================="
           "==========================================================\n\n"

          "\n\t\t\t\t\t________________________________"
          "\n\t\t\t\t\t|                              |"
	      "\n\t\t\t\t\t| 1 ->   ALLOTEE SYSTEM        |"
		  "\n\t\t\t\t\t|______________________________|"
		  
		  "\n\t\t\t\t\t________________________________"
          "\n\t\t\t\t\t|                              |"
	      "\n\t\t\t\t\t| 2 ->   ROOMING SYSTEM        |"
		  "\n\t\t\t\t\t|______________________________|"
		  
		  "\n\t\t\t\t\t________________________________"
          "\n\t\t\t\t\t|                              |"
	      "\n\t\t\t\t\t| 3 ->   ROOM ASSIGNMENT       |"
		  "\n\t\t\t\t\t|______________________________|"
		  
		  "\n\t\t\t\t\t________________________________"
          "\n\t\t\t\t\t|                              |"
	      "\n\t\t\t\t\t| 4 ->        EXIT             |"
		  "\n\t\t\t\t\t|______________________________|";
		  
   cout << "\n\n\n\t\t\t\t\t  ENTER YOU CHOICE =  ";     cin>>choice;   system("cls");
   
   switch (choice) {
   	
   	    case 1:
   	    	Allotees :: Menu(A);              break;
   	    
   	    case 2:
   	    	Allotees :: Rooms :: Menu(R, n);      break;
   	    	
   	    case 3:
   	    	Allotees :: AssignMenu(R, n);      break;
   	    	
   	    case 4:	
   	    cout<<"\n\tXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX"                             
		          "\n\t\t\t\t\t_____________________________________"
		          "\n\t\t\t\t\t|                                   |"
				  "\n\t\t\t\t\t|  THANK YOU FOR USING THE SYSTEM   |"
				  "\n\t\t\t\t\t|___________________________________|"
				  "\n\n\tXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n";    
				  exit(0);
   	    
   	    default:	
   	    	cout<<"\n\tXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX"                             
		          "\n\t\t\t\t\t_____________________________________"
		          "\n\t\t\t\t\t| Error!                            |"
				  "\n\t\t\t\t\t|          INVALID INPUT!           |"
				  "\n\t\t\t\t\t|___________________________________|"
				  "\n\n\tXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n";      
				  getch();	system("cls");
   	
   }

}

		
	return 0;
}

