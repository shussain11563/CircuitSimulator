#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int exponent(int power)
{
    return 1 << power;
}

void populateBit(int row, int inputVar)
{

    for(int i = 0; i < row; i++)
    {
        int value = i;
        int counter = inputVar;
        printf("Value: %d -> ", value);
        for(int j = 0; j < inputVar; j++)
        {   
            counter--;
            int q = (value >> counter) & 1;
            printf("%d ", q);
            //counter--;
        }
        printf("\n");
    }
    

}


int main(int argc, char* argv[])
{
    populateBit(8, 3);
}
