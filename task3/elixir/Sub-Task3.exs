defmodule Diamond do
    def print_diamond(n) do
        IO.puts "Pattern 1"

        # Upper half of the diamond
        for a1 <- 1..div(n + 1, 2) do
            IO.write String.duplicate(" ", div(n + 1, 2) - a1)
            IO.write String.duplicate("*", a1 * 2 - 1)
            IO.puts ""
        end

        # Lower half of the diamond
        for a1 <- div(n + 1, 2) + 1..n do
            IO.write String.duplicate(" ", a1 - div(n + 1, 2))
            IO.write String.duplicate("*", (n + 1 - a1) * 2 - 1)
            IO.puts ""
        end
    end
end

Diamond.print_diamond(7)  # Example number of rows
