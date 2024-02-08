#include <iostream>
#include <math.h>
using namespace std;

int JumpSearch(int arr[], int len, int key){
    int step = sqrt(len), prev=0;
    while(arr[step-1] < key && step < len){
        prev = step;
        step += sqrt(len);
        if(prev >= len) return -1;
    }
    while(arr[prev] < key){
        prev++;
        if(prev >= len) return -1;
    }
    if(arr[prev] == key) return prev;
    return -1;
}

int main(){
    int iter, len, key, res;
    cout<<"Enter number of cases: ";
    cin>>iter;
    for(int i=0; i<iter; i++){
        cout<<"Enter length of "<<i+1<<" sorted array: ";
        cin>>len;
        cout<<"Enter elements: ";
        int arr[len];
        for(int j=0; j<len; j++){
            cin>>arr[j];
        }
        cout<<"Enter key to search: ";
        cin>>key;
        res = JumpSearch(arr, len, key);
        if(res<0) cout<<"Not Present"<<endl;
        else cout<<"Present"<<endl;
    }
}

// DONE