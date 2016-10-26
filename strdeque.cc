#include <algorithm>
#include <cassert>
#include <climits>
#include <cstring>
#include <deque>
#include <iostream>
#include <map>
#include "strdeque.h"

namespace {
#ifndef NDEBUG
    const bool debug = true;
#else
    const bool debug = false;
#endif

    typedef std::deque<std::string> dequeString;

    std::map<unsigned long, dequeString>& deques() {
        static std::map<unsigned long, dequeString> ans;

        ans[0] = dequeString();

        return ans;
    }

    std::string returnName (unsigned long id) {
        std::string name = "";

        if (id == 0) {
            name = "the Empty Deque";
        } else {
            name = "deque " + std::to_string(id);
        }

        return name;
    }

    void printEntryMessage(const std::string &funcName, const std::string &dequeName) {
        std::cerr << funcName << "(" << dequeName << ")\n";
    }
}

unsigned long strdeque_new() {
    static unsigned long nextId = 1;

    assert (nextId != ULONG_MAX);

    if (debug) {
        printEntryMessage(__FUNCTION__, "");
        std::cerr << __FUNCTION__ << ": deque " << nextId << " created\n";
    }

    dequeString d;
    deques()[nextId] = d;

    return nextId++;
}

void strdeque_delete(unsigned long id) {
    if (debug) {
        printEntryMessage(__FUNCTION__, returnName(id));
    }

    auto it = deques().find(id);

    if (debug) {
        std::string name = returnName(id);
        std::cerr << __FUNCTION__ << ": ";

        if (id == 0) {
            std::cerr << "attempt to remove " << name << "\n";
        } else {
            if (it != deques().end()) {
                std::cerr << name << " deleted\n";
            } else {
                std::cerr << name << " does not exist\n";
            }
        }
    }

    if (id != 0 && it != deques().end()) {
        deques().erase(it);
    }
}

size_t strdeque_size(unsigned long id) {
    size_t size = 0;

    if (debug) {
        printEntryMessage(__FUNCTION__, returnName(id));
    }

    auto it = deques().find(id);

    if (id != 0 && it != deques().end()) {
        size = it->second.size();
    }

    if (debug) {
        std::string name = returnName(id);
        std::cerr << __FUNCTION__ << ": ";

        if (it != deques().end()) {
            std::cerr << name << " contains " << size << " elements\n";
        } else {
            std::cerr << name << " does not exist\n";
        }
    }

    return size;
}

void strdeque_insert_at(unsigned long id, size_t pos, const char *value) {
    if (debug) {
        std::cerr << __FUNCTION__ << "(" << returnName(id) << ", "
                  << pos << ", ";

        if (value == NULL) {
            std::cerr << "NULL";
        } else {
            std::cerr << "\"" << value << "\"";
        }

        std::cerr << ")\n";
    }

    auto it = deques().find(id);

    if (debug) {
        std::string name = returnName(id);
        std::cerr << __FUNCTION__ << ": ";

        if (id == 0) {
            std::cerr << "attempt to insert to " << name << "\n";
        } else {
            if (it != deques().end()) {
                if (value == NULL) {
                    std::cerr << "attempt to insert NULL into a deque\n";
                } else {
                    if (pos >= it->second.size()) {
                        std::cerr << name << ", element \""
                                  << value << "\" inserted at "
                                  << it->second.size() << "\n";
                    } else {
                        std::cerr << name << ", element \""
                                  << value << "\" inserted at "
                                  << pos << "\n";
                    }
                }
            } else {
                std::cerr << name << " does not exist\n";
            }
        }
    }

    if (id != 0 && it != deques().end() && value != NULL) {
        std::string s = std::string(value);

        if (pos >= it->second.size()) {
            it->second.push_back(s);
        } else {
            it->second.insert(it->second.begin() + pos, s);
        }
    }
}

void strdeque_remove_at(unsigned long id, size_t pos) {
    if (debug) {
        std::cerr << __FUNCTION__ << "(" << returnName(id) << ", "
                  << pos << ")\n";
    }

    auto it = deques().find(id);

    if (debug) {
        std::string name = returnName(id);
        std::cerr << __FUNCTION__ << ": ";

        if (id == 0) {
            std::cerr << "attempt to remove from " << name << "\n";
        } else {
            if (it != deques().end()) {
                if (pos < it->second.size()) {
                    std::cerr << name << ", element at " << pos << " removed\n";
                } else {
                    std::cerr << name << " does not contain element at "
                              << pos << "\n";
                }
            } else {
                std::cerr << name << " does not exist\n";
            }
        }
    }

    if (id != 0 && it != deques().end() && pos < it->second.size()) {
        it->second.erase(it->second.begin() + pos);
    }
}

const char *strdeque_get_at(unsigned long id, size_t pos) {
    if (debug) {
        std::cerr << __FUNCTION__ << "(" << returnName(id) << ", "
                  << pos << ")\n";
    }

    auto it = deques().find(id);

    if (debug) {
        std::string name = returnName(id);
        std::cerr << __FUNCTION__ << ": ";

        if (id == 0) {
            std::cerr << "attempt to get from " << name << "\n";
        } else {
            if (it != deques().end()) {
                if (pos < it->second.size()) {
                    std::cerr << name << ", element at " << pos << " is \""
                              << it->second[pos] << "\"\n";
                } else {
                    std::cerr << name << " does not contain element at "
                              << pos << "\n";
                }
            } else {
                std::cerr << name << " does not exist\n";
            }
        }
    }

    if (id != 0 && it != deques().end() && pos < it->second.size()) {
        return it->second[pos].c_str();
    }

    return NULL;
}

void strdeque_clear(unsigned long id) {
    if (debug) {
        printEntryMessage(__FUNCTION__, returnName(id));
    }

    auto it = deques().find(id);

    if (debug) {
        std::cerr << __FUNCTION__ << ": ";

        if (id == 0) {
            std::cerr << "attempt to clear " << returnName(id) << "\n";
        } else {
            if (it != deques().end()) {
                std::cerr << returnName(id) << " cleared\n";
            } else {
                std::cerr << returnName(id) << " does not exist\n";
            }
        }
    }

    if (id != 0 && it != deques().end()) {
        it->second.clear();
    }
}

int strdeque_comp(unsigned long id1, unsigned long id2) {
    if (debug) {
        std::cerr << __FUNCTION__ << "(" << returnName(id1) << ", "
                  << returnName(id2) << ")\n";
    }

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

    int result = 0;

    if (deque1 < deque2) {
        result = -1;
    } else if (deque1 == deque2) {
        result = 0;
    } else {
        result = 1;
    }

    if (debug) {
        std::cerr << __FUNCTION__ << ": ";
        std::string name1 = returnName(id1);
        std::string name2 = returnName(id2);

        if (it1 == deques().end()) {
            std::cerr << name1 << " does not exist\n";
        } else {
            if (it2 == deques().end()) {
                std::cerr << name2 << " does not exist\n";
            } else {
                std::cerr << "result of comparing " << name1 << " to "
                          << name2 << " is " << result << "\n";
            }
        }
    }

    return result;
}
