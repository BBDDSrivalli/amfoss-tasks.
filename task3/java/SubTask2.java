import java.io.*;

public class SubTask2 {
    public static void createInputFile() {
        try {
            FileWriter fileWriter = new FileWriter("input.txt");
            fileWriter.write("This is a test string for Sub-Task 2.");
            fileWriter.close();
            System.out.println("input.txt has been created.");
        } catch (IOException e) {
            System.out.println("An error occurred while creating input.txt.");
            e.printStackTrace();
        }
    }

    public static void readAndWrite() {
        try {
            // Read from input.txt
            BufferedReader reader = new BufferedReader(new FileReader("input.txt"));
            String content = reader.readLine();
            reader.close();
            System.out.println("Content read from input.txt: " + content);

            // Write to output.txt
            FileWriter fileWriter = new FileWriter("output.txt");
            fileWriter.write(content);
            fileWriter.close();
            System.out.println("Content successfully copied to output.txt.");

            // Append to output.txt
            FileWriter appendWriter = new FileWriter("output.txt", true);
            appendWriter.write("\nAppending new content to output.txt.");
            appendWriter.close();

            // Display updated content of output.txt
            BufferedReader updatedReader = new BufferedReader(new FileReader("output.txt"));
            String updatedContent;
            System.out.println("Updated content of output.txt:");
            while ((updatedContent = updatedReader.readLine()) != null) {
                System.out.println(updatedContent);
            }
            updatedReader.close();
        } catch (IOException e) {
            System.out.println("An error occurred.");
            e.printStackTrace();
        }
    }

    public static void main(String[] args) {
        createInputFile();
        readAndWrite();
    }
}

