import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class HandsOn
{
    public static class Frame extends JFrame implements ActionListener
    {
        JTextField nameTextField;
        JTextField mobileTextField;
        JTextField birthTextField;
        JTextField emailTextField;
        JTextField confirmEmailTextField;
        JPasswordField passwordTextField;
        JPasswordField confirmPasswordTextField;

        String[] courses = {"Course", "BSCS", "BSIT"};
        JComboBox courseComboBox;

        JTextArea textArea;

        JButton buttonA;
        JButton buttonB;
        JButton buttonC;
        Frame()
        {
            this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
            this.setSize(500,700);
            this.setLocationRelativeTo(null);
            this.setLayout(new GridLayout(2,1));

            JPanel upperRow = new JPanel();
            JPanel bottomRow = new JPanel();
            JPanel bottomRow1 = new JPanel();
            JPanel bottomRow2 = new JPanel();
            JPanel bottomRowA = new JPanel();
            JPanel bottomRowB = new JPanel();
            JPanel bottomRowC = new JPanel();
            JPanel upperRow1 = new JPanel();
            JPanel upperRow2 = new JPanel();
            JPanel upperRow3 = new JPanel();
            JPanel upperRow4 = new JPanel();
            JPanel upperRow5 = new JPanel();
            JPanel upperRow6 = new JPanel();
            JPanel upperRow7 = new JPanel();
            JPanel upperRow8 = new JPanel();
            JPanel upperRow9 = new JPanel();
            JPanel upperRow10 = new JPanel();

            upperRow2.setBackground(Color.lightGray);
            upperRow3.setBackground(Color.lightGray);

            JLabel accountRegisterLabel = new JLabel("ACCOUNT REGISTER");
            accountRegisterLabel.setFont(new Font("Comic Sans", Font.BOLD, 10));

            JLabel nameLabel = new JLabel("NAME:");
            nameLabel.setPreferredSize(new Dimension(200,10));
            nameLabel.setFont(new Font("Comic Sans", Font.BOLD, 10));

            JLabel mobileLabel = new JLabel("MOBILE NUMBER:");
            mobileLabel.setPreferredSize(new Dimension(200,10));
            mobileLabel.setFont(new Font("Comic Sans", Font.BOLD, 10));

            JLabel birthLabel = new JLabel("BIRTHDAY:");
            birthLabel.setPreferredSize(new Dimension(200,10));
            birthLabel.setFont(new Font("Comic Sans", Font.BOLD, 10));

            JLabel emailLabel = new JLabel("EMAIL:");
            emailLabel.setPreferredSize(new Dimension(200,10));
            emailLabel.setFont(new Font("Comic Sans", Font.BOLD, 10));

            JLabel confirmEmailLabel = new JLabel("CONFIRM EMAIL:");
            confirmEmailLabel.setPreferredSize(new Dimension(200,10));
            confirmEmailLabel.setFont(new Font("Comic Sans", Font.BOLD, 10));

            JLabel passwordLabel = new JLabel("PASSWORD:");
            passwordLabel.setPreferredSize(new Dimension(200,10));
            passwordLabel.setFont(new Font("Comic Sans", Font.BOLD, 10));

            JLabel confirmPasswordLabel = new JLabel("CONFIRM PASSWORD:");
            confirmPasswordLabel.setPreferredSize(new Dimension(200,10));
            confirmPasswordLabel.setFont(new Font("Comic Sans", Font.BOLD, 10));

            JLabel courseLabel = new JLabel("COURSE:");
            courseLabel.setPreferredSize(new Dimension(200,10));
            courseLabel.setFont(new Font("Comic Sans", Font.BOLD, 10));

            JLabel semesterLabel = new JLabel("SEMESTER:");
            semesterLabel.setPreferredSize(new Dimension(100,10));
            semesterLabel.setFont(new Font("Comic Sans", Font.BOLD, 10));

            nameTextField = new JTextField();
            nameTextField.setPreferredSize(new Dimension(200,20));
            nameTextField.setFont(new Font("Times New Roman", Font.PLAIN, 10));

            mobileTextField = new JTextField();
            mobileTextField.setPreferredSize(new Dimension(200,20));
            mobileTextField.setFont(new Font("Times New Roman", Font.PLAIN, 10));

            birthTextField = new JTextField();
            birthTextField.setPreferredSize(new Dimension(200,20));
            birthTextField.setFont(new Font("Times New Roman", Font.PLAIN, 10));
            
            emailTextField = new JTextField();
            emailTextField.setPreferredSize(new Dimension(200,20));
            emailTextField.setFont(new Font("Times New Roman", Font.PLAIN, 10));

            confirmEmailTextField = new JTextField();
            confirmEmailTextField.setPreferredSize(new Dimension(200,20));
            confirmEmailTextField.setFont(new Font("Times New Roman", Font.PLAIN, 10));

            passwordTextField = new JPasswordField();
            passwordTextField.setPreferredSize(new Dimension(200,20));
            passwordTextField.setFont(new Font("Times New Roman", Font.PLAIN, 10));

            confirmPasswordTextField = new JPasswordField();
            confirmPasswordTextField.setPreferredSize(new Dimension(200,20));
            confirmPasswordTextField.setFont(new Font("Times New Roman", Font.PLAIN, 10));

            courseComboBox = new JComboBox<>(courses);
            courseComboBox.setPreferredSize(new Dimension(100, 20));
            courseComboBox.setFont(new Font("Comic Sans", Font.PLAIN, 10));
            
            JRadioButton firstSemester = new JRadioButton("1st Semester");
            JRadioButton secondSemester = new JRadioButton("2nd Semester");

            ButtonGroup semesterGroup = new ButtonGroup();
            semesterGroup.add(firstSemester);
            semesterGroup.add(secondSemester);

            textArea = new JTextArea();

            buttonA = new JButton("btnADD");
            buttonA.addActionListener(this);
            buttonB = new JButton("btnRESET");
            buttonB.addActionListener(this);
            buttonC = new JButton("btnCLEAR");
            buttonC.addActionListener(this);
            
            upperRow.setLayout(new GridLayout(10,1));
            bottomRow.setLayout(new GridLayout(2, 1));
            bottomRow1.setLayout(new GridLayout());
            bottomRow2.setLayout(new GridLayout(1,3, 5, 5));
            upperRow1.setLayout(new GridBagLayout());
            upperRow2.setLayout(new GridBagLayout());
            upperRow3.setLayout(new GridBagLayout());
            upperRow4.setLayout(new GridBagLayout());
            upperRow5.setLayout(new GridBagLayout());
            upperRow6.setLayout(new GridBagLayout());
            upperRow7.setLayout(new GridBagLayout());
            upperRow8.setLayout(new GridBagLayout());
            upperRow9.setLayout(new GridBagLayout());
            upperRow10.setLayout(new GridBagLayout());

            this.add(upperRow);
            upperRow.add(accountRegisterLabel);
            upperRow.add(upperRow1);
            upperRow.add(upperRow2);
            upperRow.add(upperRow3);
            upperRow.add(upperRow4);
            upperRow.add(upperRow5);
            upperRow.add(upperRow6);
            upperRow.add(upperRow7);
            upperRow.add(upperRow8);
            upperRow.add(upperRow9);
            upperRow.add(upperRow10);

            upperRow1.add(accountRegisterLabel);

            upperRow2.add(nameLabel);
            upperRow2.add(nameTextField);

            upperRow3.add(mobileLabel);
            upperRow3.add(mobileTextField);

            upperRow4.add(birthLabel);
            upperRow4.add(birthTextField);

            upperRow5.add(emailLabel);
            upperRow5.add(emailTextField);

            upperRow6.add(confirmEmailLabel);
            upperRow6.add(confirmEmailTextField);

            upperRow7.add(passwordLabel);
            upperRow7.add(passwordTextField);

            upperRow8.add(confirmPasswordLabel);
            upperRow8.add(confirmPasswordTextField);

            upperRow9.add(courseLabel);
            upperRow9.add(courseComboBox);

            upperRow10.add(semesterLabel);
            upperRow10.add(firstSemester);
            upperRow10.add(secondSemester);

            this.add(bottomRow);
            bottomRow.add(bottomRow1);
            bottomRow.add(bottomRow2);

            bottomRow1.add(textArea);

            bottomRow2.add(bottomRowA);
            bottomRow2.add(bottomRowB);
            bottomRow2.add(bottomRowC);

            bottomRowA.add(buttonA);
            bottomRowB.add(buttonB);
            bottomRowC.add(buttonC);

            this.setVisible(true);
        }

        @Override
        public void actionPerformed(ActionEvent e)
        {
            if (e.getSource() == buttonA)
            {
                String name = new String(nameTextField.getText());
                String courseInput = (String) courseComboBox.getSelectedItem();
                textArea.append(name + " - " + courseInput + "\n");
            }
            else if(e.getSource() == buttonB)
            {
                textArea.setText("");
            }
            else if (e.getSource() == buttonC)
            {
                nameTextField.setText("");
                mobileTextField.setText("");
                emailTextField.setText("");
                birthTextField.setText("");
                confirmEmailTextField.setText("");
                passwordTextField.setText("");
                confirmPasswordTextField.setText("");
            }
        }
    }

    public static void main(String[] args)
    {
        new Frame();
    }
}
