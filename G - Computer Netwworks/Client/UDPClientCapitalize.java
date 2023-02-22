import java.io.*;
import java.net.*;
class UDPClientCapitalize
{
	public static void main(String args[]) throws Exception
	{
		BufferedReader inFromUser = new BufferedReader(new InputStreamReader(System.in));
		DatagramSocket clientSocket = new DatagramSocket();
		System.out.print("Enter IP Address of server: ");
		String ip = inFromUser.readLine();
		InetAddress IPAddress = InetAddress.getByName(ip);
		byte[] sendData = new byte[1024], receiveData = new byte[1024];
		System.out.print("Enter message/data: ");
		String sentence = inFromUser.readLine();
		sendData = sentence.getBytes();
		DatagramPacket sendPacket = new DatagramPacket(sendData, sendData.length, IPAddress, 9876);
		clientSocket.send(sendPacket);
		DatagramPacket receivePacket = new DatagramPacket(receiveData, receiveData.length);
		clientSocket.receive(receivePacket);
		String modifiedSentence = new String(receivePacket.getData());
		System.out.println("From Server: " + modifiedSentence);
		clientSocket.close();
	}
}
