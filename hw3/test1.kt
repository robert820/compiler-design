class test1
{
  val n = 10
  var sum: int
  fun main () {
    sum = 0
    
    for(index in 1 .. n){
      sum = sum + index
	}
    print ("The sum is ")
    println (sum)
  }
}
