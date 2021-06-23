# Golang Basics
###### notes from Golang documentation (mainly)

### Get Started with Go

#### Write some code

Get started with Hello, World.

  1. Open a command prompt and cd to your home directory
     On Linux or mac: 
	cd

  2. Create a hello directoru for your first Go source code.

     For example, use the following commands:
	mkdir hello
	cd hello

  3. Enable dependency tracking for your code.

     When your code imports packages contained in other modules, you manage those dependencies
     through your code's own module. That module is defined by a go.mod file that tracks the modules
     that provide those packages. That go.mod file stays with your code, including in your source
     code repository.

     To enable depency tracking for your code by creating a go.mod file, run the *go mod init* command,
     giving it the name of the module your code will be in. The name is the module's path. In most
     cases, this will be the repository location where your source code will be kept, such as 
     *github.com/mymodule*. If you plan to publish your module for others to use, the module path must
     be a location from which Go tools can download your module.

     For the purposes of this tutorial, just use example.com/hello.

	$ go mod init example.com/hello
	go: creating new go.mod: module example.com/hello

  4. In your text editor, create a file hello.go in which to write your code.

  5. Paste the following code into your hello.go file and save the file.

	package main

	import "fmt"

	func main(){
		fmt.Println("Hello, World!")
	}

     This is your Go code. In this code you:

          * Declare a main package (a package is a way to group functions, and it's made up of all 
            the files in the same directory).

          * Import the popular fmt package, which contains functions for fomatting text, including
            printing to the console. This package is one of the **standard library** packages you
            got when you installed Go.

          * Implement a main function to print a message to the console. A *main* function executes
            by default when you run the main package.

  6. Run your codoe to see the greeting.

	$ go run .
	Hello, World!

### Call code in an external package

When you need your code to do something that might have been implemented by someone else, you can look
for a package that has functions you can use in your code.

  1. Make your printed message a little more interesting with a function from an external module.
     

