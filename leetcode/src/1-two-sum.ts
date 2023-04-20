function twoSum(nums: number[], target: number): number[] | void {
    const hashMap = new Map();

    for (let i = 0; i < nums.length; i++) {
        const diff = target - nums[i];
        if (hashMap.has(diff)) return [hashMap.get(diff), i];
        hashMap.set(nums[i], i);
    }

}
