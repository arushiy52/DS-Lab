// To find the missing element in n-1 integer 1 to n 
// a) Using linear search
// b) Using binary search

# include <iostream>
using namespace std;



int missing_element_linear(int arr[], int len) {
    
    for (int i = 0; i<len-1; i++) {
        if (arr[i+1] - arr[i] != 1) return arr[i]+1;
    }
    return -1;
}


int missing_element_binary(int arr[], int len){
    int low = 0;
    int high = len-2;
    while(low<=high) {
        int mid = (low + high)/2;

        // The second condition is to find the first anomoly ie as soon as it got messed up
        if (arr[mid] != mid+1 && arr[mid-1] == mid) {
            return mid+1;
        }

        if (arr[mid] != mid+1) {
            high = mid -1;
        }

        else low = mid+1;
    }
    return -1;
}




int main()
{
    int array[6] = {1,2,3,5,6};
    int length = 6;

    cout << "Mising element : " << missing_element_linear(array, length) << endl;
   
    cout << "Missing element : " << missing_element_binary(array, length) << endl;

    return 0;
}



    
