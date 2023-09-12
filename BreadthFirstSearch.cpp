#include"BreadthFirstSearch.h"
#include<iostream>
namespace BREADTH_FIRST_SEARCH {
	void BreadthFirstSearch::showTest() {
		node root;
		node node1(1,1);
		node node2(2,2);
		node node3(3,3);
		node node1_1(4,4);
		node node1_2(5,5);
		node node3_1(6,6);
		node node3_2(7,7);
		node node1_2_1(8,8);
		node node1_2_2(9,9);
		node node3_1_1(10,10);
		node node3_1_2(11,11);

		node1_2.connectnode.push_back(&node1_2_1);
		node1_2.connectnode.push_back(&node1_2_2);
		node3_1.connectnode.push_back(&node3_1_1);
		node3_1.connectnode.push_back(&node3_1_2);

		node1.connectnode.push_back(&node1_1);
		node1.connectnode.push_back(&node1_2);
		node3.connectnode.push_back(&node3_1);
		node3.connectnode.push_back(&node3_2);

		root.connectnode.push_back(&node1);
		root.connectnode.push_back(&node2);
		root.connectnode.push_back(&node3);
		
		//대상 노드 탐색
		std::vector<node> result = bfs(&root, 10);
		for (std::vector<node>::iterator it = result.begin(); it != result.end(); it++) {
			std::cout << it->value << "\n";
		}
	}

	std::vector<node> BreadthFirstSearch::bfs(node *root,int TargetValue) {
		std::queue<node*> visitable;
		std::vector<int> visited;
		visitable.push(root);
		while (!visitable.empty()) {
			
			node &target = *visitable.front();
			if (TargetValue == target.value) {
				return getBfsResult(target);
			}
			for (std::list<node*>::iterator it = target.connectnode.begin(); it != target.connectnode.end(); it++) {
				if (std::find_if(visited.begin(), visited.end(), [&it](int value) -> bool{
					return value == (*it)->id; 
					}
				) != visited.end()) 
				{
					continue;
				}
				(*it)->parent=&target;
				visitable.push(&(**it));
			}
			visited.push_back(target.id);
			visitable.pop();
		}
		return std::vector<node>();
	}
	
	std::vector<node> BreadthFirstSearch::getBfsResult(node& goal) {
		std::vector<node> result;
		node* target = &goal;
		while (target != NULL) {
			result.emplace_back(*target);
			target = target->parent;
		}
		std::reverse(result.begin(), result.end());
		return result;
	}

	node::node() : value(0),id(0),parent(NULL) {

	}
	node::node(int _id,int _value) : id(_id),value(_value),parent(NULL) {

	}
	node::~node() {
		value = 0;
		connectnode.clear();
	}
}