package main
import("fmt")
/*
	Print()
	Println()
	Printf()
*/
func main(){
	var i, j string = "Hello", "world"
	fmt.Print(i)
	fmt.Print(j)
	// or
	fmt.Println()
	fmt.Printf("You are my %s \n", j)
	// or %v : value ||| %T : type
	fmt.Printf("i has value : %v and type : %T\n", i, i)
}