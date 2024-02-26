#include <iostream>
#include <vector>
using namespace std;

int CheckDuplicate(vector<char> arr){
    int minEle=arr[0], maxEle=arr[0], len = arr.size();
    for(int i=1; i<len; i++){
        if(maxEle<arr[i])
            maxEle = arr[i];
        if(minEle>arr[i])
            minEle = arr[i];
    }
    vector<int> countArr;
    countArr.assign(maxEle-minEle+1, 0);
    for(int i=0; i<len; i++){
        countArr[arr[i]-minEle]++;
    }
    for(int i=0; i<countArr.size(); i++){
        cout<<i<<" "<<countArr[i]<<endl;
    }
}

int main(){
    int iter, len, res;
    char temp;
    cout<<"Enter number of cases: ";
    cin>>iter;
    for(int i=0; i<iter; i++){
        cout<<"Enter length of "<<i+1<<" case: ";
        cin>>len;
        cout<<"Enter elements: ";
        vector<char> arr;
        for(int j=0; j<len; j++){
            cin>>temp;
            arr.push_back(temp);
        }
        res = CheckDuplicate(arr);
        //if(res == -1)
        //    cout<<""<<endl;
        //else
        //    
    }
}

// 
