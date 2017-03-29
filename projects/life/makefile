.DEFAULT_GOAL := test

FILES :=         \
    .gitignore   \
    Life.c++     \
    Life.h       \
    Life.log     \
    html         \
    makefile     \
    RunLife.c++  \
    RunLife.in   \
    RunLife.out  \
    TestLife.c++ \
    TestLife.out

# uncomment these:
#    .travis.yml                         \
#    darwin-tests/GitHubID-RunLife.in  \
#    darwin-tests/GitHubID-RunLife.out \

ifeq ($(shell uname), Darwin)                                           # Apple
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

.PHONY: darwin-tests
darwin-tests:
	git clone https://github.com/cs371pt-spring-2017/darwin-tests.git

html: Doxyfile
	doxygen Doxyfile

Life.log:
	git log > Life.log

Doxyfile:
	doxygen -g

# Make the following edits to Doxyfile.
# EXTRACT_ALL            = YES
# EXTRACT_PRIVATE        = YES
# EXTRACT_STATIC         = YES

RunLife:
	$(CXX) $(CXXFLAGS) Life.c++ RunLife.c++ -o RunLife
	-$(CLANG-CHECK) -extra-arg=-std=c++11          Life.c++     --
	-$(CLANG-CHECK) -extra-arg=-std=c++11 -analyze Life.c++     --
	-$(CLANG-CHECK) -extra-arg=-std=c++11          RunLife.c++  --
	-$(CLANG-CHECK) -extra-arg=-std=c++11 -analyze RunLife.c++  --

.PHONY: RunLife.tmp
RunLife.tmp: RunLife
	./RunLife < RunLife.in > RunLife.tmp
	diff RunLife.tmp RunLife.out

TestLife:
	$(CXX) $(CXXFLAGS) $(GCOVFLAGS) Life.c++ TestLife.c++ -o TestLife $(LDFLAGS)
	-$(CLANG-CHECK) -extra-arg=-std=c++11          TestLife.c++ --
	-$(CLANG-CHECK) -extra-arg=-std=c++11 -analyze TestLife.c++ --

.PHONY: TestLife.tmp
TestLife.tmp: TestLife
	$(VALGRIND) ./TestLife                                       >  TestLife.tmp 2>&1
	-$(GCOV) -b Life.c++     | grep -A 5 "File 'Life.c++'"     >> TestLife.tmp
	-$(GCOV) -b TestLife.c++ | grep -A 5 "File 'TestLife.c++'" >> TestLife.tmp
	cat TestLife.tmp

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
	rm -f  RunLife
	rm -f  RunLife.tmp
	rm -f  TestLife
	rm -f  TestLife.tmp
	rm -rf *.dSYM
	rm -rf latex

config:
	git config -l

format:
	$(CLANG-FORMAT) -i Life.c++
	$(CLANG-FORMAT) -i Life.h
	$(CLANG-FORMAT) -i RunLife.c++
	$(CLANG-FORMAT) -i TestLife.c++

scrub:
	make clean
	rm -f  Life.log
	rm -f  Doxyfile
	rm -rf html

status:
	make clean
	@echo
	git branch
	git remote -v
	git status

test: html Life.log RunLife.tmp TestLife.tmp darwin-tests
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
