package main
import ("fmt")
const A string = "Quach Trong Kha" // typed constants
const PI = 3.14 // untyped constants

// or we have multi constant
const(
	B = 12
	C = "khas"
	D bool = true
)
func main(){
// const CONSTNAME type = value
	fmt.Println(A)
	fmt.Println(PI)
	fmt.Println(B)
	fmt.Println(C)
	fmt.Println(D)
}