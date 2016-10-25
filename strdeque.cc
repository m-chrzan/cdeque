#include <algorithm>
#include <cstring>
#include <deque>
#include <map>
#include <iostream>

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

    unsigned long nextId = 1;

    std::string returnName (unsigned long id) {
        std::string name = "";

        if (id == 0) {
            name = "the Empty Deque";
        } else {
            name = "deque " + std::to_string(id);
        }

        return name;
    }

<<<<<<< HEAD
=======
    void printDebugMessage(const std::string &funcName, std::string &message) {
        std::cerr << funcName << ": " << message << '\n';
    }

>>>>>>> fd436601c54427723de7f94bdd9c52f8dc86db39
    void printEntryMessage(const std::string &funcName, const std::string &dequeName) {
        std::cerr << funcName << "(" << dequeName << ")\n";
    }
}

unsigned long strdeque_new() {
<<<<<<< HEAD
	
=======
>>>>>>> fd436601c54427723de7f94bdd9c52f8dc86db39
    if (debug) {
        printEntryMessage(__FUNCTION__, "");
        std::cerr << __FUNCTION__ << ": deque " + std::to_string(nextId) + " created\n";
    }

    dequeString d;
    deques()[nextId] = d;

    return nextId++;
}

void strdeque_delete(unsigned long id) {
<<<<<<< HEAD

    if (debug) {
        printEntryMessage(__FUNCTION__, returnName(id));
    }    
    
    auto it = deques().find(id);
    
     if (debug) {
		std::string name = returnName(id);
=======
    if (debug) {
        std::string name = returnName(id);
        printEntryMessage(__FUNCTION__, name);
    }    
    
    auto it = deques().find(id);
    if (it != deques().end()) {
        deques().erase(it);
    }

    if (debug) {
        std::string name = returnName(id);
>>>>>>> fd436601c54427723de7f94bdd9c52f8dc86db39
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
    
    if (it != deques().end()) {
        deques().erase(it);
    }
    
}

size_t strdeque_size(unsigned long id) {
    size_t size = 0;

    if (debug) {
        printEntryMessage(__FUNCTION__, returnName(id));
    }

    auto it = deques().find(id);
    
    if (it != deques().end()) {
        size = it->second.size();
    }
	
	if (debug) {
		std::string name = returnName(id);
		std::cerr << __FUNCTION__ << ": ";
		if (id == 0) {
			std::cerr << name << " contains " << std::to_string(size) 
		              << " elements\n";
		} else {
			if (it != deques().end()) {
				std::cerr << name << " contains " << std::to_string(size) 
		              << " elements\n";
			} else {
				std::cerr << name << " does not exist\n";
			}
		}
    }
    
    return size;
}

void strdeque_insert_at(unsigned long id, size_t pos, const char *value) {
	
	if (debug) {
		std::cerr << __FUNCTION__ << "(" << returnName(id) << ", "
		          << std::to_string(pos) << ", ";
		if (value == NULL)
			std::cerr << "NULL";
		else
			std::cerr << "\"" << std::string(value) << "\"";
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
								  << std::string(value) << "\" inserted at "
								  << std::to_string(it->second.size()) << "\n";
					} else {
						std::cerr << name << ", element \""
								  << std::string(value) << "\" inserted at "
								  << std::to_string(pos) << "\n";
					}
				}
			} else {
				std::cerr << name << " does not exist\n";
			}
		}
	}
	
    if (it != deques().end() && value != NULL) {
        std::string s = std::string(value);

        if (pos >= it->second.size()) {
            it->second.push_back(s);
        } else {
            it->second.insert(it->second.begin() + pos, s);
        }
    }
}

void strdeque_remove_at(unsigned long id, size_t pos) {
<<<<<<< HEAD
	
	if (debug) {
		std::cerr << __FUNCTION__ << "(" << returnName(id) << ", "
		          << std::to_string(pos) << ")\n";
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
					std::cerr << name << ", element at "
					          << std::to_string(pos) << " removed\n";
				} else {
					std::cerr << name << " does not contain element at "
					          << std::to_string(pos) << "\n";
				}
			} else {
				std::cerr << name << " does not exist\n";
			}
		}
	}
	
	if (it != deques().end() && pos < it->second.size()) {
		it->second.erase(it->second.begin() + pos);
=======
	if (debug) {
        std::string name = returnName(id);
		printEntryMessage(__FUNCTION__, name);
	}
	
    auto it = deques().find(id);

    if (debug) {
        std::string name = returnName(id);
        std::string message = "";
        if (id == 0) {
            message = "Attempt to remove from emptydeque.";
        } else {
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
		printDebugMessage(__FUNCTION__, message);
    }

	if (id != 0 && it != deques().end() && pos < it->second.size()) {
				it->second.erase(it->second.begin() + pos);
>>>>>>> fd436601c54427723de7f94bdd9c52f8dc86db39
	}
	
}

const char *strdeque_get_at(unsigned long id, size_t pos) {
	
	if (debug) {
		std::cerr << __FUNCTION__ << "(" << returnName(id) << ", "
		          << std::to_string(pos) << ")\n";
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
					std::cerr << name << ", element at "
					          << std::to_string(pos) << " is \""
					          << it->second[pos].c_str() << "\"\n";
				} else {
					std::cerr << name << " does not contain element at "
					          << std::to_string(pos) << "\n";
				}
			} else {
				std::cerr << name << " does not exist\n";
			}
		}
	}
	
    if (it != deques().end() && pos < it->second.size()) {
        return it->second[pos].c_str();
    }

    return NULL;
}

void strdeque_clear(unsigned long id) {
    std::string name = returnName(id);
    
    if (debug) {
        printEntryMessage(__FUNCTION__, name);
    }
        
    auto it = deques().find(id);
    
     if (debug) {
		std::cerr << __FUNCTION__ << ": ";
        if (id == 0) {
			std::cerr << "attempt to clear " << name << "\n";
		}
		else {
			if (it != deques().end()) {
				std::cerr << name << " cleared\n";
			} else {
				std::cerr << name << " does not exist\n";
			}
		}
    }
    
    if (it != deques().end()) {
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
				          << name2 << " is " << std::to_string(result) << "\n";
			}
		}
	}
	
	return result;
}
