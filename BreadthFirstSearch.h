#ifndef BREADTH_FIRST_SEARCH_H
#define BREADTH_FIRST_SEARCH_H
#include<list>
#include <queue>
#include <algorithm>
namespace BREADTH_FIRST_SEARCH {
	class node {
	public:
		int id;
		int value;
		node* parent;
		std::list<node> connectnode;
		std::list<node>& getConnectNode();
		node& getOriginal();
		node();
		node(int,int);
		~node();
		node(const node&);
		node(node*);
	private:
		node* original;
	};
	class BreadthFirstSearch {
	public:
		std::vector<node> bfs(node&,int);
		void showTest();
	private:
		std::vector<node> getBfsResult(node&);
	};
	
}
#endif // !BREADTH_FIRST_SEARCH_H
