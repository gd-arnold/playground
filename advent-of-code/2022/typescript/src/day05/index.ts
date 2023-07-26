import { readFileSync } from "fs";

const data = readFileSync("./input", "utf8");

const initializeStacks = ((rows: string[]) => {
    const stacks: string[][] = [];
    for (let i = 0; rows[i + 1] !== ""; i++) {
        const crates = rows[i].match(/.{1,4}/g)!.map(crate => crate.trim())

        for (let j = 0; j < crates.length; j++) {
            if (crates[j] !== '') {
                if (!stacks[j]) stacks[j] = [];
                stacks[j].unshift(crates[j][1]);
            }
        }
    }

    return stacks;
});

const rows = data.split("\n");
const stacks = initializeStacks(rows);

const part1 = JSON.parse(JSON.stringify(stacks));
const part2 = JSON.parse(JSON.stringify(stacks));

for (let i = Math.max(...stacks.map(stack => stack.length)) + 2; i < rows.length - 1; i++) {
    const [count, from, to] = rows[i].split(" ").filter((_, i) => i % 2 !== 0).map(Number);
    part1[to - 1].push(...(part1[from - 1].splice(part1[from - 1].length - count)).reverse());
    part2[to - 1].push(...(part2[from - 1].splice(part2[from - 1].length - count)));
}

console.log(part1.reduce((msg: string, stack: []) => msg += stack[stack.length - 1], ''));
console.log(part2.reduce((msg: string, stack: []) => msg += stack[stack.length - 1], ''));
