class Solution {
public:
    string smallestSubsequence(string s) {
        int n = s.length();
        string st = "" ;
        vector<int> last_occ(26,0);
        vector<bool> visited(26 ,false);

        for(int i = 0 ; i < n ; i++ ){
           last_occ[s[i] - 'a'] = i ;
        }
        for(int i= 0 ; i < n ; i++){
               char ch = s[i];
               if(visited[ch - 'a']){
                continue;
               }
               while(!st.empty() && st.back() > ch && last_occ[st.back() - 'a'] > i){
                visited[st.back() - 'a'] = false;
                st.pop_back();
               }
               st.push_back(ch);
               visited[ch -'a'] = 'true';
        }
       return st;
    }
};
