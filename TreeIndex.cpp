#include<iostream>
#include "TreeIndex.h"

namespace TreeIndex {
	/// <summary>
	/// 자식의 인덱스를 찾아보는 함수.
	/// </summary>
	void Tree::getChildTreeIndex() {
		int degree,result,select,childselect;
		//너무 큰 숫자는 모두 루트와 연결되므로 임의의 제한을 줌.
		degree = getRandomInt(2, 5);
		std::cout << "degree" << degree << "\n";
		select = getRandomInt(1, TreeArraySize/degree);
		childselect = getRandomInt(1, degree);
		result = getChildNodeIndex(select, degree,childselect);
		std::cout << "select index : " << select <<" child select : "<<childselect << " child index : " << result << " child value : " << TreeArray[result] << "\n";
		select = getRandomInt(1, TreeArraySize/degree);
		childselect = getRandomInt(1, degree);
		result = getChildNodeIndex(select, degree,childselect);
		std::cout << "select index : " << select << " child select : " << childselect << " child index : " << result << " child value : " << TreeArray[result] << "\n";
	}
	/// <summary>
	/// 부모의 인덱스를 찾아보는 함수
	/// </summary>
	void Tree::getParentTreeIndex() {
		int degree,result,select;
		//너무 큰 숫자는 모두 루트와 연결되므로 임의의 제한을 줌.
		degree = getRandomInt(2, 5);
		std::cout << "degree" << degree << "\n";
		select = getRandomInt(10, 25);
		result = getParentNodeIndex(select, degree);
		std::cout <<"select index : "<<select << " parent index : " << result << " parent value : " << TreeArray[result] << "\n";
		select = getRandomInt(1, TreeArraySize);
		result = getParentNodeIndex(select, degree);
		std::cout << "select index : " << select << " parent index : " << result << " parent value : " << TreeArray[result] << "\n";
	}
	int Tree::getParentNodeIndex(int ChildIndex,int DegreeOfTree) {
		return floor((ChildIndex  - 1) / DegreeOfTree);
	}
	int Tree::getChildNodeIndex(int ParentIndex, int DegreeOfTree,int ChildOrder) {
		return floor((ParentIndex *DegreeOfTree))+ChildOrder;
	}

	Tree::Tree() {
		for (int i = 0; i < TreeArraySize; i++) {
			TreeArray[i] = i;
		}
		RandomGenerator = std::mt19937(std::random_device()());
	}
	/// <summary>
	/// return a random int
	/// </summary>
	int Tree::getRandomInt(int row,int high) {
		return std::uniform_int_distribution<int>(row,high)(RandomGenerator);
	}
}