#include "stdio.h"

main(){
	double blanks, tabs, newlines;
	blanks = tabs = newlines = 0;
	char c;
	while((c = getchar()) != EOF){
		if(c == ' ')
			++blanks;
		else if (c == '\t')
			++tabs;
		else if (c == '\n')
			++newlines;
	}
	printf("Blanks: %.0f tabs: %.0f newlines: %.0f \n", blanks, tabs, newlines);
}