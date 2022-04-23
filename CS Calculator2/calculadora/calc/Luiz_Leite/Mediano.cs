using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO; // biblioteca que permite manipular pastas( e seus caminhos) e arquivos do computador
using MetroFramework.Controls; // biblioteca que permite manipular os componentes do metro framework

namespace Luiz_Leite
{
    public partial class Mediano : MetroFramework.Forms.MetroForm // usando o metroform 
    {
        private int contador;
        private string caminho = Application.StartupPath; // criando um atributo para guardar o caminho do executavel do programa, para manipula-lo depois
        private string cam;
        private string genero;
        public Mediano()
        {
            InitializeComponent();
        }

        private void Timagem_Tick(object sender, EventArgs e)
        {
            if (contador == 5)
            {
                contador = 0; // caso o contador seja 5, ele será zerado para que as imagens do slide continuem em constante repetição
            }
            cam = Path.GetFullPath(Path.Combine(caminho,@"..\..\"));// manipulando o caminho do executavel para voltar dois niveis, para que seja possivel acessar a pasta das imagens para o slide
            PB.Image = Image.FromFile(cam + @"Resources\slide" + (contador + 1) + ".jpg"); // atribuindo o caminho certo para a pasta onde esta as imagens e concatenando o contador para que a cada tick do timer ele use uma imagem correspondente
            contador++; // incrementando o contador
            
          
        }

        private void Mediano_Load(object sender, EventArgs e)
        {
            // deixando os valores padrões para inicialização do formulário
            CBestado.SelectedIndex = 0;
            btncalcular.Enabled = false;
            contador = 1;
            cam = Path.GetFullPath(Path.Combine(caminho,@"..\..\"));
            Timagem.Enabled = true;
            PB.Image = Image.FromFile(cam+@"Resources\slide"+contador+".jpg");
            
        }
        public void BotaoPressionado(Button botao,RichTextBox campo)
        {
            // método criado para pegar os valores dos botões da calculadora e atribui-los ao richTextBox 
            if (campo.Text == "")
            {
                CBoperacao.Enabled = true;
            }
            double valor;
            valor = double.Parse(botao.Text);
            campo.Text += valor.ToString();
        }

        private void btn1_Click(object sender, EventArgs e)
        {
            BotaoPressionado((Button)sender, RTBresultado); // usando o método para cada clique de um botão da calculadora
        }

        private void CBoperacao_SelectedIndexChanged(object sender, EventArgs e)
        {
            // indicando um operador matematico de acordo com um indice escolhido no comboBox
            if (CBoperacao.SelectedIndex == 0)
            {
                RTBresultado.Text += "*";
            }
            else if (CBoperacao.SelectedIndex == 1)
            {
                RTBresultado.Text += "/";
            }
            else if (CBoperacao.SelectedIndex == 2)
            {
                RTBresultado.Text += "+";
            }
            else if (CBoperacao.SelectedIndex == 3)
            {
                RTBresultado.Text += "-";
            }
            CBoperacao.Enabled = false; // desabilitando o comboBox depois de um operador ser definido para a operação
            btncalcular.Enabled = true; // logo após a escolha do operador será possível usar o botão calcular
        }

        private void btncalcular_Click(object sender, EventArgs e)
        {
            try
            {
                string operacaoMAT;
                int posicao = 0;
                //verificando abaixo o operador contido na sentença, o operador verificado será guardado sua posição dentro de uma variável
                if (RTBresultado.Text.Contains("+"))
                {
                    posicao = RTBresultado.Text.IndexOf("+");
                }
                else if (RTBresultado.Text.Contains("-"))
                {
                    posicao = RTBresultado.Text.IndexOf("-");
                }
                else if (RTBresultado.Text.Contains("*"))
                {
                    posicao = RTBresultado.Text.IndexOf("*");
                }
                else if (RTBresultado.Text.Contains("/"))
                {
                    posicao = RTBresultado.Text.IndexOf("/");
                }

                operacaoMAT = RTBresultado.Text.Substring(posicao, 1); // usando sua posição, agora será o operador que será guardado dentro de uma variavel
                double op1 = double.Parse(RTBresultado.Text.Substring(0, posicao));// pegando o primeiro numero antes do operador
                double op2 = double.Parse(RTBresultado.Text.Substring(posicao + 1, RTBresultado.Text.Length - posicao - 1)); //pegando o segundo numero apos o operador

                // verificando qual operador guardado na variavel e aplicando sua devida operação
                if (operacaoMAT == "+")
                {
                    RTBresultado.Text += "=" + (op1 + op2);
                }
                else if (operacaoMAT == "-")
                {
                    RTBresultado.Text += "=" + (op1 - op2);
                }
                else if (operacaoMAT == "*")
                {
                    RTBresultado.Text += "=" + (op1 * op2);
                }
                else
                {
                    if (op2 == 0)
                    {
                        // caso o denominadr da divisão for zero será exibida a imagem a seguir
                        RTBresultado.Text += "= Não é possível dividir um número por zero!";
                    }
                    else
                    {

                        RTBresultado.Text += "=" + (op1 / op2);
                    }
                }
            }
            catch (Exception erro)
            {

                MessageBox.Show("Insira do números corretamente\nErro :"+erro.Message);
            }
            
        }

        private void btnlimpar_Click(object sender, EventArgs e)
        {
            // limpando o richTextBox
            RTBresultado.Clear();
        }

        private void btnapagar_Click(object sender, EventArgs e)
        {
            // removendo apenas um caractere
            if (RTBresultado.Text != "")
            {
                RTBresultado.Text = RTBresultado.Text.Remove(RTBresultado.TextLength - 1);
            }     
        }

        private void btnHOME_Click(object sender, EventArgs e)
        {
            TelaInicial tela = new TelaInicial();
            tela.Show();
            this.Hide();
        }

        private void iconButton1_Click(object sender, EventArgs e)
        {
            //exibindo os termos de uso para o usuário
            MessageBox.Show("Termos de uso");
            
        }
        private void RBmasculino_Click(object sender, EventArgs e)
        {
            // verificando se o usuário clicou no radiobutton masculino
            RBfeminino.Checked = false;
            genero = "Masculino";
        }

        private void RBfeminino_Click(object sender, EventArgs e)
        {
            //verificando se o usuário clicou no radiobutton feminino
            RBmasculino.Checked = false;
            genero = "Feminino";
        }
        private void checksim_Click(object sender, EventArgs e)
        {
            checksim.CheckState = CheckState.Checked;
        }

        private void btnenviar_Click(object sender, EventArgs e)
        {
            try
            {
                // pegando os dados digitados pelo usuário e usando o método para verificar a autenticidade dos mesmos
                VerificarCampos(txtnome);
                VerificarCampos(txtemail);
                VerificarCampos(txtsalario);
                VerificarCampos(txtcpf);
                VerificarCampos(txtemail);
                VerificarCampos(txttelefone);
                VerificarCampos(CBestado);
                VerificarCampos(txtcidade);
                if (RBmasculino.Checked == false && RBfeminino.Checked == false)
                {
                    Epmediano.SetError(RBfeminino, "Escolha uma das opções");// setando os erros caso falte a marcação dos radio buttons
                }
                else
                {
                    Epmediano.SetError(RBfeminino, "");
                }
                if (checksim.Checked == false)
                {
                    Epmediano.SetError(checksim, "Aceite os termos para continuar"); // setando erro para o usuário que não aceitou os termos
                }
                else
                {
                    //concatenando e exibindo as informações caso o usuário preencha todos os campos corretamente, serão exibidos no richtextBox
                    Epmediano.SetError(checksim, "");
                    if (Epmediano.GetError(txtnome) == "" && Epmediano.GetError(RBfeminino) == "" && Epmediano.GetError(txtemail) == "" && Epmediano.GetError(txtcpf) == "" && Epmediano.GetError(txttelefone) == "" && Epmediano.GetError(CBestado) == "" && Epmediano.GetError(txtcidade) == "" && Epmediano.GetError(txtsalario) == "" && Epmediano.GetError(checksim) == "")
                    {
                        string salario = txtsalario.Text;
                        RTBexibir.Text = "Nome :" + txtnome.Text + "\nSexo :" + genero + "\nE-mail : " + txtemail.Text + "\nCPF: " + txtcpf.Text + "\nTelefone :" + txttelefone.Text + "\nEstado :" + CBestado.SelectedIndex + "\nCidade : " + txtcidade.Text + "\nSalário :" + salario + "\nTermos : Aceito";
                    }
                    else
                    {
                        MessageBox.Show("Preencha todos os campos!"); // caso algum dos campos esteja errado será exbido ao usuário esta mensagem
                    }
                }
            }
            catch (Exception erro)
            {

                MessageBox.Show("Erro: "+erro.Message,"Erro",MessageBoxButtons.OK,MessageBoxIcon.Error);
                
            }
            

            
        }
        public void VerificarCampos(MetroTextBox txt)
        {
            // método criado para verificar os dados do usuário dentro do componente MetroTextBox, caso haja erros será exibido um aviso pelo ErrorProvider
            string text = txt.Text;
            if (String.IsNullOrWhiteSpace(text))
            {
                Epmediano.SetError(txt,"Preencha o campo Corretamente");
            }
            else
            {
                Epmediano.SetError(txt, "");
            }
        }
        public void VerificarCampos(MaskedTextBox txt)
        {
            // método criado para verificar os dados do usuário dentro do componente MaskedTextBox, caso haja erros será exibido um aviso pelo ErrorProvider
            string text = txt.Text;
            if (String.IsNullOrWhiteSpace(text))
            {
                Epmediano.SetError(txt, "Preencha o campo Corretamente");
            }
            else
            {
                Epmediano.SetError(txt, "");
            }
        }
        public void VerificarCampos(ComboBox txt)
        {
            // método criado para verificar os dados do usuário dentro do componente ComboBox, caso haja erros será exibido um aviso pelo ErrorProvider
            string text = txt.Text;
            if (text == "Selecione seu estado")
            {
                Epmediano.SetError(txt, "Selecione um estado !");
            }
            else
            {
                Epmediano.SetError(txt, "");
            }
        }

        private void txtsalario_Leave(object sender, EventArgs e)
        {
            // caso o usuário deixe o campo salário, será aplicada uma formatação monetária em cima do mesmo
            try
            {
                double salario = double.Parse(txtsalario.Text);
                txtsalario.Text = salario.ToString("c2");
            }
            catch (Exception erro)
            {

                MessageBox.Show("Erro: "+erro.Message,"Erro",MessageBoxButtons.OK,MessageBoxIcon.Error);
            }
            
        }

        private void txtsalario_Enter(object sender, EventArgs e)
        {
            // caso o usuário entr no componente salário, será removida a formatação monetária
            string formatar = txtsalario.Text;
            string remover = formatar.Replace("R$","");
            txtsalario.Text = remover;

        }

        private void btnCF_Click(object sender, EventArgs e)
        {
            // será exibido um painel para mudar a cor de fundo caso o usuário clique nesse botão
            DialogResult resposta = CDrtbexibir.ShowDialog();
            if (resposta == DialogResult.OK)
            {
                RTBexibir.BackColor = CDrtbexibir.Color;
            }
        }

        private void btncorFonte_Click(object sender, EventArgs e)
        {
            // será exibido uma tela para mudar a cor da fonte caso o usuário clique nesse botão
            DialogResult resposta = CDrtbexibir.ShowDialog();
            if (resposta == DialogResult.OK)
            {
                RTBexibir.ForeColor = CDrtbexibir.Color;
            }
        }

        private void btnFonte_Click(object sender, EventArgs e)
        {
            // será exibido uma tela para alterar a fonte quando o usuário clicar nesse botão
            DialogResult resposta = FDrtbexibir.ShowDialog();
            if (resposta == DialogResult.OK)
            {
                RTBexibir.Font = FDrtbexibir.Font;
            }
        }

    }
}
