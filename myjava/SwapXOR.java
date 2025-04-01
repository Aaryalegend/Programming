import java.util.Scanner;

public class SwapXOR {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);    
        System.out.print("Enter two numbers: ");
        int a = in.nextInt();
        int b = in.nextInt();

        swap(a, b);
    }

    static void swap(int a, int b) {
        a ^= b;
        b ^= a;
        a ^= b;
        System.out.println(a + " " + b);
    }
}  
