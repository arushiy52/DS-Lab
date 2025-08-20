// To sort strings in alphabetical order

# include <iostream>
# include <string>
using namespace std;


// To display strings
void display(string arr[], int len) {
    for (int i = 0; i<len;i++) {
        cout << arr[i] << "\n";
    }
}


void sort_strings(string arr[], int len) {
    
    for (int i=0; i<len-1; i++) {
        for (int j=i+1; j<len; j++) {
            if (arr[j]<arr[i]) {
                // Swapping strings
                string temp = arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
    }
    cout << "Strings in Alphabetical Order :-" << endl;
    display(arr, len);
}




int main()
{
    string arr[] = {"Spider", "Snake", "Fly", "Dragonfly", "Butterfly", "Grasshopper" };
    int length = sizeof(arr)/sizeof(arr[0]);
    sort_strings(arr, length);
}