// Count Number of inversions in an array
// ie counting how many times an element is smaller than its previous one


#include <iostream>
using namespace std;


int count_inversions(int A[], int len) {
    int inv = 0;
    for(int i = 0; i < len-1; i++) {
        for(int j = i + 1; j < len; j++) {
            if(A[i] > A[j])
                inv++;
        }
    }
    return inv;
}

int main() {
    int len;
    cout << "Enter length : ";
    cin >> len;

    int A[len];
    cout << "Enter elements: ";
    for(int i = 0; i < len; i++)
        cin >> A[i];

    int inversions = count_inversions(A, len);
    cout << "Number of inversions : " << inversions << endl;

    return 0;
}
