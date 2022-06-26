#include <bits/stdc++.h>
#include <unordered_set>
using namespace std ;

struct TrieNode {
    string word ;
    vector<TrieNode*> children ;
    TrieNode() {
        children.resize(256,NULL);
    } 
};

TrieNode* Build(vector<string> &terms) {
    TrieNode* root = new TrieNode();
    for(auto &s : terms) {
        TrieNode* curr = root ;
        for(char c : s) {
            if(!curr->children[int(c)]) curr->children[int(c)] = new TrieNode();
            curr = curr->children[int(c)];
        }
        curr->word = s ;
    }
    return root ;
}

void dfs(TrieNode* root, vector<string> &item) {
    if(!root) return ;
    if(!root->word.empty()) item.push_back(root->word);
    for(int i=0 ; i<256 ; i++)
        dfs(root->children[i],item);
}

vector<string> SearchResults(TrieNode* root, vector<string> &terms, string searchW) {
    vector<string> ans ;
    TrieNode* curr = root ;
    int n = searchW.size();
    for(int i=0 ; i<n ; i++) {
        if(!curr->children[searchW[i]]) return ans ;
        curr = curr->children[searchW[i]];
    }
    dfs(curr,ans);
    return ans ;
}

int main() {
    // Load Previous Searched Words into cache and create a Trie
    unordered_set<string> cache ;
    fstream f ;
    f.open("cache.txt",ios::in);
    while(!f.eof()) {
        string s ; f>>s ;
        cache.insert(s);
    }
    f.close();
    vector<string> terms(cache.begin(),cache.end());

    // Build the Trie
    TrieNode* root = Build(terms);

    // Ask user what they want to search 
    string searchW ; char c ;
    cout<<"Enter Search Word " ;
    while(true) {
        cin>>c ;
        system("clear");
        if(c=='.') {
            break ;
        }
        searchW.push_back(c);
        vector<string> current = SearchResults(root,terms,searchW);
        if(current.empty()) {
            cout<<"No Results found for "<<searchW<<endl ;
            continue ;
        }
        cout<<"Showing Results for "<<searchW<<endl ;
        for(auto &res : current) cout<<res<<endl ;
    }
    // Store the results
    vector<string> final = SearchResults(root,terms,searchW);

    // Reload Current Results and previous back to cache
    f.open("cache.txt",ios::out);
    cache.insert(searchW);
    for(string s : cache) if(!s.empty()) f<<s<<endl ;
    f.close();
    return 0;
}