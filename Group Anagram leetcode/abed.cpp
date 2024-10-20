class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& str) { //O(m*nlog(n))
        
        unordered_map<string,vector<string>> mp;
        for(int i=0;i<str.size();i++){
            string cur = str[i];
            sort(cur.begin(),cur.end());

            mp[cur].push_back(str[i]);    //root word
        }

        vector<vector<string>> ans;
        for(auto it : mp){
            ans.push_back(it.second);
        }
        
        return ans;
    }
};
