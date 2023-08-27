#include <iostream>
#include "vector"

using namespace std;

void bubbleSort(vector<int>* origin) {
    int temp = 0;
    for(int i = 0; i < origin->size(); i++) {
        for(int j = 0; j < origin->size() - i - 1; j++)
        {
            if (origin->at(j) > origin->at(j + 1))
            {
                temp = origin->at(j);
                origin->at(j) = origin->at(j + 1);
                origin->at(j+1) = temp;
            }
        }
    }
}

int main() {

    vector<int> array = {9, 2, 8, 3, 1, 5};
    bubbleSort(&array);

    for(int i = 0; i < array.size(); i++){
        cout << array[i] << " ";
    }

    return 0;
}
