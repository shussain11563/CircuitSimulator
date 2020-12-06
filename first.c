#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node
{
    int data;
    char varName[50];
    struct Node* next;

} Node;

Node* insert(Node* head, char* name, int data)
{
    Node* insertedNode = (Node*) malloc(sizeof(Node));
    insertedNode ->data = data;
    insertedNode->next = NULL;
    strcpy(insertedNode->varName, name);
    
    if(head==NULL)
    {
        return insertedNode;
    }

    Node* ptr = head;
    while(ptr!=NULL)
    {
        ptr = ptr->next;
        
        if(ptr == NULL)
        {
            ptr->next = insertedNode;
            return head;
        }
    }

}

int exponent(int power)
{
    return 1 << power;
}

void populateBit(int row, int inputVar, int** arr)
{
    for(int i = 0; i < row; i++)
    {
        int value = i;
        int counter = inputVar;
        for(int j = 0; j < inputVar; j++)
        {   
            counter--;
            arr[i][j] = (value >> counter) & 1;
        }
    }
}

void not(char* currLine, )
{
    char tempCommand[20]; 
    char inputFirst[50]; 
    char output[50];
    sscanf(currLine, "%s %s %s", tempCommand, inputFirst,  output);
}

void functions(char* currLine)
{
    char tempCommand[20]; 
    char inputFirst[50]; 
    char inputSec[50];
    char output[50];
    //int x = 0;
    //int y = 0;
    sscanf(currLine, "%s %s %s %s", tempCommand, inputFirst, inputSec, output);

    int inputFirstVal = 0;
    int inputSecVal = 0;

    if(strcmp(argument, "INPUTVAR")==0)
    {
        if(strcmp(argument, "AND")==0)
        {

        }
        else if(strcmp(argument, "OR")==0)
        {
            
        }
        else if(strcmp(argument, "NAND")==0)
        {
            
        }
        else if(strcmp(argument, "NOR")==0)
        {
            
        }
        else if(strcmp(argument, "XOR")==0)
        {
            
        }
    }

}

//int** arr = NULL;

int main(int argc, char* argv[])
{
    FILE* fp = fopen(argv[1], "r");

    Node* output = NULL;
    Node* tempVar = NULL;

    char line[100] = "";
    char argument[25] = "";
    int rows = 0;
    int cols = 0;
    int** truthTable = NULL;
    int inputVar = 0;
    int outputVar = 0;

    fgets(line, 100,fp);
    if(strcmp(argument, "INPUTVAR")==0)
    {
       
        char testArgument[25] = ""; 
        sscanf(line, "%s %i", testArgument, &inputVar);
        rows = exponent(inputVar);
    }

    fgets(line, 100,fp);
    if(strcmp(argument, "OUTPUTVAR")==0)
    {
        char testArgument[25] = ""; 
        sscanf(line, "%s %i", testArgument, &outputVar);
        cols = inputVar+outputVar;

        truthTable = malloc(rows*sizeof(int*));
        for(int i = 0; i < rows; i++)
        {
            truthTable[i] = malloc(cols*sizeof(int));
        }
    }

    //
    
    while(fgets(line, 100,fp)!=NULL)
    {
        sscanf(line, "%s", argument);

        //remove this from loop
        if(strcmp(argument, "INPUTVAR")==0)
        {

        }
        else if(strcmp(argument, "OUTPUTVAR")==0)
        {
            
        }
        else if(strcmp())
        {

        }

        printf("%s \n", argument);
    }
}
