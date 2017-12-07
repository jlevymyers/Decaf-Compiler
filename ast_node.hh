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

class ast_node {
private: 
    std::vector<ast_node*> ast_children;
	int ast_id; 
	static int ast_count; 
public:
	void visit_children(visitor* v); 
	ast_node* get_child(int index);
	void add_child(ast_node* a);
	void insert_child(ast_node* a);
	void replace_child(int index, ast_node* a);
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