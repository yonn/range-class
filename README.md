# Range
Range is a C++ class used to represent a range of integers. Range works with iterators and supports range based for loops. 
Range attempts to stimulate the behavior of the standard range function and class from Python. 

## Usage
Use the class in a range based for loop for maximum readability. It can also be used manually in a normal for loop, although it is not recomended. 

## Constructor

Values can be supplied to the constructor in three ways: 

1) supply the end value for iteration through (0, end].

2) supply both the end and the start values for iteration through (start, end].

3) supply both the end and the start values, along with the step, for incrementing the iterator differently.

by supplying a start value that is greater than the end value, the class detects that the iteration is backward and supplies a negative step value.
