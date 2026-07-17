class Solution {
public:

    string encode(vector<string>& strs) {
        string ans= "";
        for(auto str: strs){
            ans+= str;
            ans+="|";
        }
        return ans;
    }

    vector<string> decode(string s) {
        vector<string> ans;
        string word="";
        for(auto ch:s){
            if( ch=='|'){
                ans.push_back(word);
                word="";
            }
            else{
                word+=ch;
            }
        }
        return ans;
    }
};
