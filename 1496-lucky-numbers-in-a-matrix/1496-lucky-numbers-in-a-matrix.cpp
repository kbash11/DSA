class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        unordered_map<int,int> row;
        unordered_map<int,int> col;
        vector<int> ans;

        for(int i=0;i<m;i++){
            int rowMin=INT_MAX;
            for(int j=0;j<n;j++){
                rowMin=min(rowMin,matrix[i][j]);  
            }
            row[rowMin]++;
        }
        for(int j=0;j<n;j++){
            int colMax=INT_MIN;
            for(int i=0;i<m;i++){
                colMax=max(colMax,matrix[i][j]);  
            }
            col[colMax]++;
        }
        for(auto [it,_]:row){
            if(col.count(it)>0){
                ans.push_back(it);
            }
        }
        
        return ans;
    }
};