defmodule Diamond do
  def print_pattern_to_file(n) do
    {:ok, file} = File.open("output.txt", [:write])

    for i <- 1..div(n + 1, 2) do
      IO.write(file, String.duplicate(" ", div(n + 1, 2) - i))
      IO.write(file, String.duplicate("*", i * 2 - 1))
      IO.write(file, "\n")

      IO.write(String.duplicate(" ", div(n + 1, 2) - i))
      IO.puts(String.duplicate("*", i * 2 - 1))
    end

    for i <- div(n + 1, 2) + 1..n do
      IO.write(file, String.duplicate(" ", i - div(n + 1, 2)))
      IO.write(file, String.duplicate("*", (n + 1 - i) * 2 - 1))
      IO.write(file, "\n")

      IO.write(String.duplicate(" ", i - div(n + 1, 2)))
      IO.puts(String.duplicate("*", (n + 1 - i) * 2 - 1))
    end

    File.close(file)
    IO.puts("Diamond pattern has been written to output.txt")
  end
end

IO.puts("Enter the number of rows:")
n = String.to_integer(IO.gets("") |> String.trim())
Diamond.print_pattern_to_file(n)
