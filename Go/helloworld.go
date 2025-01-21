/*
	4 part
	package declaration
	Import packages
	Functions
	Statements and expressions
*/

// every program is part of a package
// we define this uisng the package keyword
package main

// lets us import files included in the fmt package.
import ("fmt")
func main(){
	// function made available from the fmt package
	// used to output/ print text
	// can use ';' instead of endline '\n'
	fmt.Println("Hello World!")
}