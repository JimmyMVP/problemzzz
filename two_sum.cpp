#include <map>


// Given an array of integers, find two numbers such that they add up to a specific target number.

// The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.

// You may assume that each input would have exactly one solution.

// Input: numbers={2, 7, 11, 15}, target=9
// Output: index1=1, index2=2

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        
        vector<int> solution;
        std::map<int,int> m;
        
        
        for(int i = 0; i < nums.size(); i++) {
            if(m.find(2*nums[i]) == m.end())
                m[2*nums[i]] = i;
            else
                m[2*nums[i]+1] = i;
        }  
        
        for(int i = 0; i < nums.size(); i++) {
            int v1,v2;
            if(m.find(2*(target - nums[i])) == m.end())
                continue;
            v1 = m[2*(target - nums[i])];
            if(v1 == i){
                v2 = m[2*nums[i]+1];
                if(!v2){
                    continue;
                } 
            } else {
                v2 = i;
            }
            int i1,i2;
            i1 = v2  > v1 ? v1 : v2;
            i2 =  v2 < v1 ? v1 : v2;
            solution.push_back(i1+1);
            solution.push_back(i2+1);
            return solution;

                
        }
       
        
    }
};


//Is this solution memory ineffective? Faster than the previous
class Solution2 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        vector<int> solution;
        int min, max;
        
        min = target;
        max = nums[0];
        for(int num : nums) {
            if(num < min) {
                min = num;
            }
            if(num > max) {
                max = num;
            }
        }
        int a[max-min];
        
        for(int i = 0; i < max-min; i++) {
            a[i] = -1;
        }
        for(int i = 0; i < nums.size(); i++) {
            a[nums[i]-min] = i;
        }
        int bet = target - min;
        int d = max-min;
        for(int i = 0; i < nums.size();i++) {
            int p = bet - nums[i];
            if(p > d || p < 0) continue;
            int v1 = a[p];
            if(v1 != i && v1 >= 0) {
                solution.push_back(i+1);
                solution.push_back(v1+1);
                return solution;
            }
        }
        
    }
};