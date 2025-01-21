package main
import("fmt")
func main(){
	myslice1 := [4]int{1,2,3,4}
	fmt.Println(len(myslice1))
	fmt.Println(cap(myslice1))
	fmt.Println(myslice1)

	myslice2 := []string{"Go","Slices", "Are", "Powerful"}
	fmt.Println(len(myslice2))
	fmt.Println(cap(myslice2))
	fmt.Println(myslice2)

	myslice3 := myslice2[2:len(myslice2)]
	fmt.Println(myslice3)

	// use make 

	myslice4 := make([]int, 5, 12)
	fmt.Printf("myslice4: = %v\n", myslice4)
	fmt.Printf("Length = %d\n", len(myslice4))
	fmt.Printf("capacity = %d \n", cap(myslice4))

	// 
	fmt.Println("=======================")
	prices := []int{10,20,30}
	fmt.Printf("Cap : %d\n", cap(prices))
	fmt.Println(prices[0])
	fmt.Println(prices[2])
	//				plus cap, value...
	prices = append(prices, 2, 1)
	fmt.Printf("New cap: %d\n", cap(prices))
	fmt.Println(prices)
	fmt.Println("===============")
	n  := []int{4,2,5,1}
	np := []int{1,2, 5, 4}
	new_prices := append(n, np...)
	fmt.Printf("New_prices: %v\n", new_prices)
	fmt.Printf("New_length: %d\n", len(new_prices))
	fmt.Printf("New_cap:    %d\n", cap(new_prices))

	// change the length of a slice
	new_slice1 := [6]int{9,10,11,12,13,14}
	new_slice2 := new_slice1[1:5]
	fmt.Printf("new_slice2 := %v\n", new_slice2)
	fmt.Printf("Length := %d\n", len(new_slice2))
	fmt.Printf("Capacity := %d\n", cap(new_slice2))

	new_slice2 = new_slice1[1:3]// change length by resclicing the array
	fmt.Printf("new_slice2 = %v\n", new_slice2)
	fmt.Printf("Length := %d\n", len(new_slice2))
	fmt.Printf("Capacity := %d\n", cap(new_slice2))

	new_slice2 = append(new_slice2, 20, 21, 22, 23)
	fmt.Printf("new_slice2 = %v\n", new_slice2)
	fmt.Printf("Length := %d\n", len(new_slice2))
	fmt.Printf("Capacity := %d\n", cap(new_slice2))

	/*
		If array is large and we need only few elements,
		use copy function
		copy(dest, src)
	*/
	fmt.Println("++++++++++++++++++++++++")
	numbers := []int{1,2,3,4,5,6,7,8,9,10,11,12,13,14,15}
	// Original slice
	fmt.Printf("numbers = %v\n", numbers)
	fmt.Printf("length = %d\n", len(numbers))
	fmt.Printf("capacity = %d\n", cap(numbers))

	// Create copy with only needed numbers
	neededNumbers := numbers[:len(numbers)-10]
	numbersCopy := make([]int, len(neededNumbers))
	copy(numbersCopy, neededNumbers)

	fmt.Printf("numbersCopy = %v\n", numbersCopy)
	fmt.Printf("length = %d\n", len(numbersCopy))
	fmt.Printf("capacity = %d\n", cap(numbersCopy))



}