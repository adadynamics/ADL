use platform::x86_64::baremetal
use hal


struct Stage1:
	Platform platform
	Array setup	


impl Stage1:
	fn __init__(Stage1 self,Platform platform)->Stage1:
		self.platform = platform
		self.setup = Array::new()
		
		for u64 i = 0; i < platform_size; i++:
			self.setup.PushBack(fns)		
	
	fn x86_legacy_booting(Stage1 self)->void: __attribute__((asm))
		asm
		{
			org 0x7C00
			bits 16

			times 510 - ($ - $$) db 0
			db 0x55AA
		}

	fn x86_hl_entry_point()->void:
		pass


