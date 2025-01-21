package main
import("fmt")

func main(){
	var a = map[string]string{"brand":"Food",
	"model":"Mustang","year":"1964", "day":""}
	b := map[string]int{"Oslo":1, "Bergen":2,
		"Trondheim":3,"Stavanger":4}

	fmt.Printf("a\t%v\n", a)
	fmt.Printf("b\t%v\n", b)

	// we can use make to create map
	var c = make(map[string]string)
	c["he"] = "lo"
	c["xin"] = "Chào"
	c["hope"] = "uz"
	fmt.Println("==================")
	fmt.Printf("c\t%v\n",c)

	// delete(map_name, key)
	delete(c,"xin")
	fmt.Printf("c\t%v\n", c)

	// Check for specific elements in a map
	// val, ok :=map_name[key]
	val1, ok1 := a["brand"] // Checking for existing key and its value
	val2, ok2 := a["color"] // Checking for non-existing key and its value
	val3, ok3 := a["day"]   // Checking for existing key and its value
	_, ok4 := a["model"]    // Only checking for existing key and not its value

	fmt.Println(val1, ok1)
	fmt.Println(val2, ok2)
	fmt.Println(val3, ok3)
	fmt.Println(ok4)
}