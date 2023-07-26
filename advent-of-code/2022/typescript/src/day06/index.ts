import { readFileSync } from "fs";

const data = readFileSync("./input", "utf8");

const findMarker = (data: string, count: number) => {
    for (let i = 0; i < data.length - count; i++) {
        if (new Set(data.slice(i, i + count)).size === count) return i + count;
    }
}

const part1 = findMarker(data, 4);
const part2 = findMarker(data, 14);

console.log(part1, part2);
