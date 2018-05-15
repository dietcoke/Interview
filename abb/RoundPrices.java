package round_prices;

import java.util.*;

import org.junit.*;

import static org.junit.Assert.*;

public class RoundPrices {
    /*
        Round Prices
        AirBnB Interview Question
     */
    public class Solution {
        public int[] roundUp(double[] arr) {
            int n = arr.length;
            NumWithDiff[] arrWithDiff = new NumWithDiff[n];
            double sum = 0.0;
            int floorSum = 0;
            for (int i = 0; i < n; i++) {
                int floor = (int) arr[i];
                int ceil = floor;
                if (floor < arr[i]) ceil++;
                floorSum += floor;
                sum += arr[i];
                arrWithDiff[i] = new NumWithDiff(ceil, ceil - arr[i]);
            }

            int num = (int) Math.round(sum);
            int diff = num - floorSum;
            Arrays.sort(arrWithDiff, new Comparator<NumWithDiff>() {
                @Override
                public int compare(NumWithDiff n1, NumWithDiff n2) {
                    if (n1.diffWithCeil <= n2.diffWithCeil) return -1;
                    else return 1;
                }
            });
            // Arrays.sort(arrWithDiff, (a, b) -> (Double.compare(b.diffWithCeil, a.diffWithCeil)));

            int[] res = new int[n];
            int i = 0;
            for (; i < diff; i++) {
                res[i] = arrWithDiff[i].num; // 这些放ceil
            }
            for (; i < n; i++) {
                res[i] = arrWithDiff[i].num - 1; // 剩下的只放floor
            }
            return res;
        }

        class NumWithDiff {
            int num;
            double diffWithCeil;

            public NumWithDiff(int n, double c) {
                this.num = n;
                this.diffWithCeil = c;
            }
        }
    }
