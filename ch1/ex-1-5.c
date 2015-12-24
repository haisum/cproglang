/*
Exercise 1-5. Modify the temperature conversion program to print the table in reverse order,
that is, from 300 degrees to 0.
 */
#include "stdio.h"

main(){
	int step, lower, upper;
	float fahr, celsius;

	lower = 0;
	upper = 300;
	step = 20;

	printf("%6s %6s\n", "Fahr", "Celsius");
	for(fahr = upper; fahr >= lower; fahr -= 20){
		celsius = 5.0/9.0 * (fahr - 30.0);
		printf("%6.0f %6.1f\n", fahr, celsius);
	}
}