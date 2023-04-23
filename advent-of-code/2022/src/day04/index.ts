import { readFileSync } from "fs";

const data = readFileSync("./input", "utf8");

const pairs = data.trim().split("\n");

const solution = pairs.reduce(([part1, part2], pair) => {
    const [a, b] = pair.split(",");
    const [la, ra] = a.split("-").map(Number);
    const [lb, rb] = b.split("-").map(Number);

    if ((la >= lb && ra <= rb) || (lb >= la && rb <= ra)) part1++;
    if ((ra >= lb && la <= rb) || (rb >=la && lb <= ra)) part2++;

    return [part1, part2];
}, [0, 0]);

console.log(solution[0], solution[1]);
