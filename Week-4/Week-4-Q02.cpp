#include <iostream>
#include <vector>
using namespace std;

int partition(vector<int> &arr, int left, int right, int &comp, int &swaps){
    int pivot = arr[right];
    int i = left-1;
    for(int j=left; j<right; j++){
        comp++;
        if(arr[j] <= pivot){
            i++;
            swap(arr[i], arr[j]);
            swaps++;
        }
    }
    swap(arr[i+1], arr[right]);
    swaps++;
    return i+1;
}

void QuickSort(vector<int> &arr, int left, int right, int &comp, int &swaps){
    if(left>=right) return;
    int p = partition(arr, left, right, comp, swaps);
    QuickSort(arr, left, p-1, comp, swaps);
    QuickSort(arr, p+1, right, comp, swaps);
}

int CheckDuplicate(vector<int> arr){
    int len = arr.size();
    for(int i=0; i<len-1; i++)
        if(arr[i] == arr[i+1])
            return 1;
    return 0;
}

int main(){
    int iter, len, temp, comp, swaps;
    cout<<"Enter number of cases: ";
    cin>>iter;
    for(int i=0; i<iter; i++){
        comp=0, swaps=0;
        cout<<"Enter length of "<<i+1<<" case: ";
        cin>>len;
        cout<<"Enter elements: ";
        vector<int> arr;
        for(int j=0; j<len; j++){
            cin>>temp;
            arr.push_back(temp);
        }
        QuickSort(arr, 0, len-1, comp, swaps);
        for(int j=0; j<len; j++){
            cout<<arr[j]<<" ";
        }
        cout<<endl<<"comparisons = "<<comp<<endl;
        cout<<"swaps = "<<swaps<<endl;
    }
}

// DONE
