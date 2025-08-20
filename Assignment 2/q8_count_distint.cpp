// To count number of distinct elements in an array

# include <iostream>
# include <algorithm>
using namespace std;


// Recursive approach
int count_distinct(int arr[], int len) {
    if (len <= 0) return 0;
    if (len == 1) return 1;     // Single element is distinct

    // If a distinct is encountered, count it
    if (arr[0] != arr[1]) return 1 + count_distinct(arr+1, len-1);

    // If two consecutive elements are same, dont count it (it will be counted at the last duplication when an unequal element is encountered)
    else return count_distinct(arr+1, len-1);
}


int main() 
{
    int len;
    cout << "Enter length : " ;
    cin >> len;
    int arr[len];
    cout << "Enter array : ";
    for (int i = 0; i<len; i++) cin >> arr[i];
    
    sort(arr, arr+len);
    cout << "Distinct elements : " << count_distinct(arr,len);
}
