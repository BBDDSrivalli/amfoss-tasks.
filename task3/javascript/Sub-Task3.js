const readline = require('readline');

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

rl.question('Enter the number of rows: ', (n) => {
    n = parseInt(n);
    console.log("Pattern 1");

    for (let i = 1; i <= (n + 1) / 2; i++) {
        console.log(" ".repeat((n + 1) / 2 - i) + "*".repeat((i * 2) - 1));
    }

    for (let i = (n + 1) / 2 + 1; i <= n; i++) {
        console.log(" ".repeat(i - (n + 1) / 2) + "*".repeat((n + 1 - i) * 2 - 1));
    }

    rl.close();
});

