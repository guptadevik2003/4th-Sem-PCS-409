#include <iostream>
#include <vector>
using namespace std;

int partition(vector<int> &arr, int left, int right){
    int pivot = arr[right];
    int i = left-1;
    for(int j=left; j<right; j++){
        if(arr[j] <= pivot){
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i+1], arr[right]);
    return i+1;
}

void QuickSort(vector<int> &arr, int left, int right){
    if(left>=right) return;
    int p = partition(arr, left, right);
    QuickSort(arr, left, p-1);
    QuickSort(arr, p+1, right);
}

int CheckDuplicate(vector<int> arr){
    int len = arr.size();
    for(int i=0; i<len-1; i++)
        if(arr[i] == arr[i+1])
            return 1;
    return 0;
}

int main(){
    int iter, len, temp;
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
        QuickSort(arr, 0, len-1);
        if(CheckDuplicate(arr))
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
}

// DONE
