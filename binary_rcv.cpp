#include <bits/stdc++.h>
using namespace std;

int binary_search(vector<int>& arr, int x, int low, int high){
    if(low > high)return -1;
    int mid = (low+high)/2;
    if(arr[mid] == x)return mid;
    else if(arr[mid] > x)return binary_search(arr, x, low, mid-1);
    else return binary_search(arr, x, mid+1, high);
}

int main(){
    vector<int> arr = {1,4,5,6,8,9,12};
    int res = binary_search(arr, 8, 0, 6);
    cout << res << endl;
    return 0;
}
