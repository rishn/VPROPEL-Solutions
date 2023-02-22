/*
import java.io.*;
import java.net.*;
class UDPServerForWebIPData
{
	public static void main(String args[]) throws Exception
	{
		InputStream is = new FileInputStream("WebsiteIP.txt");
		DataInputStream dis = new DataInputStream(is);
		OutputStream os = new FileOutputStream("WebsiteIP.txt");
		DataOutputStream dos = new DataOutputStream(os);
		DatagramSocket serverSocket = new DatagramSocket(9876);
		byte[] receiveData = new byte[1024], sendData = new byte[1024];
		while(true)
		{
			DatagramPacket receivePacket = new DatagramPacket(receiveData, receiveData.length), sendPacket;
			serverSocket.receive(receivePacket);
			String action = new String(receivePacket.getData());
			InetAddress IPAddress = receivePacket.getAddress();
			int port = receivePacket.getPort();
			if (action.equals("1"))
			{
				receivePacket = new DatagramPacket(receiveData, receiveData.length);
				serverSocket.receive(receivePacket);
				String url = new String(receivePacket.getData());
				dos.writeUTF(url);
				receivePacket = new DatagramPacket(receiveData, receiveData.length);
				serverSocket.receive(receivePacket);
				String ip = new String(receivePacket.getData());
				dos.writeUTF(ip);
				sendData = "Data entered successfully...".getBytes();
				sendPacket = new DatagramPacket(sendData, sendData.length, IPAddress, port);
				serverSocket.send(sendPacket);
			}
			else if (action.equals("2"))
			{
				receivePacket = new DatagramPacket(receiveData, receiveData.length);
				serverSocket.receive(receivePacket);
				String url = new String(receivePacket.getData());
				int found = 0;
				while (dis.available() > 0)
				{
					if (dis.readUTF().equals(url))
					{
						found = 1;
						String ip = dis.readUTF();
						sendData = ("Required IP Address: " + ip).getBytes();
						break;
					}
					dis.readUTF();
				}
				if (found == 0)
					sendData = "URL not found in database...".getBytes();
				sendPacket = new DatagramPacket(sendData, sendData.length, IPAddress, port);
				serverSocket.send(sendPacket);
			}
		}
	}
}
*/
import java.io.*;
import java.net.*;
class UDPServerForWebIPData
{
	public static void main(String args[]) throws Exception
	{          
		DatagramSocket serverSocket = new DatagramSocket(9876);         
		byte[] receiveData = new byte[1024], sendData  = new byte[1024];  
		while (true)          
		{              
			DatagramPacket receivePacket = new DatagramPacket(receiveData,receiveData.length);  
			serverSocket.receive(receivePacket);              
			String sentence = new String(receivePacket.getData());
			sentence = sentence.trim();
			InetAddress IPAddress = receivePacket.getAddress();  
			int port = receivePacket.getPort();              
			File f = new File("WebsiteIP.txt");             
			FileReader fr = new FileReader(f);             
			String str = null, temp = null;             
			BufferedReader br = new BufferedReader(fr);
			int chk = 0;
			while ((str = br.readLine()) != null)             
			{         
				if (str.contains(sentence))
				{                        
					temp = str;
					chk = 1;
				}
			}	 
			fr.close();
			if (chk == 0)
				temp = "URL not found";
			sendData = temp.getBytes();              
			DatagramPacket sendPacket = new DatagramPacket(sendData, sendData.length, IPAddress, port);  
			serverSocket.send(sendPacket);
		}      
	}  
}   