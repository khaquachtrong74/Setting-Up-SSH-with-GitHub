package main
import("fmt")
func main(){
/*
	%v  Prints the value in default format
	%#v Prints the value in Go-syntax format

	%T 	Prints the type of the value
	%% 	Print the % sign
*/

	var i int = 15
	var txt = "Hello"

	fmt.Printf("%v\n", i)
	fmt.Printf("%#v\n", i)
	fmt.Printf("%v%%\n", i)
	fmt.Printf("%T\n", i)

	fmt.Printf("============")
	fmt.Printf("%#v\n", txt)
	fmt.Printf("%v\n", txt)
	fmt.Printf("%T\n", txt)

	// some formating of interger
	// %b base 2
	// %d base 10
	// %+d base 10 an always show sign
	// %o base 8
	// %O base 8, with leading 0o
	// %x base 16, lowercase
	// %X base 16, Upercase
	// %#x base 16 with leading 0x
	// %4d pad with spaces(width4, right justifiled)
	// %-4d pad with spaces(width 4, left justifiled)
	// %04d pad with zeros(width 4)

	fmt.Println("___________________")	
	

	fmt.Printf("%b\n", i)
	fmt.Printf("%d\n", i)
	fmt.Printf("%+d\n", i)
	fmt.Printf("%o\n", i)
	fmt.Printf("%O\n", i)
	fmt.Printf("%x\n", i)
	fmt.Printf("%X\n", i)
	fmt.Printf("%#X\n", i)
	fmt.Printf("%4d\n", i)
	fmt.Printf("%-4d\n", i)
	fmt.Printf("%04d\n", i)

	/*
		%s	Prints the value as plain string
		%q	Prints the value as a double-quoted string
		%8s	Prints the value as plain string (width 8, right justified)
		%-8s	Prints the values as plain String(with 8, left justified)
		%x 	Prints the value as hex dump of byte values
		% x Prints the value as hex dump with space
	*/
	fmt.Println("_________________________")
	fmt.Printf("%s\n", txt)
	fmt.Printf("%q\n", txt)
	fmt.Printf("%8s\n", txt)
	fmt.Printf("%-8s\n", txt)
	fmt.Printf("%x\n", txt)
	fmt.Printf("% x\n", txt)

	// with boolean we have %t
	fmt.Println("_______________________")
	fmt.Printf("%t\n",true)
	fmt.Printf("%t\n", false)

	/*	float
		%e		Scientific notation with 'e' as exponent
		%f		Decimal point, no Exponent
		%.2f	Default width, precision 2
		%6.2f	width 6, precision 2
		%g 		Exponent as needed, only necessary digits

	*/
	// i:float = 3.141
	var k =3.141
	fmt.Println("========================")
	fmt.Printf("%e\n", k)
	fmt.Printf("%f\n", k)
	fmt.Printf("%.2f\n", k)
	fmt.Printf("%6.2f\n", k)
	fmt.Printf("%g\n", k)
}