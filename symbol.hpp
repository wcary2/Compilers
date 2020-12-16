/*
* William Cary
* symbol.hpp
* Program 6, Compilers
* Dec 14, 2020
* Contains all different nodes
*/
#ifndef _SYMBOL_HPP_
#define _SYMBOL_HPP_
#include <string>
#include <vector>

using namespace std;

struct Symbol {
  string value; // name of the symbol
  string type;
  string order; // either variable, method, constr or class.
  string rType = "@none";
  bool notFound = false; // used to determine if a variable was found after  a lookup. 
  vector<string> params;
  vector<int> arrSize; // determines if it's an array. size of 0 indicates not array
  vector<string> methods; // represents methods in a class
  vector<string> vars; // represents the variables in a class
  Symbol();
  Symbol(string val, string type, string order, string rType, vector<string> & params_, vector<int> &arrSize);
  Symbol(const Symbol & sym);
};



#endif