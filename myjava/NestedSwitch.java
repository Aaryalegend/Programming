import java.util.Scanner;

public class NestedSwitch {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int empID = in.nextInt();
        String department = in.next();
        switch (empID) {
            case 1: 
                System.out.println("Aryan Babar");
                break;
            case 2:
                System.out.println("Arnva Bibor");
                break;
            case 3:
                switch (department) {
                    case "IT":
                        System.out.println("IT Dept");
                        break;
                    case "Management":
                        System.out.println("Mgmt Dept");
                        break;
                    default:
                        System.out.println("No Department");
                }
                break;
            default:
                System.out.println("Enter a valid Employee ID");
        }
    }
}
