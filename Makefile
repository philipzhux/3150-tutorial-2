CFILES:= $(shell ls|grep .c)
PROGS:=$(patsubst %.c,%,$(CFILES))
LIB := -pthread

all: $(PROGS)

%:%.c
	$(CC) $(LIB) -o $@ $<

clean:$(PROGS)
	rm -f $(PROGS)