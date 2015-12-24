/*
Exercise 1-24. Write a program to check a C program for rudimentary syntax errors like
unmatched parentheses, brackets and braces. Don't forget about quotes, both single and
double, escape sequences, and comments. (This program is hard if you do it in full generality.)
 */
#include "stdio.h"
#define MAX 5
#define MAXBRACKETS 100
#define STARTED 1
#define ENDED 0

void recordPrev(char prev[], char c);

int isOpeningBracket(char c);
int isClosingBracket(char c);
char bracketStack[MAXBRACKETS];//this should be struct but we haven't been taught structs in book yet.
int bracketCharPositionStack[MAXBRACKETS];
int bracketLineNumberStack[MAXBRACKETS];
int stackLength = 0;
char getLastBracket();
int getLastBracketCharPosition();
int getLastBracketLineNumber();
void popLastBracket();
int saveBracket(char c, int charPosition, int lineNumber);

int main(){
    int quote, scomment, mcomment, charPosition = 1, lineNumber = 1;
    char c, prev[3], next;
    prev[0] = next = '\0';

    c = getchar();
    do{
        next = getchar();
        if(c == '\n'){
            ++lineNumber;
            charPosition = 1;
        } else {
            ++charPosition;
        }
        if(quote != STARTED && scomment != STARTED && mcomment != STARTED &&
         c == '"' && (prev[0] != '\'' || (prev[0] != '\\' && prev[1] != '\'')) && next != '\'' ){
            quote = STARTED;
        }
        else if (quote == STARTED && c == '"' && prev[0] != '\\'){
            quote = ENDED;
        }
        else if (c == '/' && next == '*' && quote != STARTED && mcomment != STARTED && scomment != STARTED){
            mcomment = STARTED;
        }
        else if (c == '/' && next == '/' && mcomment != STARTED && scomment != STARTED && quote != STARTED){
            scomment = STARTED;
        }
        else if ( mcomment == STARTED && prev[0] == '/' && prev[1] == '*'){
            mcomment = ENDED;
        }
        else if (scomment == STARTED && c == '\n'){
            scomment = ENDED;
        }
        if(scomment != STARTED && mcomment != STARTED && c != EOF){
            if(isOpeningBracket(c)){
                if(!saveBracket(c, charPosition, lineNumber)){
                    printf("Error in saving bracket. This program doesn't support checking for more than %d bracket pairs.", MAXBRACKETS);
                }
            } else if (isClosingBracket(c)){
                if((c == ')' && getLastBracket() == '(') ||
                    (c == ']' && getLastBracket() == '[') ||
                    (c == '}' && getLastBracket() == '{')){
                    popLastBracket();
                } else {
                    if(getLastBracket() != '\0'){
                        printf("Bracket mismatched. Expected closing for bracket %c opened at line %d on position %d,"\
                        " instead got %c on line %d at position %d", getLastBracket(), getLastBracketLineNumber(), getLastBracketCharPosition(), c, lineNumber, charPosition);
                    } else {
                        printf("Unexpected closing bracket %c with no matching opening brace at line %d position %d", c, lineNumber, charPosition);
                    }
                    return 1;
                }
            }
        }
        recordPrev(prev, c);
        c = next;
    }while( c!=EOF );

    if(getLastBracket() != '\0'){
        printf("Expected matching bracket for %c from line %d and position %c instead found end of file.\n", getLastBracket(), getLastBracketLineNumber(), getLastBracketCharPosition());
        return 1;
    } else {
        printf("Program didn't have any missing brackets.\n");
        return 0;
    }
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


char getLastBracket(){
    if(stackLength >= 1){
        return bracketStack[stackLength-1];
    }
    else {
        return '\0';
    }
}
int getLastBracketCharPosition(){
    if(stackLength >= 1){
        return bracketCharPositionStack[stackLength-1];
    }
    else {
        return 0;
    }
}
int getLastBracketLineNumber(){
    if(stackLength >= 1){
        return bracketLineNumberStack[stackLength-1];
    }
    else {
        return 0;
    }
}
void popLastBracket(){
    if(stackLength >= 1){
        bracketStack[stackLength-1] = '\0';
        --stackLength;
    }
}
int saveBracket(char c, int charPosition, int lineNumber){
    if(stackLength < MAXBRACKETS && stackLength >= 0){
        bracketStack[stackLength] = c;
        bracketLineNumberStack[stackLength] = lineNumber;
        bracketCharPositionStack[stackLength] = charPosition;
        ++stackLength;
        return 1;
    }
    else {
        return 0;
    }
}
int isOpeningBracket(char c){
    if( c == '(' || c == '{' || c == '[')
        return 1;
    return 0;
}
int isClosingBracket(char c){
    if( c == ')' ||  c == '}' || c == ']')
        return 1;
    return 0;
}
