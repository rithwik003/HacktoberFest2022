class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        int rightmax[n];
        int leftmax[n];
       //for leftmax
        leftmax[0]=height[0];
        for(int i=1;i<n;i++){
            leftmax[i]=max(leftmax[i-1],height[i]);
        }
        //for rightmax
        rightmax[n-1]=height[n-1];
          for(int i=n-2;i>=0;i--){
          rightmax[i]=max(rightmax[i+1],height[i]);
          } 
        //for creating a water
       int water[n];
        for(int i=0;i<n;i++){
            water[i]=min(leftmax[i],rightmax[i])-height[i];
        }
        //for sum
        int sum=0;
        for(int i=0;i<n;i++){
         sum=sum+water[i];
        }
        return sum;
    }
};