# the compiler: gcc for C program, define as g++ for C++
CC = g++

RM = rm -f

DEBUG=-DNS3_LOG_ENABLE

LIBS = ns3-applications ns3-core ns3-internet ns3-mobility ns3-network ns3-olsr ns3-aodv ns3-visualizer ns3-flow-monitor

# compiler flags:
#  -g    adds debugging information to the executable file
#  -Wall turns on most, but not all, compiler warnings
CFLAGS  = -g -Wall -Wextra $(shell pkg-config --cflags $(LIBS))
LDFLAGS=$(shell pkg-config --libs $(LIBS))

# the build target executable:
OLSR = OLSR
AODV = AODV

HEADER = myapp.h

$(OLSR): $(HEADER) lab2-olsr.cc
	$(CC) $(DEBUG) $(CFLAGS) $(LDFLAGS) -o $@ lab2-olsr.cc

$(AODV): $(HEADER) lab2-aodv.cc
	$(CC) $(DEBUG) $(CFLAGS) $(LDFLAGS) -o $@ lab2-aodv.cc

all: $(OLSR) $(AODV)

clean:
	$(RM) $(OLSR) $(AODV)