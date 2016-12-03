#include <stdio.h>
#include <stdlib.h>

#include "functions_description.h"

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

#endif FILTERING
