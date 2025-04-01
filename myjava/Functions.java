import java.util.Scanner;

public class Functions {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        System.out.print("Name-> ");
        String name = in.nextLine();
        
        System.out.println(greet(name));
    }

    static String greet(String name) {
        return "Hello, " + name;
    }
}
