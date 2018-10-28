using System;
using System.IO;

using static System.Console;

namespace Bme121
{
    // Describe one subject in study of males being treated for inoperable lung cancer.

    class Subject
    {
        public string ChemoType       { get; private set; } // Type of chemotherapy
        public string CellType        { get; private set; } // Type of cancer cells
        public int    SurvivalDays    { get; private set; } // Suvival time in days
        public bool   IsCensored      { get; private set; } // Indicate censored survival times
        public int    KarnofskyPct    { get; private set; } // Karnofsky performance percent
        public int    DiagMonthsAgo   { get; private set; } // Months since diagnosis
        public int    AgeYears        { get; private set; } // Age in years
        public bool   HadPriorTherapy { get; private set; } // Indicate therapy prior to trial

        // Private default constructor so users can't instantiate objects.

        private Subject( ) { }

        // Return new object with data contained in csv string.

        private static Subject ParseCsv( string csv )
        {
            return new Subject( ); // remove this line
        }

        // Return true/false for yes/no.

        private static bool YesNoParse( string s )
        {
            if( s == "yes" ) return  true;
            if( s == "no"  ) return false;
            throw new FormatException( "Invalid yes/no format" );
        }

        // Return a short description for debugging.

        public override string ToString( )
        {
            string chemoPart = "???";
            if( ChemoType == "standard" ) chemoPart = "Std";
            if( ChemoType == "test"     ) chemoPart = "Tst";

            string cellPart = "??";
            if( CellType == "squamous"  ) cellPart  = "Sq";
            if( CellType == "smallcell" ) cellPart  = "Sc";
            if( CellType == "adeno"     ) cellPart  = "Ad";
            if( CellType == "large"     ) cellPart  = "Lg";

            return string.Format( "{0}{1}{2:d3}", chemoPart, cellPart, SurvivalDays );
        }

        public static Subject[ ] MakeArrayFromFile( string path )
        {
            return new Subject[ 1 ] { new Subject( ) }; // remove this line
        }
    }

    static class Program
    {
        static void Main( )
        {
            Subject[ ] subjects = Subject.MakeArrayFromFile( "lung.csv" );

            for( int i = 0; i < subjects.Length; i ++ )
            {
                if( i % 10 > 0 ) Write( " " );
                Write( subjects[ i ] );
                if( i % 10 == 9 ) WriteLine( );
            }
        }
    }
}
