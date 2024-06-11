class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        // map<int,int> m;                   //T.C- O(nlogn)     S.C-O(n)
        // for(auto it:arr1){  
        //     m[it]++;
        // }
        // vector<int> ans;
        // for(int i=0;i<arr2.size();i++){
        //     while(m[arr2[i]]>0){
        //         ans.push_back(arr2[i]);
        //         m[arr2[i]]--;
        //     }
        //     if(m[arr2[i]]==0){
        //         m.erase(arr2[i]);
        //     }
        // }
        // for(auto it :m){
        //     while(it.second>0){
        //         ans.push_back(it.first);
        //         it.second--;
        //     }
        // }
        // return ans;

        unordered_map<int,int> m;
        for(int i=0;i<arr2.size();i++){
            m[arr2[i]]=i;
        }
        for(auto it:arr1){
            if(!m.count(it)){
                m[it]=INT_MAX;
            }
        }
        auto lambda=[&](int &num1,int &num2){
            if(m[num1]==m[num2]){        // if both equal to INT_MAX
                return num1<num2;
            }
            return m[num1]<m[num2];
        };

        sort(arr1.begin(),arr1.end(),lambda);
        return arr1;
    }
};