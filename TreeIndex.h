#ifndef TREE_INDEX_H
#define TREE_INDEX_H
#include <random>
namespace TreeIndex {

	class Tree {
	public:
		Tree();
		void getChildTreeIndex();
		void getParentTreeIndex();
	private:
		constexpr static int TreeArraySize = 50;
		int TreeArray[TreeArraySize];
		std::mt19937 RandomGenerator;
		int getChildNodeIndex(int, int,int);
		int getParentNodeIndex(int, int);
		int getRandomInt(int, int);
	};
}
#endif // !TREE_INDEX_H
