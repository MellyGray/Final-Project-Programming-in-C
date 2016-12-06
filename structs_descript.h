#include <stdio.h>
#include <stdlib.h>

#define FILTERING

#ifdef 	FILTERING
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
};struct Date {
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
	char name[256];
	struct Date Birthdate;
	char nationality[];
};
struct Movies {
	char Tittle[256];
	char Genre[256];
	char director[256];
	int year;
	struct info actor;
	char descript[256];
	int prize;
};
struct Film{
	char name[100];
	struct Date date;
	int prize;
};
/*----------------------------------------------------------------------------------------------------------------*/
#endif FILTERING
