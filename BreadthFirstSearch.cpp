#include"BreadthFirstSearch.h"

namespace BREADTH_FIRST_SEARCH {
	void BreadthFirstSearch::showTest() {
		node root;
		node temp1;
		temp1.value = 1;
		node temp2;
		temp2.value = 2;
		root.connectnode.push_back(temp1);
		root.connectnode.push_back(temp2);
		root.connectnode.clear();
	}

	node::node() :value(0) {

	}
	node::~node() {
		value = 0;
		connectnode.clear();
	}
}