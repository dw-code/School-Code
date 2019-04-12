/*
CSC 362
Programming Assignment #3

This program simulates the story of the tortoise and the hare. On each turn, the tortoise moves a random number of places between 1-3, while the hare can
move up to 8 places, but has a 1/3 chance of napping, and must stop to eat carrots if landing on a carrot spot. Also, if the hare hits a rock or stream, it must
move back to the last position before it, while the tortoise can keep moving. The simulation continues until one of the animals reaches the finish line, and if they both
end there on the same turn, the animal that moved further wins.

*/


#include <stdio.h> //Printing
#include <stdlib.h> // for rand()
#include <time.h>	// for rand() seed

//Define the current max position either animal can be to 60, which is the length of the path given by the design doc
#define MAX 60

char *moveTortoise(char *tort, char *hare, int *collision) {
	/*
	This function moves the tortoise with the following stipulations
		- The tortoise moves between 1 and 3 places each turn
		- The tortoise can continue through rocks and streams without stopping
		- If landing on the hare, the tortoise moves back 1 place

	*/

	int turn = rand() % 3 + 1; //Pick a number between 1 and 3 to move

	//Test to see if the tortoise lands on the hare
	if (tort + turn == hare) {
		tort = tort + turn - 1; //Move the toroise to the position of the hare, then subtract 1 to get the space behind it
		*collision = 1; //Set the collision flag to true
	}
	else {
		tort = tort + turn; //Move the tortoise the number of positions given
		*collision = 0; //No collision occurred, set to false
	}
	return tort;
}
char *moveHare(char *tort, char *hare, int *collision, int *napping) {
	/*
	This function moves the hare with the following stipulations
		- The hare moves between 1 and 8 places each turn
		- The hare must land on a clear spot, and if landing on a rock or stream must move back to the first clear position before it
		- If landing on the tortoise, the hare moves back 1 place
		- There is a 1 in 3 chance that the hare naps for a turn
		- If the hare hits a carrot patch, it must take a turn to eat the carrot

	*/

	int nap = rand() % 3 + 1; //Roll to see if the hare is napping

	//If the hare is napping (Number between 1 and 3 for a 1/3 chance; set to 1 here), just nap and end the turn
	if (nap == 1) {
		*napping = 1;
		
	}
	//If the hare is not napping, and is not on a carrot patch complete the rest of the turn
	else if (*hare != 'C'){
		*napping = 0;
		int turn = rand() % 8 + 1; //Find the number of positions to move

		hare = hare + turn; //Move the hare to its new position

		//If the hare is on top of the tortoise, move it back 1
		if (hare == tort) {
			hare = hare - 1;
		}

		//Moves the hare back until it is not on a river or stream (doesn't do anything if it's on a valid position)
		while (*(hare + turn) == 'R' || *(hare + turn) == 'S') {
			turn = turn - 1;
		}

	}

	return hare;
}

void print(char *path, char *tort, char *hare, int turn, int collision, int nap) {
	/*
	This function prints the path, including the position of the Tortoise and the Hare
	and also displays any status flags that occurred during the turn
	
	*/
	
	//Grab the beginning of the path, and print the turn heading
	char *currentChar = path;
	printf("Turn %-2d: ", turn);

	//Iterate through the array until it reaches the end (path address + length, which is MAX)
	while (currentChar != path+MAX) {
		
		//Print the hare
		if (currentChar == hare) {
			//Removes the carrot patch if the hare is on top of it
			if (*currentChar == 'C') {
				*currentChar = ' ';
			}
			printf("%c", 'H'); //Print the Hare's position
		}
		//Print the tortoise
		else if (currentChar == tort) {
			printf("%c", 'T');
		}
		//Print the current path item, if it's not either animal
		else {
			printf("%c", *currentChar);
		}
		currentChar += 1;
	}
	//Print a collision flag, if needed
	if(collision) {
		printf("%s", "--collision--");
	}
	//Print a napping flag, if needed 
	if(nap) {
		printf("%s", "--hare napping--");
	}

	printf("\n"); //End the line 

}

void main() {
	char path[] = " R  R  R  SSSSS   R  R CCCC  R   R   CCCCCCCCCC  R  SSSS  R "; //Create the path the tortoise and hare will travel on
	
	char *tort = path; //Set the tortoise (abbreviated as tort, because I can't spell) to point at the beginning of the path 
	char *hare =  path; //Set the hare to point at the beginning of the path 
	int turn = 1; //Start the turn counter at 1
	int collision, napping = 0; //Set the collision and nap flags to false for the first turn

	srand(time(NULL)); 	//Define the random generator

	//Loop through the program logic while the tortoise and hare are still on the path
	//Move the tortoise and the hare, print the path, and increment the turn
	while (tort < path+MAX && hare < path+MAX) {
		tort = moveTortoise(tort, hare, &collision);
		hare = moveHare(tort, hare, &collision, &napping);
		print(path, tort, hare, turn, collision, napping);
		turn++;
	}
	if (tort > hare) {
		printf("%s", "Tortoise Wins!");
	}
	else {
		printf("%s", "Hare Wins!");
	}
	//Hold program before exiting
	getchar();
}
