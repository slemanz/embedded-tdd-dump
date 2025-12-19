CC = gcc
CXX = g++
LD = g++

TEST_DIR = tests
BUILD_DIR = build


CFLAGS = -c -Wall -Wextra -g
CXXFLAGS = $(CFLAGS)

#LDFLAGS += -L $(CPPUTEST_PATH) # used in windows env
LDFLAGS += -lCppUTest -lCppUTestExt

###########################################
#				 INCLUDES
###########################################

#INCLUDES += -I $(CPPUTEST_INCLUDE) # used in windows env
INCLUDES += -I lib/

############################################
# 				SOURCE FILES
############################################

OBJS 		+= $(BUILD_DIR)/calculator.o

TEST_OBJS 	+= $(BUILD_DIR)/AllTests.o
TEST_OBJS 	+= $(BUILD_DIR)/calculatorTests.o

PREREQ = $(BUILD_DIR)

all: $(PREREQ) $(BUILD_DIR)/run_tests $(TEST_OBJS)

$(PREREQ):
	mkdir $(PREREQ)

$(BUILD_DIR)/%.o: lib/%.c
	$(CC) $(CFLAGS) $(INCLUDES) -o $(BUILD_DIR)/$(*).o lib/$(*).c

$(BUILD_DIR)/%.o: tests/%.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -o $(BUILD_DIR)/$(*).o tests/$(*).cpp

$(BUILD_DIR)/run_tests: $(TEST_OBJS) $(OBJS)
	$(LD) -o $(BUILD_DIR)/run_tests $^ $(LDFLAGS) 
	$(BUILD_DIR)/run_tests

clean:
	rm -rf $(BUILD_DIR)/*