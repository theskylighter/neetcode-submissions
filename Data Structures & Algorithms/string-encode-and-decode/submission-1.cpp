class Solution {
public:

    string encode(vector<string>& strs) {
        string ans= "";
        for(auto str: strs){
            ans+= to_string(str.length());
            ans+="#";
            ans+= str;
        }
        return ans;
    }

    vector<string> decode(string s) {
        vector<string> ans;
        string word="";
        int n=0;;
        char ch;
        int i=0;
        while(i< s.length()){
            word="";
            n=0;
            // ch=s[i];
            // count digit until '#'
        
            while( s[i]!='#'){
                ch= s[i];
                n=n*10 + (ch-'0');
                i++;
            }
            // skip the hash after digit
            i++;
            // count the n letters into a word
            while(n>0){
                ch= s[i];
                word+= ch;
                i++;
                n--;
            }
            // push the word into ans;
            ans.push_back(word);
            

            
        }
        return ans;
    }
};
