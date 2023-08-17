#include"BreadthFirstSearch.h"
#include<iostream>
namespace BREADTH_FIRST_SEARCH {
	void BreadthFirstSearch::showTest() {
		node root;
		node node1(1);
		node node2(2);
		node node3(3);
		node node1_1(4);
		node node1_2(5);
		node node3_1(6);
		node node3_2(7);
		node node1_2_1(8);
		node node1_2_2(9);
		node node3_1_1(10);
		node node3_1_2(11);
		
		node1_2.connectnode.push_back(node1_2_1);
		node1_2.connectnode.push_back(node1_2_2);
		node3_1.connectnode.push_back(node3_1_1);
		node3_1.connectnode.push_back(node3_1_2);

		node1.connectnode.push_back(node1_1);
		node1.connectnode.push_back(node1_2);
		node3.connectnode.push_back(node3_1);
		node3.connectnode.push_back(node3_2);

		root.connectnode.push_back(node1);
		root.connectnode.push_back(node2);
		root.connectnode.push_back(node3);
		
		

		


		bfs(root, 10);
	}

	void BreadthFirstSearch::bfs(node root,int TargetValue) {
		std::queue<node> visitable;
		std::vector<int> visited;
		visitable.push(root);
		while (!visitable.empty()) {
			
			node &target = visitable.front();
			if (TargetValue == target.value) {
				std::vector<node> result=getBfsResult(target);
				for (std::vector<node>::iterator it = result.begin(); it != result.end(); it++) {
					std::cout << it->value<<"\n";
				}
				return;
			}
			std::cout << "now target : " << target.value <<" child size "<< target.connectnode.size()<<"\n";
			for (std::list<node>::iterator it = target.connectnode.begin(); it != target.connectnode.end(); it++) {
				std::cout <<"child overlap checking : " << it->value << "\n";
				if (std::find_if(visited.begin(), visited.end(), [&it](int value) -> bool{
					return value == it->value; 
					}
				) != visited.end()) 
				{
					std::cout << "continue"<<"\n";
					continue;
				}
				it->parent = &target;
				std::cout << "target child parent " << it->parent->value << "\n";
				visitable.push(*it);
			}
			if(target.parent!=NULL)
			std::cout<<"target parent value" << target.parent->value << "\n\n";
			target.id = visited.size()-1;
			visited.push_back(target.id);
			visitable.pop();
			//std::cout << "size" << visitable.size() << "\n";
		}
		//fail
	}
	
	std::vector<node> BreadthFirstSearch::getBfsResult(node goal) {
		std::vector<node> result;
		node* target = &goal;
		while (target != NULL) {
			result.push_back(*target);
			if (target->parent != NULL) {
				std::cout << target->parent->value;
			}
			target = target->parent;
		}
		std::reverse(result.begin(), result.end());
		return result;
	}

	node::node() : value(0),id(0),parent(NULL) {

	}
	node::node(int ivalue) : id(0),value(ivalue),parent(NULL) {

	}
	node::~node() {
		value = 0;
		connectnode.clear();
	}
}