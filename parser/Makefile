.PHONY: all clean bison compile
all: bison

bison:
	@ bison -vd parser.y --warnings=all  

compile: 
	@ gcc parser.tab.c -o parser
	
clean: 
	@rm -f parser.tab.c parser parser.tab.h parser.output
