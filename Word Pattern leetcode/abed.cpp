class Solution {
public:
    bool wordPattern(string pattern, string s) {
        
        unordered_map<char,string> mp1;
        unordered_map<string,char> mp2;
        int i = 0;
        string word = "";

        for (auto x : s)
        {
            if(x == ' ')
            {
                if(mp1.find(pattern[i]) == mp1.end() && mp2.find(word) == mp2.end()){
                    mp1[pattern[i]] = word;
                    mp2[word] = pattern[i];
                }
                else{
                    if(mp1[pattern[i]] != word || mp2[word] != pattern[i]){
                        return false;        //mismatched mapping
                    }
                    //else ok
                }
                word = "";
                i++;
            }
            else {
                word = word + x;
            }
        }
        if(!word.empty()){
            if(mp1.find(pattern[i]) == mp1.end() && mp2.find(word) == mp2.end()){
                mp1[pattern[i]] = word;
                mp2[word] = pattern[i];
            }
            else{
                if(mp1[pattern[i]] != word || mp2[word] != pattern[i]){
                    return false;        //mismatched mapping
                }
            }
            i++;
        }

        return i==pattern.size();
        
    }
};
