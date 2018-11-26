
using System;
using System.IO;
using System.Linq;
using static System.Console;
using MediCal;
using DataStructures;

namespace DataStructures
{
    partial class LinkedList
    {
        // Method forms a sub-list of Drug objects satisfying a target predicate.
        public LinkedList SubList(Func<Drug,bool> predicate = null)
        {
            if (predicate == null)
                return this;
            LinkedList drugSubList = new LinkedList();
            var drugdata = this.ToArray().Where(predicate);
            foreach (var drug in drugdata)
            {
                drugSubList.AddLast(drug);
            }

            return drugSubList;
        }
    }
}

namespace Bme121
{
    static class Programwa07
    {
        // Test a drug name for Lorazepam tablet.
        public static bool IsLorazepamTablet( Drug d )
        {
            return d.Name.Contains( "LORAZEPAM" ) && d.Name.Contains( "TABLET" );
        }

        // Test a drug name for Temazipam capsule.
        public static bool IsTemazipamCapusule( Drug d )
        {
            return d.Name.Contains( "TEMAZEPAM" ) && d.Name.Contains( "CAPSULE" );
        }

        // Test the 'LinkedList.SubList' method.
        static void MainWa07( )
        {
            // Parameters for reading the drug file.
            const string path = "RXQT1503.txt";
            const FileMode mode = FileMode.Open;
            const FileAccess access = FileAccess.Read;

            // Load all drugs into a linked list.
            LinkedList allDrugs = new LinkedList( );
            using( FileStream file = new FileStream( path, mode, access ) )
            using( StreamReader reader = new StreamReader( file ) )
            {
                while( ! reader.EndOfStream )
                {
                    string line = reader.ReadLine( );
                    Drug d = Drug.ParseFileLine( line );
                    allDrugs.AddLast( d );
                }
            }
            WriteLine( "allDrugs.Count = {0}", allDrugs.Count );

            // Form a sub-list of Temazipam capsules.
            LinkedList subDrugs1 = allDrugs.SubList(IsLorazepamTablet );
            WriteLine( "subDrugs1.Count = {0}", subDrugs1.Count );
            foreach( Drug d in subDrugs1.ToArray( ) ) WriteLine( d );

            // Form a sub-list of Lorazepam tablets.
            LinkedList subDrugs2 = allDrugs.SubList( IsTemazipamCapusule);
            WriteLine( "subDrugs2.Count = {0}", subDrugs2.Count );
            foreach( Drug d in subDrugs2.ToArray( ) ) WriteLine( d );
        }
    }
}
