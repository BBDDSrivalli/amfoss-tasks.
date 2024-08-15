use std::fs::{File, OpenOptions};
use std::io::{self, prelude::*, BufReader, Write};

fn create_input_file() {
    let mut file = File::create("input.txt").expect("Error creating input.txt");
    file.write_all(b"This is a test string for Sub-Task 2.")
        .expect("Error writing to input.txt");
}

fn read_and_write() {
    let file = File::open("input.txt").expect("Error opening input.txt");
    let mut reader = BufReader::new(file);

    let mut content = String::new();
    reader.read_line(&mut content).expect("Error reading input.txt");

    println!("Content read from input.txt:");
    println!("{}", content);

    let mut outfile = File::create("output.txt").expect("Error creating output.txt");
    outfile
        .write_all(content.as_bytes())
        .expect("Error writing to output.txt");

    println!("Content successfully copied from input.txt to output.txt");

    let mut appendfile = OpenOptions::new()
        .append(true)
        .open("output.txt")
        .expect("Error opening output.txt for append");
    writeln!(appendfile, "\nAppending new content to output.txt.")
        .expect("Error appending to output.txt");

    let updatedfile = File::open("output.txt").expect("Error reading output.txt");
    let mut updatedreader = BufReader::new(updatedfile);

    println!("Updated content of output.txt:");
    let mut updatedcontent = String::new();
    updatedreader
        .read_to_string(&mut updatedcontent)
        .expect("Error reading updated output.txt");
    println!("{}", updatedcontent);
}

fn main() {
    create_input_file();
    read_and_write();
}
