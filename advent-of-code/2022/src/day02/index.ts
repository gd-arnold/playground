import { readFileSync } from "fs";

type shape = "A" | "B" | "C" | "X" | "Y" | "Z";

function convertToNumber(entry: shape) {
    switch (entry) {
        case "A":
        case "X":
            return 1;
        case "B":
        case "Y":
            return 2;
        case "C":
        case "Z":
            return 3;
    }
}

function roundOutcome(diff: number) {
    switch (diff) {
        case 0:
            return 3;
        case -1:
        case  2:
            return 6;
        default:
            return 0;
    }
}

function calculateScore(round: string) {
    const [opponent, response] = (round.split(" ") as [shape, shape])
        .map(entry => convertToNumber(entry));

    return roundOutcome(opponent - response) + response;
}

const data = readFileSync("./input", "utf8");

const part1 = data
    .trim()
    .split("\n")
    .reduce((sum, round) => sum += calculateScore(round), 0);

console.log(part1);
