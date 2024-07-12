class Solution {
public:
    int maximumGain(string s, int x, int y) {
        stack<char> stk;
        stk.push(s[0]);
        int ans=0;
        for(int i=1;i<s.size();i++){
            if(x>y){
                if(!stk.empty() && stk.top()=='a' && s[i]=='b'){
                    stk.pop();
                    ans+=x;
                }else{
                    stk.push(s[i]);
                }    
            }else{
                if(!stk.empty() && stk.top()=='b' && s[i]=='a'){
                    stk.pop();
                    ans+=y;
                }else{
                    stk.push(s[i]);
                }  
            }
        }
        string str;
        while(!stk.empty()){
            str+=stk.top();
            stk.pop();
        }
        reverse(str.begin(),str.end());

        stk.push(str[0]);
        for(int i=1;i<str.size();i++){
            if(x<=y){
                if(!stk.empty() && stk.top()=='a' && str[i]=='b'){
                    stk.pop();
                    ans+=x;
                }else{
                    stk.push(str[i]);
                }    
            }else{
                if(!stk.empty() && stk.top()=='b' && str[i]=='a'){
                    stk.pop();
                    ans+=y;
                }else{
                    stk.push(str[i]);
                }  
            }
        }
        
        return ans;

        //int ans=0;
        // while(s.find("ab")!=string::npos || s.find("ba")!=string::npos){
        //     int ab=s.find("ab");
        //     int ba=s.find("ba");
        //     if(ab!=string::npos && ba!=string::npos){
                
        //         if(x>y){
        //             s.erase(ab,2);
        //             ans+=x;
        //         }else{
        //             s.erase(ba,2);
        //             ans+=y;
        //         }
        //     }else if(ab!=string::npos){
        //         ans+=x;
        //         s.erase(ab,2);
        //     }else if(ba!=string::npos){
        //         ans+=y;
        //         s.erase(ba,2);
        //     } 
        // }
        // return ans;
    }
};