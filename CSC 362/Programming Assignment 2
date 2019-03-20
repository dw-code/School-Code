#include "Functions.h"
/*
	Dale Wade
	CSC 362
	Programming Assignment #2

	This file is the main driver for the program, handling all of the operational logic for the program, and connecting the I/O with different compute functions
*/

void main() {
	//Main function running the program


	//Required variables for the city calculations
	char city[20], bestCity[20];
	int pop, sqmiles, pollution, crime, expense, highways;
	double popDensity, liv, bestLivability, totalLivability;
	FILE *fp1;

	//Sets numCities to zero, so it can be incremented
	int numCities = 0;

	//Open the file
	fp1 = fopen("Cities2.txt", "r");

	//Output the header
	outputHead();

	//Iterate through each city, get its population density and livability, and determine whether or not its the best city
	while(inputFile(fp1, &city, &pop, &sqmiles, &pollution, &crime, &expense, &highways) != EOF) {
		
		popDensity = populationDensity(pop, sqmiles); //Population density
		computeStatistics(pollution,  crime, expense, popDensity, highways, &liv); //Livabilty score
		update(&numCities, &totalLivability, liv, city, bestCity, &bestLivability); //Update the current best city
		outputCity(&city, popDensity, liv); //Output the city
	}

	//Output the best city
	outputBestCity(&bestCity, bestLivability, numCities);
	
	//Hold program before exiting
	getchar();

}
