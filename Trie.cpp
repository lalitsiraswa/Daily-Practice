#include <bits/stdc++.h>
using namespace std;

// --------------------------------------------------------------- 208. Implement Trie (Prefix Tree) -------------------------------------------------------
/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
class TrieNode
{
public:
    map<char, TrieNode *> children;
    bool isWord;
    TrieNode()
    {
        this->isWord = false;
    }
};
class Trie
{
    TrieNode *root;

public:
    // Constructor to create a trie node.
    Trie()
    {
        this->root = new TrieNode();
    }
    // A function to insert a word in trie.
    void insert(string word)
    {
        TrieNode *node = this->root;
        for (char ch : word)
        {
            if (node->children.find(ch) == node->children.end())
            {
                node->children[ch] = new TrieNode();
            }
            node = node->children[ch];
        }
        node->isWord = true;
    }
    // A function to search for a word in the trie.
    bool search(string word)
    {
        TrieNode *node = this->root;
        for (char ch : word)
        {
            if (node->children.find(ch) == node->children.end())
            {
                return false;
            }
            node = node->children[ch];
        }
        return node->isWord;
    }
    // A function to search for a prefix of a word in the trie.
    bool startsWith(string prefix)
    {
        TrieNode *node = this->root;
        for (char ch : prefix)
        {
            if (node->children.find(ch) == node->children.end())
            {
                return false;
            }
            node = node->children[ch];
        }
        return true;
    }
};

// int main()
// {
//     cout << string(35, '-') << endl;
//     Trie *obj = new Trie();
//     obj->insert("the");
//     obj->insert("this");
//     obj->insert("bye");
//     obj->insert("by");
//     obj->insert("a");
//     obj->search("bye");
//     obj->search("that");
//     cout << endl
//          << string(35, '-');
// }

// --------------------------------------------------------------- 1268. Search Suggestions System ----------------------------------------------------------
class Node
{
public:
    Node *childrens[26] = {nullptr};
    bool isWord;
    Node() : isWord(false) {}
    // checks if the reference trie is present or not
    bool containsKey(char ch)
    {
        return this->childrens[ch - 'a'] != nullptr;
    }
    // creating reference trie
    void put(char ch, Node *node)
    {
        this->childrens[ch - 'a'] = node;
    }
    // to get the next node for traversal
    Node *get(char ch)
    {
        return this->childrens[ch - 'a'];
    }
    // setting isWord to true at the end of the word
    void setEnd()
    {
        this->isWord = true;
    }
    // checking if the word is completed or not
    bool isEnd()
    {
        return isWord;
    }
};
class TrieImpl
{
private:
    Node *root;

public:
    TrieImpl() : root(new Node()) {}
    void insert(string word)
    {
        // initializing dummy node pointing to root initially
        Node *node = root;
        for (char ch : word)
        {
            if (!node->containsKey(ch))
            {
                node->put(ch, new Node());
            }
            // moves to reference trie
            node = node->get(ch);
        }
        node->setEnd();
    }
    bool search(string word)
    {
        Node *node = root;
        for (char ch : word)
        {
            if (!node->containsKey(ch))
            {
                return false;
            }
            node = node->get(ch);
        }
        return node->isEnd();
    }
    bool startsWith(string prefix)
    {
        Node *node = root;
        for (char ch : prefix)
        {
            if (!node->containsKey(ch))
            {
                return false;
            }
            node = node->get(ch);
        }
        return true;
    }
    Node *getLastPrefixNode(string prefix)
    {
        Node *node = root;
        for (char ch : prefix)
        {
            if (!node->containsKey(ch))
            {
                return nullptr;
            }
            node = node->get(ch);
        }
        return node;
    }
};
// ---------------------------------- MLE -------------------------------------------
void suggestedProductsCall(vector<string> &items, string prefixWord, Node *node)
{
    if (node->isEnd())
        items.push_back(prefixWord);
    bool flag = false;
    for (int i = 0; i < 26; i++)
    {
        if (node->childrens[i] != nullptr)
        {
            prefixWord.push_back(i + 'a');
            suggestedProductsCall(items, prefixWord, node->childrens[i]);
            prefixWord.pop_back();
        }
    }
}
vector<vector<string>> suggestedProducts(vector<string> &products, string searchWord)
{
    TrieImpl *root = new TrieImpl();
    sort(products.begin(), products.end());
    for (string word : products)
        root->insert(word);
    string prefixWord;
    vector<vector<string>> suggestedItems;
    for (char ch : searchWord)
    {
        vector<string> items;
        prefixWord.push_back(ch);
        Node *node = root->getLastPrefixNode(prefixWord);
        if (node != nullptr)
            suggestedProductsCall(items, prefixWord, node);
        int size = items.size();
        if (size > 3)
            suggestedItems.push_back({items.begin(), items.begin() + 3});
        else
            suggestedItems.push_back(items);
    }
    return suggestedItems;
}
// ---------------------------------
class TNode
{
public:
    map<char, TNode *> childrens;
    vector<string> searchWords;
};
class TrieImplementation
{
    TNode *root;

public:
    TrieImplementation() : root(new TNode()) {}
    // inserting string in trie
    void insert(string word)
    {
        TNode *node = this->root;
        for (auto c : word)
        {
            if (node->childrens.find(c) == node->childrens.end())
            {
                node->childrens[c] = new TNode();
            }
            node = node->childrens[c];
            if (node->searchWords.size() < 3)
            {
                node->searchWords.push_back(word);
            }
        }
    }
    // searching for a string
    vector<vector<string>> search(string word)
    {
        vector<vector<string>> result;
        TNode *node = this->root;
        int j = 0;
        for (auto c : word)
        {
            if (node->childrens.find(c) == node->childrens.end())
            {
                for (int i = 0; i < word.size() - j; i++)
                {
                    result.push_back({});
                }
                return result;
            }
            else
            {
                node = node->childrens[c];
                result.push_back(node->searchWords);
            }
            j += 1;
        }
        return result;
    }
};
vector<vector<string>> SuggestedProducts(vector<string> products, string searchWord)
{
    sort(products.begin(), products.end());
    TrieImplementation trie;
    for (string product : products)
        trie.insert(product);
    return trie.search(searchWord);
}
// int main()
// {
//     cout << string(35, '-') << endl;
//     vector<string> products = {"mobile", "mouse", "moneypot", "monitor", "mousepad"};
//     // vector<string> products = {"mobile"};
//     vector<vector<string>> suggested = SuggestedProducts(products, "mouse");
//     for (auto items : suggested)
//     {
//         for (auto item : items)
//             cout << item << ", ";
//         cout << endl;
//     }
//     cout << endl
//          << string(35, '-');
// }
// ------------------------------------------------------------------- 648. Replace Words -----------------------------------------------------------------------

class TryNode
{
public:
    map<char, TryNode *> childrens;
    bool endOfWord;
    TryNode() : endOfWord(false) {}
};
class TryImpl
{
    TryNode *root;

public:
    TryImpl() : root(new TryNode()) {}
    // inserting string in trie
    void insert(string word)
    {
        TryNode *curr = this->root;
        // adding string characters in the tree
        for (char ch : word)
        {
            // Create a new node if char does not exist in children dictionary
            if (curr->childrens.find(ch) == curr->childrens.end())
            {
                curr->childrens[ch] = new TryNode();
            }
            curr = curr->childrens[ch]; // update the node as we move to the next character
        }
        curr->endOfWord = true;
    }
    // this function replaces each word in the sentence with
    // the smallest word from the dictionary
    string replace(string word)
    {
        TryNode *curr = this->root;
        // iterate over each dictionary word along
        // with the index of that character
        int i = 0;
        for (char ch : word)
        {
            // if the character doesn't belong to the current node's children,
            // then return the word
            if (curr->childrens.find(ch) == curr->childrens.end())
            {
                return word;
            }
            // move to the child of the current node
            // corresponding to the current character
            curr = curr->childrens[ch];
            // when the flag end_of_word becomes TRUE, this means
            // we've reached the end of word in the trie. If this is the
            // case, then return this word
            if (curr->endOfWord)
            {
                return word.substr(0, i + 1);
            }
            i++;
        }
        return word;
    }
};
vector<string> senToStr(string sentence)
{
    vector<string> wordList;
    string word;
    for (char ch : sentence)
    {
        if (ch == ' ')
        {
            wordList.push_back(word);
            word.clear();
        }
        else
        {
            word.push_back(ch);
        }
    }
    wordList.push_back(word);
    return wordList;
}
string replaceWords(vector<string> &dictionary, string sentence)
{
    TryImpl trie;
    for (string prefix : dictionary)
    {
        trie.insert(prefix);
    }
    vector<string> newList = senToStr(sentence);
    for (int i = 0; i < newList.size(); i++)
    {
        newList[i] = trie.replace(newList[i]);
    }
    string result = "";
    for (string s : newList)
    {
        result += s + " ";
    }
    result.pop_back();
    return result;
}
// int main()
// {
//     cout << string(35, '-') << endl;
//     string sentence = "the quick brown fox jumps over the lazy dog";
//     vector<string> dictionary = {"qui", "brow", "bro", "jum", "j", "lazy", "d", "do"};
//     sentence = replaceWords(dictionary, sentence);
//     cout << sentence << endl;
//     cout << endl
//          << string(35, '-');
// }
// ------------------------------------------------------ 211. Design Add and Search Words Data Structure --------------------------------------------------
class myNode
{
public:
    map<char, myNode *> childrens;
    bool endOfWord;
    myNode() : endOfWord(false) {}
};
class WordDictionary
{
    myNode *root;

public:
    WordDictionary()
    {
        this->root = new myNode();
    }

    void addWord(string word)
    {
        myNode *curr = this->root;
        for (char ch : word)
        {
            if (curr->childrens.find(ch) == curr->childrens.end())
            {
                curr->childrens[ch] = new myNode();
            }
            curr = curr->childrens[ch];
        }
        curr->endOfWord = true;
    }
    bool searchCall(myNode *curr, string &word, int index)
    {
        if (index >= word.size())
        {
            if (curr->endOfWord)
                return true;
            return false;
        }
        if (word[index] == '.')
        {
            if (curr->childrens.empty())
                return false;
            for (pair<char, myNode *> item : curr->childrens)
            {
                if (searchCall(item.second, word, index + 1))
                    return true;
            }
            return false;
        }
        else if (curr->childrens.find(word[index]) == curr->childrens.end())
        {
            return false;
        }
        curr = curr->childrens[word[index]];
        return searchCall(curr, word, index + 1);
    }

    bool search(string word)
    {
        return this->searchCall(this->root, word, 0);
    }
};

int main()
{
    cout << string(35, '-') << endl;
    WordDictionary wd;
    wd.addWord("at");
    wd.addWord("anda");
    wd.addWord("an");
    wd.addWord("add");
    // cout << wd.search("a") << endl;
    // cout << wd.search(".at") << endl;
    wd.addWord("bat");
    // wd.search(".at");
    // wd.search("an.");
    // cout << wd.search("a.d.") << endl;
    cout << wd.search("and") << endl;
    // wd.search("b.");
    // wd.search("a.d");
    // wd.search(".");
    cout << endl
         << string(35, '-');
}