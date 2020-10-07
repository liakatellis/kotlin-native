import platform.darwin.*
import platform.Foundation.*

fun foo(vararg s: String) = NSLog("zzz", *s)
