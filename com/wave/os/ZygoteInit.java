/*
 源码路径
 frameworks/base/core/java/com/android/internal/os/ZygoteInit.java
 */
package com.wave.os;
import java.awt.GridLayout;
import javax.swing.JButton;
import javax.swing.JFrame;
import java.lang.Thread;
import java.lang.Exception;
import java.lang.reflect.Method;

public class ZygoteInit{
    native String sayHello();
//     static{
//         System.loadLibrary("")
//     }
    ZygoteInit(){
		System.out.println("ZygoteInit");
    }
	public static void main(String[] args){
		System.out.println("ZygoteInit  main");

        ZygoteInit zygote = new ZygoteInit();
        try{
            System.out.println("->sayHello");
            System.out.println( zygote.sayHello() );

        }catch(Exception e){
            e.printStackTrace();
        }
        System.out.println("over !");
    }
}