using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using Microsoft.VisualBasic;

namespace P0030482011028
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void btnVerificar_Click(object sender, EventArgs e)
        {
            
            //OK -crie uma matriz 8 x 4
            
            int linha = 8;
            int coluna = 4;

            double[,] matriz = new double[linha, coluna];

            lbResultado.Items.Clear();
            double[] TotalMes = new double[linha];
            double TotalGeral = 0;

            //Utilizar InputBox para a entrada de dados.
            for (var i = 0; i < linha; i++)
            {
                TotalMes[i] = 0;
                for (var j = 0; j < coluna; j++)
                {
                    if (double.TryParse(Interaction.InputBox($"Insira o valor da venda da semana {j + 1} do mes {i + 1} por favor: ", "Entrada de dados"), out matriz[i, j]))
                    {
                        //Total vendido em cada semana de cada mês;
                        lbResultado.Items.Add($"Mes {i + 1}, Semana {j + 1}: {matriz[i, j].ToString("c2")}\n");
                        TotalMes[i] += matriz[i, j];
                    }
                    else
                    {
                        MessageBox.Show("Insira Valores Númericos validos por favor!");
                    }
                }
                
                //Total vendido em cada mês;
                lbResultado.Items.Add($">> Total Mês: {i + 1}: {TotalMes[i].ToString("c2")}\n");
                lbResultado.Items.Add("------------------");

                TotalGeral += TotalMes[i];
            }
            int x = 0;

           //OK Total Geral vendido em todos os meses.
            lbResultado.Items.Add($"\n>> Total Geral: {TotalGeral.ToString("c2")}");

            //  Os valores só podem ser numéricos.

            //Valores devem ser mostrados NO FORMATO MOEDA e com 2(duas) casas decimais.

            ///////////////////////////////////////////////////////////////////////////////////
            ////Professora, no meu aparece em $ acho que por que meu sistema está em ingles////
            ///////////////////////////////////////////////////////////////////////////////////
            
            // Utilizar normalização para os nomes dos componentes e variáveis.

        }
    }
}
