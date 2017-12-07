# include "symbol_table.hh"
# include "symbol.hh"

using namespace std;

symbol_table::symbol_table(){
    classes = unordered_map<string, ast::symbol*>();
    fields = unordered_map<string, ast::symbol*>() ;
    methods = unordered_map<string, ast::symbol*>() ; 
    variables = unordered_map<string, ast::symbol*>() ;
}

void symbol_table::add_symbol(ast::symbol *sym){
    cout << "inserted symbol: " << sym -> get_name() << endl;
    switch(sym -> get_symbol_type()){
	  case ast::SYM_FORMAL_ARG: {
        this -> variables[sym -> get_name()] = sym;
        cout << "created variable" << endl;
        break;
      }
	case ast::SYM_FIELD: {
        this -> fields[sym -> get_name()] = sym;
        cout << "created field" << endl;
        break;
      }
	case ast::SYM_LOCAL_VAR: {
        this -> variables[sym -> get_name()] = sym;
        cout << "created local" << endl;
        break;
       }
	   // case ast::SYM_CLASS: 
    case ast::SYM_CLASS: {
            this -> classes[sym -> get_name()] =  sym;
            cout << "created classs" << endl;
            break;
       }
    case ast::SYM_CTOR: {
        this -> methods[sym -> get_name()] = sym;
        cout << "created constructor" << endl;
        break;
    }
    case ast::SYM_METHOD: {
        this -> methods[sym -> get_name()] = sym;
        cout << "created method" << endl;
        break;
    }
    case ast::SYM_NONE: {
        cout << "attempted to insert non-symbol: " << sym -> get_name() << sym -> get_symbol_type() << endl;
        break;
    }
    default: {
        cout << "reached default" << endl;
    }
    }
}

void symbol_table::set_super_scope(ast::scope *s){
    if(s != NULL){
	    this -> super_table = s -> get_table(); 
    }
    else{
        this -> super_table = NULL;
    }
}
void symbol_table::set_parent_scope(ast::scope *s){
    if(s != NULL){
	    this -> parent_table = s -> get_table();;
    }
    else{
        this -> parent_table = NULL;
    }
}

void symbol_table::set_outer_scope(ast::scope *s){
    if(s != NULL){
	    this -> parent_table = s -> get_table();;
    }
    else{
        this -> parent_table = NULL;
    }
}

ast::symbol* symbol_table::find_scope(string name){
    if(this -> classes.find(name) == classes.end()){
        if(this -> parent_table){
            cout << "searching parent for: " << name << endl; 
            return parent_table -> find(name);
        }
        else{
            cout << "could not find symbol: " << name << endl; 
            return NULL;
        }
    }
    else{
        cout << "found symbol: " << name << endl; 
        return classes[name];
    }
}


ast::symbol* symbol_table::find(string name){
    if(this -> outer_table -> classes.find(name) == classes.end()){
        cout << "could not find symbol in global scope: " << name << endl; 
        return NULL;
    }
    else{
        cout << "found global symbol: " << name << endl; 
        return classes[name];
    }
}
