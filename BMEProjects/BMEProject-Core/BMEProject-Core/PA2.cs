/*
 * Akanksha Joshi
 * BME 121 - Fall 2018
 * Programming Assignment 2 Part B: 
*/

using System;
using System.Drawing;

using static System.Console;

using SixLabors.ImageSharp;
using SixLabors.ImageSharp.PixelFormats;

namespace Bme121
{
    class Retina
    {
        public class Tile
        {
            public const int Len = 8;

            public Color[,] Pixels { get; set; }

            public Tile()
            {
                Pixels = new Color[Len, Len];
            }
        }

        public Tile[,] Tiles { get; set; }
        public int Height { get; private set; }
        public int Width { get; private set; }

        public Retina(string path)
        {
            Image<Rgba32> img6L = Image.Load<Rgba32>(path);

            Height = (int)Math.Ceiling((double)img6L.Height / Tile.Len);
            Width = (int)Math.Ceiling((double)img6L.Width / Tile.Len);
            Tiles = new Tile[Height, Width];

            for (int tileRow = 0; tileRow < Height; tileRow++)
            {
                for (int tileCol = 0; tileCol < Width; tileCol++)
                {
                    Tiles[tileRow, tileCol] = new Tile();

                    for (int row = 0; row < Tile.Len; row++)
                    {
                        for (int col = 0; col < Tile.Len; col++)
                        {
                            if (tileRow * Tile.Len + row >= img6L.Height || tileCol * Tile.Len + col >= img6L.Width)
                            {
                                Tiles[tileRow, tileCol].Pixels[row, col] = Color.FromArgb(255, 0, 0, 0);
                            }
                            else
                            {
                                Rgba32 p = img6L[tileRow * Tile.Len + row, tileCol * Tile.Len + col];
                                Color c = Color.FromArgb(p.A, p.R, p.G, p.B);

                                Tiles[tileRow, tileCol].Pixels[row, col] = c;
                            }
                        }
                    }
                }
            }

            //for (int x = 0; x < img6L.Width; x++)
            //{
            //for (int y = 0; y < img6L.Height; y++)
            //{
            //Rgba32 p = img6L[x,y];

            //Color c = Color.FromArgb(p.A, p.R, p.G, p.B);
            //Pixels[y, x] = c;
            //}
            //}
        }

        public void SaveToFile(string path)
        {
            Image<Rgba32> img6L = new Image<Rgba32>(Width * Tile.Len, Height* Tile.Len);
            for (int x = 0; x < Width; x++)
            {
                for (int y = 0; y < Height; y++)
                {
                    Color[,] c = Tiles[y, x].Pixels;
                    for (int k = 0; k < Tile.Len; k++)
                    {
                        for (int l = 0; l < Tile.Len; l++)
                        {
                            Rgba32 p = new Rgba32(c[k,l].R, c[k, l].G, c[k, l].B, c[k, l].A);
                            var posY = x * Tile.Len + k;
                            var posX = y * Tile.Len + l;
                            img6L[posX, posY] = p;
                        }
                    }
                }
            }

            img6L.Save(path);
        }
    }
    static class Program
    {
        static void Main()
        {
            const string path = "20051020_63711_0100_PP.png";
            Retina retina = new Retina(path);
            retina.SaveToFile("test.png");
        }
    }
}
