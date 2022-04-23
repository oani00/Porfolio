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
    public partial class TelaInicial : MetroFramework.Forms.MetroForm
    {
        public TelaInicial()
        {
            InitializeComponent();
        }
        private void button1_Click(object sender, EventArgs e)
        {
            Iniciante form2 = new Iniciante(); // ao clicar no botão iniciante , criará um formulário e esconderá o formulario de origem
            this.Hide();
            form2.Show(); // exibindo o formulário iniciante
            
        }

        private void button2_Click(object sender, EventArgs e)
        {
            Mediano form3 = new Mediano(); // ao clicar no botão mediano , criará um formulário e esconderá o formulario de origem
            this.Hide();
            form3.Show(); // exibindo o formulário mediano
            
        }

        private void TelaInicial_FormClosed(object sender, FormClosedEventArgs e)
        {
            Application.Exit(); //quando clicado , o botão de saída fechará o aplicativo(projeto)
        }

        private void btnavançado_Click(object sender, EventArgs e)
        {
            Avancado form4 = new Avancado();// ao clicar no botão avançado , criará um formulário e esconderá o formulario de origem
            this.Hide();
            form4.Show();//exibindo o formulário avançado
        }

        private void btnsobre_Click(object sender, EventArgs e)
        {
            TelaSobre sobre = new TelaSobre(); // criando a tela sobre´para ser exibida ao clique sobre o botao
            sobre.ShowDialog();
        }

        
    }
}
