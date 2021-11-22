using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;


namespace WinFormsApp3
{
    public partial class Form2 : Form
    {
        private string[] films1 = { "МАТРИЦА", "АВАТАР", "МСТИТЕЛИ", "ДЖОКЕР", "СИЯНИЕ" };
        private Button[] B1 = new Button[10];
        int len1;
        int q1;
        string x1;
        string bukva1;
        int wrong1 = 0;
        int flag1 = 2;
        int e1;


        private int rnd1()
        {
            Random rng = new Random();
            int value = rng.Next(0, 4);
            return value;
        }
        public Form2()
        {
            InitializeComponent();
            int q = rnd1();
            SetButtons(q1);



        }
        private void SetButtons(int q1)
        {

            x1 = films1[q1];
            len1 = (int)films1[q1].Length;
            for (int i = 0; i < len1; i++)
            {
                B1[i] = new Button();
                B1[i].Location = new Point(625 + 33 * i, 140);
                B1[i].Size = new Size(27, 29);
                this.Controls.Add(B1[i]);
            }
            B1[0].Text = x1[0].ToString();
            B1[len1 - 1].Text = x1[len1 - 1].ToString();

        }


        private void button1_Click(object sender, EventArgs e)
        {
            bukva1 = sender.GetType().GetProperty("Text").GetValue(sender).ToString();
            Game(q1);
            sender.GetType().GetProperty("Enabled").SetValue(sender, false);
        }



        private void Game(int q)
        {
            int position = 0;


            if (bukva1 == B1[len1 - 1].Text) flag1--;
            if (flag1 != len1 && wrong1 != 7)
            {
                if (x1.IndexOf(bukva1, position) != -1)
                {
                    if (x1.IndexOf(bukva1) == 0) position++;
                    while (x1.IndexOf(bukva1, position) != -1)
                    {


                        B1[x1.IndexOf(bukva1, position)].Text = bukva1;
                        flag1++;
                        position = x1.IndexOf(bukva1, position) + 1;


                    }
                }
                else
                {
                    wrong1++;
                }
            }

            if (wrong1 != 7 && flag1 == len1)
            {
                MessageBox.Show("Win!");
                NewGame();
            }
            if (wrong1 == 7)
            {
                MessageBox.Show("Lose!");
                  NewGame();
            }
            Kartinochka(wrong1);
        }

          private void Kartinochka(int wrong1)
          {
              switch (wrong1)
              {

                  case 1:
                      Bitmap image1 = new Bitmap(Environment.CurrentDirectory + "//1.jpg");
                      pictureBox1.Image = image1;
                      break;
                  case 2:
                      image1 = new Bitmap(Environment.CurrentDirectory + "//2.jpg");

                      pictureBox1.Image = image1;
                      break;
                  case 3:
                      image1 = new Bitmap(Environment.CurrentDirectory + "//3.jpg");

                      pictureBox1.Image = image1;
                      break;
                  case 4:
                      image1 = new Bitmap(Environment.CurrentDirectory + "//4.jpg");

                      pictureBox1.Image = image1;
                      break;
                  case 5:
                      image1 = new Bitmap(Environment.CurrentDirectory + "//5.jpg");

                      pictureBox1.Image = image1;
                      break;
                  case 6:
                      image1 = new Bitmap(Environment.CurrentDirectory + "//6.jpg");

                      pictureBox1.Image = image1;
                      break;
                  case 7:
                      image1 = new Bitmap(Environment.CurrentDirectory + "//7.jpg");

                      pictureBox1.Image = image1;
                      break;

              }

    }
        private void NewGame()
        {
            DialogResult res = MessageBox.Show("Начать новую игру?", "", MessageBoxButtons.YesNo,
           MessageBoxIcon.Information,
           MessageBoxDefaultButton.Button1,
           MessageBoxOptions.DefaultDesktopOnly);
            if (res == DialogResult.Yes)
            {
                this.Hide();
                Form1 form1 = new Form1();
                form1.Closed += (s, args) => this.Close();
                form1.Show();
            }


        }
     
    }

}