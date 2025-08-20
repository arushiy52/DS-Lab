// Efficient way to store diagonal matrix
// A 2-D diagonal matrix can be stored as a 1-D array having the diagonal values as the only elements
// Ignoring the apparent zeroes saves memory
// The 1-D array can be converted back to the original 2-D array if and when required


# include <iostream>
using namespace std;



void Diagonal(int arr[4][4]) {
    int diag[4];              // 1-D array to stores the diagonal elements
    for (int i=0; i<4; i++) {
        diag[i] = arr[i][i];
    }

    // Printing the 1-D array
    for (int i=0; i<4; i++) {
        cout << diag[i] << "    ";
    }
    cout << endl;
}




int main()
{
    int arr[4][4] = {
        {5, 0, 0, 0} , 
        {0, 1, 0, 0} ,
        {0, 0, -2, 0} ,
        {0, 0, 0, 6}
    };
    Diagonal(arr);
}