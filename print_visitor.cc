# include "print_visitor.hh"

print_visitor::print_visitor(): visitor(){
     std::cout << "\n-----------------------------" << std::endl;
    std::cout << "Printing Abstact Syntax Tree" << std::endl;
    std::cout << "-----------------------------\n" << std::endl;

}
print_visitor::~print_visitor(){}

void print_visitor::visit_ast(ast_node *n){
    n -> accept(this);
    this -> visit_children(n);
    }
void print_visitor::visit_children(ast_node *n){
    n -> visit_children(this); 
    }

void print_visitor::visit_outer_scope(outer_scope* n){
    std::cout << "outer scope";
    std::cout << std::endl;
    }

void print_visitor::visit_class_list(class_list* n){
    std::cout << "class list";
    std::cout << std::endl;
    }

void print_visitor::visit_class_node(class_node *n){
    std::cout << "class node: " << n -> get_name() << std::endl;
    }
void print_visitor::visit_member_list(member_list *n){
    std::cout << "member list";
    std::cout << std::endl;
    }
void print_visitor::visit_super_node(super_node *n){
    std::cout << "super node";
    std::cout << std::endl;
    }
void print_visitor::visit_field_decl(field_decl *n){
    std::cout << "field decl";
    std::cout << std::endl;
    }
void print_visitor::visit_field_node(field_node *n){
    std::cout << "field " << std::endl;
    }
void print_visitor::visit_method_node(method_node *n){
    std::cout << "method: " << n -> get_name() << std::endl;
    }
void print_visitor::visit_method_body(method_body *n){
    std::cout << "method body" << std::endl;
    }
void print_visitor::visit_constructor_node(constructor_node *n){
    std::cout << "constructor_node" << std::endl; 
    }
void print_visitor::visit_formal_list(formal_list *n){
    std::cout << "formal list" << std::endl; 
    }
void print_visitor::visit_formal_node(formal_node *n){
    std::cout << "formal: " << n -> get_name() << std::endl; 
    }
void print_visitor::visit_type_node(type_node *n){
    std::cout << "type node" << std::endl;
    }
void print_visitor::visit_class_type(class_type *n){
    std::cout << "class type" << std::endl;
    }
void print_visitor::visit_array_type_node(array_type_node *n){
    std::cout << "array type" << std::endl;
    }
void print_visitor::visit_primative_int(primative_int *n){
    std::cout << "int" << std::endl;
    }
void print_visitor::visit_primative_bool(primative_bool *n){
    std::cout << "boolean" << std::endl;
    } 
void print_visitor::visit_primative_char(primative_char *n){
    std::cout << "char" << std::endl;
    }
void print_visitor::visit_primative_void(primative_void *n){
    std::cout << "void" << std::endl;
    }
void print_visitor::visit_null_node(null_node *n){
    std::cout << "null" << std::endl;
    }
void print_visitor::visit_init_node(init_node *n){
    std::cout << "init" << std::endl;
    }
void print_visitor::visit_meta_node(meta_node *n){
    std::cout << "meta" << std::endl;
    }
void print_visitor::visit_statement_list(statement_list *n){
    std::cout << "statement list" << std::endl;
    }
//void print_visitor::visit_statement{ std::cout << "";} ABSTRACT 
void print_visitor::visit_empty_stat(empty_stat *n){
    std::cout << "empty stat" << std::endl;
    }
void print_visitor::visit_decl_stat(decl_stat *n){
    std::cout << "decl stat" << std::endl;
    }
void print_visitor::visit_local_node(local_node *n){
    std::cout << "local" << std::endl;
    }
void print_visitor::visit_if_stat(if_stat *n){
    std::cout << "if" << std::endl;
    }
void print_visitor::visit_expression_stat(expression_stat *n){ 
    std::cout << "expression stat" << std::endl;
        }
void print_visitor::visit_while_stat(while_stat *n) {
    std::cout << "while stat" << std::endl;
        }
void print_visitor::visit_return_stat(return_stat*n) { 
    std::cout << "return stat" << std::endl;
        }
void print_visitor::visit_continue_stat(continue_stat *n) { 
    std::cout << "continue stat" << std::endl;
        }
void print_visitor::visit_break_stat(break_stat *n) { 
    std::cout << "break stat" << std::endl;
        }
void print_visitor::visit_block_stat(block_stat *n) { 
    std::cout << "block stat" << std::endl;
        }

void print_visitor::visit_block_node(block_node *n) { 
    std::cout << "block scope" << std::endl;
}
void print_visitor::visit_super_stat(super_stat *n) { 
    std::cout << "super_stat" << std::endl;
        }
void print_visitor::visit_expression(expression *n) { 
    std::cout << "expression" << std::endl;
        }
void print_visitor::visit_op_exp(op_exp *n){
     std::cout << "op" << std::endl;
          }
void print_visitor::visit_name_exp(name_exp *n) { 
    std::cout << "name: " << n -> get_name() << std::endl;
    }

void print_visitor::visit_new_exp(new_exp *n){
    std::cout << "new" << std::endl;
        }
void print_visitor::visit_new_array_exp(new_array_exp *n){
    std::cout << "new array" << std::endl;
        }

void print_visitor::visit_call_exp(call_exp *n) {
    std::cout << "call" << std::endl;
        }
void print_visitor::visit_array_ref(array_ref *n) {
     std::cout << "array ref" << std::endl;
          }

//void print_visitor::visit_literal ABSTRACT 
void print_visitor::visit_null_literal(null_literal *n) { 
    std::cout << "null" << std::endl;
        }
void print_visitor::visit_bool_literal(bool_literal *n) {
     std::cout << "bool literal" << std::endl;
          }
void print_visitor::visit_int_literal(int_literal *n) { 
    std::cout << "int literal" << std::endl;
        }
void print_visitor::visit_char_literal(char_literal *n) { 
    std::cout << "char literal" << std::endl;
        }
void print_visitor::visit_string_literal(string_literal *n) {
    std::cout << "string literal" << std::endl;
        }
void print_visitor::visit_expression_list(expression_list *n) {
     std::cout << "expression list" << std::endl;
          }
        
