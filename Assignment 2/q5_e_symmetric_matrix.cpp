// Symmetric Matrix


#include <iostream>
using namespace std;

void symmetric(int arr[4][4]) {
    int row = 4;
    int len = row*(row+1)/2;
    int sym[10];
    int k = 0;

    for (int i = 0; i < row; i++) {
        for (int j = 0; j <= i; j++) {
            sym[k++] = arr[i][j];
        }
    }

    for (int i = 0; i < k; i++) cout << sym[i] << " ";
    cout << endl;
}

int main() {
    int arr[4][4] = {
        {1, 2, 3, 4},
        {2, 5, 6, 7},
        {3, 6, 8, 9},
        {4, 7, 9, 10}
    };
    symmetric(arr);
}
