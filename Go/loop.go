package main
import("fmt")
func main(){
	for i:=0; i < 5; i++{
		fmt.Println(i)
	}
	// nested loops
	for i:=0; i < 4; i++{
		for j:= 0; j <4; j++{
			fmt.Println(j)
			break
		}
		break
	}

	// range key words
	fruit :=[3]string{"apple","orange","banana"}
	for idx, val := range fruit{
		fmt.Printf("%v\t%v\n", idx, val)
	}
	// we can use _ to hide 
	fmt.Println("==============")
	for _, val := range fruit{
		fmt.Printf("t%v\n",  val)
	}
	// or
	fmt.Println("===============")
	for idx, _ := range fruit{
		fmt.Printf("%v\t\n", idx)
	}
}