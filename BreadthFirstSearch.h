#ifndef BREADTH_FIRST_SEARCH_H
#define BREADTH_FIRST_SEARCH_H
#include<list>
namespace BREADTH_FIRST_SEARCH {
	class BreadthFirstSearch {
	public:
		
		void bfs();
		void showTest();

	};
	class node {
	public:
		int value;
		std::list<node> connectnode;
		node();
		~node();
	};
}
#endif // !BREADTH_FIRST_SEARCH_H
