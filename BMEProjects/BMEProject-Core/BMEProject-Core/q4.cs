using System;
using System.IO;

using static System.Console;

namespace Bme121
{
    static class Program
    {
        static void Main()
        {
            const string path = "TheEnd.txt";
            int counter = 1;
            var lines = readData(path);
            for (int i = 0; i < lines.Length-1; i+=2)
            {
                var endTime = "";
                if (i + 3 > lines.Length)
                {
                    endTime = lines[i].Trim() + ",999";
                }
                else
                {
                    endTime = lines[i + 2].Trim() + ",000";
                }
                var time = lines[i]+",000 -->" + endTime;
                var caption = lines[i + 1];
                Console.WriteLine(counter);
                Console.WriteLine(time);
                Console.WriteLine(caption);
                Console.WriteLine();
                counter++;
            }
        }

        static string[] readData(string path)
        {
            string[] lines = File.ReadAllLines(path);
            return lines;
        }
        
    }
}
