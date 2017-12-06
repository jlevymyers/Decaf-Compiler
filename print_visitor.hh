#ifndef PRINTER_HH
# define PRINTER_HH

# include "visitor.hh"
# include "ast.hh"
# include <iostream>

using namespace ast;

class print_visitor : public visitor {
public:
    print_visitor();
    ~print_visitor();

    virtual void visit_ast(ast_node* n) ;
    virtual void visit_children(ast_node* n) ; 

    virtual void visit_class_list(class_list* n) ; 
    virtual void visit_class_node(class_node *n) ; 
    virtual void visit_member_list(member_list *n) ; 
    virtual void visit_super_node(super_node *n) ; 
    virtual void visit_member(member *n); 
    virtual void visit_field_decl(field_decl *n) ; 
    virtual void visit_field_node(field_node *n) ; 
    virtual void visit_method_node(method_node *n) ; 
    virtual void visit_method_body(method_body *n); 
    virtual void visit_constructor_node(constructor_node *n); 
    virtual void visit_formal_list(formal_list *n); 
    virtual void visit_formal_node(formal_node *n); 
    virtual void visit_type_node(type_node *n); 
    virtual void visit_class_type(class_type *n); 
    virtual void visit_array_type_node(array_type_node *n); 
    //virtual void visit_primative_type(primative_type *n); 
    virtual void visit_primative_int(primative_int *n); 
    virtual void visit_primative_bool(primative_bool *n); 
    virtual void visit_primative_char(primative_char *n); 
    virtual void visit_primative_void(primative_void *n); 
    virtual void visit_null_node(null_node *n); 
    virtual void visit_init_node(init_node *n); 
    virtual void visit_meta_node(meta_node *n); 
    virtual void visit_statement_list(statement_list *n); 
    //virtual void visit_statement;  ABSTRACT 
    virtual void visit_empty_stat(empty_stat *n); 
    virtual void visit_decl_stat(decl_stat *n); 
    virtual void visit_local_node(local_node *n); 
    virtual void visit_if_stat(if_stat *n); 
    virtual void visit_expression_stat(expression_stat *n); 
    virtual void visit_while_stat(while_stat *n); 
    virtual void visit_return_stat(return_stat*n); 
    virtual void visit_continue_stat(continue_stat *n); 
    virtual void visit_break_stat(break_stat *n); 
    virtual void visit_block_stat(block_stat *n); 
    virtual void visit_super_stat(super_stat *n); 
    virtual void visit_expression(expression *n); 
    virtual void visit_op_exp(op_exp *n); 
    virtual void visit_name_exp(name_exp *n); 
    virtual void visit_new_array_exp(new_array_exp *n); 
    virtual void visit_call_exp(call_exp *n); 
    virtual void visit_array_ref(array_ref *n); 

    virtual void visit_null_literal(null_literal *n); 
    virtual void visit_bool_literal(bool_literal *n); 
    virtual void visit_int_literal(int_literal *n); 
    virtual void visit_char_literal(char_literal *n); 
    virtual void visit_string_literal(string_literal *n); 
    virtual void visit_expression_list(expression_list *n); 
};

#endif // ! PRINT_HH