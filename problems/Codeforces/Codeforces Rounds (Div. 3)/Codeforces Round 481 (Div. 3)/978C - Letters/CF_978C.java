
/**
 * Title: "Letters", Codeforces problem. 
 * Date: Tuesday, 02 January 2024 
 *
 */
import java.io.*;
import java.util.*;

public class CF_978C {

  public static void main(final String args[]) throws IOException {
    final FastScanner sc = new FastScanner();
    final PrintWriter out = new PrintWriter(System.out);

    final int n = sc.nextInt();
    int m = sc.nextInt();

    final long[] arr = new long[n + 1];
    for (int i = 1; i <= n; i++) {
      arr[i] = sc.nextLong();
      arr[i] += arr[i - 1];
    }

    long num;
    while (m-- > 0) {
      num = sc.nextLong();

      int left = 0, right = n, middle;
      while (left <= right) {
        middle = left + ((right - left) >> 1);
        if (arr[middle] < num)
          left = middle + 1;
        else
          right = middle - 1;
      }

      out.println(left + " " + (num - arr[left - 1]));
    }

    out.close();
  }

  static class FastScanner {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st;

    String next() {
      while (st == null || !st.hasMoreTokens()) {
        try {
          st = new StringTokenizer(br.readLine());
        } catch (final IOException e) {
          e.printStackTrace();
        }
      }
      return st.nextToken();
    }

    int[] readArray(final int n) {
      final int[] a = new int[n];
      for (int i = 0; i < n; i++)
        a[i] = nextInt();
      return a;
    }

    int nextInt() {
      return Integer.parseInt(next());
    }

    long nextLong() {
      return Long.parseLong(next());
    }

    double nextDouble() {
      return Double.parseDouble(next());
    }
  }
}
