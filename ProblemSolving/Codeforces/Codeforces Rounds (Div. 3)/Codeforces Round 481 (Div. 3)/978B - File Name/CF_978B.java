/**
 * Title: "File Name", Codeforces problem. 
 * Date: Saturday, 30 December 2023 
 *
 */
import java.io.*;
import java.util.*;

public class CF_978B {

  public static void main(String args[]) throws IOException {
    FastScanner sc = new FastScanner();
    PrintWriter out = new PrintWriter(System.out);
    int n = sc.nextInt(), count = 0, result = 0;
    char[] file = sc.next().toCharArray();

    for (char ch : file) {
      if (ch == 'x') {
        if (++count >= 3)
          result++;
      } else
        count = 0;
    }

    out.println(result);

    out.close();
  }

  static class FastScanner {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st;

    String next() {
      while (st == null || !st.hasMoreTokens()) {
        try {
          st = new StringTokenizer(br.readLine());
        } catch (IOException e) {
          e.printStackTrace();
        }
      }
      return st.nextToken();
    }

    int[] readArray(int n) {
      int[] a = new int[n];
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
