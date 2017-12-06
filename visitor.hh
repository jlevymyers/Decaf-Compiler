#ifndef VISITOR_HH
# define VISITOR_HH

# include "ast.hh"

using namespace ast;

class visitor {
public:
    // visitor();
    virtual ~visitor();

    virtual void visit_ast(ast::ast_node* n)   = 0;
    virtual void visit_children(ast_node* n)  = 0;

    virtual void visit_class_list(class_list* n)  = 0;
    virtual void visit_class_node(class_node *n)  = 0;
    virtual void visit_member_list(member_list *n)  = 0;
    virtual void visit_super_node(super_node *n)  = 0;
    virtual void visit_member(member *n)  = 0;
    virtual void visit_field_decl(field_decl *n)  = 0;
    virtual void visit_field_node(field_node *n)  = 0;
    virtual void visit_method_node(method_node *n)  = 0;
    virtual void visit_method_body(method_body *n)  = 0;
    virtual void visit_constructor_node(constructor_node *n)  = 0;
    virtual void visit_formal_list(formal_list *n)  = 0;
    virtual void visit_formal_node(formal_node *n)  = 0;
    virtual void visit_type_node(type_node *n)  = 0;
    virtual void visit_class_type(class_type *n)  = 0;
    virtual void visit_array_type_node(array_type_node *n)  = 0;
    //virtual void visit_primate_type(primative_type *n)  = 0;
    virtual void visit_primative_int(primative_int *n)  = 0;
    virtual void visit_primative_bool(primative_bool *n)  = 0;
    virtual void visit_primative_char(primative_char *n)  = 0;
    virtual void visit_primative_void(primative_void *n)  = 0;
    virtual void visit_null_node(null_node *n)  = 0;
    virtual void visit_init_node(init_node *n)  = 0;
    virtual void visit_meta_node(meta_node *n)  = 0;
    virtual void visit_statement_list(statement_list *n)  = 0;
    //virtual void visit_statement  = 0; ABSTRACT 
    virtual void visit_empty_stat(empty_stat *n)  = 0;
    virtual void visit_decl_stat(decl_stat *n)  = 0;
    virtual void visit_local_node(local_node *n)  = 0;
    virtual void visit_if_stat(if_stat *n)  = 0;
    virtual void visit_expression_stat(expression_stat *n)  = 0;
    virtual void visit_while_stat(while_stat *n)  = 0;
    virtual void visit_return_stat(return_stat*n)  = 0;
    virtual void visit_continue_stat(continue_stat *n)  = 0;
    virtual void visit_break_stat(break_stat *n)  = 0;
    virtual void visit_block_stat(block_stat *n)  = 0;
    virtual void visit_super_stat(super_stat *n)  = 0;
    virtual void visit_expression(expression *n)  = 0;
    virtual void visit_op_exp(op_exp *n)  = 0;
    virtual void visit_name_exp(name_exp *n)  = 0;
    virtual void visit_new_array_exp(new_array_exp *n)  = 0;
    virtual void visit_call_exp(call_exp *n)  = 0;
    virtual void visit_array_ref(array_ref *n)  = 0;

    virtual void visit_null_literal(null_literal *n) =0 ;
    virtual void visit_bool_literal(bool_literal *n) =0 ;
    virtual void visit_int_literal(int_literal *n) =0 ;
    virtual void visit_char_literal(char_literal *n) =0 ;
    virtual void visit_string_literal(string_literal *n) =0 ;
    virtual void visit_expression_list(expression_list *n) =0 ;
};


#endif // ! VISITOR_HH