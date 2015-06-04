/*
 * FILE NAME: opalCalcStandardFunctions
 * NAME: Opal Calculator Program
 * BY: Weilon Ying
 * DATE: started on 19th April
 * DESCRIPTION: Holds standard functions that may 
 *   be used in other programs.
 */

int getInput (int minimum, int maximum);
void reportProgramError (char *errorCode);

int getInput (int minimum, int maximum) { 
	//gets integer input from user between a certain range
	int input;
	scanf ("%d", &input);

	while ((input < minimum) || (input > maximum)) {
		printf ("You entered an invalid number. Please enter a number "
			"between %d and %d.\n\n", minimum, maximum);
		scanf ("%d", &input);
	}

	return input;
}

void reportProgramError (char *errorCode) {
	printf ("An error has occurred and the program will need to shut down. \n"
		"Please report the sequence of numbers you have entered and the \n"
		"following error code to the developer: %s\n\n",
		 errorCode);
	assert (0 == 1); //Deliberately stop the program
}
