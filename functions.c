#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUMBER_OF_MOVIES 10 //Max number of movies
#include "functions.h" //Library with the functions declaration
#include "structs_descript.h" //Library with the structures

static int nClients=10; //Number of registered clients
 
/*-------------------------------------------------FUNCTIONS DEFINITION------------------------------------*/

/*Start of the Funtion introduction*/

void Introduction(){
	int intro; //Variable to get the answer on the intro funct.
	puts("----------------------------------WELCOME TO MOVIES CLUB AGENCY!----------------------------------");
	puts("");
	puts(" Do you want to create a new account or to log in?");
	puts("");
	puts("(1) REGISTER");
	puts("(2) LOG IN");
	//Action depending on the answer.
	puts("");
	printf("Type an option (1 or 2):");
	scanf("%i", &intro);
	if (intro == 1){
		SaveClients(); //Calling the function safeclients to register
	}else if(intro == 2){
		logging(); //Calling the function to loggin.
		
	}else{
		puts("");
		  puts("Invalid option, please, select a correct one."); 
		  Introduction();
	}  
}
/*End of the introduction function*/

/*Funtion to log in*/

void logging(){
	int found; //Variable to stop the while loop when it finds the client
	int enter; //To select and action depending on if the id has been found or not
	int i; //Position of the client in the array Clients[]	
	char nid[8]; // Gets the the ID introduced when asking to log in
	struct Client Clients[nClients]; //Struct of the array Clients[]
	FILE *fi; //Declare file variable
	fi = fopen("input.txt", "r"); // Open file. In input.txt we have the initial data of some clients.
	/* Read clients information from the input.txt file */
    for (i=0; i<nClients; i++) {
        fscanf(fi, " %[^\t]s",Clients[i].name); //Gets the clients complete name
        fscanf(fi, "%s",Clients[i].id); //Gets the clients ID
        fscanf(fi, "%i", &Clients[i].Birthdate.day); //Gets the day of the birthday
        fscanf(fi, "%i", &Clients[i].Birthdate.month); //Gets the month of the birthday
        fscanf(fi, "%i", &Clients[i].Birthdate.year); //Gets the year of the birthday
	}
	puts("");
	puts("--------------------------------------LOG IN YOUR ACCOUNT--------------------------------------------");
	puts("");
	puts("Enter your ID");   // Logging
	scanf("%s",nid);
	found=0;
	i=0; //Position of the client in the array Clients[].
	enter=0;
	while((found==0) && (i<nClients)){
		if (strcmp(nid,Clients[i].id) == 0){
		    found=1;  //Searching if it is in the file
		    enter=1;		     
		}else{
			i++;
		}
}
	if(enter==1){
		puts("------------------------------------------------------------------------------------------------------");
		puts("");
			MainMenu();
	}else if(enter==0){
		puts("");
		puts("Your ID is not registered yet, please register now.");
		puts("------------------------------------------------------------------------------------------------------");
		puts("");
		SaveClients();
	}
	fclose(fi); 	// close file
}

/* End of the function to log in*/

/*Function to save the data of a new client*/

void SaveClients(){                                                        
	struct Client user; //Struct to save the clients info
	FILE *fi;      //Declare file variable
    puts("");
   puts("--------------------------------------JOIN CLUB MOVIES AGENCY.-------------------------------------------");
     puts("");
     /*Ask for the complete name, Id and Birthday to add it to the text file input.txt*/
   printf("Complete name:");                     
   scanf(" %[^\n]s", user.name);
     puts(""); 
     printf("Create ID:");
     scanf("%s",user.id);
     puts("");
   puts("Now, introduce your birthday:"); 
   printf("Day:");
   scanf("%i", &user.Birthdate.day);
     printf("Month:");
   scanf("%i", &user.Birthdate.month);
     printf("Year:");
   scanf("%i", &user.Birthdate.year);
   //Age filter.
   fi=fopen("input.txt","a"); //Open text file input.txt and write at the end
   fprintf (fi, "\n %s	%s %i %i %i", user.name,user.id, user.Birthdate.day, user.Birthdate.month, user.Birthdate.year);
   fclose(fi);
   puts("");
   puts("Register completed successfuly.!!!");
   puts("");
   puts("Now log in with your ID.");
   puts("");
   nClients++;
   logging();
}

/*End of the funtion to save data of a new client*/

/*Function MainMenu() */

void MainMenu(){
	int menu;
	puts("-------------------------------------------MAIN MENU--------------------------------------------------");
	puts("");
	puts("(1)  Watch an online movie");
	puts("(2)  Show online rentals");
	puts("(3)  Rent a DVD movie");
	puts("(4)  Show DVD rentals");
	puts("(5)  Show DVD availability");
	puts("(6)  Show online movies rented by a client");
	puts("(7)  Exit");
	/* Select an option*/
	do{
	puts("");
	puts("Select one option (Type a number from 1 to 7)");
	scanf("%i", &menu);
	switch(menu){
		case 1: //Call the function WatchOnlineMovies()
		   WatchOnlineMovies();
		   break;
		case 2://Call the function ShowOnlineRentals();
		   //ShowOnlineRentals();
		   break;
		case 3://Call the function RentaDVDMovie();
		   RentaDVDMovie();
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

/*Function to watch online movies*/

void WatchOnlineMovies(){
	int found,enter,i,j,cardnumber,answer,price,day,month,year;
	int location; //Variable for the position of the movie in the text file in order to find its price.
	struct Date Initial;
	char search[100]; //Variable of the title introduced by the title to search on the database.
	FILE *mT; // Open file with the movie titles
	mT = fopen("mtitle.txt", "r"); //In mtitle.txt we have all the initial data with the movie titles
	struct Movies Search[NUMBER_OF_MOVIES]; //Struct of the movies for the title search
	/* Read movies titles information from the file */
	    for (i=0; i<NUMBER_OF_MOVIES; i++) {
        fscanf(mT, " %[^\n]s",Search[i].Title);
	}   
	fclose(mT);
	puts("----------------------------------WATCH ONLINE MOVIES----------------------------------------------------");
	puts("");
	puts("To search for a movie, introduce the title:");
	scanf(" %[^\n]s",search);
	puts("");
	found=0;
	enter=0;
	i=0;
while((found==0) && (i<NUMBER_OF_MOVIES)){
		if (strcmp(search,Search[i].Title) == 0){
		    found=1;  //Searching if it is in the file
		    enter=1;
			location=i;		     
		}else{
			i++;
			
		}
}

if (enter == 1){
	FILE *mp;
	mp = fopen("mprice.txt", "r"); //Open the file with the movie prices.
	//Search for the price of the selected movie
	for (j=0; j<=location; j++){
        fscanf(mp, " %i",&price);
    }
    fclose(mp);
	printf("The total price for %s movie is: %i $.\n",Search[i].Title,price);
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
    puts("Now add a credit card.");
    puts("");
    puts("Introduce card number:");
    scanf("%i",&cardnumber);
    puts("");
    puts("Introduce expiration date (d m y):");
    scanf("%i %i %i",&day,&month,&year);
    puts("");
    printf("Great! Successful payment. Now you can watch %s for 24h. Enjoy! \n",Search[i].Title);
    puts("");
    puts("------------------------------------------------------------------------------------------------------");
    puts("Thank you for using our www.moviesclubagency.net! :D ");
    puts("");
    printf("Movie:       %s \n",Search[i].Title);
    printf("Total price: %i $ \n",price);
    puts("");
    puts("------------------------------------------------------------------------------------------------------");
    puts("");
    	puts("What do you want to do now?");
    	printf("(1) Search for another movie. \n(2) Go back to Main Menu. \n");
    	puts("");
    	puts("Select one option (1 or 2):");
    	scanf("%i",&answer);
    	if (answer == 1){
    		puts("");
    	    WatchOnlineMovies();
    	}else if (answer == 2){
    		puts("");
    	    MainMenu();
    	}	
    puts("------------------------------------------------------------------------------------------------------");
    }
    else if(answer == 2){
    	puts("-------------------------------------------------------------------------------");
    	puts("");
    	printf(" (1) Search for another movie. \n(2)Go back to Main Menu. \n");
    	puts("");
    	puts("Select one option (1 or 2):");
    	scanf("%i",&answer);
    	if (answer == 1){
    		puts("");
    	    WatchOnlineMovies();
    	}else if (answer == 2){
    		puts("");
    	    MainMenu();
    	}	
    }
    
    
}else if(enter == 0){
	puts("");
	puts("The movie does not exist. Please, search again.");
	puts("");
	puts("-------------------------------------------------------------------------------");
	puts("");
	WatchOnlineMovies();
}	
	
}
/*End of the function to watch online movies*/

/*Function to rent a DVD movie*/
void RentaDVDMovie(){
	int found,enter,i,j,cardnumber,answer,price,day,month,year,Finalday;
	int location; //Variable for the position of the movie in the text file in order to find its price.
	struct Date Initial;
	int period;
	char search[100]; //Variable of the title introduced by the title to search on the database.
	FILE *mT; // Open file with the movie titles
	mT = fopen("mtitle.txt", "r"); //In mtitle.txt we have all the initial data with the movie titles
	struct Movies Search[NUMBER_OF_MOVIES]; //Struct of the movies for the title search
	/* Read movies titles information from the file */
	    for (i=0; i<NUMBER_OF_MOVIES; i++) {
        fscanf(mT, " %[^\n]s",Search[i].Title);
	}   
	fclose(mT);
	puts("----------------------------------RENT A DVD MOVIE----------------------------------------------------");
	puts("");
	puts("To search for a movie, introduce the title:");
	scanf(" %[^\n]s",search);
	puts("");
	found=0;
	enter=0;
	i=0;
while((found==0) && (i<NUMBER_OF_MOVIES)){
		if (strcmp(search,Search[i].Title) == 0){
		    found=1;  //Searching if it is in the file
		    enter=1;
			location=i;		     
		}else{
			i++;
			
		}
}

if (enter == 1){
	FILE *mp;
	mp = fopen("mprice.txt", "r"); //Open the file with the movie prices.
	//Search for the price of the selected movie
	for (j=0; j<=location; j++){
        fscanf(mp, " %i",&price);
    }
    fclose(mp);
    printf("To rent %s introduce start date:\n",Search[i].Title);
    scanf("%i %i %i",&Initial.day,&Initial.month,&Initial.year);
    puts("How many days would you like to rent it?");
    scanf("%i",&period);
    Finalday=Initial.day+period;
    price=price*period;
	printf("The total price for %s movie is: %i $.\n",Search[i].Title,price);
	puts("");
	puts("RENT");
	puts("(1) YES");
	puts("(2) NO");
	puts("");
    scanf("%i",&answer);
    if(answer == 1){
    	puts("");
    puts("You have already log in with your account.");
    puts("");
    puts("Now add a credit card.");
    puts("");
    puts("Introduce card number:");
    scanf("%i",&cardnumber);
    puts("");
    puts("Introduce expiration date (d m y):");
    scanf("%i %i %i",&day,&month,&year);
    puts("");
    printf("Great! Successful payment. Please, get the DVD movie. You have to return %s next %i/%i/%i. Enjoy! \n",Search[i].Title,Finalday,Initial.month,Initial.year);
       puts("");
    puts("------------------------------------------------------------------------------------------------------");
    puts("Thank you for using our www.moviesclubagency.net! :D ");
    puts("");
    printf("Movie:              %s \n",Search[i].Title);
    printf("Rental start date:  %i/%i/%i \n",Initial.day,Initial.month,Initial.year);
    printf("Rental end time:    %i/%i/%i \n",Finalday,Initial.month,Initial.year);
    printf("Total price:        %i $ \n",price);
    puts("");
    puts("------------------------------------------------------------------------------------------------------");
    puts("");
    	puts("What do you want to do now?");
    	printf("(1) Search for another movie. \n(2) Go back to Main Menu. \n");
    	puts("");
    	puts("Select one option (1 or 2):");
    	scanf("%i",&answer);
    	if (answer == 1){
    		puts("");
    	    WatchOnlineMovies();
    	}else if (answer == 2){
    		puts("");
    	    MainMenu();
    	}	
    puts("------------------------------------------------------------------------------------------------------");
    }
    else if(answer == 2){
    	puts("-------------------------------------------------------------------------------");
    	puts("");
    	printf(" (1) Search for another movie. \n(2) Go back to Main Menu. \n");
    	puts("");
    	puts("Select one option (1 or 2):");
    	scanf("%i",&answer);
    	if (answer == 1){
    		puts("");
    	    WatchOnlineMovies();
    	}else if (answer == 2){
    		puts("");
    	    MainMenu();
    	}	
    }
    
    
}else if(enter == 0){
	puts("");
	puts("The movie does not exist. Please, search again.");
	puts("");
	puts("-------------------------------------------------------------------------------");
	puts("");
	WatchOnlineMovies();
}	
	
}
/*End of the function to rent a DVD movie*/

/*Function to exit the application*/
int EXIT(){
	
}

/*End of the EXIT function*/

