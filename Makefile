CPPFLAGS = CPPFLAGS ?= -std=c++17 -g -Wall -Wextra -Werror -g

build: xent

xent: beautiful.cpp
	$(CXX) $(CXXFLAGS) -o $@ $^

