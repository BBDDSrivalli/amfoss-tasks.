n = 7  # Example number of rows

puts "Pattern 1"

# Upper half of the diamond
(1..(n + 1) / 2).each do |a1|
    print " " * ((n + 1) / 2 - a1)
    print "*" * (a1 * 2 - 1)
    puts
end

# Lower half of the diamond
(((n + 1) / 2 + 1)..n).each do |a1|
    print " " * (a1 - (n + 1) / 2)
    print "*" * ((n + 1 - a1) * 2 - 1)
    puts
end
