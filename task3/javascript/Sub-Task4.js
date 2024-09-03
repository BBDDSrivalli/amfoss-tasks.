const fs = require('fs');

function printPatternToFile(n) {
    let outputFile = fs.createWriteStream('output.txt');

    for (let i = 1; i <= Math.ceil((n + 1) / 2); i++) {
        let line = ' '.repeat(Math.ceil((n + 1) / 2) - i) + '*'.repeat((i * 2) - 1);
        outputFile.write(line + '\n');
        console.log(line);
    }

    for (let i = Math.ceil((n + 1) / 2) + 1; i <= n; i++) {
        let line = ' '.repeat(i - Math.ceil((n + 1) / 2)) + '*'.repeat((n + 1 - i) * 2 - 1);
        outputFile.write(line + '\n');
        console.log(line);
    }

    outputFile.end();
    console.log("Diamond pattern has been written to output.txt");
}

const readline = require('readline').createInterface({
    input: process.stdin,
    output: process.stdout
});

readline.question('Enter the number of rows: ', n => {
    printPatternToFile(parseInt(n, 10));
    readline.close();
});
