class Solution {
public:
    string convertToTitle(int cn) {
        string ans="";
        while(cn>0){
        cn--;
            ans+= (cn%26) +'A';
            cn/=26;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};