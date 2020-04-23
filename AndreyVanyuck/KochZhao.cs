using System;
using System.Collections.Generic;
using System.Drawing;
using System.Drawing.Imaging;
using System.IO;
using System.Text;
using System.Windows.Forms;
using System.Linq;

namespace WindowsFormsApp1
{
    class KochZhao : ISendInformationToForm, IChangeInformation
    {
        public Bitmap Image { get; set; }
        public ImageFormat ImageFormat { get; set; }
        public string PathImage { get; set; }
        public string DataFile { get; set; }
        public Point Point1 { get; set; }
        public Point Point2 { get; set; }
        public int Key { get; set; }
        public int P { get; set; }
        public byte[] HiddenInformation { get; set; }
        public int SizeSegment { get; set; }
        public Form1 Form { get; set; }

        public KochZhao(Form1 form)
        {
            P = 25;
            Point1 = new Point(6, 4);
            Point2 = new Point(4, 6);
            Form = form;
        }


        public void Inlining()
        {
            try
            {
                ChangeProgress(0);
                SendMessageToForm("Начало встраивания");
                SendMessageToForm("P = " + P);
                SendMessageToForm("Размер блоков = " + SizeSegment);
                SendMessageToForm("Точки встраивания: (" + Point1.X + "; " + Point1.Y + ")  (" + Point2.X + "; " + Point2.Y + ")");
                SendMessageToForm("Ключ для извлечения: " + HiddenInformation.Length);

                if ((Image.Width % SizeSegment) != 0 || (Image.Height % SizeSegment) != 0)
                {
                    Image = ResizeImage(Image);
                }

                int width = Image.Width;
                int height = Image.Height;
                var blueComponent = new byte[width, height];
                var greenComponent = new byte[width, height];
                var redComponent = new byte[width, height];


                for (var i = 0; i < width; i++)
                {
                    for (var j = 0; j < height; j++)
                    {
                        blueComponent[i, j] = Image.GetPixel(i, j).B;
                        greenComponent[i, j] = Image.GetPixel(i, j).G;
                        redComponent[i, j] = Image.GetPixel(i, j).R;
                    }
                }

                ChangeProgress(5);

                List<byte[,]> sepationBlueComponent = Separation(blueComponent, width, height);

                SendMessageToForm("Вычисление ДКП");

                List<double[,]> DCP = sepationBlueComponent.Select(selector: i => GetDCP(i)).ToList();

                ChangeProgress(15);
                SendMessageToForm("Встраивание информации");

                DCP = InliningMessage(HiddenInformation, DCP);

                ChangeProgress(65);
                SendMessageToForm("Вычисление ОДКП");

                List<double[,]> IDCP = DCP.Select(selector: i => GetIDCP(i)).ToList();

                ChangeProgress(75);

                var newBlueComponent = new double[width, height];

                newBlueComponent = Integration(IDCP, newBlueComponent, width, height);
                newBlueComponent = Normalize(newBlueComponent);

                ChangeProgress(85);

                var newImage = new Bitmap(Image, width, height);
                for (var i = 0; i < width; i++)
                {
                    for (var j = 0; j < height; j++)
                    {
                        newImage.SetPixel(i, j, Color.FromArgb(redComponent[i, j], greenComponent[i, j], (byte)Math.Round(newBlueComponent[i, j])));
                    }
                }

                ChangeProgress(95);
                SendMessageToForm("Встраивание завершено!");
                SendPictureToForm(newImage);

                string name = PathImage.Substring(PathImage.LastIndexOf("\\") + 1);
                string path = Path.GetDirectoryName(PathImage);

                File.WriteAllText(path + "\\new-" + name + ".key.txt", Convert.ToString(HiddenInformation.Length), Encoding.Default);
                path += "\\new-" + name;
                newImage.Save(path, ImageFormat);

                ChangeNameOfLabelOnForm(path);
                ChangeProgress(100);
                SendMessageToForm("Сохранено: " + path + "\n\n");
            }
            catch (Exception ex)
            {
                ChangeProgress(100);
                SendMessageToForm("Ошибка встраивания: " + ex.Message + "\n\n");
            }

        }


        public void Extraction()
        {
            try
            {
                ChangeProgress(0);
                SendMessageToForm("Начало извлечения");
                SendMessageToForm("P = " + P);
                SendMessageToForm("Размер блоков = " + SizeSegment);
                SendMessageToForm("Точки встраивания: (" + Point1.X + "; " + Point1.Y + ")  (" + Point2.X + "; " + Point2.Y + ")");
                SendMessageToForm("Ключ: " + Key);

                int width = Image.Width;
                int height = Image.Height;

                var blueComponent = new byte[width, height];

                for (var i = 0; i < width; i++)
                {
                    for (var j = 0; j < height; j++)
                    {
                        blueComponent[i, j] = Image.GetPixel(i, j).B;
                    }
                }

                ChangeProgress(5);

                List<byte[,]> sepBlue = Separation(blueComponent, width, height);
                
                SendMessageToForm("Вычисление ДКП");
                ChangeProgress(10);

                List<double[,]> DCP = sepBlue.Select(selector: i => GetDCP(i)).ToList();

                ChangeProgress(20);
                SendMessageToForm("Извлечение информации");

                List<byte> message = ExtractionMessage(DCP);

                ChangeProgress(80);

                Image.Dispose();

                ChangeProgress(95);

                SendMessageToForm("Извлечение завершено!");
                SendMessageToForm("Извлечено " + message.Count + " байт");

                string path = Path.GetDirectoryName(PathImage);

                path += "\\mess.txt";

                if (SaveMessage(message, path))
                {
                    SendMessageToForm("Сохранено: " + path);
                }
                else
                {
                    SendMessageToForm("Не удалось извлечь сообщение!\n\n");
                }

                SendMessageToForm("\n\n");
                ChangeProgress(100);
            }
            catch (Exception ex)
            {
                ChangeProgress(100);
                SendMessageToForm("Не удалось извлечь сообщение!" + ex.Message + "\n\n");
            }
        }
        private bool SaveMessage(List<byte> message, string path)
        {
            try
            {
                File.WriteAllBytes(path, message.ToArray());
                return true;
            }
            catch (Exception)
            {
                return false;
            }
        }
        private double[,] Integration(List<double[,]> ODCP, double[,] newBlue, int sizeX, int sizeY)
        {
            double[][,] temp = ODCP.ToArray();
            int nX = sizeX / SizeSegment;
            int nY = sizeY / SizeSegment;
            var count = 0;

            for (var i = 0; i < nX; i++)
            {
                int startX = i * SizeSegment;
                int endX = startX + SizeSegment - 1;

                for (var j = 0; j < nY; j++)
                {
                    int startY = j * SizeSegment;
                    int endY = startY + SizeSegment - 1;

                    if (count > temp.GetLength(0))
                    {
                        throw new IndexOutOfRangeException();
                    }
                    newBlue = Insert(newBlue, temp[count], startX, endX, startY, endY);
                    count++;
                }
            }
            return newBlue;
        }


        private double[,] Insert(double[,] newBlue, double[,] temp, int startX, int endX, int startY, int endY)
        {
            var u = 0;
            for (int i = startX; i < endX + 1; i++)
            {
                var v = 0;
                for (int j = startY; j < endY + 1; j++)
                {
                    newBlue[i, j] = temp[u, v];
                    v++;
                }
                u++;
            }
            return newBlue;
        }

        private double[,] Normalize(double[,] arrForNormalizes)
        {
            double min = arrForNormalizes[0, 0]; 
            double max = arrForNormalizes[0, 0];

            for (var i = 0; i < arrForNormalizes.GetLength(0); i++)
            {
                for (var j = 0; j < arrForNormalizes.GetLength(1); j++)
                {
                    if (arrForNormalizes[i, j] > max)
                    {
                        max = arrForNormalizes[i, j];
                    }
                    if (arrForNormalizes[i, j] < min)
                    {
                        min = arrForNormalizes[i, j];
                    }
                }
            }

            var result = new double[arrForNormalizes.GetLength(0), arrForNormalizes.GetLength(1)];

            for (var i = 0; i < arrForNormalizes.GetLength(0); i++)
            {
                for (var j = 0; j < arrForNormalizes.GetLength(1); j++)
                {
                    result[i, j] = 255 * (arrForNormalizes[i, j] + Math.Abs(min)) / (max + Math.Abs(min));
                }
            }
            return result;
        }
        private List<byte> ExtractionMessage(List<double[,]> DCP)
        {
            int size = Key;
            var stringOfBits = "";
            var message = new List<byte>();
            int key = Key;
            var allPos = new List<int>();

            for (var i = 0; i < DCP.Count; i++)
            {
                allPos.Add(i);
            }

            while (size > 0)
            {
                key = Multicarry(key, allPos.Count);
                int pos = allPos[key];
                allPos.RemoveAt(key);

                double AbsPoint1 = Math.Abs(DCP[pos][Point1.X, Point1.Y]);
                double AbsPoint2 = Math.Abs(DCP[pos][Point2.X, Point2.Y]);

                if (AbsPoint1 > AbsPoint2)
                {
                    stringOfBits += "0";
                }
                if (AbsPoint1 < AbsPoint2)
                {
                    stringOfBits += "1";
                }
                if (stringOfBits.Length == 8)
                {
                    message.Add(Convert.ToByte(Convert.ToInt32(stringOfBits, 2)));
                    stringOfBits = "";
                    size--;
                }
            }
            return message;
        }
        private List<double[,]> InliningMessage(byte[] message, List<double[,]> DCP)
        {
            int key = message.Length;
            var allPos = new List<int>();

            for (var i = 0; i < DCP.Count; i++)
            {
                allPos.Add(i);
            }

            for (var i = 0; i < message.Length; i++)
            {
                Converter conv = new Converter(message[i]);
                for (var j = 0; j < 8; j++)
                {
                    key = Multicarry(key, allPos.Count);
                    int pos = allPos[key];
                    allPos.RemoveAt(key);

                    double AbsPoint1 = Math.Abs(DCP[pos][Point1.X, Point1.Y]);
                    double AbsPoint2 = Math.Abs(DCP[pos][Point2.X, Point2.Y]);
                    var z1 = 1;
                    var z2 = 1;

                    if (DCP[pos][Point1.X, Point1.Y] < 0)   z1 = -1;
                    if (DCP[pos][Point2.X, Point2.Y] < 0)   z2 = -1;

                    if (conv[j] == 0)
                    {
                        if (AbsPoint1 - AbsPoint2 <= P)
                        {
                            AbsPoint1 = P + AbsPoint2 + 1;
                        }
                    }
                    if (conv[j] == 1)
                    {
                        if (AbsPoint1 - AbsPoint2 >= -P)
                        {
                            AbsPoint2 = P + AbsPoint1 + 1;
                        }
                    }

                    DCP[pos][Point1.X, Point1.Y] = z1 * AbsPoint1;
                    DCP[pos][Point2.X, Point2.Y] = z2 * AbsPoint2;
                }
            }
            return DCP;
        }

        private int Multicarry(long x, int maxSize)
        {
            long a = 0xffffda61L;
            x = (a * (x & 65535)) + (x >> 16);
            x = Math.Abs((int)x);
            if (x >= maxSize)
            {
                x %= maxSize;
            }
            return (int)x;
        }
        private double SetValueCoefficient(double value) => value == 0 ? 1.0 / Math.Sqrt(2) : 1;

        private double[,] GetDCP(byte[,] arr)
        {
            int size = arr.GetLength(0);
            var result = new double[size, size];
            double U, V, temp;

            for (var v = 0; v < size; v++)
            {
                for (var u = 0; u < size; u++)
                {
                    U = SetValueCoefficient(u);
                    V = SetValueCoefficient(v);
                    temp = 0;

                    for (var i = 0; i < size; i++)
                    {
                        for (var j = 0; j < size; j++)
                        {
                            temp += arr[i, j] * Math.Cos(Math.PI * v * (2 * i + 1) / (2 * size)) *
                                                Math.Cos(Math.PI * u * (2 * j + 1) / (2 * size));
                        }
                    }
                    result[v, u] = U * V * temp / (Math.Sqrt(2 * size));
                }
            }
            return result;
        }

        private double[,] GetIDCP(double[,] DCP)
        {
            int size = DCP.GetLength(0);
            var result = new double[size, size];
            double U, V, temp;

            for (var v = 0; v < size; v++)
            {
                for (var u = 0; u < size; u++)
                {
                    temp = 0;
                    U = SetValueCoefficient(u);
                    V = SetValueCoefficient(v);

                    for (var i = 0; i < size; i++)
                    {
                        for (var j = 0; j < size; j++)
                        {
                            temp += U * V * DCP[i, j] * Math.Cos(Math.PI * i * (2 * v + 1) / (2 * size)) *
                                                        Math.Cos(Math.PI * j * (2 * u + 1) / (2 * size));
                        }
                    }
                    result[v, u] = temp / (Math.Sqrt(2 * size));
                }
            }
            return result;
        }
        private List<byte[,]> Separation(byte[,] Blue, int sizeX, int sizeY)
        {
            int nX = sizeX / SizeSegment;
            int nY = sizeY / SizeSegment;
            var sepBlue = new List<byte[,]>();  

            for (var i = 0; i < nX; i++)
            {
                int startX = i * SizeSegment;
                int endX = startX + SizeSegment - 1;

                for (var j = 0; j < nY; j++)
                {
                    int startY = j * SizeSegment;
                    int endY = startY + SizeSegment - 1;
                    sepBlue.Add(GetSubmatrix(Blue, startX, endX, startY, endY));
                }
            }

            return sepBlue;
        }

        private byte[,] GetSubmatrix(byte[,] Blue, int startX, int endX, int startY, int endY)
        {
            int sizeX = endX - startX + 1;
            int sizeY = endY - startY + 1;
            var resultMatrix = new byte[sizeY, sizeX]; 

            for (var i = 0; i < sizeX; i++)
            {
                for (var j = 0; j < sizeY; j++)
                {
                    resultMatrix[i, j] = Blue[i + startX, j + startY];
                }
            }

            return resultMatrix;
        }



        public void LoadMessage(string fileName)
        {
            FileStream fileStream = File.Open(fileName, FileMode.Open, FileAccess.Read);
            var list1 = new List<byte>();
            int @byte;

            while (true)
            {
                @byte = fileStream.ReadByte();
                if (@byte == -1)
                {
                    break;
                }
                list1.Add((byte)@byte);
            }
            HiddenInformation = list1.ToArray();

            fileStream.Close();
        }

        public Bitmap ResizeImage(Bitmap image)
        {
            int x = image.Width % SizeSegment;
            int y = image.Height % SizeSegment;
            var newSize = new Size(image.Width - x, image.Height - y);
            var newImage = new Bitmap(newSize.Width, newSize.Height);

            for (var i = 0; i < newImage.Width; i++)
            {
                for (var j = 0; j < newImage.Height; j++)
                {
                    newImage.SetPixel(i, j, image.GetPixel(i, j));
                }
            }

            return newImage;
        }

        public void ChangeProgress(int value)
        {
            if (Form.InvokeRequired)
            {
                Form.Invoke((MethodInvoker)delegate { Form.ChangeProgress(value); });
            }
            else
            {
                Form.ChangeProgress(value);
            }
        }
        public void SendMessageToForm(string message)
        {
            if (Form.InvokeRequired)
            {
                Form.Invoke((MethodInvoker)delegate { Form.SendMessage(message); });
            }
            else
            {
                Form.SendMessage(message);
            }
        }
        public void SendPictureToForm(Bitmap image)
        {
            if (Form.InvokeRequired)
            {
                Form.Invoke((MethodInvoker)delegate { Form.SendPicture(image); });
            }
            else
            {
                Form.SendPicture(image);
            }
        }

        public void ChangeNameOfLabelOnForm(string text)
        {
            if (Form.InvokeRequired)
            {
                Form.Invoke((MethodInvoker)delegate { Form.ChangeNameOfLabel(text); });
            }
            else
            {
                Form.ChangeNameOfLabel(text);
            }
        }
    }
}
