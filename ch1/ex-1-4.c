#include "stdio.h"

main(){
	int step, lower, upper;
	float celsius, fahr;

	step = 20;
	lower = 0;
	upper = 300;

	printf("%8s %8s \n", "Celsius", "Fahrenheit");
	for(celsius = 0; celsius <= upper; celsius += 20){
		fahr = celsius * (9.0/5.0) + 32;
		printf("%8.0f %8.1f \n", celsius, fahr);
	}
}