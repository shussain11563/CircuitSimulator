#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
typedef struct Node
{
    int data;
    int index;
    char varName[50];
    struct Node* next;
} Node;

Node* insert(Node* head, char* name, int data, int index)
{
    Node* insertedNode = (Node*) malloc(sizeof(Node));
    insertedNode ->data = data;
    insertedNode->next = NULL;
    insertedNode->index = index;
    strcpy(insertedNode->varName, name);
    
    if(head==NULL)
    {
        return insertedNode;
    }

    Node* prev = NULL;
    Node* ptr = head;
    while(ptr!=NULL)
    {
        prev = ptr;
        ptr = ptr->next;
        
        if(ptr == NULL)
        {
            prev->next = insertedNode;
            return head;
        }
    }

}

int exponent(int power)
{
    return 1 << power;
}

void freeMemory(Node* head)
{
    Node* prev = NULL;
    Node* ptr = head;
    while(ptr!=NULL)
    {
        prev = ptr;
        ptr = ptr->next;
        free(prev);
    }
}

Node* populateBit(int currRow, int inputVar, Node* inputLL)
{
    Node* ptr = inputLL;
    int counter = inputVar;
    for(int j = 0; j < inputVar; j++)
    {   
        counter--;
        ptr->data = (currRow >> counter) & 1;
        ptr = ptr->next;
    }
    return inputLL;
}

void getValue(int* inputVal, char* inputName,  Node* inputLL, Node* tempLL)
{
    Node* ptr = NULL;
    if(inputName[0] >= 'A' && inputName[0] <= 'Z')
    {
        ptr = inputLL;
    }
    else if(inputName[0] >= 'a' && inputName[0] <= 'z') 
    {
        ptr = tempLL;
    }
    while(ptr!=NULL)
    {
        if(strcmp(ptr->varName, inputName)==0)
        {
            *inputVal = ptr->data;
            return;
        }
        ptr = ptr->next;
    }
    
}
int not(char* currLine, Node* inputLL, Node* tempLL, char* outputName)
{
    char tempCommand[20]; 
    char inputFirst[50]; 
    char output[50];
 
    sscanf(currLine, "%s %s %s", tempCommand, inputFirst, output);
    strcpy(outputName, output);

    int inputFirstVal = 0;
    getValue(&inputFirstVal, inputFirst, inputLL, tempLL);

    int outputVal = 0;
    if(strcmp(tempCommand, "NOT")==0)
    {
        outputVal = !inputFirstVal;
    }
    return outputVal;   
}

int returnOutput(char* currLine, Node* inputLL, Node* tempLL, char* outputName)
{
    char tempCommand[20]; 
    char inputFirst[50]; 
    char inputSec[50];
    char output[50];
 
    sscanf(currLine, "%s %s %s %s", tempCommand, inputFirst, inputSec, output);
    strcpy(outputName, output);

    int inputFirstVal = 0;
    int inputSecVal = 0;

    getValue(&inputFirstVal, inputFirst, inputLL, tempLL);
    getValue(&inputSecVal, inputSec, inputLL, tempLL);

    int outputVal = 0; //change to -1 for debugging

    if(strcmp(tempCommand, "AND")==0)
    {
        outputVal = inputFirstVal & inputSecVal;
    }
    else if(strcmp(tempCommand, "OR")==0)
    {
        outputVal = inputFirstVal | inputSecVal;
    }
    else if(strcmp(tempCommand, "NAND")==0)
    {
        outputVal = !(inputFirstVal & inputSecVal);
    }
    else if(strcmp(tempCommand, "NOR")==0)
    {
        outputVal = !(inputFirstVal | inputSecVal);
    }
    else if(strcmp(tempCommand, "XOR")==0)
    {
        outputVal = inputFirstVal ^ inputSecVal;
    }
    return outputVal;
}

Node* storeOutputLL(char* name, Node* outputLL, int outputVal)
{
    char nameNew[30] = " ";
    strcpy(nameNew, name);
    Node* ptr = outputLL;
    while(ptr!=NULL)
    {
        if(strcmp(nameNew, ptr->varName)==0)
        {
            ptr->data = outputVal;
            return outputLL;
        }
        ptr = ptr->next;
    }
}

Node* parseCreateInput(Node* head, char* line)
{
    char testArgument[25] = ""; 
    char nameNew[100] = " ";
    strcpy(nameNew, line);
    int inputVar = 0;
    char* delimiters = " \n\t\0";
    sscanf(nameNew, "%s %i", testArgument, &inputVar);

    char *token;
    token = strtok(nameNew, delimiters);
    token = strtok(NULL, delimiters);
    
    for(int i =0; i <inputVar; i++)
    {
        char temp[25] = "";
        token = strtok(NULL, delimiters);
        strcpy(temp, token);
        head = insert(head, temp, -1, i);
    }
    return head;
}

void printLL(Node* head)
{
    Node* ptr = head;
    while(ptr!=NULL)
    {
        printf("%d ",ptr->data);
        ptr = ptr->next;
    }
}

int main(int argc, char* argv[])
{
    FILE* fp = fopen(argv[1], "r");

    Node* inputLL = NULL;
    Node* outputLL = NULL;
    Node* tempVarLL = NULL;

    char line[100] = "";
    char argument[30] = "";
    int rows = 0;
    int inputVar = 0;
    int outputVar = 0;

    fgets(line, 100,fp);
    sscanf(line, "%s", argument);
    if(strcmp(argument, "INPUTVAR")==0)
    {
        char testArgument[25] = ""; 
        sscanf(line, "%s %i", testArgument, &inputVar);
        rows = exponent(inputVar);
        inputLL = parseCreateInput(inputLL, line);
    }

    fgets(line, 100,fp);
    sscanf(line, "%s", argument);
    if(strcmp(argument, "OUTPUTVAR")==0)
    {
        char testArgument[25] = ""; 
        sscanf(line, "%s %i", testArgument, &outputVar);
        outputLL = parseCreateInput(outputLL, line);
    }

    for(int currRow = 0; currRow < rows; currRow++)
    {
        rewind(fp);
        inputLL = populateBit(currRow, inputVar,inputLL);

        while(fgets(line, 100,fp)!=NULL)
        {
            sscanf(line, "%s", argument);
            if(strcmp(argument, "INPUTVAR")==0)
            {
                continue;
            }
            else if(strcmp(argument, "OUTPUTVAR")==0)
            {
                continue;
            }
            else if(strcmp(argument, "NOT")==0)
            { 
                char outputName[30] = " ";
                int outputRet = not(line, inputLL, tempVarLL, outputName);
                if(outputName[0] >= 'A' && outputName[0] <= 'Z') 
                {
                    outputLL = storeOutputLL(outputName, outputLL, outputRet);
                }
                else if(outputName[0] >= 'a' && outputName[0] <= 'z') 
                {
                    tempVarLL = insert(tempVarLL, outputName, outputRet, 0);
                }
            }
            else if(strcmp(argument, "OR")==0 || strcmp(argument, "AND")==0 || strcmp(argument, "NAND")==0 || strcmp(argument, "NOR")==0 || strcmp(argument, "XOR")==0)
            {
                char outputName[30] = " ";
                int outputRet = returnOutput(line, inputLL, tempVarLL, outputName);
                if(outputName[0] >= 'A' && outputName[0] <= 'Z') 
                {
                    outputLL = storeOutputLL(outputName, outputLL, outputRet);
                }
                else if(outputName[0] >= 'a' && outputName[0] <= 'z') 
                {
                    tempVarLL = insert(tempVarLL, outputName, outputRet, 0);
                }
            }
        }
        printLL(inputLL);
        printLL(outputLL);
        freeMemory(tempVarLL);
        tempVarLL = NULL;
        printf("\n");
    }
    freeMemory(inputLL);
    freeMemory(outputLL);
    fclose(fp);
}
