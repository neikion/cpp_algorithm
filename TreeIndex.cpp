#include<iostream>
#include "TreeIndex.h"

namespace TreeIndex {
	/// <summary>
	/// �ڽ��� �ε����� ã�ƺ��� �Լ�.
	/// </summary>
	void Tree::getChildTreeIndex() {
		int degree,result,select,childselect;
		//�ʹ� ū ���ڴ� ��� ��Ʈ�� ����ǹǷ� ������ ������ ��.
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
	/// �θ��� �ε����� ã�ƺ��� �Լ�
	/// </summary>
	void Tree::getParentTreeIndex() {
		int degree,result,select;
		//�ʹ� ū ���ڴ� ��� ��Ʈ�� ����ǹǷ� ������ ������ ��.
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