CXXFLAGS=-Wall -g -std=c++14
CFLAGS=$(CXXFLAGS)
CXX=g++
CC=g++

SRCS=strdeque.cc strdequeconst.cc
OBJS=$(SRCS:.cc=.o)

TEST_CSRCS=strdeque_test1.c 
TEST_COBJS=$(TEST_CSRCS:.c=.o)
TEST_CCSRCS=strdeque_test2a.cc strdeque_test2b.cc
TEST_CCOBJS=$(TEST_CCSRCS:.cc=.o)
TESTS=$(TEST_COBJS:.o=) $(TEST_CCOBJS:.o=)

all: $(TESTS)

tests: $(TEST_COBJS) $(TEST_CCOBJS)

strdeque_test1: $(OBJS) strdeque_test1.o
	$(CXX) $(CXXFLAGS) -o strdeque_test1 $(OBJS) strdeque_test1.o

strdeque_test2a: $(OBJS) strdeque_test2a.o
	$(CXX) $(CXXFLAGS) -o strdeque_test2a $(OBJS) strdeque_test2a.o

strdeque_test2b: $(OBJS) strdeque_test2b.o
	$(CXX) $(CXXFLAGS) -o strdeque_test2b $(OBJS) strdeque_test2b.o

NDEBUG_FLAG=-DNDEBUG

.PHONY: clean

clean:
	rm -rf $(OBJS) $(TEST_COBJS) $(TEST_CCOBJS) $(TESTS)
