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

    std::ostream& cerr() {
        static std::ios_base::Init i = std::ios_base::Init();

        return std::cerr;
    }
}

std::string returnName (unsigned long id) {
	std::string name = "";
	if (id == 0)
		name = "the Empty Deque";
	else
		name = std::to_string(id);
	return name;
}

void printDebugMessage(std::string &funcName, std::string &message) {
	cerr() << funcName << ": " << message << '\n';
}

void printEntryMessage(const std::string &funcName, const std::string &dequeName) {
	cerr() << funcName << "(" << dequeName << ")\n";
}
unsigned long strdeque_new() {
	std::string functionName = "strdeque_new";
	if (debug) {
		printEntryMessage(functionName, "");
		std::string message = "deque " + std::to_string(nextId) + " created";
		printDebugMessage(functionName, message);
	}
	dequeString d;
	deques()[nextId] = d;
    return nextId++;
}

void strdeque_delete(unsigned long id) {
	std::string name = returnName(id);
	std::string debugMessage = "";
	std::string functionName = "strdeque_delete";
	if (debug) {
		printEntryMessage(functionName, name);
	}	
	
	if (id == 0) {
		debugMessage += "attempt to remove " + name;
	}
	else {
		name = "deque " + name;
		auto it = deques().find(id);
		if (it != deques().end()) {
			debugMessage += name + " deleted";
			deques().erase(it);
		} else
			debugMessage += name + " does not exist";
	}
	if (debug)
		printDebugMessage(functionName, debugMessage);
}

size_t strdeque_size(unsigned long id) {
	std::string name = returnName(id);
	std::string functionName = "strdeque_size";
	std::string message = "";
	size_t size = 0;
	if (debug)
		printEntryMessage(functionName, name);
	if (id == 0)
		message = name + " contains " + std::to_string(size) + " elements";
	else {
		auto it = deques().find(id);
		name = "deque " + name;
		if (it != deques().end()) {
			size = it->second.size();
			message = name + " contains " + std::to_string(size) + " elements ";
		} else
			message = name + " does not exist ";
	}
	if (debug)
		printDebugMessage(functionName, message);
	return size;
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
	std::string functionName = "strdeque_clear";
	std::string name = returnName(id);
	std::string message = "";
	
	if (debug)
		printEntryMessage(functionName, name);
		
	if (id == 0)
		message = "attempt to clear " + name;
	else {
		name = "deque " + name;
		auto it = deques().find(id);
		if (it != deques().end()) {
			message = name + " cleared";
			it->second.clear();
		} else
			message = name + " does not exist";
	}
	if (debug)
		printDebugMessage(functionName, message);
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
