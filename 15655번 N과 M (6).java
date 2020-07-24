import java.io.*;
import java.util.*;


public class NandM5{
    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        StringTokenizer  st;

        st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        int[] arr= new int[n];
        int[] result = new int[m];
        int[] check = new int [n];

        st = new StringTokenizer(br.readLine());
        for(int i = 0; i<n;i++)
        {
            check[i] = 0;
            arr[i] = Integer.parseInt(st.nextToken());
        }
        br.close();
        Arrays.sort(arr);

        print_result(check,arr,result,n,m,0);
    }
    static void print_result(int[] check,int[] arr,int[] result,int n,int m,int stage){
        if(stage == m)
        {
            for(int k = 0; k < m-1; k++)
            {
                if(result[k]>result[k+1])
                {
                    return;
                }
            }
            for(int i = 0; i < m;i++)
            {
                System.out.print(result[i]);
                System.out.print(" ");
            }
            System.out.println();
            return;
        }
        for(int j = 0; j <n;j++)
        {
            if (check[j] == 0)
            {
                check[j] = 1;
                result[stage]= arr[j];
                print_result(check,arr,result,n,m,stage+1);
                check[j] = 0;
            }
        }
        return;
    }
}