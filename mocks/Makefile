CC = gcc
CXX = g++
LD = g++

TEST_DIR = tests
BUILD_DIR = build


CFLAGS = -c -Wall -Wextra -g
CXXFLAGS = $(CFLAGS)

#LDFLAGS += -L $(CPPUTEST_PATH)
LDFLAGS += -lCppUTest -lCppUTestExt

###########################################
#				 INCLUDES
###########################################

#INCLUDES += -I $(CPPUTEST_INCLUDE)
INCLUDES += -I lib/
INCLUDES += -I drivers/

############################################
# 				SOURCE FILES
############################################

OBJS 		+= $(BUILD_DIR)/log.o
OBJS 		+= $(BUILD_DIR)/sensor.o
OBJS 		+= $(BUILD_DIR)/driver_mock.o

TEST_OBJS 	+= $(BUILD_DIR)/AllTests.o
TEST_OBJS 	+= $(BUILD_DIR)/ut_sensor.o

PREREQ = $(BUILD_DIR)

all: $(PREREQ) $(BUILD_DIR)/run_tests 

$(PREREQ):
	mkdir $(PREREQ)

$(BUILD_DIR)/%.o: lib/%.c
	$(CC) $(CFLAGS) $(INCLUDES) -o $(BUILD_DIR)/$(*).o lib/$(*).c

$(BUILD_DIR)/%.o: drivers/%.c
	$(CC) $(CFLAGS) $(INCLUDES) -o $(BUILD_DIR)/$(*).o drivers/$(*).c

$(BUILD_DIR)/%.o: tests/%.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -o $(BUILD_DIR)/$(*).o tests/$(*).cpp

$(BUILD_DIR)/run_tests: $(TEST_OBJS) $(OBJS)
	$(LD) -o $(BUILD_DIR)/run_tests $^ $(LDFLAGS) 
	$(BUILD_DIR)/run_tests

clean:
	rm -rf $(BUILD_DIR)/*