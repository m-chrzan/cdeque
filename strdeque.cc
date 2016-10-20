#include <cstring>
#include <map>
#include <deque>
#include <algorithm>
#include "strdeque.h"

typedef std::deque<std::string> dequeString;
const unsigned long maxLength = 1000000000;
std::map< unsigned long , dequeString> deques;
unsigned long nextId = 0;

unsigned long strdeque_new() {
	dequeString d;
	deques[nextId] = d;
    return nextId++;
}

void strdeque_delete(unsigned long id){
	auto it = deques.find(id);
	if (it != deques.end())
		deques.erase(it);
}

size_t strdeque_size(unsigned long id){
	auto it = deques.find(id);
	if (it != deques.end())
		return deques[id].size();
	return (size_t) 0;
}

void strdeque_insert_at(unsigned long id, size_t pos, const char *value) {
	auto it = deques.find(id);
	if (it != deques.end() && value != NULL) {
		std::string s = std::string(value, 0, maxLength);
		if (pos >= deques[id].size())
			deques[id].push_back(s);
		else
			deques[id].insert(deques[id].begin() + pos, s);
	}
}

void strdeque_remove_at(unsigned long id, size_t pos) {
	auto it = deques.find(id);
	if (it != deques.end() && pos < deques[id].size())
		deques[id].erase(deques[id].begin() + pos);
}

const char *strdeque_get_at(unsigned long id, size_t pos) {
	auto it = deques.find(id);
	if (it != deques.end() && pos < deques[id].size())
		return deques[id][pos].c_str();
    return NULL;
}

void strdeque_clear(unsigned long id) {
	auto it = deques.find(id);
	if (it != deques.end())
		deques[id].clear();
}

int strdeque_comp(unsigned long id1, unsigned long id2) {
    auto first = deques.find(id1);
    auto second = deques.find(id2);
    if (first == deques.end()) {
		if (second == deques.end())
			return 0;
		else
			return -1;
	} else {
		if (second == deques.end())
			return 1;
		else {
			size_t minSize = std::min(deques[id1].size(), deques[id2].size());
			for (int i = 0; i < (int) minSize; i++) {
				int result = deques[id1][i].compare(deques[id2][i]);
				if (result != 0)
					return result;
			}
			if (deques[id1].size() < deques[id2].size())
				return 1;
			else {
				if (deques[id1].size() == deques[id2].size())
					return 0;
				return -1;
			}
		}
	}
}
