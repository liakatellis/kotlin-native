package org.jetbrains.kotlin.backend.konan

enum class MemoryManager(val suffix: String) {
    LEGACY("Legacy"),
    EXPERIMENTAL("Experimental")
}