CXX       := clang++
CXXFLAGS  := -std=c++17 -Iinclude -Wall -Wextra
SRCDIR    := src
BUILDDIR  := build

SOURCES   := $(shell find $(SRCDIR) -type f -name '*.cpp')
BINARIES  := $(patsubst %.cpp,$(BUILDDIR)/%,$(notdir $(SOURCES)))

.PHONY: all clean

all: $(BUILDDIR) $(BINARIES)

$(BUILDDIR):
	mkdir -p $(BUILDDIR)

define make_bin
$(BUILDDIR)/$(basename $(notdir $1)): $1 | $(BUILDDIR)
	$(CXX) $(CXXFLAGS) $$< -o $$@
endef

$(foreach src,$(SOURCES),$(eval $(call make_bin,$(src))))

clean:
	rm -rf $(BUILDDIR)