#ifndef SCOPE_HH
# define SCOPE_HH

#include <string>
#include "ast_node.hh"
#include <utility>
# include <stdlib.h>

class symbol_table;

namespace ast {

class symbol;

class scope : public ast_node {
private:
	scope *parent_scope; 
	scope *super_scope;
	scope *outer_scope; 
    symbol_table *sym_table;
public: 
	scope();
	scope(ast_node *a);
	scope(ast_node *a, ast_node *b);

	virtual ~scope(){} 

    std::vector<ast_node*> get_children();

	symbol *find(std::string name);
	symbol *find_scope(std::string name);
	symbol *find_method(std::string name); 

	void add_symbol(symbol* sym);

	scope* get_super_scope();
	scope* get_parent_scope();
    scope* get_outer_scope();

	void set_parent_scope(scope *s);
	void set_super_scope(scope *s);
    void set_outer_scope(scope *s);

    symbol_table* get_table();
};
};

#endif // ! SCOPE_HH