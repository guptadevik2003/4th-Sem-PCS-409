// Q04) Write a C / C++ / Java program to sort an array
// consisting elements 0, 1 and 2 using single loop. (EXTRA QUESTION)

#include <iostream>
#include <vector>
using namespace std;

void SortArray(vector<int> &arr){
  int len = arr.size();
  int start = 0, mid = 0, end = len-1;

  while(mid <= end){
    if(arr[mid] == 0){
      swap(arr[start], arr[mid]);
      mid++, start++;
    }
    else if(arr[mid] == 1){
      mid++;
    }
    else if(arr[mid] == 2){
      swap(arr[end], arr[mid]);
      end--;
    }
  }
}

int main(){
  int len, temp;
  cout<<"Enter length of array: ";
  cin>>len;
  cout<<"Enter elements: ";
  vector<int> arr;
  for(int i=0; i<len; i++){
    cin>>temp;
    arr.push_back(temp);
  }
  SortArray(arr);
  cout<<"Result: ";
  for(int i=0; i<len; i++){
    cout<<arr[i]<<" ";
  }
  cout<<endl;
}

// DONE
