.PHONY: all clean

implementations = recur iter threads

all: clean

define test_template =
.PHONY: run-test-$(1) clean-$(1)
all:nqueens_$(1) test-$(1)
test-all: run-test-$(1)
run-test-$(1): test-$(1)
	@./test-$(1) --gtest_color=yes
clean: clean-$(1)
clean-$(1):
	rm -f test-$(1) nqueens_$(1)
nqueens_$(1): main.cpp nqueens_$(1).cpp
	g++ -O3 -I. -pthread -W -Wall -Wextra -std=c++14 $$^ -o $$@
test-$(1): tests.cpp  nqueens_$(1).cpp
	g++ -O3 -I. -pthread -W -Wall -Wextra -std=c++14 $$^ -L/usr/lib -lgtest -lgtest_main -o $$@
endef

$(foreach test,$(implementations), $(eval $(call test_template,$(test))))



