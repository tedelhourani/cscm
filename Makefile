IDIR =./include
CC=cc
CFLAGS=-I$(IDIR) -g

ODIR=./obj
LDIR =./lib

LIBS=-lm

_DEPS = parser.h ast.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = main.o parser.o ast.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))


$(ODIR)/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

main: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~ main
