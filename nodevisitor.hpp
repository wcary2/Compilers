/*
* William Cary
* dispatcher.cpp
* Program 5, Compilers
* Nov 25, 2020
* Contains all different nodes
*/
#ifndef _NODEVISITOR_HPP_
#define _NODEVISITOR_HPP_
#include <string>
#include <vector>
#include <iostream>
#include <tuple>
#include "symboltable.hpp"
#include "Node.hpp"


using namespace std;

class Node;
class NodeList;
class Root;
class ClassDec;
class VarDec;
class ConstrDec;
class MethodDec;
class ClassBody;
class Type;
class SimpleType;
class ResultType;
class ParamList;
class Parameter;
class Block;
class LocalVarDecs;
class LocalVarDec;
class Statement;
class AssignStatement;
class FuncCallStatement;
class PrintStatement;
class WhileStatement;
class ReturnStatement;
class BlockStatement;
class IfStatement;
class IfElseStat;
class Name;
class Expression;
class ArgList;
class FuncExp;
class ReadExp;
class NewExp;
class Nexp;
class SqExp;
class Sq;
class BinaryExp;
class UnaryExp;
class UnaryOp;
class ParanExp;
class Multibrackets;




class NodeVisitor {
public: 
  NodeVisitor();
  virtual int visit(Node & node) = 0;
  virtual int visit(NodeList & node) = 0;
  virtual int visit(Root & node) = 0;
  virtual int visit(ClassDec & node) = 0;
  virtual int visit(VarDec & node) = 0;
  virtual int visit(ConstrDec & node) = 0;
  virtual int visit(MethodDec & node) = 0;
  virtual int visit(ClassBody & node) = 0;
  virtual int visit(Type & node) = 0;
  virtual int visit(SimpleType & node) = 0;
  virtual int visit(ResultType & node) = 0;
  virtual int visit(ParamList & node) = 0;
  virtual int visit(Parameter & node) = 0;
  virtual int visit(Block & node) = 0;
  virtual int visit(LocalVarDecs & node) = 0;
  virtual int visit(LocalVarDec & node) = 0;
  virtual int visit(Statement & node) = 0;
  virtual int visit(AssignStatement & node) = 0;
  virtual int visit(FuncCallStatement & node) = 0;
  virtual int visit(PrintStatement & node) = 0;
  virtual int visit(WhileStatement & node) = 0;
  virtual int visit(ReturnStatement & node) = 0;
  virtual int visit(BlockStatement & node) = 0;
  virtual int visit(IfStatement & node) = 0;
  virtual int visit(IfElseStat & node) = 0;
  virtual int visit(Name & node) = 0;
  virtual int visit(Expression & node) = 0;
  virtual int visit(ArgList & node) = 0;
  virtual int visit(FuncExp & node) = 0;
  virtual int visit(ReadExp & node) = 0;
  virtual int visit(NewExp & node) = 0;
  virtual int visit(Nexp & node) = 0;
  virtual int visit(SqExp & node) = 0;
  virtual int visit(Sq & node) = 0;
  virtual int visit(BinaryExp & node) = 0;
  virtual int visit(UnaryExp & node) = 0;
  virtual int visit(UnaryOp & node) = 0;
  virtual int visit(ParanExp & node) = 0;
  virtual int visit(Multibrackets & node) = 0;
};

class SymbolTableBuilder : protected NodeVisitor {
  string currentScope = "@"; // current scope 
  string classScope = ""; // scope of the current class
  tuple<string, int> varConstruction; // represents the type and array size
    // stores instances in which the compiler symbol table could not find a particular
      // class so it stores it here until it reaches the end of the file
      // at which point it will check to see if all of class names have been resolved.
  vector<tuple<string, string>> errors; // <type, name>
  vector<Symbol> params;
  vector<string> names; // all the names only used for printing
  // represent the type of a variable or expression being processed
  string rType = ""; 
  // represent a name being assembled
  string assemName = "";
  // list of the enclosing blocks to check:
  vector<string> enclosingBlocks;
  // the current symbol returned from name
  vector<Node *> errorStats;
  int blockCount = 0;
  bool mainfunc = false;
  vector<int> bCount;  // maintains current block
  int checkErrors(); // checks to see if classes not found have been added to the document
  void printNameError(int r); 
public:
  SymbolTableBuilder();
  SymbolTable symt; 
  void print();
  int start(Node & node);
  /* functions for different node types */
  int visit(Node & node);
  int visit(NodeList & node);
  int visit(Root & node);
  int visit(ClassDec & node);
  int visit(VarDec & node);
  int visit(ConstrDec & node);
  int visit(MethodDec & node);
  int visit(ClassBody & node);
  int visit(Type & node);
  int visit(SimpleType & node);
  int visit(ResultType & node);
  int visit(ParamList & node);
  int visit(Parameter & node);
  int visit(Block & node);
  int visit(LocalVarDecs & node);
  int visit(LocalVarDec & node);
  int visit(Statement & node);
  int visit(AssignStatement & node);
  int visit(FuncCallStatement & node);
  int visit(PrintStatement & node);
  int visit(WhileStatement & node);
  int visit(ReturnStatement & node);
  int visit(BlockStatement & node);
  int visit(IfStatement & node);
  int visit(IfElseStat & node);
  int visit(Name & node);
  int visit(Expression & node);
  int visit(ArgList & node);
  int visit(FuncExp & node);
  int visit(ReadExp & node);
  int visit(NewExp & node);
  int visit(Nexp & node);
  int visit(SqExp & node);
  int visit(Sq & node);
  int visit(BinaryExp & node);
  int visit(UnaryExp & node);
  int visit(UnaryOp & node);
  int visit(ParanExp & node);
  int visit(Multibrackets & node);
  

};

#endif
