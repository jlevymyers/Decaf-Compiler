# include "resolve_scope.hh"

resolve_scope::resolve_scope(): visitor(){

    std::cout << "\n-----------------------------" << std::endl;
    std::cout << "Resolving Scope & Building Symbol Table" << std::endl;
    std::cout << "-----------------------------\n" << std::endl;
    
    this -> current_class = NULL;
    build_runtime();
}

resolve_scope::~resolve_scope(){}

void resolve_scope::build_runtime(){
    std::cout << "SCOPE: adding runtime symbols" << std::endl;
    outer_scope* out = new outer_scope();
    out -> set_parent_scope(NULL);
    out -> set_super_scope(NULL);
    this -> resolve_outer_scope = out;
    out -> set_outer_scope(NULL);
    this -> push_scope(out);
    
    class_node* object_class = new class_node("Object", NULL, new member_list());
    out -> add(object_class);    

    class_node* string_class = new class_node("String", NULL, new member_list());
    out -> add(string_class);

    member_list* io_member = new member_list();
    method_node* putChar = build_method("putChar", new primative_void(), new primative_char(), "c");
    method_node* putInt = build_method("putInt", new primative_void(), new primative_int(), "v");
    method_node* putString = build_method("putString", new primative_void(), new class_type("String"), "s");
    method_node* peek = build_method("peek", new primative_int(), NULL, "");
    method_node* getChar = build_method("getChar", new primative_int(), NULL, "");
    method_node* getInt = build_method("getInt", new primative_int(), NULL, "");
    method_node* getLine = build_method("getLine", new class_type("String"), NULL, "");

    io_member -> add_member(putChar);
    io_member -> add_member(putInt);
    io_member -> add_member(putString);
    io_member -> add_member(peek);
    io_member -> add_member(putChar);
    io_member -> add_member(getChar);
    io_member -> add_member(getInt);
    io_member -> add_member(getLine);

    class_node* io_class = new class_node("IO", new super_node(new class_type("Object")), io_member);
    out -> add(io_class);
    visit_ast(resolve_outer_scope);
}

/**
 * 
 *  build symbols for runtime methods
 *  
 **/

method_node* resolve_scope::build_method(std::string name, type_node* ret_type, type_node* arg_type, std::string arg_name){
    formal_list* method_args = new formal_list();  
    if((arg_type != NULL) && (!(arg_name == ""))){
        formal_node *arg = new formal_node(arg_type, arg_name); 
        method_args -> add_formal(arg); 
    }
    method_body* mbody = new method_body(method_args, new statement_list());
    method_node* m = new method_node(MOD_PUBLIC, name, ret_type, mbody);
    std::cout << "SCOPE: added runtime method: " << name << std::endl;
    return m;
}

void resolve_scope::push_scope(scope* s){
    std::cout << "SCOPE: entering scope: " << s << std::endl;
    this -> scope_stack.push(s);
}
void resolve_scope::pop_scope(){
    std::cout << "SCOPE: leaving scope: " << this -> get_current_scope() << std::endl;
    this -> scope_stack.pop(); 
}
scope* resolve_scope::get_current_scope(){
    return this -> scope_stack.top();
}

scope* resolve_scope::get_outer_scope(){
    return this -> resolve_outer_scope;
}

void resolve_scope::set_current_class(class_node *c){
    if(this -> current_class != NULL){
        std::cout << "ERROR: cannot define nested classes" << std::endl;
    }
    else{
        this -> current_class = c;
    }
}

class_node *resolve_scope::get_current_class(){
    assert(this -> current_class);
    return this -> current_class; 
}

void resolve_scope::pop_current_class(){
    this -> current_class = NULL;
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
    this -> set_current_class(n);
    visit_children(n);
    this -> pop_current_class();
} 

void resolve_scope::visit_member_list(member_list *n){
    n -> set_super_scope(NULL);    
    n -> set_parent_scope(this -> get_current_scope());
    n -> set_outer_scope(this -> resolve_outer_scope);
    std::string class_name = this -> get_current_class() -> get_name();

    this -> push_scope(n);
    visit_children(n);

    //add default constructor
    symbol *ctor = n -> find_method(class_name);

    if(ctor == NULL){
        method_body *ctor_body = new method_body(new formal_list(), new statement_list());
        constructor_node* default_ctor = new constructor_node(MOD_PUBLIC, class_name, ctor_body);
        n -> add_member(default_ctor);
        n -> add_symbol(default_ctor);
        std::cout << "INSERTING: default constructor: " << class_name << std::endl;
    }
    else{
        std::cout << "FOUND: default constructor: " << class_name << std::endl;
    }
    this -> pop_scope();
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

    //add the implicit "this" argument
    std::string current_class = this -> get_current_class() -> get_name(); 
    class_type *this_class = new class_type(current_class);
    formal_node *this_formal = new formal_node(this_class, "this");
    n -> get_formal_args() -> add_formal_first(this_formal);

    this -> push_scope(n);
    visit_children(n);
    this -> pop_scope();
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
    n -> set_super_scope(NULL); 
    n -> set_parent_scope(this -> get_current_scope()); 
    n -> set_outer_scope(this -> resolve_outer_scope);
    std::cout << "SCOPE: entering resolving blockscope" << std::endl;
    this -> push_scope(n);
    visit_children(n);
    this -> pop_scope();
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
void resolve_scope::visit_new_exp(new_exp *n){
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
        
