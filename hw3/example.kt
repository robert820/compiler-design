/*
 * Example with Functions
 */

class example {
  // constants
  val a = 5

  // variables
  var c : int

  // function declaration
  fun add (a: int, b: int) : int {
    return a+b
  }
  
  // main statements
  fun main() {
    c = add(a, 10)
	var d = false
    if (!d)
      print -c
    else
      print c
    println ("Hello World")
  }
}
