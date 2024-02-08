#include <iostream>
using namespace std;

int BinarySearch(int arr[], int left, int right, int key, int *comp){
    *comp = *comp + 1;
    if(right >= left){
        int mid = left + (right - left) / 2;

        if(arr[mid] == key)
            return mid;
        
        if(arr[mid] > key)
            return BinarySearch(arr, left, mid-1, key, comp);
        
        if(arr[mid] < key)
            return BinarySearch(arr, mid+1, right, key, comp);
    }
    return -1;
}

int main(){
    int len, key, res, comp=0;
    cout<<"Enter length of sorted array: ";
    cin>>len;
    int arr[len];
    cout<<"Enter elements: ";
    for(int i=0; i<len; i++){
        cin>>arr[i];
    }
    cout<<"Enter key to search: ";
    cin>>key;
    res = BinarySearch(arr, 0, len-1, key, &comp);
    if(res == -1)
        cout<<"Couldn't find "<<key<<" even after "<<comp<<" comparisons!"<<endl;
    else
        cout<<"Found "<<key<<" at index "<<res<<" after "<<comp<<" comparisons!"<<endl;
}

// DONE