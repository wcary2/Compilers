/*
* William Cary
* Node.cpp
* Program 4, Compilers
* Nov 1, 2020
* Contains all different nodes
*/

#include <string>
#include <vector>
#include <iostream>
#include "Node.hpp"

using std::vector;
using std::string;
using std::cout;
using std::cerr;
using std::endl;

/* Base class Node */

Node::Node() {
  isNode = true;
}

Node::Node(string id){
  identifier = id;
}

int Node::accept(NodeVisitor & visitor){
  return visitor.visit(*this);
}

Node::~Node() {}

void Node::print(ostream * out = 0) {
  return;
}

Node * Node::at(int i){
  return 0;
}

string Node::getIdent(){
  return identifier;
}

string Node::getValue() {
  return value;
}

bool Node::getIsNode(){
  return isNode;
}
int Node::size(){return 0;}

void Node::push_back(Node* n){}


/** Node List **/

int NodeList::accept(NodeVisitor & visitor){
	return visitor.visit(*this);
}

NodeList::NodeList() {}

void NodeList::push_back(Node * n){
  list.push_back(n);
}

int NodeList::size(){
  return list.size();
}

void NodeList::print(ostream * out = 0){
  for(int i = 0; i < list.size(); i++){
    *out << val;
  }
  for(int i = 0; i < list.size(); i++){
    list[i]->print(out);
  }
}

Node * NodeList::at(int i ){
  return list.at(i);
}

/** Root **/
int Root::accept(NodeVisitor & visitor){
	return visitor.visit(*this);
}

Root::Root() {}

/** ClassDec **/
int ClassDec::accept(NodeVisitor & visitor){
	return visitor.visit(*this);
}

ClassDec::ClassDec(string id, Node * cb){
  val = "<ClassDeclaration> -> ";
  identifier = id;
  classbody = cb;
  isBlock = true;
}

void ClassDec::print(ostream * out = 0){
  *out << val << "class " << identifier << " <ClassBody>" << endl;
  classbody->print(out);

}

/** VarDec **/
int VarDec::accept(NodeVisitor & visitor){
	return visitor.visit(*this);
}

VarDec::VarDec(Node * n, string id){
  val = "<VariableDeclaration> -> <Type> ";
  child = n;
  identifier = id;
}

void VarDec::print(ostream * out = 0){
  *out << val << identifier << ";" << endl;
  child->print(out);
}

/** ConstrDec**/
int ConstrDec::accept(NodeVisitor & visitor){
	return visitor.visit(*this);
}

ConstrDec::ConstrDec(string id, Node * argN, Node * bn) {
  identifier = id;
  argChild = argN;
  block = bn;
  isBlock = true;
}

void ConstrDec::print(ostream * out = 0){
  if(argChild->size() == 0) {
    *out << "<ConstructorDeclaration> -> " << identifier << "() <Block>" << endl;
  }
  else {
    *out << "<ConstructorDeclaration> -> " << identifier << "( " << "<ParameterList> "
      << ") <Block>" << endl;
    argChild->print(out);
  }
  block->print(out);

  
}

/** MethodDec **/
int MethodDec::accept(NodeVisitor & visitor){
	return visitor.visit(*this);
}

MethodDec::MethodDec(Node * n, string id, Node * param, Node * bn){
  identifier = id;
  resultChild = n;
  argChild = param;
  block = bn;
  isBlock = true;
}

void MethodDec::print(ostream * out = 0){
  if(argChild->size() == 0){
    *out << "<MethodDeclaration> -> <ResultType> " << identifier << "() ";
  }
  else {
    *out << "<MethodDeclaration> -> <ResultType> " << identifier 
      << "( <ParameterList> ) ";
  }
  *out << "<Block>" << endl;
  resultChild->print(out);
  argChild->print(out);
  block->print(out);
}

/** Class Body **/
int ClassBody::accept(NodeVisitor & visitor){
	return visitor.visit(*this);
}

ClassBody::ClassBody() {
  val = "<ClassBody> -> ";
  vars = 0;
  constructors = 0;
  methods = 0;
}

ClassBody::ClassBody(Node * v, Node * c, Node * m){
  val = "<ClassBody> -> ";
  vars = v;
  constructors = c;
  methods = m;
}

void ClassBody::print(ostream * out = 0){
  *out << val;
  for(int i =0; i < vars->size(); i++){
    *out << "<VariableDeclaration> ";
  }
  for(int i = 0; i < constructors->size(); i++){
    *out << "<ConstructorDeclaration> ";
  }
  for(int i = 0; i < methods->size(); i++){
    *out << "<MethodDeclaration> ";
  }
  *out << endl;
  vars->print(out);
  constructors->print(out);
  methods->print(out);
}

/** Type **/

int Type::accept(NodeVisitor & visitor){
	return visitor.visit(*this);
}

Type::Type(Node * n, Node * l){
  if(1){
    val = "<Type> -> <Type> []";
  }
  else { val = "<Type> -> <SimpleType>";}
  child = n;
  multibrackets = l;
}

void Type::print(ostream * out = 0) {
  *out << val << endl; 
  child->print(out);
}


/** SimpleType **/

int SimpleType::accept(NodeVisitor & visitor){
	return visitor.visit(*this);
}

SimpleType::SimpleType(string n){
  val = "<SimpleType> -> ";
  identifier = n;  
}

SimpleType::SimpleType(){
  val = "<SimpleType> -> ";
  identifier = "int";
}

void SimpleType::print(ostream * out){
  *out << val << identifier << endl;
}

/** ResultType **/
int ResultType::accept(NodeVisitor & visitor){
	return visitor.visit(*this);
}

ResultType::ResultType(Node * n){
  val = "<ResultType> -> ";
  child = n;
  identifier = "<Type>";
}

ResultType::ResultType(){
  val = "<ResultType> -> ";
  child = 0;
  identifier = "void";
}

void ResultType::print(ostream * out){
  *out << val << identifier << endl;
  if(child != 0){
    child->print(out);
  }
}

/** ParamList **/
int ParamList::accept(NodeVisitor & visitor){
	return visitor.visit(*this);
}

ParamList::ParamList() {}

void ParamList::print(ostream * out) {
  if(size() == 0)
    return;
  *out << "<ParameterList> -> ";
  for(int i = 0; i < list.size() - 1; i++) {
    *out << "<Parameter> , ";
  }
  *out << "<Parameter>" << endl;
  for(int i = 0; i < list.size(); i++){
    list[i]->print(out);
  }
}


/** Parameter **/
int Parameter::accept(NodeVisitor & visitor){
	return visitor.visit(*this);
}

Parameter::Parameter(Node * n, string id){
  val = "<Parameter> -> <Type> ";
  child = n;
  identifier = id;
}

void Parameter::print(ostream * out){
  *out << val << identifier << endl;
  child->print(out);
}

/** Block **/
int Block::accept(NodeVisitor & visitor){
	return visitor.visit(*this);
}

Block::Block(Node * lv, Node * st){
  localvars = lv;
  statements = st;
  val = "<Block> -> ";
}

void Block::print(ostream *out = 0){
  *out << val;
  *out << "{ ";
  for(int i =0; i < localvars->size(); i++){
    *out << "<LocalVarDeclaration> ";
  }
  for(int i = 0; i < statements->size(); i++){
    *out << "<Statement> ";
  }
  *out << "} " << endl;
  localvars->print(out);
  statements->print(out);
}

/** LocalVarDec **/
int LocalVarDec::accept(NodeVisitor & visitor){
	return visitor.visit(*this);
}

LocalVarDec::LocalVarDec(Node * n, string id) {
  child = n;
  val = "<LocalVarDec> ";
  identifier = id;
}

void LocalVarDec::print(ostream * out){
  *out << val << " - > " << "<Type> " << identifier << " ; " << endl;
  child->print(out); 
}

/** Statement **/ 
int Statement::accept(NodeVisitor & visitor){
	return visitor.visit(*this);
}

Statement::Statement() {
  val = " <Statement> ";
  stat = 0;
}

Statement::Statement(Node * n ){
  stat = n;
}


void Statement::print(ostream * out = 0){
  if(stat == 0)
    *out << val << "-> " << ";" << endl;
  else {
    *out << val << "-> ";
    stat->print(out);
  }
}

/** AssignStatement **/
int AssignStatement::accept(NodeVisitor & visitor){
	return visitor.visit(*this);
}

AssignStatement::AssignStatement(Node * n, Node * e){
  name = n;
  exp = e;
  val = "<Statement> -> <Name> = <Expression> ;";
}

void AssignStatement::print(ostream * out = 0){
  *out << val << endl;
  name->print(out);
  exp->print(out);
}

/** FuncCallStatement **/
int FuncCallStatement::accept(NodeVisitor & visitor){
	return visitor.visit(*this);
}

FuncCallStatement::FuncCallStatement(Node *n, Node *ar){
  name = n;
  argChild = ar;
}

void FuncCallStatement::print(ostream * out = 0){
  val = "<Statement> -> ";
  *out << val;
  if(argChild->size() == 0){
    *out << "<Name> ( ) ;" << endl; 
    name->print(out);
  }
  if(argChild->size() != 0){
    *out << "<Name> ( <ArgList> ) ;" << endl;
    name->print(out);
    argChild->print(out);
  }
}

/** Name **/
int Name::accept(NodeVisitor & visitor){
	return visitor.visit(*this);
}

Name::Name(){
  val = "<Name> -> this";
  option = 1;
}

Name::Name(string id){
  identifier = id;
  val = "<Name> -> ";
  option = 2;
}

Name::Name(Node * n, string id){
  name = n;
  identifier = id;
  option = 3;
  val = "<Name> -> ";
}

Name::Name(Node * n, Node * e){
  name = n;
  exp = e;
  option = 4;
  val = "<Name> -> ";
}

Name::Name(string id, Node * n) {
  identifier = id;
  option = 5;
  name = n;
}

void Name::print(ostream * out = 0){
  if(option == 1) {
    *out << val << endl;
  }
  if(option == 2) {
    *out << val << identifier << endl;
  }
  if(option == 3){
    *out << val << "<Name> . " << identifier << endl;
    name->print(out);
  }
  if(option == 4){
    *out << val << "<Name> [ <Expression> ] " << endl;
    name->print(out);
    exp->print(out);
  }
}

/** Expression **/
int Expression::accept(NodeVisitor & visitor){
	return visitor.visit(*this);
}

Expression::Expression(int n){
  num = n;
  name = 0;
  isNum = true;
  val = "<Expression> ->  ";
}

Expression::Expression() {
  isNul = true;
}

Expression::Expression(Node * n){
  name = n;
  val = "<Expression> -> ";
}

Expression::Expression(int o, int n){
  val = "<Expression> ->  null";
  num = n;
  name = 0;
  option = o;
}

void Expression::print(ostream * out = 0){
  if(option == 3){
    *out << val << endl;
  }
  else if(name == 0){
    *out << val << num << endl;
  }
  else {
    *out << val << "<Name>" << endl; 
    name->print(out);
  }
}


/** ArgList **/
int ArgList::accept(NodeVisitor & visitor){
	return visitor.visit(*this);
}

ArgList::ArgList() {
  val = "<ArgList> -> ";
}

void ArgList::print(ostream * out = 0){
  *out << val;
  for(int i = 0; i < size() - 1; i++){
    *out << "<Expression> , ";
  }
  *out << "<Expression>" << endl;
  for(int i = 0; i < size(); i++){
    list[i]->print(out);
  }
}

/** PrintStatement **/
int PrintStatement::accept(NodeVisitor & visitor){
	return visitor.visit(*this);
}

PrintStatement::PrintStatement(Node * n){
  argChild = n;
}

void PrintStatement::print(ostream * out = 0){
  if(argChild->size() == 0) {
    *out << "<Statement> -> print ( );" << endl;
  }
  else {
    *out << "<Statement> -> print ( <ArgList> ) " << endl;
    argChild->print(out);
  }
}

/** WhileStatement **/
int WhileStatement::accept(NodeVisitor & visitor){
	return visitor.visit(*this);
}

WhileStatement::WhileStatement(Node * e, Node * s){
  exp = e;
  stat = s;
  val = "<Statement> -> while ";
}

void WhileStatement::print(ostream * out = 0){
  *out << val << "( <expression> ) <Statement>" << endl;
  exp->print(out);
  stat->print(out);
}

/** ReturnStatement **/
int ReturnStatement::accept(NodeVisitor & visitor){
	return visitor.visit(*this);
}

ReturnStatement::ReturnStatement(Node * e = 0 ) {
  exp = e;
  val = "<Statement> -> return ";
}

ReturnStatement::ReturnStatement() {
  exp = 0;
  val = "<Statement> -> return ";
}

void ReturnStatement::print(ostream * out = 0){
  *out << val;
  if(exp == 0){
    *out << ";" << endl;
  }
  else {
    *out << "<Expression> ;" << endl;
    exp->print(out);
  }
}

/** BlockStatement **/
int BlockStatement::accept(NodeVisitor & visitor){
	return visitor.visit(*this);
}

BlockStatement::BlockStatement(Node * n){
  block = n;
  val = "<Statement> -> <Block>";
}

void BlockStatement::print(ostream * out = 0) {
  *out << val << endl;
  block->print(out);
}

/** IfStatement **/
int IfStatement::accept(NodeVisitor & visitor){
	return visitor.visit(*this);
}

IfStatement::IfStatement(Node * e, Node * s){
  exp = e;
  stat = s;
  val = "<Statement> -> if ( <Expression> ) <Statement>";
}

void IfStatement::print(ostream * out = 0){
  *out << val << endl;
  exp->print(out);
  stat->print(out);
}

/** IfElseStat **/

int IfElseStat::accept(NodeVisitor & visitor){
	return visitor.visit(*this);
}

IfElseStat::IfElseStat(Node * e, Node * s, Node * se){
  exp = e;
  stat = s;
  elstat = se;
  val = "<Statement> -> if ( <Expression> ) <Statement> else <Statement>";
}

void IfElseStat::print(ostream * out = 0){
  *out << val << endl;
  exp->print(out);
  stat->print(out);
  elstat->print(out);
}

/** FuncExp **/
int FuncExp::accept(NodeVisitor & visitor){
	return visitor.visit(*this);
}

FuncExp::FuncExp(Node * n, Node * ar, bool in){
  name = n;
  isNode = in;
  argChild = ar;
  val = "<Expression> -> ";
}

void FuncExp::print(ostream * out = 0){
  *out << val;
  if(isNode == true){
    *out << "<Name> ( )" << endl;
  }
  else {
    *out << "<Name> ( <ArgList> ) " << endl;
  }
  name->print(out);
  argChild->print(out);
}

/** ReadExp **/
int ReadExp::accept(NodeVisitor & visitor){
	return visitor.visit(*this);
}

ReadExp::ReadExp(){
  val = "<Expression> -> read ( ) ";
}

void ReadExp::print(ostream * out = 0){
  *out << val << endl;
}

/** NewExp **/
int NewExp::accept(NodeVisitor & visitor){
	return visitor.visit(*this);
}

NewExp::NewExp(Node * n ){
  nexp = n;
  val = "<Expression> -> <NewExpression>";
}

void NewExp::print(ostream * out = 0){
  *out << val << endl;
  nexp->print(out);
}


/** Nexp **/
int Nexp::accept(NodeVisitor & visitor){
	return visitor.visit(*this);
}

Nexp::Nexp(string s, Node * n){
  identifier = s;
  argChild = n;
  val = "<NewExpression> -> new ";
}

Nexp::Nexp(string s){
  identifier = s;
  argChild = 0;
  val = "<NewExpression> -> new ";
}

Nexp::Nexp(Node * n){
  val = "<NewExpression> -> new ";
  argChild = 0;
  st = n;
}

Nexp::Nexp(Node * n, Node * e, Node * sq){
  val = "<NewExpression> -> new ";
  argChild = 0;
  st = n;
  expList = e;
  sqList = sq;
}
void Nexp::print(ostream * out = 0){
  *out << val;
  if(argChild == 0 && st == 0){
    *out << identifier << "( )" << endl;
  }
  if(argChild != 0){
    *out << identifier << "( <ArgList> )" << endl;
    argChild->print(out);
  }
  else if(st != 0){
    *out << "<SimpleType>";
    for(int i = 0; i < expList->size(); i++){
      *out << "[ <expression> ] ";
    }
    for(int i = 0; i < sqList->size(); i++){
      *out << "[ ] ";
    }
    *out << endl;
    st->print(out);
    expList->print(out);
    sqList->print(out);
  }

}

int SqExp::accept(NodeVisitor & visitor){
	return visitor.visit(*this);
}

SqExp::SqExp(Node *n){
  exp = n;
}

void SqExp::print(ostream * out = 0){
  exp->print(out);
}


/** Sq **/
int Sq::accept(NodeVisitor & visitor){
	return visitor.visit(*this);
}

Sq::Sq(){

}
void Sq::print(ostream * out){
  return;
}


/** BinaryExp **/
int BinaryExp::accept(NodeVisitor & visitor){
	return visitor.visit(*this);
}

BinaryExp::BinaryExp(Node * l, string id, Node * r){
  left = l;
  identifier = id;
  val = "<Expression> -> ";
  right = r;
}

void BinaryExp::print(ostream * out = 0){
  *out << val << "<Expression> " << identifier << " <Expression> " << endl;
  left->print(out);
  right->print(out);
}

/** UnaryExp **/
int UnaryExp::accept(NodeVisitor & visitor){
	return visitor.visit(*this);
}

UnaryExp::UnaryExp(Node * u, Node * e){
  val = "<Expression> -> ";
  unary = u;
  exp = e;
}

void UnaryExp::print(ostream * out = 0){
  *out << val << "<UnaryExp> <Expression>" << endl;
  unary->print(out);
  exp->print(out);
}

/** UnaryOp **/
int UnaryOp::accept(NodeVisitor & visitor){
	return visitor.visit(*this);
}

UnaryOp::UnaryOp(string id){
  val = "<UnaryOp> -> ";
  identifier = id;
}

void UnaryOp::print(ostream * out = 0){
  *out << val << identifier << endl;
}

/** ParanExp **/
int ParanExp::accept(NodeVisitor & visitor){
	return visitor.visit(*this);
}

ParanExp::ParanExp(Node * n){
  val = "<Expression> -> ";
  exp = n;
}

void ParanExp::print(ostream * out = 0){
  *out << val << "( <Expression> ) " << endl;
  exp->print(out);
}

/* Multibrackets */
int Multibrackets::accept(NodeVisitor & visitor){
	return visitor.visit(*this);
}

Multibrackets::Multibrackets() {
  value = "multibrackets";
};


/* ElementAccessList */

ElementAccessList::ElementAccessList() {}

int ElementAccessList::accept(NodeVisitor & visitor) {
  return visitor.visit(*this); 
}

/* ElementAccess */

ElementAccess::ElementAccess(Node * n) {
  child = n;
}

int ElementAccess::accept(NodeVisitor & visitor) {
  return visitor.visit(*this);
}
