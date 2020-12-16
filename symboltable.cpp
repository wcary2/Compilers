/*
* William Cary
* symboltable.hpp
* Program 6, Compilers
* Dec 14, 2020
* Contains all different nodes
*/
#include <string>
#include <vector>
#include <iostream>
#include "symboltable.hpp"

using namespace std;



SymbolTable::SymbolTable() {}

/* Inserts a symbol into the symbol table
 * returns 0, if succesful.
 * returns -1 if symbol already exists 
*/
int SymbolTable::insert(string value, Symbol & sym){
  pair<string, Symbol> ins (value, sym);
  auto success = table.emplace(value, sym);
  //cout << "inserting " << value << " succesful: " << get<1>(success) << endl;
  return (get<1>(success)) ? 0 : -1;
}

/* looksup an element  
 * returns the symbol in the table 
 * if it can't find it sets notFound value to true;
*/
Symbol SymbolTable::lookup(string value) {
  if(table.count(value) == 0) {
    Symbol sym;
    sym.notFound = true;
    return sym;
  }
  //if(sym.notFound);
  return Symbol(table.at(value));
}

int SymbolTable::modFoundStatus(string value){
  try {
    table.at(value).notFound = false;
    return 0;
  }
  catch(out_of_range & oor){
    cerr << "Out of range exception occured when modifying found for " 
      << "symbol " << value << endl;
      return -1;
  }
}

/*
 * Inserts a new method can include constructors into a symbol
*/
void SymbolTable::addMeth(string value, string name){
  try {
    table.at(value).methods.push_back(name);
  }
  catch(out_of_range & oor) {
    cerr << "Out of range exception occurred when add var or method for "
      << "Symbol " << value << " inserting " << name << endl;
  }
}

/*
 * Inserts a new variable can include constructors into a symbol
*/
void SymbolTable::addVar(string value, string name){
  try {
    table.at(value).vars.push_back(name);
  }
  catch(out_of_range & oor) {
    cerr << "Out of range exception occurred when add var or method for "
      << "Symbol " << value << " inserting " << name << endl;
  }
}

