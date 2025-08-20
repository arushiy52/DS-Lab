// Bubble sort

#include<iostream>
using namespace std;



void print(int*arr,int n){
    for(int i=0;i<n;i++){
        cout << arr[i] <<" ";
    }
    cout << endl;
}


void bubblesort(int*arr,int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
            }
        }
    }
    cout << "Sorted Array : ";
    print(arr,n);
}



int main(){
    int len=7,  arr[] = {3,3,-1,1,0,9,100};
    bubblesort(arr,len);
    return 0;
}
