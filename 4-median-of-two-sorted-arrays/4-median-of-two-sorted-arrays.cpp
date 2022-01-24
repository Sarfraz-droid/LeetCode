class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        
        int i = 0,j=0;
        int k = 0;
        vector<int> fV(n1+n2);
        while(i<n1 and j<n2){
            
            if(nums1[i] < nums2[j]){
                fV[k++] = nums1[i++];
            }else{
                fV[k++] = nums2[j++];
            }
        }
        
        while(i<n1){
            fV[k++] = nums1[i++];
        }
        
        while(j<n2){
            fV[k++] = nums2[j++];
        }

        int mid = (fV.size()-1)/2;
        cout<<mid<<" : ";
        for(int l = 0;l<fV.size();l++){
            cout<<fV[l]<<" ";
        }
        cout<<endl;
        
        if(fV.size()%2 == 0){
            double sum = (fV[mid] + fV[mid+1])/(double)2;
            return sum;
        }else{
            double sum = fV[mid];
            return sum;
        }
        
    }
};