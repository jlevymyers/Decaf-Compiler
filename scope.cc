#include "scope.hh"
# include "symbol_table.hh"
# include "symbol.hh"
# include "ast.hh"


using namespace ast;

scope::scope(): ast_node(){
    this -> sym_table = new symbol_table();
}
scope::scope(ast_node *a): ast_node(a){
    this -> sym_table = new symbol_table();
}
scope::scope(ast_node *a, ast_node *b): ast_node(a,b){
    this -> sym_table = new symbol_table();
}

scope* scope::get_super_scope(){
	return this -> super_scope; 
}

scope* scope::get_parent_scope(){
	return this -> parent_scope;
}

scope* scope::get_outer_scope(){
	return this -> outer_scope;
}

void scope::set_outer_scope(scope *s){
    this -> outer_scope = s;
    this -> sym_table -> set_outer_scope(s); 
}

void scope::set_super_scope(scope *s){
	 this -> super_scope = s; 
     this -> sym_table -> set_super_scope(s);
}

void scope::set_parent_scope(scope *s){
	 this -> parent_scope = s;
     this -> sym_table -> set_parent_scope(s);
}

void scope::add_symbol(symbol *s){
    this -> sym_table -> add_symbol(s);
}

symbol_table* scope::get_table(){
    return this -> sym_table;
}


symbol* scope::find_scope(std::string name){
    std::cout << "finding field/variable" << std::endl; 
    if(this -> sym_table != NULL)
        return this -> sym_table -> find_scope(name);
    else{
        return NULL;
    }
}


symbol* scope::find_method(std::string name){
    std::cout << "finding method" << std::endl; 
    if(this -> sym_table != NULL)
        return this -> sym_table -> find_method(name);
    else{
        return NULL;
    }
}

symbol* scope::find(std::string name){
    std::cout << "finding global" << std::endl; 
    if(this -> sym_table != NULL)
        return this -> sym_table -> find(name);
    else{
        return NULL;
    }
}