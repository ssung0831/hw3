CXX := g++
CXXFLAGS := -g -Wall --std=c++11
VALGRIND := valgrind --tool=memcheck --leak-check=yes
OBJS = llrec-test.o llrec.o 

#-----------------------------------------------------
# ADD target(s) to build your llrec-test executable
#-----------------------------------------------------
llrec-test: $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS)

llrec-test.o: llrec.h llrec-test.cpp
	$(CXX) $(CXXFLAGS) -o $@ -c llrec-test.cpp

llrec.o: llrec.h llrec.cpp
	$(CXX) $(CXXFLAGS) -o $@ -c llrec.cpp
	
clean:
	rm -f *.o rh llrec-test *~

.PHONY: clean 