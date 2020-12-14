/*
* William Cary
* dispatcher.cpp
* Program 5, Compilers
* Nov 25, 2020
* Contains all different nodes
*/

/*
 Multiple Symbol tables pros:
  Easy to navigate through each one just get the next pointer, and do it recursively.
  Easy namespace system:
  Can still mangle parameters into the the name of the symbol allowing for overloading.
  Wouldn't be too difficult to manage enclosing/class, global and current scope inside
  of the symbolTable Builder.
 Cons:
  have to work with pointers, which will probably suck since you will have to store them in a vector
  this will result in some complications with determining if you are at the right node of the symbol table tree
  could be solved by storing additional information inside Symbol object, but that's just wasted space in memory 
  and clutters design.
 One symbol table with mangled names pros:
  Wouldn't be too difficult to mangle names.
  Easy namespace system just prepend type information to names until you arrive at the correct name
  Wouldn't require any pointers, wouldn't require function to iterate through tree just creating strings
  Making some of the 


 */

#include <string>
#include <vector>
#include <iostream>
#include "symboltable.hpp"
#include "nodevisitor.hpp"
#include "Node.hpp"
using namespace std;


NodeVisitor::NodeVisitor() {}

SymbolTableBuilder::SymbolTableBuilder() {
  symt = SymbolTable();
	currentScope = "";
	classScope = "";
  // initialize the built in types and functions
  Symbol syb;
  syb.value = "int";
  syb.order = "class";
	symt.insert("@int", syb);
  syb.value = "void";
  syb.order = "rType";
 	symt.insert("@void", syb);
  syb.value = "print";
  syb.order = "method";
  syb.rType = "@void";
  symt.insert("@print", syb);
  syb.value = "read";
  syb.order = "method";
  syb.rType = "@void";
}


void SymbolTableBuilder::print(){
	for(string name : names){
		Symbol sym = symt.lookup(name);
		string tabs = "";
		for(int i = 1; i < name.size(); i++){
			if(name[i] == '@')
				tabs += "  ";
		}
		if(sym.order.compare("class") == 0) {
				cout << tabs << sym.value << " class_type " << endl;
		}
		if(sym.order.compare("constr") == 0) {
			cout << tabs << sym.value << " method_type " << " void <- ";
			if(sym.params.size() == 0) cout << "void ";
			else for(string param : sym.params) cout << param << " , ";
			cout << endl; 
		}
		if(sym.order.compare("method") == 0){
			cout << tabs << sym.value << " method_type " << sym.rType << " <- ";
			if(sym.params.size() == 0) cout << "void ";
			else for(string param : sym.params) cout << param <<  " , "; 

			cout << endl; 
		}
		if(sym.order.compare("var") == 0){
			cout << tabs << sym.value << " " << sym.type << endl;
		}
	}
}

int SymbolTableBuilder::checkErrors(){
	for(tuple<string, string> error : errors){
		// <type, name>
		Symbol errSym = symt.lookup("@" + get<0>(error));
		if(errSym.notFound == true){
			cout << "No symbol " << get<0>(error) << " was declared for variable/method "
				<< get<1>(error) << endl;
		}
		else {
			//cout << "Found class " << get<0>(error);
			symt.modFoundStatus(get<1>(error));
		}
	}
	return 0;
}

int SymbolTableBuilder::start(Node & node){
  for(int i = 0; i < node.size(); i++){
    node.at(i)->accept(*this);
  }
	checkErrors();
  return 0;
}

int SymbolTableBuilder::visit(Node & node){
  // cout << "No definied behavior for default node" << endl;
  // cout << "Returning default node" << endl;
  return -1;
}


int SymbolTableBuilder::visit(NodeList & node){
	for(int i = 0; i < node.size(); i++){
		node.at(i)->accept(*this);
	}
	return 0;
}

int SymbolTableBuilder::visit(Root & node){

	return 0;
}

int SymbolTableBuilder::visit(ClassDec & node){
  string name = "@";
	name += node.getIdent();
	names.push_back(name);
	Symbol sym;
	sym.value = node.getIdent();
	sym.order = "class";
	if(symt.insert(name, sym) < 0) {
		cerr << "class " << node.getIdent() << " already exists!" <<endl;
		return -1;
	}
	currentScope = name;
	classScope = name;
	node.classbody->accept(*this);
	currentScope =  "";
	classScope = "";
	return 0;
}


/* 
 * returns 0 when successful
 * returns -1 when the variable's name is reserved for the constructor
 * returns -2 when the variable already exists
 * returns -3 when the variable's type can't be found
*/
int SymbolTableBuilder::visit(VarDec & node){
	string name = currentScope + "@" + node.getIdent();
	if(classScope.compare("@" + node.getIdent()) == 0){
		cerr << "Variable name " << node.getIdent() 
			<< " is reserved for the constructor " << endl;
		return -1; 
	} 
	Symbol sym;
	sym.value = node.getIdent();
	sym.order = "var";
	int err = node.child->accept(*this);
	if(err == -1){
		sym.notFound = true;
		errors.push_back(make_tuple(get<0>(varConstruction), name));
	}
	sym.type = get<0>(varConstruction);
	for(int i=0; i < get<1>(varConstruction); i++){
		sym.arrSize.push_back(0);
	}
	if(symt.insert(name, sym) < 0){
		cerr << "var " << node.getIdent() << " already exists in class "
			<< classScope.substr(1) << endl;
		return -3;
	}
	symt.addVar(currentScope, node.getIdent());
	names.push_back(name);
	varConstruction = make_tuple("", 0);

	return 0;
}

/*
 * returns -1 when constructor's name is not recognized
 * returns -2 when constructor already exists 
*/
int SymbolTableBuilder::visit(ConstrDec & node){
	params.clear();
	if(classScope.compare("@" + node.getIdent())) {
		cerr << "Constructors name not recognized" << endl;
		return -1;
	}
	string name = currentScope + "@" + node.getIdent() + "#";
	Symbol sym;
	sym.order = "constr";
	sym.value = node.getIdent();
	sym.rType = classScope.substr(1);
	currentScope = currentScope + "@" + node.getIdent();
	for(int i = 0; i < node.argChild->size(); i++){
		node.argChild->at(i)->accept(*this);
		sym.params.push_back(get<0>(varConstruction));
		name += get<0>(varConstruction) + "&";
	}

	name += "#"; // end of parameters indicator
	names.push_back(name);
	if(symt.insert(name, sym) == -1){
		cerr << "Constructor for class " << classScope.substr(1) << " with parameters ";
		for(int i = 0; i < sym.params.size(); i++)
			cerr << sym.params[i] << " ";
		cerr << "already exists " << endl; 
		currentScope = classScope;
		return -2;
	}
	for(int i = 0; i < params.size(); i++){
		string varName = name + "$1@" + params[i].value;
		symt.insert(varName, params[i]); 
		names.push_back(varName);
	}
	symt.addMeth(classScope, node.getIdent());
  blockCount = 1;
	currentScope = name;
	node.block->accept(*this);
  blockCount = 0; 
	currentScope = classScope;
	return 0;
}

/*
 * Returns -3 if the function is main but there is an error parsing it
 * 	does not continue to parse after this error.
 * 
*/
int SymbolTableBuilder::visit(MethodDec & node){
	params.clear();
	if(classScope.compare("@" + node.getIdent()) == 0){
		cerr << "Variable name " << node.getIdent() 
			<< " is reserved for the constructor " << endl;
		return -1; 
	}
	string name = currentScope + "@" + node.getIdent() + "#";
	Symbol sym;
	sym.order = "method";
	sym.value = node.getIdent();
	// get the return type 
	node.resultChild->accept(*this);
	sym.rType = get<0>(varConstruction);
	Symbol errSym = symt.lookup("@" + get<0>(varConstruction));
	for(int i = 0; i < get<1>(varConstruction); i++){
		sym.arrSize.push_back(0);
	}
	
	currentScope = currentScope + "@" + node.getIdent();
	for(int i = 0; i < node.argChild->size(); i++){
		node.argChild->at(i)->accept(*this);
		sym.params.push_back(get<0>(varConstruction));
		name += get<0>(varConstruction) + "&";
	}
	name += "#"; // end of parameters indicator
	names.push_back(name);
	if(node.getIdent().compare("main") == 0){
		if(mainfunc == true){
			cerr << "main function already exists" << endl;
			return -3;
		}
		else {
			if(sym.rType.compare("void") == 0 || sym.rType.compare("int") == 0) {
				mainfunc = true;
			}
			else {
				cerr << "main function must have a return type of int or void" << endl;
				return -3;
			}
		}
	}
	if(symt.insert(name, sym) == -1){
		cerr << "Constructor for class " << classScope.substr(1) << " with parameters ";
		for(int i = 0; i < sym.params.size(); i++)
			cerr << sym.params[i] << " ";
		cerr << "already exists " << endl; 
		return -2;
	}
	for(int i = 0; i < params.size(); i++){
		string varName = name + "$1@" + params[i].value;
		symt.insert(varName, params[i]); 
	
		names.push_back(varName);
	}
	if(errSym.notFound){
		sym.notFound = true;
		errors.push_back(make_tuple(sym.rType, name));
	}
	symt.addMeth(classScope, node.getIdent());
  blockCount = 1;
	//cout << "Modifying current scope from " << currentScope << " to " << name << endl;
	currentScope = name;
	node.block->accept(*this);
  blockCount = 0;
	//cout << "Returning current scope from " << currentScope << " to " << classScope << endl;
	currentScope = classScope;
	return 0;
}

int SymbolTableBuilder::visit(ClassBody & node){
	for(int i = 0; i < node.vars->size(); i++){
		node.vars->at(i)->accept(*this);
	}
	for(int i = 0; i < node.constructors->size(); i++){
		node.constructors->at(i)->accept(*this);
	}
	for(int i = 0; i < node.methods->size(); i++){
		node.methods->at(i)->accept(*this);
	}
	return 0;
}

int SymbolTableBuilder::visit(Type & node){
	int err = node.child->accept(*this);
	get<1>(varConstruction) = node.multibrackets->size();
	if(node.multibrackets->size() > 0) get<0>(varConstruction) += "%" 
		+ to_string(node.multibrackets->size()); 
	return err;
}

int SymbolTableBuilder::visit(SimpleType & node){
	string name = "@" + node.getIdent();
	Symbol err = symt.lookup(name);
	int error = 0;
	if(err.notFound){
		error = -1;
	}
	get<0>(varConstruction) = node.getIdent();
	return error;
}

int SymbolTableBuilder::visit(ResultType & node){
	if(node.child == 0){
		get<0>(varConstruction) = "void";
		get<1>(varConstruction) = 0;
		return 0;
	}
	return node.child->accept(*this);
	
}

int SymbolTableBuilder::visit(ParamList & node){
	for(int i = 0; i < node.size(); i++){
		node.at(i)->accept(*this);
	}
	return 0;
}

int SymbolTableBuilder::visit(Parameter & node){
	string name = currentScope + "$1@" + node.getIdent();
	if(classScope.compare("@" + node.getIdent()) == 0){
		cerr << "Parameter name " << node.getIdent() 
			<< " is reserved for the constructor " << endl;
		return -1; 
	}
	Symbol sym;
	sym.order = "var";
	sym.value = node.getIdent();
	int err = node.child->accept(*this);
	if(err == -1){
		sym.notFound = true;
	}
	else sym.notFound = false;
	sym.type = get<0>(varConstruction);
	for(int i=0; i < get<1>(varConstruction); i++){
		sym.arrSize.push_back(0);
	}
	params.push_back(sym);
	
	//varConstruction = make_tuple("", 0);
	return 0;
}

int SymbolTableBuilder::visit(Block & node){
	string enclosingScope = currentScope; 
	enclosingBlocks.push_back(enclosingScope);
	string name = currentScope + "$" + to_string(blockCount);
	currentScope = name; 
	for(int i=0; i < node.localvars->size(); i++){
		node.localvars->at(i)->accept(*this);
	}
	for(int i = 0; i < node.statements->size(); i++){
		node.statements->at(i)->accept(*this);
	}
	currentScope = enclosingScope;
	enclosingBlocks.pop_back();
	return 0;
}

int SymbolTableBuilder::visit(LocalVarDecs & node){
	for(int i = 0; i < node.size(); i++){
		node.list.at(i)->accept(*this);
	}
	return 0;
}

int SymbolTableBuilder::visit(LocalVarDec & node){
	string name = currentScope + "@" + node.getIdent();
	if(classScope.compare("@" + node.getIdent()) == 0){
		cerr << "Variable name " << node.getIdent() 
			<< " is reserved for the constructor " << endl;
		return -1; 
	} 
	Symbol sym;
	sym.value = node.getIdent();
	sym.order = "var";
	int err = node.child->accept(*this);
	if(err == -1){
		errors.push_back(make_tuple(get<0>(varConstruction), name));
	}
	sym.type = get<0>(varConstruction);
	for(int i=0; i < get<1>(varConstruction); i++){
		sym.arrSize.push_back(0);
	}
	if(symt.insert(name, sym) < 0){
		cerr << "var " << node.getIdent() << " already exists in scope "
			<< currentScope.substr(1) << endl;
		return -3;
	}
	//cout << "added successfully: " << name << endl;
	names.push_back(name);
	varConstruction = make_tuple("", 0);
	return 0;
}

int SymbolTableBuilder::visit(Statement & node){
	node.stat->accept(*this);
	return 0;
}

int SymbolTableBuilder::visit(AssignStatement & node){
  rType = "NONE"; // To check if it doesn't change
	int r = node.name->accept(*this);
	if(r == -4){
		errorStats.push_back(&node);
		return -1;
	}
	if(r != 0){
		printNameError(r);
		return -1;
	}
	string leftType = symt.lookup(assemName).type;
	r = node.exp->accept(*this);

	if(r != 0){
		printNameError(r);
		return -1;
	}
	assemName = "";
	if(leftType.compare(rType) != 0){
		cerr << "Types do not match in assign statement: " << leftType 
			<< " and " << rType << " for variable " << assemName << endl;
		return -1;
	}
	
	return 0;
}

int SymbolTableBuilder::visit(FuncCallStatement & node){
	return 0;
}

int SymbolTableBuilder::visit(PrintStatement & node){
	return 0;
}

int SymbolTableBuilder::visit(WhileStatement & node){
	return 0;
}

int SymbolTableBuilder::visit(ReturnStatement & node){
	return 0;
}

int SymbolTableBuilder::visit(BlockStatement & node){
	blockCount++;
	node.block->accept(*this);
	return 0;
}

int SymbolTableBuilder::visit(IfStatement & node){
	return 0;
}

int SymbolTableBuilder::visit(IfElseStat & node){
	return 0;
}
/*
 * returns 1 when the name resolved is a method
 * returns 0 when the value returned is a variable
 * returns -1 when the variable does't exist
 * returns -2 when their is some other error
 * returns -3 when "this" is not at the start
 * returns -4 when the  type does not exist (yet)
 * This should not print errors that should be handled by its parent
 * Most important node for type checking. 
*/
int SymbolTableBuilder::visit(Name & node){
	if(node.getIdent().compare("this") == 0){
		if(assemName.length() != 0){
			return -3;
		}
		assemName += classScope;
	}
	else {
		if(assemName.length() == 0){
			// iterate through all the enclosing blocks to check for the variable
			bool found = false; 
			for(auto scope : enclosingBlocks){
				string tmpName = scope + "@" + node.getIdent();
				Symbol sym = symt.lookup(tmpName);
				if(!sym.notFound) {
					found = true;
					assemName = scope + "@" + node.getIdent();
				}
			}
			// check class scope if cant be found in enclosing scopes
			if(!found){
				// check if there exists a method in the current scope by the name
				for(string vm : symt.lookup(classScope).methods){
					if(vm.compare(node.getIdent()) == 0){
						assemName = classScope + "@" + node.getIdent();
						return 1;
					}
				}
				Symbol sym = symt.lookup(classScope + "@" + node.getIdent());
				if(sym.notFound){
					return -4;
				}
				assemName = classScope + "@" + node.getIdent();
			}
		}
		else {
			Symbol sym = symt.lookup(assemName);
			string tmpScope = "@" + sym.type;
			Symbol nextSym = symt.lookup(tmpScope + "@" + node.getIdent());
			if(nextSym.notFound){
				nextSym = symt.lookup(tmpScope);
				for(string m : nextSym.methods){
					if(m.compare(node.getIdent()) == 0){
						assemName = tmpScope + "@" + node.getIdent();
						return 1;
					}
				}
				return -1;
			}
			assemName = tmpScope + "@" + node.getIdent();
		}
	}
	if(node.name != 0){
		int r = node.name->accept(*this);
		if(r < 0) return r;
	}
	if(node.exp != 0){
		int r = node.exp->accept(*this);
		if(r < 0) return r;
	}

	return 0;
}
/*
 * This is the second most important one
 * this one should modify rType because it may not always return
 * a function
 * returns 0 when successful
 * returns -1 when there is an error in the expression itself
 * 	ex: class A + 2
 * 
*/
int SymbolTableBuilder::visit(Expression & node){
	if(node.isNul){
		rType = "null";
	}
	else if(node.isNum){
		rType = "int";
	}
	else {
		node.name->accept(*this);
		Symbol sym = symt.lookup(assemName);
		rType = sym.rType;
	}
	return 0;
}

int SymbolTableBuilder::visit(ArgList & node){
	for(int i = 0; i < node.size(); i++){
		node.at(i)->accept(*this);
	}
	return 0;
}

int SymbolTableBuilder::visit(FuncExp & node){
	return 0;
}

int SymbolTableBuilder::visit(ReadExp & node){
	return 0;
}

int SymbolTableBuilder::visit(NewExp & node){
	return 0;
}

int SymbolTableBuilder::visit(Nexp & node){
	return 0;
}

int SymbolTableBuilder::visit(SqExp & node){
	return 0;
}

int SymbolTableBuilder::visit(Sq & node){
	return 0;
}

int SymbolTableBuilder::visit(BinaryExp & node){
	return 0;
}

int SymbolTableBuilder::visit(UnaryExp & node){
	return 0;
}

int SymbolTableBuilder::visit(UnaryOp & node){
	return 0;
}

int SymbolTableBuilder::visit(ParanExp & node){
	return 0;
}

int SymbolTableBuilder::visit(Multibrackets & node){
	return 0;
}

/*
 * prints the type of error that occurred. 
*/
void SymbolTableBuilder::printNameError(int r){
	if(r == -1) {
		cerr << "Could not find variable: " << assemName << endl;
	}
	if(r == -2){
		cerr << "Error occurred while parsing statment " << endl;
	}
	if(r == -3) {
		cerr << "Error occurred because this is not at the front " << endl;
	}
	if(r == 1) {
		cerr << "Method on the left side of a function" << endl; 
	}
}