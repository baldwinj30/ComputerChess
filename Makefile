# Set up basic information
CXX = g++
SRCDIR = src
INCLUDE = -I include
BUILDDIR = build
TARGET = bin/chess

# Find the sources
SOURCES = $(shell find $(SRCDIR) -type f -name *.cpp)
OBJECTS = $(patsubst $(SRCDIR)/%,$(BUILDDIR)/%,$(SOURCES:.cpp=.o))

# Link
$(TARGET): $(OBJECTS)
  @echo " Linking..."
  $(CC) $^ -o $(TARGET) $(LIB)

$(BUILDDIR)/%.o: $(SRCDIR)/%.cpp)
  @echo "Building..."
  @mkdir -p $(BUILDDIR)
  $(CC) $(CFLAGS) $(INC) -c -o $@ $<

clean:
  @echo " Cleaning..."; 
  @echo " $(RM) -r $(BUILDDIR) $(TARGET)"; $(RM) -r $(BUILDDIR) $(TARGET)
