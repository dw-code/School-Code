//Dale Wade
//CSC 362
//Programming Assignment #1

//This program takes in a file consisting of a long string, decodes it accordingly:
//	Start looking for an uppercase character
//	if an uppercase character is found, print it (in lower) and start looking for a lowercase letter
//	if a lowercase character is found, print it and start looking for an uppercase letter
//	if a period is found, start looking for an uppercase character, and output it as an uppercase
//	Each character outputted is sent to the output file specified via outFile
//The program counts the number of characters inputted and outputted, then ouputs the number of each
//as well as a percentage reduction in result of the decoding. Also outputted is the input and output
//file name for each run. Statistical information is outputted to the console

#include <stdio.h> //File functions
#include <ctype.h> //Character typing

void main(){
	//Filenames (changed each time to test new file)
	char inFile[] = "input3.txt";
	char outFile[] = "output3.txt";

	//Create the files needed for I/O
	FILE *in, *out; //Creates a pointer for the input file
	in = fopen(inFile, "r"); //Opens the input file in read mode
	out = fopen(outFile, "w"); //Opens the output file in write mode
	
	//Create the variables needed for decoding
	int inChars = 0; //Characters input
	int outChars = 0; //Characters output
	int cCase = 1;  //Current case we're looking for, 0/lower 1/upper
	int foundPeriod = 1; //If we find a period, print the first upper as an upper
	char c;	//Character in file
	
	//Create the variables needed for statistical output
	int inputChar = 0; //Characters inputted
	int outputChar = 0; //Characters outputted

	//Iterate through each character in the file
	while((c=getc(in)) != EOF){
		inputChar += 1; //Count every character
		//If not an alphabetic character, at least print
		if(!isalpha(c)){
			fprintf(out,"%c",c);
			outputChar +=1;
			//If a period, start looking for an upper
			if(c == '.'){
				cCase = 1;
				foundPeriod = 1;
			}
		}

		//Alphabetic character, check for case
		else{
			//If searching for upper
			if(cCase){
				//If found the upper
				if(isupper(c)){
					//Check if it came after a period
					if(foundPeriod){
						//Output to file, count
						fprintf(out,"%c", c);
						outputChar += 1;
						foundPeriod = 0;//Reset period

					}
					else{
						//Ouput to file, count
						fprintf(out,"%c", tolower(c));
						outputChar += 1;
					}
					cCase = 0; //Swap to look for lower
				}
			}
			//If searching for lower
			else{
				if(islower(c)){
					//Output to file, count
					fprintf(out,"%c", c);
					outputChar += 1;
					cCase = 1; //Swap to look for upper case
				}
			}
		}
	
	}
	fclose(in); //Close the input file
	fclose(out); //Close the output file

	float percentChar = ((float)outputChar/inputChar)*100; //Calculate the percentage of shrink

	//Print the statistical output
	printf("%-30s %-5s\n", "Input file: ", inFile);
	printf("%-30s %-5s\n", "Output file: ", outFile);
	printf("%-30s %-5i\n", "Number of input characters: ", inputChar);
	printf("%-30s %-5i\n", "Number of output characters: ", outputChar);
	printf("%-30s %-5.2f%%\n", "Number of input characters: ", percentChar);

}
