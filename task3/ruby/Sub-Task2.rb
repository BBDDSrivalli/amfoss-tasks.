def create_input_file
    File.open('input.txt', 'w') do |file|
        file.write("This is a test string for Sub-Task 2.")
    end
end

def read_and_write
    file_content = File.read('input.txt')
    puts "Content read from input.txt:"
    puts file_content
    
    File.open('output.txt', 'w') do |file|
        file.write(file_content)
    end
    puts "Content successfully copied from input.txt to output.txt"
    
    File.open('output.txt', 'a') do |file|
        file.write("\nAppending new content to output.txt.")
    end
    
    updated_content = File.read('output.txt')
    puts "Updated content of output.txt:"
    puts updated_content
end

create_input_file
read_and_write
