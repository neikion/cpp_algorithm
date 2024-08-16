#include <iostream>

#define MY_MEMORY_DEBUG
#ifdef MY_MEMORY_DEBUG
#include <crtdbg.h>
//new 대신 DBG_NEW를 사용하면 해당 메모리는 메모리 누수시 출력창에 보고됨.
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
//아레 주석처럼 new를 써도 되나 권장하지는 않음.
//#define new new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#endif // 몇행에서 메모리 누수가 나는지 알려줌.


#include "EuclideanAlgorithm.h"
#include "BreadthFirstSearch.h"
#include "TreeIndex.h"
#include "MinimumSpanningTree.h"
#include "Trie.h"

using namespace EUCLIDEAN_ALGORITHM;
using namespace std;
int main()
{
	//최대 공약수 구하기
	/*
	Euclidean euclidean;
	cout<<euclidean.getGreatestCommonDivisor(5, 10)<<"\n";
	*/
	
	/*
	//메모리를 정보를 저장할 변수
	_CrtMemState s1,s2,s3;
	//메모리 상태 캡쳐
	_CrtMemCheckpoint(&s1);
	*/

	/*
	//bfs
	BREADTH_FIRST_SEARCH::BreadthFirstSearch bfs;
	bfs.showTest();
	*/

	/*
	//메모리 캡쳐 테스트
	int *a = new int[20];
	//메모리 상태 캡쳐
	_CrtMemCheckpoint(&s2);
	//s1과 s2를 비교하여 그 결과를 s3에 저장
	if (_CrtMemDifference(&s3, &s1, &s2)) {
		//s3를 출력
		_CrtMemDumpStatistics(&s3);
	}
	*/


	//트리 인덱스 테스트
	/*TreeIndex::Tree test;
	test.getParentTreeIndex();*/

	//mst 테스트
	/*
	mst::MSTtree test;
	test.testMst();
	*/

	//Trie 테스트
	trie::MainTest();

	//메모리 누수 확인
	_CrtDumpMemoryLeaks();
}