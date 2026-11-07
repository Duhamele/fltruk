# file fltrk/GNUmakefile

## see https://github.com/bstarynk/fltruk
## Author(s):
##      Basile STARYNKEVITCH, 92340 Bourg-la-Reine, France,
##                    <basile@starynkevitch.net>
CXX = g++ #the Gnu C compiler
OPTIM ?= -Og
CXXFLAGS += -Wall -Wextra -Weffc++ $(OPTIM) -g
ASTYLE = astyle
SOURCEFILES:= $(wildcard *.cc)
OBJECTFILES=$(patsubst %.cc, obj/%.o, $(SOURCEFILES))
.PHONY: all clean indent
all: fltruk

clean:
	/bin/rm -vf *~ obj/*.o fltruk _*_.cc *.i *~ *%

indent:
	$(ASTYLE) -v $(wildcard [a-z]*.cc [a-z]*.hh)

# compile a source file to an object 
obj/%.o: %.cc fltruk.hh | GNUmakefile get-short-git.sh
	$(CXX) -UFLTRUK_MAKOBJ $(CXXFLAGS) \
             -DFLTRUK_SHORTGIT=\"$(shell ./get-short-git.sh $^)\" \
             -c $< -o $@

fltruk: $(OBJECTFILES)
	$(CXX) $(OPTIM) -g $(OBJECTFILES) -o $* -lfltk
