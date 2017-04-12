.DEFAULT_GOAL := test

FILES :=           \
    .gitignore     \
    Voting.c++     \
    Voting.h       \
    Voting.log     \
    html           \
    makefile       \
    RunVoting.c++  \
    RunVoting.in   \
    RunVoting.out  \
    TestVoting.c++ \
    TestVoting.out

# uncomment these:
#    .travis.yml                         \
#    voting-tests/GitHubID-RunVoting.in  \
#    voting-tests/GitHubID-RunVoting.out \

ifeq ($(shell uname), Voting)                                           # Apple
    CXX          := g++
    INCLUDE      := /usr/local/include
    CXXFLAGS     := -pedantic -std=c++14 -I$(INCLUDE) -Wall -Weffc++
    LIBB         := /usr/local/lib
    LIBG         := /usr/local/lib
    LDFLAGS      := -lboost_serialization -lgtest_main
    CLANG-CHECK  := clang-check
    GCOV         := gcov
    GCOVFLAGS    := -fprofile-arcs -ftest-coverage
    VALGRIND     := valgrind
    DOXYGEN      := doxygen
    CLANG-FORMAT := clang-format
else ifeq ($(CI), true)                                                 # Travis CI
    CXX          := g++-5
    INCLUDE      := /usr/include
    CXXFLAGS     := -pedantic -std=c++14 -Wall -Weffc++
    LIBB         := /usr/lib
    LIBG         := $(PWD)/gtest
    LDFLAGS      := -lboost_serialization -lgtest -lgtest_main -pthread
    CLANG-CHECK  := clang-check
    GCOV         := gcov-5
    GCOVFLAGS    := -fprofile-arcs -ftest-coverage
    VALGRIND     := valgrind
    DOXYGEN      := doxygen
    CLANG-FORMAT := clang-format
else ifeq ($(shell uname -p), unknown)                                  # Docker
    CXX          := g++
    INCLUDE      := /usr/include
    CXXFLAGS     := -pedantic -std=c++14 -Wall -Weffc++
    LIBB         := /usr/lib
    LIBG         := /usr/lib
    LDFLAGS      := -lboost_serialization -lgtest -lgtest_main -pthread
    CLANG-CHECK  := clang-check
    GCOV         := gcov
    GCOVFLAGS    := -fprofile-arcs -ftest-coverage
    VALGRIND     := valgrind
    DOXYGEN      := doxygen
    CLANG-FORMAT := clang-format-3.5
else                                                                    # UTCS
    CXX          := g++
    INCLUDE      := /usr/include
    CXXFLAGS     := -pedantic -std=c++14 -Wall -Weffc++
    LIBB         := /usr/lib/x86_64-linux-gnu
    LIBG         := /usr/local/lib
    LDFLAGS      := -lboost_serialization -lgtest -lgtest_main -pthread
    CLANG-CHECK  := clang-check
    GCOV         := gcov
    GCOVFLAGS    := -fprofile-arcs -ftest-coverage
    VALGRIND     := valgrind
    DOXYGEN      := doxygen
    CLANG-FORMAT := clang-format-3.8
endif

.PHONY: voting-tests
voting-tests:
	git clone https://github.com/cs371pt-spring-2017/voting-tests.git

html: Doxyfile
	doxygen Doxyfile

Voting.log:
	git log > Voting.log

Doxyfile:
	doxygen -g

# Make the following edits to Doxyfile.
# EXTRACT_ALL            = YES
# EXTRACT_PRIVATE        = YES
# EXTRACT_STATIC         = YES

RunVoting: Voting.h Voting.c++ RunVoting.c++
	$(CXX) $(CXXFLAGS) Voting.c++ RunVoting.c++ -o RunVoting
	-$(CLANG-CHECK) -extra-arg=-std=c++11          Voting.c++     --
	-$(CLANG-CHECK) -extra-arg=-std=c++11 -analyze Voting.c++     --
	-$(CLANG-CHECK) -extra-arg=-std=c++11          RunVoting.c++  --
	-$(CLANG-CHECK) -extra-arg=-std=c++11 -analyze RunVoting.c++  --

.PHONY: RunVoting.tmp
RunVoting.tmp: RunVoting
	./RunVoting < RunVoting.in > RunVoting.tmp
	diff RunVoting.tmp RunVoting.out

TestVoting: Voting.h Voting.c++ TestVoting.c++
	$(CXX) $(CXXFLAGS) $(GCOVFLAGS) Voting.c++ TestVoting.c++ -o TestVoting $(LDFLAGS)
	-$(CLANG-CHECK) -extra-arg=-std=c++11          TestVoting.c++ --
	-$(CLANG-CHECK) -extra-arg=-std=c++11 -analyze TestVoting.c++ --

.PHONY: TestVoting.tmp
TestVoting.tmp: TestVoting
	$(VALGRIND) ./TestVoting                                       >  TestVoting.tmp 2>&1
	-$(GCOV) -b Voting.c++     | grep -A 5 "File 'Voting.c++'"     >> TestVoting.tmp
	-$(GCOV) -b TestVoting.c++ | grep -A 5 "File 'TestVoting.c++'" >> TestVoting.tmp
	cat TestVoting.tmp

check:
	@not_found=0;                                 \
    for i in $(FILES);                            \
    do                                            \
        if [ -e $$i ];                            \
        then                                      \
            echo "$$i found";                     \
        else                                      \
            echo "$$i NOT FOUND";                 \
            not_found=`expr "$$not_found" + "1"`; \
        fi                                        \
    done;                                         \
    if [ $$not_found -ne 0 ];                     \
    then                                          \
        echo "$$not_found failures";              \
        exit 1;                                   \
    fi;                                           \
    echo "success";

clean:
	rm -f  *.bin
	rm -f  *.db
	rm -f  *.gcda
	rm -f  *.gcno
	rm -f  *.gcov
	rm -f  *.plist
	rm -f  RunVoting
	rm -f  RunVoting.tmp
	rm -f  TestVoting
	rm -f  TestVoting.tmp
	rm -rf *.dSYM
	rm -rf latex

config:
	git config -l

format:
	$(CLANG-FORMAT) -i Voting.c++
	$(CLANG-FORMAT) -i Voting.h
	$(CLANG-FORMAT) -i RunVoting.c++
	$(CLANG-FORMAT) -i TestVoting.c++

scrub:
	make clean
	rm -f  Voting.log
	rm -f  Doxyfile
	rm -rf html

status:
	make clean
	@echo
	git branch
	git remote -v
	git status

test: html Voting.log RunVoting.tmp TestVoting.tmp voting-tests
	ls -al
	make check

versions:
	which make
	make --version
	@echo
	which git
	git --version
	@echo
	which $(CXX)
	$(CXX) --version
	@echo
	ls -ald $(INCLUDE)/boost
	@echo
	ls -ald $(INCLUDE)/gtest
	@echo
	ls -al $(LIBB)/*boost*
	@echo
	ls -al $(LIBG)/*gtest*
	@echo
	which $(CLANG-CHECK)
	-$(CLANG-CHECK) --version
	@echo
	which $(GCOV)
	$(GCOV) --version
	@echo
	which $(VALGRIND)
	$(VALGRIND) --version
	@echo
	which $(DOXYGEN)
	$(DOXYGEN) --version
	@echo
	which $(CLANG-FORMAT)
	-$(CLANG-FORMAT) --version
