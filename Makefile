Q=@

target := guppy
builddir := build
srcs := $(shell find "src" -type f -name '*.cc')
objs := $(patsubst %, $(builddir)/%.o, $(srcs))

CXXFLAGS += -std=gnu++17 -IolcPixelGameEngine
LDFLAGS += -lX11 -lGL -lpthread -lpng 

ifeq ($(RELEASE),1)
CXXFLAGS += -O3
else
CXXFLAGS += -Og -g
endif

.DEFAULT: all
.PHONY: all
all: $(target)

# Link
$(target): $(objs)
	@echo -e "  [LD] $@"
	$(Q)mkdir -p $(dir $@)
	$(Q)$(CXX) -o $@ $^ $(CXXFLAGS) $(LDFLAGS)

# Compile
$(builddir)/%.o: %
	@echo -e "  [CXX] $^"
	$(Q)mkdir -p $(dir $@)
	$(Q)$(CXX) -c -o $@ $^ $(CXXFLAGS)

.PHONY: run
run: $(target)
	$(Q)vblank_mode=0 ./$(target)

.PHONY: clean
clean:
	-$(Q)rm -fr $(objs) $(builddir) $(target) 2>/dev/null
