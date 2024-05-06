#include <bits/stdc++.h>
using namespace std;

int main() {
  int len;
  cout<<"Enter size of array: ";
  cin>>len;

  vector<int> arr(len);

  cout<<"Enter elements:"<<endl;
  for(int i=0; i<len; i++) {
    cin>>arr[i];
  }

  map<int, int> freq;

  for(int i=0; i<len; i++) {
    freq[arr[i]]++;
  }

  map<int, int>::iterator it = freq.begin();
  int maxEle, maxFreq = 0;

  while(it != freq.end()) {
    if(it->second > maxFreq) {
      maxEle = it->first;
      maxFreq = it->second;
    }
    it++;
  }

  if(maxFreq>len/2) {
    cout<<"yes"<<endl;
    cout<<maxEle<<endl;

  } else {
    cout<<"no"<<endl;
  }
}

// DONE
