#ifndef AST_HH
# define AST_HH
//# include "visitor.hh"
# include <iostream>
# include <stdlib.h>
# include <string>
# include <map>
# include <vector>

class visitor;

namespace ast
{

/* method modifiers */  

enum mods {
	MOD_NONE = 0,
	MOD_STATIC,
	MOD_PUBLIC,
	MOD_PRIVATE,
	MOD_PROTECTED
};

//forward declare AST
class symbol;
class ast_node;
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

using namespace std;

class ast_node {
private: 
	vector<ast_node*> ast_children;
	int ast_id; 
	static int ast_count; 
public:
	void visit_children(visitor* v); 
	ast_node* get_child(int index);
	void add_child(ast_node* a);
	void insert_child(ast_node* a);
	int num_children(); 
	virtual void accept(visitor* v);
	virtual ~ast_node();
	ast_node();
	ast_node(ast_node *a);
	ast_node(ast_node *a, ast_node *b);
	ast_node(ast_node *a, ast_node *b, ast_node *c); 
	ast_node(ast_node *a, ast_node *b, ast_node *c, ast_node *d);
};


class symbol : public ast_node {
public:
	symbol(): ast_node(){}
	symbol(ast_node* a): ast_node(a){}
	virtual ~symbol(){}
	virtual void accept(visitor *v) = 0;
};

class class_list: public ast_node {
public:
	void visit_children(visitor *v);
	class_node* get_class(int index);
	void accept(visitor *v);
	class_list(class_node *a_class); 
};

class class_node : public ast_node {
private:
	std::string id; 
public:
	void accept(visitor *v);
	type_node* get_type();
	member_list* get_member_list();
	super_node* get_super();
	class_node(std::string, super_node *super, member_list *mlist);
};

class member_list : public ast_node {
public:
	void accept(visitor *v);
	member_list();
};

//NOTE: use Object
class super_node : public ast_node {
public:
	void accept(visitor *v);
	super_node(type_node *type);
};

class member : public ast_node {
private: 
	int modifiers; 
public:
	virtual ~member();
	virtual void accept(visitor *v) = 0;
	member();
	member(ast_node *a, ast_node *b);
	member(ast_node *a, ast_node *b, ast_node *c, ast_node *d);
	void set_modifiers(int modifiers);
};

class field_decl : public member {
private:
	int id; 
	int modifiers;
public:
	void accept(visitor *v); 
	field_decl();
};

//initializer???
class field_node : public symbol {
private:
	std::string id; 
	int count;
public:
	void accept(visitor *v);
	expression *get_init();
	field_node(string id, int count); 
	
};

class method_node : public member {
private:
	int id;
	int modifiers;
public:
	void accept(visitor *v);
	method_node(int modifiers, type_node *type, method_body *body); 
};

class method_body : public ast_node {
public: 
	void accept(visitor *v);
	method_body(formal_list *flist, statement_list *slist); 
};

//constructor node
class constructor_node : public member {
private:
	int id;
	int modifiers;
public:
    void accept(visitor *v);	
	constructor_node(int modifiers, type_node *type, method_body *body); 
};

class formal_list : public ast_node {
public:
	void accept(visitor *v);
	formal_list(); 
};

class formal_node : public symbol {
private:
	int id; 
public:
	void accept(visitor *v);
	formal_node(type_node *type);
};

class type_node : public ast_node {
	string type_id; 
public:
	virtual void accept(visitor *v);
	virtual ~type_node();
	string get_name();
	type_node(string id);
};

class class_type : public type_node {
private: 
	string id;	
public:
	class_type(string id);
	string get_name();
	void accept(visitor *v);
};

class array_type_node : public type_node {
public:
	array_type_node(type_node* type);
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
};

class statement : public ast_node {
public:
	statement(): ast_node(){}
	statement(ast_node *a): ast_node(a){}
	statement(ast_node *a, ast_node *b): ast_node(a,b){}
	statement(ast_node *a, ast_node *b, ast_node *c): ast_node(a,b,c){}
	statement(ast_node *a, ast_node *b, ast_node *c, ast_node *d): ast_node(a,b,c,d){}
	virtual void accept(visitor *v) = 0;
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
};

class local_node : public symbol {
private:
	string id;
	int count;
public:
	local_node(string id, int count);
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

class super_stat : public statement {
public:
	super_stat(call_exp *c); 
	void accept(visitor *v);
};

class expression : public ast_node {
public:
	virtual ~expression();
	expression(){}
	expression(ast_node *a): ast_node(a){}
	expression(ast_node *a, ast_node *b): ast_node(a,b){}
	expression(ast_node *a, ast_node *b, ast_node *c): ast_node(a,b,c){}
	expression(ast_node *a, ast_node *b, ast_node *c, ast_node *d): ast_node(a,b,c,d){}
	virtual void accept(visitor *v) = 0;
};

class op_exp : public expression {
private: 
	int op; 
public:
       op_exp(ast_node *exp);
	   op_exp(ast_node *left, ast_node *right);	
		void accept(visitor *v);       
};


class name_exp : public expression {
private:
	string id;
public: 
	string get_name();
	name_exp(string id);
	void accept(visitor *v);
};

class new_array_exp : public expression {
private: 
	type_node* type; 
public:
	new_array_exp(type_node *type); 
	expression* get_dimension(int index);
	void accept(visitor *v);
};

class call_exp: public expression {
public: 
	call_exp(name_exp* id, expression_list *actual_args);
	void accept(visitor *v);
};

class array_ref : public expression {
public: 
	array_ref(name_exp *id, expression* dimension);
	array_ref(expression* array_exp, expression* dimension); 
	void accept(visitor *v);
};

class literal : public expression {
public:
	virtual void accept(visitor *v) = 0;
	~literal();
}; 

class null_literal : public literal {
public: 
	null_literal();
	void accept(visitor *v);
};

class bool_literal : public literal {
private:
	bool val; 
public: 
	bool_literal(bool val);
	void accept(visitor *v);
};

class int_literal : public literal {
private:
	int val;
public:
	int_literal(int val);
	void accept(visitor *v);
};

class char_literal : public literal {
private:
	char val; 
public:
	char_literal(char val);
	void accept(visitor *v);};

class string_literal : public literal {
private:
	string val; 
public:
	string_literal(string val);
	void accept(visitor *v);
};

class expression_list : public ast_node {
public: 
	expression_list();
	expression* get_expression(int index);
	void accept(visitor *v); 
};
};

#endif // ! AST_HH


