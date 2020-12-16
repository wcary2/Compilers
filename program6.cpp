/*
* William Cary
* Program6.hpp
* Program 6, Compilers
* Dec 14, 2020
* Contains all different nodes
*/

#include <iostream>
#include <string>
#include <FlexLexer.h>
#include "Node.hpp"
#include "nodevisitor.hpp"
#include "program6.tab.hpp"
#include <vector>
#include <stdlib.h>

using std::vector;
using std::endl;
using std::cout;
int errors = 0;
yyFlexLexer scanner;
Root tree;
int main() {
  
  yyparse();
  SymbolTableBuilder builder;
  builder.start(tree);
  builder.print();
}


void yyerror(const char * str) {
  cout << "Error at line " << scanner.lineno() << ": " << str << endl;
  if(errors > 10) {
    exit(-1);
  }
}
