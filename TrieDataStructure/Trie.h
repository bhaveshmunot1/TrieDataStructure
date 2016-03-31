#pragma once

#include "TrieNode.h"
#include <string.h>

class Trie
{
    TrieNode *m_pTNRoot;
    int m_iCountOfNodes;
    TrieNode* GetNode();
    void PrintSuffixes(TrieNode* pRoot, char PrefixString[]);
public:
    Trie();
    ~Trie();
    void Insert(char InsertString[]);
    bool Search(char SearchString[]);
    void AutoComplete(char PrefixString[]);
};

