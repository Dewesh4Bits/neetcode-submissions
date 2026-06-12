class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<long long int, int> sumIndex;
        long long int seqSum = 0;  
        
        // solution 
        int count = 0; 

        sumIndex[0] = 1; 
        for(int i=0; i<nums.size(); i++){
            seqSum += nums[i]; 
            if(sumIndex.find(seqSum - k) != sumIndex.end()){
                count += sumIndex[seqSum - k]; 
            }
            if(sumIndex.find(seqSum) != sumIndex.end()){
                sumIndex[seqSum]++; 
            }
            else{
                sumIndex[seqSum]=1;
            }
        }

        return count; 
    }
};