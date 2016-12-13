#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define size 100
#define NUMBER_OF_MOVIES 10 //Max number of movies
#include "functions.h" //Library with the functions declaration
#include "structs_descript.h" //Library with the structures

static int nClients=10; //Number of registered clients

/*-------------------------------------------------FUNCTIONS DEFINITION------------------------------------------------------*/

/*------------------------------Start of the Funtion Introduction()-------------------------------*/

void Introduction(){
	int intro; //Variable to get the answer on the intro funct.
	puts("----------------------------------WELCOME TO MOVIES CLUB AGENCY!-------------------------------------");
	puts("");
	//Ask to register or to log into an account.
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
		  puts("Invalid option, please, type a number (1 or 2)."); 
		  Introduction();
	}  
}
/*-------------------------------------End of the Introduction() function------------------------------*/

/*-------------------------------------Funtion to log in-----------------------------------------------*/

void logging(){
	int found; //Variable to stop the while loop when it finds the client
	int enter; //To select and action depending on if the id has been found or not
	int i; //Position of the client in the array Clients[]	
	char nid[100]; // Gets the the ID introduced when asking to log in
	struct Client Clients;
	FILE *fi; //Declare file variable
	fi = fopen("clients.txt", "r"); // Open file. In clients.txt we have the initial data of some clients.
	/* Read clients information from the input.txt file */
	puts("");
	puts("--------------------------------------LOG IN YOUR ACCOUNT--------------------------------------------");
	puts("");
	puts("Enter your ID");   // Logging
	scanf("%s",nid);
	found=0;
	i=0; //Position of the client in the array Clients[].
	enter=0;
	//Searching if there is a coincidence in the text file
	while((found==0) && (i<nClients)){
		 fscanf(fi, " %[^\t]s",Clients.name); //Gets the clients complete name
        fscanf(fi, " %[^\t]s",Clients.id); //Gets the clients ID
        fscanf(fi, "%i", &Clients.Birthdate.day); //Gets the day of the birthday
        fscanf(fi, "%i", &Clients.Birthdate.month); //Gets the month of the birthday
        fscanf(fi, "%i", &Clients.Birthdate.year); //Gets the year of the birthday
		if (strcmp(nid,Clients.id) == 0){
		    found=1;  
		    enter=1;
		}else{
			i++;
		}
}
	if(enter==1){
		puts("-----------------------------------------------------------------------------------------------------");
		puts("");
			MainMenu();
	}else if(enter==0){
		puts("");
		puts("Your ID is not registered yet, please register now.");
		puts("");
		SaveClients();
	}
	fclose(fi); 	// close file
}

/* ---------------------------------End of the function to log in---------------------------------*/

/*-------------------------Function to save the data of a new client------------------------------*/

void SaveClients(){                                                        
	struct Client user; //Struct to save the clients info
	FILE *fi;      //Declare file variable
    puts("");
   puts("--------------------------------------JOIN CLUB MOVIES AGENCY.---------------------------------------");
     puts("");
     /*Ask for the complete name, Id and Birthday to add it to the text file input.txt*/
   printf("Complete name:");                     
   scanf(" %[^\n]s", user.name);
     puts(""); 
     printf("Create ID:");
     scanf("%s",user.id);
   	/* Check birthdate */   
	   int dayOk, monthOk, yearOk, dateOk;	
   	do {
   		puts("");
        puts("Introduce your birthday (d m y):");
         puts("");
         scanf("%i %i %i", &user.Birthdate.day,&user.Birthdate.month,&user.Birthdate.year);
         puts("");
   		yearOk = (user.Birthdate.year<=1999); //Check if it is over 18.
   		if (yearOk){
		monthOk = (user.Birthdate.month >= 1) && (user.Birthdate.month <= 12);
   		switch(user.Birthdate.month) {
   			case 1:
   			case 3:
   			case 5:
   			case 7:
   			case 8:
   			case 10:
   			case 12:
   				dayOk = (user.Birthdate.day >= 1) && (user.Birthdate.day <= 31);   					
   				break;
   			case 4:
   			case 6:
   			case 9:
   			case 11:
   				dayOk = (user.Birthdate.day >= 1) && (user.Birthdate.day <= 30);
				break;   					
   			case 2:
   				dayOk = (user.Birthdate.day >= 1) && (user.Birthdate.day <= 28);   					
   				break;   			
   			default:
   				dayOk = 0;
   				break;
   		}
   		dateOk = yearOk && monthOk && dayOk;
   		if(!dateOk) 		
   			printf("%02i/%02i/%i is not a valid date.  \n\n", user.Birthdate.day, user.Birthdate.month, user.Birthdate.year);
   		}else if(user.Birthdate.year>=1999){
   			printf("%02i/%02i/%i is not a valid date. YOU MUST BE OVER 18.  \n\n", user.Birthdate.day, user.Birthdate.month, user.Birthdate.year);
   			puts("");
   			puts("-------------------------------------------BYE---------------------------------------------");
   			exit(EXIT_SUCCESS);
   		}
   	} while( !dateOk );
   	//Now save all the data in the text file
   fi=fopen("input.txt","a"); //Open text file input.txt and write at the end
   fprintf (fi, "\n%s\t%s\t%02i %02i %i", user.name,user.id, user.Birthdate.day, user.Birthdate.month, user.Birthdate.year);
   fclose(fi);
   puts("");
   puts("Register completed successfuly.!!!");
   puts("");
   puts("Now log in with your ID.");
   puts("");
   nClients++;
   logging();
}

/*-------------------------End of the funtion to save data of a new client------------------------*/

/*----------------------------------Function MainMenu()-------------------------------------------*/

void MainMenu(){
	int menu;
	puts("-------------------------------------------MAIN MENU-------------------------------------------------");
	puts("");
	puts("(1)  Watch an online movie.");
	puts("(2)  Show online rentals.");
	puts("(3)  Rent a DVD movie.");
	puts("(4)  Show DVD rentals.");
	puts("(5)  Show DVD availability.");
	puts("(6)  Show online movies rented by a client.");
	puts("(7)  Exit.");
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
		  ShowOnlineMoviesRentedByClient();
		   break;
		case 7://Call the function exit();
		   exit(EXIT_SUCCESS);
		   break;
		default: puts("The option does not exists. Please, select a valid option.");
			
	}// End of the switch 
	}while(menu >7 || menu <1); // End of the do while
}

/*------------------------------End of the MainMenu() function------------------------------------*/

/*----------------------------------Function to watch online movies-------------------------------*/

void WatchOnlineMovies(){
	char completename[100];
	int found,enter,i,j,cardnumber,answer,price,day,month,year;
	int location; //Variable for the position of the movie in the text file in order to find its price.
	struct Date Initial;
	char movie[100];
	char search[100]; //Variable of the title introduced by the title to search on the database.
	FILE *mT; // Open file with the movie titles
	mT = fopen("mtitle.txt", "r"); //In mtitle.txt we have all the initial data with the movie titles
	struct Movies Search[NUMBER_OF_MOVIES]; //Struct of the movies for the title search
	/* Read movies titles information from the file */
	    for (i=0; i<NUMBER_OF_MOVIES; i++) {
        fscanf(mT, " %[^\n]s",Search[i].Title);
	}   
	fclose(mT);
	puts("----------------------------------WATCH ONLINE MOVIES------------------------------------------------");
	puts("");
	puts("Welcome to Movies Club Agency. This is our catalog:");
	puts("");
	FILE *fi;
	fi=fopen("mtitle.txt","r");
	for(i=0;i<NUMBER_OF_MOVIES;i++){
	fscanf(fi," %[^\n]s",movie);
	printf("%s\n",movie);
}
fclose(fi);
puts("");
	puts("To watch a movie, please, introduce the title:");
	scanf(" %[^\n]s",search);
	puts("");
	found=0;
	enter=0;
	i=0;
	//Check if the movie is on the text file mtitle
while((found==0) && (i<NUMBER_OF_MOVIES)){
		if (strcmp(search,Search[i].Title) == 0){
		    found=1; 
		    enter=1;
			location=i;		     
		}else{
			i++;
			
		}
}
//If the movie is founf, the app gets its price from mprice
if (enter == 1){
	FILE *mp;
	mp = fopen("mprice.txt", "r"); //Open the file with the movie prices.
	//Search for the price of the selected movie
	for (j=0; j<=location; j++){
        fscanf(mp, " %i",&price);
    }
    fclose(mp);
	printf("The total price for %s movie is: %i $.\n",Search[i].Title,price);
	//Now asks if the Client wants to buy it
	puts("");
	puts("PURCHASE");
	puts("(1) YES");
	puts("(2) NO");
	puts("");
    scanf("%i",&answer);
    if(answer == 1){
    	puts("");
     puts("Please, introduce complete name:");
	scanf(" %[^\n]s",completename);
    puts("");
     int dayOk, monthOk, yearOk, dateOk;	
   	do {
   		printf("To rent %s introduce start date (dd mm yyyy):\n",Search[i].Title);
        scanf("%i %i %i",&Initial.day,&Initial.month,&Initial.year);
   		yearOk  = (Initial.year>=2016);
		monthOk = (Initial.month >= 1) && (Initial.month <= 12);
   			
   		switch(Initial.month) {
   			case 1:
   			case 3:
   			case 5:
   			case 7:
   			case 8:
   			case 10:
   			case 12:
   				dayOk = (Initial.day >= 1) && (Initial.day <= 31);   					
   				break;
   			case 4:
   			case 6:
   			case 9:
   			case 11:
   				dayOk = (Initial.day >= 1) && (Initial.day <= 30);
				break;   					
   			case 2:
   				dayOk = (Initial.day >= 1) && (Initial.day <= 28);   					
   				break;   			
   			default:
   				dayOk = 0;
   				break;
   		}
   		dateOk = yearOk && monthOk && dayOk;
   		if(!dateOk) 		
   			printf("%02i/%02i/%4i is not a valid date.  \n\n", Initial.day, Initial.month, Initial.year);			    				
   	} while( !dateOk );
    puts("Now add a credit card.");
    puts("");
    puts("Introduce card number:");
    scanf("%i",&cardnumber);
    puts("");
    /* Check expiration date */   
   	do {
   		puts("");
   		puts("Introduce expiration date (m y):");
        scanf("%i %i",&month,&year);
         puts("");
   		yearOk = (year>=2017);
		monthOk = (month >= 1) && (month<=12);
   		dateOk = yearOk && monthOk;
   		if(!dateOk) 		
   			printf("%02i/%i is not a valid expiration date.  \n\n",month,year);
   		}
   	while( !dateOk );
    puts("");
    printf("Great! Successful payment. Now you can watch %s for 24h. Enjoy! \n",Search[i].Title);
    puts("");
    puts("-----------------------------------------------------------------------------------------------------");
    puts("Thank you for using our www.moviesclubagency.net! :D ");
    puts("");
    printf("Movie:       %s \n",Search[i].Title);
    printf("Total price: %i $ \n",price);
    puts("");
    puts("-----------------------------------------------------------------------------------------------------");
    puts("");
    FILE *online;
    online=fopen("OnlineRentals.txt","a");
    fprintf(online,"\n%s\t%s\t%i %i %i %i",Search[i].Title,completename,Initial.day,Initial.month,Initial.year,price); 
    fclose(online);
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
    puts("-----------------------------------------------------------------------------------------------------");
    }
    else if(answer == 2){
    	puts("-----------------------------------------------------------------------------------------------------");
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
	puts("-----------------------------------------------------------------------------------------------------");
	puts("");
	WatchOnlineMovies();
}	
	
}
/*----------------------End of the function to watch online movies--------------------------------*/

/*-------------------Funtion to show online rentals in the current month--------------------------*/
void ShowOnlineRentals(){
	char title[256];
	int month, year;
	FILE *fi;
	struct Film Online;
	int e;
	int found,condit, answer;
	int enter;
	puts("-------------------------------------ONLINE RENTALS----------------------------------------");
	puts("");
	do{
	puts("");
	puts("Introduce the title of the film");
	scanf(" %[^\n]s", title);
	puts("");
	 /* Check date */   
	int monthOk, yearOk,dateOk;	
   	do {
   		puts("");
   			puts("Introduce the date(m y)");
	scanf("%i %i", &month,&year);
         puts("");
   		yearOk = (year>=2016);
		monthOk = (month >= 1) && (month<=12);
   		dateOk = yearOk && monthOk;
   		if(!dateOk) 		
   			printf("%02i/%i is not a valid date.  \n\n",month,year);
   		
   	} while( !dateOk );
	enter=0;
	fi=fopen("OnlineRentals.txt","r");
    e=0;
    found=0;
    condit=0;
    printf("List of online rentals of the movie %s on %02i/%i:\n ",title,month,year);
    puts("");
    puts("CLIENT'S NAME\tSTAR DATE\tTOTAL PRICE");
	    do{
		    fscanf(fi," %[^\t]s", Online.title);
			fscanf(fi," %[^\t]s", Online.name);
			fscanf(fi,"%i", &Online.date.day);
			fscanf(fi,"%i", &Online.date.month);
			fscanf(fi,"%i", &Online.date.year);
			e=fscanf(fi,"%i", &Online.price);
			if(strcmp(title, Online.title)==0){
				enter=1;
				if((e!=EOF) && month==Online.date.month && year==Online.date.year){
				condit=1;
				if(found==0){
				puts("");
				found=1;
			}
				puts("");
				printf("%s\t%i/%i/%i\t%i $\n", Online.name, Online.date.day, Online.date.month, Online.date.year, Online.price);
				
			}
		}
		}while(e!=EOF);
		fclose(fi);
		if (enter==0 && condit==0){
				puts("-------------------------------------------------------------------------------------------");
			puts("");
			puts("                 Film`s information not found, please, choose another one");
				puts("-------------------------------------------------------------------------------------------");
		}
		if(condit==0 && enter==1){
				puts("-------------------------------------------------------------------------------------------");
			puts("");
			printf("           The film %s has not been rented in the month %i in the year %i :\n", title, month, year);
			puts("");
				puts("-------------------------------------------------------------------------------------------");
		}
	}while(enter==0);
	puts("-------------------------------------------------------------------------------------------");
    puts("");
    puts("What do you want to do now?");
    	printf(" (1) Search for another film \n(2) Go back to Main Menu. \n");
    	puts("");
    	puts("Select one option (1 or 2):");
    	scanf("%i",&answer);
    	if (answer == 1){
    		puts("");
    	    ShowOnlineRentals();
    	}else if (answer == 2){
    		puts("");
    	    MainMenu();
    	}	
}

/*-----------------------------End of functin show online rentals---------------------------------*/

/*--------------------------------Function to rent a DVD movie------------------------------------*/
void RentaDVDMovie(){
	int found,enter,i,j,cardnumber,answer,price,day,month,year,period;
	int location; //Variable for the position of the movie in the text file in order to find its price.
	struct Date Initial;
	int Finalday;
	char movie[100];
	char search[100];
	char completename[100]; //Variable of the title introduced by the title to search on the database.
	FILE *mT; // Open file with the movie titles
	mT = fopen("mtitle.txt", "r"); //In mtitle.txt we have all the initial data with the movie titles
	struct Movies Search[NUMBER_OF_MOVIES]; //Struct of the movies for the title search
	/* Read movies titles information from the file */
	    for (i=0; i<NUMBER_OF_MOVIES; i++) {
        fscanf(mT, " %[^\n]s",Search[i].Title);
	}   
	fclose(mT);
	puts("----------------------------------RENT A DVD MOVIE---------------------------------------------------");
		puts("");
	puts("Welcome to Movies Club Agency. This is our catalog:");
	puts("");
	FILE *fi;
	fi=fopen("mtitle.txt","r");
	for(i=0;i<NUMBER_OF_MOVIES;i++){
	fscanf(fi," %[^\n]s",movie);
	printf("%s\n",movie);
}
fclose(fi);
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
	   int dayOk, monthOk, yearOk, dateOk;	
   	do {
   		printf("To rent %s introduce start date (d m y):\n",Search[i].Title);
        scanf("%i %i %i",&Initial.day,&Initial.month,&Initial.year);
   		yearOk  = (Initial.year>=2016);
		monthOk = (Initial.month >= 1) && (Initial.month <= 12);
   			
   		switch(Initial.month) {
   			case 1:
   			case 3:
   			case 5:
   			case 7:
   			case 8:
   			case 10:
   			case 12:
   				dayOk = (Initial.day >= 1) && (Initial.day <= 31);   					
   				break;
   			case 4:
   			case 6:
   			case 9:
   			case 11:
   				dayOk = (Initial.day >= 1) && (Initial.day <= 30);
				break;   					
   			case 2:
   				dayOk = (Initial.day >= 1) && (Initial.day <= 28);   					
   				break;   			
   			default:
   				dayOk = 0;
   				break;
   		}
   		dateOk = yearOk && monthOk && dayOk;
   		if(!dateOk) 		
   			printf("%02i/%02i/%4i is not a valid date.  \n\n", Initial.day, Initial.month, Initial.year);			    				
   	} while( !dateOk );
   	  puts("How many days would you like to rent it?");
   	  scanf("%i",&period);
   	  Finalday=Initial.day+period;
    //Check the avaliabilitiy
      FILE *dvd;
    dvd=fopen("dvdrent.txt","r");
    int iday,imonth,iyear;
    char imovie[100];
    int ent=0;
    found=0;
    int j;
    while (!feof(dvd) && (found !=1)){
    	    fscanf(dvd," %[^\t]s",imovie);
			fscanf(dvd,"%i",&iday);
			fscanf(dvd,"%i",&imonth);
			fscanf(dvd,"%i",&iyear);
			for (j=Initial.day;j<Finalday;j++){
    	    if ((strcmp(imovie,Search[i].Title)==0)&&(iday==Initial.day)&&(imonth==Initial.month)&&(iyear==Initial.year)){
    	    	found=1;
    	    	ent=1;
				}
				}
    }

    fclose(dvd);
    //End of the check
    if (ent==0){
    FILE *mp;
	mp = fopen("mprice.txt", "r"); //Open the file with the movie prices.
	//Search for the price of the selected movie
	for (j=0; j<=location; j++){
        fscanf(mp, " %i",&price);
    }
    fclose(mp); 
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
     puts("Please, introduce complete name:");
	scanf(" %[^\n]s",completename);
    puts("");
    	puts("");
    puts("Now add a credit card.");
    puts("");
    puts("Introduce card number:");
    scanf("%i",&cardnumber);
    puts("");
   /* Check expiration date */   
   	do {
   		puts("");
   		puts("Introduce expiration date (m y):");
        scanf("%i %i",&month,&year);
         puts("");
   		yearOk = (year>=2017);
		monthOk = (month >= 1) && (month<=12);
   		dateOk = yearOk && monthOk;
   		if(!dateOk) 		
   			printf("%02i/%i is not a valid expiration date.  \n\n",month,year);
   		
   	} while( !dateOk );
    puts("");
    printf("Great! Successful payment. Please, get the DVD movie. You have to return %s next %02i/%02i/%04i. Enjoy! \n",Search[i].Title,Finalday,Initial.month,Initial.year);
       puts("");
   puts("-----------------------------------------------------------------------------------------------------");
    puts("Thank you for using our www.moviesclubagency.net! :D ");
    puts("");
    printf("Movie:              %s \n",Search[i].Title);
    printf("Rental start date:  %02i/%02i/%i \n",Initial.day,Initial.month,Initial.year);
    printf("Rental end time:    %02i/%02i/%i \n",Finalday,Initial.month,Initial.year);
    printf("Total price:        %i $ \n",price);
    puts("");
    puts("-----------------------------------------------------------------------------------------------------");
    puts("");
    /*Save the rent in dvdrent.txt*/
    dvd=fopen("dvdrent.txt","a");
    int iiday;
    for (iiday=Initial.day; iiday<=Finalday; iiday++){
        fprintf(dvd,"\n%s\t%i %i %i",Search[i].Title,iiday,Initial.month,Initial.year);
    }    
    fclose(dvd);
     /*Save the rent in ShowDVDRentals.txt*/
    dvd=fopen("ShowDVDRentals.txt","a");
        fprintf(dvd,"\n%s\t%s\t%i %i %i %i %i %i %i",Search[i].Title,completename,Initial.day,Initial.month,Initial.year,Finalday,Initial.month,Initial.year,price); //////////////////////////////////////
    fclose(dvd);
    puts("");
    	puts("What do you want to do now?");
    	printf("(1) Search for another movie. \n(2) Go back to Main Menu. \n");
    	puts("");
    	puts("Select one option (1 or 2):");
    	scanf("%i",&answer);
    	if (answer == 1){
    		puts("");
    	    RentaDVDMovie();
    	}else if (answer == 2){
    		puts("");
    	    MainMenu();
    	}	
    puts("-----------------------------------------------------------------------------------------------------");
    }
    else if(answer == 2){
    	puts("-----------------------------------------------------------------------------------------------------");
    	puts("");
    	printf(" (1) Search for another movie. \n(2) Go back to Main Menu. \n");
    	puts("");
    	puts("Select one option (1 or 2):");
    	scanf("%i",&answer);
    	if (answer == 1){
    		puts("");
    	    RentaDVDMovie();
    	}else if (answer == 2){
    		puts("");
    	    MainMenu();
    	}	
    }
}
  else if(ent==1){
  		puts("");
	printf("There is not avaliable DVD for the movie %s according to the specified dates. Please, search again.\n",Search[i].Title);
	puts("");
	puts("-----------------------------------------------------------------------------------------------------");
	puts("");
	RentaDVDMovie();
  }  
}
else if(enter == 0){
	puts("");
	puts("The movie does not exist. Please, search again.");
	puts("");
	puts("-----------------------------------------------------------------------------------------------------");
	puts("");
	RentaDVDMovie();
}	
	
}
/*-------------------------End of the function to rent a DVD movie--------------------------------*/

/*------------------------Star of function  ShowDVDRentals----------------------------------------*/
void ShowDVDRentals(){
	char title[256];
	int month, year;
	FILE *fi;
	struct FilmD Online; 
	int e;
	int found,condit,answer;
	int enter;
	do{
	puts("Introduce the title of the film");
	scanf(" %[^\n]s", title);
	/* Check date */   
	int monthOk, yearOk,dateOk;	
   	do {
   		puts("");
   			puts("Introduce the date(m y)");
	scanf("%i %i", &month,&year);
         puts("");
   		yearOk = (year>=2016);
		monthOk = (month >= 1) && (month<=12);
   		dateOk = yearOk && monthOk;
   		if(!dateOk) 		
   			printf("%02i/%i is not a valid date.  \n\n",month,year);
   		
   	} while( !dateOk );
	enter=0;
	fi=fopen("ShowDVDRentals.txt","r");
    e=0;
    found=0;
    condit=0;
    puts("");
    printf("List of DVD rentals of the movie %s in %02i/%i is:\n",title,month,year);
    puts("");
    puts("CLIENT'S NAME\tSTAR DATE\tEND DATE\tTOTAL PRICE");
	    do{
		    fscanf(fi," %[^\t]s", Online.title);
			fscanf(fi," %[^\t]s", Online.name);
			fscanf(fi,"%i", &Online.start.day);
			fscanf(fi,"%i", &Online.start.month);
			fscanf(fi,"%i", &Online.start.year);
			fscanf(fi,"%i", &Online.end.day);
			fscanf(fi,"%i", &Online.end.month);
			fscanf(fi,"%i", &Online.end.year);
			e=fscanf(fi," %i", &Online.price);
			if(strcmp(title, Online.title)==0){
				enter=1;
				if((e!=EOF) && month==Online.start.month && year==Online.start.year){
				condit=1;
				if(found==0){
				puts("");
				printf("%s         %i/%i/%i       %i/%i/%i           %i $\n", Online.name, Online.start.day, Online.start.month, Online.start.year, Online.end.day, Online.end.month, Online.end.year, Online.price);
				puts("");
				found=1;
			}		
			}
		}
		}while(e!=EOF);
		fclose(fi);
		if (enter==0 && condit==0){
			puts("-------------------------------------------------------------------------------------------");
			puts("                 Film`s information not found, choose another one");
			puts("-------------------------------------------------------------------------------------------");
		}
		if(condit==0 && enter==1){
			puts("-------------------------------------------------------------------------------------------");
			printf("     The film %s has not been rented in the month %i in the year %i :", title, month, year);
			puts("-------------------------------------------------------------------------------------------");
			puts("");
		}
	}while(enter==0);
	puts("-------------------------------------------------------------------------------------------");
    puts("");
    puts("What do you want to do now?");
    	printf(" (1) Search for another film \n(2) Go back to Main Menu. \n");
    	puts("");
    	puts("Select one option (1 or 2):");
    	scanf("%i",&answer);
    	if (answer == 1){
    		puts("");
    	    ShowDVDRentals();
    	}else if (answer == 2){
    		puts("");
    	    MainMenu();
    	}	
}
/*-------------------------------End of fucntion Show DVD rentals---------------------------------*/

/*------------------------------Function to show DVD avaliability---------------------------------*/
void ShowDVDAvailability(){
	char imovie [100];
	char fsearch [100];
	char actor [100];
	char director [100];
	char description [256];
	int day,month,year;
	int cday, cmonth, cyear;
	int iday,imonth,iyear;
	int period;
	int d;
	int e, r;
	int i;
	int t;
	int s,h1,h2,h3,h4,h5,h6,h7,h72,l;
	s=0;
	h1=0;
	h2=0;
	h3=0;
	h4=0;
	h5=0;
	h6=0;
	h7=0;
	h72=0;
	l=0;
	char name [10][100];
	i=0;
	
	puts("----------------------------------DVD Availability---------------------------------------------------");
	 int dayOk, monthOk, yearOk, dateOk;	
   	do {
   		printf("Introduce start date (d m y):\n");
        scanf("%i %i %i",&day,&month,&year);
   		yearOk  = (year>=2016);
		monthOk = (month >= 1) && (month <= 12);
   			
   		switch(month) {
   			case 1:
   			case 3:
   			case 5:
   			case 7:
   			case 8:
   			case 10:
   			case 12:
   				dayOk = (day >= 1) && (day <= 31);   					
   				break;
   			case 4:
   			case 6:
   			case 9:
   			case 11:
   				dayOk = (day >= 1) && (day <= 30);
				break;   					
   			case 2:
   				dayOk = (day >= 1) && (day <= 28);   					
   				break;   			
   			default:
   				dayOk = 0;
   				break;
   		}
   		dateOk = yearOk && monthOk && dayOk;
   		if(!dateOk) 		
   			printf("%02i/%02i/%4i is not a valid date.  \n\n", day, month, year);			    				
   	} while( !dateOk );
	puts("Introduce how many days");
	scanf(" %i", &period);         
	t=day+period;
	cday=day;
	cmonth=month;
	cyear=year;
	
	
	FILE *dvd;
    dvd=fopen("dvdrent.txt","r");
	
	while (!feof(dvd)){
		    strcpy(name[i], "fault");
    	    fscanf(dvd," %[^\t]s",imovie);
			fscanf(dvd,"%i",&iday);
			fscanf(dvd,"%i",&imonth);
			fscanf(dvd,"%i",&iyear);
			day=cday;
			month=cmonth;
			year=cyear;
			for(d=day; d<=t; d++){
    	    if (iday==day && imonth==month && iyear==year ){
    	    	if( strcmp(imovie,"star wars 1")==0 && s==0){
    	    		strcpy(name[i], imovie);
    	    		s=1;}
    	        if( strcmp(imovie,"harry potter 1")==0 && h1==0){
    	    		strcpy(name[i], imovie);
    	    		h1=1;}
    	    	if( strcmp(imovie,"harry potter 2")==0 && h2==0){
    	    		strcpy(name[i], imovie);
    	    		h2=1;}
    	         if( strcmp(imovie,"harry potter 3")==0 && h3==0){
    	    		strcpy(name[i], imovie);
    	    		h3=1;}
    	    	if( strcmp(imovie,"harry potter 4")==0 && h4==0){
    	    	strcpy(name[i], imovie);
    	    		h4=1;
    	    		}
				if( strcmp(imovie,"harry potter 5")==0 && h5==0){
    	    		strcpy(name[i], imovie);
    	    		h5=1;
    	    		}
				if( strcmp(imovie,"harry potter 6")==0 && h6==0){
    	    		strcpy(name[i], imovie);
    	    		h6=1;
    	    		}
				if( strcmp(imovie,"harry potter 7.1")==0 && h7==0){
    	    		strcpy(name[i], imovie);
    	    		h7=1;
    	    		}
				if( strcmp(imovie,"harry potter 7.2")==0 && h72==0){
    	    	strcpy(name[i], imovie);
    	    		h72=1;
    	    		}
				if( strcmp(imovie,"Locke")==0 && l==0){
    	    		strcpy(name[i], imovie);
    	    		l=1;
    	    	}
}
}
i++;
}
e=i;

for(i=e; i<10; i++){
	strcpy(name[i], "fault");
	
}
puts("\tMOVIE TITLE\tDIRECTOR\tYEAR\tACTOR\tDESCRIPTION\n");
fclose(dvd);
FILE *inf;
inf=fopen("inf.txt", "r");
	s=0;
i=0;
	while (!feof(inf)){
		i=0;
    	    fscanf(inf," %[^\t]s", fsearch);
			fscanf(inf," %[^\t]s", director);
			fscanf(inf,"%i",&year);
			fscanf(inf," %[^\t]s", actor);
			fscanf(inf," %[^\t]s", description);
			
			for(i=0; i<NUMBER_OF_MOVIES ; i++){  //
    	    		if(strcmp(fsearch,name[i])==0){
					s=1;
				}
			}
				if(s==0){
					printf(" %s\t%s\t%i\t%s\t%s\n", fsearch, director, year, actor, description);
					puts("");
					puts("");
				}
				s=0;
    	    		
    	   
    
}
 puts("-----------------------------------------------------------------------------------------------------");
fclose(inf);
}

/*-------------------------------End of the DVD avaliability function-----------------------------*/

/*---------------------------Function to show the movies rented by a client-----------------------*/
void ShowOnlineMoviesRentedByClient(){
	char cname[100];
	char ccname[100];
	char movie[100];
	struct Date Initial;
	int price,answer;
	puts("-----------------------------ONLINE MOVIES RENTED BY CLIENTS-------------------------------");
	puts("");
	puts("Introduce Client´s name:");
	scanf(" %[^\n]s",cname);
	printf("List of movies rented by %s is:\n",cname);
	puts("MOVIE TITLE\tSTART DATE\tTOTAL PRICE");
	//Search
    FILE *online;
    online=fopen("OnlineRentals.txt","r");
    while (!feof(online)){
    	    fscanf(online," %[^\t]s",movie);
    	    fscanf(online," %[^\t]s",ccname);
			fscanf(online,"%i",&Initial.day);
			fscanf(online,"%i",&Initial.month);
			fscanf(online,"%i",&Initial.year);
			fscanf(online,"%i",&price);
    	    if (strcmp(ccname,cname) == 0){
    	    	printf("%s\t%02i/%02i/%i\t%i $ \n",movie,Initial.day,Initial.month,Initial.year,price);
    }
}
    fclose(online);
    puts("-----------------------------------------------------------------------------------------------------");
    puts("");
    puts("What do you want to do now?");
    	printf(" (1) Search for another client \n(2) Go back to Main Menu. \n");
    	puts("");
    	puts("Select one option (1 or 2):");
    	scanf("%i",&answer);
    	if (answer == 1){
    		puts("");
    	    ShowOnlineMoviesRentedByClient();
    	}else if (answer == 2){
    		puts("");
    	    MainMenu();
    	}	
    //End of the search
}
/*---------------------End of the function ShowOnlineMoviesRentedByClient()-----------------------*/

