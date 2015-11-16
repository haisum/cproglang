#include "stdio.h"

main(){
	printf("abc \\b \b \n");
	printf("abc \\a \a \n");
	printf("abc \\v \v \n");
	printf("abc \\r \r \r \n");// \r removes chars from start on windows
	printf("abc\b\b");
}