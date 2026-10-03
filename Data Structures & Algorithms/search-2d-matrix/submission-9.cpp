class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();

        int l=0, r=n-1, midr=0;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(matrix[mid][0]<=target && target<=matrix[mid][m-1]){
                midr = mid;
                break;
            }
            else if(target > matrix[mid][m-1])
                l=mid+1;
            else if(target < matrix[mid][0])
                r=mid-1;
        }

        l=0, r=m-1;
        while(l<=r){
            int m = l+(r-l)/2;
            if(matrix[midr][m]==target)
                return true;
            else if(matrix[midr][m] > target)
                r=m-1;
            else
                l=m+1;
        }

        return false;
    }
};
