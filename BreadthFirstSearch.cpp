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

		bfs(root, 11);
	}

	void BreadthFirstSearch::bfs(node &root,int TargetValue) {
		std::queue<node> visitable;
		std::vector<int> visited;
		visitable.emplace(&root);
		while (!visitable.empty()) {
			
			node &target = visitable.front().getOriginal();
			if (TargetValue == target.getValue()) {
				std::vector<node> result=getBfsResult(target);
				for (std::vector<node>::iterator it = result.begin(); it != result.end(); it++) {
					std::cout << it->getValue()<<"\n";
				}
				return;
			}
			std::cout << "now target : " << target.getValue() <<" child size "<< target.getConnectNode().size() << "\n";
			for (std::list<node>::iterator it = target.getConnectNode().begin(); it != target.getConnectNode().end(); it++) {
				std::cout <<"child overlap checking : " << it->getId() << "\n";
				if (std::find_if(visited.begin(), visited.end(), [&it](int value) -> bool{
					return value == it->getId(); 
					}
				) != visited.end()) 
				{
					std::cout << "continue"<<"\n";
					continue;
				}
				it->setParent(target.getOriginal());
				std::cout << "target child parent " << it->getParent().getValue()<< "\n";
				visitable.emplace(&(*it));
				
			}
			visited.push_back(target.getId());
			visitable.pop();
			//std::cout << "size" << visitable.size() << "\n";
			std::cout << "--------------------\n\n";
		}
		//fail
	}
	
	std::vector<node> BreadthFirstSearch::getBfsResult(node& goal) {
		std::vector<node> result;
		node* target = &goal;
		while (target != NULL) {
			result.emplace_back(target);
			target = &(target->getParent());
		}
		std::reverse(result.begin(), result.end());
		return result;
	}

	node::node() : value(0),id(0),parent(NULL),original(NULL) {

	}
	node::node(int inid,int invalue) : id(inid),value(invalue),parent(NULL),original(NULL) {

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
	int node::getId() {
		return original != NULL ? original->getId() : id;
	}
	void node::setId(int value) {
		if (original != NULL) {
			return original->setId(value);
			
		}
		id = value;
	}
	int node::getValue() {
		return original != NULL ? original->getValue() : value;
	}
	node& node::getParent() {
		return original != NULL ? original->getParent() : *parent;
	}
	void node::setParent(node& value) {
		if (original != NULL) {
			return original->setParent(value);

		}
		parent = &value;
	}
	std::list<node>& node::getConnectNode() {
		return original != NULL ? original->getConnectNode() : connectnode;
	}
	node& node::getOriginal() {
		return original != NULL ? original->getOriginal() : *this;
	}
}