## Calculator

This is a simple C++ calculator that uses lexing and parsing for building an AST.

### Building

* Install [xmake](https://xmake.io/#/)
* Run `xmake`
 
### Usage

You can run the REPL version with `xmake run repl`

### Features
* Basic operations (`+`,`-`,`*`,`/`)
* Power (`^`)
* Parenthesis
* Functions (`sin`, `cos`, `tan`, `abs`)
* Variables:
    * mutable variables: `let a = 5`
    * constant variables `const n = 6`
