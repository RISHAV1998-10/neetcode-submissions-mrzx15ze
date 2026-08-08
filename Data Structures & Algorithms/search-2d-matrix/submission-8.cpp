class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();

        int lr=0, rr=n-1, lc=0, rc=m-1, row=-1;
        while(lr<=rr){
            int midr=(lr+rr)/2;
            if(matrix[midr][lc]<=target && target<=matrix[midr][rc]){
                row=midr;
                break;
            }
            else if(target<matrix[midr][lc])
                rr=midr-1;
            else  if(target>matrix[midr][rc])
                lr=midr+1;
        }

        if(row==-1)
            return false;

        while(lc<=rc){
            int mid=(lc+rc)/2;
            if(target==matrix[row][mid])
                return true;
            else if(target>matrix[row][mid])
                lc=mid+1;
            else
                rc=mid-1;
        }

        return false;
    }
};
