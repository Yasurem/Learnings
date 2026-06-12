import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import javax.swing.text.*;


public class Student {
    private JFrame frame;
    
    JPanel pnlCenter, pnlSouth;
    
    String[] txtLabels = {"NAME: ", "MOBILE NUMBER: ","BIRTHDAY: ", "EMAIL ",
                          "CONFIRM EMAIL: ", "PASSWORD", "CONFIRM PASSWORD: ", 
                          "COURSE: ", "SEMESTER"};
    
    // Top
    private JLabel lbHeader;
    
    // Center
    JPanel pnlLeft, pnlRight;
    
    private JLabel[] lbLeft = new JLabel[txtLabels.length];
    private JFormattedTextField[] tfInfo = new JFormattedTextField[5];
    
    String[] txtCourse = {"BSCS", "BSIT", "BSIS"};
    private JComboBox<String> cbCourse;
    private JPasswordField pfPassword, pfConfirm;
    
    ButtonGroup btnGroup;
    JRadioButton rbSem1, rbSem2;
    
    // Bottom
    JTextArea taDisplay;
    String[] txtButton = {"btnADD", "btnRESET", "btnCLEAR"};
    JButton btnAdd, btnReset, btnClear;
    
    
    public Student() throws Exception  {
        frame = new JFrame("Student Form");
        frame.setLayout(new BorderLayout());
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        
        // Top
        lbHeader = new JLabel("ACCOUNT REGISTER");
        lbHeader.setHorizontalAlignment(0);
        
        // Center
        pnlCenter = createCenterPanel();
        pnlSouth = createSouthPanel();
        
        method();
        
        frame.pack();
        frame.setVisible(true);
    }

    private void method() {
        frame.add(lbHeader, BorderLayout.NORTH);
        frame.add(pnlCenter, BorderLayout.CENTER);
        frame.add(pnlSouth, BorderLayout.SOUTH);
    }
    
    private JPanel createCenterPanel() throws Exception {
        JPanel panel = new JPanel();
        panel.setLayout(new BorderLayout());
        
        // Left panel
        JPanel pnlLeft = new JPanel();
        pnlLeft.setLayout(new GridLayout(9, 1));
        for (int i = 0; i < txtLabels.length; i++) {
            lbLeft[i] = new JLabel(txtLabels[i]);
            pnlLeft.add(lbLeft[i]);
        }
       
        // Right panels
        JPanel pnlRight = new JPanel();
        pnlRight.setLayout(new GridLayout(9, 1));
        for(int i = 0; i < 5; i++) {
            tfInfo[i] = new JFormattedTextField();

            pnlRight.add(tfInfo[i]);
        }
        
        
        tfInfo[1].setFormatterFactory(new DefaultFormatterFactory(new MaskFormatter("###########")));
        tfInfo[2].setFormatterFactory(new DefaultFormatterFactory(new MaskFormatter("###-###-##")));
        
        pfPassword = new JPasswordField(15);
        pfConfirm = new JPasswordField(15);
        
        pnlRight.add(pfPassword);
        pnlRight.add(pfConfirm);
        
        cbCourse = new JComboBox<>(txtCourse);
        pnlRight.add(cbCourse);
        
        JPanel pnlRadio = new JPanel();
        
        btnGroup = new ButtonGroup();
        rbSem1 = new JRadioButton("1st Semester");
        rbSem2 = new JRadioButton("2nd Semester");
        
        btnGroup.add(rbSem1);
        btnGroup.add(rbSem2);
        
        pnlRadio.add(rbSem1);
        pnlRadio.add(rbSem2);
        
        pnlRight.add(pnlRadio);
        
        panel.add(pnlLeft, BorderLayout.WEST);
        panel.add(pnlRight, BorderLayout.CENTER);
        
        return panel;
    }
    
    private JPanel createSouthPanel() throws Exception {
        JPanel panel = new JPanel();
        panel.setLayout(new BorderLayout());
        
        taDisplay = new JTextArea(2, 50);
        taDisplay.setEditable(false);
        
        JPanel pnlButton = new JPanel();
        
        btnAdd = new JButton("btnADD");
        btnReset = new JButton("btnRESET");
        btnClear = new JButton("btnCLEAR");
        
        btnAdd.addActionListener(e -> {
            String pw1 = new String(pfPassword.getPassword());
            String pw2 = new String(pfConfirm.getPassword());
            
            if((tfInfo[3].getText().endsWith("@gmail.com")|| 
               tfInfo[3].getText().endsWith("@yahoo.com"))&&
               tfInfo[4].getText().equals(tfInfo[3].getText())&&
               pw1.equals(pw2) && (rbSem1.isSelected() || rbSem2.isSelected())){
                taDisplay.setEditable(true);
                
                taDisplay.append(tfInfo[0].getText() + " - " + cbCourse.getSelectedItem() + "\n");

            }
        });
        
        btnReset.addActionListener(e -> {
            for(JFormattedTextField tf : tfInfo) {
                tf.setValue(null);
            }

            pfPassword.setText("");
            pfConfirm.setText("");
            btnGroup.clearSelection();
        });
        
        pnlButton.add(btnAdd);
        pnlButton.add(btnReset);
        pnlButton.add(btnClear);
        
        panel.add(taDisplay, BorderLayout.CENTER);
        panel.add(pnlButton, BorderLayout.SOUTH);
        
        return panel;
    }
    
    public static void main(String args[]) throws Exception {
        SwingUtilities.invokeLater(() -> {
        try {
            new Student();
        } catch (Exception e) {
            e.printStackTrace();
        }
        });
    }
}
