/*
 * Akanksha Joshi
 * BME 121 - Fall 2018
 * WA04 - Subjects for Chemotherapy
*/

using static System.Console;

namespace Bme121
{
    public class Subject
    {
        private string chemoType, cellType, survivalDaysToString;
        private int survivalDays, karnofskyPct, diagMonthsAgo, ageYears;
        private bool isCensored, hadPriorTherapy;

        public Subject(string chemoType, string cellType, int survivalDays, bool isCensored, int karnofskyPct, int diagMonthsAgo, int ageYears, bool hadPriorTherapy)
        {
            this.chemoType = chemoType;
            this.cellType = cellType;
            this.survivalDays = survivalDays;
            this.karnofskyPct = karnofskyPct;
            this.diagMonthsAgo = diagMonthsAgo;
            this.ageYears = ageYears;
            this.isCensored = isCensored;
            this.hadPriorTherapy = hadPriorTherapy;
        }

        public override string ToString()
        {
            if (chemoType == "Standard") chemoType = "Std";
            else if (chemoType == "Test") chemoType = "Tst";

            if (cellType == "Squamous") cellType = "Sq";
            else if (cellType == "Small Cell") cellType = "Sc";
            else if (cellType == "Adeno") cellType = "Ad";
            else if (cellType == "Large") cellType = "Lg";

            if (survivalDays < 100 && survivalDays > 9)
            {
                survivalDaysToString = $"{survivalDays:D2}";
            }
            else if (survivalDays < 10)
            {
                survivalDaysToString = $"{survivalDays:D2}";
            }

            return string.Format($"{chemoType}{cellType}{survivalDays}");
        }
    }
    static class Program
    {
        static void Main()
        {
            Subject[] subjects = {
                new Subject( "Standard", "Squamous"  ,  72, false, 60,  7, 69, false),
                new Subject( "Standard", "Squamous"  , 411, false, 70,  5, 64,  true),
                new Subject( "Standard", "Squamous"  , 228, false, 60,  3, 38, false),
                new Subject( "Standard", "Squamous"  , 126, false, 60,  9, 63,  true),
                new Subject( "Standard", "Squamous"  , 118, false, 70, 11, 65,  true),
                new Subject( "Standard", "Squamous"  ,  10, false, 20,  5, 49, false),
                new Subject( "Standard", "Squamous"  ,  82, false, 40, 10, 69,  true),
                new Subject( "Standard", "Squamous"  , 110, false, 80, 29, 68, false),
                new Subject( "Standard", "Squamous"  , 314, false, 50, 18, 43, false),
                new Subject( "Standard", "Squamous"  , 100,  true, 70,  6, 70, false),
                new Subject( "Standard", "Squamous"  ,  42, false, 60,  4, 81, false),
                new Subject( "Standard", "Squamous"  ,   8, false, 40, 58, 63,  true),
                new Subject( "Standard", "Squamous"  , 144, false, 30,  4, 63, false),
                new Subject( "Standard", "Squamous"  ,  25,  true, 80,  9, 52,  true),
                new Subject( "Standard", "Squamous"  ,  11, false, 70, 11, 48,  true),
                new Subject( "Standard", "Small Cell",  30, false, 60,  3, 61, false),
                new Subject( "Standard", "Small Cell", 384, false, 60,  9, 42, false),
                new Subject( "Standard", "Small Cell",   4, false, 40,  2, 35, false),
                new Subject( "Standard", "Small Cell",  54, false, 80,  4, 63,  true),
                new Subject( "Standard", "Small Cell",  13, false, 60,  4, 56, false),
                new Subject( "Standard", "Small Cell", 123,  true, 40,  3, 55, false),
                new Subject( "Standard", "Small Cell",  97,  true, 60,  5, 67, false),
                new Subject( "Standard", "Small Cell", 153, false, 60, 14, 63,  true),
                new Subject( "Standard", "Small Cell",  59, false, 30,  2, 65, false),
                new Subject( "Standard", "Small Cell", 117, false, 80,  3, 46, false),
                new Subject( "Standard", "Small Cell",  16, false, 30,  4, 53,  true),
                new Subject( "Standard", "Small Cell", 151, false, 50, 12, 69, false),
                new Subject( "Standard", "Small Cell",  22, false, 60,  4, 68, false),
                new Subject( "Standard", "Small Cell",  56, false, 80, 12, 43,  true),
                new Subject( "Standard", "Small Cell",  21, false, 40,  2, 55,  true),
                new Subject( "Standard", "Small Cell",  18, false, 20, 15, 42, false),
                new Subject( "Standard", "Small Cell", 139, false, 80,  2, 64, false),
                new Subject( "Standard", "Small Cell",  20, false, 30,  5, 65, false),
                new Subject( "Standard", "Small Cell",  31, false, 75,  3, 65, false),
                new Subject( "Standard", "Small Cell",  52, false, 70,  2, 55, false),
                new Subject( "Standard", "Small Cell", 287, false, 60, 25, 66,  true),
                new Subject( "Standard", "Small Cell",  18, false, 30,  4, 60, false),
                new Subject( "Standard", "Small Cell",  51, false, 60,  1, 67, false),
                new Subject( "Standard", "Small Cell", 122, false, 80, 28, 53, false),
                new Subject( "Standard", "Small Cell",  27, false, 60,  8, 62, false),
                new Subject( "Standard", "Small Cell",  54, false, 70,  1, 67, false),
                new Subject( "Standard", "Small Cell",   7, false, 50,  7, 72, false),
                new Subject( "Standard", "Small Cell",  63, false, 50, 11, 48, false),
                new Subject( "Standard", "Small Cell", 392, false, 40,  4, 68, false),
                new Subject( "Standard", "Small Cell",  10, false, 40, 23, 67,  true),
                new Subject( "Standard", "Adeno"     ,   8, false, 20, 19, 61,  true),
                new Subject( "Standard", "Adeno"     ,  92, false, 70, 10, 60, false),
                new Subject( "Standard", "Adeno"     ,  35, false, 40,  6, 62, false),
                new Subject( "Standard", "Adeno"     , 117, false, 80,  2, 38, false),
                new Subject( "Standard", "Adeno"     , 132, false, 80,  5, 50, false),
                new Subject( "Standard", "Adeno"     ,  12, false, 50,  4, 63,  true),
                new Subject( "Standard", "Adeno"     , 162, false, 80,  5, 64, false),
                new Subject( "Standard", "Adeno"     ,   3, false, 30,  3, 43, false),
                new Subject( "Standard", "Adeno"     ,  95, false, 80,  4, 34, false),
                new Subject( "Standard", "Large"     , 177, false, 50, 16, 66,  true),
                new Subject( "Standard", "Large"     , 162, false, 80,  5, 62, false),
                new Subject( "Standard", "Large"     , 216, false, 50, 15, 52, false),
                new Subject( "Standard", "Large"     , 553, false, 70,  2, 47, false),
                new Subject( "Standard", "Large"     , 278, false, 60, 12, 63, false),
                new Subject( "Standard", "Large"     ,  12, false, 40, 12, 68,  true),
                new Subject( "Standard", "Large"     , 260, false, 80,  5, 45, false),
                new Subject( "Standard", "Large"     , 200, false, 80, 12, 41,  true),
                new Subject( "Standard", "Large"     , 156, false, 70,  2, 66, false),
                new Subject( "Standard", "Large"     , 182,  true, 90,  2, 62, false),
                new Subject( "Standard", "Large"     , 143, false, 90,  8, 60, false),
                new Subject( "Standard", "Large"     , 105, false, 80, 11, 66, false),
                new Subject( "Standard", "Large"     , 103, false, 80,  5, 38, false),
                new Subject( "Standard", "Large"     , 250, false, 70,  8, 53,  true),
                new Subject( "Standard", "Large"     , 100, false, 60, 13, 37,  true),
                new Subject( "Test",     "Squamous"  , 999, false, 90, 12, 54,  true),
                new Subject( "Test",     "Squamous"  , 112, false, 80,  6, 60, false),
                new Subject( "Test",     "Squamous"  ,  87,  true, 80,  3, 48, false),
                new Subject( "Test",     "Squamous"  , 231,  true, 50,  8, 52,  true),
                new Subject( "Test",     "Squamous"  , 242, false, 50,  1, 70, false),
                new Subject( "Test",     "Squamous"  , 991, false, 70,  7, 50,  true),
                new Subject( "Test",     "Squamous"  , 111, false, 70,  3, 62, false),
                new Subject( "Test",     "Squamous"  ,   1, false, 20, 21, 65,  true),
                new Subject( "Test",     "Squamous"  , 587, false, 60,  3, 58, false),
                new Subject( "Test",     "Squamous"  , 389, false, 90,  2, 62, false),
                new Subject( "Test",     "Squamous"  ,  33, false, 30,  6, 64, false),
                new Subject( "Test",     "Squamous"  ,  25, false, 20, 36, 63, false),
                new Subject( "Test",     "Squamous"  , 357, false, 70, 13, 58, false),
                new Subject( "Test",     "Squamous"  , 467, false, 90,  2, 64, false),
                new Subject( "Test",     "Squamous"  , 201, false, 80, 28, 52,  true),
                new Subject( "Test",     "Squamous"  ,   1, false, 50,  7, 35, false),
                new Subject( "Test",     "Squamous"  ,  30, false, 70, 11, 63, false),
                new Subject( "Test",     "Squamous"  ,  44, false, 60, 13, 70,  true),
                new Subject( "Test",     "Squamous"  , 283, false, 90,  2, 51, false),
                new Subject( "Test",     "Squamous"  ,  15, false, 50, 13, 40,  true),
                new Subject( "Test",     "Small Cell",  25, false, 30,  2, 69, false),
                new Subject( "Test",     "Small Cell", 103,  true, 70, 22, 36,  true),
                new Subject( "Test",     "Small Cell",  21, false, 20,  4, 71, false),
                new Subject( "Test",     "Small Cell",  13, false, 30,  2, 62, false),
                new Subject( "Test",     "Small Cell",  87, false, 60,  2, 60, false),
                new Subject( "Test",     "Small Cell",   2, false, 40, 36, 44,  true),
                new Subject( "Test",     "Small Cell",  20, false, 30,  9, 54,  true),
                new Subject( "Test",     "Small Cell",   7, false, 20, 11, 66, false),
                new Subject( "Test",     "Small Cell",  24, false, 60,  8, 49, false),
                new Subject( "Test",     "Small Cell",  99, false, 70,  3, 72, false),
                new Subject( "Test",     "Small Cell",   8, false, 80,  2, 68, false),
                new Subject( "Test",     "Small Cell",  99, false, 85,  4, 62, false),
                new Subject( "Test",     "Small Cell",  61, false, 70,  2, 71, false),
                new Subject( "Test",     "Small Cell",  25, false, 70,  2, 70, false),
                new Subject( "Test",     "Small Cell",  95, false, 70,  1, 61, false),
                new Subject( "Test",     "Small Cell",  80, false, 50, 17, 71, false),
                new Subject( "Test",     "Small Cell",  51, false, 30, 87, 59,  true),
                new Subject( "Test",     "Small Cell",  29, false, 40,  8, 67, false),
                new Subject( "Test",     "Adeno"     ,  24, false, 40,  2, 60, false),
                new Subject( "Test",     "Adeno"     ,  18, false, 40,  5, 69,  true),
                new Subject( "Test",     "Adeno"     ,  83,  true, 99,  3, 57, false),
                new Subject( "Test",     "Adeno"     ,  31, false, 80,  3, 39, false),
                new Subject( "Test",     "Adeno"     ,  51, false, 60,  5, 62, false),
                new Subject( "Test",     "Adeno"     ,  90, false, 60, 22, 50,  true),
                new Subject( "Test",     "Adeno"     ,  52, false, 60,  3, 43, false),
                new Subject( "Test",     "Adeno"     ,  73, false, 60,  3, 70, false),
                new Subject( "Test",     "Adeno"     ,   8, false, 50,  5, 66, false),
                new Subject( "Test",     "Adeno"     ,  36, false, 70,  8, 61, false),
                new Subject( "Test",     "Adeno"     ,  48, false, 10,  4, 81, false),
                new Subject( "Test",     "Adeno"     ,   7, false, 40,  4, 58, false),
                new Subject( "Test",     "Adeno"     , 140, false, 70,  3, 63, false),
                new Subject( "Test",     "Adeno"     , 186, false, 90,  3, 60, false),
                new Subject( "Test",     "Adeno"     ,  84, false, 80,  4, 62,  true),
                new Subject( "Test",     "Adeno"     ,  19, false, 50, 10, 42, false),
                new Subject( "Test",     "Adeno"     ,  45, false, 40,  3, 69, false),
                new Subject( "Test",     "Adeno"     ,  80, false, 40,  4, 63, false),
                new Subject( "Test",     "Large"     ,  52, false, 60,  4, 45, false),
                new Subject( "Test",     "Large"     , 164, false, 70, 15, 68,  true),
                new Subject( "Test",     "Large"     ,  19, false, 30,  4, 39,  true),
                new Subject( "Test",     "Large"     ,  53, false, 60, 12, 66, false),
                new Subject( "Test",     "Large"     ,  15, false, 30,  5, 63, false),
                new Subject( "Test",     "Large"     ,  43, false, 60, 11, 49,  true),
                new Subject( "Test",     "Large"     , 340, false, 80, 10, 64,  true),
                new Subject( "Test",     "Large"     , 133, false, 75,  1, 65, false),
                new Subject( "Test",     "Large"     , 111, false, 60,  5, 64, false),
                new Subject( "Test",     "Large"     , 231, false, 70, 18, 67,  true),
                new Subject( "Test",     "Large"     , 378, false, 80,  4, 65, false),
                new Subject( "Test",     "Large"     ,  49, false, 30,  3, 37, false)
            };



            for (int i = 0; i < subjects.Length; i++)
            {
                Subject singularSubject = subjects[i];
                Write(singularSubject +" ");
                if((i+1)%10 ==0)
                    WriteLine();
            }
        }
    }
}



