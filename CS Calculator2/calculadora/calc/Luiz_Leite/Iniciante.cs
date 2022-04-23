using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Luiz_Leite
{
    public partial class Iniciante : MetroFramework.Forms.MetroForm
    {
        public Iniciante()
        {
            InitializeComponent();
        }

        private void Iniciante_Load(object sender, EventArgs e)
        {

        }

        private void btncalcular_Click(object sender, EventArgs e)
        {
            try // try catch é usado para tratamento de excessoes
            {
                double espaco, tempo;
                espaco = double.Parse(txtespaco.Text); // pegando valor do campo espaço
                tempo = double.Parse(txttempo.Text); // pegando valor do campo tempo
                double resultado = espaco / tempo; // calculando a velocidade media de acordo com os valores recebidos
                lblresultado.Text = "VM = " + resultado + " (m/s)"; // exibindo o resultado para o usuário
            }
            catch (Exception erro) // caso dê algum tipo de erro , o catch irá guardar este numa variável 
            {

                MessageBox.Show("Erro : " + erro.Message, "Erro", MessageBoxButtons.OK, MessageBoxIcon.Error); // exibindo o erro capturado para o usuário
            }
            
        }

        private void btnlimpar_Click(object sender, EventArgs e)
        {
            // ao clicar no botão limpar, todos os textboxes serão limpos e o label de exibição do resultado terá seu valor removido tambem
            txtespaco.Clear();
            txttempo.Clear();
            lblresultado.Text = "VM = ";
        }

        private void btnsomatoria_Click(object sender, EventArgs e)
        {
            try
            {

                double n;
                n = double.Parse(txtsoma.Text); // pegando o valor digitado pelo usuário no campo da somatória
                double resultado = (n + 1) * n / 2; // usando a formula do calculo da somatoria
                lblsoma.Text = "Somatória = " + resultado; //exibindo o resultado da somatoria para o usuário
            }
            catch (Exception erro)
            {
                MessageBox.Show("Erro : "+erro.Message, "Erro", MessageBoxButtons.OK, MessageBoxIcon.Error); // caso de algum erro, este será exibindo em um message box para o usuario
            }
        }

        private void iconButton1_Click(object sender, EventArgs e)
        {
            txtsoma.Clear();
            lblsoma.Text = "Somatória =";
        }

        private void btnHOME_Click(object sender, EventArgs e)
        {
            // caso o botão home ou o formulário atual seja fechado, será criado um outro formulário telainicial
            TelaInicial frmtelaI = new TelaInicial(); 
            frmtelaI.Show();
            this.Hide();

        }
    }
}
