#include <stdio.h>
#include <stdlib.h>

/*Header to define functions*/

void MainMenu();
/*
The main menu of the programm, it should stard with the execution on the app.*/

void ShowOnlineRentals();
/* 
First option of the main menu, it allows the user to rent an online movie*/

void WatchOnlineMovies();
/*
Second option of the main menu, it shows a list of the online rentals of a movie in the current month*/

void RentaDVDMovie();
/*
Given a movie title and a period of time (start and end dates), 
the application should find the availability of the required movie in the indicated period */

void ShowDVDRentals();
/*
The main purpose of this functionality is to show a list of the rentals of a specific movie in the current month. */

void ShowDVDAvailability();
/*
The main purpose is to show a list of the available DVD movies 
(DVDs which are not rented for a specific period of time) in the agency.*/

void ShowOnlineMoviesRentByClient();
/*
After introducing the client’s name, the application shows a list of the movies that have been rented by him/her.*/

void EXIT();

/*End the execution of the program*/
