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
};
/*----------------------------------------------------------------------------------------------------------------*/
#endif FILTERING
