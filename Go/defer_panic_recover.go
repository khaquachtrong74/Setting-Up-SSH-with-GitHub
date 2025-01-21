package main
import "fmt"
func first(){
	fmt.Println("1st")
}
func second(){
	fmt.Println("2nd")
}
func line(){
	fmt.Println("==============================")
}
func main(){
	defer second() // defer second() to the end of the function
	first()
	// one example is used to free near open
	/*
	f, _ := os.Open(file_name)
	defer f.Close()
	
		3 advantages
		+	Keeps Close call near Open
		+	if func had multiple return statements
			Close will happen before both of them
		+	Deferred func are run even if run-time panic occurs
	*/

	fmt.Println("===================")
	// Panic & recover

	// we can use like this when panic occurs -> heal(recover)
	// panic("PANIC")
	// str := recover()
	// fmt.Println(str)
	// .. but it's won't happend because panic immediately
	// stop excution of the function -> we should pair with defer
	defer func(){
		str := recover()
		fmt.Println(str)
	}()
	// panic("PANIC")
	/*
		SOME PROBLEMS:
	*/
	line()
	
	/*
		Task 1: sum is a function which takes a 
		slice of numbers and adds them together. 
		What would its function signature look like in Go?
	*/
	sum := func(x []int, a, b int) int{
		total := 0
		new_slice := x[a:b]
		for _, val := range new_slice{
			total += val
		}
		return total
	}
	x := []int{1,2,3,4}
	fmt.Println(sum(x, 0, 3))
	// better ways
	sum1 := func(numbers interface{}) float64{
		total := 0.0
		switch v := numbers.(type) {
		case []int:
			for _, val := range v{
				total += float64(val)
			}
		case []float64:
			for _, val := range v{
				total += val
			}
		}
		return total
	}
	line()
	fmt.Println(sum1(x))

	line()
	/*
		Write a function which takes an integer and halves it 
		and returns true if it was even or false if it was odd. 
		For example half(1) should return (0, false) and half(2) 
		should return (1, true).
	*/
	
}