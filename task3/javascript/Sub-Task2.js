const fs = require('fs');

function createInputFile() {
    fs.writeFileSync('input.txt', 'This is a test string for Sub-Task 2.');
}

function readAndWrite() {
    const fileContent = fs.readFileSync('input.txt', 'utf8');
    console.log('Content read from input.txt:');
    console.log(fileContent);
    
    fs.writeFileSync('output.txt', fileContent);
    console.log('Content successfully copied from input.txt to output.txt');
    
    fs.appendFileSync('output.txt', '\nAppending new content to output.txt.');
    
    const updatedContent = fs.readFileSync('output.txt', 'utf8');
    console.log('Updated content of output.txt:');
    console.log(updatedContent);
}

createInputFile();
readAndWrite();
