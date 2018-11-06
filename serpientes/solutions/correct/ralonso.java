import java.io.*;
import java.util.*;

class serpientes {
  public static int pairToPosition(int r, int c, int nr, int nc) {
    return r * nc + ((r & 1) == 0 ? c : nc - 1 - c);
  }

  public static String positionToPairString(int p, int nr, int nc) {
    int r = p / nc;
    int c = (r & 1) == 0 ? p % nc : nc - 1- p % nc;
    return r + " " + c;
  }

  public static void main(String args[]) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    StringTokenizer st = new StringTokenizer(br.readLine());

    int m = Integer.parseInt(st.nextToken());
    int n = Integer.parseInt(st.nextToken());

    st = new StringTokenizer(br.readLine());

    int e = Integer.parseInt(st.nextToken());

    int a, b, c, d;

    int jump[] = new int[m * n];

    for (int i = 0; i < m * n; i++) jump[i] = i;

    for (int i = 0; i < e; i++) {
      st = new StringTokenizer(br.readLine());

      a = Integer.parseInt(st.nextToken());
      b = Integer.parseInt(st.nextToken());
      c = Integer.parseInt(st.nextToken());
      d = Integer.parseInt(st.nextToken());

      jump[pairToPosition(a, b, m, n)] = pairToPosition(c, d, m, n);
    }

    st = new StringTokenizer(br.readLine());

    int p = 0;
    int t;
    int tt = Integer.parseInt(st.nextToken());

    st = new StringTokenizer(br.readLine());

    for (int i = 0; i < tt; i++) {
      p += Integer.parseInt(st.nextToken());

      if (p + 1 >= m * n) {
        p = m * n - 1;
        break;
      }

      p = jump[p];

      if (p + 1 >= m * n) {
        p = m * n - 1;
        break;
      }
    }

    System.out.println(positionToPairString(p, m, n));
  }
}
