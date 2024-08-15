fn print_pattern(n: usize) {
    println!("Pattern 1");

    for i in 1..=((n + 1) / 2) {
        let spaces = (n + 1) / 2 - i;
        let stars = (i * 2) - 1;
        println!("{: >width$}{}", "", "*".repeat(stars), width = spaces);
    }

    for i in ((n + 1) / 2 + 1)..=n {
        let spaces = i - (n + 1) / 2;
        let stars = (n + 1 - i) * 2 - 1;
        println!("{: >width$}{}", "", "*".repeat(stars), width = spaces);
    }
}

fn main() {
    let mut input = String::new();
    println!("Enter the number of rows:");
    std::io::stdin().read_line(&mut input).unwrap();
    let n: usize = input.trim().parse().unwrap();

    print_pattern(n);
}
