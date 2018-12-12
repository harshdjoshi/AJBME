using System;
using static System.Console;

namespace Bme121
{
    static class Program
    {
        static void Main()
        {
            // Define the number and names of metabolic-syndrome risk factors.

            const int nRisks = 5;

            string[] longRiskNames = new string[nRisks]
            {
                "Fasting Glucose",
                "Waist Circumference",
                "HDL Cholesterol",
                "Triglycerides",
                "Blood Pressure"
            };

            string[] shortRiskNames = new string[nRisks] { "FG", "WC", "HC", "TG", "BP" };

            // Get the risk prevalences from the user.
            // TO DO:


            // Call method to form the pairwise risk-ratios matrix.
            // TO DO:


            // Display the pairwise risk-ratios matrix.
            // TO DO:


        }

        // Method to form a pairwise risk-ratio array from a risk-prevalences array.
        // TO DO:


    }
}
