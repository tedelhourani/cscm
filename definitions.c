

char * symbol[256];         # symbol implemented as a string of length at most 256 characters
int  number;      # A Scheme Number is implemented as a Python int or float
  Atom   = (Symbol, Number) # A Scheme Atom is a Symbol or Number
  List   = list             # A Scheme List is implemented as a Python list
  Exp    = (Atom, List)     # A Scheme expression is an Atom or List
  Env    = dict             # A Scheme environment (defined below)
# is a mapping of {variable: value}
