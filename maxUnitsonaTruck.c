import java.util.Arrays;

class Solution {
    public int maximumUnits(int[][] boxTypes, int truckSize) {
        Arrays.sort(boxTypes, (a, b) -> b[1] - a[1]);

        int maxUnits = 0;
        for (int[] boxType : boxTypes) {
            int boxesToLoad = Math.min(truckSize, boxType[0]);
            maxUnits += boxesToLoad * boxType[1];
            truckSize -= boxesToLoad;
            if (truckSize == 0) break;
        }
        return maxUnits;
    }
}
