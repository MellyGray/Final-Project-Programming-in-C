#include <stdio.h>
#include <stdlib.h>

//#define FILTERING

//#ifdef 	FILTERING
/*--------------------------------------BLOCK FOR STRUCTURES------------------------------------------------------*/
struct Date {
    int day;
    int month;
    int year;
};

struct Client {
	int id;       // To make the ID, make a loop that sum 1 number to 00000000
    char name[100];
    struct Date Birthdate;
};

struct Logging {    //ATENDER SIEMPRE A LA LOCALIDAD DE LAS VARIABLES,
	char name[100]; //No vaya a ser que una variable que pensemo que es local no lo es
};
struct info {
	char name[100];
	struct Date Birthdate;
	char nationality[50];
};
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
//#endif FILTERING
