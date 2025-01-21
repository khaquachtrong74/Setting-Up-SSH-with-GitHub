package main
import("fmt")

func helloWorld(){
	fmt.Println("Hello kha!")
}
func familyName(fname string){
	fmt.Printf("Hello %s", fname)
}

// return func
func caculate(x int, y int) int{
	return x + y
}
// or
func caculateOne(x int, y int) (res int){
	res =  x - y
	return
}

// multiple return values
func myFunc(x int, s string)(res int, name string){
	res = x*2
	name += s+" KHA NE"
	return
}

// recursion
func testCoutn(x int) int{
	if x == 11{
		return 0
	}
	fmt.Println(x)
	return testCoutn(x+1)
}

func factorial_recursion(x float64) (y float64){
	if x > 0 {
		y = x * factorial_recursion(x-1)
	}else{
		y = 1
	}
	return 
}

func makeEvenGenerator() func() uint{
	// means this function will return func and uint
	i := uint(0)
	return func() (ret uint){
		ret = i
		i += 2
		return 
	}
}
// variadic functions
func add(args ...int)int{
	total := 0
	for _, v := range args{
		total += v
	}
	return total
}
func main(){
	helloWorld()
	familyName("del")
	fmt.Printf("my caculate: %d\n", caculate(2, 5))
	fmt.Println(caculateOne(4,3))
	fmt.Println(myFunc(2, "hoho"))
	// if we want to omit the first val return

	_, k := myFunc(2, "kasd")
	fmt.Println(k)
	fmt.Println("========================")
	testCoutn(1)
	fmt.Println(factorial_recursion(3))
	// closure
	add := func(x, y int) int {
		return x + y
	}
	fmt.Println("Closure: ",add(2, 5))
	fmt.Println("Closure: ",add(7, 12))
	x := 0
	increment := func()int{
		x++
		return x
	}
	fmt.Println("=================")
	/*
		x like global val in func main so func increment 
		use x can be modified
	*/
	fmt.Println(increment())
	fmt.Println(increment())
	fmt.Println("==================")
	nextEven := makeEvenGenerator()
	/*
		makeEvenGenerator will returns a func with generates even numbs
		Each time it's called it adds 2 to the local i variable which
		unlike normal local variables - persists between calls.
	
		Closure cho phép
		+ Tạo hàm sinh số (hàm có trí nhớ)
		+ Giữ trạng thái giữa các lần gọi
		+ Đóng gói trạng thái của biến
	*/
	fmt.Println(nextEven())// 0
	fmt.Println(nextEven())// 2
	fmt.Println(nextEven())// 4
}