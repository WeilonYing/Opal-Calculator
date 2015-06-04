/*
 * FILE NAME: opalCalcDefinitions
 * NAME: Opal Calculator Program
 * BY: Weilon Ying
 * DATE: started on 19th April 2015
 * DESCRIPTION: Holds #define definitions.
 *
 * DISCLAIMER: Opal Card and its associated trademarks are intellectual 
 *  property of Transport for NSW and its subsidiaries such as 
 *  Sydney Trains, Ferries and Buses. The author does not claim any 
 *  responsibility for mistakes in the calculation of the 
 *  journey fare (please don't sue me D:).
 * 
 * All fares have been obtained from https://www.opal.com.au/en/fares-and-benefits/
 * as of 19th April 2015.
 */

#define TRUE 1
#define FALSE 0

#define NOT_CONCESSION 0
#define CHILD_STUDENT_CONCESSION 1
#define PENSIONER_CONCESSION 2

#define OFF_PEAK_DISCOUNT 0.7;
#define CONCESSION_HALF_PRICE 0.5

#define STANDARD_DAILY_CAP 15.00
#define CONCESSION_DAILY_CAP 7.50
#define PENSIONER_DAILY_CAP 2.50
#define SUNDAY_CAP 2.50

#define TRAIN 1
#define BUS 2
#define FERRY 3
#define LIGHTRAIL 4

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
#define STOCKTON_FERRY_ZONE 3
#define SYDNEY_FERRY_FARE_1 5.74
#define SYDNEY_FERRY_FARE_2 7.18
#define STOCKTON_FERRY_FARE 2.10

#define LIGHTRAIL_ZONE_1 1
#define LIGHTRAIL_ZONE_2 2
#define LIGHTRAIL_FARE_1 2.10
#define LIGHTRAIL_FARE_2 3.50

#define NO_INPUT -1 //If there is no input yet, set to -1 first.
#define MAX_TRIPS 3 //Maximum trips per journey is 3.