//
//  main.cpp
//  TestC++
//
//  Created by 伍秦宋 on 2018/4/15.
//  Copyright © 2018年 伍秦宋. All rights reserved.
//

#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

class Solution {
public:
    int thirdMax(vector<int>& nums) {

        if(nums.size()==1)
        {
            return nums[1];
        }
        if(nums.size()==2)
        {
            return nums[1]>nums[2]?nums[1]:nums[2];
        }
        int a,b,c;
        a=b=c=INT_MIN;
        bool minflag = false;
        unsigned long fi = nums.size();
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==INT_MIN && !minflag)
            {
                minflag = true;
                continue;
            }
            
            if(nums[i]==a || nums[i]== b || nums[i]==c)
            {
                fi--;
                continue;
            }
            
            if(nums[i]>a)
            {
                c=b;b=a;a=nums[i];
                continue;
            }
            else if(nums[i]>b)
            {
                c=b;b=nums[i];
                continue;
            }
            else if(nums[i]>c)
            {
                c=nums[i];
                continue;
            }
        }
        return fi>=3?c:a;
    };
};

int main(int argc, const char * argv[]) {
    vector<int> a = {1,2};
    Solution solution;
    cout<<solution.thirdMax(a)<<endl;
    
    return 0;
};
