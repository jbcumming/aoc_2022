CXXFLAGS = -g -Wall -Werror -std=c++2a
LDLIBS =

PRGM  = ./bin/day2
SRCS := $(wildcard *.cpp)
OBJS := $(SRCS:.cpp=.o)
DEPS := $(OBJS:.o=.d)

.PHONY: all clean

all: $(PRGM)

$(PRGM): $(OBJS)
	$(CXX) $(OBJS) $(LDLIBS) -o $@

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -MMD -MP -c $< -o $@

clean:
	rm -rf $(OBJS) $(DEPS) $(PRGM)

-include $(DEPS)
