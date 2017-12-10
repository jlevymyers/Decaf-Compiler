#include "ast_node.hh"
#include "visitor.hh"

int ast_node::ast_count =  0;

void ast_node::add_child(ast_node *child){
	if(child != NULL){
		this -> ast_children.push_back(child);
	}
	else{
		std::cout << "attempted to push null child" << std::endl << std::endl;
	}
}

void ast_node::insert_child(ast_node *child){
	this -> ast_children.insert(this -> ast_children.begin(), child);
}

void ast_node::replace_child(int index, ast_node* a){
	this -> ast_children[index] = a; 
}

void ast_node::visit_children(visitor *v){
	std::vector<ast_node*>::iterator iter; 
	for(iter = this -> ast_children.begin(); iter != this -> ast_children.end(); iter++){
		v -> visit_ast(*iter);
	}
}

ast_node::ast_node() : ast_children(std::vector<ast_node*>()){
	this -> ast_id = ast_node::ast_count++;
}
ast_node::ast_node(ast_node *a) : ast_children(std::vector<ast_node*>()){
	this -> ast_id = ast_node::ast_count++;
	if(a != NULL){
		this -> add_child(a);
	}
}
ast_node::ast_node(ast_node *a, ast_node *b) : ast_children(std::vector<ast_node*>()){
	this -> ast_id = ast_node::ast_count++;
	if(a != NULL){
		this -> add_child(a);
	}
	if(b != NULL){
		this -> add_child(b);
	}
}
ast_node::ast_node(ast_node *a, ast_node *b, ast_node *c) : ast_children(std::vector<ast_node*>()){
	this -> ast_id = ast_node::ast_count++;
	if(a != NULL){
		this -> add_child(a);
	}
	if(b != NULL){
		this -> add_child(b);
	}
	if(c != NULL){
		this -> add_child(c);
	}
}
ast_node::ast_node(ast_node *a, ast_node *b, ast_node *c, ast_node *d): ast_children(std::vector<ast_node*>()){
	this -> ast_id = ast_node::ast_count++;
	if(a != NULL){
		this -> add_child(a);
	}
	if(b != NULL){
		this -> add_child(b);
	}
	if(c != NULL){
		this -> add_child(c);
	}
	if(d != NULL){
		this -> add_child(d);
	}
}

int ast_node::num_children(){
	return this -> ast_children.size();
}

ast_node* ast_node::get_child(int index){
	if(index >= 0 && index < this -> num_children()){
		return this -> ast_children[index];
	}
	else{
		return NULL;
	}
}