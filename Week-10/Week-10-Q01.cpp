#include <bits/stdc++.h>
using namespace std;

struct Activity {
  int index, start, finish;
};

vector<int> selectActivities(vector<Activity> arr) {
  vector<int> selected;

  sort(arr.begin(), arr.end(), [](Activity &a, Activity &b) {
    return a.finish < b.finish;
  });

  int prev_finish = -1;
  vector<Activity>::iterator it = arr.begin();

  while(it != arr.end()) {
    if(it->start >= prev_finish) {
      selected.push_back(it->index);
      prev_finish = it->finish;
    }
    it++;
  }

  return selected;
}

int main() {
  int len;
  cout<<"Enter number of activities: ";
  cin>>len;

  vector<Activity> arr(len);

  cout<<"Enter starting times:"<<endl;
  for(int i=0; i<len; i++) {
    arr[i].index = i;
    cin>>arr[i].start;
  }
  cout<<"Enter finishing times:"<<endl;
  for(int i=0; i<len; i++) {
    cin>>arr[i].finish;
  }

  vector<int> selected = selectActivities(arr);

  for(int i=0; i<selected.size(); i++) {
    cout<<selected[i]+1<<" ";
  }
}

// DONE
