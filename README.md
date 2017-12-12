# Decaf-Compiler
Compiler for Decaf Language

# Making Decaf
To make the project, run 'make' in the top level directory. 

# Running Decaf
./decaf <file_name> 

options:
  -p trace parsing 
  -s trace scanning
  
# Structure of the Project

This project is a frontend for the decaf language. A source program is scanned by a flex scanner, and transformed into tokens.
The tokens are passed into a bison parser, which transforms the tokens into in abstract syntax tree. The abstract syntax tree 
class supports a visitor pattern. The transformations on the abstract syntax tree are done through a visitor pattern. There are 
two implemented visitor classes. One traverses the AST keeping track of scope, and builds the symbol table. The second visitors 
resolves the symbols. This two pass approach is required because of forward references. 

# Project Details 
ast_node.hh -- virtual abstract syntax tree node 

ast.hh -- definitions for various nodes in the decaf AST 

scope.hh -- virtual class extended by nodes in the AST that represent scope

symbol.hh -- virtual class extended by nodes in the AST that are symbols 

symbol_table.hh -- map which stores symbols. Each scope has a symbol table, and an additional outer scope for global objects 
                   such as classes
visitor.hh -- visitor class interface

print_visitor.hh -- class implementing visitor that prints the names of each node in the AST. For debugging purposes

resolve_scope.hh -- class implementing visitor that builds the scope of scope nodes in AST. Also adds symbols to scope. 

build_symbols.hh -- class implementing visitor that resolves symbols. This second pass is required because of forward references. 

code_gen.hh      -- class implementing visitor that transforms the AST into LLVM code. This class is incomplete. It will become the final stage in building a decaf program. 

driver.hh        -- the driver class runs the scanning, parsing, and AST transformations. It also does error handling. 

decaf.cc         -- main program that processes arguments to decaf, and runs the driver 

scanner.l        -- flex object that tokenizes a decaf program

parser.yy        -- bison object that parses a decaf program

The decaf pipeline: 

decaf source --> scanner.l --> parser.yy --> resolve_scope --> build_symbols --> code_gen --> LLVM compiler

