package main

import(
	"fmt"
	"student-manager/student"
)


func main(){
	sv1 := student.NewStudent(1, "Nguyen van a", 20, 1.4)
	sv2 := student.NewStudent(2, "ba va", 10, 2.4)
	sv3 := student.NewStudent(5, "Detbeed", 21, 4.6)
	fmt.Println("Danh sach")
	sv1.PrintInfo()
	sv2.PrintInfo()
	sv3.PrintInfo()
}
