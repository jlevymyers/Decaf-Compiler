# include "build_symbols.hh"

build_symbols::build_symbols(): visitor(){}
build_symbols::~build_symbols(){}

void build_symbols::build(scope *s){
}

void build_symbols::visit_children(ast_node* n){
    n -> visit_children(this);
}

void build_symbols::visit_ast(ast_node* n){
    n -> accept(this);
}

void build_symbols::visit_outer_scope(outer_scope *n){
    visit_children(n);
}

void build_symbols::visit_class_list(class_list* n){
    visit_children(n);
}
void build_symbols::visit_class_node(class_node *n){
    visit_children(n);
}  

void build_symbols::visit_member_list(member_list *n){
    std::cout << "building member scope" << std::endl;
    visit_children(n);
}

void build_symbols::visit_super_node(super_node *n){
    visit_children(n);
}
void build_symbols::visit_field_decl(field_decl *n){
    visit_children(n);
}
void build_symbols::visit_field_node(field_node *n){
    visit_children(n);
}
void build_symbols::visit_method_node(method_node *n){
    visit_children(n);
}
void build_symbols::visit_method_body(method_body *n){
    std::cout << "building method scope" << std::endl;
    visit_children(n);
}
void build_symbols::visit_constructor_node(constructor_node *n){
    visit_children(n);
}
void build_symbols::visit_formal_list(formal_list *n){
    visit_children(n);
}
void build_symbols::visit_formal_node(formal_node *n){
    visit_children(n);
}
void build_symbols::visit_type_node(type_node *n){
    visit_children(n);
}
void build_symbols::visit_class_type(class_type *n){
    visit_children(n);
}
void build_symbols::visit_array_type_node(array_type_node *n){
    visit_children(n);
}
void build_symbols::visit_primative_int(primative_int *n){
    visit_children(n);
}
void build_symbols::visit_primative_bool(primative_bool *n){
    visit_children(n);
} 
void build_symbols::visit_primative_char(primative_char *n){
    visit_children(n);
}
void build_symbols::visit_primative_void(primative_void *n){
    visit_children(n);
}
void build_symbols::visit_null_node(null_node *n){
    visit_children(n);
}
void build_symbols::visit_init_node(init_node *n){
    visit_children(n);
}
void build_symbols::visit_meta_node(meta_node *n){
    visit_children(n);
}
void build_symbols::visit_statement_list(statement_list *n){
    visit_children(n);
}

void build_symbols::visit_empty_stat(empty_stat *n){
    visit_children(n);
}

void build_symbols::visit_decl_stat(decl_stat *n){
    visit_children(n);
}
void build_symbols::visit_local_node(local_node *n){
    visit_children(n); 
}
void build_symbols::visit_if_stat(if_stat *n){
    visit_children(n);
}
void build_symbols::visit_expression_stat(expression_stat *n){ 
        visit_children(n);
    }
void build_symbols::visit_while_stat(while_stat *n) {
        visit_children(n);
    }
void build_symbols::visit_return_stat(return_stat*n) { 
        visit_children(n);
    }
void build_symbols::visit_continue_stat(continue_stat *n) { 
        visit_children(n);
    }
void build_symbols::visit_break_stat(break_stat *n) { 
        visit_children(n);
    }  
void build_symbols::visit_block_stat(block_stat *n) { 
    visit_children(n);
    }

void build_symbols::visit_block_node(block_node *n) { 
    std::cout << "building block scope" << std::endl;
    build(n);
    visit_children(n);
    }

void build_symbols::visit_super_stat(super_stat *n) { 
        visit_children(n);
    }
void build_symbols::visit_expression(expression *n) { 
        visit_children(n);
    }
void build_symbols::visit_op_exp(op_exp *n){
          visit_children(n);
     }
void build_symbols::visit_name_exp(name_exp *n) { 
        visit_children(n);
    }
void build_symbols::visit_new_array_exp(new_array_exp *n){
        visit_children(n);
    }
void build_symbols::visit_call_exp(call_exp *n) {
        visit_children(n);
    }
void build_symbols::visit_array_ref(array_ref *n) {
          visit_children(n);
     }

//void build_symbols::visit_literal ABSTRACT 
void build_symbols::visit_null_literal(null_literal *n) { 
        visit_children(n);
    }
void build_symbols::visit_bool_literal(bool_literal *n) {
          visit_children(n);
     }
void build_symbols::visit_int_literal(int_literal *n) { 
        visit_children(n);
    }
void build_symbols::visit_char_literal(char_literal *n) { 
        visit_children(n);
    }
void build_symbols::visit_string_literal(string_literal *n) {
        visit_children(n);
    }
void build_symbols::visit_expression_list(expression_list *n) {
          visit_children(n);
     }
        
