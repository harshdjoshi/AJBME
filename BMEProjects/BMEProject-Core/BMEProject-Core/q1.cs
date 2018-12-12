using System;
using static System.Console;

using DataStructures;

namespace DataStructures
{
    partial class LinkedList<TData>
    {
        // Method to find the k-th element in the list.
        // For positive k, count forwards from the head.
        // For negative k, count backwards from the null after the tail.
        // TO DO:
        public bool TryFindKth(int k, out TData kthItem)
        {
            kthItem = default(TData);
            var listArray = this.ToArray();
            if (Math.Abs(k) > listArray.Length)
            {
                return false;
            }

            int kPos = k;
            if (k < 0)
            {
                kPos = listArray.Length + k;
            }

            kthItem = listArray[kPos];
            return true;
        }

    }
}

namespace Bme121
{
    static class Program
    {
        static Random rGen = new Random();

        static void Main()
        {
            // Create an empty linked list of integers.

            LinkedList<int> myList = new LinkedList<int>();

            // Add random integer values to the linked list, then display it.

            for (int count = 0; count < 16; count++) myList.AddLast(rGen.Next(100));
            WriteLine();
            Write("myList:");
            foreach (int number in myList.ToArray())
            {
                Write(" {0,2}", number);
            }
            WriteLine();

            // Find and display the k-th element for various values of k.

            WriteLine();
            foreach (int k in new int[] { 0, 1, -1, 2, -2, 5, -5, 10, -10, 20, -20 })
            {
                bool found = myList.TryFindKth(k, out int kthItem);
                WriteLine("k = {0,3}, myList.TryFindKth( k, out int kthItem ) = {1,5}, kthItem = {2,2}",
                    k, found, kthItem);
            }

            WriteLine();
        }
    }
}
