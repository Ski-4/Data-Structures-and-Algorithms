// Link to problem - https://leetcode.com/problems/remove-duplicate-letters/

class Solution {
public:
    string removeDuplicateLetters(string s) {
        int n = s.length();
        
        vector<int> freq(26,0);
        for(int i=0;i<n;i++) {
            freq[s[i]-'a']++;
        }
        
        vector<bool> visited(26,false);
        
        string ans;
        for(int i=0;i<n;i++) {
            if(visited[s[i]-'a']) {
                freq[s[i]-'a']--;
                continue;
            }
            
            while(!ans.empty() && freq[ans.back()-'a']>0 && ans.back()>s[i]) {
                visited[ans.back()-'a'] = false;
                ans.pop_back();
            }
            ans+=s[i];
            visited[s[i]-'a'] = true;
            freq[s[i]-'a']--;
        }
        
        return ans;
    }
};