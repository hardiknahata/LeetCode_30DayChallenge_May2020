/*

Implement a trie with insert, search, and startsWith methods.

Example:

Trie trie = new Trie();

trie.insert("apple");
trie.search("apple");   // returns true
trie.search("app");     // returns false
trie.startsWith("app"); // returns true
trie.insert("app");   
trie.search("app");     // returns true

*/

const int ALPHABET_SIZE=26;
class Trie 
{

private:
    struct TrieNode
    {
        struct TrieNode *children[ALPHABET_SIZE];
        
        //isEndOfWord to indicate if a word ends at a node
	    bool isEndOfWord;
    };
    TrieNode* root;
    
    
public:
    
    /** Initialize your data structure here. */
    
    Trie() 
    {
       root = new TrieNode();
    };
   
    
    /** Inserts a word into the trie. */
    void insert(string word) 
    {
        TrieNode *cur = root;
        
        for(int i=0;i<word.length();i++)
        {
            int index = word[i]-'a';
            if(!cur->children[index])
                cur->children[index]=new TrieNode();
            
            cur=cur->children[index];
        }
        
        cur->isEndOfWord = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) 
    {
        TrieNode *cur = root;
        for(int i=0;i<word.length();i++)
        {
            int index = word[i]-'a';
            if(!cur->children[index])
                return false;
            cur=cur->children[index];
        }
        
        return (cur->isEndOfWord&&cur!=NULL);
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) 
    {
        TrieNode *cur = root;
        for(int i=0;i<prefix.length();i++)
        {
            int index = prefix[i]-'a';
            if(!cur->children[index])
                return false;
            cur=cur->children[index];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
