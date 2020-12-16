#
# $Author: kbuckner $
# $ID$
#
# $Log: Makefile,v $
# Revision 1.3  2020-09-28 14:10:51-06  kbuckner
# Removed the std= and added no-sign flags from g++ flags.
#
# Revision 1.2  2019-10-07 14:41:40-06  kbuckner
# Added tarball target
#
# Revision 1.1  2017-10-04 13:20:53-06  kbuckner
# Finally working version
#
#
###############################################################

CXX=g++
CXXFLAGS=-ggdb -Wall -Wno-sign-compare
YACC=bison
YFLAGS=--report=state -W -d 
YFLAGSTESTING=--report=state -W -d
LEX=flex
LEXXX=flex++
LFLAGS=--warn

.PHONY: clean tarball

all: tester program6.tab.cpp program6_lex.cpp


tester: program6.tab.cpp program6.tab.hpp program6_lex.cpp program6.cpp nodevisitor.cpp symbol.cpp symboltable.cpp Node.hpp 
	$(CXX) $(CXXFLAGS) program6.cpp program6.tab.cpp program6_lex.cpp Node.cpp \
		nodevisitor.cpp symboltable.cpp symbol.cpp -o program6

program6.tab.cpp : program6.ypp Node.hpp
	$(YACC) $(YFLAGS) program6.ypp

parserTesting: program6.ypp Node.hpp
	$(YACC) $(YFLAGSTESTING) program6.ypp

program6_lex.cpp: program6.lpp Node.hpp
	$(LEXXX) $(LFLAGS) program6.lpp

tidy:
	/bin/rm -f a.out core.* program6.tab.* program6.output \
	  program6_lex.cpp

# the tidy rule cleans up but leaves the executable. The clean, uses tidy
# then it removes the executable.
clean: tidy
	/bin/rm -f tester

tarball:
	tar cf program6.tar Makefile Node.hpp Node.cpp program6.lpp program6.ypp\
	  program6.cpp nodevisitor.cpp nodevisitor.hpp symbol.cpp symbol.hpp \
		symboltable.hpp symboltable.cpp