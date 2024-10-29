CXX = g++

CXXFLAGS = -Iinc -std=c++11 `pkg-config --cflags opencv4`
LDFLAGS = `pkg-config --libs opencv4` -lpthread -lrt

SRCS = src/main.cpp src/process.cpp
OBJS = $(patsubst src/%.cpp,$(BUILDDIR)/%.o,$(SRCS))

EXEC = test
BUILDDIR = build

$(shell mkdir -p $(BUILDDIR))

all: $(BUILDDIR)/$(EXEC)

$(BUILDDIR)/$(EXEC): $(OBJS)
	$(CXX) -o $@ $^ $(LDFLAGS)

$(BUILDDIR)/%.o: src/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS) $(BUILDDIR)/$(EXEC) $(BUILDDIR)
