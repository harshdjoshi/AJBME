using System;
using System.Collections.Generic;
using System.IO;

using static System.Console;

namespace Bme121
{
    // Describe one subject in study of males being treated for inoperable lung cancer.

    public class Subject
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
            var subjectData = csv.Split(',');
            if (subjectData.Length != 8)
                return null;
            var chemoType = subjectData[0];
            var cellType = subjectData[1];
            var survivalDays = subjectData[2];
            var isCensored = subjectData[3];
            var karnofskyPercent = subjectData[4];
            var diagMonthsAgo = subjectData[5];
            var ageYears = subjectData[6];
            var hadPriorTherapy = subjectData[7];
            return new Subject()
            {
                AgeYears = Int32.Parse(ageYears.Trim()),
                CellType = cellType.Trim(),
                ChemoType = chemoType.Trim(),
                DiagMonthsAgo = Int32.Parse(diagMonthsAgo.Trim()),
                HadPriorTherapy = YesNoParse(hadPriorTherapy.Trim()),
                IsCensored = YesNoParse(isCensored.Trim()),
                KarnofskyPct = Int32.Parse(karnofskyPercent.Trim()),
                SurvivalDays = Int32.Parse(survivalDays.Trim())

            };

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
            var containsHeader = true;
            var subjectList = new List<Subject>();
            using (var sr = new StreamReader(path))
            {
                if (containsHeader)
                {
                    string headerLine = sr.ReadLine();
                }
                string currentLine;
                while ((currentLine = sr.ReadLine()) != null)
                {
                    var subject = ParseCsv(currentLine);
                    if(subject!=null)
                        subjectList.Add(ParseCsv(currentLine));
                }
            }

            return subjectList.ToArray();
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
