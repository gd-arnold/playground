import { readFileSync } from "fs";

const data = readFileSync("./input", "utf8");

const shapeToScore = new Map<string, number>([["X", 1], ["Y", 2], ["Z", 3]]);
const outcomeToScore = new Map<string, number>([
        ["AX", 3], ["AY", 6], ["AZ", 0],
        ["BX", 0], ["BY", 3], ["BZ", 6],
        ["CX", 6], ["CY", 0], ["CZ", 3]
]);
const instructionsToShape = new Map<string, string>([
        ["AX", "Z"], ["AY", "X"], ["AZ", "Y"],
        ["BX", "X"], ["BY", "Y"], ["BZ", "Z"],
        ["CX", "Y"], ["CY", "Z"], ["CZ", "X"]
]);

const games = data.trim().split("\n");

const part1 = games.reduce((sum, game) => sum +
    (shapeToScore.get(game[2]) as number) +
    (outcomeToScore.get(`${game[0]}${game[2]}`) as number), 0);

const part2 = games.reduce((sum, game) => {
    const res = instructionsToShape.get(`${game[0]}${game[2]}`) as string;

    return sum +
        (shapeToScore.get(res) as number) +
        (outcomeToScore.get(`${game[0]}${res}`) as number)
}, 0);

console.log(part1, part2);
