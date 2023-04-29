const crypto = require("crypto");
const promisify = require("./promisify.js");

const args = ["password", "salt", 100000, 512, "sha512"];
const syncFn = crypto.pbkdf2Sync.bind(crypto, ...args);
const asyncFn = promisify(crypto.pbkdf2).bind(crypto, ...args);

const timePassed = start => ((Date.now() - start) / 1000).toFixed(2);

// Sync
let start = Date.now();
for (let i = 0; i < 4; i++) syncFn();
console.log(timePassed(start));

// Async
process.env.UV_THREADPOOL_SIZE = 5; // Increase libuv's thread pool size
start = Date.now();
Promise.all([
    asyncFn(), asyncFn(), asyncFn(), asyncFn(), asyncFn()
]).then(() => console.log(timePassed(start)));
