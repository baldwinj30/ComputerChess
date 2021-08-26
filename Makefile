# Set up basic information
CXX = g++
SRCDIR = src
INCLUDE = -I include
BUILDDIR = build
TARGET = bin/chess
CXXFLAGS = -g

# Find the sources
SOURCES = $(shell find $(SRCDIR) -type f -name *.cpp)
OBJECTS = $(patsubst $(SRCDIR)/%,$(BUILDDIR)/%,$(SOURCES:.cpp=.o))

# Link
$(TARGET): $(OBJECTS)
	@echo " Linking...";
	$(CXX) $^ -o $(TARGET)

# Build
$(BUILDDIR)/%.o: $(SRCDIR)/%.cpp
	@echo "Building...";
	@mkdir -p $(BUILDDIR);
	$(CXX) $(CXXFLAGS) $(INC) -c -o $@ $<

clean:
	@echo " Cleaning..."; 
	@echo " $(RM) -r $(BUILDDIR) $(TARGET)"; $(RM) -r $(BUILDDIR) $(TARGET)
