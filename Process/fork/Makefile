CC = gcc
CXX = g++
CFLAGS = -g
PROG = tst multifork

.PHONY = all clean

all : $(PROG)
	@echo "Job's done!"

%.o : %.cpp
	$(CXX) -c $(CFLAGS) $^ -o $@

# TODO: add the .o files here
tst : main.o
	$(CXX) $(CFLAGS) $^ -o $@

multifork: multi_fork.o
	$(CXX) $(CFLAGS) $^ -o $@

clean :
	-rm -rf *.o
	-rm -rf $(PROG)
