class Node{
    public:
    Node* links[26];
    bool flag;

    Node(){
        flag=false;
        for(int i=0;i<26;i++){
            links[i]=NULL;
        }
        
    }

    bool containsKey(char ch){
        return links[ch-'a']!=NULL;
    }

    void put(char ch){
        links[ch-'a']=new Node();
    }

    Node* get(char ch){
        return links[ch-'a'];
    }

    void setEnd(){
        flag=true;
    }

    bool isEnd(){
        return flag;
    }

};

class Trie {
private:
    Node* root;
public:
    Trie() {
        root=new Node();
    }
    
    void insert(string word) {
        // complexity is O(n) where n is length of word
        int n=word.size();
        Node* node=root;
        for(int i=0;i<n;i++){
            if(!(node->containsKey(word[i]))){
                node->put(word[i]);
            }
            node=node->get(word[i]);
        }
        node->setEnd();
    }
    
    bool search(string word) {
        // complexity is O(n) where n is length of word
        Node* node=root;
        int n=word.size();
        for(int i=0;i<n;i++){
            if(!node->containsKey(word[i])){
                return false;
            }
            node=node->get(word[i]);
        }
        return node->isEnd();
    }
    
    bool startsWith(string prefix) {
        // complexity is O(n) where n is length of word
        Node* node=root;
        int n=prefix.size();
        for(int i=0;i<n;i++){
            if(!node->containsKey(prefix[i])){
                return false;
            }
            node=node->get(prefix[i]);
        }
        return true;
    }
};
