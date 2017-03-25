.DEFAULT_GOAL := test

FILES :=           \
    .gitignore     \
    Darwin.c++     \
    Darwin.h       \
    Darwin.log     \
    html           \
    makefile       \
    RunDarwin.c++  \
    RunDarwin.in   \
    RunDarwin.out  \
    TestDarwin.c++ \
    TestDarwin.out

# uncomment these:
#    .travis.yml                         \
#    darwin-tests/GitHubID-RunDarwin.in  \
#    darwin-tests/GitHubID-RunDarwin.out \

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

Darwin.log:
	git log > Darwin.log

Doxyfile:
	doxygen -g

# Make the following edits to Doxyfile.
# EXTRACT_ALL            = YES
# EXTRACT_PRIVATE        = YES
# EXTRACT_STATIC         = YES

RunDarwin:
	$(CXX) $(CXXFLAGS) Darwin.c++ RunDarwin.c++ -o RunDarwin
	-$(CLANG-CHECK) -extra-arg=-std=c++11          Darwin.c++     --
	-$(CLANG-CHECK) -extra-arg=-std=c++11 -analyze Darwin.c++     --
	-$(CLANG-CHECK) -extra-arg=-std=c++11          RunDarwin.c++  --
	-$(CLANG-CHECK) -extra-arg=-std=c++11 -analyze RunDarwin.c++  --

.PHONY: RunDarwin.tmp
RunDarwin.tmp: RunDarwin
	./RunDarwin < RunDarwin.in > RunDarwin.tmp
	diff RunDarwin.tmp RunDarwin.out

TestDarwin:
	$(CXX) $(CXXFLAGS) $(GCOVFLAGS) Darwin.c++ TestDarwin.c++ -o TestDarwin $(LDFLAGS)
	-$(CLANG-CHECK) -extra-arg=-std=c++11          TestDarwin.c++ --
	-$(CLANG-CHECK) -extra-arg=-std=c++11 -analyze TestDarwin.c++ --

.PHONY: TestDarwin.tmp
TestDarwin.tmp: TestDarwin
	$(VALGRIND) ./TestDarwin                                       >  TestDarwin.tmp 2>&1
	-$(GCOV) -b Darwin.c++     | grep -A 5 "File 'Darwin.c++'"     >> TestDarwin.tmp
	-$(GCOV) -b TestDarwin.c++ | grep -A 5 "File 'TestDarwin.c++'" >> TestDarwin.tmp
	cat TestDarwin.tmp

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
	rm -f  RunDarwin
	rm -f  RunDarwin.tmp
	rm -f  TestDarwin
	rm -f  TestDarwin.tmp
	rm -rf *.dSYM
	rm -rf latex

config:
	git config -l

format:
	$(CLANG-FORMAT) -i Darwin.c++
	$(CLANG-FORMAT) -i Darwin.h
	$(CLANG-FORMAT) -i RunDarwin.c++
	$(CLANG-FORMAT) -i TestDarwin.c++

scrub:
	make clean
	rm -f  Darwin.log
	rm -f  Doxyfile
	rm -rf html

status:
	make clean
	@echo
	git branch
	git remote -v
	git status

test: html Darwin.log RunDarwin.tmp TestDarwin.tmp darwin-tests
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
