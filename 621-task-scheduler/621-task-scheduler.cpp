class Solution {
public:
    
    static bool cmp(int &a,int &b){
        return a > b;
    }
    
    int leastInterval(vector<char>& tasks, int n) {
        
        unordered_map<char,int> mp;
        for(auto x : tasks){
            mp[x]++;
        }
        
        priority_queue<int> pq;
        
        for(auto x : mp) pq.push(x.second);        
        int time = 0;
        while(!pq.empty()){
            vector<int> tmp;
            
            // output(pq);
            int l = 0;
            
            for(int i = 0;i<=n;i++){
                if(!pq.empty()){
                    tmp.push_back(pq.top()-1);                     
                    pq.pop();
                    l++;
                }
            }            
            for(auto x: tmp){
                if(x>0) pq.push(x);
            }
            
            time += pq.empty() ? l : n+1;
            
        }
        
        return time;
    }
    
    void output(priority_queue<int> pq){
        while(!pq.empty()){
            cout<<pq.top()<<" ";
            pq.pop();
        }
        cout<<endl;
    }
};