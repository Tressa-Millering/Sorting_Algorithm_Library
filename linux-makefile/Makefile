CC = g++
CFLAGS = -g
INCLUDEDIR = .
LIBDIR = .
LIB = sort
SORTSDIR = ./sort_files
SORTS = selection_sort.o insertion_sort.o bubble_sort.o quick_sort.o merge_sort.o
LIBOBJ = libsort.a
TARGET = srt
DEBUG_TARGET = srt_debug
EXE := $(shell find . -maxdepth 1 -type f -executable ! -name 'Makefile' | head -1)  #only for the run command, find the first exe in the curr dir
DATAFILES := $(wildcard datafiles/*)
VPATH = . $(SORTSDIR)

TARGET: $(TARGET)

.PHONY: clean cleabobjs cleanexes run debug

debug: CFLAGS += -DDEBUG
debug: clean $(DEBUG_TARGET)

$(TARGET): Sort.h main.o $(LIBOBJ)
	$(MAKE) cleanexes
	$(CC) $(CFLAGS) -L$(LIBDIR) -o $@ main.o -l$(LIB)
	$(MAKE) cleanobjs

$(DEBUG_TARGET): Sort.h main.o $(LIBOBJ)
	$(CC) $(CFLAGS) -L$(LIBDIR) -o $@ main.o -l$(LIB)
	$(MAKE) cleanobjs

$(LIBOBJ): $(SORTS)
	ar -rs $@ $(SORTS)


.SUFFIXES: .cpp .o
.cpp.o: 
	$(CC) $(CFLAGS) -c $<

clean:
	/bin/rm -rf *.o *.a $(TARGET) $(DEBUG_TARGET)
	/bin/ls | /bin/grep -P "sorted" | /bin/xargs -d"\n" rm

cleanobjs:
	/bin/rm -rf *.o *.a

cleanexes:
	/bin/rm -rf $(TARGET) $(DEBUG_TARGET)


run:
	$(foreach var, $(DATAFILES), $(EXE) $(var);)
