TARGETS := main
CXXFLAGS += -g -Wall -std=c++11 -pthread

all: $(TARGETS)

clean:
	@rm -rf ./$(TARGETS)

run:
	./main