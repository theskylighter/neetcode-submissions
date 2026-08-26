class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
            unordered_set<string> ust;
        for( auto &st:emails){
            // process
            string s="";
            bool atF=false;
            bool plusF=false;

            for(char &ch:st){
                if(ch=='@'&&!atF) atF=true;
                if(!atF && ch=='.'){
                    continue;
                }
                else if(ch=='+' && !plusF)
                     plusF=true;
                else if(plusF&& !atF){
                    continue;
                }
                else
                    s+=ch;
            }
            // cout<<s<<endl;
            ust.insert(s);
        }
        return ust.size();
    }
};