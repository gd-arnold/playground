import { readFileSync } from "fs";

function getTotalCalories(input: string) {
    return input.split('\n')
                .reduce((sum, calories) => sum += Number(calories), 0);
}

const data = readFileSync('./input', 'utf8');

const calories = data.split("\n\n");

const part1 = calories.reduce((max, calories) => Math.max(max, getTotalCalories(calories)),
        getTotalCalories(calories[0]));

const part2 = calories
    .sort((a, b) => getTotalCalories(b) - getTotalCalories(a))
    .slice(0, 3)
    .reduce((sum, calories) => sum += getTotalCalories(calories), 0);

console.log(part1, part2);
