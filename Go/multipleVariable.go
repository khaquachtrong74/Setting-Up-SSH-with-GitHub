package main
import ("fmt")

func main(){
	var a, b, c, d int = 1, 2, 4, 5
	fmt.Println(a)
	fmt.Println(b)
	fmt.Println(c)
	fmt.Println(d)

	// or we can declared without type
	fmt.Println("==================")
	var x, y = 6, "hello"
	m, n := 7, false
	fmt.Println(x);fmt.Println(y);fmt.Println(m);fmt.Println(n)

	// declaration in a block
	var(
		a1 int
		b1 int = 5
		c1 string = "Hello" 
	)
	fmt.Println("============")
	fmt.Println(a1)
	fmt.Println(b1);fmt.Println(c1)
	// some multi word variable names

	// Camel Case
	myVar = "Hoho"
	// Pascal Case
	MyPas = "Hehge"
	// Snake Case
	my_snake_case = "HLM"
}