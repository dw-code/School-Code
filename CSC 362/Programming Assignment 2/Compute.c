/*
	Dale Wade
	CSC 362
	Programming Assignment #2

	This file contains all the nessecary computation functions for ranking of the cities given by the input, including the population density, traffic ratingt, crime per capita, expense per capita, and livability
*/

#include "Functions.h"

double populationDensity(int population, int sqmiles) {
	//Computes the population density of a city
	//Equation: population / square mileage 
	return ((double)population) / sqmiles;
}

void computeStatistics(int pollution, int crime, int expense, double populationDensity, int highways, double *liv) {
	/*
	Takes in the raw data for a city, and computes the statistical information for each variable, as well as the livability score for the city

	Formulas:

	Population density = population / square mileage.
	Pollution = pollution amount * population density / 1000
	Traffic rating = population density * 1.7 / major highways
	Crime per capita = crime * population density / 872.6
	Expense per capita = expense * population density / 1217.1
	Livability = 100 – (Pollution + Traffic rating + Crime per capita + Expense per capita) /13.81

	*/

	//Computes intermediary values as doubles, to prevent loss of precision in livability score calculation
	double poll = pollution * populationDensity / 1000;
	double traff = populationDensity * TRAFFIC_CONSTANT / highways;
	double cr = crime * populationDensity / CRIME_CONSTANT;
	double exp = expense * populationDensity / EXPENSE_CONSTANT;
	//Compute the final livability score
	*liv = 100 - (poll + traff + cr + exp) / LIVABILITY_CONSTANT;
	

}

void update(int *numCities, double *totalLivability, double livability, char *city, char *bestCity, double *bestLivability) {
	//Updates the overall statistics for the current run, and determines whether or not the current city is the best city
	*numCities += 1; //Increment the number of cities
	*totalLivability += livability;

	//Determine whether or not the best city needs to be updated
	if (livability > *bestLivability) {
		*bestLivability = livability;
		strcpy(bestCity, city);
	}

}