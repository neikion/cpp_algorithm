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

		node1_2.getConnectNode().push_back(node1_2_1);
		node1_2.getConnectNode().push_back(node1_2_2);
		node3_1.getConnectNode().push_back(node3_1_1);
		node3_1.getConnectNode().push_back(node3_1_2);

		node1.getConnectNode().push_back(node1_1);
		node1.getConnectNode().push_back(node1_2);
		node3.getConnectNode().push_back(node3_1);
		node3.getConnectNode().push_back(node3_2);

		root.getConnectNode().push_back(node1);
		root.getConnectNode().push_back(node2);
		root.getConnectNode().push_back(node3);

		std::vector<node> result = bfs(root, 10);
		for (std::vector<node>::iterator it = result.begin(); it != result.end(); it++) {
			std::cout << it->value << "\n";
		}
	}

	std::vector<node> BreadthFirstSearch::bfs(node &root,int TargetValue) {
		std::queue<node> visitable;
		std::vector<int> visited;
		visitable.emplace(&root);
		while (!visitable.empty()) {
			
			node &target = visitable.front().getOriginal();
			if (TargetValue == target.value) {
				return getBfsResult(target);
			}
			for (std::list<node>::iterator it = target.getConnectNode().begin(); it != target.getConnectNode().end(); it++) {
				if (std::find_if(visited.begin(), visited.end(), [&it](int value) -> bool{
					return value == it->id; 
					}
				) != visited.end()) 
				{
					continue;
				}
				it->parent=&target;
				visitable.emplace(&(*it));
				
			}
			visited.push_back(target.id);
			visitable.pop();
		}
		return std::vector<node>();
	}
	
	std::vector<node> BreadthFirstSearch::getBfsResult(node& goal) {
		std::vector<node> result;
		node* target = &goal.getOriginal();
		while (target != NULL) {
			result.emplace_back(*target);
			target = target->parent;
		}
		std::reverse(result.begin(), result.end());
		return result;
	}

	node::node() : value(0),id(0),parent(NULL),original(NULL) {

	}
	node::node(int _id,int _value) : id(_id),value(_value),parent(NULL),original(NULL) {

	}
	node::~node() {
		value = 0;
		if (original == NULL) {
			connectnode.clear();
		}
	}
	//deep copy
	node::node(const node& node)
	:id(node.id),value(node.value){
		node.parent != NULL ? parent = node.parent : parent = NULL;
		node.original != NULL ? original = node.original : original = NULL;
		if (node.connectnode.size() != 0) {
			connectnode = node.connectnode;
		}
	}
	node::node(node* inputnode) :id(0), value(0),original(inputnode) {
		parent = NULL;
	}
	std::list<node>& node::getConnectNode() {
		return original != NULL ? original->getConnectNode() : connectnode;
	}
	node& node::getOriginal() {
		return original != NULL ? original->getOriginal() : *this;
	}
}