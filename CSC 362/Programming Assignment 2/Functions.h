/*
	Dale Wade
	CSC 362
	Programming Assignment #2

	This file contains function prototypes, constants, and includes used in the program 
*/

//Include statments
#include <stdio.h>
#include <string.h> //Only used to change the value of bestCity with the strcpy() function


//Constants for all the calculations in Compute.c, per program instructions
#define TRAFFIC_CONSTANT  1.7
#define CRIME_CONSTANT  872.6
#define EXPENSE_CONSTANT  1217.1
#define LIVABILITY_CONSTANT 13.81


//Function prototypes
double populationDensity(int population, int squareMiles); //Given a population and square mileage, compute the compuation density
void computeStatistics(int *pollution, int crime, int expense, double populationDensity, int highways, double *liv); //Given the raw data of a city, compute the statistics for each variable, and the livability
void update(int *numCities, double *totalLivability, double livability, char city, char *bestCity, double *bestLivability); //Update the overall statistics of the current city, and determine the current best city
int inputFile(FILE *fp1, char city, int *pop, int *sqmiles, int *pollution, int *crime, int *expense, int *highways); //Takes in a file, and grabs the pertinent information from a single line (population, city name, etc.)
void outputCity(char *city, double popDensity, double liv); //Outputs the name of the current city and its population density and livability score
void outputBestCity(char *bestCity, double bestLivability, int numCities); //Outputs the best city
void outputHead(); //Outputs the header for statistical info