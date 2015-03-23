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
#include <assert.h>

#define TRUE 1
#define FALSE 0

#define NOT_CONCESSION 0
#define CHILD_STUDENT_CONCESSION 1
#define PENSIONER_CONCESSION 2

#define CONCESSION_HALF_PRICE 0.5

/* BEGIN DECLARATION OF FUNCTIONS */
float getFinalCost (void);
int getConcessionStatus (void);
/* END DECLARATION OF FUNCTIONS */

int main (int argc, char * argv[]) {
   float costOfJourney = 0;
   
   costOfJourney = getFinalCost();
   
   printf("The journey of your cost is: %.2f\n", costOfJourney);
   return EXIT_SUCCESS;
}

float getFinalCost (void) {
    //Initialise return variable
	float finalCost = 0; //Initialise final cost variable
    
    //Initialise calculation variables
    int concessionStatus = NOT_CONCESSION; //Initialise as 0, so 
    //int isSunday = FALSE;
    //int basicCost = 0;
    
    //get value of concessionStatus variable
    concessionStatus = getConcessionStatus();
    
	finalCost = 10; //temporary setting to test main function.
    if (concessionStatus > NOT_CONCESSION) {
        finalCost = finalCost * CONCESSION_HALF_PRICE;
    }
    
	return finalCost;
}

int getConcessionStatus (void) {
    int inputConcessionStatus = NOT_CONCESSION;
    
    printf ("Are you using a concession Opal card?\n");
    printf ("Enter 0 if you are not using a concession card, \n");
    printf ("1 if you are using a child or student card and \n");
    printf ("2 if you are using a pensioner card.\n");
    printf ("Entering a value other than 0, 1 or 2 will crash the program.\n\n");
    
    scanf ("%d", &inputConcessionStatus);
    
    assert (inputConcessionStatus >= NOT_CONCESSION);
    assert (inputConcessionStatus <= PENSIONER_CONCESSION);
    
    return inputConcessionStatus;
}
