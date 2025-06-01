class Solution {

    private int n;

    public int maxSizeSlices(int[] slices) {
        n = slices.length / 3;
        int[] slicesWithoutFirst = new int[slices.length - 1];
        System.arraycopy(slices, 1, slicesWithoutFirst, 0, slicesWithoutFirst.length);
        int maxSumExcludingFirst = calculateMaxSum(slicesWithoutFirst);
        int[] slicesWithoutLast = new int[slices.length - 1];
        System.arraycopy(slices, 0, slicesWithoutLast, 0, slicesWithoutLast.length);
        int maxSumExcludingLast = calculateMaxSum(slicesWithoutLast);
        return Math.max(maxSumExcludingFirst, maxSumExcludingLast);
    }
    private int calculateMaxSum(int[] nums) {
        int m = nums.length;
        int[] prev = new int[n + 1];
        int[] curr = new int[n + 1];
        for (int i = 1; i <= m; ++i) {
            int[] next = new int[n + 1];
            for (int j = 1; j <= n; ++j) {
                next[j] = Math.max(curr[j], prev[j - 1] + nums[i - 1]);
            }
            prev = curr;
            curr = next;
        }
        return curr[n];
    }
}
