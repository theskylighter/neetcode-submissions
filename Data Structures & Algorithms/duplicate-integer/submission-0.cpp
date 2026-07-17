class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> st;
        for(int &i: nums){
            if(st.find(i)== st.end()){
                // not found , add to set
                st.insert(i);
            }
            else{
                return true;
            }
        }
        return false;
    }
};