#ifndef TABLE_HH
# define TABLE_HH

# include <unordered_map>
# include <utility>
# include "ast.hh"

using namespace std;

class class_table;
class class_symbol;
class field_table;
class method_table; 
class method_symbol;
class field_symbol;

class symbol {
};

class variable_symbol : public symbol {
private: 
    int count; 
    expression *exp; 
public: 
    variable_symbol(); 
}

class field_symbol : public symbol {
private:
    int count; 
    ast::field_node *field; 
public:
    field_symbol();
};

class method_symbol : public symbol{
public:
    ast::method_node* method;
    unordered_map<string, ast::variable_symbol> variable_map;
    method_symbol(ast::method_node* method);
};

class class_symbol {
public:
    ast::unordered_map<string, ast::field_symbol> fields;
    ast::unordered_map<string, ast::method_symbol> methods; 
    ast::class_node *this_class; 
    ast::class_node *parent_class; 
    class_symbol(ast::class_node *this_class);
};

class class_table {
public: 
    void add_class(string id, ast::class_node *a_class);
    ast::class_node* get_class(string id);
    unordered_map<string, class_symbol> class_map;
    class_table();
};

#endif // ! TABLE_HH