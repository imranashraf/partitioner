CC=g++
EXEC=exec
CFLAGS= -g -Wall -O2
LIBS=-lm -lxerces-c
LFLAGS=-L/data/lib/xercesc/lib
INCLUDES=-I. -I/data/lib/XSD/libxsd -I/data/lib/boost_1_48_0 -I/data/lib/xercesc/include 
CPPSRC=main.cpp globals.cpp Graph.cpp Xml.cpp
CXXSRC=q2profiling.cxx
XSDSC=q2profiling.xsd 
OBJECTS=$(CPPSRC:.cpp=.o)
OBJECTS+=$(CXXSRC:.cxx=.o)
# HIDE=@-
XMLFile=q2profiling.xml
FuncList=funcList.txt

all:compile
compile:$(EXEC)

$(EXEC):$(OBJECTS)
	$(HIDE) echo "Linking ... "
	$(HIDE) $(CC) $(LFLAGS) -o $@ $^ $(LIBS)

%.o: %.cpp
	$(HIDE) echo "Compiling $< ... "
	$(HIDE) $(CC) $(INCLUDES) -c $(CFLAGS) -o $@ $<

%.o: %.cxx
	$(HIDE) echo "Compiling $< ..."
	$(HIDE) $(CC) $(INCLUDES) -c $(CFLAGS) -o $@ $<

run: $(EXEC)
	$(HIDE) echo "Executing ... "
	$(HIDE) ./$(EXEC) $(XMLFile) $(FuncList)

clean: 
	$(HIDE) echo "Cleaning  ... "
	$(HIDE) rm -rf $(EXEC) $(OBJECTS) graph.dot graph.pdf

generate:
	$(HIDE) echo "Generating cxx and hxx files from xsd schema ... "
	$(HIDE) ~/XSD/bin/xsd cxx-tree $(XSDSRC)

.PHONY: all clean compile run
