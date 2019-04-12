
#include <stdio.h>

void main() {
	/*
	This program computes how perfect a number is. A number is perfect if the sum of it's numbers add up to the number itself. For example 6 is a perfect number, because its factors 2 and 3 add up to 6. Only a handful of numbers are perfect, so we will calculate how close
	a number is to being perfect, where the formula is abs[(sum-number)] / number. So, a number like 12 (sum 16) would have a perfectness of abs[4] / 12, or 33%. This implementation is written in c, where the number is given, it's factors are computed and summed, then the closeness
	of the number to being perfect is outputted, along with its sum of factors. If a number is a perfect number, it will print out 0%, as it is 0% of a perfect number (a complete match)
	*/
	int input; //Variable for input

	//Grabs the number to be tested
	printf("Enter the number to be tested: ");
	scanf("%d", &input);

	while (input > 1) {
		int result = 0, sum = 0, two, oneHundred; //Initialize the sum and result; //Need to create 2 as a variable to divide by
		
		__asm {

					//Resets the result and sum to 0
					mov result, 0
					mov sum, 0

					//Creates the numbers 2 and 100 as variables for later division and multiplication (immediate referencing is now allowed)
					mov two, 2
					mov oneHundred, 100

					//Computes where the loop will stop factors, which is half of the input value
					mov eax, input
					div two //Divide by 2 to get the stop point of the function (factors mirror after n/2)
					mov ecx, eax //Moves the halved value into the loop counter

					//Loop Control
		top:		cmp ecx, 0 //Check to see if the loop variable is zero
					je closeness //If they're equal, end the program
				
					//Check for a factor
					mov eax, input //Move the input value to the acc
					mov edx, 0 //Clear the edx
					div ecx //Divide by the loop variable
					cmp edx, 0 //If no remainder, the value is a factor
					je factor //Jump to factor handling
					jmp preloop //If not a factor, just do the preloop
					
					//If there is a factor, add it to the sum
		factor:		mov eax, ecx //Move the loop variable to the accumulator
					add eax, sum //Add the sum to the loop variable
					mov sum, eax //Move the result as the new sum
					jmp preloop //Move to the preloop

					//Prepare for the next loop
		preloop:	dec ecx //Decrement the loop variable
					jmp top //Jump to the top

					//Calculate the closeness
		closeness:	mov eax, sum //Move the sum to the accumulator for subtraction
					sub eax, input //Subtract the number from the sum
					cmp eax, 0 //Check if the result is negative
					jge fin //If not, jump to the end of the calculation
					neg eax //If so, negate the result

		fin:		mul oneHundred //Multiply by 100 for division
					mov edx, 0 //Clear the edx
					div input //Divide by the number
					mov result, eax //Store the result
		end: nop		

		}
		//Print the result
		printf("Result is: %d%%\n", result);
		printf("Sum is: %d\n", sum);
		
		//Grab the next number
		printf("Enter the next number: ");
		scanf("%d", &input);
	}
	//Holds the console open to see ouput
	getchar();

}