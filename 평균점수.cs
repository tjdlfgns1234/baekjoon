using System;

namespace MyProgram
{
    class Practice
    {
        static int Main(string[] args)
        {
            int[] num;
            int result=0;
            num = new int[5];

            for(int i=0;i<5;i++)
            {
                num[i]=int.Parse(Console.ReadLine());
                if(num[i]<40)
                {
                    num[i] = 40;
                }
                result = result + num[i];
            }

            Console.WriteLine(result/5);

            return 0;
        }
    }
}