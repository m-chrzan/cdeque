#include <algorithm>
#include <cstring>
#include <deque>
#include <map>
#include <iostream>
#include "strdeque.h"

#ifndef NDEBUG
	const static bool debug = true;
#else
	const static bool debug = false;
#endif

namespace {
    typedef std::deque<std::string> dequeString;
    const unsigned long maxLength = 1000000000;

    std::map<unsigned long, dequeString>& deques() {
        static std::map<unsigned long, dequeString> ans;
        return ans;
    }

    unsigned long nextId = 1;
}

std::string returnName (unsigned long id) {
	std::string name = "";
	if (id == 0)
		name = "the Empty Deque";
	else {
		name = "deque ";
		name += std::to_string(id);
	}
	//std::cerr << "return " << name << "\n";
	return name;
}

unsigned long strdeque_new() {
	if (debug) {
		std::cerr << "strdeque_new()\n";
		std::cerr << "strdeque_new: deque " << nextId << " created\n";
	}
	dequeString d;
	deques()[nextId] = d;
    return nextId++;
}

void strdeque_delete(unsigned long id) {
	std::string name = returnName(id);
	//std::cerr << name <<"\n\n";
	if (debug) {
		if (id == 0)
			std::cerr << "strdeque_delete(" << name << ")\n";
		else
			std::cerr << "strdeque_delete(" << id << ")\n";
		std::cerr << "strdeque_delete: ";
	}	
	
	if (id == 0) {
		if (debug)
			std::cerr << "attempt to remove " << name << "\n";
	}
	else {
		auto it = deques().find(id);
		if (it != deques().end()) {
			if (debug)
					std::cerr << name << " deleted\n";
			deques().erase(it);
		} else
			if (debug)
					std::cerr << name << " does not exist\n";
	}

}

size_t strdeque_size(unsigned long id) {
	auto it = deques().find(id);
	if (it != deques().end())
		return it->second.size();
	return (size_t) 0;
}

void strdeque_insert_at(unsigned long id, size_t pos, const char *value) {
	auto it = deques().find(id);
	if (it != deques().end() && value != NULL) {
		std::string s = std::string(value, 0, maxLength);
		if (pos >= it->second.size())
			it->second.push_back(s);
		else
			it->second.insert(it->second.begin() + pos, s);
	}
}

void strdeque_remove_at(unsigned long id, size_t pos) {
	auto it = deques().find(id);
	if (it != deques().end() && pos < it->second.size())
		it->second.erase(it->second.begin() + pos);
}

const char *strdeque_get_at(unsigned long id, size_t pos) {
	auto it = deques().find(id);
	if (it != deques().end() && pos < it->second.size())
		return it->second[pos].c_str();
    return NULL;
}

void strdeque_clear(unsigned long id) {
	auto it = deques().find(id);
	if (it != deques().end())
		it->second.clear();
}

int strdeque_comp(unsigned long id1, unsigned long id2) {
    auto first = deques().find(id1);
    auto second = deques().find(id2);
    if (first == deques().end()) {
		if (second == deques().end())
			return 0;
		else
			return -1;
	} else {
		if (second == deques().end()) {
			return 1;
        } else {
			size_t minSize = std::min(deques()[id1].size(), deques()[id2].size());
			for (int i = 0; i < (int) minSize; i++) {
				int result = deques()[id1][i].compare(deques()[id2][i]);
				if (result != 0)
					return result;
			}
			if (deques()[id1].size() < deques()[id2].size()) {
				return 1;
            } else {
				if (deques()[id1].size() == deques()[id2].size())
					return 0;
				return -1;
			}
		}
	}
}
