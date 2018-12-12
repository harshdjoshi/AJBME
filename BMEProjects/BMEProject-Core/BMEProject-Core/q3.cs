using System;
using System.Diagnostics;
using System.Linq;
using System.Net.NetworkInformation;
// for the 'Contains' method on line 32

using static System.Console;

namespace Bme121
{
    static class Program
    {
        static Random rGen = new Random(7103);

        // Create an integer array filled with random values.
        // This is a modified version which allows generation of an array
        // with no repeated values (all values unique).

        static int[] NewRandomArray(int size, bool unique = false)
        {
            if (size < 1) return new int[0];

            int[] result = new int[size];
            Array.Fill(result, -1); // Each -1 will be replaced by a nonnegative value

            int range;
            if (unique) range = 4 * size / 3;
            else /* ( ! unique ) */ range = 3 * size / 4;

            for (int i = 0; i < result.Length; i++)
            {
                int value = rGen.Next(0, range);
                if (unique)
                    while (result.Contains(value))
                    {
                        value = rGen.Next(0, range);
                    }
                result[i] = value;
            }

            return result;
        }

        // Comparison method - returns -1, 0, +1 if 'a' is <, =, > 'b', respectively.

        static int Compare(int a, int b)
        {
            return a.CompareTo(b);
        }

        // Computer a measure of disorder (unsortedness).
        // For each element, its disorder is the distance to the closest position
        // it where it could appear in the sorted array. For the whole array, the
        // disorder is the sum of the disorders of its elements.

        static int Disorder(int[] a)
        {
            if (a == null) return 0;
            if (a.Length < 2) return 0;

            int result = 0;
            int duplicates = 0;
            for (int cycleStart = 0; cycleStart < a.Length; cycleStart++)
            {
                int item = a[cycleStart];
                int pos = 0;
                
                for (int i = 0; i < a.Length; i++)
                {
                    if (i != cycleStart)
                    {
                        if (Compare(item, a[i]) > 0) pos++;
                        if (item == a[i])
                        {
                            duplicates++;
                        }
                    }

                }

                result += Math.Abs(pos - cycleStart);
                //pending for non unique
            }

            return result;
        }

        static void Main()
        {
            int[] data;
            int disorder;

            WriteLine();
            WriteLine("unique values");

            data = NewRandomArray(size: 15, unique: true);
            disorder = Disorder(data);

            Write("data:");
            foreach (int value in data) Write(" {0,3}", value);
            WriteLine("   disorder:{0,3}", disorder);

            Array.Sort(data);
            disorder = Disorder(data);

            Write("sort:");
            foreach (int value in data) Write(" {0,3}", value);
            WriteLine("   disorder:{0,3}", disorder);

            WriteLine();
            WriteLine("non-unique values");

            data = NewRandomArray(size: 15, unique: false);
            disorder = Disorder(data);

            Write("data:");
            foreach (int value in data) Write(" {0,3}", value);
            WriteLine("   disorder:{0,3}", disorder);

            Array.Sort(data);
            disorder = Disorder(data);

            Write("sort:");
            foreach (int value in data) Write(" {0,3}", value);
            WriteLine("   disorder:{0,3}", disorder);

            WriteLine();
        }
    }
}
