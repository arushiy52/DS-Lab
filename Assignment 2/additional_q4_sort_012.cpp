// Sort an array containing only 0's, 1's and 2's

# include <iostream>
using namespace std;


void print_array(int *arr, int len) {
    for (int i=0; i<len; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}


// Counting no of 0's, 1's and 2's, and then putting them in place
// Time complexity -> O(2n)
// Space Complexity -> O(1)
void sort_012_m1(int *arr, int len) {

    int count0=0, count1=0, count2=0;

    for (int i=0; i<len; i++) {
        if (arr[i] == 0 || arr[i] == 1 || arr[i] == 2) {
            if (arr[i] == 0) count0 += 1;
            if (arr[i] == 1) count1 += 1;
            if (arr[i] == 2) count2 += 1;
        }
        else {
            cout << "Array should contain only zero's and one's" << endl;
            return;
        }
    }
    //cout << count0 << " " << count1 << " " << count2 << " " << endl;

    int i = 0;
    while (i<count0) {
        arr[i] = 0;
        i++;
    }
    while (i<count1+count0) {
        arr[i] = 1;
        i++;
    }
    while (i<count2+count1+count0) {
        arr[i] = 2;
        i++;
    }

    print_array(arr,len);

}



// Dutch National Flag Algorithm
// Time Complexity -> O(n)
// Space Complexity -> O(1)
void sort_012_m2(int *arr, int len) {
    
    // zero points to where the next should be placed. In the end, it will point to the first one.
    int zero = 0;
    // Two points to where the next two should be placed. In the end, it will point to the last one.
    int two = len-1;
    int check = 0;  // Points to the element being currently checked

    while (check<=two) {
        if (arr[check] == 0) {
            swap(arr[check], arr[zero]);
            zero++;
            check++;
        }
        else if (arr[check] == 1) {
            check++;
        }
        else if (arr[check] == 2) {
            swap(arr[check], arr[two]);
            two--;
        }
        else {
            cout << "Array should contain only zero's and one's" << endl;
            return;
        }

    }
    print_array(arr,len);
    // cout << zero << " " << two;
}





int main() 
{
    const int len = 10;
    int arr[len] = {1,0,1,5,0,2,1,1,0,2};
    cout << "Array : ";   print_array(arr,len);

    sort_012_m1(arr,len);
    sort_012_m2(arr,len);
    
}
