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

Assembly language programs consist of three types of statements:

* Executable instructions or instructions

* Assembler directives or pseudo-ops

* Macros

The **executable instructions** or simply **instructions** tell the processor what to do. Each instruction
consists of an operation code (opcode). Each executable instruction generates one machine language instruction.

The **assembler directiver** or **pseudo-ops** tell the assembler about the various aspects of the assembly
process. These are non-executable and do not generate machine language instructions.

**Macros** are basically a text substitution mechanism.

### Syntax of Assembly Language Statements

Assembly language statements are entered one statement per line. Each statement follows the following format:

	[label] mnemonic [operands] [;comment]

The fields in the square brackets are optional. A basic instruction has two parts, the first one is the name
of the instruction (or the mnemonic), which is to be executed, and the second are the operands or the parameters
of the command.

Following are some examples of typical assembly language statements:

	INC COUNT				; Increment the memory variable COUNT
	
	MOV TOTAL, 48			; Transfer the value 48 in the memory
							; variable TOTAL
						
	ADD AH, BH				; Add the content of the BH register into the
							; AH register
	
	AND MASK1, 128			; Perform AND operation on the variable MASK1 
							; and 128
							
	ADD MARKS, 10			; Add 10 to the variable MARKS
	MOV AL, 10				; Transfer the value 10 to the AL register
	
### The Hello World Program in Assembly

The following assembly language code displays the string 'Hello World' on the screen:

	section .text
		global start				; Must be declared for linker (ld)
	
	_start:							; Tells linker entry point
		mov edx, len				; Message Length
		mov ecx, msg				; Message to write
		mov ebx, 1					; File descriptor (stdout)
		mov eax, 4					; System call number (sys_write)
		int 0x80					; Call Kernel
		
		mov eax, 1					; System call number (sys_exit)
		int 0x80					; Call Kernel
		
	section .data
	msg db 'Hello, World!', 0xa		; String to be printed
	len equ $ - msg					; Length of the string

When the above code is compiled and executed, it produces the following result:

	Hello, World!

### Compiling and Linking an Assembly Program in NASM

Make sure you have set the path of **nasm** and **Id** binaries in your PATH environment variable. Now, take 
the following steps for compiling and linking the above program:

* Type the above code using a text editor and save it as hello.asm

* Make sure that you are in the same directory where you saved hello.asm

* To assemble the program, type nasm -f elf hello.asm

* If there is any error, you will be prompted about that at this stage. otherwise, an object file of your
program named **hello.o** will be created

* To link the object file and create an executable file named hello, type **Id -m elf_i386 -s -o hello hello.o**

* Execute the program by typing ./hello

### Memory Segments 

A segmented memory model divides the system memory into groups of independent segments referenced by pointers
located in the segment registers. Each segment is used to contain a specific type of data. One segment is
used to contain instruction codes, another segment stores the data elements and the thir segments keeps
the program stack.

In the light of the above discussion, we can specify various memory segment as:

* **Data Segment**: It is represented by .data section and the .bss. THe .data section is used to declare
the memory region, where data elements are stored for the program. This section cannot be expanded after
the data elements are declared, and it remains static throughout the program.

the .bss section is also a static memory section that contains buffers for data to be declared later in the program.
This buffer memory is zero-filled.

* **Code segment** : Is represented by .text section. This defines the area in memory that stores the instruction
codes. This is also a fixed area.

* **Stack**: This segment contains data values passed to functions and procedures within the program. 

### Processor Registers

There are ten 32-bit and six 16-bit registers in IA-32 architecture. The registers are grouped into three
categories:

* General Registers

* Control Registers

* Segment Registers

The general registers are further divided into the following groups:

* Data Registers

* Pointer Registers

* Index Registers

### Data Registers

Four 32-bit data registers are used for arithmetic, logical, and other operations. These 32-bit registers
can be used in three ways:

* As complete 32-bit data registers: EAX, EBX, ECX, EDX

* Lower halves of the 32-bit registers can be used as four 16-bit data registers: AX, BX, CX and DX

* Lower and higher halves of the above-mentioned four 16-bit registers can be used as eight 8-bit data
registers: AH, AL, BH, BL, CH, CL, DH, and DL

Some of these data registers have specific used in artihmetical operations.

**AX is the primary accumulator**, it is used in input/output and most arithmetic instructions. For example,
in multiplication operations, one operand is stored in EAX or AX or AL register according to the size of the operand.

**BX is known as the base register**, as it could be used in indexed addressing.

**CX is known as the count register**, as the ECX, CX registers store the loop count in iterative operations.

**DX is known as the data register**. It is also used in input/output operations. It is also used with AX register
along with DX for multiplying and divide operations involving large values.

### Pointer Registers

The pointer registers are 32-bit EIP, ESP and EBP registers and corresponding 16-bit right portions IP, SP
and BP. There are three categories of pointer registers:

* **Instruction Pointer (IP)**: The 16-bit IP register stores the offset address of the next instruction to be 
executed. IP in association with the CS register (as CS:IP) gives the complete address of the current instruction
in the code segment

* **Stack Pointer (SP)**: The 16-bit SP register provides the offset value within the program stack. SP in association
with the SS register (SS:SP) refers to the current position of data or address within the program stack.

* **Base Pointer (BP)**: The 16-bit BP register mainly helps in referencing the parameter variables passed to a subroutine.
The address in SS register is combined with the offset in BP to get the location of the parameter. BP can
also be combined with DI and SI as base register for special addressing.

### Index Registers	

The 32-bit index registers, ESI and EDI, and their 16-bit rightmost portions. SI and DI, are used for indexed
addressing and sometimes used in addition and subtraction. There are two sets of index pointers:

* **Source Index (SI)**: It is used as source index for string operations

* **Destination Index (DI)**: It is used as detination index for string operations

### Control Register

The 32-bit instruction pointer register and the 32-bit flags register combined are considered as the control
registers.

Many instructions involve comparisons and mathematical calculations and change the status of the flags and
some other conditional instructions test the value of these status flags to take the control flow to other location

The common flag bits are:

* **Overflow Flag (OF)**: It indicates the overflow of a high-order bit (leftmost bit) of data after a signed
arithmetic operation

* **Direction Flag (DF)**: It determines left or right direction for moving or comparing string data. When the
DF value is 0, the string operations takes left-to-right direction and when the value is set to 1, the string
operation takes right-to-left direction

* **Interrupt Flag (IF)**: It determines wheter the external interrupts like keyboard entry are to be ignored
or processed. It disables the external interrupt when the value is - and enables interrupts when set to 1

* **Trap Flag (TF)**: It allows setting the operation of the processor in single-step mode. The DEBUG program
we used sets the trap flag, so we could step through the execution one instruction at a time

* **Sign Flag (SF)**: It shows the sign of the result og an arithmetic operation. This flag is set according
to the sign of a data item following the arithmetic operation. The sign is indicated by the high-order of leftmost
bit. A positive result clears the value of SF to 0 and negative results sets it to 1

* **Zero Flag (ZF)**: It indicates the result of an arithmetic or comparison operations. A nonzero result clears
the zero flag to 0, and a zero result sets it to 1

* **Auxiliary Carry Flag (AF)**: It contains the carry frorm bit 3 to bit 4 following an arithmetic operation;
used for specialized arithmetic. The AF is set when a 1-byte arithmetic operation causes a carry from bit 3 into bit 4

* **Parity Flag (PF)**: It indicates the total number of 1-bits in the result obtained from an arithmetic operation.
An even number of 1-bits clears the parity flag to 0 and an odd number of 1-bits sets the parity flag to 1

* **Carry Flag (CF)**: It contains the carry of 0 or 1 from high-order bit (leftmost) after an arithmetic operation.
It also stores the contents of last bit of a shift or rotate operation.









	
















