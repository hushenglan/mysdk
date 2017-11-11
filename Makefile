#
# Linux Makefile.
#



#------------------------------- DEFINE -------------------------------
CC = gcc
CFLAGS = -std=gnu++11 -D_DEBUG -ggdb -O0 -Wall -Wextra -D_REENTRANT -D_FILE_OFFSET_BITS=64

CXX = g++
CXXFLAGS = -std=gnu++11 -D_DEBUG -ggdb -O0 -Wall -Wextra -D_REENTRANT -D_FILE_OFFSET_BITS=64

AR      = ar
ARFLAGS = -rvl
LINK    = $(CXX)

FRAMEWORK_MODULE_NAME = framework
BUSINESS_MODULE_NAME = business
EXAMPLE_MODULE_NAME = example
INTERFACE_MODULE_NAME = interface
BUSINESS1_MODULE_NAME = business_1
BUSINESS2_MODULE_NAME = business_2

PROJ_DIR = .
INTERFACE_DIR = $(BUSINESS_DIR)/$(INTERFACE_MODULE_NAME)
BUSINESS_DIR = $(PROJ_DIR)/$(BUSINESS_MODULE_NAME)
BUSINESS1_DIR = $(BUSINESS_DIR)/$(BUSINESS1_MODULE_NAME)
BUSINESS2_DIR = $(BUSINESS_DIR)/$(BUSINESS2_MODULE_NAME)
FRAMEWORK_DIR = $(PROJ_DIR)/$(FRAMEWORK_MODULE_NAME)
EXAMPLE_DIR = $(PROJ_DIR)/$(EXAMPLE_MODULE_NAME)

OBJS_DIR = $(PROJ_DIR)/objs
FRAMEWORK_OBJS_DIR = $(OBJS_DIR)/$(FRAMEWORK_MODULE_NAME)
BUSINESS_OBJS_DIR = $(OBJS_DIR)/$(BUSINESS_MODULE_NAME)
BUSINESS1_OBJS_DIR = $(BUSINESS_OBJS_DIR)/$(BUSINESS1_MODULE_NAME)
BUSINESS2_OBJS_DIR = $(BUSINESS_OBJS_DIR)/$(BUSINESS2_MODULE_NAME)
EXAMPLE_OBJS_DIR = $(OBJS_DIR)/$(EXAMPLE_MODULE_NAME)

CORE_INCS += -I$(INTERFACE_DIR) -I$(FRAMEWORK_DIR) -I$(BUSINESS1_DIR) -I$(BUSINESS2_DIR)

LIBS      += -Wl,-Bstatic -lexpat -lreadline -lncurses
LIBS      += -Wl,-Bdynamic -lpthread -lbz2 -lz -lrt -lm -lc -ldl
GTEST_LIBS_LOC += -L$(PROJ_DIR)/deps/gtest/googletest-release-1.8.0/googletest/make
GTEST_LIBS += $(PROJ_DIR)/deps/gtest/googletest-release-1.8.0/googletest/make/gtest.a
GTEST_LIBS += $(PROJ_DIR)/deps/gtest/googletest-release-1.8.0/googletest/make/gtest_main.a

MYLIB = $(PROJ_DIR)/mylib.a
MYLIB_OBJS = $(FRAMEWORK_OBJS_DIR)/mysdk.o \
             $(FRAMEWORK_OBJS_DIR)/mysdk_impl.o \
             $(BUSINESS1_OBJS_DIR)/business_1.o \
             $(BUSINESS1_OBJS_DIR)/business_1_impl.o \
             $(BUSINESS2_OBJS_DIR)/business_2.o \
             $(BUSINESS2_OBJS_DIR)/business_2_impl.o

DEMO_OBJS  = $(OBJS_DIR)/demo_1.o
DEMO_EXE   = $(PROJ_DIR)/demo



#------------------------------- MKDIR -------------------------------
build_obj_path := $(shell \
    mkdir -p $(OBJS_DIR) && \
    mkdir -p $(FRAMEWORK_OBJS_DIR) && \
    mkdir -p $(BUSINESS_OBJS_DIR) && \
    mkdir -p $(BUSINESS1_OBJS_DIR) && \
    mkdir -p $(BUSINESS2_OBJS_DIR) && \
    mkdir -p $(EXAMPLE_OBJS_DIR))



#------------------------------- ALL -------------------------------
.PHONY:all
all: mylib demo



#------------------------------- DEPENDS -------------------------------
$(FRAMEWORK_OBJS_DIR)/%.d:$(FRAMEWORK_DIR)/%.cpp
	@set -e; rm -f $@; \
	$(CXX) -MM $(CORE_INCS) $< > $@.$$$$; \
	sed 's,\($*\)\.o[ :]*,$(FRAMEWORK_OBJS_DIR)/\1.o $@ : ,g' < $@.$$$$ > $@; \
	rm -f $@.$$$$

$(BUSINESS1_OBJS_DIR)/%.d:$(BUSINESS1_DIR)/%.cpp
	@set -e; rm -f $@; \
	$(CXX) -MM $(CORE_INCS) $< > $@.$$$$; \
	sed 's,\($*\)\.o[ :]*,$(BUSINESS1_OBJS_DIR)/\1.o $@ : ,g' < $@.$$$$ > $@; \
	rm -f $@.$$$$

$(BUSINESS2_OBJS_DIR)/%.d:$(BUSINESS2_DIR)/%.cpp
	@set -e; rm -f $@; \
	$(CXX) -MM $(CORE_INCS) $< > $@.$$$$; \
	sed 's,\($*\)\.o[ :]*,$(BUSINESS2_OBJS_DIR)/\1.o $@ : ,g' < $@.$$$$ > $@; \
	rm -f $@.$$$$

$(EXAMPLE_OBJS_DIR)/%.d:$(EXAMPLE_DIR)/%.cpp
	@set -e; rm -f $@; \
	$(CXX) -MM $(CORE_INCS) $< > $@.$$$$; \
	sed 's,\($*\)\.o[ :]*,$(EXAMPLE_OBJS_DIR)/\1.o $@ : ,g' < $@.$$$$ > $@; \
	rm -f $@.$$$$

$(OBJS_DIR)/%.d:$(EXAMPLE_DIR)/%.cpp
	@set -e; rm -f $@; \
	$(CXX) -MM $(CORE_INCS) $< > $@.$$$$; \
	sed 's,\($*\)\.o[ :]*,$(OBJS_DIR)/\1.o $@ : ,g' < $@.$$$$ > $@; \
	rm -f $@.$$$$

-include $(MYLIB_OBJS:.o=.d)
-include $(DEMO_OBJS:.o=.d)



#------------------------------- OBJS -------------------------------
$(FRAMEWORK_OBJS_DIR)/%.o:$(FRAMEWORK_DIR)/%.cpp
	$(CXX) -c $(CXXFLAGS) $(CORE_INCS) -o $@ $<

$(BUSINESS1_OBJS_DIR)/%.o:$(BUSINESS1_DIR)/%.cpp
	$(CXX) -c $(CXXFLAGS) $(CORE_INCS) -o $@ $<

$(BUSINESS2_OBJS_DIR)/%.o:$(BUSINESS2_DIR)/%.cpp
	$(CXX) -c $(CXXFLAGS) $(CORE_INCS) -o $@ $<

$(EXAMPLE_OBJS_DIR)/%.o:$(EXAMPLE_DIR)/%.cpp
	$(CXX) -c $(CXXFLAGS) $(CORE_INCS) -o $@ $<

$(OBJS_DIR)/%.o:$(EXAMPLE_DIR)/%.cpp
	$(CXX) -c $(CXXFLAGS) $(CORE_INCS) -o $@ $<


.PHONY:mylib
mylib: $(MYLIB_OBJS)
	@echo
	@echo ----------------------------- compile finish, then link -----------------------------
	@echo
	$(AR) $(ARFLAGS) $(MYLIB) $(MYLIB_OBJS)


.PHONY:demo
demo: $(DEMO_OBJS)
	@echo
	@echo ----------------------------- compile finish, then link -----------------------------
	@echo
	$(LINK) -o $(DEMO_EXE) $(DEMO_OBJS) $(MYLIB) $(LIBS_LOCS) $(LIBS)



#------------------------------- CLEAN -------------------------------
.PHONY:clean
clean:
	rm -fr $(OBJS_DIR) $(MYLIB) $(DEMO_EXE)



#------------------------------- UNPACK -------------------------------
.PHONY:unpack
unpack:
	sh $(PROJ_DIR)/unpack.sh
