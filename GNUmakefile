# file fltrk/GNUmakefile

## see https://github.com/bstarynk/fltruk
## Author(s):
##      Basile STARYNKEVITCH, 92340 Bourg-la-Reine, France,
##                    <basile@starynkevitch.net>
CX = g++ #the Gnu C compiler
OPTIM ?= -Og
CXXFLAGS += -Wall -Wextra -Weffc++ $(OPTIM) -g
ASTYLE = astyle
.PHONY: all clean indent
all: fltruk

clean:
	/bin/rm -vf *~ obj/*.o fltruk _*_.cc *.i *~ *%

indent:
	$(ASTYLE) -v $(wildcard [a-z]*.cc [a-z]*.hh)

# compile a source file to an object 
obj/%.o: %.c fltruk.hh | GNUmakefile get-short-git.sh
	$(CC) -UFLTRUK_MAKOBJ $(CFLAGS) -DFLTRUK_SHORTGIT=\"$(shell ./get-short-git.sh $^)\" -c $< -o $@
