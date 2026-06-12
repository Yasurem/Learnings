import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import javax.swing.text.*;

public class Speed {
    JFrame frame;
    JLabel lbNorth;
    
    JPanel pnlCenter, pnlWest, pnlEast, pnlSouth;
    JLabel[] lbText = new JLabel[9];
    String[] txtLabels = {"NAME","NUMBER","BDAY","EMAIL","CONFIRM EMAIL","PASSWORD","CONFIRM PASSWORD","COURSE","SEMESTER"};
    
    JFormattedTextField[] ftfText = new JFormattedTextField[5];
    JPasswordField pfPassword;
    JPasswordField pfConfirm;
    
    String[] txtCombo = {"BSCS","BSIT","BSIS"};
    JComboBox<String> cbCourse;
    
    ButtonGroup grpBtn;
    JRadioButton rbFirst, rbSec;
    
    JTextArea taDisplay;
    JPanel pnlBtn;
    JButton btnAdd, btnReset, btnClear;
    
    public Speed()throws Exception {
        frame = new JFrame("SpeedCode");
        frame.setLayout(new BorderLayout());
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        
        lbNorth = new JLabel("ACCOUNT REGISTER");
        
        pnlWest = createWestPanel();
        pnlCenter = createCenterPanel();
        pnlSouth = createSouthPanel();
        
        
        frame.add(lbNorth, BorderLayout.NORTH);
        frame.add(pnlWest, BorderLayout.WEST);
        frame.add(pnlCenter, BorderLayout.CENTER);
        frame.add(pnlSouth, BorderLayout.SOUTH);
        
        frame.pack();
        frame.setVisible(true);
    }
    private JPanel createWestPanel() {
        JPanel panel = new JPanel();
        panel.setLayout(new GridLayout(9, 1));
        
        for(int i = 0; i < txtLabels.length; i++) {
            lbText[i] = new JLabel(txtLabels[i]);
            panel.add(lbText[i]);
        }
        
        return panel;
    }
    
    private JPanel createCenterPanel()throws Exception {
        JPanel panel = new JPanel();
        panel.setLayout(new GridLayout(9, 1));
        
        for(int i = 0; i < 5; i++) {
           if(i == 1) {
               ftfText[i] = new JFormattedTextField(new MaskFormatter("###########")); 
           } else if(i == 2) {
               ftfText[i] = new JFormattedTextField(new MaskFormatter("##-##-####")); 
           } else {
               ftfText[i] = new JFormattedTextField();
           }
           
           panel.add(ftfText[i]);
        }
        pfPassword = new JPasswordField(10);
        pfConfirm = new JPasswordField(10);
        
        cbCourse = new JComboBox<>(txtCombo);
        
        grpBtn = new ButtonGroup();
        rbFirst = new JRadioButton("First Semester");
        rbSec = new JRadioButton("Second Semester");
        
        grpBtn.add(rbFirst);
        grpBtn.add(rbSec);
        
        JPanel pnl1 = new JPanel();
        
        panel.add(pfPassword);
        panel.add(pfConfirm);
        panel.add(cbCourse);
        pnl1.add(rbFirst);
        pnl1.add(rbSec);
        panel.add(pnl1);
        
        return panel;
    }
    
    private JPanel createSouthPanel()throws Exception {
        JPanel panel = new JPanel();
        panel.setLayout(new BorderLayout());
        
        taDisplay = new JTextArea(10, 5);
        
        pnlBtn = new JPanel();
        
        btnAdd = new JButton("btnADD");
        btnReset = new JButton("btnRESET");
        btnClear = new JButton("btnCLEAR");
        
        btnAdd.addActionListener(e -> {
            String pw1 = new String(pfPassword.getPassword());
            String pw2 = new String(pfConfirm.getPassword());
            
            boolean isValid = (ftfText[3].getText().endsWith("@gmail.com") || 
                               ftfText[3].getText().endsWith("@yahoo.com"))&& 
                              (ftfText[3].getText().equals(ftfText[4].getText())&&
                               pw1.equals(pw2) && (rbFirst.isSelected() || rbSec.isSelected()));
            if(isValid) {
                taDisplay.setEditable(true);
                taDisplay.append(ftfText[0].getText() + " - " + cbCourse.getSelectedItem() + "\n");
            }
        });
        
        btnReset.addActionListener(e -> {
            for (JFormattedTextField i: ftfText) {
                i.setText("");
                i.setValue(null);
            }
            
            pfPassword.setText("");
            pfConfirm.setText("");
            grpBtn.clearSelection();
            
        });
        
        btnClear.addActionListener(e -> {
            for (JFormattedTextField i: ftfText) {
                i.setValue(null);
            }
            
            pfPassword.setText("");
            pfConfirm.setText("");
            grpBtn.clearSelection();
            taDisplay.setText("");
        });
        
        pnlBtn.add(btnAdd);
        pnlBtn.add(btnReset);
        pnlBtn.add(btnClear);
        
        panel.add(taDisplay, BorderLayout.CENTER);
        panel.add(pnlBtn, BorderLayout.SOUTH);
        
        return panel;
    }
    
    public static void main(String args[]) {
        SwingUtilities.invokeLater(() -> {
            try {
                new Speed();
            } catch (Exception e) {
                System.out.println("Error");
            }
        });
    }
}
