const fs = require("fs");

const readableStream = fs.createReadStream(__filename);
readableStream.close();

console.log("First");

// I/O Queue
// Note: I/O polling done AFTER event loop checks I/O Queue
fs.readFile(__filename, () => {
    console.log("Eleventh")
    // Check Queue
    setImmediate(() => console.log("Thirteenth"));
    // nextTick Queue
    process.nextTick(() => console.log("Twelfth"));
});

// Close Queue
readableStream.on("close", () => console.log("Tenth"));

// Check Queue
setImmediate(() => console.log("Ninth"));

// Timer Queue
setTimeout(() => console.log("Fifth"), 0);
setTimeout(() => {
    console.log("Sixth");
    // Promise Queue
    Promise.resolve().then(() => console.log("Seventh"));
}, 0);
setTimeout(() => console.log("Eighth"), 0);

// Microtask Queues
// ----------------
// Promise queue
Promise.resolve().then(() => console.log("Fourth"));
// nextTick queue
process.nextTick(() => console.log("Third"));

console.log("Second");
