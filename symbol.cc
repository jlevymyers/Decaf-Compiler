#include "symbol.hh"

using namespace ast;

int symbol::get_modifiers(){
    return this -> modifiers; 
}
void symbol::set_modifiers(int mod){
    this -> modifiers = mod; 
}

scope* symbol::get_define_scope(){
    return this -> define_scope;
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
