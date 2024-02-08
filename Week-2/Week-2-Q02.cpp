#include <iostream>
#include <vector>
using namespace std;

vector<int> FindSequence(vector<int> arr){
    int len = arr.size();
    vector<int> res;
    for(int k=len-1; k>=2; k--){
        int i=0, j=k-1;
        while(i < j){
            if(arr[i] + arr[j] == arr[k]){
                res.push_back(i+1);
                res.push_back(j+1);
                res.push_back(k+1);
                return res;
            }

            if(arr[i] + arr[j] < arr[k])
                i++;

            if(arr[i] + arr[j] > arr[k])
                j--;
        }
    }
    return res;
}

int main(){
    int iter, len, temp;
    cout<<"Enter number of cases: ";
    cin>>iter;
    for(int i=0; i<iter; i++){
        cout<<"Enter length of "<<i+1<<" sorted array: ";
        cin>>len;
        cout<<"Enter elements: ";
        vector<int> arr;
        for(int j=0; j<len; j++){
            cin>>temp;
            arr.push_back(temp);
        }
        vector<int> res = FindSequence(arr);
        if(!res.empty())
            cout<<res[0]<<", "<<res[1]<<", "<<res[2]<<endl;
        else
            cout<<"No sequence found."<<endl;
    }
}

// DONE