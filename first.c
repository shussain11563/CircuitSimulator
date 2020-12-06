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

void populateBit(int row, int inputVar, int** truthTable)
{
    //int value = row;
    /*
               unsigned short value = ((x >> parameterOne) & 1) ;
            printf("%hu\n", value);

    */
    for(int i = 0; i < row; i++)
    {
        int value = i;
        int counter = inputVar;
        for(int j = 0; j < inputVar; j++)
        {
            truthTable[i][j] 
        }
    }
    //
    

}

//int** arr = NULL;

int main(int argc, char* argv[])
{
    FILE* fp = fopen(argv[1], "r");
    
    char line[100] = "";
    char argument[25] = "";
    int rows = 0;
    int cols = 0;
    int** truthTable = NULL;

    Node* output = NULL;
    Node* tempVar = NULL;

    //fgets(line, 100,fp);
    

    while(fgets(line, 100,fp)!=NULL)
    {
        sscanf(line, "%s", argument);

        //remove this from loop
        if(strcmp(argument, "INPUTVAR")==0)
        {
            //make sure im not mallocing multiple times;
            int inputVariables = 0;
            sscanf(line, "%s %i", argument, &inputVariables);
            rows = exponent(inputVariables);
            cols = inputVariables+1;

            truthTable = malloc(rows*sizeof(int*));
            for(int i = 0; i < rows; i++)
            {
                truthTable[i] = malloc(cols*sizeof(int));
            }

            //change output size???
            //cols = inputVariables+1;

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
