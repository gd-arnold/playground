// Time: O(n)
// Memory: O(n)
// No division operation
function productExceptSelf(nums: number[]): number[] {
    const productFromLeft = [1];
    const productFromRight = [];

    productFromRight[nums.length - 1] = 1;

    for (let i = 1; i < nums.length; i++) {
        productFromLeft[i] = productFromLeft[i - 1] * nums[i - 1];
    }

    for (let i = nums.length - 2; i >= 0; i--) {
        productFromRight[i] = productFromRight[i + 1] * nums[i + 1];
    }

    const result = [];

    for (let i = 0; i < productFromLeft.length; i++) {
        result.push(productFromLeft[i] * productFromRight[i]);
    }

    return result;
};

console.log(productExceptSelf([4,2,3,4]));
// productFromLeft:  [ 1, 4, 8, 24 ]
// productFromRight: [ 24, 12, 4, 1 ]
// result: [ 24, 48, 32, 24 ]
