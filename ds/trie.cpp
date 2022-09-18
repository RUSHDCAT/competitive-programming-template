class Trie {
public:
    Trie* children[26]={};
    int n=0;
    /** Initialize your data structure here. */
    Trie() {
        
    }
    /** Inserts a word into the trie. */
    void insert(string& word) {
        Trie* node=this;
        ++n;
        for(char c:word){
            if(!node->children[c-'a'])
                node->children[c-'a']=new Trie();
            node=node->children[c-'a'];
            ++(node->n);
        }
    }
    /** Returns if the word is in the trie. */
    int search(string& word) {
        int res=0;
        Trie* node=this;
        for(char c:word){
            if(!node->children[c-'a'])
                return false;
            node=node->children[c-'a'];
            res+=node->n;
        }
        return res;
    }
};