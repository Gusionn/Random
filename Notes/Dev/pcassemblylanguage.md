# PC Assembly Language
###### by Paul A. Carter 
###### November 16 2019

## Introduction

### 1.1 Numeric Systems

Memory in a computer contains numbers. Computer memory stores numbers in binary (base 2).

#### 1.1.1 Decimal

Base 10 numbers are composed of 10 possible digits (0-9). Each digit of a number has a power of 10 associated
with it based on its position in the number. For example:

234 = 2 x 10² + 3 x 10¹ + 4 x 10⁰

#### 1.1.2 Binary

Base 2 numbers are composed of 2 possible digits (0 and 1). Each digit of a number has a power of 2 associated
with it based on its position. For example:

11001 = 1 x 2⁴ + 1 x 2³ + 0 x 2² + 0 x 2¹
      = 16 + 8 + 1
      = 25
      
This shows how binary numbers may be converted to decimal.

If we consider the following decimal division:

1234 / 10 = 123 *r* 4

We can see that this division strips off the rightmost decumal digit of the number and shifts the other decimal
digits one position to the right. Dividing by two performs a similar operation, but for binary digits:

1101 / 101 = 110 r 1

This fact can be used to convert a decimal number to its equivalent binary representation. This method finds
the rightmost digit first, this digit is called *least significant bit (lsb)*. The leftmost digit is called
the *most significant bit (msb)*. The basic unit of memory consistes of 8 bits and is called a *byte*.

#### 1.1.3 Hexadecimal

Hexadecimal numbers use base 16. The Hexadecimal (or *hex* for short) can be used as a shorthand for binary
numbers. Hex has 16 possible digits. This creates a problem since there are no symbols to use for these extra
digits after 9. By convention, letters are used for these extra digits. The 16 hex digits are 0-9 then A, B, C,
D, E, and F. the digit A is equivalent to 10 in decimal, B to 11 etc. For example:

2BD = 2 x 16² + 11 x 16¹ + 13 x 16⁰
    = 512 + 176 + 13
    = 701

To convert from decimal to hex, use the same idea that was used for binary conversion, except divide by 16.
The reason that hex is useful is that there is a very simple way to convert between hex and binary. Binary
numbers get large and cumbersome quickly. Hex provides a much more compact way to represent binary.
To convert a hex to binary, simply convert each hex digit to a 4-bit binary number. For example:

24D = 0010 0100 1101

| word        | 2 bytes |
| double word | 4 bytes |
| quad word   | 8 bytes |
| paragraph   | 16 bytes| 
###### Units of memory

Note that leading zeros of the 4-bits are important. If a leading zero for the middle digit 24D is not used
the result is wrong. Converting binary to hex is just as easy. One does the process in reverse. Convert each
4-bit segments of the binary to hex. Start from the right end, not the left end of the binary number. This
ensures that the process uses the correct 4-bit segments. Example:

110 0000 0101 1010 0111 1110
6     0    5    A    7    E

A 4-bit number is called a nibble. Thus each hex digit corresponds to a nibble. Two nibbles make a byte and so
a byte can be represented by a 2-digit hex number. A byte's value ranges from 0 to 11111111 in binary, 0 to FF
in hex and 0 to 255 in decimal.

### 1.2 Computer Organization

#### 1.2.1 Memory

The basic unit of memory is a byte. A computer with 32 megabytes of memory can hold roughly 32 million bytes
of information. Each byte in memory is labeled by a unique number known as its address

   0    1    2    3   4     5    6    7     ; Address
| 2A | 45 | B8 | 20 | 8F | CD | 12 | 2E |   ; Memory

Often memory is used in larger chunks than single bytes. On the PC architecture, names have been given to these
larger sections of memory. All data in memory is numeric. Characters are stored by using *character code* that maps
numbers to characters. One of the most common character codes is known as ASCII (American Standard Code for Information
Interchang). A new, more complete code that is supplating ASCII uses is Unicode. One key difference between the two
codes is that ASCII uses one byte to encode a character, but Unicode uses multiple bytes. There are several
different forms of Unicode. On x86 C/C++ compilers, Unicode is represented in code using the wchar_t type and
the UTF-16 encoding which uses 16 bits (or a word) per character. For example, ASCII maps the byte 41(hex) to the character
capital A; UTF-16 maps it to the word 0041. Since ASCII uses a byte, it is limited to 256 different characters. Unicode
extends the ASCII values and allows many more characters to be represented.

#### 1.2.2 The CPU

The Central Processing Unit (CPU) is the physical device that performs instructions. The instructions that
CPUs perform are generally very simple. Instructions may require the data they act on to be in special storage
locations in the CPU itself called *registers*. The CPU can access data in registers much faster than data in
memory. However, the number of registers in a CPU is limited, so the programmer must take care to keep only
currently used data in registers

The instructions a type of CPU execute make up the CPU's machine language. Machine programs have a much more basic
structure than higher-level languages. Machine language instructions are encoded as raw numbers, not in friendly
A CPU must be able to decode an instruction's purpose very quickly to run efficiently. Machine language is designed
with this goal in mind, not to be easily deciphered by humans. Programs written in other languages must be 
converted to the nativa machine language of the CPU to run on the computer. A compiler is a program that translates
programs written in programming languages into the machine language of a particular coputer architecture. In general,
every type of CPU has its own unique machine language. This is one reason why programs written for a Mac can not run
on an IBM-type PC.

Computers use a *clocK* to synchronize the execution of the instructions. The clock pulses at a fixed frequency
(known as the *clock speed*). When you buy a 1.6 GHz computer, 1.6 GHz is the frequency of this clock. The clock
does not keep track of minutes and seconds. It simply beats at a constant rate. The electronics of the CPU
uses beats to perform their operations correctly, like how the beats of a metronome help one play music at the correct
rythm. The number of beats (or as they are usually called cycles) an instruction requires depends on the CPU
generation and model. The number of cycles depends on the instructions before it and other factors as well.

#### 1.2.3 The 80x86 family of CPUs

