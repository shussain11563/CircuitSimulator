#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int exponent(int power)
{
    return 1 << power;
}

void populateBit(int currRow, int inputVar)
{
    int value = currRow;
    int counter = inputVar;
    for(int j = 0; j < inputVar; j++)
    {   
        counter--;
        int q = (value >> counter) & 1;
        printf("%i ", q);
    }
    printf("\n");
}

//output variable
//int isTempVariable()
void output(char* name)
{
    char c = name[0];
    if(c >= 'A' && c <= 'Z') 
    {
        printf("OUTPUT VARIABLE \n");
    }
    else if(c >= 'a' && c <= 'z') 
    {
        printf("temp variable \n");
    }
    //else if nummber
    //else special character like null character, end program/break program
    //else if()

}

void parseInput(char* name)
{
    char testArgument[25] = ""; 
    char nameNew[100];
    //char* delimiters = " \n\t\0";
    strcpy(nameNew, name);
    int inputVar = 0;
    sscanf(name, "%s %i", testArgument, &inputVar);
    char* delimiters = " \n\t\0";
    char *token;
    token = strtok(nameNew, delimiters);
    token = strtok(NULL, delimiters);

    int i = 0;
    for(int i =0; i <inputVar; i++)
    {
        token = strtok(NULL, delimiters);
        printf( "%s\n", token );
    }
}


int main(int argc, char* argv[])
{
    //populateBit(7, 3);
    char name[100] =  "INPUTVAR 3 IN1 IN2 IN3";
    parseInput(name);
}
