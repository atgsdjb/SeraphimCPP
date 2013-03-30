.PHONY : all
%.o : %.cxx
	g++ -c $< -o $@
all : seraph
seraph:seraphim.o
	gcc $< -o $@

