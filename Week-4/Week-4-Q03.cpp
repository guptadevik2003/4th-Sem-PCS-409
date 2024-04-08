#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int KthElement(vector<int> arr, int k, int &res){
  priority_queue<int> pq;
  for(int i=0; i<arr.size(); i++){
    pq.push(arr[i]);
  }
  for(int i=0; i<arr.size()-k; i++){
    pq.pop();
    if(pq.empty()) return 0;
  }
  res = pq.top();
  return 1;
}

int main(){
  int iter, len, temp, k, found, res;
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
    cout<<"Enter value of k: ";
    cin>>k;
    found = KthElement(arr, k, res);
    if (found){
      cout<<res<<endl;
    } else {
      cout<<"not present"<<endl;
    }
  }
}

// DONE
