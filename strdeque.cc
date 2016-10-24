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

        ans[0] = dequeString();

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

    if (id == 0) {
        name = "the Empty Deque";
    } else {
        name = std::to_string(id);
    }

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
    } else {
        name = "deque " + name;

        auto it = deques().find(id);
        if (it != deques().end()) {
            debugMessage += name + " deleted";
            deques().erase(it);
        } else {
            debugMessage += name + " does not exist";
        }
    }

    if (debug) {
        printDebugMessage(functionName, debugMessage);
    }
}

size_t strdeque_size(unsigned long id) {
    std::string name = returnName(id);
    std::string functionName = "strdeque_size";
    std::string message = "";
    size_t size = 0;

    if (debug) {
        printEntryMessage(functionName, name);
    }

    if (id == 0) {
        message = name + " contains " + std::to_string(size) + " elements";
    } else {
        name = "deque " + name;

        auto it = deques().find(id);
        if (it != deques().end()) {
            size = it->second.size();
            message = name + " contains " + std::to_string(size) + " elements ";
        } else {
            message = name + " does not exist ";
        }
    }

    if (debug) {
        printDebugMessage(functionName, message);
    }

    return size;
}

void strdeque_insert_at(unsigned long id, size_t pos, const char *value) {
    auto it = deques().find(id);
    if (it != deques().end() && value != NULL) {
        std::string s = std::string(value, 0, maxLength);

        if (pos >= it->second.size()) {
            it->second.push_back(s);
        } else {
            it->second.insert(it->second.begin() + pos, s);
        }
    }
}

void strdeque_remove_at(unsigned long id, size_t pos) {
	std::string functionName = "strdeque_remove_at";
	std::string name = returnName(id);
	std::string message = "";
	
	if (debug) {
		printEntryMessage(functionName, name);
	}
	
	if (id == 0) {
		message = "attempt to remove from " + name;
	} else {
		name = "deque " + name;
		auto it = deques().find(id);
		if (it != deques().end()) {
			if (pos < it->second.size()) {
				message = name + ", element at "
				               + std::to_string(pos) + " removed";
				it->second.erase(it->second.begin() + pos);
			} else {
				message = name + " does not contain element at "
				               + std::to_string(pos);
			}
		} else {
			message = name + " does not exist";
		}
	}
	
	if (debug) {
		printDebugMessage(functionName, message);
	}
}

const char *strdeque_get_at(unsigned long id, size_t pos) {
    auto it = deques().find(id);
    if (it != deques().end() && pos < it->second.size()) {
        return it->second[pos].c_str();
    }

    return NULL;
}

void strdeque_clear(unsigned long id) {
    std::string functionName = "strdeque_clear";
    std::string name = returnName(id);
    std::string message = "";
    
    if (debug) {
        printEntryMessage(functionName, name);
    }
        
    if (id == 0) {
        message = "attempt to clear " + name;
    } else {
        name = "deque " + name;
        auto it = deques().find(id);
        if (it != deques().end()) {
            message = name + " cleared";
            it->second.clear();
        } else {
            message = name + " does not exist";
        }
    }
    
    if (debug) {
        printDebugMessage(functionName, message);
    }
}

int strdeque_comp(unsigned long id1, unsigned long id2) {
    auto it1 = deques().find(id1);
    auto it2 = deques().find(id2);

    dequeString deque1;
    dequeString deque2;

    if (it1 == deques().end()) {
        deque1 = deques()[0];
    } else {
        deque1 = it1->second;
    }

    if (it2 == deques().end()) {
        deque2 = deques()[0];
    }  else {
        deque2 = it2->second;
    }

    if (deque1 < deque2) {
        return -1;
    } else if (deque1 == deque2) {
        return 0;
    } else {
        return 1;
    }
}
