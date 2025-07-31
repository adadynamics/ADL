

enum Plaform:
	PLATFORM_X86,
	PLATFORM_X86_64,
	PLATFORM_ARM

struct Hal:
	Platform platform
	Array setup


impl Hal:
	fn __init__(Hal self,Platform platform,Array setup)->Hal:
		self.platform = platform
		self.setup    = setup
	
	fn __setup__(Hal self)->bool:
		switch(self.platform):
			case PLATFORM_X86:
				setup.at(PLATFORM_X86)()
				break
			case PLATFORM_86_64:
				setup.at(PLATFORM_X86_64)()
				break
			case PLATFORM_ARM:
				setup.at(PLATFORM_ARM)()
				break
			default:
				return false

		return true




	
