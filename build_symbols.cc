# include "build_symbols.hh"

build_symbols::build_symbols(scope* outer): visitor(){
    std::cout << "\n-----------------------------" << std::endl;
    std::cout << "Resolving Symbols" << std::endl;
    std::cout << "-----------------------------\n" << std::endl;
    assert(outer);
    this -> set_outer_scope(outer);
    this -> push_scope(outer);
}
build_symbols::~build_symbols(){}

void build_symbols::push_scope(scope* s){
    std :: cout << "pushing scope" << std :: endl;
    this -> scope_stack.push(s);
}
void build_symbols::pop_scope(scope *s){
    std :: cout << "popping scope" << std :: endl;
    this -> scope_stack.pop(); 
}
scope* build_symbols::get_current_scope(){
    return this -> scope_stack.top();
}

void build_symbols::set_outer_scope(scope* outer){
    this -> outer = outer; 
}

scope* build_symbols::get_outer_scope(){
    return this -> outer;
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
    //std::cout << "building member scope" << std::endl;
    this -> push_scope(n);
    visit_children(n);
    this -> pop_scope(n);
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
    std::cout << "building method symbol" << std::endl;
    this -> push_scope(n);
    visit_children(n);
    this -> pop_scope(n);
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
    std::string class_name = n -> get_name();
    std::cout << "resolving class type: " << class_name << std::endl;
    symbol* c = NULL;
    if(this -> scope_stack.size() == 0){
        std::cout << "currrent scope null" << std::endl;
    }
    else{
        scope* current_scope = get_current_scope();
        c = this -> get_outer_scope() -> find(class_name);
    }
    if(c == NULL){
        std::cout << "could not resolve class symbol" << std::endl;
    }
    else{
        n -> set_symbol(c);
    }
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
    std::cout << "building block symbol" << std::endl;
    this -> push_scope(n);
    visit_children(n);
    this -> pop_scope(n);
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
    symbol* class_sym;

    //check if name needs to be evaluated in LHS scope
    if(n -> get_is_lhs()){
        std::cout << "visiting non-rhs name: " << n -> get_name() << std::endl;
        class_sym = this -> get_current_scope() -> find(n -> get_name());
        //RHS can be variable/field
        if(class_sym == NULL){
            class_sym = this -> get_current_scope() -> find_scope(n -> get_name());
        }
    }
    else{
        std::cout << "visiting lhs expression: " << n -> get_name() << std::endl;
        expression* lhs_exp = n -> get_expression();


        //RESOLVE EXPRESSION
        visit_ast(lhs_exp);
        std::cout << "LHS exp: " << lhs_exp -> get_type() -> get_name() << std::endl; 
        
        //RESOLVE EXPRESSION TYPE
        visit_ast(lhs_exp -> get_type());

        scope* lhs_scope = lhs_exp -> get_type() -> get_associated_scope(); 

        if(lhs_scope == NULL){
            std::cout << "ERROR: lhs invalid" << std::endl;
            return;
        }

        //check is name is a call
        if(n -> get_is_call()){
            std::cout << "visiting rhs name call" << std::endl;
            class_sym = lhs_scope -> find_method(n -> get_name());
        }
        else{
            std::cout << "visiting rhs field" << std::endl;   
            class_sym = lhs_scope -> find_scope(n -> get_name());
        }
    }
    
    if(class_sym != NULL){
        n -> set_symbol(class_sym);
        n -> set_type(class_sym -> get_type());
    }
    else{
        std::cout << "ERROR: couldn't resolve symbol" << n -> get_name() << std::endl; 
    }
    //visit_children(n);
}

void build_symbols::visit_new_exp(new_exp *n){
        std::cout << "visiting new expression" << std::endl;
        visit_children(n);
    }

void build_symbols::visit_new_array_exp(new_array_exp *n){
        visit_children(n);
}

void build_symbols::visit_call_exp(call_exp *n) {
        std::cout << "visiting call exp: " << n -> get_method() -> get_name() << std::endl;
        //name_exp *method = n -> get_method();
        //symbol* method_sym = this -> get_current_scope() -> find_method(method -> get_name());
        //method -> set_symbol(method_sym);
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
        
