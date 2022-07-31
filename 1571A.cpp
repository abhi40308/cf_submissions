fun main() = repeat(readLine()!!.toInt()) {
  val s = readLine()!!
  val l = s.count({ it == '<' })
  val g = s.count({ it == '>' })
  if (l > 0 && g > 0) println("?")
  else if (l > 0) println("<");
  else if (g > 0) println(">");
  else println("=");
}