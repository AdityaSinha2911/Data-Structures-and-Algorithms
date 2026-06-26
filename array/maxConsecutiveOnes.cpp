#include <iostream>
#include <vector>

using namespace std;

/* leetcode ques:485
    approach: first taken variable count and maxcount and initialized with 0
              then traverse the vector, and when the number is 1, it increase count, and max of count and 
                    maxCount get stored into maxCount.
              if, the continutiy breaks, count score get resettled at 0 .
*/

int maxOne(vector<int>& nums){
    int count =0;
    int maxCount=0;

    for(int i=0;i<nums.size();i++){
        if(nums[i]==1){
            count++;
            maxCount=max(count,maxCount);
        }else{
            count=0;
        }
    }

    return maxCount;
}

int main(){
    vector<int> arr={1,1,2,0,1,1,1,1,4,1,1,1,1,1};
    cout<<maxOne(arr);

    // output: 5
}