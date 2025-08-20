// Storing tri-diagonal matrix

#include <iostream>
using namespace std;

void tri_diagonal(int arr[4][4]) {
    int row = 4;
    int tri[3*row-2]; 
    int k = 0;

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (i == j || i == j+1 || i+1 == j) {
                tri[k++] = arr[i][j];
            }
        }
    }

    
    for (int i = 0; i < k; i++) cout << tri[i] << " ";
    cout << endl;
}

int main() {
    int arr[4][4] = {
        {1, 2, 0, 0},
        {3, 4, 5, 0},
        {0, 6, 7, 8},
        {0, 0, 9, 10}
    };
    tri_diagonal(arr);
}
