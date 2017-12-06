#include "ast.hh"
#include "visitor.hh"

using namespace ast;

//CLASS LIST

int ast_node::ast_count =  0;

void ast_node::add_child(ast_node *child){
	if(child != NULL){
		this -> ast_children.push_back(child);
	}
	else{
		std::cout << "attempted to push null child" << std::endl << std::endl;
	}
}

void ast_node::visit_children(::visitor *v){
	std::vector<ast_node*>::iterator iter; 
	for(iter = this -> ast_children.begin(); iter != this -> ast_children.end(); iter++){
		(*iter) -> accept(v);
	}
}

void ast_node::accept(::visitor *v){
	std::cout << "this instance shouldnt exist" << std::endl; 
}

ast_node::ast_node() : ast_children(vector<ast_node*>()){
	this -> ast_id = ast_node::ast_count++;
}
ast_node::ast_node(ast_node *a) : ast_children(vector<ast_node*>()){
	this -> ast_id = ast_node::ast_count++;
	if(a != NULL){
		this -> add_child(a);
	}
}
ast_node::ast_node(ast_node *a, ast_node *b) : ast_children(vector<ast_node*>()){
	this -> ast_id = ast_node::ast_count++;
	if(a != NULL){
		this -> add_child(a);
	}
	if(b != NULL){
		this -> add_child(b);
	}
}
ast_node::ast_node(ast_node *a, ast_node *b, ast_node *c) : ast_children(vector<ast_node*>()){
	this -> ast_id = ast_node::ast_count++;
	if(a != NULL){
		this -> add_child(a);
	}
	if(b != NULL){
		this -> add_child(b);
	}
	if(c != NULL){
		this -> add_child(c);
	}
}
ast_node::ast_node(ast_node *a, ast_node *b, ast_node *c, ast_node *d): ast_children(vector<ast_node*>()){
	this -> ast_id = ast_node::ast_count++;
	if(a != NULL){
		this -> add_child(a);
	}
	if(b != NULL){
		this -> add_child(b);
	}
	if(c != NULL){
		this -> add_child(c);
	}
	if(d != NULL){
		this -> add_child(d);
	}
}


void ast_node::insert_child(ast_node *child){
	this -> ast_children.insert(this -> ast_children.begin(), child);
}

int ast_node::num_children(){
	return this -> ast_children.size();
}

ast_node* ast_node::get_child(int index){
	if(index < 0 && index >= this -> num_children()){
		return this -> ast_children[index];
	}
	else{
		return NULL;
	}
}

class_list::class_list(class_node *a_class) : ast_node(a_class) {}

void class_list::accept(::visitor *v) {
	v -> visit_class_list(this);
}

class_node* class_list::get_class(int index) {
	return (class_node*) this -> get_class(index);	
}

//TYPE 

string type_node::get_name(){
	return this -> type_id;
}

type_node::type_node(string type_id): type_id(type_id){}

void type_node::accept(::visitor *v){
	std::cout << "this shouldn't be an instance" << std::endl;
}

//CLASS 

class_node::class_node(std::string id, super_node *super, member_list *mlist): id(id), ast_node(super, mlist) {}

void class_node::accept(::visitor *n) {
	n -> visit_class_node(this);
}

type_node* class_node::get_type(){
	return (type_node*) this -> get_child(0);
}

member_list* class_node::get_member_list(){
	return (member_list*) this -> get_child(2); 
}

super_node* class_node::get_super(){
	return (super_node*) this -> get_child(1);
}

//MEMBER LIST 
member_list::member_list(): ast_node(){}

void member_list::accept(::visitor *n){
	n -> visit_member_list(this);
}

//ABSTRACT MEMBER CLASS
member::member() : ast_node(){}
member::member(ast_node *a, ast_node *b) : ast_node(a,b){}
void member::set_modifiers(int modifiers){
	this -> modifiers = modifiers;
}


//VIRTUAL DESTRUCTORS
expression::~expression(){}
member::~member(){}
literal::~literal(){}
statement::~statement(){}
type_node::~type_node(){}
ast_node::~ast_node(){}

//SUPER
super_node::super_node(type_node *type): ast_node(type){}
void super_node::accept(::visitor *n) {
	n -> visit_super_node(this);
}

//FIELD DECLARATION 
field_decl::field_decl(): member(){} 
void field_decl::accept(::visitor *n) {
	n -> visit_field_decl(this);
}

//FIELD 
field_node::field_node(std::string id, int count): id(id), count(count), symbol() {} 

expression* field_node::get_init(){
	if(this -> num_children() < 1){
		return NULL;
	}
	else{
		return (expression*) get_child(0);
	}
}

void field_node::accept(visitor *n){
	n -> visit_field_node(this); 
}



//METHOD
method_node::method_node(int modifiers, type_node *type, method_body *body): id(0), modifiers(modifiers), member(type, body){}
void method_node::accept(visitor *n){
	n -> visit_method_node(this);
}

//METHOD BODY
method_body::method_body(formal_list *flist, statement_list *slist): ast_node(flist, slist) {}; 

void method_body::accept(visitor *n){
	n -> visit_method_body(this);
}

//CONSTRUCTOR

constructor_node::constructor_node(int modifiers, type_node *type, method_body *body): id(0), modifiers(modifiers), member(type, body){}

void constructor_node::accept(visitor *n){
	n -> visit_constructor_node(this);
}

//FORMAL ARGUMENT LIST
formal_list::formal_list(): ast_node(){}

void formal_list::accept(visitor *n){
	n -> visit_formal_list(this);
}

//FORMAL ARGUMENT
formal_node::formal_node(type_node* type): id(0), symbol(type){}
void formal_node::accept(visitor *n){
	n -> visit_formal_node(this);
}

class_type::class_type(string id): type_node(id) {}
void class_type::accept(visitor *n){
	n -> visit_class_type(this);
}

array_type_node::array_type_node(type_node *type): type_node(type -> get_name() + "[]") {}

void array_type_node::accept(visitor *n){
	n -> visit_array_type_node(this);
}


//INTEGER
primative_int::primative_int(): type_node("int") {}
void primative_int::accept(visitor *n){
	n -> visit_primative_int(this);
}

//BOOLEAN
primative_bool::primative_bool(): type_node("bool") {}
void primative_bool::accept(visitor *n){
	n -> visit_primative_bool(this);
}

//CHAR
primative_char::primative_char(): type_node("char") {}
void primative_char::accept(visitor *n){
	n -> visit_primative_char(this);
}

//VOID
primative_void::primative_void(): type_node("void") {}
void primative_void::accept(visitor *n){
	n -> visit_primative_void(this);
}

//NULL
null_node::null_node(): type_node("null") {}
void null_node::accept(visitor *n){
	n -> visit_null_node(this);
}

//INIT
init_node::init_node(): type_node("init") {}
void init_node::accept(visitor *n){
	n -> visit_init_node(this);
}

//META
meta_node::meta_node(): type_node("meta") {}
void meta_node::accept(visitor *n){
	n -> visit_meta_node(this); 
}

//STATEMENT LIST
statement_list::statement_list(): ast_node(){}
void statement_list::accept(visitor *n){
	n -> visit_statement_list(this);
}

 empty_stat::empty_stat(): statement(){}
 void empty_stat::accept(visitor *n){
	 n -> visit_empty_stat(this);
 }

 decl_stat::decl_stat(): statement(){}
 void decl_stat::accept(visitor *n){
	 n -> visit_decl_stat(this);
 }
 void decl_stat::set_type(type_node *type){
	 this -> insert_child(type);
 }

local_node::local_node(string id, int count): id(id), count(count), symbol() {}
void local_node::accept(visitor *n){
	n -> visit_local_node(this);
}

if_stat::if_stat(expression *exp, statement *stat): statement(exp, stat){}
if_stat::if_stat(expression *exp, statement *if_stat, statement *else_stat): statement(exp, if_stat, else_stat){}
void if_stat::accept(visitor *n){
	n -> visit_if_stat(this);
} 

expression_stat::expression_stat(expression *exp): statement(exp){}
void expression_stat::accept(visitor *n){
	n -> visit_expression_stat(this);
}


while_stat::while_stat(expression* exp, statement* stat): statement(exp, stat){}
void while_stat::accept(visitor *n){
	n -> visit_while_stat(this);
}


return_stat::return_stat(): statement(){}
return_stat::return_stat(expression *exp): statement(exp){}
void return_stat::accept(visitor *n){
	n -> visit_return_stat(this);
}


continue_stat::continue_stat(): statement(){}
void continue_stat::accept(visitor *n){
	n -> visit_continue_stat(this);
}

break_stat::break_stat(): statement(){}
void break_stat::accept(visitor *n){
	n -> visit_break_stat(this);
}

block_stat::block_stat(statement_list *stats): statement(stats){}
void block_stat::accept(visitor *n){
	n -> visit_block_stat(this);
}

super_stat::super_stat(call_exp *c): statement(c){}
void super_stat::accept(visitor *n){
	n -> visit_super_stat(this);
}

op_exp::op_exp(ast_node *exp): expression(exp){}
op_exp::op_exp(ast_node *left, ast_node *right): expression(left, right) {}     
void op_exp::accept(visitor *n){
	n -> visit_op_exp(this);
}


name_exp::name_exp(string id): id(id), expression(){}
void name_exp::accept(visitor *n){
	n -> visit_name_exp(this);
}



new_array_exp::new_array_exp(type_node *type): expression(type){}

expression* new_array_exp::get_dimension(int index){
	return (expression*) this -> get_child(index);
}
void new_array_exp::accept(visitor *n){
	n -> visit_new_array_exp(this);
}

call_exp::call_exp(name_exp* id, expression_list *actual_args): expression(id, actual_args){}
void call_exp::accept(visitor *n){
	n -> visit_call_exp(this);
}
 
array_ref::array_ref(name_exp *id, expression* dimension): expression(id, dimension){}
array_ref::array_ref(expression* array_exp, expression* dimension){}
void array_ref::accept(visitor *n){
	n -> visit_array_ref(this);
}

null_literal::null_literal(): literal(){}
void null_literal::accept(visitor *n){
	n -> visit_null_literal(this);
}

bool_literal::bool_literal(bool val): val(val), literal(){}
void bool_literal::accept(visitor *n){
	n -> visit_bool_literal(this);
}

int_literal:: int_literal(int val): val(val), literal(){}
void int_literal::accept(visitor *n){
	n -> visit_int_literal(this);
}

char_literal::char_literal(char val): val(val), literal(){}
void char_literal::accept(visitor *n){
	n -> visit_char_literal(this);
}

string_literal::string_literal(string val): val(val), literal(){}
void string_literal::accept(visitor *n){
	n -> visit_string_literal(this);
}

expression_list::expression_list(): ast_node(){}
void expression_list::accept(visitor *n){
	n -> visit_expression_list(this);
}

expression* expression_list::get_expression(int index){
	return (expression *) get_child(index);
}

// SYMBOL

