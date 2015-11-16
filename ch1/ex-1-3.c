#include "stdio.h"

/*
	Print Fahr celsius table for Fahr=0,20,....,300 with headings
*/
main(){
	int step, lower, upper;
	float fahr, celsius;

	lower = 0;
	upper = 300;
	step = 20;

	printf("%6s %6s\n", "Fahr", "Celsius");
	for(fahr = lower; fahr <= upper; fahr += 20){
		celsius = 5.0/9.0 * (fahr - 30.0);
		printf("%6.0f %6.1f\n", fahr, celsius);
	}
}