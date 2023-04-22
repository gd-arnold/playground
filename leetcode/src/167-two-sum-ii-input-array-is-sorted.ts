// Time: O(n^2)
// Space: O(1)
function twoSum(numbers: number[], target: number): number[] {
    for (let i = 0; i < numbers.length - 1; i++) {
        for (let j = i + 1; j < numbers.length; j++) {
            if (numbers[i] + numbers[j] === target) return [i + 1, j + 1];
        }
    }

    return [];
};

console.log(twoSum([2,7,11,15], 9));
