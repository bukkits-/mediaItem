# Matthew Groeling
# Joe Mehltretter
# CS225
# Assignment 6
# makefile
#
# Uses Prof. Davis' provided makefile

# Here is a simple Make Macro.
TEST_SCRIPT1 = ts_15.in
TEST_SCRIPT2 = ts_16.in
CURRENT_ASSIGNMENT = assignment7
LINK_TARGET = $(CURRENT_ASSIGNMENT).exe

# Here is a Make Macro that uses the backslash to extend to multiple lines.
OBJS =  \
 main.o \
	classBody.o \
	element.o \
	derived.o \
	author.o \
	ioMediaInfo.o \

# Here is a Make Macro defined by two Macro Expansions.
# A Macro Expansion may be treated as a textual replacement of the Make Macro.
# Macro Expansions are introduced with $ and enclosed in (parentheses).
REBUILDABLES = $(OBJS) $(LINK_TARGET)

# The rule for "all" is used to incrementally build your system.
# It does this by expressing a dependency on the results of that system,
# which in turn have their own rules and dependencies.
all : $(LINK_TARGET)
	echo All done

# Here is a simple Rule (used for "cleaning" your build environment).
# It has a Target named "clean" (left of the colon ":" on the first line),
# no Dependencies (right of the colon),
# and two Commands (indented by tabs on the lines that follow).
# The space before the colon is not required but added here for clarity.
clean : 
	rm -f $(REBUILDABLES)
	echo Clean done

final : $(LINK_TARGET)
	echo Compilation done
	echo Source code...
	cat main.cpp
	cat classBody.h
	cat classBody.cpp
	cat derived.h
	cat derived.cpp
	cat element.h
	cat element.cpp
	cat author.h
	cat author.cpp
	cat Error_Derived.h
	cat makefile
	echo Test script execution...
	./$(CURRENT_ASSIGNMENT).exe < $(TEST_SCRIPT1) -f data.dat
	./$(CURRENT_ASSIGNMENT).exe < $(TEST_SCRIPT2) -f data.dat

# There are two standard Targets your Makefile should probably have:
# "all" and "clean", because they are often command-line Goals.
# Also, these are both typically Artificial Targets, because they don't typically
# correspond to real files named "all" or "clean".  

# There is no required order to the list of rules as they appear in the Makefile.
# Make will build its own dependency tree and only execute each rule only once
# its dependencies' rules have been executed successfully.

# Here is a Rule that uses some built-in Make Macros in its command:
# $@ expands to the rule's target, in this case "test_me.exe".
# $^ expands to the rule's dependencies, in this case the three files
# main.o, test1.o, and  test2.o.
$(LINK_TARGET) : $(OBJS)
	g++ -Wall -std=c++11 -g -o $@ $^ -lboost_serialization

# Here is a Pattern Rule, often used for compile-line.
# It says how to create a file with a .o suffix, given a file with a .cpp suffix.
# The rule's command uses some built-in Make Macros:
# $@ for the pattern-matched target
# $< for the pattern-matched dependency
%.o : %.cpp
	g++ -Wall -g -o $@ -c $< 

# These are Dependency Rules, which are rules without any command.
# Dependency Rules indicate that if any file to the right of the colon changes,
# the target to the left of the colon should be considered out-of-date.
# The commands for making an out-of-date target up-to-date may be found elsewhere
# (in this case, by the Pattern Rule above).
# Dependency Rules are often used to capture header file dependencies.
main.o : derived.cpp classBody.cpp Error_Derived.h ioMediaInfo.h
classBody.o : classBody.h derived.cpp derived.h element.cpp element.h
derived.o : element.cpp element.h derived.h
