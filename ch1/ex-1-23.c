/*
Exercise 1-23. Write a program to remove all comments from a C program. Don't forget to
handle quoted strings and character constants properly. C comments don't nest.
 */

/*
Conditions:

quote start if:
    quote is not started
	" charachter is encountered
	multi comment is not started
	single comment is not started
	it's not inside char literal: either '"' or '\"'

quote end if:
	" quote is encountered
	quote was started
	quote isn't preceeded by escape char \

multi comment start if:
    multi comment was not started
	quote was not started
	single comment was not started
	/ character is encountered
	* charachter is encountered after /

multi comment end if:
	multi comment was started
	* character is encountered
	/ chacter is encountered after *

single comment start if
	quote was not started
	multi comment was not started
	single comment was not started
	/ character is encountered
	/ character is encountered
	/ charachter is encountered after /

single comment end if
	single comment was started
	newline was encountered

echo if
	single comment is not started
	multi comment is not started
*/
#include "stdio.h"
#define MAX 5
#define STARTED 1
#define ENDED 0

void recordPrev(char prev[], char c);

int main(){
    int quote, scomment, mcomment;
    char c, prev[3], next;
    prev[0], next = '\0';

    c = getchar();
    do{
        next = getchar();
        /*
        quote start if:
        quote is not started
        " charachter is encountered
        multi comment is not started
        single comment is not started
        it's not inside char literal: either '"' or '\"'
        */
        if(quote != STARTED && scomment != STARTED && mcomment != STARTED &&
         c == '"' && (prev[0] != '\'' || (prev[0] != '\\' && prev[1] != '\'')) && next != '\'' ){
            quote = STARTED;
        }
        /*
        quote end if:
        " quote is encountered
        quote was started
        quote isn't preceeded by escape char \
        */
        else if (quote == STARTED && c == '"' && prev[0] != '\\'){
            quote = ENDED;
        }
        /*
        multi comment start if:
        multi comment was not started
        quote was not started
        single comment was not started
        / character is encountered
        * charachter is encountered after /
        */
        else if (c == '/' && next == '*' && quote != STARTED && mcomment != STARTED && scomment != STARTED){
            mcomment = STARTED;
        }
        /*
        single comment start if
        quote was not started
        multi comment was not started
        single comment was not started
        / character is encountered
        / charachter is encountered after /
        */
        else if (c == '/' && next == '/' && mcomment != STARTED && scomment != STARTED && quote != STARTED){
            scomment = STARTED;
        }
        /*
        multi comment end if:
        multi comment was started
        * character is encountered
        / chacter is encountered after *
        */
        else if ( mcomment == STARTED && prev[0] == '/' && prev[1] == '*'){
            mcomment = ENDED;
        }
        /*
        single comment end if
        single comment was started
        newline was encountered
        */
        else if (scomment == STARTED && c == '\n'){
            scomment = ENDED;
        }
        if(scomment != STARTED && mcomment != STARTED && c != EOF){
            putchar(c);
        }
        recordPrev(prev, c);
        c = next;
    }while( c!=EOF );
    return 0;
}

void recordPrev(char prev[], char c){
     if( c != EOF ){
        if(prev[0] == '\0'){
            prev[0] = c;
            prev[1] = '\0';
        }
        else {
            prev[1] = prev[0];
            prev[0] = c;
            prev[2] = '\0';
        }
    }
    else {
        prev[0] = '\0';
    }
}
