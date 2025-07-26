use std::io


struct Calc:
	

impl Calc:
	fn __init__(Calc self)->Calc:
		pass

	fn Add(Calc self,f64 x,f64 y)->f64:
		return x + y

	fn Subtract(Calc self,f64 x,f64 y)->f64:
		return x - y

	fn Multiply(Calc self,f64 x,f64 y)->f64:
		return x * y

	fn Divide(Calc self,f64 x,f64 y)->f64:
		return x / y

	fn __fini__(Calc self)->void:
		pass


fn main()->u64:
	Calc calc = Calc::new()
	f64 sum = calc.Add(78,100)
	print(sum)

	while not true:
		
