# include "resolve_scope.hh"

resolve_scope::resolve_scope(): visitor(){
    this -> resolve_outer_scope = new outer_scope();
}
resolve_scope::~resolve_scope(){}


void resolve_scope::push_scope(scope* s){
    this -> scope_stack.push(s);
}
void resolve_scope::pop_scope(scope *s){
    this -> scope_stack.pop(); 
}
scope* resolve_scope::get_current_scope(){
    return this -> scope_stack.top();
}

scope* resolve_scope::get_outer_scope(){
    return this -> resolve_outer_scope;
}


void resolve_scope::visit_children(ast_node* n){
    n -> visit_children(this);
}

void resolve_scope::visit_ast(ast_node* n){
    n -> accept(this);
}

void resolve_scope::visit_outer_scope(outer_scope *n){
    visit_children(n);
}

void resolve_scope::visit_class_list(class_list* n){
    visit_children(n);
}
void resolve_scope::visit_class_node(class_node *n){
    this -> get_outer_scope() -> add_symbol(n);
    visit_children(n);
} 

void resolve_scope::visit_member_list(member_list *n){
    n -> set_parent_scope(this -> resolve_outer_scope);    
    n -> set_super_scope(n -> get_super_scope());
    n -> set_outer_scope(this -> resolve_outer_scope);
    std::cout << "resolving member scope" << std::endl;
    this -> scope_stack.push(n);
    visit_children(n);
    this -> scope_stack.pop();
}

void resolve_scope::visit_super_node(super_node *n){
    visit_children(n);
}
void resolve_scope::visit_field_decl(field_decl *n){
    visit_children(n);
}
void resolve_scope::visit_field_node(field_node *n){
    this -> get_current_scope() -> add_symbol(n);
    visit_children(n);
}
void resolve_scope::visit_method_node(method_node *n){
    this -> get_current_scope() -> add_symbol(n);
    visit_children(n);
}
void resolve_scope::visit_method_body(method_body *n){
    n -> set_super_scope(NULL);
    n -> set_parent_scope(this -> get_current_scope()); 
    n -> set_outer_scope(this -> resolve_outer_scope);
    std::cout << "resolving method scope" << std::endl;
    this -> push_scope(n);
    visit_children(n);
    this -> pop_scope(n);
}
void resolve_scope::visit_constructor_node(constructor_node *n){
    this -> get_current_scope() -> add_symbol(n);
    visit_children(n);
}
void resolve_scope::visit_formal_list(formal_list *n){
    visit_children(n);
}
void resolve_scope::visit_formal_node(formal_node *n){
    this -> get_current_scope() -> add_symbol(n);
    visit_children(n);
}
void resolve_scope::visit_type_node(type_node *n){
    visit_children(n);
}
void resolve_scope::visit_class_type(class_type *n){
    visit_children(n);
}
void resolve_scope::visit_array_type_node(array_type_node *n){
    visit_children(n);
}
void resolve_scope::visit_primative_int(primative_int *n){
    visit_children(n);
}
void resolve_scope::visit_primative_bool(primative_bool *n){
    visit_children(n);
} 
void resolve_scope::visit_primative_char(primative_char *n){
    visit_children(n);
}
void resolve_scope::visit_primative_void(primative_void *n){
    visit_children(n);
}
void resolve_scope::visit_null_node(null_node *n){
    visit_children(n);
}
void resolve_scope::visit_init_node(init_node *n){
    visit_children(n);
}
void resolve_scope::visit_meta_node(meta_node *n){
    visit_children(n);
}
void resolve_scope::visit_statement_list(statement_list *n){
    visit_children(n);
}

void resolve_scope::visit_empty_stat(empty_stat *n){
    visit_children(n);
}

void resolve_scope::visit_decl_stat(decl_stat *n){
    visit_children(n);
}
void resolve_scope::visit_local_node(local_node *n){
    this -> get_current_scope() -> add_symbol(n);
    visit_children(n); 
}
void resolve_scope::visit_if_stat(if_stat *n){
    visit_children(n);
}
void resolve_scope::visit_expression_stat(expression_stat *n){ 
        visit_children(n);
    }
void resolve_scope::visit_while_stat(while_stat *n) {
        visit_children(n);
    }
void resolve_scope::visit_return_stat(return_stat*n) { 
        visit_children(n);
    }
void resolve_scope::visit_continue_stat(continue_stat *n) { 
        visit_children(n);
    }
void resolve_scope::visit_break_stat(break_stat *n) { 
        visit_children(n);
    }  
void resolve_scope::visit_block_stat(block_stat *n) { 
    visit_children(n);
    }

void resolve_scope::visit_block_node(block_node *n) { 
    n -> set_parent_scope(this -> get_current_scope()); 
    n -> set_super_scope(NULL);
    n -> set_outer_scope(this -> resolve_outer_scope);
    std::cout << "resolving blockscope" << std::endl;
    this -> push_scope(n);
    visit_children(n);
    this -> pop_scope(n);
    }

void resolve_scope::visit_super_stat(super_stat *n) { 
        visit_children(n);
    }
void resolve_scope::visit_expression(expression *n) { 
        visit_children(n);
    }
void resolve_scope::visit_op_exp(op_exp *n){
          visit_children(n);
     }
void resolve_scope::visit_name_exp(name_exp *n) { 
        visit_children(n);
    }
void resolve_scope::visit_new_array_exp(new_array_exp *n){
        visit_children(n);
    }
void resolve_scope::visit_call_exp(call_exp *n) {
        visit_children(n);
    }
void resolve_scope::visit_array_ref(array_ref *n) {
          visit_children(n);
     }

//void resolve_scope::visit_literal ABSTRACT 
void resolve_scope::visit_null_literal(null_literal *n) { 
        visit_children(n);
    }
void resolve_scope::visit_bool_literal(bool_literal *n) {
          visit_children(n);
     }
void resolve_scope::visit_int_literal(int_literal *n) { 
        visit_children(n);
    }
void resolve_scope::visit_char_literal(char_literal *n) { 
        visit_children(n);
    }
void resolve_scope::visit_string_literal(string_literal *n) {
        visit_children(n);
    }
void resolve_scope::visit_expression_list(expression_list *n) {
          visit_children(n);
     }
        
