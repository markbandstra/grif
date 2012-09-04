# Simulator that passes data using classes

This is an example application that uses GRIF.  It is identical to the 
simulator example, except that the data is passed using classes.  There are
two classes used: ```EventClassArray``` and ```EventClassVector```, which
store the ADC, channel, and timestamp data using simple arrays or QVectors, 
respectively.

When running this example, the lengths of the arrays or vectors are printed
to stdout.  This way one can see how vectors are corrupted by the GRIF
MemoryManager while arrays are not.


