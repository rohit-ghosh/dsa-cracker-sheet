/*
Longest Consecutive Subsequence
Given an array of integers, find the length of the longest sub-sequence such that elements in the subsequence are consecutive integers, the consecutive numbers can be in any order.

Examples:

Input: arr[] = {1, 9, 3, 10, 4, 20, 2}
Output: 4
Explanation: The subsequence 1, 3, 4, 2 is the longest subsequence of consecutive elements

Input: arr[] = {36, 41, 56, 35, 44, 33, 34, 92, 43, 32, 42}
Output: 5
Explanation: The subsequence 36, 35, 33, 34, 32 is the longest subsequence of consecutive elements.
*/

import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class Q24 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        Integer testCases = in.nextInt();
        while(testCases-- > 0){
            Integer n = in.nextInt();
            ArrayList<Integer> arr = new ArrayList<>();
            for (int i = 0; i < n; i++) {
                Integer num = in.nextInt();
                arr.add(num);
            }
            Integer maxInArr = Collections.max(arr);
            boolean[] visited = new boolean[maxInArr+1];
            for (int i = 0; i < n; i++) {
                visited[arr.get(i)]= true;
            }

            Integer ans = 0, presentCount = 0;
            for (int i = 0; i <= maxInArr; i++) {
                if(visited[i] == true){
                    ++presentCount;
                }
                else{
                    ans = Math.max(ans, presentCount);
                    presentCount = 0;
                }
            }
            ans = Math.max(ans, presentCount);
            System.out.println("Ans: " + ans);
        }
    }
}
