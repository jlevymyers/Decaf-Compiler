all: decaf

CC = g++
CXX = g++
CXXFLAGS = -I../flex/include   

decaf: driver.o parser.o scanner.o decaf.o ast.o visitor.o print_visitor.o #print_visitor.o #symbol_table.o
	$(CXX) $(CXXFLAGS)  -o decaf driver.o parser.o scanner.o decaf.o ast.o visitor.o print_visitor.o #symbol_table.o

driver.o: driver.cc driver.hh parser.hh ast.o visitor.o print_visitor.o # print_visitor.o #symbol_table.o
	$(CXX) $(CXXFLAGS)  -c driver.cc

parser.o: parser.cc parser.hh driver.hh visitor.o print_visitor.o
	$(CXX) $(CXXFLAGS) -c parser.cc

parser.cc parser.hh: parser.yy ast.o visitor.o print_visitor.o

	bison --defines=parser.hh -o parser.cc parser.yy

scanner.o: scanner.cc parser.hh driver.hh visitor.o print_visitor.o
	$(CXX) $(CXXFLAGS)  -c scanner.cc

scanner.cc: scanner.l visitor.o print_visitor.o
	flex -oscanner.cc scanner.l

decaf.o: decaf.cc visitor.o print_visitor.o
	$(CXX) $(CXXFLAGS) -c decaf.cc

ast.o: ast.hh ast.cc 
	$(CXX) $(CXXFLAGS)  -c ast.cc

print_visitor.o: ast.o visitor.o print_visitor.hh print_visitor.cc
	$(CXX) $(CXXFLAGS) -c print_visitor.cc 

visitor.o: visitor.hh visitor.cc ast.o
	$(CXX) $(CXXFLAGS) -c visitor.cc 

.PHONY: clean

clean:
	-rm *.o *.gch parser.hh parser.cc scanner.cc location.hh position.hh stack.hh decaf
