#include <stdio.h>
#define ARRAY_MAX_SIZE 100

int main(){
    // input array by console
    int array[ARRAY_MAX_SIZE];
    char input[ARRAY_MAX_SIZE * 2];
    int size = 0;
    int temp;
    while(1)
    {
        scanf("%d", &array[size]);
        size++;
        char c = getchar();
        if(c == '\n')
        {
            break;
        }
    }

    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size  - i -1; j++)
        {
            if(array[j] > array[j + 1])
            {
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
    for(int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}