#include <iostream>
#include <climits>
#include <unordered_map>
#include <vector>

using namespace std;

int fruitsIntoBasket(vector<int>& nums){
    int low,high,res;
    low=high=0;
    res= INT_MIN;

    int n=nums.size();

    unordered_map<int,int> f;

    for(high=0;high<n;high++){
        f[nums[high]]++;

        while(f.size()>2){
            f[nums[low]]--;

            if(f[nums[low]]==0){
                f.erase(nums[low]);
            }

            low++;
        }
        int len=high-low+1;
        res=max(res,len);
    }

    if(res==INT_MIN) return -1;

    return res;
}

int main(){
    vector<int> nums = {1, 2, 1};
    cout << fruitsIntoBasket(nums) << endl;

    return 0;
}