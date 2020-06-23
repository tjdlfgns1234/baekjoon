using System;

namespace MyProgram
{
    class Program
    { 
        static int Main(string[] args)
        {
            int N = int.Parse(Console.ReadLine());

            for (int i = 0; i < N; i++)
            {
                for (int j = 0; j < i+1; j++)
                {
                    Console.Write("*");
                }
                Console.WriteLine();
            }

            for(int i=N;i>0;i--)
            {
                for (int j = 0; j < i - 1; j++)
                {
                    Console.Write("*");
                }
                Console.WriteLine();
            }

            return 0;
        }
    }
}