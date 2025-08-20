// Lower Triangular Matrix


#include <iostream>
using namespace std;

void lower_triangular(int arr[4][4]) {
    int row = 4;
    int length = row*(row+1)/2;
    int lower[length];
    int k = 0;

    for (int i = 0; i < row; i++) {
        for (int j = 0; j <= i; j++) {
            lower[k++] = arr[i][j];
        }
    }

    for (int i = 0; i < k; i++) cout << lower[i] << " ";
    cout << endl;
}

int main() {
    int arr[4][4] = {
        {1, 0, 0, 0},
        {2, 3, 0, 0},
        {4, 5, 6, 0},
        {7, 8, 9, 10}
    };
    lower_triangular(arr);
}
