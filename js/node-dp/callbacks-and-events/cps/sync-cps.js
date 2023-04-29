function addCps(a, b, callback) {
    callback(a + b);
}

console.log("Before");
addCps(3, 4, result => console.log(result));
console.log("After");
