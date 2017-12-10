#ifndef AST_HH
# define AST_HH
//# include "visitor.hh"
# include <iostream>
# include <stdlib.h>
# include <string>
# include <vector>
# include <utility>
# include <cassert>

#include "ast_node.hh"
#include "scope.hh"
#include "symbol.hh"

namespace ast
{
//forward dec  lare AST
class variable;
class class_list;
class class_node;
class member_list; 
class super_node;
class member;
class field_decl;
class field_node; 
class method_node;
class method_body;
class constructor_node; 
class formal_list; 
class formal_node;
class type_node;
class class_type; 
class array_type_node; 
class primative_type;
class primative_int;
class primative_bool;
class primative_char;
class primative_void;
class null_node;
class init_node;
class meta_node;
class statement_list; 
class statement;
class empty_stat; 
class decl_stat;
class local_node;
class if_stat;
class expression_stat;
class while_stat; 
class return_stat;
class continue_stat;
class break_stat;
class block_stat;
class super_stat;
class expression;
class op_exp;
class name_exp;
class new_exp; 
class new_array_exp; 
class call_exp;
class array_ref;
class literal;
class null_literal;
class bool_literal;
class int_literal; 
class char_literal;
class string_literal;
class expression_list;

/* method modifiers */  

class outer_scope : public scope {
public:
	outer_scope();
	void accept(visitor *v);
	void add(ast_node* n);
};

class variable : public symbol {
private: 
	int offset; 
public:
	virtual ~variable(){}
	variable(int mod, std::string id, symbol_type sym_type, type_node *t);
    variable(int mod, std::string id, symbol_type sym_type);
	int get_offset(); 
	int set_offset(int off);
	void set_type(type_node *type);
	type_node* get_type();
};


class class_list: public ast_node {
public:
	class_list(class_node *c);
	void visit_children(visitor *v);
	class_node* get_class(int index);
	void accept(visitor *v);

	void add_class(class_node *c);
};

class class_node : public symbol {
public:
	void accept(visitor *v);
	super_node* get_super();
	member_list* get_members();
	type_node* get_type();
	scope *get_associated_scope();

	class_node(std::string id, super_node *super, member_list *mlist);
};

class member_list : public scope {
public:
	member_list();
	void accept(visitor *v);

	ast_node* get_member(int index){
		assert(index > 0 && index < this -> num_children());
		return (ast_node*) this -> get_child(index);
	}

	void add_member(ast_node *m){
		this -> add_child(m);
	}
};

//NOTE: use Object
class super_node : public ast_node {
public:
	void accept(visitor *v);
	super_node(type_node *type);

	class_type *get_super_type(){
		return (class_type*) this -> get_child(0);
	}
};

class field_decl : public ast_node {
private:
	int modifiers;
public:
	void accept(visitor *v); 
	field_decl(){}
	void set_modifiers(int mod){
		this -> modifiers = mod;
	}
	void set_type(type_node *type){
		//this -> add_child(type);
	}

	void add_field(field_node *f);

};

//initializer???
class field_node : public variable {
private:
	std::string id; 
	int count;
public:
	void accept(visitor *v);
	expression *get_init();

	void add_assignment(expression *exp);

	field_node(std::string id, int count): count(count), variable(MOD_NONE, id, SYM_FIELD){}
};

class method_node : public symbol {
private:
	int id;
	int modifiers;
public:
	void accept(visitor *v);
	//constructors 
	method_node(int modifiers, std::string id, symbol_type sym_type, type_node *type, method_body *body); 
	method_node(int modifiers, std::string id, type_node *type, method_body *body);

	type_node *get_type(){
		return (type_node* ) this -> get_child(0);
	} 
};

class method_body : public scope {
public: 
	void accept(visitor *v);
	method_body(formal_list *flist, statement_list *slist); 
	
	formal_list *get_formal_args(){
		return (formal_list*) this -> get_child(0);
	}

};

//constructor node
class constructor_node : public method_node {
public:
    void accept(visitor *v);	
	constructor_node(int modifiers, std::string id, method_body *body); 
};

class formal_list : public ast_node {
public:
	void accept(visitor *v);
	formal_list(); 

	void add_formal(formal_node *formal);
	void add_formal_first(formal_node *formal);
};

class formal_node : public variable {
private:
	int id; 
public:
	void accept(visitor *v);
	formal_node(type_node *type, std::string id);

};

class type_node : public ast_node {
private:
	std::string type_id; 
	symbol * assoc_sym; 
public:
	void set_symbol(symbol *s){
		this -> assoc_sym = s;
	}

	symbol *get_symbol(){
		return this -> assoc_sym; 
	}

	virtual scope* get_associated_scope(){
		return NULL;
	}



 	void accept(visitor *v);

	std::string get_name();
	
	type_node(std::string id);
};

class class_type : public type_node {
private:
	scope *class_scope; 
	class_type *super_type; 
	symbol *class_symbol; 
	int class_length; 
	int vtable_length; 
public:
	class_type(std::string id);

	scope *get_associated_scope(){
		std::cout << "getting associated scope: " << this -> class_scope << std::endl;
		return this -> class_scope;
	}

	symbol *get_symbol(){
		return this -> class_symbol;
	}

	class_type *get_super_type(){
		return this -> super_type;
	}

	void set_symbol(symbol *s){
		this -> class_scope = s -> get_associated_scope();
		assert(this -> class_scope);
		this -> class_symbol = s; 
	}

	void accept(visitor *v);
};

class array_type_node : public type_node {
public:
	array_type_node(type_node* type);
	class_type *get_array_base(){
		assert(this -> get_child(0));
		return ((class_type*) this -> get_child(0));
	}
	void accept(visitor *v);
};

class primative_int : public type_node {
public:
	void accept(visitor *v);
	primative_int();
};

class primative_bool : public type_node {
public:
	void accept(visitor *v);
	primative_bool();
};

class primative_char : public type_node {
public:
	void accept(visitor *v);
	primative_char(); 
};

class primative_void : public type_node {
public:
	void accept(visitor *v);
	primative_void();
};

class null_node : public type_node {
public:
	void accept(visitor *v);
	null_node();
};

class init_node : public type_node {
public:
	void accept(visitor *v);
	init_node();
};

class meta_node : public type_node {
public:
	void accept(visitor *v);
	meta_node();
};

class statement_list : public ast_node {
public:
	void accept(visitor *v);
	statement_list();

	void add_statement(statement *stat);
};

class statement : public ast_node {
public:
	statement(): ast_node(){}
	statement(ast_node *a): ast_node(a){}
	statement(ast_node *a, ast_node *b): ast_node(a,b){}
	statement(ast_node *a, ast_node *b, ast_node *c): ast_node(a,b,c){}
	statement(ast_node *a, ast_node *b, ast_node *c, ast_node *d): ast_node(a,b,c,d){}
	virtual void accept(visitor *v) = 0;

	void add_type(type_node *type);

	virtual ~statement();
};

class empty_stat : public statement {
public:
	empty_stat();
	void accept(visitor *v);
};

class decl_stat : public statement {
private: 
	std::string id;
public:
	decl_stat(); 
	void set_type(type_node* type);
	void accept(visitor *v);

	void add_local(local_node* l);

};

class local_node : public variable {
private:
	std::string id;
	int count;
public:
	local_node(std::string id, int count);
	void add_assignment(expression *exp);
	void accept(visitor *v);
};

class if_stat : public statement {
public: 
	if_stat(expression *exp, statement *stat);
	if_stat(expression *exp, statement *if_stat, statement *else_stat); 
	void accept(visitor *v);
};

class expression_stat : public statement {
public: 
	expression_stat(expression *exp); 
	void accept(visitor *v);
};

class while_stat : public statement {
public:
	while_stat(expression* exp, statement* stat);
	void accept(visitor *v);
};

class return_stat : public statement {
public: 
	return_stat();
	return_stat(expression *exp);
	void accept(visitor *v);
};

class continue_stat : public statement {
public:
	continue_stat();
	void accept(visitor *v);
};

class break_stat : public statement {
public:
	break_stat();
	void accept(visitor *v);
};

class block_stat : public statement {
public:
	block_stat(statement_list *stats); 
	void accept(visitor *v);
};

class block_node : public scope {
public: 
	block_node();
	void accept(visitor *v);  
};

class super_stat : public statement {
public:
	super_stat(call_exp *c); 
	void accept(visitor *v);
};

class expression : public ast_node {
protected: 
	type_node *exp_type;
public:
	virtual ~expression();
	expression(){}
	expression(ast_node *a): ast_node(a){}
	expression(ast_node *a, ast_node *b): ast_node(a,b){}
	expression(ast_node *a, ast_node *b, ast_node *c): ast_node(a,b,c){}
	expression(ast_node *a, ast_node *b, ast_node *c, ast_node *d): ast_node(a,b,c,d){}

	virtual type_node* get_type() = 0;

	virtual void accept(visitor *v) = 0;
};

class op_exp : public expression {
private: 
	int op; 
public:
       op_exp(expression *exp);
	   op_exp(expression *left, expression *right);	

		type_node* get_type();

	   void accept(visitor *v);       
};


class name_exp : public expression {
private:
	std::string id;
	bool is_call;
	bool is_lhs;
	symbol * assoc_sym; 
public: 
	void set_symbol(symbol *s){
		this -> assoc_sym = s;
	}

	symbol *get_symbol(){
		return this -> assoc_sym; 
	}

	type_node* get_type();

	std::string get_name(){
		return this -> id;
	}

	bool get_is_call(){
		return this -> is_call;
	}

	bool get_is_lhs(){
		return this -> is_lhs;
	}

	void set_type(type_node *type);

	name_exp(std::string id);
	name_exp(expression* exp, std::string id, bool is_call);

	expression* get_expression(){
		assert(this -> num_children() == 1);
		//std::cout << ((expression*) get_child(0)) -> get_type() << std::endl;
		return (expression *) this -> get_child(0);
	}

	void accept(visitor *v);
};

class new_exp : public expression {
public:
	new_exp(type_node* exp);
	type_node *get_type();
	void accept(visitor *v);
};

class new_array_exp : public expression {
private: 
	type_node* type; 
public:
	new_array_exp(type_node *type); 
	expression* get_dimension(int index);
	void add_dimension(expression* exp){
		this -> add_child(exp);
	}

	type_node* get_type(); 
	void accept(visitor *v);
};

class call_exp: public expression {
public: 
	call_exp(name_exp* id, expression_list *actual_args);

	name_exp* get_method(){
		return (name_exp*) this -> get_child(0);
	}

	type_node* get_type(); 
	void accept(visitor *v);
};

class array_ref : public expression {
public: 

	array_ref(name_exp *id, expression* dimension);
	array_ref(expression* array_exp, expression* dimension); 

	type_node* get_type(); 
	void accept(visitor *v);
};

class literal : public expression {
public:
	virtual void accept(visitor *v) = 0;
	virtual type_node* get_type() = 0;
	~literal();
}; 

class null_literal : public literal {
public: 
	null_literal();
	type_node* get_type(); 
	void accept(visitor *v);
};

class bool_literal : public literal {
private:
	bool val; 
public: 
	bool_literal(bool val);
	type_node* get_type(); 
	void accept(visitor *v);
};

class int_literal : public literal {
private:
	int val;
public:
	int_literal(int val);
	type_node* get_type(); 
	void accept(visitor *v);
};

class char_literal : public literal {
private:
	char val; 
public:
	char_literal(char val);
	type_node* get_type(); 
	void accept(visitor *v);
};

class string_literal : public literal {
private:
	std::string val; 
public:
	string_literal(std::string val);
	type_node* get_type(); 
	void accept(visitor *v);
};

class expression_list : public ast_node {
public: 
	expression_list();
	expression* get_expression(int index);
	void add_expression(expression *exp);
	void accept(visitor *v); 
};
};

#endif // ! AST_HH


