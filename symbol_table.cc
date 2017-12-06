# include "symbol_table.hh"

field_table::field_table(): 
    field_map(unordered_map<string, ast::field_node*>()){}

method_table::method_table(): 
    method_map(unordered_map<string, method_symbol>()){}

method_symbol::method_symbol(ast::method_node *method): 
    method(method), 
    variable_map(unordered_map<string, ast::symbol*>()){}

class_symbol::class_symbol(ast::class_node *this_class): 
    fields(field_table()), 
    methods(method_table()),
    this_class(this_class){}

class_table::class_table(): 
    class_map(unordered_map<string, class_symbol>()){
        //MORE work needs to be done
        this -> add_class("Object", NULL);
    }

void class_table::add_class(string id, ast::class_node *a_class){
    pair<string, class_symbol> ins (id, a_class);
    this -> class_map.insert(ins);
}

ast::class_node* class_table::get_class(string id){
    return this -> class_map.at(id).this_class;
}