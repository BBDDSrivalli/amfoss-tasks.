use std::fs::File;
use std::io::{self, Write};

fn print_pattern_to_file(n: i32, output_file: &mut File) {
    for i in 1..=(n + 1) / 2 {
        for _ in 0..(n + 1) / 2 - i {
            write!(output_file, " ").unwrap();
            print!(" ");
        }
        for _ in 0..(i * 2) - 1 {
            write!(output_file, "*").unwrap();
            print!("*");
        }
        writeln!(output_file).unwrap();
        println!();
        io::stdout().flush().unwrap();
    }

    for i in (n + 1) / 2 + 1..=n {
        for _ in 0..i - (n + 1) / 2 {
            write!(output_file, " ").unwrap();
            print!(" ");
        }
        for _ in 0..(n + 1 - i) * 2 - 1 {
            write!(output_file, "*").unwrap();
            print!("*");
        }
        writeln!(output_file).unwrap();
        println!();
        io::stdout().flush().unwrap();
    }
}

fn main() {
    let mut n = String::new();
    println!("Enter the number of rows: ");
    io::stdin().read_line(&mut n).unwrap();
    let n: i32 = n.trim().parse().unwrap();

    let mut output_file = File::create("output.txt").expect("Error opening output.txt");

    print_pattern_to_file(n, &mut output_file);

    println!("Diamond pattern has been written to output.txt");
}
