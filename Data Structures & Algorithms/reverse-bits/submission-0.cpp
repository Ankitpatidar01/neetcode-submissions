class Solution {
public:
    uint32_t reverseBits(uint32_t n) {

         int i = 0;
         int ans = 0;
         while(i < 32){
            int bit = (n & 1) == 1 ? 1 : 0;
            //cout<<bit<<" at "<<i<<endl;
            if(bit == 1){
                ans = (ans << 1) + 1;
            }else{
                ans = ans << 1;
            }

            n = n >> 1;

            i++;
         }

         return ans;
    }
};
