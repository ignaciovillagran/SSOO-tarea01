CC=gcc
RM=rm -f

TARGET=../hora


INCLUDES=-I./include -I/opt/local/include
LDFLAGS=-L/usr/local/lib 
LDLIBS=-lpthread

CFLAGS=-g -Wall -O2

DIR_OBJ=objs

SRCS=$(wildcard *.c)

OBJS=$(patsubst %.c,$(DIR_OBJ)/%.o,$(SRCS))


all: $(TARGET)
	@echo Made [ $? ] OK :\)

$(TARGET): $(OBJS)
	@echo Linking [$@]
	@$(CC) -o $@ $^ $(CFLAGS) $(LDLIBS) $(LDFLAGS) 

$(DIR_OBJ)/%.o: %.c
	@echo Compiling [$@]
	@mkdir -p $(DIR_OBJ)
	@$(CC) -c -o $@ $< $(CFLAGS) $(INCLUDES)

clean:
	@$(RM) $(OBJS)
	@$(RM) *~ core

distclean: clean
	@$(RM) $(TARGET)
	@$(RM) -f $(DIR_OBJ)

.PHONY: all clean distclean
	
