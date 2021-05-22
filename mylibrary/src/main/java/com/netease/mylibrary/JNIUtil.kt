package com.netease.mylibrary

/**
 * Author: snail
 * Data: 5/20/21.
 * Des:
 * version:
 */
class JNIUtil {

    init {
        System.loadLibrary("test1")
    }
    external fun md5Digest(input:String):String
}