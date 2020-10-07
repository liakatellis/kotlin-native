import platform.darwin.*
import platform.Foundation.*

fun foo(vararg s: String) = NSAssertionHandler().handleFailureInFunction("zzz", "zzz", 0L, null, *s)
