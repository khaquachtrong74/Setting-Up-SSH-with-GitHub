package main
import("fmt")

/*
	type struct_name struct
*/
type Person struct{
	name string
	age int
	money int
}
func main(){
	var pers1 Person
	var pers2 Person

	pers1.name = "kha"
	pers1.age = 19
	pers1.money = 10

	pers2.name = "Kha"
	pers2.age = 24
	pers2.money = 100
	printPerson(pers1)
	printPerson(pers2)
	// print all
}

func printPerson(pers Person) {
  fmt.Println("Name: ", pers.name)
  fmt.Println("Age: ", pers.age)
  fmt.Println("Salary: ", pers.money)
}