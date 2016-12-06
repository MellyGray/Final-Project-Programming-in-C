#include <stdio.h>
#include <stdlib.h>

#include "functions_description.h"
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

/* Function SaveClients() */

void SaveClients(){
    ReadClientsFile();      
    /* Ask for date and print contact names */
    puts("Join Movies Club Agency.");
   puts("Complete name");
   scanf("")       //The extrange method to write at the end
    printf("day? ");
    scanf("%i", &d);
    printf("month? ");
    scanf("%i", &m);
    
    printf("\nContacts born on %i/%i is ", d, m);
	for(i=0; i<nContacts; i++) {
        if(contacts[i].birthDate.day == d && contacts[i].birthDate.month == m)
            printf("%s\n", contacts[i].name);
    }

	
}

/*End of the funtion Clients()*/

/*Function MainMenu() */

void MainMenu(){
	int menu;
	/*Print the Main Menu*/
	printf("Main Menu/n 1 – Watch an online movie /n 2 – Show online rentals /n 3 – Rent a DVD movie /n 4 – Show DVD rentals /n5 – Show DVD availability /n 6 – Show online movies rented by a client /n 7 – Exit /n Please, select an option (1-7):");
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

// Start of function 2
void ShowOnlineRentals(){
	char title[256];
	FILE *fi;
    int i;
	struct Film Online[i];
	int e;
	int enter;
	int t;
	t=-1;
	do{
	puts("Introduce the title of the film");
	char title[256];
	scanf(" %[^\n]", title);
	enter=0;
	i=0;
	if(strcmp(title,"star wars 1")==0){
		fi=fopen("star wars 1O.txt","r");
		do{
	    e=fscanf(fi," %[^\n]", &Online[i].name);
		printf("%s", Online[i].name);
		e=fscanf(fi,"%i", &Online[i].date.day);
		printf("%i", Online[i].date.month);
		if(e!=t){
			i++;
		}	    //Vamos a hacer dos archivos, uno con nombres y otro con una estrutura file              //de data y file
		}while(e!=t);
		fclose(fi);
	}else if(strcmp(title,"harry potter 1")==0){
		fi=fopen("harry potter 1.txt","r");
		do{
			e=fscanf(fi,"%[^\t]", Online[i].name);
			printf("%s", Online[i].name);
			e=fscanf(fi,"%i", &Online[i].date.day);
			printf("%i", Online[i].date.day);
			e=fscanf(fi,"%i", &Online[i].date.month);
			printf("%i", Online[i].date.month);
			e=fscanf(fi,"%i", &Online[i].date.year);
			printf("%i", Online[i].date.year);
			e=fscanf(fi,"%[^\n]", &Online[i].prize);
			printf("%i", Online[i].prize);
			puts("");
			i++;    //Vamos a hacer dos archivos,            //de data y file
		}while(e!=t);
		fclose(fi);
	}else if(strcmp(title,"harry potter 2")==0){
		fi=fopen("harry potter 2.txt","r");
		do{
			e=fscanf(fi,"%[^\t]", Online[i].name);
			printf("%s", Online[i].name);
			e=fscanf(fi,"%i", &Online[i].date.day);
			printf("%i", Online[i].date.day);
			e=fscanf(fi,"%i", &Online[i].date.month);
			printf("%i", Online[i].date.month);
			e=fscanf(fi,"%i", &Online[i].date.year);
			printf("%i", Online[i].date.year);
			e=fscanf(fi,"%[^\n]", &Online[i].prize);
			printf("%i", Online[i].prize);
			puts("");
			i++;    //Vamos a hacer dos archivos,               //de data y file
		}while(e!=t);
		fclose(fi);
	}else if(strcmp(title,"harry potter 3")==0){
		fi=fopen("harry potter 3.txt","r");
		do{
			e=fscanf(fi,"%[^\t]", Online[i].name);
			printf("%s", Online[i].name);
			e=fscanf(fi,"%i", &Online[i].date.day);
			printf("%i", Online[i].date.day);
			e=fscanf(fi,"%i", &Online[i].date.month);
			printf("%i", Online[i].date.month);
			e=fscanf(fi,"%i", &Online[i].date.year);
			printf("%i", Online[i].date.year);
			e=fscanf(fi,"%[^\n]", &Online[i].prize);
			printf("%i", Online[i].prize);
			puts("");
			i++;    //Vamos a hacer dos archivos,          //de data y file
		}while(e!=t);
		fclose(fi);
	}else if(strcmp(title,"harry potter 4")==0){
		fi=fopen("harry potter 4.txt","r");
		do{
			e=fscanf(fi,"%[^\t]", Online[i].name);
			printf("%s", Online[i].name);
			e=fscanf(fi,"%i", &Online[i].date.day);
			printf("%i", Online[i].date.day);
			e=fscanf(fi,"%i", &Online[i].date.month);
			printf("%i", Online[i].date.month);
			e=fscanf(fi,"%i", &Online[i].date.year);
			printf("%i", Online[i].date.year);
			e=fscanf(fi,"%[^\n]", &Online[i].prize);
			printf("%i", Online[i].prize);
			puts("");
			i++;     //Vamos a hacer dos archivos,dos archivos, uno con nombres y otro con una estrutura file
			               //de data y file
		}while(e!=t);
		fclose(fi);
	}else if(strcmp(title,"harry potter 5")==0){
		fi=fopen("harry potter 5.txt","r");
		do{
			e=fscanf(fi,"%[^\t]", Online[i].name);
			printf("%s", Online[i].name);
			e=fscanf(fi,"%i", &Online[i].date.day);
			printf("%i", Online[i].date.day);
			e=fscanf(fi,"%i", &Online[i].date.month);
			printf("%i", Online[i].date.month);
			e=fscanf(fi,"%i", &Online[i].date.year);
			printf("%i", Online[i].date.year);
			e=fscanf(fi,"%[^\n]", &Online[i].prize);
			printf("%i", Online[i].prize);
			puts("");
			i++;     //Vamos a hacer dos archivos,              //de data y file
		}while(e!=t);
		fclose(fi);
	}else if(strcmp(title,"harry potter 6")==0){
		fi=fopen("harry potter 6.txt","r");
		do{
			e=fscanf(fi,"%[^\t]", Online[i].name);
			printf("%s", Online[i].name);
			e=fscanf(fi,"%i", &Online[i].date.day);
			printf("%i", Online[i].date.day);
			e=fscanf(fi,"%i", &Online[i].date.month);
			printf("%i", Online[i].date.month);
			e=fscanf(fi,"%i", &Online[i].date.year);
			printf("%i", Online[i].date.year);
			e=fscanf(fi,"%[^\n]", &Online[i].prize);
			printf("%i", Online[i].prize);
			puts("");
			i++;     //Vamos a hacer dos archivos,           //de data y file
		}while(e!=t);
		fclose(fi);
	}else if(strcmp(title,"harry potter 7.1")==0){
		fi=fopen("harry potter 7.1.txt","r");
		do{
			e=fscanf(fi,"%[^\t]", Online[i].name);
			printf("%s", Online[i].name);
			e=fscanf(fi,"%i", &Online[i].date.day);
			printf("%i", Online[i].date.day);
			e=fscanf(fi,"%i", &Online[i].date.month);
			printf("%i", Online[i].date.month);
			e=fscanf(fi,"%i", &Online[i].date.year);
			printf("%i", Online[i].date.year);
			e=fscanf(fi,"%[^\n]", &Online[i].prize);
			printf("%i", Online[i].prize);
			puts("");
			i++;     //Vamos a hacer dos archivos,              //de data y file
		}while(e!=t);
		fclose(fi);
	}else if(strcmp(title,"harry poter 7.2")==0){
		fi=fopen("harry poter 7.2.txt","r");
		do{
			e=fscanf(fi,"%[^\t]", Online[i].name);
			printf("%s", Online[i].name);
			e=fscanf(fi,"%i", &Online[i].date.day);
			printf("%i", Online[i].date.day);
			e=fscanf(fi,"%i", &Online[i].date.month);
			printf("%i", Online[i].date.month);
			e=fscanf(fi,"%i", &Online[i].date.year);
			printf("%i", Online[i].date.year);
			e=fscanf(fi,"%[^\n]", &Online[i].prize);
			printf("%i", Online[i].prize);
			puts("");
			i++;     //Vamos a hacer dos archivos,             //de data y file
		}while(e!=t);
		fclose(fi);
	}else if(strcmp(title,"Locke")==0){
		do{
			e=fscanf(fi,"%[^\t]", Online[i].name);
			printf("%s", Online[i].name);
			e=fscanf(fi,"%i", &Online[i].date.day);
			printf("%i", Online[i].date.day);
			e=fscanf(fi,"%i", &Online[i].date.month);
			printf("%i", Online[i].date.month);
			e=fscanf(fi,"%i", &Online[i].date.year);
			printf("%i", Online[i].date.year);
			e=fscanf(fi,"%[^\n]", &Online[i].prize);
			printf("%i", Online[i].prize);
			puts("");
			i++;     //Vamos a hacer dos archivos,      //de data y file
		}while(e!=t);
		fclose(fi);
	}else{
		puts("Please choose a correct option");
		enter=1;
	}
}while(enter==1);
}

#endif FILTERING

//End of  function 2
