// Context:
// Array is sorted
// Must use only constant extra space

// Time: O(n)
// Space: O(1)
function twoSumOpt(numbers: number[], target: number): number[] {
    let l = 0;
    let r = numbers.length - 1;

    while (l < r) {
        const sum = numbers[l] + numbers[r];

        if (sum === target) return [l + 1, r + 1];

        if (sum > target) r--;
        else l++;
    }

    return [l, r];
}

console.log(twoSumOpt([2,7,11,15], 9));

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
