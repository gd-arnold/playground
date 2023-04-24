function search(nums: number[], target: number): number {
    const isTargetInLeft = target > nums[nums.length - 1];

    let start = 0;
    let end = nums.length - 1;

    while (start <= end) {
        const mid = Math.floor((start + end) / 2);

        if (nums[mid] === target) return mid;

        const isGuessInLeft = nums[mid] > nums[nums.length - 1];

        if (isTargetInLeft && isGuessInLeft) {
            if (nums[mid] > target) end = mid - 1;
            else start = mid + 1;
        } else if (isTargetInLeft) {
            end = mid - 1;
        } else if (isGuessInLeft) {
            start = mid + 1;
        } else {
            if (nums[mid] > target) end = mid - 1;
            else start = mid + 1;
        }
    }

    return -1;
};
