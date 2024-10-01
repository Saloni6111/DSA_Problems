class Solution {
    public int trap(int[] height) {
        int n = height.length;
        int[] bigInR = new int[n];
        int[] bigInL = new int[n];
        int maxl = -1;
        int maxr = -1;
        int totalw = 0;
        for (int i = 0; i < n; i++) {
            if (height[i] >= maxl) {
                maxl = height[i];
            }
            bigInL[i] = maxl;
        }
        for (int i = n - 1; i >= 0; i--) {
            if (height[i] >= maxr) {
                maxr = height[i];
            }
            bigInR[i] = maxr;
        }
        for (int j = 0; j < n; j++) {
            totalw += ((Math.min(bigInL[j], bigInR[j])) - height[j]);
            System.out.println(totalw);
        }
        return totalw;
    }
}