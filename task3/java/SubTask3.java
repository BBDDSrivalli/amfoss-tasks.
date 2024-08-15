import java.util.Scanner;

public class SubTask3 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter the number of rows: ");
        int n = scanner.nextInt();

        System.out.println("Pattern 1");

        // Upper half of the diamond
        for (int i = 1; i <= (n + 1) / 2; i++) {
            System.out.print(" ".repeat((n + 1) / 2 - i));
            System.out.println("*".repeat((i * 2) - 1));
        }

        // Lower half of the diamond
        for (int i = (n + 1) / 2 + 1; i <= n; i++) {
            System.out.print(" ".repeat(i - (n + 1) / 2));
            System.out.println("*".repeat((n + 1 - i) * 2 - 1));
        }

        scanner.close();
    }
}
