#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUMBER_OF_MOVIES 10
#include "functions.h"
#include "structs_descript.h"

static int nClients=10;

/*---------------------------FUNCTIONS DEFINITON------------------------------------*/

/*Funtion introduction*/

void Introduction(){
	int intro;
	puts("-------------------Welcome to Movies Club Agency------------------------");
	puts("");
	puts(" Do you want to create a new account or to logging?");
	puts("(1) REGISTER");
	puts("(2) LOG IN");
	do{
		puts("");
		puts("\n Select one option:");
	scanf("%i", &intro);
	switch(intro){
		case 1://Calling the function safeclients.
		   SaveClients();
		    break;
		case 2: //Calling the function to loggin.
		  logging();
		    break;
		default: 
		puts("");
		    puts("Invalid option, select a correct one.");  
	}//Final of the switch:
	}while( intro!=1 && intro!=2);
	
	
}
/*End of the introduction function*/

/*Funtion to log in*/

void logging(){
	int location;
	int found;
	int narray;
	int enter;
	int i; //Position of the client in the array Clients[]	
	int j;
	//Declare file variable
	FILE *fi;
	// Open file
	fi = fopen("input.txt", "r"); //In input.txt we save all the clients information

	struct Client Clients[nClients]; //Struct of the array Clients[]
   
	/* Read clients information from the file */
    for (i=0; i<nClients; i++) {
        fscanf(fi, " %[^\t]s",Clients[i].name);
        fscanf(fi, "%i", &Clients[i].Birthdate.day);
        fscanf(fi, "%i", &Clients[i].Birthdate.month);
        fscanf(fi, "%i", &Clients[i].Birthdate.year);
	}   
	puts("-------------------------Log in your account--------------------------------");
	struct Logging user;
	puts("");
	puts("Enter your name");   // Logging
	scanf(" %[^\n]s",user.name);
	found=0;
	i=0; //The last valid value of i
	enter=0;
	while((found==0) && (i<nClients)){
		if (strcmp(user.name,Clients[i].name) == 0){
		    found=1;  //Searching if it is in the file
		    enter=1;		     
		}else{
			i++;
		}
}
	if(enter==1){
		MainMenu();
	}else if(enter==0){
		puts("");
			puts("Your name is not registred yet, please register now.");
		SaveClients();
	}
	// close file
	fclose(fi);
	  puts("------------------------------------------------------------------------------------------------------");
}

/* End of the function to log in*/

/*Function to save the data of a new client*/

void SaveClients(){                                                        
	struct Client user;
	FILE *fi;      //Declare file variable
	fi=fopen("input.txt","a");
    /* Ask for date and print contact names */
    puts("");
   puts("---------------------------Join Movies Club Agency.-------------------------------------------");
     puts("");
   printf("Complete name:");                      //ASIGNAR VALOR A LA ID
   scanf(" %[^\n]s", user.name);
     puts("");
   puts("First introduce your birthday:"); 
     puts("");                         //PONER FILTRO DE EDAD Y QUE COINCIDADN LAS FECHAS CON VALORES LOGICOS.
   printf("Day:");
   scanf("%i", &user.Birthdate.day);
     printf("Month:");
   scanf("%i", &user.Birthdate.month);
     printf("Year:");
   scanf("%i", &user.Birthdate.year);
   fprintf (fi, "\n %s %i %i %i", user.name, user.Birthdate.day, user.Birthdate.month, user.Birthdate.year);
   fclose(fi);
   puts("");
   puts("Register completed successfuly.!!!");
   puts("");
   nClients++;
   logging();
	
}

/*End of the funtion to save data of a new client*/

/*Function to watch online movies*/

void WatchOnlineMovies(){
	int found,enter,location,i,j,cardnumber,answer,answer2,price;
	int day,month,year;
	FILE *mT; // Open file
	mT = fopen("mtitle.txt", "r"); //In mtitle.txt we save all the titles
	struct Movies Title[NUMBER_OF_MOVIES]; //Struct of the movies for the title search
	struct Movies Search;
	struct Movies Price[NUMBER_OF_MOVIES];
	/* Read movies titles information from the file */
	    for (i=0; i<NUMBER_OF_MOVIES; i++) {
        fscanf(mT, " %[^\n]s",Title[i].Title);
	}   
	fclose(mT);
	puts("---------------------------WATCH ONLINE MOVIES------------------------------------");
	puts("");
	puts("Search for a movie. Introduce the name:");
	scanf(" %[^\n]s",Search.Title);
	puts("");
	found=0;
	enter=0;
	i=0;
while((found==0) && (i<NUMBER_OF_MOVIES)){

		if (strcmp(Search.Title,Title[i].Title) == 0){
		    found=1;  //Searching if it is in the file
		    enter=1;
			location=i;		     
		}else{
			i++;
			
		}
}

if (enter == 1){
	FILE *mp;
	mp = fopen("mprice.txt", "r");
	for (j=0; j<=location; j++){
        fscanf(mp, "%i",&price);
    }
    fclose(mp);
	printf("The total price for %s movie is: %i €.\n",Search.Title,price);
	puts("");
	puts("PURCHASE");
	puts("(1) YES");
	puts("(2) NO");
	puts("");
    scanf("%i",&answer);
    if(answer == 1){
    	puts("");
    puts("You have already log in with your account.");
    puts("");
    puts("Add a credit card.");
    puts("");
    puts("Introduce card number:");
    scanf("%12.i",&cardnumber);
    puts("");
    puts("Introduce expiration date (d m y):");
    scanf("%i %i %i",&day,&month,&year);
    puts("");
    printf("Great! Successful payment. Now you can watch %s for 24h. Enjoy!\n",Search.Title);
    puts("------------------------------------------------------------------------------------------------------");
    }
    else if(answer == 2){
    	puts("-------------------------------------------------------------------------------");
    	puts("");
    	printf(" 1 - Search for another movie \n 2 - Go back to Main Menu \n");
    	puts("");
    	puts("Select one option (1 or 2):");
    	scanf("%i",&answer2);
    	if (answer2 == 1)
    	WatchOnlineMovies();
    	if (answer2 == 2)
    	MainMenu();
    }
    
    
}else if(enter == 0){
	puts("");
	puts("The movie does not exist. Please, search again.");
	puts("");
	puts("-------------------------------------------------------------------------------");
	WatchOnlineMovies();
}	
	
}
/*End of the function to watch online movies*/

/*Function MainMenu() */

void MainMenu(){
	int menu;
	/*Print the Main Menu*/
	printf("-----------------------Main Menu------------------------\n \n 1  Watch an online movie \n 2  Show online rentals \n 3  Rent a DVD movie \n 4  Show DVD rentals \n 5  Show DVD availability \n 6  Show online movies rented by a client \n 7  Exit \n  \n");
	/* Select an option*/
	do{
	puts("Select one option (Type a number from 1 to 7)");
	scanf("%i", &menu);
	switch(menu){
		case 1: //Call the funcition WatchOnlineMovies()
		   WatchOnlineMovies();
		   break;
		case 2://Call the function ShowOnlineRentals();
		   //ShowOnlineRentals();
		   break;
		case 3://Call the function RentaDVDMovie();
		   //RentaDVDMovie();
		   break;
		case 4://Call the function ShowDVDRentals();
		   //ShowDVDRentals();
		   break;
		case 5://Call the function ShowDVDAvailability();
		   //ShowDVDAvailability();
		   break;
		case 6://Call the function ShowOnlineMoviesRentByClient();
		  // ShowOnlineMoviesRentByClient();
		   break;
		case 7://Call the function EXIT();
		   //EXIT();
		   break;
		default: puts("The option does not exists. Please, select a valid option.");
			
	}// End of the switch 
	}while(menu >7 || menu <1); // End of the do while
}

/* End of the MainMenu() function*/
