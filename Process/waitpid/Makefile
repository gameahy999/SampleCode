CC = gcc
CXX = g++
CFLAGS = -g
PROG = tst waitnone

.PHONY = all clean

all : $(PROG)
	@echo "Job's done!"

%.o : %.cpp
	$(CXX) -c $(CFLAGS) $^ -o $@

# TODO: add the .o files here
tst : main.o
	$(CXX) $(CFLAGS) $^ -o $@

waitnone : waitnone.o
	$(CXX) $(CFLAGS) $^ -o $@

clean :
	-rm -rf *.o
	-rm -rf $(PROG)
