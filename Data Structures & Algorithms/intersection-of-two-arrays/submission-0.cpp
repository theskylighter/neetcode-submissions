class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        unordered_set<int> st(nums1.begin(),nums1.end());
        unordered_set<int> ansSt;
        for( int & i:nums2){
            if(st.count(i)&&ansSt.count(i)==0){
                ans.push_back(i);
                ansSt.insert(i);
            }
        }
        return ans;
    }
};