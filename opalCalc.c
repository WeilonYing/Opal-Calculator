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

#define TRAIN 0
#define BUS 1f
#define FERRY 2

#define TRAIN_ZONE_1 1
#define TRAIN_ZONE_2 2
#define TRAIN_ZONE_3 3
#define TRAIN_ZONE_4 4
#define TRAIN_ZONE_5 5
#define TRAIN_FARE_1 3.38
#define TRAIN_FARE_2 4.20
#define TRAIN_FARE_3 4.82
#define TRAIN_FARE_4 6.46
#define TRAIN_FARE_5 8.30

#define CONCESSION_HALF_PRICE 0.5

/* BEGIN DECLARATION OF FUNCTIONS */
float getFinalCost (void);
int getConcessionStatus (void);
int getIsSunday (void);
float getBasicCost (void)
float getTravelPlan (void);
int getTransportMode (void);
int getTravelDist (int transportMode);
int calculateCost (int transportMode, int travelDist, int isOffPeak);
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
    int concessionStatus = NOT_CONCESSION; //Initialise as 0, to minimise error risk.
    int isSunday = FALSE; //Initialise as 0 to minimise error risk.
    float basicCost = 0;
    
    //get value of concessionStatus variable
    concessionStatus = getConcessionStatus();
    
    //get value of isSunday variable
    isSunday = getIsSunday();
    
    //get value of basicCost
    basicCost = getBasicCost();
    
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
    
    scanf ("%d", &inputConcessionStatus);inputGetIsSunday
    
    assert (inputConcessionStatus >= NOT_CONCESSION);
    assert (inputConcessionStatus <= PENSIONER_CONCESSION);
    
    return inputConcessionStatus;
}

int getIsSunday (void) {
    int inputGetIsSunday = 0; //Initialising to 0 minimise error risk
    printf ("Are you travelling on a Sunday? Enter 1 if you are, otherwise, enter 0.\n");
    printf ("Entering a value other than 0 or 1 will crash the program.\n\n");
    
    scanf("%d", &inputGetIsSunday);
    
    assert (inputGetIsSunday == 0 || inputGetIsSunday == 1);
    
    return inputGetIsSunday;
}

float getBasicCost (void) {
    float basicCost = 0; //Initialise to 0 to minimise error risk
    int allTripsEntered = FALSE //Set to true when user confirms all trips entered
    
    while (allTripsEntered != TRUE) {
        basicCost += getTravelPlan();
        
        printf ("Would you like to enter a connecting trip to your journey?\n");
        printf ("If yes, please enter 1. Otherwise, enter 0.\n");
        printf ("Entering a value other than 0 or 1 will crash the program");
        
        scanf ("%d", &allTripsEntered);
        
        assert (allTripsEntered == TRUE || allTripsEntered == FALSE);
    }
}

float getTravelPlan (void) {
    /* Declaration of variables */
    int transportMode; //Train (0), bus (1) or ferry
    int travelDist; //The distance of the trip (this affects cost)
    int isOffPeak = TRUE; //Only used for train services. Initialised to true;
    float cost = 0; //Holds the cost of the trip. Set to 0 to minimise error risk.
    /* End declaration of variables */
    
    transportMode = getTransportMode();
    travelDist = getTravelDist (transportMode);
    cost = calculateCost (transportMode, travelDist, isOffPeak);
    
    return cost;
}

int getTransportMode (void) {
    int inputGetTransportMode = TRAIN; //Initialising to 0 to minimise error risk.
    
    printf ("How will you make your trip?\n");
    printf ("If travelling by train, enter 0. If by bus, enter 1.");
    printf ("If by ferr, enter 2.\n")
    printf ("Entering any other value will crash the program");
    
    scanf ("%d", &inputGetTransportMode);
    
    assert (inputGetTransportMode >= TRAIN && inputGetTransportMode <= FERRY);
    
    return inputGetTransportMode;
}

int getTravelDist (int transportMode) {
    int inputGetTravelDist;
    
    inputGetTravelDist = 1; //debug
    if (transportMode == TRAIN) {
        //NOTE TO SELF: WRITE CODE TO PROCESS IF USER IS TRAVELLING DURING PEAK OR OFF PEAK!
        
    } else if (transportMode == BUS) {
        
    } else if (transportMode == FERRY) {
        
    }
    
    return inputGetTravelDist;
}

float calculateCost (int transportMode, int travelDist, int isOffPeak) {
    float calculateCostResult = 0;
    if (transportMode == TRAIN) {
        printf ("Are you travelling off peak")
        
        if (travelDist == TRAIN_ZONE_1) {
            calculateCostResult = TRAIN_FARE_1;
        } else if (travelDist == TRAIN_ZONE_2) {
            calculateCostResult = TRAIN_FARE_2;
        } else if (travelDist == TRAIN_ZONE_3) {
            calculateCostResult = TRAIN_FARE_3;
        } else if (travelDist == TRAIN_ZONE_4) {
            calculateCostResult = TRAIN_FARE_4;
        } else if (travelDist == TRAIN_ZONE_5) {
            calculateCostResult = TRAIN_FARE_5;
        }
        
        if (isOffPeak )
    }
}








