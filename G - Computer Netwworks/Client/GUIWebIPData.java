import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.lang.Exception;
import java.net.*; 
import java.io.*;
class CreateLoginForm extends JFrame implements ActionListener
{
    JButton b1;
    JPanel newPanel;
    JLabel urlLabel;
    final JTextField  textField1;
    CreateLoginForm()
    {    
        urlLabel = new JLabel();
        urlLabel.setText("Enter URL: ");
        textField1 = new JTextField(15);
        b1 = new JButton("SUBMIT");
        newPanel = new JPanel(new GridLayout(3, 1));
        newPanel.add(urlLabel);
        newPanel.add(textField1);
        newPanel.add(b1);
        add(newPanel, BorderLayout.CENTER);
        b1.addActionListener(this);
        setTitle("GUI WEB-IP");
    }
    public void actionPerformed(ActionEvent ae)
    {
	    try
	    {
        String userValue = textField1.getText();
        BufferedReader inFromUser = new BufferedReader(new InputStreamReader(System.in)); 
        DatagramSocket clientSocket = new DatagramSocket();
        System.out.print("Enter Server IP Address: ");
        InetAddress IPAddress = InetAddress.getByName(inFromUser.readLine()); 
        byte[] sendData = new byte[1024], receiveData = new byte[1024];  
        String url = userValue; 
        sendData = url.getBytes(); 
        DatagramPacket sendPacket = new DatagramPacket(sendData, sendData.length,IPAddress, 9876); 
        clientSocket.send(sendPacket); 
        DatagramPacket receivePacket = new DatagramPacket(receiveData, receiveData.length); 
        clientSocket.receive(receivePacket); 
        String modifiedSentence = new String(receivePacket.getData());
        JFrame  page = new JFrame();
        page.setVisible(true);
        JLabel wel_label = new JLabel("IP Address: " + modifiedSentence);
        page.getContentPane().add(wel_label);
        clientSocket.close();
	    }
	    catch(Exception e)
	    {
	      JOptionPane.showMessageDialog(null, e.getMessage());
	    }
    }
}

