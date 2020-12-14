/*
* William Cary
* Node.cpp
* Program 4, Compilers
* Nov 25, 2020
* Contains all different nodes
*/
#ifndef _SYMBOLTABLE_HPP_
#define _SYMBOLTABLE_HPP_
#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
#include "symbol.hpp"

using namespace std;

class SymbolTable {
  unordered_map<string, Symbol> table;
public:
  SymbolTable();
  int insert(string value, Symbol & sym); 
  Symbol lookup(string value);
  int modFoundStatus(string value); // flips not found
  void addMeth(string value, string name);
  void addVar(string value, string name);
};


#endif