#pragma once
#define CHARACTERS 26

class TrieNode
{
    int m_iId;
    TrieNode *m_pChildren[CHARACTERS];
public:
    TrieNode();
    ~TrieNode();   
    bool IsNullChildrenAt(int iIndex);
    void SetChildrenAt(int iIndex, TrieNode* pNode);
    TrieNode * GetNodeAtIndex(int iIndex);
    void SetId(int iId);
    int GetId();
};

