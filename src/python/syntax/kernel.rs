use hal


struct Kernel:
	


impl Kernel:
	fn __init__(Kernel self):
		Stage1 stage1 = Stage1::new(PLATFORM_X86)
		stage1.boot()
		
		Hal hal = Hal::new(PLATFORM_X86,setup)
		hal.setup()

	fn Main()->void:
		loop:
			setup()
			draw()
			render()


		
