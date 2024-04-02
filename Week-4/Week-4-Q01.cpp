#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int> &arr, int left, int mid, int right, int &comp, int &inver){
  int n1 = mid - left + 1;
  int n2 = right - mid;

  vector<int> L(n1), R(n2);

  for(int i=0; i<n1; i++)
    L[i] = arr[left+i];

  for(int j=0; j<n2; j++)
    R[j] = arr[mid+1+j];
  
  int i = 0, j = 0, k = left;

  while(i < n1 && j < n2){
    comp++;
    if(L[i] <= R[j]) {
      arr[k] = L[i];
      i++;
    } else {
      arr[k] = R[j];
      j++;
      inver += (mid-left+1-i);
    }
    k++;
  }

  while(i < n1){
    arr[k] = L[i];
    i++, k++;
  }

  while(j < n2){
    arr[k] = R[j];
    j++, k++;
  }
}

void MergeSort(vector<int> &arr, int left, int right, int &comp, int &inver){
  if(left < right) {
    int mid = left + (right - left) / 2;

    MergeSort(arr, left, mid, comp, inver);
    MergeSort(arr, mid+1, right, comp, inver);
    
    merge(arr, left, mid, right, comp, inver);
  }
}

int main(){
  int iter, len, temp, comp, inver;
  cout<<"Enter number of cases: ";
  cin>>iter;
  for(int i=0; i<iter; i++){
    comp=0, inver=0;
    cout<<"Enter length of "<<i+1<<" case: ";
    cin>>len;
    cout<<"Enter elements: ";
    vector<int> arr;
    for(int j=0; j<len; j++){
      cin>>temp;
      arr.push_back(temp);
    }
    MergeSort(arr, 0, len, comp, inver);
    for(int j=0; j<len; j++){
      cout<<arr[j]<<" ";
    }
    cout<<endl<<"comparisons = "<<comp<<endl;
    cout<<"inversions = "<<inver<<endl;
  }
}

// DONE
