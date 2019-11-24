target := guppy
srcs :=
srcs += main.cpp
objs := $(srcs:.cpp=.o)

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

$(target): $(objs)
	g++ -o $@ $^ $(CXXFLAGS) $(LDFLAGS)

.PHONY: run
run: $(target)
	vblank_mode=0 ./$(target)

.PHONY: clean
clean:
	-rm $(objs) $(target) 2>/dev/null
