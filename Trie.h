#ifndef trie_h
#define trie_h

#ifndef list_h
#define list_h
#include<list>
#endif

#ifndef string_h
#define string_h
#include<string>
#endif

#ifndef map_h
#define map_h
#include<map>
#endif

namespace trie {
	using namespace std;
	
	class node {
	public:
		map<char, node*> child;
		node() = default;
		bool endOfWord=false;
	};
	class Trie {
	public:
		void insert(const string&);
		bool find(const string&);
		bool remove(node&,const string&, int);
		bool remove(const string&);
		Trie();
	private:
		node* root;
	};
	
	void MainTest();
}
#endif