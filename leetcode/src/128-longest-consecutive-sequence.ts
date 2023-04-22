// Time: O(n)
// Space: O(n)
// Requirements: must run in O(n) time
function longestConsecutive(nums: number[]): number {
    const set = new Set(nums);
    let longest = 0;

    for (const num of nums) {
        if (!set.has(num - 1)) {
            // start of a sequence
            let seq = 1;
            while (set.has(num + seq)) seq++;
            longest = Math.max(longest, seq);
        }
    }

    return longest;
};

console.log(longestConsecutive([100,4,200,1,3,2]));
