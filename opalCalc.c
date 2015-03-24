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

#define OFF_PEAK_DISCOUNT 0.7;
#define CONCESSION_HALF_PRICE 0.5

#define TRAIN 0
#define BUS 1
#define FERRY 2
#define LIGHTRAIL 3

#define SYDNEY_FERRIES 0
#define STOCKTON_FERRY 1

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

#define BUS_ZONE_1 1
#define BUS_ZONE_2 2
#define BUS_ZONE_3 3
#define BUS_FARE_1 2.10
#define BUS_FARE_2 3.50
#define BUS_FARE_3 4.50

#define SYDNEY_FERRY_ZONE_1 1
#define SYDNEY_FERRY_ZONE_2 2
#define SYDNEY_FERRY_FARE_1 5.74
#define SYDNEY_FERRY_FARE_2 7.18
#define STOCKTON_FERRY_FARE 2.10

#define LIGHTRAIL_ZONE_1 1
#define LIGHTRAIL_ZONE_2 2
#define LIGHTRAIL_FARE_1 2.10
#define LIGHTRAIL_FARE_2 3.50

/* BEGIN DECLARATION OF FUNCTIONS */
float getFinalCost (void);
int getConcessionStatus (void);
int getIsSunday (void);
float getBasicCost (void)
float getTravelPlan (void);
int getTransportMode (void);
int getIsOffPeak (int transportMode);
int getTravelDist (int transportMode);
int calculateCost (int transportMode, int travelDist, int isOffPeak);
int calculateFinalCost (float basicCost, int concessionStatus, int isSunday);
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
    
    finalCost = calculateFinalCost (basicCost);
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
    int inputGetIsSunday = FALSE; //Initialising to 0 minimise error risk
    printf ("Are you travelling on a Sunday? Enter 1 if you are, otherwise, enter 0.\n");
    printf ("Entering a value other than 0 or 1 will crash the program.\n\n");
    
    scanf("%d", &inputGetIsSunday);
    
    assert (inputGetIsSunday == FALSE || inputGetIsSunday == TRUE);
    
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
    
    return basicCost;
}

float getTravelPlan (void) {
    /* Declaration of variables */
    int transportMode; //Train (0), bus (1) or ferry
    int travelDist; //The distance of the trip (this affects cost)
    int isOffPeak = FALSE; //Only used for train services. Initialised to true;
    float cost = 0; //Holds the cost of the trip. Set to 0 to minimise error risk.
    /* End declaration of variables */
    
    transportMode = getTransportMode();
    travelDist = getTravelDist (transportMode);
    isOffPeak = getIsOffPeak (transportMode);
    cost = calculateCost (transportMode, travelDist, isOffPeak);
    
    return cost;
}

int getTransportMode (void) {
    int inputGetTransportMode = TRAIN; //Initialising to 0 to minimise error risk.
    
    printf ("How will you make your trip?\n");
    printf ("If travelling by train, enter 0. If by bus, enter 1.");
    printf ("If by ferry, enter 2. If by light rail, enter 3.\n")
    printf ("Entering any other value will crash the program.\n");
    
    scanf ("%d", &inputGetTransportMode);
    
    assert (inputGetTransportMode >= TRAIN && inputGetTransportMode <= LIGHTRAIL);
    
    return inputGetTransportMode;
}

int getTravelDist (int transportMode) {
    int inputGetTravelDist;

    if (transportMode == TRAIN) {
        printf ("How far is your train trip?\n");
        printf ("Enter 1 if 0-10km, 2 if 10-20km, 3 if 20-35km, ");
        printf ("4 if 35-65km or 5 if over 65km\n");
        printf ("Entering any other value will crash the program\n");
        
        scanf ("%d", inputGetTravelDist);
        
        assert (inputGetTravelDist >= TRAIN_ZONE_1 &&
            inputGetTravelDist <= TRAIN_ZONE_5);
    } else if (transportMode == BUS) {
        printf ("How far is your train trip?\n");
        printf ("Enter 1 if 0-3km, 2 if 3-8km or 3 if over 8km\n");
        printf ("Entering any other value will crash the program.\n");
        
        scanf ("%d", inputGetTravelDist);
        
        assert (inputGetTravelDist >= BUS_ZONE_1 &&
            inputGetTravelDist <= BUS_ZONE_3);
    } else if (transportMode == FERRY) {
        
    } else if (transportMode == LIGHTRAIL) {
        
    } else {
        printf ("Oops. Something broke. Please panic and yell at ");
        printf ("the developer ASAP.\n");
    }
    
    return inputGetTravelDist;
}
int getIsOffPeak (int transportMode) {
    int inputGetIsOffPeak = FALSE;
    if (transportMode == TRAIN) {
        if (isSunday == FALSE) {
            printf ("You appear to be travelling by train. Great!\n");
            printf ("Are you going to be travelling in the off-peak period, ");
            printf ("a Sunday or on a public holiday)?\n");
            printf ("Enter 1 if you are, or 0 if you're not.\n");
            printf ("Entering any other value will crash the program.\n");
            
            scanf ("%d", inputGetIsOffPeak);
            assert (inputGetIsOffPeak >= FALSE && inputGetIsOffPeak <= TRUE);
        }
        else {
            getIsOffPeak = TRUE;
        }
    }
    return inputGetIsOffPeak;
}

float calculateCost (int transportMode, int travelDist, int isOffPeak) {
    float calculateCostResult = 0;
    if (transportMode == TRAIN) {
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
        
        if (isOffPeak == TRUE) {
            calculateCostResult = calculateCostResult * OFF_PEAK_DISCOUNT;
        }
    } else if (transportMode == BUS) {
        if (travelDist == BUS_ZONE_1) {
            calculateCostResult = BUS_FARE_1;
        } else if (travelDist == BUS_ZONE_2) {
            calculateCostResult = BUS_FARE_2;
        } else if (travelDist == BUS_ZONE_3) {
            calculateCostResult = BUS_FARE_3;
        }
    } else if (transportMode == FERRY) {
        int ferryCompany;
        printf ("Are you using Sydney Ferries or the Stockton Ferry?\n");
        printf ("Enter 0 if you're using Sydney Ferries, and 1 if you're using Stockton.\n");
        printf ("Entering a value other than 0 or 1 will crash the program.\n");
        
        scanf ("%d", &ferryCompany);
        
        assert (ferryCompany >= SYDNEY_FERRIES && ferryCompany <= STOCKTON_FERRY);
        
        if (ferryCompany == SYDNEY_FERRIES) {
            if (travelDist == SYDNEY_FERRY_ZONE_1) {
                calculateCostResult = SYDNEY_FERRY_FARE_1;
            } else if (travelDist == SYDNEY_FERRY_ZONE_2) {
                calculateCostResult = SYDNEY_FERRY_FARE_2;
            }
        } else if (ferryCompany == STOCKTON_FERRY) {
            calculateCostResult = STOCKTON_FERRY_FARE;
        }
    } else if (transportMode == LIGHTRAIL) {
        if (travelDist == LIGHTRAIL_ZONE_1) {
            calculateCostResult = LIGHTRAIL_FARE_1;
        } else if (travelDist == LIGHTRAIL_ZONE_2) {
            calculateCostResult = LIGHTRAIL_FARE_2;
        }
    } else {
        printf ("You broke the program. Please let the developer know.");
    }
    
    return calculateCostResult;
}

float calculateFinalCost (float basicCost, int concessionStatus, int isSunday) {
    if (concessionStatus > NOT_CONCESSION) {
        basicCost = basicCost * CONCESSION_HALF_PRICE;
    }
    else {
        
    }
}








