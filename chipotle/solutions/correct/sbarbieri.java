import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;

class chipotle {

//programado sin hash. eso lo hago dsps.

	public static String s;
	public static int M,l;
	public static String[] dic;
	public static long[] c;
	public static long mod;


	public static void main(String[] args) throws IOException {
		Scanner in = new Scanner(System.in);
		mod = 1000009;
		M = in.nextInt();
		dic = new String [M];
		for(int i =0; i<M; i++){dic[i]=in.next();}
		s = in.next();
		c = new long[s.length()+1];
		c[s.length()]=1;
		for(int i =s.length()-1; i >=0; i--){
			for(int j =0; j<M; j++){
				l = dic[j].length();
				if(i+l <= s.length()){
					if(s.substring(i,i+l).equals(dic[j])){c[i]=(c[i]+c[i+l])%mod;}
				}
			}
			//System.out.println(i+" "+c[i]);
		}
		System.out.println(c[0]);
	}
}
