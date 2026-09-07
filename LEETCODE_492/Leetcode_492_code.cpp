class Solution {
public:
    vector<int> constructRectangle(int area) {
        // area of rectanle is l*w
        for(int w=sqrt(area) ; w>=1 ; w--){
            if(area % w == 0){
              int l = area / w;
              return{l,w};
              break;
          }
        }

        return {};
    }
};
