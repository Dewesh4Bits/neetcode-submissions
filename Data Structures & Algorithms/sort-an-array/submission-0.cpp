void swap(int &a, int &b){
    int temp = a; a = b; b = temp; 
}

void my_quickSort(vector<int> &arr, int l, int h){
    if(l>=h)
        return; 
    
    int pivot = arr[h]; 
    int j = l; 
    for(int i=l; i<h; i++){
        if(arr[i]<pivot){
            swap(arr[i], arr[j]);
            j++;        
        }
    }
    swap(arr[j], arr[h]);
    my_quickSort(arr, l, j-1); 
    my_quickSort(arr, j+1, h);
} 

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        my_quickSort(nums, 0, nums.size()-1); 
        return nums; 
    }
};