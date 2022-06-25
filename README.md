# IDENT
There is a sequence of identifiers built according to the following rules:
1. The first sequence identifier is 'A1', the second is 'A2', the third is 'A3', and so on. 'A9' is followed by 'B1'. The next after 'Z9' looks like 'A1-A1', then 'A1-A2' and so on. 'A1-Z9' is followed by 'A2-A1'.
2. The maximum length of the identifier is ten groups of two characters.
3. Identifiers should never contain the letters 'D', 'F', 'G', 'J', 'M', 'Q', 'V' and the number '0'.
It is necessary to implement a class that provides work with the identifier according to the given rules.
The class must have the following functionality:
• A method that sets the current value of an identifier
• A method that increments the value of an identifier and returns a new value
Technical requirements for the solution:
1. Code must be thread-safe.
2. The code must compile.
3. The code must be cross-platform (successfully compiled by msvc/gcc/clang compilers).
4. To solve the problem, only the standard C++ library (standard up to C++17 inclusive) can be used.

=============================================================================
Two implementation options: arithmetic progression and geometric progression.
arithmetic:
A1
A1-A1
Z9-Z9 A1
Z9-Z9 Z9-Z9 A1

geometric:
A1
A1-A1 A1
A1-A1 Z9-Z9
A1-A2 A1-A1
