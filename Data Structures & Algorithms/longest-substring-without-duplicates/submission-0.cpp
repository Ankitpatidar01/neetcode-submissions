class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int>mp;
       
        int maxLen = 0;
        int j = 0;


        for(int i = 0 ; i < s.length() ; i++){
            mp[s[i]]++;

           while(mp[s[i]] > 1){
              mp[s[j]]--;
              j++;
           }

           maxLen = max(maxLen , i - j + 1);
        }

        return maxLen;
    }
};
