
/**
 * Title: "Remove Duplicates", Codeforces problem. 
 * Date: Friday, 29 December 2023 
 *
 */
import java.io.*;
import java.util.*;

public class CF_978A {

  public static void main(String args[]) {
    FastScanner sc = new FastScanner();
    PrintWriter out = new PrintWriter(System.out);
    int n = sc.nextInt();

    int[] arr = new int[n];
    for (int i = 0; i < arr.length; i++)
      arr[i] = sc.nextInt();

    ArrayList<Integer> pos = new ArrayList<>();
    Map<Integer, Boolean> freq = new HashMap<Integer, Boolean>();
    for (int i = n - 1; i >= 0; i--) {
      if (!freq.containsKey(arr[i])) {
        pos.add(arr[i]);
        freq.put(arr[i], true);
      }
    }

    out.println(pos.size());
    for (int i = pos.size() - 1; i >= 0; i--)
      out.print(pos.get(i) + " ");

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
