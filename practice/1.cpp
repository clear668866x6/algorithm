#include<bits/stdc++.h>
using namespace std;



int binary_search(vector<int> &nums, int target) {
    int i = 0, j = nums.size() - 1;
    while(i <= j) {
        int m = (j + i) / 2; //mid
        if(nums[m] < target) {
            i = m + 1;  //target is in [m+1,j
        } else if (nums[m] > target) {
            j = m - 1; //target is in [i,m-1]
        } else {
            j = m - 1;
        }
    }
    return i;
}

int binary_search_L(vector<int> &nums, int target){
    int i = binary_search(nums, target);
    
    if(i == nums.size() || nums[i] != target) {
        return -1;
    }
    return i;
}

int binary_search_R(vector<int> &nums, int target) {
    int i = binary_search(nums, target+1);
    
    int j = i - 1;
    if (j == -1 || nums[j] != target) {
        return -1;
    }

    return j;
}

int main() {
    int n, q, k;
    cin >> n >> q;
    // nums.resize(n);
    vector<int> nums;
    for(int i = 0; i < n; ++i){
        int x;
        cin>>x;
        nums.push_back(x);
    }
    for(int i = 0; i < q; ++i) {
        cin >> k;
        cout << binary_search_L(nums, k) << " " << binary_search_R(nums, k) << endl;
    }
    return 0;
}