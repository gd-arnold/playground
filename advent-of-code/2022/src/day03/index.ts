import { readFileSync } from "fs";

const data = readFileSync("./input", "utf8");

const itemToNum = (item: string) => {
   const code = item.charCodeAt(0);

   if (code >= 97 && code <= 122) return code - 96;
   return code - 38;
}

const sacks = data.trim().split("\n");

const part1 = sacks.reduce((sum, sack) => {
    const firstComp = sack.slice(0, sack.length / 2);
    const secondComp = sack.slice(sack.length / 2);

    for (const item of firstComp) {
        if (secondComp.includes(item)) return sum + itemToNum(item);
    }
    return 0;
}, 0);

// PART 2
let part2 = 0;

for (let i = 0; i < sacks.length; i += 3) {
    for (const item of sacks[i]) {
        if (sacks[i + 1].includes(item) && sacks[i + 2].includes(item)) {
            part2 += itemToNum(item);
            break;
        }
    }
}

console.log(part1, part2);
