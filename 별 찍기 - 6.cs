using System;

namespace MyProgram
{
    class Practice
    {
        static int Main(string[] args)
        {
            int N = int.Parse(Console.ReadLine());

            for(int i=N;i>0;i--)
            {
                for (int j = i; j < N; j++)
                {
                    Console.Write(" ");
                }
                for (int k = 0; k < 2*i-1; k++)
                { 
                    Console.Write("*");
                }                
                Console.WriteLine();
            }

            return 0;
        }
    }
}