#include"Trie.h"
#include <iostream>
namespace trie {

	void MainTest() {
		Trie t;
		t.insert("apple");
		t.insert("app");
		cout<<t.find("apple")<<endl;
		cout << t.find("app") << endl;
		cout << t.find("appe")<<endl<<endl;
		cout << t.remove("apple") << endl;
		cout << t.remove("appe") << endl;
		cout << t.find("apple") << endl;
		cout << t.find("app") << endl;
	}
	void Trie::insert(const string& value) {
		node* target = root;
		for (int i = 0; i < value.size(); i++) {
			if (target->child.find(value[i]) == target->child.end()) {
				target->child.insert({ value[i],new node() });
			}
			target = target->child[value[i]];
		}
		target->endOfWord = true;
	}

	bool Trie::find(const string& value) {
		node target = *root;
		string result = "";
		for (int i = 0; i < value.size(); i++) {
			if (target.child.find(value[i]) != target.child.end()) {
				result.push_back(value[i]);
				if (result == value) {
					if (target.child[value[i]]->endOfWord) {
						return true;
					}
					return false;
				}
				target = *target.child[value[i]];
			}
			else {
				return false;
			}
		}
		return false;
	}


	bool Trie::remove(node& target, const string& value, int index) {
		if (value.size() == index) {
			if (target.endOfWord) {
				target.endOfWord = false;
				return true;
			}
			return false;
		}
		else {
			if (target.child.find(value[index]) != target.child.end()) {
				//지워도 됨.
				if (remove(*target.child[value[index]], value, index+1)) {
					node* temp= target.child[value[index]];
					if (temp->child.size() == 0) {
						temp->child.erase(value[index]);
					}
				}
				else {
					//찾는 항목이 없었음.
					return false;
				}
			}
			else {
				//찾는 항목이 없음.
				return false;
			}
		}
		return true;
	}
	bool Trie::remove(const string& value) {
		return Trie::remove(*root, value, 0);
	}
	Trie::Trie() {
		root = new node();
	}
}