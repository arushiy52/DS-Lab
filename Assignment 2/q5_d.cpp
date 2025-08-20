// Upper Triangular Matrix


#include <iostream>
using namespace std;

void upper_triangular(int arr[4][4]) {
    int row = 4;
    int len = row*(row+1)/2;
    int upper[len]; // n(n+1)/2 = 10 for n=4
    int k = 0;

    for (int i = 0; i < row; i++) {
        for (int j = i; j < 4; j++) {
            upper[k++] = arr[i][j];
        }
    }

    for (int i = 0; i < k; i++) cout << upper[i] << " ";
    cout << endl;
}

int main() {
    int arr[4][4] = {
        {1, 2, 3, 4},
        {0, 5, 6, 7},
        {0, 0, 8, 9},
        {0, 0, 0, 10}
    };
    upper_triangular(arr);
}
