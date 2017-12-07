#ifndef SCOPE_HH
# define SCOPE_HH

#include <string>
#include "ast_node.hh"
#include <utility>
# include <stdlib.h>

namespace ast {

class symbol;

class scope : public ast_node {
private:
	scope *parent_scope; 
	scope *super_scope;
	scope *outer_scope; 
public: 
	scope(): ast_node(){}
	scope(ast_node *a): ast_node(a){}
	scope(ast_node *a, ast_node *b): ast_node(a,b){}
	virtual ~scope(){}; 

	symbol *find(std::string name);
	symbol *find_scope(std::string name);
	symbol *find_method(std::string name); 

	void *add_symbol(symbol* sym);

	scope* get_super_scope();
	scope* get_parent_scope();

	void set_parent_scope(scope *s);
	void set_super_scope(scope *s);
};
};

#endif // ! SCOPE_HH