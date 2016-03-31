// TrieDataStructure.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Trie.h"
#include <iostream>
using namespace std;

int main()
{
    Trie T;    
    T.Insert("bhavesh");
    T.Insert("bharat");
    T.Insert("banana");

    cout << "Auto Complete Results for 'b'" << endl;
    T.AutoComplete("b");
    
    cout << "Auto Complete Results for 'bha'" << endl;
    T.AutoComplete("bha");
    
    cout << "Auto Complete Results for 'pc'" << endl;
    T.AutoComplete("pc");
    
    return 0;
}

int _tmain(int argc, _TCHAR* argv[])
{
	return main();
}

