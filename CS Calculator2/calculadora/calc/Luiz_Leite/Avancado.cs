using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO;

namespace Luiz_Leite
{
    public partial class Avancado : MetroFramework.Forms.MetroForm
    {
        private int contador;
        private int nvolta = 0;
        private string[] caminho; // criando um vetor de strings para guardar os caminhos das imagens selecionadas peo usuário
        private int contador2;
        public Avancado()
        {
            InitializeComponent();
        }

        private void btnHOME_Click(object sender, EventArgs e)
        {
            // caso clique nesse botão , o usuário será direcionado para o formulário da tela inicial( que será criada abaixo)
            TelaInicial Inicio = new TelaInicial();
            Inicio.Show();
            this.Hide();
        }

        private void Avancado_Load(object sender, EventArgs e)
        {
            Ttempo.Enabled = false; // quando inicializar, o timer do cronograma estará desativado
        }

        private void btninicio_Click(object sender, EventArgs e)
        {
            Ttempo.Enabled = true;// o timer do cronograma só será ativado ao clicar nesse botão
            
        }

        private void Ttempo_Tick(object sender, EventArgs e)
        {
            // a cada tick do timer, o cronograma incrementará um ao contador e exibirá o atual valor ao usuário por meio de um label
            contador++;
            lblcronograma.Text = contador.ToString();
        }

        private void btnpausar_Click(object sender, EventArgs e)
        {
            // caso o usuáio clique nesse botão , o timer se pausado e por consequência o cronograma tambem
            if (Ttempo.Enabled == true)
            {
                Ttempo.Enabled = false;
            }
            else
            {
                Ttempo.Enabled = true;
            }
        }

        private void btnvolta_Click(object sender, EventArgs e)
        {
            // caso o usuário clique nesse botão, uma variável guardará o tempo registrado e exibirá esta volta em um richTextBox
            nvolta++;
            int volta = contador;
          
            RTBvoltas.Text += "- Volta "+nvolta+"-Tempo: "+volta+" segundos\n";
        }

        private void btnzerar_Click(object sender, EventArgs e)
        {
            // caso o usuário zere o cronograma, será exibida uma tela para ele perguntando se o mesmo deseja salvar o histórico de voltas caso sim um arquivo txt será gerado e tudo será zerado, caso não tudo será zerado sem qualquer salvamento
            Ttempo.Enabled = false;
            DialogResult resposta = MessageBox.Show("Deseja salvar o histórico de voltas?","Confirmação",MessageBoxButtons.YesNo,MessageBoxIcon.Question);
            if (resposta == DialogResult.Yes)
            {
                DialogResult salvar = SFDtempo.ShowDialog();
                if (salvar == DialogResult.OK)
                {
                    string caminho = SFDtempo.FileName;
                    File.WriteAllLines(caminho, RTBvoltas.Lines);
                    MessageBox.Show("Arquivo salvo com sucesso!");
                    contador = 0;
                    Ttempo.Enabled = false;
                    RTBvoltas.Clear();
                    lblcronograma.Text = "-";
                    nvolta = 0; 

                }
            }
            else
            {
                contador = 0;
                Ttempo.Enabled = false;
                RTBvoltas.Clear();
                lblcronograma.Text = "-";
                nvolta = 0; 

            }
        }

        private void btnescolher_Click(object sender, EventArgs e)
        {
            // caso o usuário clique nesse botão , ele poderá escolher um conjunto de imagens para exibição em um pictureBox
            DialogResult resposta = OFDimagens.ShowDialog();
            if (resposta == DialogResult.OK)
            {
                caminho = OFDimagens.FileNames; // guardando o camingo das imagens em um vetor
                PBslide.Image = Image.FromFile(caminho[0]);
                btniniciar.Enabled = true;
                btnparar.Enabled = true;
                CBintervalo.Enabled = true;
                CBintervalo.SelectedIndex = 0;
            }
        }

        private void btniniciar_Click(object sender, EventArgs e)
        {
            // ao clicar em iniciar, o timer será inicializado
            Timagens.Enabled = true;
            btniniciar.BackColor = Color.FromArgb(0,64,64);
            btnparar.BackColor = Color.FromArgb(0,192,192);
        }

        private void Timagens_Tick(object sender, EventArgs e)
        {
            int intervalo = CBintervalo.SelectedIndex;
            Timagens.Interval = 1000 * (intervalo + 1);
            if (contador2 == caminho.Length)
            {
                // caso o contador esteja com um valor igual ao numero de indices dento do vetor, ele será zerado
                contador2 = 0;
            }
            PBslide.Image = Image.FromFile(caminho[contador2]); // um contador será criado para que a cada tick do timer, um indice do vetor será escolhido, assim as imagens serão passadas
            contador2++;// o contador será incrementado a cada tick do timer
        }

        private void btnparar_Click(object sender, EventArgs e)
        {
            // caso o usuário clique nesse botão , os slides serão pausados
            btniniciar.BackColor = Color.FromArgb(0,192,192);   
            if (Timagens.Enabled == true)
            {
                btnparar.BackColor = Color.FromArgb(0,64,64);
                Timagens.Enabled = false;
            }
            else
            {
                Timagens.Enabled = true;
                btnparar.BackColor = Color.FromArgb(0,192,192);

            }
        }

        private void CBintervalo_SelectedIndexChanged(object sender, EventArgs e)
        {
            // caso o indice do ComboBox mude, uma variavel irá guardar esse novo indice e o multiplicará pelo intervalo do timer, para que a velocidade escolhida pelo usuário seja correspondida
            int intervalo = CBintervalo.SelectedIndex;
            Timagens.Interval = 1000 * (intervalo + 1);
        } 

    }
}
