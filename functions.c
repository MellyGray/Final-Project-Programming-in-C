#include <stdio.h>
#include <stdlib.h>

#include "functions.h"
#include "structs_descript.h"

#define FILTERING

#ifdef FILTERING

/*---------------------------FUNCTIONS DEFINITON------------------------------------*/

/*Function to filter errors*/

void filtering(int act, int mue, int step){
	char c; //Entry to continiue
	if (act == TRUE){
		printf("%i",mue);
		if(step==TRUE)
		scanf("%c",&c);
	} //End if
}

/*End of the filtering function*/

/*Funtion introduction*/

void Introduction(){
	int intro;
	puts("-------------------Welcome to Movies Club Agency------------------------");
	puts(" Do you want to create a new account or to logging?");
	puts("(1) REGISTER");
	puts("(2) LOG IN");
	do{
		puts("\n Select one option:");
	scanf("%i", &intro);
	switch(intro){
		case 1://Calling the function safeclients.
		   SaveClients();
		    break;
		case 2: //Calling the function to loggin.
		  // logging();
		    break;
		default: 
		    puts("Invalid option, select a correct one.");  
	}//Final of the switch:
	}while( intro!=1 && intro!=2);
	
	
}
/*End of the introduction function*/

/*Funtion to read the clients on the file input.txt*/
void ReadClientsFile(){
	int nClients; //Max number of clients on the file
	int i; //Position of the client in the array Clients[]	
	//Declare file variable
	FILE *fi;
	// Open file
	fi = fopen("input.txt", "r"); //In input.txt we save all the clients information
    	
    // Read file
	fscanf (fi, "%i", &nClients); //Read the maximum number of clients

	struct Client Clients[nClients]; //Struct of the array Clients[]
   
	/* Read clients information from the file */
    for (i=0; i<nClients; i++) {
        fscanf(fi, "%i", &Clients[i].id);
        fscanf(fi, "%s", Clients[i].name);
        fscanf(fi, "%i", &Clients[i].Birthdate.day);
        fscanf(fi, "%i", &Clients[i].Birthdate.month);
        fscanf(fi, "%i", &Clients[i].Birthdate.year);
	}
	    
	// close file
	fclose(fi);
}

/* End of the function of readind clients from the input file*/

/* End of the function of readind clients from the input file*/

void SaveClients(){                                                        
	struct Client user;
    ReadClientsFile();
	FILE *fi;      //Declare file variable
	fi=fopen("input.txt","a");
    /* Ask for date and print contact names */
   puts("Join Movies Club Agency.");
   printf("Complete name(After introducing the name, please press Tab):");                      //ASIGNAR VALOR A LA ID
   scanf("%[^\t]", user.name);
   printf("Birthday:");                          //PONER FILTRO DE EDAD Y QUE COINCIDADN LAS FECHAS CON VALORES LOGICOS.
   printf("Day:");
   scanf("%i", &user.Birthdate.day);
     printf("Month:");
   scanf("%i", &user.Birthdate.month);
     printf("Year:");
   scanf("%i", &user.Birthdate.year);
   fprintf (fi, "\n %s %i %i %i", user.name, user.Birthdate.day, user.Birthdate.month, user.Birthdate.year);
   fclose(fi);
	
}

/*End of the funtion Clients()*/

/*Function MainMenu() */

void MainMenu(){
	int menu;
	/*Print the Main Menu*/
	printf("Main Menu/n 1 � Watch an online movie /n 2 � Show online rentals /n 3 � Rent a DVD movie /n 4 � Show DVD rentals /n5 � Show DVD availability /n 6 � Show online movies rented by a client /n 7 � Exit /n Please, select an option (1-7):");
	/* Select an option*/
	do{
	puts("Select one option (Type a number from 1 to 7)");
	scanf("%i", &menu);
	switch(menu){
		case 1: //Call the funcition WatchOnlineMovies()
		   WatchOnlineMovies();
		   break;
		case 2://Call the function ShowOnlineRentals();
		   ShowOnlineRentals();
		   break;
		case 3://Call the function RentaDVDMovie();
		   RentaDVDMovie();
		   break;
		case 4://Call the function ShowDVDRentals();
		   ShowDVDRentals();
		   break;
		case 5://Call the function ShowDVDAvailability();
		   ShowDVDAvailability();
		   break;
		case 6://Call the function ShowOnlineMoviesRentByClient();
		   ShowOnlineMoviesRentByClient();
		   break;
		case 7://Call the function EXIT();
		   EXIT();
		   break;
		default: puts("The option does not exists. Please, select a valid option.");
			
	}// End of the switch 
	}while(menu >7 || menu <1); // End of the do while
}

/* End of the MainMenu() function*/

#endif FILTERING
