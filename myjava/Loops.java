import java.util.Scanner;

public class Loops {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int a = in.nextInt();
        int b = in.nextInt();
        int c = in.nextInt();

        int maxi = Math.max(a, Math.max(b,c));
        // int max = a; 
        // if (b> max) {
        //     max = b;
        // }
        // if (c > max) {
        //     max = c;
        // }
        System.out.println("The maximum number is: "+ maxi);
        // for (int num = 1; num < n; num++) {
        //     System.out.println(num);
        // }
    }
}
