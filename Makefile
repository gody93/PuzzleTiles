#src = $(shell find . -type f -name "*.cpp")
src = $(wildcard *.cpp)
obj = $(src:.cpp=.o)

CXXFLAGS = -g
LDFLAGS = `sdl2-config --cflags --libs` -lSDL2_image

main: $(obj)
	$(CXX) -o $@ $^ $(LDFLAGS)

.PHONY: clean

clean:
	rm -f $(obj) main
