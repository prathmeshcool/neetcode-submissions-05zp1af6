class PrefixTree {
public:
    bool isLeaf;
    PrefixTree* children[26];

    PrefixTree() {
        isLeaf = false;
        for(int i=0; i<26;i++){
            children[i]=nullptr;    
        }     
    }
    void insert(string word) {
        PrefixTree* curr = this;

        for(auto c:word){
            if(curr->children[c-'a']==nullptr){
                PrefixTree* node = new PrefixTree();
                curr->children[c-'a'] = node;
            }
            curr=curr->children[c-'a'];
        }
        curr->isLeaf = true;
    }
    
    bool search(string word) {
        PrefixTree* curr = this;

        for(auto x:word){
            if(curr->children[x-'a']==nullptr){
                return false;
            }
            curr=curr->children[x-'a'];
        }
        return curr->isLeaf;
    }
    
    bool startsWith(string prefix) {
        PrefixTree* curr = this;

        for(auto x:prefix){
            if(curr->children[x-'a']==nullptr){
                return false;
            }
            curr= curr->children[x-'a'];
        }
        return true;
    }
};
