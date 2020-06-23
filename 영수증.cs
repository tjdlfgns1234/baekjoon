using System;

namespace MyProgram
{
    class Program
    { 
        static int Main(string[] args)
        {
            int N = int.Parse(Console.ReadLine());
            int[] price=new int[9];
            int sum=0;

            for (int i = 0; i < 9; i++)
            {
                price[i] = int.Parse(Console.ReadLine());
                sum = sum + price[i];
            }

            Console.WriteLine(N-sum);

            return 0;
        }
    }
}
