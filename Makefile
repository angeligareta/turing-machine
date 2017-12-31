CXX=g++
CXXFLAGS=-std=c++11

SRCDIR=src
BUILDDIR=build
EXECDIR=bin
TARGET=bin/turing-machine

SOURCES=$(shell find $(SRCDIR) -type f -name *.cpp)
OBJECTS=$(patsubst $(SRCDIR)/%.cpp,$(BUILDDIR)/%.o,$(SOURCES))

$(BUILDDIR)/%.o: $(SRCDIR)/%.cpp
	@mkdir -p $(EXECDIR)
	@mkdir -p $(BUILDDIR)
	@mkdir -p $(BUILDDIR)/Shared
	@mkdir -p $(BUILDDIR)/TM
	@echo " $(CXX) $(CXXFLAGS) $(INC) -c -o $@ $<"; $(CXX) $(CXXFLAGS) -c -o $@ $<

all: ${OBJECTS}
	$(CXX) $(CXXFLAGS) ${OBJECTS} -o ${TARGET}

clean: 
	rm -r ${BUILDDIR} ${TARGET}