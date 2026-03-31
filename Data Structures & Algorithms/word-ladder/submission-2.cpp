class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int n = wordList.size();
        vector<bool> visited(n, false);

        int cnt = 0;
        queue<string> q;
        q.push(beginWord);

        while(q.size()){

            int sz = q.size();
            cnt++;
            for(int i=0; i<sz; i++){
                string s = q.front();
                q.pop();
                for(int j=0; j<n; j++){
                    if(visited[j])continue;
                    int wordSize = s.size();
                    int diff = 0;
                    for(int k=0; k<wordSize; k++){
                        if(s[k]!=wordList[j][k])diff++;
                    }
                    if(diff==1){
                        if(wordList[j]==endWord)
                            return cnt+1;
                        q.push(wordList[j]);
                        visited[j]=true;
                    }
                }
            }
        }
        return 0;
    }
};
