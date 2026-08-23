class Solution {
public:

    string decodeString(string s) {

         stack<string>st;

         for(int i = 0 ; i < s.length() ; i++){
            if(s[i] >= '0' && s[i] <= '9'){
                 string num = "";

                while (i < s.length() && isdigit(s[i])) {
                    num += s[i];
                    i++;
                }

                st.push(num);
                i--;   
            }else if(s[i] == '[' || (s[i] >= 'a' && s[i] <= 'z')){
                st.push(string(1 , s[i]));
            }else if(s[i] == ']'){
                string temp = "";

                while (st.top() != "[") {
                    temp = st.top() + temp;
                    st.pop();
                }

                st.pop();

                int num = stoi(st.top());
                st.pop();

                string temp2 = "";

                while (num--) {
                    temp2 += temp;
                }
                st.push(temp2);
            }
        }

        string ans = "";

        while (!st.empty()) {
            ans = st.top() + ans;
            st.pop();
        }

         return ans;
    }
};