/*
* William Cary
* Node.cpp
* Program 4, Compilers
* Nov 1, 2020
* Contains all different node definitions
*/

#ifndef _NODE_HPP_
#define _NODE_HPP_
#include <iostream>
#include <string>
#include <vector>
#include "nodevisitor.hpp"

using std::string;
using std::vector;
using std::endl;
using std::cout;
using std::cerr;
using std::ostream;

class NodeVisitor;

class Node {

public:
  Node();
  Node(string);
  virtual ~Node();
  virtual void push_back(Node *);
  virtual Node * at(int);
  virtual int size();
  virtual void print(ostream *);
  string getIdent();
  string getValue();
  bool getIsNode();
  virtual int accept(NodeVisitor & visitor);
//protected:
  bool isNode = false;
  string val; // used by tree during print
  string value; // used by symbol table to determine type
  string identifier = "";
  bool isBlock = false;
};


class NodeList : public Node {
public:
  NodeList();
  void push_back(Node *);
  int size();
  Node * at(int);
  virtual void print(ostream *);
  virtual int accept(NodeVisitor & visitor);
//protected:
  vector<Node*> list;
  string name;
};

class Root : public NodeList {
public:
  Root(); 
  virtual int accept(NodeVisitor & visitor);
};

class ClassDec : public Node {
public:
  ClassDec(string, Node *);
  void print(ostream *);
  virtual int accept(NodeVisitor & visitor);
//protected:
  Node * classbody = 0;
};

class VarDec : public Node {
public:
  VarDec(Node *, string);
  void print(ostream *);
  virtual int accept(NodeVisitor & visitor);
  Node * child = 0;
};

class ConstrDec : public Node {
public:
  ConstrDec(string, Node *, Node *);
  void print(ostream *);
  virtual int accept(NodeVisitor & visitor);
//protected:
  Node * argChild = 0;
  Node * block = 0;
};

class MethodDec : public Node {
public:
  MethodDec(Node *, string, Node *, Node *);
  void print(ostream *);
  virtual int accept(NodeVisitor & visitor);
//protected:
  Node * resultChild = 0;
  Node * argChild = 0;
  Node * block = 0;
};


class ClassBody : public Node {
public:
  ClassBody();
  ClassBody(Node *, Node *, Node *);
  void print(ostream *);
  virtual int accept(NodeVisitor & visitor);
//protected:
  Node * vars = 0;
  Node * constructors = 0;
  Node * methods = 0;
};

class Type : public Node {
public:
  Type(Node *, Node *);
  void print(ostream *);
  virtual int accept(NodeVisitor & visitor);
//protected:
  Node * child = 0;
  Node * multibrackets = 0;
};

class SimpleType : public Node {
  public:
    SimpleType(string);
    SimpleType();
    void print(ostream *);
    int accept(NodeVisitor & visitor);
};

class ResultType : public Node {
  public:
    ResultType(Node *);
    ResultType();
    void print(ostream * );
  virtual int accept(NodeVisitor & visitor);
//protected:
    Node * child = 0;
};

class ParamList : public NodeList {
  public:
    ParamList();
    void print(ostream *);  
    int accept(NodeVisitor & visitor);
};

class Parameter : public  Node {
  public:
    Parameter(Node *, string);
    void print(ostream *);
  virtual int accept(NodeVisitor & visitor);
//protected:
    Node * child = 0;
};

class Block : public Node {
  public:
    Block(Node *, Node *);
    void print(ostream *);
  virtual int accept(NodeVisitor & visitor);
//protected:
    Node * localvars = 0;
    Node * statements = 0;
};


class LocalVarDecs : public NodeList {
  public:
    LocalVarDecs(Node*, string);
    void print(ostream *);
};

class LocalVarDec : public Node {
  public:
    LocalVarDec(Node *, string);
    void print(ostream *);
  virtual int accept(NodeVisitor & visitor);
//protected:
    Node * child = 0;
};

class Statement : public Node {
  public:
    Statement();
    Statement(Node *);
    void print(ostream *);
  virtual int accept(NodeVisitor & visitor);
//protected:
    Node * stat = 0;
};

class AssignStatement : public Node {
  public:
    AssignStatement(Node *, Node *);
    void print(ostream *);
  virtual int accept(NodeVisitor & visitor);
//protected:
    Node * name = 0;
    Node * exp = 0;
};

class FuncCallStatement : public Node {
  public:
    FuncCallStatement(Node *, Node *);
    void print(ostream *);
  virtual int accept(NodeVisitor & visitor);
//protected:
    Node * name = 0;
    Node * argChild = 0;
};

class PrintStatement : public Node {
  public: 
    PrintStatement(Node *);
    void print(ostream *);
  virtual int accept(NodeVisitor & visitor);
//protected:
    Node * argChild = 0;
};

class WhileStatement : public Node {
  public:
    WhileStatement(Node * , Node * );
    void print(ostream *);
  virtual int accept(NodeVisitor & visitor);
//protected:
    Node * exp = 0;
    Node * stat = 0;
};

class ReturnStatement : public Node {
  public:
    ReturnStatement(Node *);
    ReturnStatement();
    void print(ostream *);
  virtual int accept(NodeVisitor & visitor);
//protected:
    Node * exp = 0;
};

class BlockStatement : public Node {
  public:
    BlockStatement(Node *);
    void print(ostream * );
  virtual int accept(NodeVisitor & visitor);
//protected:
  Node * block = 0;
};

class IfStatement : public Node {
  public:
    IfStatement(Node *, Node *);
    void print(ostream *);
  virtual int accept(NodeVisitor & visitor);
//protected:
  Node * exp = 0;
  Node * stat = 0;
};

class IfElseStat : public Node {
  public:
    IfElseStat(Node *, Node *, Node *);
    void print(ostream *);
  virtual int accept(NodeVisitor & visitor);
//protected:
    Node * exp = 0;
    Node * stat = 0;
    Node * elstat = 0;
};

class Name : public Node {
  public:
    Name();
    Name(string);
    Name(Node *, string);
    Name(string, Node *);
    Name(Node *, Node *);
    void print(ostream *);
  virtual int accept(NodeVisitor & visitor);
//protected:
    int option;
    Node * elAcc = 0;
    Node * name = 0;
    Node * exp = 0;
};

class Expression : public Node {
  public:
    Expression(int);
    Expression();
    Expression(int, int);
    Expression(Node *);
    void print(ostream * );
  virtual int accept(NodeVisitor & visitor);
//protected:
    bool isNum = false; 
    bool isNul = false;
    int num;
    int option;
    Node * name = 0;
    
};

class ArgList : public NodeList {
  public:
    ArgList();
    void print(ostream * );
    int accept(NodeVisitor & visitor);
};

class FuncExp : public Node {
  public:
    FuncExp(Node *, Node *, bool);
    void print(ostream *);
  virtual int accept(NodeVisitor & visitor);
//protected:
    Node * name = 0;
    Node * argChild = 0;
};

class ReadExp : public Node {
  public: 
    ReadExp();
    void print(ostream *);
    int accept(NodeVisitor & visitor);
};

class NewExp : public Node {
  public:
    NewExp(Node *);
    void print(ostream *);
  virtual int accept(NodeVisitor & visitor);
//protected:
  Node * nexp = 0;
};

class Nexp : public Node {
  public:
    Nexp(string, Node *);
    Nexp(string);
    Nexp(Node *);
    Nexp(Node *, Node *, Node *);
    void print(ostream *);
  virtual int accept(NodeVisitor & visitor);
//protected:
    Node * st = 0;
    Node * argChild = 0;
    Node * expList = 0;
    Node * sqList = 0;
};

class SqExp : public Node{
  public:
    SqExp(Node *);
    void print(ostream *);
  virtual int accept(NodeVisitor & visitor);
//protected:
    Node * exp = 0;
};

class Sq : public Node {
  public:
    Sq();
    void print(ostream *);
    int accept(NodeVisitor & visitor);
};

class BinaryExp : public Node {
  public:
    BinaryExp(Node *, string, Node *);
    void print(ostream *);
  virtual int accept(NodeVisitor & visitor);
//protected:
    Node * left = 0;
    Node * right = 0;
};

class UnaryExp : public Node {
  public:
    UnaryExp(Node *, Node *);
    void print(ostream *);
  virtual int accept(NodeVisitor & visitor);
//protected:
    Node * unary = 0;
    Node * exp = 0;
};

class UnaryOp : public Node {
  public:
    UnaryOp(string);
    void print(ostream *);
    int accept(NodeVisitor & visitor);
};

class ParanExp : public Node {
  public:
    ParanExp(Node *);
    void print(ostream *);
  virtual int accept(NodeVisitor & visitor);
//protected:
    Node * exp = 0;
};

class Multibrackets : public NodeList {
  public: 
    Multibrackets();
    int accept(NodeVisitor & visitor);
};

class ElementAccessList : public NodeList {
  public:
    ElementAccessList();
    int accept(NodeVisitor & visitor);
};

class ElementAccess : public Node {
  public:
    ElementAccess(Node *);
    int accept(NodeVisitor & visitor);
  protected:
    Node * child; // expression
};

class ExpressionList : public NodeList {
  public:
    ExpressionList();
    int accept(NodeVisitor & visitor);
};
#endif
