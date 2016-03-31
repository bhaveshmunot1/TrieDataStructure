#include "stdafx.h"
#include "Trie.h"

int Index(char c)
{
    return c - 'a';
}

char Character(int i)
{
    return i + 'a';
}

Trie::Trie()
{
    m_iCountOfNodes = 0;
    m_pTNRoot = GetNode();
}


Trie::~Trie()
{
}

void Trie::Insert(char InsertString[])
{
    TrieNode *pCrowler = m_pTNRoot;
    int iLength = strlen(InsertString);
    
    for (int i = 0; i < iLength; i++)
    {
        int iIndex = Index(InsertString[i]);
        if (pCrowler->IsNullChildrenAt(iIndex))
        {
            pCrowler->SetChildrenAt(iIndex, GetNode());            
        }
        pCrowler = pCrowler->GetNodeAtIndex(iIndex);
    }
    if ( ! pCrowler->GetId())
    {
        ++m_iCountOfNodes;
        pCrowler->SetId(m_iCountOfNodes);
    }
}

bool Trie::Search(char SearchString[])
{
    TrieNode *pCrowler = m_pTNRoot;
    int iLength = strlen(SearchString);
    bool bIsStringPresent = true;
    for (int i = 0; i < iLength; i++)
    {
        int iIndex = Index(SearchString[i]);
        if (pCrowler->IsNullChildrenAt(iIndex))
        {
            bIsStringPresent = false;
            break;
        }
        pCrowler = pCrowler->GetNodeAtIndex(iIndex);
    }
    if (bIsStringPresent)
    {
        bIsStringPresent = pCrowler->GetId();
    }
    return bIsStringPresent;
}

void Trie::AutoComplete(char PrefixString[])
{
    TrieNode *pCrowler = m_pTNRoot;
    int iLength = strlen(PrefixString);
    bool bIsStringPresent = true;
    for (int i = 0; i < iLength; i++)
    {
        int iIndex = Index(PrefixString[i]);
        if (pCrowler->IsNullChildrenAt(iIndex))
        {
            bIsStringPresent = false;
            break;
        }
        pCrowler = pCrowler->GetNodeAtIndex(iIndex);
    }
    if (bIsStringPresent)
    {
        PrintSuffixes(pCrowler, PrefixString);
    }
    else
    {
        printf("Sorry! Nos Suggestions for input!\n");
    }

}

TrieNode* Trie::GetNode()
{
    TrieNode *pNode = new TrieNode;    
    return pNode;
}

void Trie::PrintSuffixes(TrieNode* pRoot, char PrefixString[])
{
    TrieNode *pStart = pRoot;    
    if (pStart->GetId())
    {
        printf("%s\n", PrefixString);
        return;
    }
    for (int i = 0; i < CHARACTERS; i++)
    {
        if (!pStart->IsNullChildrenAt(i))        
        {                                          
                char sTemp[50]="";
                int iLen = strlen(PrefixString);
                strcpy_s(sTemp, 48, PrefixString);
                sTemp[iLen] = Character(i);
                sTemp[iLen+1] = 0;                
                PrintSuffixes(pStart->GetNodeAtIndex(i), sTemp);                
        }
    }    
}