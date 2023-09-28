#include <stdio.h>

int array[] = {2,4,1, 9, 10, 18, 3, 7, 3, 4};
int main(){
    int temp;
    for(int i = 0; i < sizeof(array) / sizeof(int); i++)
    {
        for(int j = 0; j < sizeof(array) / sizeof(int) - i -1; j++)
        {
            if(array[j] > array[j + 1])
            {
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
    for(int i = 0; i < sizeof(array) / sizeof(int); i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}