class Solution {
public:
    int ladderLength(string start, string end, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(),wordList.end());
        queue<pair<string,int>> q;
        q.push({start,1});
        dict.erase(start);

        while(!q.empty())
        {
            auto [word,cnt]=q.front();
            q.pop();

            if(word==end) return cnt;
            for(int i=0;i<word.size();i++)
            {
                char org=word[i];
                for(char ch='a';ch<='z';ch++)
                {
                    word[i]=ch;
                    if(dict.count(word))
                    {
                        dict.erase(word);
                        q.push({word,cnt+1});
                    }
                }
                word[i]=org;
            }
        }

        return 0;
    }
};