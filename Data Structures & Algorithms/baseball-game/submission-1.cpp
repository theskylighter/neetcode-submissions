class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> st;
        for(auto &s:operations){
            if(s=="+"){
                int t1= st.top();
                st.pop();
                int t2=st.top();
                st.push(t1);
                st.push(t1+t2);
            }
            else if(s=="C"){
                st.pop();
            }
            else if(s=="D"){
                int tmp= st.top();
                st.push(tmp*2);
            }
            else{
                //int
                st.push(stoi(s));
            }
        }
        int ans=0;
        for(;!st.empty();st.pop()){
            ans+= st.top();
        }
        return ans;
    }
};