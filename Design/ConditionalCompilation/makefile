RM = rm -f
CXXFLAGS = -Wall -g
CXX = c++
SRC = *.cpp
TEST1 = -DTEST_ADD
TEST2 = -DTEST_REMOVE

all: a.out

a.out: $(SRC)
	$(CXX) $(SRC) $(CXXFLAGS)

test1:
	$(CXX) $(SRC) $(CXXFLAGS) $(TEST1)

test2:
	$(CXX) $(SRC) $(CXXFLAGS) $(TEST1) $(TEST2)

clean:
	$(RM) a.out
