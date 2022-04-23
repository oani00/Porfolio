/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package fatec.poo.view;

import fatec.poo.model.Funcionario;
import fatec.poo.model.FuncionarioComissionado;
import fatec.poo.model.FuncionarioHorista;
import fatec.poo.model.FuncionarioMensalista;
import java.util.ArrayList;

/**
 *
 * @author Dimas
 */
public class GuiFuncionario extends javax.swing.JFrame {

    /**
     * Creates new form GuiFuncionario
     */
    public GuiFuncionario(ArrayList<Funcionario> cadFunc) {
        initComponents();
        cadastro = cadFunc;
        lblTaxaComissao.setVisible(false);
        txtTaxaComissao.setVisible(false);
        txtRegistro.requestFocus();
    }

    /**
     * This method is called from within the constructor to initialize the form.
     * WARNING: Do NOT modify this code. The content of this method is always
     * regenerated by the Form Editor.
     */
    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        jLabel1 = new javax.swing.JLabel();
        txtRegistro = new javax.swing.JTextField();
        jLabel2 = new javax.swing.JLabel();
        txtNome = new javax.swing.JTextField();
        jLabel3 = new javax.swing.JLabel();
        txtDtAdmissao = new javax.swing.JTextField();
        jLabel4 = new javax.swing.JLabel();
        txtCargo = new javax.swing.JTextField();
        btnConsultar = new javax.swing.JButton();
        btnInserir = new javax.swing.JButton();
        btnAlterar = new javax.swing.JButton();
        btnExcluir = new javax.swing.JButton();
        btnSair = new javax.swing.JButton();
        cbxTipo = new javax.swing.JComboBox<>();
        jLabel5 = new javax.swing.JLabel();
        lblRotulo = new javax.swing.JLabel();
        txtValor = new javax.swing.JTextField();
        lblTaxaComissao = new javax.swing.JLabel();
        txtTaxaComissao = new javax.swing.JTextField();

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);
        setTitle("Cadastro de Funcionário");

        jLabel1.setText("Registro");

        jLabel2.setText("Nome");

        txtNome.setEnabled(false);

        jLabel3.setText("Data de Admissão");

        txtDtAdmissao.setEnabled(false);

        jLabel4.setText("Cargo");

        txtCargo.setEnabled(false);

        btnConsultar.setIcon(new javax.swing.ImageIcon(getClass().getResource("/fatec/poo/view/icon/Consultar.png"))); // NOI18N
        btnConsultar.setText("Consultar");
        btnConsultar.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                btnConsultarActionPerformed(evt);
            }
        });

        btnInserir.setIcon(new javax.swing.ImageIcon(getClass().getResource("/fatec/poo/view/icon/Inserir.png"))); // NOI18N
        btnInserir.setText("Inserir");
        btnInserir.setEnabled(false);

        btnAlterar.setIcon(new javax.swing.ImageIcon(getClass().getResource("/fatec/poo/view/icon/Alterar.png"))); // NOI18N
        btnAlterar.setText("Alterar");
        btnAlterar.setEnabled(false);

        btnExcluir.setIcon(new javax.swing.ImageIcon(getClass().getResource("/fatec/poo/view/icon/Remover.png"))); // NOI18N
        btnExcluir.setText("Excluir");
        btnExcluir.setEnabled(false);

        btnSair.setIcon(new javax.swing.ImageIcon(getClass().getResource("/fatec/poo/view/icon/Sair.png"))); // NOI18N
        btnSair.setText("Sair");
        btnSair.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                btnSairActionPerformed(evt);
            }
        });

        cbxTipo.setModel(new javax.swing.DefaultComboBoxModel<>(new String[] { "Horista", "Mensalista", "Comissionado" }));
        cbxTipo.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                cbxTipoActionPerformed(evt);
            }
        });

        jLabel5.setText("Tipo");

        lblRotulo.setText("Valor Hora");

        txtValor.setEnabled(false);

        lblTaxaComissao.setText("Taxa de Comissão");

        txtTaxaComissao.setEnabled(false);

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(getContentPane());
        getContentPane().setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addGap(10, 10, 10)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addGroup(layout.createSequentialGroup()
                        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                            .addComponent(jLabel2)
                            .addComponent(jLabel4)
                            .addComponent(jLabel1)
                            .addComponent(jLabel5)
                            .addComponent(lblRotulo)
                            .addComponent(lblTaxaComissao))
                        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                            .addGroup(layout.createSequentialGroup()
                                .addGap(18, 18, 18)
                                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                                    .addComponent(txtNome, javax.swing.GroupLayout.PREFERRED_SIZE, 262, javax.swing.GroupLayout.PREFERRED_SIZE)
                                    .addComponent(txtRegistro, javax.swing.GroupLayout.PREFERRED_SIZE, 107, javax.swing.GroupLayout.PREFERRED_SIZE)
                                    .addComponent(cbxTipo, javax.swing.GroupLayout.PREFERRED_SIZE, 128, javax.swing.GroupLayout.PREFERRED_SIZE)))
                            .addGroup(layout.createSequentialGroup()
                                .addGap(17, 17, 17)
                                .addComponent(txtValor, javax.swing.GroupLayout.PREFERRED_SIZE, 109, javax.swing.GroupLayout.PREFERRED_SIZE))
                            .addGroup(layout.createSequentialGroup()
                                .addGap(17, 17, 17)
                                .addComponent(txtTaxaComissao, javax.swing.GroupLayout.PREFERRED_SIZE, 109, javax.swing.GroupLayout.PREFERRED_SIZE))
                            .addGroup(layout.createSequentialGroup()
                                .addGap(17, 17, 17)
                                .addComponent(txtCargo, javax.swing.GroupLayout.PREFERRED_SIZE, 109, javax.swing.GroupLayout.PREFERRED_SIZE))))
                    .addGroup(layout.createSequentialGroup()
                        .addComponent(jLabel3)
                        .addGap(18, 18, 18)
                        .addComponent(txtDtAdmissao, javax.swing.GroupLayout.PREFERRED_SIZE, 109, javax.swing.GroupLayout.PREFERRED_SIZE)))
                .addContainerGap(javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
            .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, layout.createSequentialGroup()
                .addContainerGap(javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                .addComponent(btnConsultar)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                .addComponent(btnInserir)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addComponent(btnAlterar)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addComponent(btnExcluir)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addComponent(btnSair)
                .addContainerGap())
        );

        layout.linkSize(javax.swing.SwingConstants.HORIZONTAL, new java.awt.Component[] {btnAlterar, btnConsultar, btnExcluir, btnInserir, btnSair});

        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addContainerGap()
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(cbxTipo, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(jLabel5))
                .addGap(10, 10, 10)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addGroup(layout.createSequentialGroup()
                        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                            .addComponent(jLabel1)
                            .addComponent(txtRegistro, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                        .addComponent(txtNome, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                    .addGroup(layout.createSequentialGroup()
                        .addGap(34, 34, 34)
                        .addComponent(jLabel2)))
                .addGap(12, 12, 12)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jLabel3)
                    .addComponent(txtDtAdmissao, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jLabel4)
                    .addComponent(txtCargo, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(lblRotulo)
                    .addComponent(txtValor, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(lblTaxaComissao)
                    .addComponent(txtTaxaComissao, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED, 31, Short.MAX_VALUE)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(btnConsultar)
                    .addComponent(btnInserir)
                    .addComponent(btnAlterar)
                    .addComponent(btnExcluir)
                    .addComponent(btnSair))
                .addContainerGap())
        );

        layout.linkSize(javax.swing.SwingConstants.VERTICAL, new java.awt.Component[] {btnAlterar, btnConsultar, btnExcluir, btnInserir, btnSair});

        pack();
    }// </editor-fold>//GEN-END:initComponents

    private void btnConsultarActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_btnConsultarActionPerformed
        int x;
        for (x = 0; x < cadastro.size(); x++){
            if (cadastro.get(x).getRegistro() == Integer.parseInt(txtRegistro.getText())){
                if (cbxTipo.getSelectedIndex() == 0 && 
                    cadastro.get(x) instanceof FuncionarioHorista){                       
                    break;
                }else
                  if (cbxTipo.getSelectedIndex() == 1 && 
                      cadastro.get(x) instanceof FuncionarioMensalista){                      
                      break; 
                  }else 
                      if (cbxTipo.getSelectedIndex() == 2 && 
                          cadastro.get(x) instanceof FuncionarioComissionado){
                          break; 
                  } 
            }
        }

        if (x < cadastro.size()){
            posFunc = x; //localizou o objeto Funcionario (horista, mensalista ou comissionado) no ArrayList
        }else{
            posFunc = -1;//não localizou o objeto Projeto no ArrayList
        }

        if (posFunc >= 0){
            txtNome.setText(cadastro.get(posFunc).getNome());
            txtDtAdmissao.setText(cadastro.get(posFunc).getDtAdmissao()); 
            txtCargo.setText(cadastro.get(posFunc).getCargo());
            if (cbxTipo.getSelectedIndex() == 0){
                txtValor.setText(String.valueOf(((FuncionarioHorista)cadastro.get(posFunc)).getValHorTrab()));
            }else
               if (cbxTipo.getSelectedIndex() == 1){
                  txtValor.setText(String.valueOf(((FuncionarioMensalista)cadastro.get(posFunc)).getValSalMin()));
               }else{                  
                  txtValor.setText(String.valueOf(((FuncionarioComissionado)cadastro.get(posFunc)).getSalBase()));
                  txtTaxaComissao.setText(String.valueOf(((FuncionarioComissionado)cadastro.get(posFunc)).getTaxaComissao()));
               } 
            btnConsultar.setEnabled(false);
            btnInserir.setEnabled(false);
            btnAlterar.setEnabled(true);
            btnExcluir.setEnabled(true);
        }else{
            btnConsultar.setEnabled(false);
            btnInserir.setEnabled(true);
            btnAlterar.setEnabled(false);
            btnExcluir.setEnabled(false);
            txtNome.requestFocus();
        }
        cbxTipo.setEnabled(false);
        txtRegistro.setEnabled(false);
        txtNome.setEnabled(true);
        txtDtAdmissao.setEnabled(true);
        txtCargo.setEnabled(true);
        txtValor.setEnabled(true);
        if (cbxTipo.getSelectedIndex() == 2){
            txtTaxaComissao.setEnabled(true);
        }
    }//GEN-LAST:event_btnConsultarActionPerformed

    private void btnSairActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_btnSairActionPerformed
        dispose();
    }//GEN-LAST:event_btnSairActionPerformed

    private void cbxTipoActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_cbxTipoActionPerformed
        if (cbxTipo.getSelectedIndex() == 0){
            lblRotulo.setText("Valor Hora");
            lblTaxaComissao.setVisible(false);
            txtTaxaComissao.setVisible(false);
        }else
           if (cbxTipo.getSelectedIndex() == 1){
               lblRotulo.setText("Salário Mínimo");
               lblTaxaComissao.setVisible(false);
               txtTaxaComissao.setVisible(false);
           }else{
               lblRotulo.setText("Salário Base");
               lblTaxaComissao.setVisible(true);
               txtTaxaComissao.setVisible(true); 
           } 
           txtRegistro.requestFocus();
    }//GEN-LAST:event_cbxTipoActionPerformed

   
    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JButton btnAlterar;
    private javax.swing.JButton btnConsultar;
    private javax.swing.JButton btnExcluir;
    private javax.swing.JButton btnInserir;
    private javax.swing.JButton btnSair;
    private javax.swing.JComboBox<String> cbxTipo;
    private javax.swing.JLabel jLabel1;
    private javax.swing.JLabel jLabel2;
    private javax.swing.JLabel jLabel3;
    private javax.swing.JLabel jLabel4;
    private javax.swing.JLabel jLabel5;
    private javax.swing.JLabel lblRotulo;
    private javax.swing.JLabel lblTaxaComissao;
    private javax.swing.JTextField txtCargo;
    private javax.swing.JTextField txtDtAdmissao;
    private javax.swing.JTextField txtNome;
    private javax.swing.JTextField txtRegistro;
    private javax.swing.JTextField txtTaxaComissao;
    private javax.swing.JTextField txtValor;
    // End of variables declaration//GEN-END:variables
    private ArrayList<Funcionario> cadastro;
    private int posFunc;
}
