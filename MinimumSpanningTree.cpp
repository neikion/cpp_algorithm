#include"MinimumSpanningTree.h"

using namespace mst;
node::node(int invalue) :value(invalue) {

}
void MSTTree::init() {
	const int nodesize = 5;
	node node[nodesize]{0,1,2,3,4};
	list<Line> lines;
	Line line;
	line.node1 = &node[0];
	line.node2 = &node[1];
	line.cost = 2;
	lines.push_back(line);
	
	line.node1 = &node[0];
	line.node2 = &node[2];
	line.cost = 1;
	lines.push_back(line);

	line.node1 = &node[1];
	line.node2 = &node[2];
	line.cost = 3;
	lines.push_back(line);

	line.node1 = &node[3];
	line.node2 = &node[2];
	line.cost = 3;
	lines.push_back(line);

	line.node1 = &node[2];
	line.node2 = &node[4];
	line.cost = 1;
	lines.push_back(line);

	line.node1 = &node[3];
	line.node2 = &node[4];
	line.cost = 2;
	lines.push_back(line);

	list<Line> result=getMST(nodesize, lines);

	cout << endl;
	for (list<Line>::iterator it = result.begin(); it != result.end(); it++) {
		cout << it->cost<<"\n";
	}
}
list<Line> MSTTree::getMST(int nodesize,list<Line> linelist) {
	int check[6] = {0};
	list<Line> result;
	for (int target = 0; target < nodesize; target++) {
		list<Line> lines;
		for (list<Line>::iterator it = linelist.begin(); it != linelist.end(); it++) {
			if (it->node1->value == target || it->node2->value==target) {
				lines.push_back(*it);
			}
		}
		//minvalue check
		int minvalue=99999;
		Line* checkline=NULL;
		for (list<Line>::iterator it = lines.begin(); it != lines.end(); it++) {
			if (it->cost < minvalue) {
				//overlap check
				if (find_if(result.begin(), result.end(), [it](Line value)-> bool{
					if (value.node1->value == it->node1->value) {
						if (value.node2->value == it->node2->value) {
							return true;
						}
					}else if (value.node2->value == it->node1->value) {
						if (value.node1->value == it->node2->value) {
							return true;
						}
					}
					return false;
				}) == result.end()) {
					minvalue = it->cost;
					checkline = &(*it);
				}
			}
		}
		
		if (checkline!=NULL) {
			result.push_back(*checkline);
		}
	}

	return result;
}
