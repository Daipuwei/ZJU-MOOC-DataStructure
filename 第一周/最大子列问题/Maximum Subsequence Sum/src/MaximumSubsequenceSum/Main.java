package MaximumSubsequenceSum;

import java.io.BufferedInputStream;
import java.util.Scanner;

public class Main {
	static int N;
	static int[] num = new int[100000];
	static int MaxSum = 0;
	static int End = 0;
	static int end = 0;
	static int negetive = 0;
	static int record_num = 0;
	static int Record_num = 0;

	public static void MaxSum(int[] num , int N){
		int ThisSum = 0;
		for ( int i = 0; i < N ; i++){
			if ( num[i] < 0){
				negetive++;
			}
			
			ThisSum += num[i];
			record_num++;
			
			if ( MaxSum < ThisSum){
				MaxSum = ThisSum;
				Record_num = record_num;
				End = i;
			}
			
			if(ThisSum == MaxSum){
				end = i;
				if ( num[End - Record_num +1] >= num[end - record_num +1]){
					if (num[End - Record_num +1] == num[end - record_num +1]){
						if ( Record_num > record_num){
							Record_num = record_num;
							End = end;
						}
					}else{
						Record_num = record_num;
						End = end;
					}
				}
			}
	
			if (ThisSum < 0){
				ThisSum = 0;
				record_num = 0;
			}
		}
		if ( negetive == N){
			System.out.print(0+" "+num[0]+" "+num[N-1]);
		}else if(MaxSum == 0){
			System.out.print(0+" "+0+" "+0);
		}else{
			System.out.print(MaxSum+" "+num[End-Record_num+1]+" "+num[End]);
		}
	}
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner in = new Scanner(new BufferedInputStream(System.in));
		N = in.nextInt();
		for ( int i = 0 ; i < N ; i++){
			num[i] = in.nextInt();
		}
		MaxSum(num, N);
		in.close();
	}

}
