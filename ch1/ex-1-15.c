#include "stdio.h"

int fahrCelTable(int lower, int upper, int step){
	float fahr, celsius;
	printf("%6s %6s\n", "Fahr", "Celsius");
	for(fahr = lower; fahr <= upper; fahr += 20){
		celsius = 5.0/9.0 * (fahr - 30.0);
		printf("%6.0f %6.1f\n", fahr, celsius);
	}
}

main(){
	int step, lower, upper;
	lower = 0;
	upper = 300;
	step = 20;
	fahrCelTable(lower, upper, step);
}