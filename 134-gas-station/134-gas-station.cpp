class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        for(int i = 0;i<n;i++){
            if(canMove(i,n,gas,cost))
                return i;
        }
        
        return -1;
    }
    
    bool canMove(int pos,int n,vector<int>& gas,vector<int>& cost){
        int currGas = gas[pos];
        int prev = pos;
        int i = pos+1 >= n ? 0:pos+1;
        if(currGas == 0)
            return false;
        do{
            
            currGas = currGas - cost[prev];    
            if(currGas < 0){
                return false;
            }
            
            currGas += gas[i];
            
            prev = i;
            i = (i+1) >= n ? 0:i+1;
        }while(i!=pos);
        
        currGas -= cost[prev];
        
        if(currGas < 0)
            return false;
        
        return true;
    }
};