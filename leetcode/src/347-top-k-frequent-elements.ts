// Time: O(n log n)
// Memory: O(n)
function topKFrequent(nums: number[], k: number): number[] {
    const frequencyMap = new Map();

    for (const num of nums) {
        frequencyMap.set(num, (frequencyMap.get(num) || 0) + 1);
    }

    return [...frequencyMap.entries()]
        .sort((a, b) => b[1] - a[1])
        .slice(0, k)
        .map(a => a[0]);
}

console.log(topKFrequent([1,1,1,2,2,3,5,5,5], 3));
