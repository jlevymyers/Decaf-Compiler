#include "symbol.hh"
#include "ast.hh"


using namespace ast;

// symbol::symbol(int mod, std::string name, symbol_type sym_type): ast_node(){
// }
// symbol::symbol(int mod, std::string name, symbol_type sym_type, ast_node *a): ast_node(a){
// }
// symbol::symbol(int mod, std::string name, symbol_type sym_type, ast_node *a, ast_node *b): ast_node(a,b){
// }
// symbol::symbol(int mod, std::string name, symbol_type sym_type, ast_node *a, ast_node *b, ast_node *c): ast_node(a,b,c){
// }
// symbol::symbol(int mod, std::string name, symbol_type sym_type, ast_node *a, ast_node *b, ast_node *c, ast_node *d): ast_node(a,b,c,d){
// }




int symbol::get_modifiers(){
    return this -> modifiers; 
}
void symbol::set_modifiers(int mod){
    this -> modifiers = mod; 
}

scope* symbol::get_define_scope(){
    return this -> define_scope;
}

symbol_type symbol::get_symbol_type(){
    return this -> sym_type;
}

void symbol::set_define_scope(scope *s){
    this -> define_scope = s; 
}

type_node* symbol::get_type(){
    return NULL; 
}

std::string symbol::get_name(){
    return this -> sym_name;
}
