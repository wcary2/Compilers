/*
* William Cary
* symbol.cpp
* Program 6, Compilers
* Dec 14, 2020
* Contains all different nodes
*/

#include "symbol.hpp"


Symbol::Symbol() {
  value = ""; // name of the symbol
  type = "";
  order = ""; // either variable, method, or class. since its important to be able to .
  rType = "@None";
  // used to determine if a variable was found after  a lookup. 
  //vector<int> arrSize; // determines if it's an array. size of 0 indicates not array
}

Symbol::Symbol(const Symbol & sym){
  value = sym.value;
  type = sym.type;
  order = sym.order;
  rType = sym.rType;
  notFound = sym.notFound;
  arrSize = sym.arrSize;
  params = sym.params;
  methods = sym.methods;
  vars = sym.vars;
}

Symbol::Symbol(string val_, string type_, string order_, string rType_,
              vector<string> & params_, vector<int> &arrSize_){
  value = val_;
  type = type_;
  order = order_;
  rType = rType_;
  params = params_;
  arrSize = arrSize_;
}