#ifndef BREADTH_FIRST_SEARCH_H
#define BREADTH_FIRST_SEARCH_H
#include<list>
#include <queue>
#include <algorithm>
namespace BREADTH_FIRST_SEARCH {
	class node {
	public:
		int getId();
		void setId(int);
		int getValue();
		node& getParent();
		std::list<node>& getConnectNode();
		void setParent(node&);
		node& getOriginal();
		node();
		node(int,int);
		~node();
		node(const node&);
		node(node*);
	private:
		int id;
		int value;
		node* parent;
		node* original;
		std::list<node> connectnode;
	};
	class BreadthFirstSearch {
	public:
		void bfs(node&,int);
		void showTest();
	private:
		std::vector<node> getBfsResult(node&);
	};
	
}
#endif // !BREADTH_FIRST_SEARCH_H
