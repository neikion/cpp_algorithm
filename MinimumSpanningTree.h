#ifndef MinimumSpenningTree_H
#define MinimumSpenningTree_H
#ifndef vector_h
#define vector_h
#include<vector>
#endif // !vector

#ifndef iostream_h
#define iostream_h
#include<iostream>
#endif // !iostream

#ifndef list_h
#define list_h
#include<list>
#endif

#ifndef algorithm_h
#define algorithm_h
#include <algorithm>
#endif // !algorithm_h

namespace mst {
	using namespace std;

	class node {
	public:
		int value;
		node()=default;
		node(int);
	};
	class Line {
	public:
		node* node1;
		node* node2;
		int cost;
	};
	class MSTtree {
	public:
		void testMst();
		list<Line> getMST(int,list<Line>);
	};
}
#endif