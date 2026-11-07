# file fltrk/GNUmakefile

## see https://github.com/bstarynk/fltruk
## Author(s):
##      Basile STARYNKEVITCH, 92340 Bourg-la-Reine, France,
##                    <basile@starynkevitch.net>
CXX = g++ #the Gnu C compiler
OPTIM ?= -Og
CXXFLAGS += -Wall -Wextra -Weffc++ $(OPTIM) -g $(shell fltk-config --cxxflags)
ASTYLE = astyle
SOURCEFILES:= $(wildcard *.cc)
OBJECTFILES=$(patsubst %.cc, obj/%.o, $(SOURCEFILES))
.PHONY: all clean indent
all: fltruk

clean:
	/bin/rm -vf *~ obj/*.o fltruk _*_.cc *.i *~ *%

indent:
	$(ASTYLE) -v $(wildcard [a-z]*.cc [a-z]*.hh)


# https://stackoverflow.com/a/3220288/841108
# compile a source file to an object 
obj/%.o: %.cc fltruk.hh | GNUmakefile get-short-git.sh
	@printf "$$< is %s\n" "$<"
	$(CXX) -UFLTRUK_MAKOBJ -DFLTRUK_BASE=\"$(basename $<)\" $(CXXFLAGS) \
             -DFLTRUK_SHORTGIT=\"$(shell ./get-short-git.sh $^)\" \
             -c $< -o $@

fltruk: $(OBJECTFILES) | GNUmakefile
	$(CXX) $(OPTIM) -g $(OBJECTFILES)  $(shell fltk-config --libs) -o $@

#obj/main-fltruk.o: main-fltruk.cc
