# ifndef SYMBOL_HH
# define SYMBOL_HH

#include <string> 
#include <utility>
#include "ast_node.hh"
# include <stdlib.h>

namespace ast{

class scope;
class type_node;

class symbol : public ast_node {
private: 
	scope *define_scope; 
	int modifiers; 
	std::string sym_name; 
    symbol_type sym_type;
    symbol* associated_symbol;
public:
	symbol(int mod, std::string name, symbol_type sym_type): modifiers(mod), sym_name(name), sym_type(sym_type), ast_node(){}
	symbol(int mod, std::string name, symbol_type sym_type, ast_node *a): modifiers(mod), sym_name(name), sym_type(sym_type), ast_node(a){}
	symbol(int mod, std::string name, symbol_type sym_type, ast_node *a, ast_node *b): modifiers(mod), sym_name(name), sym_type(sym_type), ast_node(a,b){}
	symbol(int mod, std::string name, symbol_type sym_type, ast_node *a, ast_node *b, ast_node *c): modifiers(mod), sym_name(name), sym_type(sym_type), ast_node(a,b,c){}
	symbol(int mod, std::string name, symbol_type sym_type, ast_node *a, ast_node *b, ast_node *c, ast_node *d): modifiers(mod), sym_name(name), sym_type(sym_type), ast_node(a,b,c,d){}
	virtual ~symbol(){}
	virtual void accept(visitor *v) = 0;

    symbol_type get_symbol_type();

    void set_symbol(symbol* s);
	int get_modifiers();
	void set_modifiers(int mod);
	scope* get_define_scope();

	//OVERRODE BY CLASS_NODE 
	virtual scope* get_associated_scope(){
		return NULL;
	}

	void set_define_scope(scope *s);
	virtual type_node* get_type() = 0;
	std::string get_name();
};
};

#endif // ! SYMBOL_HH