# Assembly, zero to hero?

### Addressing Data in Memory

The process through which the processor controls the execution of instructions is referred as the
**fetch-decode-execute cycle** or the **execution cycle**. It consists of three continous steps:

* Fetching the instruction from memory
* Decoding or identifying the instruction
* Executing the instruction

The processor may access one or more bytes of memory at a time. Let us consider a hexadecimal number 0725H.
This number will require two bytes of memory. The high-order byte or most significant byte is 07 and the low-order
byte is 25.

The processor stores data in reverse-byte sequence, i.e., a low-order byte is stored in a low memory address
and a high-order byte in high memory address. So if the processor brings the value 0725H from register to memory,
it will transfer 25 first to the lower memory address and 07 to the next memory address.

When the processor gets the numeric data from memory to register, it again reverses the bytes. There are two
kinds of memory addresses:

* Absolute address - a direct reference of specific location
* Segment address (or offset) - starting address of a memory segmet with the offset value

### A Program

An assembly program can be divided into three sections:

* The **data** section
* The **bss** section
* The **text** section

#### The *data* Section

The **data** section is used for declaring initialized data or constants. This data does not change at runtime.
You can declare various constant values, file names, or buffer size, etc.

The syntax for declaring data section is:

	section.data

#### The *bss* Section

The **bss** section is used for declaring variables. The syntax for declaring bss section is:

	section.bss

#### The *text* Section

The **text** section is used for keeping the actual code. This section must begin with the declaration
**global_start**, which tells the kernel where the program execution begins.

The syntax for declaring text section is:

	section.text
		global_start
	_start:
	
#### Comments

Assembly language comments begins with a semicolon (;). It may contain any printable character including blank.
It can appear on a line by itself like:

	; This program displays a message on screen

or, on the same line along with an instruction like:

	add eax, ebx     ; adds eax to ebx

### Assembly Language Statements











