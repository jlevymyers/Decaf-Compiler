#ifndef TABLE_HH
# define TABLE_HH

# include <unordered_map>
# include <utility>
# include "ast.hh"
# include "scope.hh"
# include "symbol.hh"



using namespace std;
/* 
//stores methods, and variables in their scope
class method_table {
public:
    ast::method_node* method;
    unordered_map<string, ast::variable*> variable_map;
    method_table(ast::method_node* method);
    
};

class class_table {
private: 
    unordered_map<string, ast::field_node*> fields;
    unordered_map<string, method_table*> methods; 
public:

    ast::class_node *this_class; 
    ast::class_node *parent_class; 
    class_table(ast::class_node *this_class);
}; */

class symbol_table {
private:
    symbol_table *parent_table;
    symbol_table *super_table; 
    symbol_table *outer_table; 
    unordered_map<string, ast::symbol*> classes;
    unordered_map<string, ast::symbol*> fields;
    unordered_map<string, ast::symbol*> methods; 
    unordered_map<string, ast::symbol*> variables;

public:
    symbol_table();
    ~symbol_table(){}
    ast::symbol *find(string name);
    ast::symbol *find_method(string name);
    ast::symbol *find_scope(string name);
    void add_symbol(ast::symbol *sym);
    void set_super_scope(ast::scope *s);
    void set_parent_scope(ast::scope *s);
    void set_outer_scope(ast::scope *s);

};
#endif // ! TABLE_HH