/*
	Dale Wade
	CSC 362
	Programming Assignment #2

	This file handles all the I/O functions for the program
*/

#include "Functions.h"


int inputFile(FILE *fp1, char *city, int *pop, int *sqmiles, int *pollution, int *crime, int *expense, int *highways) {
	//Takes in the file name, and pulls the information of one city
	return fscanf(fp1, "%s %d %d %d %d %d %d", city, pop, sqmiles, pollution, crime, expense, highways);
}

void outputCity(char *city, double popDensity, double livability) {
	//Prints a row of output for a given city, including its population density and livability
	printf("%-20.15s %.2f %30.2f\n", city, popDensity, livability);
}

void outputBestCity(char *bestCity, double bestLivability, int numCities) {
	//Outputs the best city,with its score and also includes the number of cities
	printf("\nOf the %d cities, the most liveable was %s with a score of %.2f", numCities, bestCity, bestLivability);
}
void outputHead() {
	//Prints out the header of the statistical data
	printf("%s%30s%30s\n", "City", "Population Dens", "Livability Score");
}