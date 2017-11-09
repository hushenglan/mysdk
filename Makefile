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

IMPLEMENT_MODULE_NAME = implement

PROJ_DIR = .
IMPLEMENT_DIR = $(PROJ_DIR)/$(IMPLEMENT_MODULE_NAME)

OBJS_DIR = $(PROJ_DIR)/objs
IMPLEMENT_OBJS_DIR = $(OBJS_DIR)/$(IMPLEMENT_MODULE_NAME)

CORE_INCS += -I$(IMPLEMENT_DIR)

LIBS_LOCS += -L$(PROJ_DIR)/deps/gtest/googletest-release-1.8.0/googletest/make
LIBS      += -Wl,-Bstatic -lexpat -lreadline -lncurses
LIBS      += -Wl,-Bdynamic -lpthread -lbz2 -lz -lrt -lm -lc -ldl
GTEST_LIB += $(PROJ_DIR)/deps/gtest/googletest-release-1.8.0/googletest/make/gtest.a
GTEST_LIB += $(PROJ_DIR)/deps/gtest/googletest-release-1.8.0/googletest/make/gtest_main.a

DEMO_OBJS  = $(BOOST_OBJS_DIR)/lexical.o $(OBJS_DIR)/demo_blue.o
DEMO_EXE   = $(PROJ_DIR)/demo_blue

GTEST_OBJS = $(TRAITS_OBJS_DIR)/csm2.o $(TRAITS_OBJS_DIR)/rparam2.o $(TRAITS_OBJS_DIR)/rparam1.o \
			 $(TRAITS_OBJS_DIR)/promote.o $(TRAITS_OBJS_DIR)/apply2.o \
			 $(TRAITS_OBJS_DIR)/apply1.o $(TRAITS_OBJS_DIR)/isclasst.o \
			 $(TRAITS_OBJS_DIR)/elementtype.o $(TRAITS_OBJS_DIR)/sizeof.o \
			 $(TRAITS_OBJS_DIR)/accum0.o $(TRAITS_OBJS_DIR)/accum9.o \
			 $(TRAITS_OBJS_DIR)/accum8.o $(TRAITS_OBJS_DIR)/accum7.o \
			 $(TRAITS_OBJS_DIR)/accum5.o $(TRAITS_OBJS_DIR)/accum4.o \
		 	 $(TRAITS_OBJS_DIR)/accum3.o $(TRAITS_OBJS_DIR)/accum2.o $(TRAITS_OBJS_DIR)/accum1.o \
			 $(POLY_OBJS_DIR)/dynahier.o $(POLY_OBJS_DIR)/dynahier_test.o \
			 $(PRIMER_OBJS_DIR)/tracer_test.o $(PRIMER_OBJS_DIR)/tracer.o \
			 $(PRIMER_OBJS_DIR)/mysecondstack_inst.o $(PRIMER_OBJS_DIR)/mysecondstackmain.o \
			 $(PRIMER_OBJS_DIR)/myfirstinst.o $(PRIMER_OBJS_DIR)/myfirst.o $(PRIMER_OBJS_DIR)/myfirstmain.o \
			 $(PRIMER_OBJS_DIR)/type.o $(PRIMER_OBJS_DIR)/refnonref.o \
			 $(PRIMER_OBJS_DIR)/max5.o $(PRIMER_OBJS_DIR)/zero_init.o \
			 $(PRIMER_OBJS_DIR)/stack7decl.o $(PRIMER_OBJS_DIR)/stack6decl.o \
			 $(PRIMER_OBJS_DIR)/stack5decl.o $(PRIMER_OBJS_DIR)/printcoll.o \
			 $(PRIMER_OBJS_DIR)/addval.o $(PRIMER_OBJS_DIR)/stack4.o \
			 $(PRIMER_OBJS_DIR)/stack3.o $(PRIMER_OBJS_DIR)/stack2.o \
			 $(PRIMER_OBJS_DIR)/stack1.o $(PRIMER_OBJS_DIR)/max4.o \
			 $(PRIMER_OBJS_DIR)/max3.o $(PRIMER_OBJS_DIR)/max2.o \
			 $(PRIMER_OBJS_DIR)/max.o $(PRIMER_OBJS_DIR)/abs.o \
			 $(OBJS_DIR)/gtest_blue.o
GTEST_EXE  = $(PROJ_DIR)/gtest_blue



#------------------------------- MKDIR -------------------------------
build_obj_path := $(shell \
	mkdir -p $(OBJS_DIR) && \
	mkdir -p $(PRIMER_OBJS_DIR) && \
	mkdir -p $(POLY_OBJS_DIR) && \
	mkdir -p $(TRAITS_OBJS_DIR) && \
	mkdir -p $(BOOST_OBJS_DIR))



#------------------------------- ALL -------------------------------
.PHONY:all
all:  gtest

.PHONY:test
test: demo



#------------------------------- DEPENDS -------------------------------
$(OBJS_DIR)/%.d:$(PROJ_DIR)/%.cc
	@set -e; rm -f $@; \
	$(CXX) -MM $(CORE_INCS) $< > $@.$$$$; \
	sed 's,\($*\)\.o[ :]*,$(OBJS_DIR)/\1.o $@ : ,g' < $@.$$$$ > $@; \
	rm -f $@.$$$$

$(BOOST_OBJS_DIR)/%.d:$(BOOST_DIR)/%.cc
	@set -e; rm -f $@; \
	$(CXX) -MM $(CORE_INCS) $< > $@.$$$$; \
	sed 's,\($*\)\.o[ :]*,$(BOOST_OBJS_DIR)/\1.o $@ : ,g' < $@.$$$$ > $@; \
	rm -f $@.$$$$

$(PRIMER_OBJS_DIR)/%.d:$(PRIMER_DIR)/%.cc
	@set -e; rm -f $@; \
	$(CXX) -MM $(CORE_INCS) $< > $@.$$$$; \
	sed 's,\($*\)\.o[ :]*,$(PRIMER_OBJS_DIR)/\1.o $@ : ,g' < $@.$$$$ > $@; \
	rm -f $@.$$$$

$(POLY_OBJS_DIR)/%.d:$(POLY_DIR)/%.cc
	@set -e; rm -f $@; \
	$(CXX) -MM $(CORE_INCS) $< > $@.$$$$; \
	sed 's,\($*\)\.o[ :]*,$(POLY_OBJS_DIR)/\1.o $@ : ,g' < $@.$$$$ > $@; \
	rm -f $@.$$$$

$(TRAITS_OBJS_DIR)/%.d:$(TRAITS_DIR)/%.cc
	@set -e; rm -f $@; \
	$(CXX) -MM $(CORE_INCS) $< > $@.$$$$; \
	sed 's,\($*\)\.o[ :]*,$(TRAITS_OBJS_DIR)/\1.o $@ : ,g' < $@.$$$$ > $@; \
	rm -f $@.$$$$

-include $(GTEST_OBJS:.o=.d)



#------------------------------- OBJS -------------------------------
$(OBJS_DIR)/%.o:$(PROJ_DIR)/%.cc
	$(CXX) -c $(CXXFLAGS) $(CORE_INCS) -o $@ $<

$(BOOST_OBJS_DIR)/%.o:$(BOOST_DIR)/%.cc
	$(CXX) -c $(CXXFLAGS) $(CORE_INCS) -o $@ $<

$(PRIMER_OBJS_DIR)/%.o:$(PRIMER_DIR)/%.cc
	$(CXX) -c $(CXXFLAGS) $(CORE_INCS) -o $@ $<

$(POLY_OBJS_DIR)/%.o:$(POLY_DIR)/%.cc
	$(CXX) -c $(CXXFLAGS) $(CORE_INCS) -o $@ $<

$(TRAITS_OBJS_DIR)/%.o:$(TRAITS_DIR)/%.cc
	$(CXX) -c $(CXXFLAGS) $(CORE_INCS) -o $@ $<


.PHONY:demo
demo: $(DEMO_OBJS)
	@echo
	@echo ----------------------------- compile finish, then link -----------------------------
	@echo
	$(LINK) -o $(DEMO_EXE) $(DEMO_OBJS) $(LIBS_LOCS) $(LIBS)


.PHONY:gtest
gtest: $(GTEST_OBJS)
	@echo
	@echo ----------------------------- compile finish, then link -----------------------------
	@echo
	$(LINK) -o $(GTEST_EXE) $(GTEST_OBJS) $(LIBS_LOCS) $(LIBS) $(GTEST_LIB)



#------------------------------- CLEAN -------------------------------
.PHONY:clean
clean:
	rm -fr $(OBJS_DIR) $(DEMO_EXE) $(GTEST_EXE)



#------------------------------- UNPACK -------------------------------
.PHONY:unpack
unpack:
	sh $(PROJ_DIR)/unpack.sh
