class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0;
        int j = s.length() - 1;

        while(i <= j){

            while (i <= j && !isalnum(s[i]))
                i++;

            while (i <= j && !isalnum(s[j]))
                j--;

            if (i > j)
                break;

            char ch1 = tolower(s[i]);
            char ch2 = tolower(s[j]);

            if(ch1 != ch2) return false;

            i++;
            j--;
        }

        return true;
    }
};
