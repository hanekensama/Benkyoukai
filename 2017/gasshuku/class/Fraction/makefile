CXX = g++
CFLAGS = -Wall -O3 -std=c++11
TARGET = Fraction
SRCS = main.cpp
SRCS += Fraction.cpp
OBJS = $(SRCS:.cpp = .o)


$(TARGET): $(OBJS)
	$(CXX) -o $@ $^ $(CFLAGS)

$(OBJS): $(SRCS)
	$(CXX) -c $(SRCS) $(CFLAGS)

all: clean $(OBJS) $(TARGET)

clean:
	-rm -f $(OBJS) $(TARGET)
