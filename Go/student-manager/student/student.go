package student

import "fmt"

type Student struct{
	ID	int
	Name	string	
	Age 	int
	Score	float64
}

func (c Student) PrintInfo(){
	fmt.Printf("ID: %d, Name: %s, Age: %d, Score: %.2f\n", c.ID, c.Name, c.Age, c.Score)
}

// Hàm tạo sinh viên mới
func NewStudent(id int, name string, age int, score float64) Student {
	return Student{
		ID: id,
		Name: name,
		Age: age,
		Score: score,
	}
}
func (s Student) IsScholarship() bool{
	return s.Score >= 8.0
}
