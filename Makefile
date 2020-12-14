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

all: tester program5.tab.cpp program5_lex.cpp


tester: program5.tab.cpp program5.tab.hpp program5_lex.cpp program5.cpp nodevisitor.cpp symbol.cpp symboltable.cpp Node.hpp 
	$(CXX) $(CXXFLAGS) program5.cpp program5.tab.cpp program5_lex.cpp Node.cpp \
		nodevisitor.cpp symboltable.cpp symbol.cpp -o program5

program5.tab.cpp : program5.ypp Node.hpp
	$(YACC) $(YFLAGS) program5.ypp

parserTesting: program5.ypp Node.hpp
	$(YACC) $(YFLAGSTESTING) program5.ypp

program5_lex.cpp: program5.lpp Node.hpp
	$(LEXXX) $(LFLAGS) program5.lpp

tidy:
	/bin/rm -f a.out core.* program5.tab.* program5.output \
	  program5_lex.cpp

# the tidy rule cleans up but leaves the executable. The clean, uses tidy
# then it removes the executable.
clean: tidy
	/bin/rm -f tester

tarball:
	tar cf program5.tar Makefile Node.hpp Node.cpp program5.lpp program5.ypp\
	  program5.cpp nodevisitor.cpp nodevisitor.hpp symbol.cpp symbol.hpp \
		symboltable.hpp symboltable.cpp