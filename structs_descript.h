#include <stdio.h>
#include <stdlib.h>

/*--------------------------------------LIBRARY FOR STRUCTURES------------------------------------------------------*/

//Structure for a Date
struct Date {
    int day;
    int month;
    int year;
};

//Structure for the Client information
struct Client {
	char id[8];       
    char name[100];
    struct Date Birthdate;
};

//Structure for an actor information
struct info {
	char name[100];
	struct Date Birthdate;
	char nationality[50];
};

//Structure for movies info.
struct Movies {
	char Title[100];
	char Genre[100];
	char director[100];
	int year;
	struct info actor;
	char descript[256];
	int price;
};

/*----------------------------------------------------------------------------------------------------------------*/
