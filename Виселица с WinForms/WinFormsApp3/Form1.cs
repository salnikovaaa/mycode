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
    public partial class Form1 : Form
    {
        private string[] films = { "МАТРИЦА", "АВАТАР", "МСТИТЕЛИ", "ДЖОКЕР", "СИЯНИЕ" };
        private Button[] B = new Button[10];
        int len;
        int q;
        string x;
        string bukva;
        int wrong = 0;
        int flag = 2;
        int e;


        private int rnd()
        {
            Random rng = new Random();
            int value = rng.Next(0, 4);
            return value;
        }
        public Form1()
        {
            InitializeComponent();
            int q = rnd();
            SetButtons(q);
          


        }
        private void SetButtons(int q)
        {

            x = films[q];
            len = (int)films[q].Length;
            for (int i = 0; i < len; i++)
            {
                B[i] = new Button();
                B[i].Location = new Point(625 + 33 * i, 140);
                B[i].Size = new Size(27, 29);
                this.Controls.Add(B[i]);
            }
            B[0].Text = x[0].ToString();
            B[len - 1].Text = x[len - 1].ToString();

        }


        private void button1_Click(object sender, EventArgs e)
        {
            bukva = sender.GetType().GetProperty("Text").GetValue(sender).ToString();
            Game(q);
            sender.GetType().GetProperty("Enabled").SetValue(sender, false);
        }



        private void Game(int q)
        { int position = 0;


            if (bukva == B[len - 1].Text) flag--;
            if (flag != len && wrong != 7)
            {
                if (x.IndexOf(bukva, position) != -1)
                {
                    if (x.IndexOf(bukva) == 0) position++;
                    while (x.IndexOf(bukva, position) != -1)
                    {


                        B[x.IndexOf(bukva, position)].Text = bukva;
                        flag++;
                        position = x.IndexOf(bukva, position) + 1;


                    }
                }
                else {
                    wrong++;
                }
            }

            if (wrong != 7 && flag == len)
            {
                MessageBox.Show("Win!");
                NewGame();
            }
            if (wrong == 7)
            {
                MessageBox.Show("Lose!");
                NewGame();
            }
            Kartinochka(wrong);
        }

        private void Kartinochka(int wrong)
        {
            switch (wrong)
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
        private void NewGame (){
            DialogResult res = MessageBox.Show("Начать новую игру?", "", MessageBoxButtons.YesNo,
           MessageBoxIcon.Information,
           MessageBoxDefaultButton.Button1,
           MessageBoxOptions.DefaultDesktopOnly);
            if(res == DialogResult.Yes)
            {
                this.Hide();
                Form2 form2 = new Form2();
                form2.Closed += (s, args) => this.Close();
                form2.Show();
                
             }


            }
        private void pictureBox1_Click(object sender, EventArgs e)
        {
            
        }
    }

}
