class Solution {
public:
    int findMin(vector<int> &nums) {
        int n = nums.size(); 
        if(n==1 || (nums[0]<nums[1] && nums[0]<nums[n-1]))
            return nums[0];
        int low = 0; 
        int high = n-1; 
        int mid = 0; 
        while(low <= high){
            if(low==high){
                return nums[low];
            }
            mid = (low+high)/2; 
            if((mid !=0 && nums[mid]<nums[mid-1]) && (mid < (n-1) && nums[mid]<nums[mid+1]))
                return nums[mid]; 
            
            // eliminate 1st half
            if(nums[0] <= nums[mid])
                low = mid+1;
            // eliminate 2nd half
            else
                high = mid-1; 
        }
        return nums[mid];
    }
};
