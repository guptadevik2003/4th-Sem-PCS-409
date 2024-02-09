#include <iostream>
#include <vector>
using namespace std;

void InsertionSort(vector<int> &arr, int *comp, int *shift){
    int key, j, len = arr.size();
    for(int i=1; i<len; i++){
        key = arr[i];
        j = i - 1;
        while(j >= 0 && arr[j] > key){
            *comp = *comp + 1;
            *shift = *shift + 1;
            arr[j+1] = arr[j];
            j = j - 1;
        }
        arr[j+1] = key;
        *shift = *shift + 1;
    }
}

int main(){
    int iter, len, temp, comp=0, shift=0;
    cout<<"Enter number of cases: ";
    cin>>iter;
    for(int i=0; i<iter; i++){
        cout<<"Enter length of "<<i+1<<" case: ";
        cin>>len;
        cout<<"Enter elements: ";
        vector<int> arr;
        for(int j=0; j<len; j++){
            cin>>temp;
            arr.push_back(temp);
        }
        InsertionSort(arr, &comp, &shift);
        for(int j=0; j<len; j++){
            cout<<arr[j]<<" ";
        }
        cout<<endl<<"comparisons = "<<comp<<endl;
        cout<<"shifts = "<<shift<<endl;
    }
}

// DONE
