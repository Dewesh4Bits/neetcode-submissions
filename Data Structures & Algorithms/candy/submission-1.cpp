class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size(); 
        vector<int> leftPass(n, 1); 
        vector<int> rightPass(n, 1); 
        int solution = 0; 

        for(int i = 1; i<n; i++){
            if(ratings[i]>ratings[i-1])
                leftPass[i] = leftPass[i-1]+1; 
        }

        for(int i = n-2; i>=0; i--){
            if(ratings[i]>ratings[i+1])
                rightPass[i] = rightPass[i+1]+1; 
        }

        for(int i = 0; i<n; i++){
            solution += max(leftPass[i], rightPass[i]); 
        }
        return solution; 
    }
};