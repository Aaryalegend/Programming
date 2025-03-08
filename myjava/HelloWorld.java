package myjava;

import java.util.*;

public class HelloWorld {
    public static void main(String[] args) {
        // store 5 nos
        int[] numbers = new int[5];
        String[] names = new String[5];
        float[] marks = new float[5];

        Student[] student = new Student[5];
        System.out.println(Arrays.toString(student));
    }
}

class Student {
    int[] numbers = new int[5];
    String[] names = new String[5];
    float[] marks = new float[5];
}