#include "stdafx.h"
#include "TrieNode.h"


TrieNode::TrieNode()
{
    m_iId = 0;
    for (int i = 0; i < CHARACTERS; i++)
        m_pChildren[i] = NULL;
}


TrieNode::~TrieNode()
{
}

bool TrieNode::IsNullChildrenAt(int iIndex)
{
    return m_pChildren[iIndex] == NULL;
}

void TrieNode::SetChildrenAt(int iIndex, TrieNode* pNode)
{
    m_pChildren[iIndex] = pNode;
}

TrieNode * TrieNode::GetNodeAtIndex(int iIndex)
{
    return m_pChildren[iIndex];
}

void TrieNode::SetId(int iId)
{
    m_iId = iId;
}

int TrieNode::GetId()
{
    return m_iId;
}