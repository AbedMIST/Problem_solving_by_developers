class Solution {
public:
    bool isAnagram(string s, string t) {  //O(n)
        int i;
        vector<int> freq(26,0);

        for(i=0;i<s.size();i++){
            freq[s[i]-'a']++;
        }
        for(i=0;i<t.size();i++){
            freq[t[i]-'a']--;
        }

        for(i=0;i<26;i++){
            if(freq[i]!=0)  return false;
        }
        return true;  //if all freq element 0
    }
};
