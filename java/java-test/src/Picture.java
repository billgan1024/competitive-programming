import java.util.*;
import java.io.*;

public class Picture {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static PrintWriter pr = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
    static StringTokenizer st;
    static int maxV = 10001;
    static long ans;

    public static void main(String[] args) throws IOException {
        int n = readInt();
        List<event> ver = new ArrayList(), hor = new ArrayList();
        for (int i = 0; i < n; i++) {
            int a = readInt() + maxV, b = readInt() + maxV, c = readInt() + maxV, d = readInt() + maxV;
            ver.add(new event(a, b, d, 1));
            ver.add(new event(c, b, d, -1));
            hor.add(new event(b, a, c, 1));
            hor.add(new event(d, a, c, -1));
        }
        fun(ver);
        fun(hor);
        System.out.println(ans);
    }

    static void fun(List<event> lst) {
        // for each axis, maintain a line from left to right
        Collections.sort(lst);
        int a[] = new int[2 * maxV];
        for (event e : lst) {
            if (e.val > 0) {
                for (int i = e.lo; i < e.hi; i++) {
                    if (a[i] == 0)
                        ans++;
                    a[i]++;
                }
            } else {
                for (int i = e.lo; i < e.hi; i++) {
                    a[i]--;
                    if (a[i] == 0)
                        ans++;
                }
            }
        }
    }

    static class event implements Comparable<event> {
        int x, lo, hi, val;

        event(int x0, int l0, int h0, int v0) {
            x = x0;
            lo = l0;
            hi = h0;
            val = v0;
        }

        public int compareTo(event a) {
            if (x != a.x)
                return Integer.compare(x, a.x);
            return -Integer.compare(val, a.val);
        }
    }

    static String next() throws IOException {
        while (st == null || !st.hasMoreTokens())
            st = new StringTokenizer(br.readLine().trim());
        return st.nextToken();
    }

    static long readLong() throws IOException {
        return Long.parseLong(next());
    }

    static int readInt() throws IOException {
        return Integer.parseInt(next());
    }

    static double readDouble() throws IOException {
        return Double.parseDouble(next());
    }

    static char readCharacter() throws IOException {
        return next().charAt(0);
    }

    static String readLine() throws IOException {
        return br.readLine().trim();
    }
}