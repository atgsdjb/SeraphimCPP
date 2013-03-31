.PHONY : all
CXXLDFS := -lstdc++
%.o : %.cxx
	g++ -c  $< -o $@
all : seraph
seraph:seraphim.o
	gcc $<  $(CXXLDFS)   -o $@

