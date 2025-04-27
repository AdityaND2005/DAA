#include <bits/stdc++.h>
using namespace std;

int binary_search(vector<int>& arr, int x){
    int low = 0;
    int high = arr.size() - 1;
    while(low <= high){
        int mid = (low + high)/2;
        if(arr[mid] == x)return mid;
        else if(arr[mid] > x)high = mid - 1;
        else low = mid + 1;
    }
    return -1;
}

int main(){
    vector<int> arr = {1,4,5,6,8,9,12};
    int res = binary_search(arr, 8);
    cout << res << endl;
    return 0;
}
