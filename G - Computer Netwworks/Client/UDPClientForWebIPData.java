/*
import java.io.*;
import java.net.*;
class UDPClientForWebIPData
{
	public static void main(String args[]) throws Exception
	{
		BufferedReader inFromUser = new BufferedReader(new InputStreamReader(System.in));
		DatagramSocket clientSocket = new DatagramSocket();
		System.out.print("CLIENT-SERVER LINK TO FIND IP ADDRESSES OF CORRESPONDING WEBSITES\n\nEnter Server IP Address: ");
		InetAddress IPAddress = InetAddress.getByName(inFromUser.readLine());
		byte[] sendData = new byte[1024], receiveData = new byte[1024];
		System.out.print("\n1. Add Data\t2. Find IP Address\t3. Exit\nEnter corresponding action no.: ");
		String action = inFromUser.readLine();
		sendData = action.getBytes();
		DatagramPacket sendPacket = new DatagramPacket(sendData, sendData.length, IPAddress, 9876), receivePacket;
		clientSocket.send(sendPacket);
		if (action.equals("1"))
		{
			System.out.print("Enter new website URL: ");
			sendData = inFromUser.readLine().getBytes();
			sendPacket = new DatagramPacket(sendData, sendData.length, IPAddress, 9876);
			clientSocket.send(sendPacket);
			System.out.print("Enter new website IP address: ");
			sendData = inFromUser.readLine().getBytes();
			sendPacket = new DatagramPacket(sendData, sendData.length, IPAddress, 9876);
			clientSocket.send(sendPacket);
			receivePacket = new DatagramPacket(receiveData, receiveData.length);
			clientSocket.receive(receivePacket);
			String output = new String(receivePacket.getData());
			System.out.println(output);
		}	
		else if (action.equals("2"))
		{
			System.out.print("Enter IP address website URL: ");
			String url = inFromUser.readLine();
			sendData = url.getBytes();
			sendPacket = new DatagramPacket(sendData, sendData.length, IPAddress, 9876);
			clientSocket.send(sendPacket);
			receivePacket = new DatagramPacket(receiveData, receiveData.length);
			clientSocket.receive(receivePacket);
			String output = new String(receivePacket.getData());
			System.out.println(output);
		}
		else if (action.equals("3"))
			System.out.println("Disconnecting...");
		else
			System.out.println("Invalid response... Restart program...");
		clientSocket.close();
	}
}
*/
import java.io.*;  
import java.net.*;  
public class UDPClientForWebIPData  
{      
	public static void main(String args[]) throws Exception      
	{          
		BufferedReader inFromUser = new BufferedReader(new InputStreamReader(System.in));          
		DatagramSocket clientSocket = new DatagramSocket();
		System.out.print("Enter Server IP Address: ");
		InetAddress IPAddress = InetAddress.getByName(inFromUser.readLine());          
		byte[] sendData = new byte[1024], receiveData = new byte[1024];  
		System.out.print("Enter URL: ");         
		String sentence = inFromUser.readLine();          
		sendData =sentence.getBytes();                  
		DatagramPacket sendPacket = new DatagramPacket(sendData, sendData.length,IPAddress, 9876);  
		clientSocket.send(sendPacket);          
		DatagramPacket receivePacket = new DatagramPacket(receiveData, receiveData.length);  
		clientSocket.receive(receivePacket);          
		String modifiedSentence = new String(receivePacket.getData());  
		System.out.println("FROM SERVER: " + modifiedSentence);  
		clientSocket.close();      
	}  
}  