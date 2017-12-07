#ifndef BUILD_SYM_HH
# define BUILD_SYM_HH

# include "visitor.hh"
# include <iostream>
# include <stack>

using namespace ast;

class build_symbols: public visitor {
public:

    build_symbols();
    ~build_symbols();
 
    void build(scope* s);

    void visit_ast(ast_node* n) ;
    void visit_children(ast_node* n) ; 

    void visit_outer_scope(outer_scope* s);

    void visit_class_list(class_list* n) ; 
    void visit_class_node(class_node *n) ; 
    void visit_member_list(member_list *n) ; 
    void visit_super_node(super_node *n) ; 
    void visit_field_decl(field_decl *n) ; 
    void visit_field_node(field_node *n) ; 
    void visit_method_node(method_node *n) ; 
    void visit_method_body(method_body *n); 
    void visit_constructor_node(constructor_node *n); 
    void visit_formal_list(formal_list *n); 
    void visit_formal_node(formal_node *n); 
    void visit_type_node(type_node *n); 
    void visit_class_type(class_type *n); 
    void visit_array_type_node(array_type_node *n); 
    void visit_primative_int(primative_int *n); 
    void visit_primative_bool(primative_bool *n); 
    void visit_primative_char(primative_char *n); 
    void visit_primative_void(primative_void *n); 
    void visit_null_node(null_node *n); 
    void visit_init_node(init_node *n); 
    void visit_meta_node(meta_node *n); 
    void visit_statement_list(statement_list *n); 
    void visit_empty_stat(empty_stat *n); 
    void visit_decl_stat(decl_stat *n); 
    void visit_local_node(local_node *n); 
    void visit_if_stat(if_stat *n); 
    void visit_expression_stat(expression_stat *n); 
    void visit_while_stat(while_stat *n); 
    void visit_return_stat(return_stat*n); 
    void visit_continue_stat(continue_stat *n); 
    void visit_break_stat(break_stat *n); 
    
    void visit_block_stat(block_stat *n); 
    void visit_block_node(block_node *n); 

    void visit_super_stat(super_stat *n); 
    void visit_expression(expression *n); 
    void visit_op_exp(op_exp *n); 
    void visit_name_exp(name_exp *n); 
    void visit_new_array_exp(new_array_exp *n); 
    void visit_call_exp(call_exp *n); 
    void visit_array_ref(array_ref *n); 

    void visit_null_literal(null_literal *n); 
    void visit_bool_literal(bool_literal *n); 
    void visit_int_literal(int_literal *n); 
    void visit_char_literal(char_literal *n); 
    void visit_string_literal(string_literal *n); 
    void visit_expression_list(expression_list *n); 
};

#endif // ! BUILD_SYM_HH