/*
 * FILE NAME: opalCalc
 * NAME: Opal Calculator Program
 * BY: Weilon Ying
 * DATE: started on 22nd March 2015
 * DESCRIPTION: Calculates the cost of using public transport in Sydney 
 *	with the Opal Card (TM).
 *
 * DISCLAIMER: Opal Card and its associated trademarks are intellectual 
 *  property of Transport for NSW and its subsidiaries such as 
 *  Sydney Trains, Ferries and Buses. The author does not claim any 
 *  responsibility for mistakes in the calculation of the 
 *  journey fare (please don't sue me D:).
 */
#include <stdio.h>
#include <stdlib.h>

/* BEGIN DECLARATION OF FUNCTIONS */
int getFinalCost (void);
/* END DECLARATION OF FUNCTIONS */

int main (int argc, char * argv[]) {
   int costOfJourney = 0;

   printf("The journey of your cost is: %d\n", costOfJourney);
   return EXIT_SUCCESS;
}

int getFinalCost (void) {
	int finalCost = 0; //Initialise final cost variable

	int finalCost = 10; //temporary setting to test main function.
	return finalCost;
}