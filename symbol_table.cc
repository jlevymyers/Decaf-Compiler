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
    cout << "inserted symbol: " << sym -> get_name() << ", field: " << this << endl;
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
            cout << &this -> classes << endl;
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
	    this -> outer_table = s -> get_table();;
    }
    else{
        this -> outer_table = NULL;
    }
}

ast::symbol* symbol_table::find_scope(string name){
    std::cout << "finding field/variable in local scope: " << name << std::endl;
    std::unordered_map<std::string, ast::symbol*>::iterator field_iter = this -> fields.find(name);
    std::unordered_map<std::string, ast::symbol*>::iterator var_iter = this -> variables.find(name);

    if(var_iter != variables.end()){
        cout << "found variable: " << name << endl; 
        return variables[name];   
    }
    else if(field_iter != fields.end()){
        cout << "found field: " << name << endl; 
        return fields[name];   
    }
    else if(this -> parent_table != NULL){
        return this -> parent_table -> find_scope(name);
    }
    else if(this -> super_table != NULL){
        return this -> super_table -> find_scope(name);
    }
    else{
        cout << "could not find field/var in object scope" << endl; 
        return NULL;
    }
}

ast::symbol* symbol_table::find_method(string name){
    std::unordered_map<std::string, ast::symbol*>::iterator iter = this -> methods.find(name);
    if(iter == methods.end()){ 
        //CHECK IF WE ARE A CLASS 
        if(parent_table == NULL){
            if(super_table == NULL){
                cout << "ERROR: object table could not resolve method" << endl;
                return NULL;
            }
            else{
                cout << "resolving method in super table" << endl;
                return this -> super_table -> find_method(name);
            }
        }
        else{
            cout << "resolving method in parent table" << endl;
            return this -> parent_table -> find_method(name);
        }
    }
    else{
        cout << "SUCCESS: found method symbol: " << name << endl;
        return methods[name];
    }
}

ast::symbol* symbol_table::find(string name){
    std::cout << "finding global symbol" << std::endl;
    if(this -> outer_table == NULL){
        if(this -> classes.find(name) == classes.end()){
            cout << "ERROR: couldn't find class in global scope: " << name << endl; 
            return NULL;
        }
        else{
            cout << "SUCCESS: found symbol: " << name << endl; 
            return classes[name];
        }
    }
    else{
        return this -> outer_table -> find(name);
    }
}