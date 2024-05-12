// JAVA 8 Features
// 1. Lambda Expressions
// 2. Functional Interfaces
// 3. Method Reference
// 4. Streams
// 5. Comparable and Comparator
// 6. Optional Class
// 7. Date/Time API

// Java program to demonstrate functional interface
@FunctionalInterface
interface Square {
    abstract int calculate(int x);
}

public class Java8Features {
    public static void main(String args[]) {
        // create anonymous inner class object
        new Thread(new Runnable() {
            @Override
            public void run() {
                System.out.println("Before Java 8 'New thread created'");
            }
        }).start();

        new Thread(() -> {
            System.out.println("Java 8 onwards 'New thread created'");
        }).start();

        // Create an anonymous class object that extends the Thread class.
        new Thread() {
            @Override
            public void run() {
                System.out.println("Hello from the anonymous class thread!");
            }
        }.start();

        // Create an anonymous class object that implements the Runnable interface.
        new Runnable() {
            @Override
            public void run() {
                System.out.println("Hello from the anonymous class runnable!");
            }
        }.run();
        // ------------------
        int a = 5;
        Square s = new Square() {
            @Override
            public int calculate(int a) {
                return a * a;
            }
        };
        System.out.println(s.calculate(a));
        // -------------------
        Square s1 = (int x) -> x * x;
        System.out.println(s1.calculate(4));
    }
}
