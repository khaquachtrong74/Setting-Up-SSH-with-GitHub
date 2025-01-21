package main
import("fmt")
import "errors"

var ErrDivideByZero = errors.New("divide by zero")
/*
	Error handling in Go is a little different than other mainstream
	programming langugages. it's don't contain stack traces, nor
	do they support conventional try/catch methods to handle them

	Go are just values returned by functions, and they can be treated
	in much the same way as any other datatype - leading to a 
	surprisingly lightweight and simple design.

	type error interface{
		Error() string
	}

*/
type DivisionError struct{
	IntA int
	IntB int
	Msg  string
}
func (e *DivisionError) Error() string{
	return e.Msg
}
func DoSomething() error{
	return errors.New("Something didn't work")
}

/*	
	fmt package can be used to add dynamic data to the error
	such as an int, string, or other error
*/
func Divide(a, b int) (int, error){
	if b == 0 {
		// return 0, fmt.Errorf("can't divide '%d' by zero", a)
		// improve
		return 0, &DivisionError{
			Msg: fmt.Sprintf("Cannot divide '%d' by zero ", a),
			IntA: a, IntB: b,
		}
	}
	return a/b , nil
}
/*
	fmt.Errorf will prove extremeply useful with %w format
*/


func main(){
	fmt.Println(Divide(2,0))

	a, b := 10, 0
	result, err := Divide(a, b)
	if err != nil{
		switch {
		case errors.Is(err, ErrDivideByZero):
			fmt.Println("Divide by zero errror")
		default:
			fmt.Printf("unexpected division error :%s\n", err)
			
		}
		return
	}
	fmt.Printf("%d/%d = %d\n", a, b, result)
}

/*
	another important technique in Go is defining expected Errors
	so they can be checked for explicitly in other parts of the code.
	Useful when we need to execute a different branch of code 
*/

/*
	Building on the Divide func
	we can improve the error signaling by pre-defining "sentinel"
	go to line 5
	*/


