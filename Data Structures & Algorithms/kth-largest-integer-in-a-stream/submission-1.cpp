class KthLargest {
public:
priority_queue<int, vector<int> , greater<int>> pq;
int k;
    KthLargest(int k, vector<int>& nums) {
        pq=priority_queue<int, vector<int> , greater<int>>(nums.begin(), nums.end());
        this->k=k;
        while(pq.size()>k){
            pq.pop();
        }
    }
    
    int add(int val) {
        pq.push(val);
        if(pq.size()>k) 
            pq.pop();
        return pq.top();
    }
};
