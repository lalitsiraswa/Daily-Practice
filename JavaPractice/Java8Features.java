// JAVA 8 Features
// 1. Lambda Expressions
// 2. Functional Interfaces
// 3. Method Reference
// 4. Streams
// 5. Comparable and Comparator
// 6. Optional Class
// 7. Date/Time API

// Java program to demonstrate functional interface

import java.util.ArrayList;
import java.util.List;
import java.util.function.Consumer;

@FunctionalInterface
interface Square {
    abstract int calculate(int x);
}

// public class Java8Features {
// public static void main(String args[]) {
// // create anonymous inner class object
// new Thread(new Runnable() {
// @Override
// public void run() {
// System.out.println("Before Java 8 'New thread created'");
// }
// }).start();

// new Thread(() -> {
// System.out.println("Java 8 onwards 'New thread created'");
// }).start();

// // Create an anonymous class object that extends the Thread class.
// new Thread() {
// @Override
// public void run() {
// System.out.println("Hello from the anonymous class thread!");
// }
// }.start();

// // Create an anonymous class object that implements the Runnable interface.
// new Runnable() {
// @Override
// public void run() {
// System.out.println("Hello from the anonymous class runnable!");
// }
// }.run();
// // ------------------
// int a = 5;
// Square s = new Square() {
// @Override
// public int calculate(int a) {
// return a * a;
// }
// };
// System.out.println(s.calculate(a));
// // -------------------
// Square s1 = (int x) -> x * x;
// System.out.println(s1.calculate(4));
// }
// }

// -----------------------------------------------------------------------
// Java program to demonstrate lambda expressions
// to implement a user defined functional interface.
@FunctionalInterface
interface FuncInterface {
    // An abstruct function
    void abstractFun(int x);

    // a non-abstract (or default) function
    default void normalFun() {
        System.out.println("Hello World!");
    }
}

class CustomPrintConsumer<T> implements Consumer<T> {
    @Override
    public void accept(T t) {
        System.out.println(t);
    }
}

class PrintEvenNumber<Integer> implements Consumer<Integer> {
    @Override
    public void accept(Integer t) {
        if ((int) t % 2 == 0) {
            System.out.println(t);
        }
    }
}

public class Java8Features {
    interface FuncInter1 {
        int operation(int a, int b);
    }

    interface FuncInter2 {
        void sayMessage(String message);
    }

    private int operate(int a, int b, FuncInter1 fobj) {
        return fobj.operation(a, b);
    }

    public static void main(String args[]) {
        FuncInterface fObj = new FuncInterface() {
            @Override
            public void abstractFun(int x) {
                System.out.println(2 * x);
            }
        };
        fObj.abstractFun(5);
        // ------- Lambda expression --------
        FuncInterface fObj2 = (int x) -> System.out.println(2 * x);
        fObj2.abstractFun(4);
        // --------------
        System.out.println("----------------------------");
        List<Integer> list = new ArrayList<Integer>();
        list.add(1);
        list.add(2);
        list.add(3);
        list.add(4);
        list.add(5);
        // Using lambda expression to print all elements of list
        list.forEach((Integer n) -> System.out.println(n));
        System.out.println("-----------------------------");
        list.forEach(new CustomPrintConsumer<Integer>());
        System.out.println("-----------------------------");
        // Using lambda expression to print even elements of list
        list.forEach((x) -> {
            if (x % 2 == 0) {
                System.out.println(x);
            }
        });
        System.out.println("--------------------------------");
        list.forEach(new PrintEvenNumber<Integer>());
        System.out.println("---------------------------------------------------");
        FuncInter1 add = (int x, int y) -> x + y;
        FuncInter1 multiply = (int x, int y) -> x * y;
        Java8Features obj = new Java8Features();
        System.out.println(obj.operate(6, 3, add));
        System.out.println(obj.operate(6, 3, multiply));
        FuncInter2 messageObj = message -> System.out.println("Hello " + message);
        messageObj.sayMessage("Geek");
    }
}
