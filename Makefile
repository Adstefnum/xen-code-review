CPPFLAGS = CPPFLAGS ?= -std=c++17 -g -Wall -Wextra -Werror -g

build: xent

pr-2: beautiful.cpp
	$(CXX) $(CXXFLAGS) -o $@ $^

