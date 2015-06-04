/*
 * FILE NAME: opalCalc
 * NAME: Opal Calculator Program
 * BY: Weilon Ying
 * DATE: started on 22nd March 2015
 * DESCRIPTION: Calculates the cost of using public transport in Sydney 
 *  with the Opal Card (TM).
 *
 * DISCLAIMER: Opal Card and its associated trademarks are intellectual 
 *  property of Transport for NSW and its subsidiaries such as 
 *  Sydney Trains, Ferries and Buses. The author does not claim any 
 *  responsibility for mistakes in the calculation of the 
 *  journey fare (please don't sue me D:).
 * 
 * All fares have been obtained from https://www.opal.com.au/en/fares-and-benefits/
 * as of 4th June 2015.
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "opalCalcStandardFunctions.h"
#include "opalCalcDefinitions.h"

/* BEGIN DECLARATION OF FUNCTIONS */
void printWelcomeMessage (void);

float getFinalCost (void);
int getConcessionStatus (void);
int getIsSunday (void);
float getBasicCost (void);
float getTravelPlan (void);
int getTransportMode (void);
int getIsOffPeak (int transportMode);
int getTravelDist (int transportMode);
float calculateCost (int transportMode, int travelDist, int isOffPeak);
float calculateFinalCost (float basicCost, int concessionStatus, int isSunday);

/* END DECLARATION OF FUNCTIONS */

int main (int argc, char * argv[]) {
    printWelcomeMessage();

    float costOfJourney = 0;

    costOfJourney = getFinalCost();
    
    printf("\nIf you're travelling to/from a Sydney Airport station, \n"
        "please be aware that a station access fee applies ($13 for \n"
        "adults, $11.60 for child/concession).\n");

    printf("\nThe cost of your journey is up to: $%.2f\n", costOfJourney);

    printf("\nThank you for using Opal Calculator.\n\n");

    return EXIT_SUCCESS;
}

void printWelcomeMessage() {
    printf ("===========================\n"
            "      OPAL CALCULATOR      \n"
            "===========================\n");

    printf ("\nby Weilon Ying (z5059444)\n");

    printf ("\nThis is my Something Awesome project! Please rate fairly :).\n");
    printf ("All fares have been obtained from "
        "https://www.opal.com.au/en/fares-and-benefits/calculating_opal_fares/ as of 4th June 2015.\n");
    printf ("Opal is a trademark owned by Transport for NSW.\n\n");


}

float getFinalCost (void) { //Master function

    float finalCost = 0; //Initialise final cost (return) variable

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
    
    finalCost = calculateFinalCost (basicCost, concessionStatus, isSunday);

    return finalCost;
}

int getConcessionStatus (void) {
    int inputConcessionStatus = NOT_CONCESSION;
    
    printf ("Hello! Are you using a concession Opal card?\n");
    printf ("Enter 0 if you are not using a concession card, \n");
    printf ("1 if you are using a child or student card and \n");
    printf ("2 if you are using a pensioner card.\n\n");
    
    inputConcessionStatus = getInput (NOT_CONCESSION, PENSIONER_CONCESSION);
    if (inputConcessionStatus < NOT_CONCESSION || 
        inputConcessionStatus > PENSIONER_CONCESSION) {

        reportProgramError ("GCS_ICS");
    }
    
    return inputConcessionStatus;
}

int getIsSunday (void) {

    int inputGetIsSunday = FALSE; //Initialising to 0 minimise error risk
    printf ("Are you travelling on a Sunday? "
        "Enter 1 if you are, otherwise, enter 0.\n\n");
    
    getInput (FALSE, TRUE);
    
    if (inputGetIsSunday < FALSE || inputGetIsSunday > TRUE) {

        reportProgramError ("GIS_IGS");
    }
    
    return inputGetIsSunday;
}

float getBasicCost (void) {

    float basicCost = 0; //Initialise to 0 to minimise error risk
    int addConnectingTrip = TRUE;
    int numTrips = 0;
    
    while (addConnectingTrip != FALSE) {
        basicCost += getTravelPlan();

        numTrips++;

        if (numTrips < MAX_TRIPS) {
            //A journey has a maximum amount of trips (as of 2015, this is 3)
            
            printf ("You currently have %d trips in your journey.\n", numTrips);

            printf ("Would you like to enter a connecting trip to your journey?\n");
            printf ("If yes, please enter 1. Otherwise, enter 0.\n\n");
            
            addConnectingTrip = getInput (FALSE, TRUE);
            
            if (addConnectingTrip < FALSE || addConnectingTrip > TRUE) {
                reportProgramError ("GBC_ACT");
            }

        } else {
            addConnectingTrip = FALSE;

            printf ("You currently have %d trips in your journey, "
                "which is the maximum allowed (%d).\n\n", numTrips, MAX_TRIPS);
        }
        
        
    }
    
    return basicCost;
}

float getTravelPlan (void) {
    /* Declaration of variables */
    int transportMode; //Train (0), bus (1), ferry (2) or light rail (3)
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
    printf ("If travelling by train, enter %d. If by bus, enter %d. \n"
        "If by ferry, enter %d. If by light rail, enter %d.\n\n", 
        TRAIN, BUS, FERRY, LIGHTRAIL);

    inputGetTransportMode = getInput (TRAIN, LIGHTRAIL);
    
    if (inputGetTransportMode < TRAIN || inputGetTransportMode > LIGHTRAIL) {
        reportProgramError ("GTM_IGTM");
    }
    
    return inputGetTransportMode;
}

int getTravelDist (int transportMode) {
    int inputGetTravelDist = NO_INPUT;

    if (transportMode == TRAIN) {

        printf ("How far is your train trip?\n");
        printf ("Enter %d if 0-10km, %d if 10-20km, %d if 20-35km, "
        "%d if 35-65km or %d if over 65km\n\n", 
        TRAIN_ZONE_1, TRAIN_ZONE_2, TRAIN_ZONE_3, TRAIN_ZONE_4, TRAIN_ZONE_5);
        
        inputGetTravelDist = getInput (TRAIN_ZONE_1, TRAIN_ZONE_5);

        if (inputGetTravelDist < TRAIN_ZONE_1 ||
            inputGetTravelDist > TRAIN_ZONE_5) {

            reportProgramError ("GTD_TRAIN");
        }
        
    } else if (transportMode == BUS) {

        printf ("How far is your bus trip?\n");
        printf ("Enter %d if 0-3km, %d if 3-8km or %d if over 8km\n\n",
            BUS_ZONE_1, BUS_ZONE_2, BUS_ZONE_3);
        
        inputGetTravelDist = getInput (BUS_ZONE_1, BUS_ZONE_3);
        
        if (inputGetTravelDist < BUS_ZONE_1 ||
            inputGetTravelDist > BUS_ZONE_3) {

            reportProgramError ("GTD_BUS");
        }

    } else if (transportMode == FERRY) {

        int ferryCompany;

        printf ("Are you using Sydney Ferries or the Stockton Ferry?\n");
        printf ("Enter %d if you're using Sydney Ferries, "
            "and %d if you're using Stockton.\n\n", 
            SYDNEY_FERRIES, STOCKTON_FERRY);
        
        ferryCompany = getInput (SYDNEY_FERRIES, STOCKTON_FERRY);
        
        if (ferryCompany < SYDNEY_FERRIES || ferryCompany > STOCKTON_FERRY) {

            reportProgramError ("GTD_FERRYCOMP");
        }
        
        if (ferryCompany == SYDNEY_FERRIES) {

            printf ("How far is your ferry trip?\n");
            printf ("Enter %d if 0-9km or %d if over 9km.\n\n", 
                SYDNEY_FERRY_ZONE_1, SYDNEY_FERRY_ZONE_2);

            inputGetTravelDist = getInput (SYDNEY_FERRY_ZONE_1, SYDNEY_FERRY_ZONE_2);
        } else if (ferryCompany == STOCKTON_FERRY) {

            inputGetTravelDist = STOCKTON_FERRY_ZONE;
        } else {

            reportProgramError ("GTD_FERRYCOMP");
        }

        if (inputGetTravelDist < SYDNEY_FERRY_ZONE_1 ||
            inputGetTravelDist > STOCKTON_FERRY_ZONE) {

            reportProgramError ("GTD_FERRY");
        }

    } else if (transportMode == LIGHTRAIL) {

        printf ("How far is your light rail trip?\n");
        printf ("Enter %d if 0-3km or %d "
            "if over 3km.\n\n", LIGHTRAIL_ZONE_1, LIGHTRAIL_ZONE_2);

        inputGetTravelDist = getInput (LIGHTRAIL_ZONE_1, LIGHTRAIL_ZONE_2);

        if (inputGetTravelDist < LIGHTRAIL_ZONE_1 || 
            inputGetTravelDist > LIGHTRAIL_ZONE_2) {

            reportProgramError ("GTD_LIGHT");
        }

    } else {

        reportProgramError ("GTD_TRANS");
    }
    
    return inputGetTravelDist;
}
int getIsOffPeak (int transportMode) {

    int inputGetIsOffPeak = FALSE;

    if (transportMode == TRAIN) {

        printf ("You appear to be travelling by train. Great!\n");
        printf ("Are you going to be travelling in the off-peak period?\n");
        printf ("(Off-peak period is anytime that is not 7-9am or 4-6:30pm\n");
        printf ("for Sydney Trains and 6-8am and 4-6:30pm for NSW TrainLink)\n");
        printf ("Enter %d if you are, or %d if you're not.\n\n",
            TRUE, FALSE);
        
        inputGetIsOffPeak = getInput (FALSE, TRUE);
        if (inputGetIsOffPeak < FALSE || inputGetIsOffPeak > TRUE) {

            reportProgramError ("GIOP_I");
        }
    }
    return inputGetIsOffPeak;
}

float calculateCost (int transportMode, int travelDist, int isOffPeak) {
    //Calculates the user's cost for a single trip.

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
        } else {
            reportProgramError ("CC_DIST_TRAIN");
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
        } else {
            reportProgramError ("CC_DIST_BUS");
        }

    } else if (transportMode == FERRY) {

        if (travelDist == SYDNEY_FERRY_ZONE_1) {
            calculateCostResult = SYDNEY_FERRY_FARE_1;
        } else if (travelDist == SYDNEY_FERRY_ZONE_2) {
            calculateCostResult = SYDNEY_FERRY_FARE_2;
        } else if (travelDist == STOCKTON_FERRY_ZONE) {
            calculateCostResult = STOCKTON_FERRY_FARE;
        } else {
            reportProgramError ("CC_DIST_FERRY");
        }

    } else if (transportMode == LIGHTRAIL) {

        if (travelDist == LIGHTRAIL_ZONE_1) {
            calculateCostResult = LIGHTRAIL_FARE_1;
        } else if (travelDist == LIGHTRAIL_ZONE_2) {
            calculateCostResult = LIGHTRAIL_FARE_2;
        } else {
            reportProgramError ("CC_DIST_LIGHT");
        }

    } else {
        reportProgramError ("CC_TRANS");
    }
    
    return calculateCostResult;
}

float calculateFinalCost (float basicCost, int concessionStatus, int isSunday) {
    //Calculates the user's final fare cost.

    //Normal concession discount test
    if (concessionStatus > NOT_CONCESSION) {
        basicCost = basicCost * CONCESSION_HALF_PRICE;
    }

    //Daily cap test
    if (concessionStatus > NOT_CONCESSION) {

        if (concessionStatus == PENSIONER_CONCESSION) {

            if (basicCost > PENSIONER_DAILY_CAP) {
                basicCost = PENSIONER_DAILY_CAP; //max fare is $2.50, and so on.
            }
        } else {

            if (basicCost > CONCESSION_DAILY_CAP) {
                basicCost = CONCESSION_DAILY_CAP;
            }

        }
    } else {

        if (basicCost > STANDARD_DAILY_CAP) {
            basicCost = STANDARD_DAILY_CAP;
        }
    }

    //Sunday cap test
    if (isSunday == TRUE) {

        if (basicCost > SUNDAY_CAP) {
            basicCost = SUNDAY_CAP;
        }
    }

    return basicCost;
}
