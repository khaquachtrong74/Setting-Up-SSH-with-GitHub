package main
import("fmt")

func main(){
	// declared
	// var array_name = [length] data_type{values}
	var arr1 =[3]int{4,5,1}
	arr2 := [5]int{4,5,1,2,5}

	fmt.Println(arr1)
	fmt.Println(arr2)

	var arr3 = [...]int{5,1,2,5,123,5,43,-342}
	fmt.Println(arr3)

	fmt.Println("==========")
	var arr4 =[2]string{}
	var arr5 =[4]int{}
	arr6 :=[4]int{1:10, 3:120}
	fmt.Printf("%s\n%d\n%d\n", arr4, arr5 ,arr6)
}