#include <map>

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