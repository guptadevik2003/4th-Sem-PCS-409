#include <iostream>
#include <vector>
using namespace std;

void SelectionSort(vector<int> &arr, int *comp, int *swaps){
    int min, len = arr.size();
    for(int i=0; i<len-1; i++){
        min = i;
        for(int j=i+1; j<len; j++){
            *comp = *comp + 1;
            if(arr[j] < arr[min])
                min = j;
        }
        if(min != i)
            *swaps = *swaps + 1;
            swap(arr[min], arr[i]);
    }
}

int main(){
    int iter, len, temp, comp=0, swaps=0;
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
        SelectionSort(arr, &comp, &swaps);
        for(int j=0; j<len; j++){
            cout<<arr[j]<<" ";
        }
        cout<<endl<<"comparisons = "<<comp<<endl;
        cout<<"swaps = "<<swaps<<endl;
    }
}

// DONE
