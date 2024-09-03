def print_pattern_to_file(n)
  File.open("output.txt", "w") do |output_file|
    (1..(n + 1) / 2).each do |i|
      line = " " * ((n + 1) / 2 - i) + "*" * (i * 2 - 1)
      output_file.puts line
      puts line
    end

    ((n + 1) / 2 + 1..n).each do |i|
      line = " " * (i - (n + 1) / 2) + "*" * ((n + 1 - i) * 2 - 1)
      output_file.puts line
      puts line
    end
  end

  puts "Diamond pattern has been written to output.txt"
end

print "Enter the number of rows: "
n = gets.to_i
print_pattern_to_file(n)
