class Solution {
public:

    bool canplace(vector<int>& position, int m , int dist){
        int count =1;
        int last = position[0];

        for(int i=1; i<position.size(); i++){
            if(position[i] - last >= dist){
                  count ++;
                  last= position[i];
            }

            if(count == m){
               return true;
            }
        }
        return false;
    }

    int maxDistance(vector<int>& position, int m) {
        // sortin the array first 
        sort(position.begin(), position.end());
        int ans=0;
        int n = position.size();
        //binary search
        int low = 1;
        int hih = position[n-1] - position[0];
        
        while(low <= hih){
           int  mid = (low+ (hih-low) / 2 ) ;

           if(canplace(position, m ,mid)){
            ans = mid;
            low = mid + 1;

           }else{
             hih = mid -1;
           }

        }

        return ans;
    }
};
