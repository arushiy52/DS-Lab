// To implement binary search
// Time Complexity = O log(n)

# include <iostream>
using namespace std;
# define length(arr) sizeof(arr)/sizeof(arr[0])

int binary_search(int arr[], int, int);


int main() 
{
    int arr[] = {1,2,3,4,5,6,7,8,9,10};
    int length = length(arr);
    int key;
    cout << "Enter element to find : " ;
    cin >> key;
    int pos = binary_search(arr, length, key);
    
    if (pos != -1) cout << "Found at position " << pos << endl;
    else cout << "Not found";
}


int binary_search(int arr[], int len, int key) {
    
    int low = 0;
    int high = len-1;
    

    while (low <= high) {
        int mid = (high + low)/2;

        if (key == arr[mid]) return mid;

        if (key < arr[mid]) high = mid-1;

        else low = mid+1;

    }

    return -1;
}