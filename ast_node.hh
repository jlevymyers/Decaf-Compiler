#ifndef AST_NODE_HH
# define AST_NODE_HH

# include <string>
# include <vector>
# include <utility>
# include <iostream>
# include <stdlib.h>
# include <stddef.h>

class visitor;

namespace ast {

    enum mods {
	MOD_NONE = 0,
	MOD_STATIC,
	MOD_PUBLIC,
	MOD_PRIVATE,
	MOD_PROTECTED
};

enum symbol_type {
	SYM_NONE = 0, 
	SYM_FORMAL_ARG, 
	SYM_FIELD,
	SYM_LOCAL_VAR,
	SYM_CLASS,
	SYM_CTOR,
	SYM_METHOD
};

enum type_kind {
	TYPE_NONE = 0, 
	TYPE_BOOL,
	TYPE_CHAR, 
	TYPE_INT, 
	TYPE_VOID,
	TYPE_CLASS,
	TYPE_NULL,
	TYPE_INIT,
	TYPE_ARRAY,
	TYPE_METHOD,
	TYPE_META
};

class ast_node {
private: 
    std::vector<ast_node*> ast_children;
	int ast_id; 
	static int ast_count; 
protected: 
	void add_child(ast_node* a);
	void insert_child(ast_node* a);
	void replace_child(int index, ast_node* a);
public:
	void visit_children(visitor* v); 
	ast_node* get_child(int index);
	int num_children(); 
	virtual void accept(visitor* v) = 0;
	virtual ~ast_node();
	ast_node();
	ast_node(ast_node *a);
	ast_node(ast_node *a, ast_node *b);
	ast_node(ast_node *a, ast_node *b, ast_node *c); 
	ast_node(ast_node *a, ast_node *b, ast_node *c, ast_node *d);
};
};

#endif // ! AST_NODE_HH