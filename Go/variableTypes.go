/*
	In Go:
	int
	float32
	string
	bool

	var
	it is not possible to declare a variable using :=
	without assigining a value to it
*/

package main
import ("fmt")
func main(){
	// var variablename type = value
	// we can have specify either type or value ( or both )

	var student1 string = "John" // type is string
	var student2 = "Jane" // type is inferred

	// variablename := value
	x := 2 // type is inferred(Suy ra)

	fmt.Println(student1)
	fmt.Println(student2)
	fmt.Println(x)
	fmt.Println("====================")
	var a string
	var b int
	var c bool

	fmt.Println(a) // ""
	fmt.Println(b) // 0
	fmt.Println(c) // false

	/*
		Difference Between var and :=
		var
			+ Can be used inside and outside of functions
			+ Variable declaration and value assignment 
			can be done separately
		:=
			+ Can only be used inside functions
			+ Variable declaration and value assignment cannot be
			done separately (must be done in the same line.)
	*/


}