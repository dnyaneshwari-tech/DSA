#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool ispossible(vector<int> &arr , int n, int c, int mid ){
    int cows = 1;int lastallpos = arr[0];
    for(int i=1;i<n;i++){
        if((arr[i] - lastallpos) >= mid){
            cows++;
            lastallpos = arr[i];
        }
        if(cows == c){
            return true;
        }
    }
    return false;
}
int getdistance(vector<int> &arr, int n,int c){
    std::sort(arr.begin(), arr.end());
    int str = 1;
    int end = arr[n-1] - arr[0];
    int ans = 0;
    while(str <= end){
        int mid = str + (end - str)/2;
        if(ispossible(arr,n,c,mid)){
            ans = mid;
            str = mid + 1;
        }
        else{
            end = mid -1;
        }
    }
    return ans;
}

int main() {
    vector<int> arr = {1,2,3,4,5,7} ;
    int n = arr.size();
    int c = 3;

    cout << "maximum possible distance between cows is : " << getdistance(arr,n,c);
    return 0;
}
