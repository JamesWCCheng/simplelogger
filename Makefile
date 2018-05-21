TARGETS := main
CXXFLAGS += -g -Wall -std=c++11

all: $(TARGETS)

clean:
	@rm -rf ./$(TARGETS)

run:
	./main