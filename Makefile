# 1. Değişkenler
CXX      = g++
CXXFLAGS = -Wall -I./src  # -I./src sayesinde #include "view/view.hpp" diyebilirsin
LIBS     = -lncurses
TARGET   = chickens

SRCS = ./src/view/view.cpp \
       ./src/models/models.cpp \
       ./src/controller/controller.cpp \
       ./src/main.cpp


OBJS = $(SRCS:.cpp=.o)


.PHONY: all clean run

all: $(TARGET)


$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(TARGET) $(LIBS)


%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)