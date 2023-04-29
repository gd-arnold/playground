function addCps(a, b, callback) {
    setTimeout(() => callback(a + b), 500);
}

console.log("Before");
addCps(3, 4, (result) => console.log(result));
console.log("After");
