all: decaf

CC = g++
CXX = g++
CXXFLAGS = -I../flex/include -std=c++98

decaf: driver.o parser.o scanner.o decaf.o ast.o visitor.o print_visitor.o resolve_scope.o build_symbols.o symbol_table.o
	$(CXX) $(CXXFLAGS)  -o decaf *.o 

driver.o: driver.cc driver.hh parser.hh ast.o visitor.o print_visitor.o resolve_scope.o 
	$(CXX) $(CXXFLAGS)  -c driver.cc

parser.o: parser.cc parser.hh driver.hh visitor.o print_visitor.o resolve_scope.o ast.o
	$(CXX) $(CXXFLAGS) -c parser.cc

parser.cc parser.hh: parser.yy ast.o visitor.o print_visitor.o resolve_scope.o
	bison --defines=parser.hh -o parser.cc parser.yy

scanner.o: scanner.cc parser.hh driver.hh visitor.o print_visitor.o resolve_scope.o ast.o
	$(CXX) $(CXXFLAGS)  -c scanner.cc

scanner.cc: scanner.l visitor.o print_visitor.o resolve_scope.o ast.o
	flex -oscanner.cc scanner.l

decaf.o: decaf.cc visitor.o print_visitor.o resolve_scope.o ast.o
	$(CXX) $(CXXFLAGS) -c decaf.cc

ast.o: ast.hh ast.cc ast_node.o scope.o symbol.o 
	$(CXX) $(CXXFLAGS)  -c ast.cc

print_visitor.o: ast.o visitor.o print_visitor.hh print_visitor.cc
	$(CXX) $(CXXFLAGS) -c print_visitor.cc 

resolve_scope.o: ast.o symbol.o visitor.o resolve_scope.hh resolve_scope.cc
	$(CXX) $(CXXFLAGS) -c resolve_scope.cc 

build_symbols.o: ast.o visitor.o symbol_table.o build_symbols.hh build_symbols.cc
	$(CXX) $(CXXFLAGS) -c build_symbols.cc 

visitor.o: visitor.hh visitor.cc ast.o
	$(CXX) $(CXXFLAGS) -c visitor.cc 

ast_node.o: ast_node.hh ast_node.cc
	$(CXX) $(CXXFLAGS) -c ast_node.cc 

scope.o: scope.hh scope.cc ast_node.o symbol.o
	$(CXX) $(CXXFLAGS)  -c scope.cc

symbol.o: symbol.hh symbol.cc ast_node.o
	$(CXX) $(CXXFLAGS)  -c symbol.cc

symbol_table.o: ast.o symbol_table.cc symbol_table.hh
	$(CXX) $(CXXFLAGS)  -c symbol_table.cc

.PHONY: clean

clean:
	-rm *.o *.gch parser.hh parser.cc scanner.cc location.hh position.hh stack.hh decaf
