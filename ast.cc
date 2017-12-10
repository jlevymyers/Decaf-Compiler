#include "ast.hh"
#include "visitor.hh"
#include <cassert>

using namespace ast;

//CLASS LIST

outer_scope::outer_scope(): scope(){}

void outer_scope::accept(visitor *v){
	v -> visit_outer_scope(this);
}

void outer_scope::add(ast_node *n){
	this -> add_child(n);
}

//CLASS LIST

class_node* class_list::get_class(int index) {
	return (class_node*) this -> get_class(index);	
}

class_list::class_list(class_node *c): ast_node(c) {}

void class_list::add_class(class_node *c){
	this -> add_child(c);
}

void class_list::accept(visitor *v) {
	v -> visit_class_list(this);
}


//TYPE 

type_node::type_node(std::string id): type_id(id), ast_node(){
	assert(this -> type_id != "");
}

std::string type_node::get_name(){
	assert(this -> type_id != "");
	return this -> type_id; 
}

void type_node::accept(visitor *v){
	std::cout << "visiting type: " << this -> get_name() << std::endl;
}

//CLASS 

class_node::class_node(std::string id, super_node *super, member_list *mlist): symbol(MOD_PUBLIC, id, SYM_CLASS, super, mlist) {
	class_type * type = new class_type(id); 
	this -> add_child(type);
}

void class_node::accept(visitor *n) {
	n -> visit_class_node(this);
}

type_node* class_node::get_type(){
	return (type_node*) this -> get_child(2);
}

super_node* class_node::get_super(){
	return (super_node*) this -> get_child(0);
}

member_list* class_node::get_members(){
	return (member_list*) this -> get_child(1);
}

scope* class_node::get_associated_scope(){
	assert(get_members());
	return (scope*) this -> get_members();
}

//MEMBER LIST 

member_list::member_list(): scope(){};

void member_list::accept(::visitor *n){
	n -> visit_member_list(this);
}

//VIRTUAL DESTRUCTORS
expression::~expression(){}
literal::~literal(){}
statement::~statement(){}
ast_node::~ast_node(){}

//STATEMENT

void statement::statement::add_type(type_node *type){
	this -> insert_child(type);
}

//SUPER
super_node::super_node(type_node *type): ast_node(type){}
void super_node::accept(::visitor *n) {
	n -> visit_super_node(this);
}

//FIELD DECLARATION 
void field_decl::accept(::visitor *n) {
	n -> visit_field_decl(this);
}

void field_decl::add_field(field_node *f){
	this -> add_child(f);
}

//FIELD 

expression* field_node::get_init(){
	if(this -> num_children() < 1){
		return NULL;
	}
	else{
		return (expression*) get_child(0);
	}
}

void field_node::add_assignment(expression *exp){
		this -> add_child(exp);
}

void field_node::accept(visitor *n){
	n -> visit_field_node(this); 
}



//METHOD
method_node::method_node(int mod, std::string id, type_node *type, method_body *body): symbol(mod, id, SYM_METHOD, type, body){}
//constructor
method_node::method_node(int mod, std::string id, symbol_type sym_type, type_node *type, method_body *body): symbol(mod, id, sym_type, type, body){}

void method_node::accept(visitor *n){
	n -> visit_method_node(this);
}

//METHOD BODY
method_body::method_body(formal_list *flist, statement_list *slist): scope(flist, slist) {}; 

void method_body::accept(visitor *n){
	n -> visit_method_body(this);
}

//CONSTRUCTOR

constructor_node::constructor_node(int modifiers, std::string id, method_body *body): method_node(modifiers, id, SYM_CTOR, new class_type(id), body){}

void constructor_node::accept(visitor *n){
	n -> visit_constructor_node(this);
}

//FORMAL ARGUMENT LIST
formal_list::formal_list(): ast_node(){}

void formal_list::accept(visitor *n){
	n -> visit_formal_list(this);
}

void formal_list::add_formal(formal_node *formal){
		this -> add_child(formal);
}

void formal_list::add_formal_first(formal_node *formal){
		this -> insert_child(formal);
}

//FORMAL ARGUMENT
formal_node::formal_node(type_node* type, std::string id): variable(MOD_PUBLIC, id, SYM_FORMAL_ARG, type){}
void formal_node::accept(visitor *n){
	n -> visit_formal_node(this);
}

class_type::class_type(std::string id): type_node(id) {}

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

void statement_list::add_statement(statement *stat){
	this -> add_child(stat);
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

 void decl_stat::add_local(local_node *l){
	 this -> add_child(l);
 }

local_node::local_node(std::string id, int count): id(id), count(count), variable(MOD_PUBLIC, id, SYM_LOCAL_VAR) {}
void local_node::accept(visitor *n){
	n -> visit_local_node(this);
}

void local_node::add_assignment(expression *exp){
	this -> add_child(exp);
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
void block_stat::accept(visitor *v){
	v -> visit_block_stat(this);
}

block_node::block_node(): scope(){}

void block_node::accept(visitor *v){
	v -> visit_block_node(this);
}

super_stat::super_stat(call_exp *c): statement(c){}
void super_stat::accept(visitor *n){
	n -> visit_super_stat(this);
}

op_exp::op_exp(expression *exp): expression(exp){
	//this -> exp_type = exp -> get_type(); 
}
op_exp::op_exp(expression *left, expression *right): expression(left, right) {
	//this -> exp_type = left -> get_type();
}     
void op_exp::accept(visitor *n){
	n -> visit_op_exp(this);
}

type_node *op_exp::get_type(){
	return ((expression*) get_child(0)) -> get_type();
}


name_exp::name_exp(std::string id): id(id), is_lhs(true), expression(){}
name_exp::name_exp(expression* exp, std::string id, bool is_call): id(id), is_call(is_call), is_lhs(false), expression(exp){}

void name_exp::accept(visitor *n){
	n -> visit_name_exp(this);
}

type_node* name_exp::get_type(){
		return this -> get_symbol() -> get_type(); 
}


void name_exp::set_type(type_node *type){
	this -> exp_type = type;
}

new_exp::new_exp(type_node *type): expression(type){}

void new_exp::accept(visitor *v){
	v -> visit_new_exp(this);
}

type_node *new_exp::get_type(){
	std::cout << "new type" << std::endl;
	return (type_node*) this -> get_child(0); 
}

new_array_exp::new_array_exp(type_node *type): expression(type){
	this -> exp_type = type;
}

expression* new_array_exp::get_dimension(int index){
	return (expression*) this -> get_child(index);
}
void new_array_exp::accept(visitor *n){
	n -> visit_new_array_exp(this);
}

type_node* new_array_exp::get_type(){
	return (type_node*) get_child(0);
}

call_exp::call_exp(name_exp* id, expression_list *actual_args): expression(id, actual_args){}
void call_exp::accept(visitor *n){
	n -> visit_call_exp(this);
}

type_node* call_exp::get_type(){
	std::cout << "ERROR: call type unimplemented" << std::endl;
	return NULL;
}
//ARRAY REFERENCE
 
array_ref::array_ref(name_exp *id, expression* dimension): expression(id, dimension){
	this -> exp_type = new array_type_node(new class_type(id -> get_name()));
}
array_ref::array_ref(expression* array_exp, expression* dimension){}
void array_ref::accept(visitor *n){
	n -> visit_array_ref(this);
}

type_node *array_ref::get_type(){
	return ((expression*) this -> get_child(0)) -> get_type();
}

//NULL

null_literal::null_literal(): literal(){
	this -> exp_type = new class_type("Object");
}
void null_literal::accept(visitor *n){
	n -> visit_null_literal(this);
}
type_node *null_literal::get_type(){
	return new null_node();
}

//BOOLEAN

bool_literal::bool_literal(bool val): val(val), literal(){
	this -> exp_type = new primative_bool();
}
void bool_literal::accept(visitor *n){
	n -> visit_bool_literal(this);
}
type_node * bool_literal::get_type(){
	return new primative_bool();
}

//INTEGER

int_literal:: int_literal(int val): val(val), literal(){
	this -> exp_type = new primative_int();
}
void int_literal::accept(visitor *n){
	n -> visit_int_literal(this);
}
type_node * int_literal::get_type(){
	return new primative_int();
}

char_literal::char_literal(char val): val(val), literal(){
	this -> exp_type = new primative_char();
}
void char_literal::accept(visitor *n){
	n -> visit_char_literal(this);
}
type_node * char_literal::get_type(){
	return new primative_char();
}

string_literal::string_literal(std::string val): val(val), literal(){
	this -> exp_type = new class_type("String");
}
void string_literal::accept(visitor *n){
	n -> visit_string_literal(this);
}
type_node * string_literal::get_type(){
	return new class_type("String");
}

expression_list::expression_list(): ast_node(){}
void expression_list::accept(visitor *n){
	n -> visit_expression_list(this);
}

expression* expression_list::get_expression(int index){
	return (expression *) get_child(index);
}

void expression_list::add_expression(expression *exp){
	this -> add_child(exp);
}

// VARIABLE 

variable::variable(int mod, std::string id, symbol_type sym_type, type_node *t): symbol(mod, id, sym_type, t){}
variable::variable(int mod, std::string id, symbol_type sym_type): symbol(mod, id, sym_type){}
void variable::set_type(type_node *type){
	this -> insert_child(type);
}

type_node *variable::get_type(){
	return (type_node*) this -> get_child(0);
}