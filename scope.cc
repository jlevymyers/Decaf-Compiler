#include "scope.hh"

using namespace ast;

scope* scope::get_super_scope(){
	return this -> super_scope; 
}
scope* scope::get_parent_scope(){
	return this -> parent_scope;
}

void scope::set_super_scope(scope *s){
	 this -> super_scope = s; 
}
void scope::set_parent_scope(scope *s){
	 this -> parent_scope = s;
}