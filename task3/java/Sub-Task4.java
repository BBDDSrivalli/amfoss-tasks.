import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

public class DiamondPattern {
    public static void printPatternToFile(int n, FileWriter outputFile) throws IOException {
        for (int i = 1; i <= (n + 1) / 2; i++) {
            for (int j = 0; j < (n + 1) / 2 - i; j++) {
                outputFile.write(" ");
                System.out.print(" ");
            }
            for (int j = 0; j < (i * 2) - 1; j++) {
                outputFile.write("*");
                System.out.print("*");
            }
            outputFile.write("\n");
            System.out.println();
        }

        for (int i = (n + 1) / 2 + 1; i <= n; i++) {
            for (int j = 0; j < i - (n + 1) / 2; j++) {
                outputFile.write(" ");
                System.out.print(" ");
            }
            for (int j = 0; j < (n + 1 - i) * 2 - 1; j++) {
                outputFile.write("*");
                System.out.print("*");
            }
            outputFile.write("\n");
            System.out.println();
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter the number of rows: ");
        int n = scanner.nextInt();

        try (FileWriter outputFile = new FileWriter("output.txt")) {
            printPatternToFile(n, outputFile);
            System.out.println("Diamond pattern has been written to output.txt");
        } catch (IOException e) {
            System.out.println("Error opening output.txt");
        }
    }
}
