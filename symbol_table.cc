# include "symbol_table.hh"

#ifndef TABLE_HH
# define TABLE_HH

# include <unordered_map>
# include <utility>
# include "ast.hh"

using namespace std;

class method_table {
public:
    ast::method_node* method;
    unordered_map<string, ast::variable_symbol> variable_map;
    method_table();
    A
};

class class_table {
public:
    ast::unordered_map<string, ast::field_node> fields;
    ast::unordered_map<string, ast::method_table> methods; 
    ast::class_node *this_class; 
    ast::class_node *parent_class; 
    class_table(ast::class_node *this_class);
};

class symbol_table{
private:
    symbol_table *parent;
    symbol_table *super; 
    class_table *class_map; 
public:
    symbol *find(string name);
    symbol *find_method(string name);
    symbol *find_scope(string name);
    symbol *add_symbol(symbol *sym);
}
#endif // ! TABLE_HH