// Converting a normal matrix to sparse matrix
// Matrices whose majority elements are 0 can be wxpressed as sparse matrix, to save memory

# include <iostream>
using namespace std;


int count_non_zeroes(int arr[4][4]) {
    int non_zeroes = 0;
    for (int i=0; i<4; i++) {
        for (int j=0; j<4; j++) {
            if (arr[i][j] != 0) non_zeroes++;
        }
    }
    return non_zeroes;
}



void convert_to_sparse(int arr[4][4]) {
    int non_zeroes = count_non_zeroes(arr);
    int row = non_zeroes, col = 3;
    int sparse[row][col];
    int k = 0;

    // Creating sparse matrix
    for (int i = 0; i<4; i++) {
        for (int j = 0; j<4; j++) {
            if (arr[i][j] != 0) {
                sparse[k][0] = i;
                sparse[k][1] = j;
                sparse[k][2] = arr[i][j];
                k++;
            }
        }
    }

    // Printing sparse matrix
    cout << "Row Col Value" << endl;
    for (int i = 0; i<row; i++) {
        for (int j = 0; j<col; j++) {
            cout << sparse[i][j] << "    ";
        }
        cout << endl;
    }
}



int main()
{
    int arr[4][4] = {
        {5, 0, 0, 0} , 
        {0, 0, 1, 6} ,
        {0, -1, 0, 0} ,
        {2, 0, 0, 0}
    };
    convert_to_sparse(arr);
}