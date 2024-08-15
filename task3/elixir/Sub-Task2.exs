defmodule FileOps do
    def create_input_file do
        File.write!("input.txt", "This is a test string for Sub-Task 2.")
    end

    def read_and_write do
        file_content = File.read!("input.txt")
        IO.puts "Content read from input.txt:"
        IO.puts file_content

        File.write!("output.txt", file_content)
        IO.puts "Content successfully copied from input.txt to output.txt"

        File.write!("output.txt", "\nAppending new content to output.txt.", [:append])

        updated_content = File.read!("output.txt")
        IO.puts "Updated content of output.txt:"
        IO.puts updated_content
    end
end

FileOps.create_input_file()
FileOps.read_and_write()
